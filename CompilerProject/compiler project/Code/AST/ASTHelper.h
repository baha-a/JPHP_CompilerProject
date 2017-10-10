#ifndef __AST_HELPER__
#define __AST_HELPER__

#include <iostream>
#include <stack>
#include "AST.h"
using namespace std;

class ASTHelper
{
public:
	static int LocalVariableFrameOffest;
	static stack<int> last_LocalVariableFrameOffest;
	static int NextOffest()
	{
		LocalVariableFrameOffest -= 4;
		return LocalVariableFrameOffest;
	}
	static void pushLocalVariableCounter(bool resetCounter = false, int i = 0) 
	{
		last_LocalVariableFrameOffest.push(LocalVariableFrameOffest);
		if (resetCounter)
			LocalVariableFrameOffest = i;
	}
	static void popLocalVariableCounter() 
	{
		LocalVariableFrameOffest = last_LocalVariableFrameOffest.top();
		last_LocalVariableFrameOffest.pop();
	}

	static void recheckForVariablesOffest(TreeNode * node)
	{
		//
		// this function will initialize the offest of variables
		// if you want understand something here you have to read
		// the function 'generate(TreeNode,string,string)' coz this
		// function is smaller version of 'generate' in the CodeGenerator.h
		//

		if (node == NULL)
			return;
		switch (node->nodeType)
		{
		
		case uneryPreMinusNode:
		{
			if (node->left->nodeType == intValNode)
			{
				node->intval = node->left->intval * -1;
				node->left = NULL;
				node->nodeType = intValNode;
			}
			else if (node->left->nodeType == doubleValNode)
			{
				node->doubleval = node->left->doubleval * -1;
				node->left = NULL;
				node->nodeType = doubleValNode;
			}
			break;
		}
		case idVariableNode:
		{
			Variable* v = (Variable*)node->symbolTableElement;
			if (v == NULL)
				break;

			if (v->isStatic == NULL || v->isStatic == false)
			{
				//if (v->isType("double"))
				//	NextOffest();

				if (v->itsDataMember)
					v->AstOffest = (NextOffest()*-1) - 4;
				else
					v->AstOffest = NextOffest();
			}
			break;
		}
		case functionNode:
		{
			Function* f = (Function*)(node->symbolTableElement);
			if (f->isAbstract())
			{
				// reserve space for the function pointer, coz abstract function is just pointer to child's function
				// and I will see the function as DataMember(pointer to function) in class
				f->AstOffest_ForAbstractFunctionsOnly = (NextOffest()*-1) - 4;
				break;
			}
			pushLocalVariableCounter(true);
			// reserve space for vtable as first paramter
			if (f->isInsideClass && !f->isStatic())
				NextOffest();
			// reserve space for function's parameters
			for (TreeNode* mover = node->left; mover; mover = mover->right)
				if (mover->symbolTableElement)
				{
					Variable* v = (Variable*)mover->symbolTableElement;
					v->AstOffest = NextOffest();
					//if (v->isType("double"))
					//	NextOffest();
				}

			// skiping to offest for pushing the $fp and $ra at begin of function
			NextOffest();
			NextOffest();

			recheckForVariablesOffest(node->right);
			popLocalVariableCounter();
			break;
		}
		case classNode:
		{
			pushLocalVariableCounter(true, ((Type*)node->symbolTableElement)->gaveMeNumberOfTheVariableInParentClass() * -4);
			recheckForVariablesOffest(node->left);
			popLocalVariableCounter();
			break;
		}
		case scopeNode:
			if (node->size > 0) pushLocalVariableCounter();
			recheckForVariablesOffest(node->left);
			if (node->size > 0) popLocalVariableCounter();
			break;
		case stmtListNode:
			for (TreeNode * m = node; m; m = m->right) recheckForVariablesOffest(m->left);  // reduceing te tree depth for avoid stackoverflow excption.
			break;

		default:
			recheckForVariablesOffest(node->left);
			recheckForVariablesOffest(node->right);
			break;
		}
	}

	static void recheckForSymbolTableElements(TreeNode * node)
	{
		//
		// this function will initialize the offest of variables
		// if you want understand something here you have to read
		// the function 'generate(TreeNode,string,string)' coz this
		// function is smaller version of 'generate' in the CodeGenerator.h
		//

		if (node == NULL)
			return;
		switch (node->nodeType)
		{

		case staticVariableNode:
		{
			Variable* v = (Variable*)(node->symbolTableElement);
			if (v == NULL)
				break;
			if (node->left)
				v->SetClassType(((Type*)node->left->symbolTableElement));
			break;
		}
		case idVariableNode:
		{
			Variable* v = (Variable*)node->symbolTableElement;
			if (v == NULL)
				break;

			if (node->left)
				v->SetClassType(((Type*)node->left->symbolTableElement));
			break;
		}
		case functionNode:
		{
			Function* f = (Function*)(node->symbolTableElement);
			for (TreeNode* mover = node->left; mover; mover = mover->right)
				if (mover->symbolTableElement)
				{
					Variable* v = (Variable*)mover->symbolTableElement;
					v->SetClassType(mover->left ? ((Type*)(mover->left->symbolTableElement)) : NULL);
				}

			recheckForSymbolTableElements(node->right);
			break;
		}
		case stmtListNode:
			for (TreeNode * m = node; m; m = m->right) recheckForSymbolTableElements(m->left);  // reduceing te tree depth for avoid stackoverflow excption.
			break;

		case callArrayVariableNode:
			node->symbolTableElement = node->left->symbolTableElement;
		default:
			recheckForSymbolTableElements(node->left);
			recheckForSymbolTableElements(node->right);
			break;
		}
	}
	
	static bool recheckReturnNode(TreeNode* node)
	{
		if (node == NULL)
			return false;
		if (node->nodeType == returnNode)
			return true;

		if (node->nodeType == scopeNode) // for inner scope
			node = node->left;   // go from 'scopeNode' to 'stmtListNode' node

		if (node->nodeType == ifNode && node->left && node->right)
			if (recheckReturnNode(node->left->right) && recheckReturnNode(node->right->right))
				return true;

		TreeNode* t = node;
		while (t)
		{
			if (t->left)
				switch (t->left->nodeType)
				{
				case returnNode: return true;
				case scopeNode: if (recheckReturnNode(t->left)) return true; break;
				case ifNode: if (recheckReturnNode(t->left)) return true; break;
				}
			t = t->right;
		}
		return false;
	}
	static bool recheckForAllPathReturnValue(TreeNode * node)
	{
		if (node == NULL)
			return false;

		node = node->right;  // go from 'functionNode' to 'functionBody' node
		node = node->left;   // go from 'functionBody' to 'scopeNode' node

		return recheckReturnNode(node);
	}

};
#endif