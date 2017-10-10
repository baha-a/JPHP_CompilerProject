#pragma once
#ifndef AST_
#define AST_

#include "..\ST\SymbolTable.h"
#include <iostream>
using namespace::std;
enum NodeType {
	//Expressions
	NOTHING,
	intValNode,
	doubleValNode,
	stringValNode,

	idVariableNode,
	idFunctionNode,
	idClassNode,
	idNode,
	classTypeNameNode,


	callVariableNode,
	callFunctionNode,

	assignNode,
	minusNode,
	plusNode,
	multNode,
	divNode,
	modNode,

	moreThanNode,
	lessThanNode,
	IsEqualNode,
	IsNotEqualNode,
	lessOrEqualNode,
	moreOrEqualNode,
	booleanAndNode,
	booleanOrNode,

	exprListNode,
	tryNode,
	variable_without_objectNode,

	//statements
	ifNode,
	ifConditionAndBodyNode,
	elseifConditionAndBodyNode,
	elseNode,

	stmtListNode,
	whileNode,
	declrationStmtNode,
	expressionNode,
	emptyNode,
	forNode,
	forBodyNode,
	forStmtNode,
	doWhileNode,

	switchNode,
	breakNode,
	continueNode,
	returnNode,
	echoNode,
	foreachNode,
	caseNode,
	defaultNode,


	//function
	functionListNode,
	functionNode,
	paramNode,
	functionBody,

	//class
	classListNode,
	classNode,
	CbodyNode,

	//type: Here AST is used as temporoy data structure to hold type to upper grammars
	idTypeNode,
	intTypeNode,
	stringTypeNode,
	boolTypeNode,
	charTypeNode,
	doubleTypeNode,
	floatTypeNode,
	realTypeNode,
	longTypeNode,
	byteTypeNode,
	uintTypeNode,
	ulongTypeNode,
	ubyteTypeNode,

	arrayNode,
	scopeNode,
	functionCallNode,
	argumentNode,
	returnTypeNode,
	plusplusNode,
	minusminusNode,
	staticVariableNode,
	variableDeclarationNode,
	arrayInitializingNode,
	arrayPairListNode,
	callArrayVariableNode,
	arrayInitializingWithValuesNode,
	forHeaderNode,
	argumentReferencNode,
	assignReferencNode,
	newClassInstance,
	objectAccessToVariableNode,
	objectAccessToFunctionNode,
	objectAccessToArrayElementNode,
	NotBooleanNode,
	booleanAndAndNode,
	booleanOrOrNode,
	readIntNode,
	readStringNode,
	readDoubleNode,
	trueNode,
	falseNode,
	nullNode,

	intCastNode,
	doubleCastNode,
	stringCastNode,
	boolCastNode,
	classTypeCastNode,
	uneryPreMinusNode,
	classTypeCastArrayNode,
	asNode,
	listcaseNode,
};

class TreeNode{
public:
	TreeNode();
	TreeNode * left;
	TreeNode * right;
	Symbol * symbolTableElement;
	NodeType nodeType;
	TreeNode * addSymbolTableElement(Symbol *);
	
	TreeNode * addValueint(int);
	TreeNode * addValuedouble(double);
	TreeNode * addValuestring(char*);
	TreeNode * addid(char*);

	TreeNode * addScopeSize(int);

	int intval;
	double doubleval;
	char* stringval;
	char * id;
	int size;

	string type;
	int line, col;
};
class AST
{
public:
	AST(void);
	~AST(void);
	static TreeNode* CurrntPointer;
	static ofstream outputfileAST;
	TreeNode * createNode(TreeNode * left, TreeNode* right, NodeType nt);
	TreeNode * addToLastRight(TreeNode * basic, TreeNode* newItem);
	static void print(TreeNode * tn, int lvl = 0);
	static char* GetNameOfEnum(NodeType e);
};
#endif