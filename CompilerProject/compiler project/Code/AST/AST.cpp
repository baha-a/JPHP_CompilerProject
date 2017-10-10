#include "AST.h"
#include "..\HelperCode.h"

char* arr[] =
{ "NOTHING" ,
"intValNode" ,
"doubleValNode" ,
"stringValNode" ,
"idVariableNode" ,
"idFunctionNode" ,
"idClassNode" ,
"idNode" ,
"classTypeNameNode",
"callVariableNode" ,
"callFunctionNode" ,
"assignNode" ,
"minusNode" ,
"plusNode" ,
"multNode" ,
"divNode" ,
"modNode" ,
"moreThanNode" ,
"lessThanNode" ,
"IsEqualNode" ,
"IsNotEqualNode" ,
"lessOrEqualNode" ,
"moreOrEqualNode" ,
"booleanAndNode" ,
"booleanOrNode" ,
"exprListNode" ,
"tryNode" ,
"variable_without_objectNode" ,
"ifNode" ,
"ifConditionAndBodyNode" ,
"elseifConditionAndBodyNode" ,
"elseNode" ,
"stmtListNode" ,
"whileNode" ,
"declrationStmtNode" ,
"expressionNode" ,
"emptyNode" ,
"forNode" ,
"forBodyNode" ,
"forStmtNode" ,
"doWhileNode" ,
"switchNode" ,
"breakNode" ,
"continueNode" ,
"returnNode" ,
"echoNode" ,
"foreachNode" ,
"caseNode" ,
"defaultNode" ,
"functionListNode" ,
"functionNode" ,
"paramNode" ,
"functionBody" ,
"classListNode" ,
"classNode" ,
"CbodyNode" ,
"idTypeNode" ,
"intTypeNode" ,
"stringTypeNode" ,
"boolTypeNode" ,
"charTypeNode" ,
"doubleTypeNode" ,
"floatTypeNode" ,
"realTypeNode" ,
"longTypeNode" ,
"byteTypeNode" ,
"uintTypeNode" ,
"ulongTypeNode" ,
"ubyteTypeNode" ,
"arrayNode" ,
"scopeNode" ,
"functionCallNode" ,
"argumentNode" ,
"returnTypeNode" ,
"plusplusNode" ,
"minusminusNode" ,
"staticVariableNode" ,
"variableDeclarationNode" ,
"arrayInitializingNode" ,
"arrayPairListNode" ,
"callArrayVariableNode" ,
"arrayInitializingWithValuesNode" ,
"forHeaderNode" ,
"argumentReferencNode" ,
"assignReferencNode" ,
"newClassInstance" ,
"objectAccessToVariableNode",
"objectAccessToFunctionNode",
"objectAccessToArrayElementNode",
"NotBooleanNode",
"booleanAndAndNode",
"booleanOrOrNode",
"readIntNode",
"readStringNode",
"readDoubleNode",
"trueNode",
"falseNode",
"nullNode",
"intCastNode" ,
"doubleCastNode" ,
"stringCastNode" ,
"boolCastNode",
"classTypeCastNode",
"uneryPreMinusNode",
"classTypeCastArrayNode",
"asNode",
"listcaseNode",
};

AST::AST(void) { }

AST::~AST(void) { }

TreeNode::TreeNode()
{
	right = NULL;
	left = NULL;
	symbolTableElement = NULL;
	intval = 0;
	doubleval = 0.0;
	stringval = "";
	id = "";
    size = 0;

	type = "";
	line = 0;
	col = 0;
}

TreeNode* AST::CurrntPointer = NULL;
ofstream AST::outputfileAST;

TreeNode * AST::createNode(TreeNode * l, TreeNode* r, NodeType nt)
{
	TreeNode * tn = new TreeNode();
	tn->nodeType = nt;
	tn->left = l;
	tn->right = r;

	CurrntPointer = tn;

	tn->line = banana::line;
	tn->col = banana::col;


	return tn;
}

int x = 0;
TreeNode * AST::addToLastRight(TreeNode * basic, TreeNode* newItem)
{
	if (basic && newItem)
	{
		x++;
		TreeNode * mover = basic;
		while (mover->right)
			mover = mover->right;
		mover->right = newItem;
	}
	CurrntPointer = basic;
	return basic;
}
TreeNode * TreeNode::addSymbolTableElement(Symbol * s)
{
	symbolTableElement = s;
	return this;
}
TreeNode * TreeNode::addValueint(int v)
{
	intval = v;
	return this;
}
TreeNode * TreeNode::addValuedouble(double d)
{
	doubleval = d;
	return this;
}
TreeNode * TreeNode::addValuestring(char* s)
{
	stringval = s;
	return this;
}
TreeNode * TreeNode::addid(char* s)
{
	id = s;
	return this;
}
TreeNode * TreeNode::addScopeSize(int s)
{
	size = s;
	return this;
}
void AST::print(TreeNode * tn, int lvl)
{
	if (lvl == 0)
		outputfileAST << "-------------------  A  S  T  ------------------" << endl;

	if (tn)
	{
		for (int i = 0; i < lvl; i++)
			outputfileAST << "  ";
		if (tn->nodeType)
		{
			outputfileAST << arr[tn->nodeType] << "\n";
			print(tn->left, lvl + 1);
			print(tn->right, lvl + 1);
		}
		else
			outputfileAST << "somethingWrongHere\n";
	}

	if (lvl == 0)
		outputfileAST << "------------------------------------------------" << endl;
}

char* AST::GetNameOfEnum(NodeType e)
{
	return arr[e];
}

