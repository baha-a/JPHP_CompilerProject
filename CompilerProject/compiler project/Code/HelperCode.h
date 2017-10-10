#pragma once
#ifndef __CODE_HELPER__
#define __CODE_HELPER__

#include "AST\ASTHelper.h"
#include "ST\SymbolTable.h"
#include "ST\MyParser.h"
#include "CodeGenerator.h"
#include <iostream>
#include <stack>
#include <fstream>
#include <memory>
using namespace std;

namespace banana
{
	template<typename Base, typename T>
	inline bool instanceof(const T *ptr)
	{
		return dynamic_cast<const Base*>(ptr) != nullptr;
	}

	extern bool DEBUGMODE_LEX;
	extern bool DEBUGMODE_YACC;
	extern bool DEBUGMODE_ST;
	extern bool DEBUGMODE_AST;
	extern bool DEBUGMODE_ASM;
	extern bool CommentingOnASMCode;
	extern bool CopyResultToClipboard;



	void enableOutPut(bool);
	void enableOutPutAST(bool);
	void enableCommentingASMCode(bool);
	void enableCopyResultToClipboard(bool);

	void changeInputFile(char* = "index.php");

	extern int errorsCount;
	extern int line;
	extern int col;

	class Error_info
	{
	public:
		int  colNo;
		int  lineNo;
		string  msg;
		string  name;

		inline void toString()
		{
			cout << "Ln(" << lineNo << ") Col(" << colNo << ") name(" << name.c_str() << ") Msg(" << msg.c_str() << ")";
		}
	};


	class unknowenClassName
	{
	public:
		Type* child;
		char* base;
		int line, col;
		bool isForInheritnce;

		TreeNode* CurrntPointer;
		unknowenClassName(Type* t, char* b, int lin, int colm)
		{
			child = t;
			base = b;
			line = lin;
			col = colm;
			isForInheritnce = true;
			CurrntPointer = AST::CurrntPointer;
			forConstruactor = false;
		}

		BlockScope* currntScope;
		Type* thisClass;
		unknowenClassName(char* name,Type* t, BlockScope* block, int lin, int colm,bool forconstruactor)
		{
			base = name;
			currntScope = block;

			line = lin;
			col = colm;

			isForInheritnce = false;

			CurrntPointer = AST::CurrntPointer;
			forConstruactor = forconstruactor;
			thisClass = t;
		}

		bool forConstruactor;
	};

	class unknowenStaticClassName
	{
	public:
		int line, col;
		char* outter;
		char* inner;

		bool forConstruactor;
		TreeNode* CurrntPointer;
		BlockScope* currntScope;

		bool staticCalling;

		unknowenStaticClassName(char* outer, char* iner, BlockScope* block, int lin, int colm, bool forconstruactor, bool s)
		{
			outter = outer;
			inner =  iner;
		
			currntScope = block;

			line = lin;
			col = colm;

			CurrntPointer = AST::CurrntPointer;
			forConstruactor = forconstruactor;

			staticCalling = s;
		}
	};

	class unknowenVariablesCalling
	{
	public:
		char* var;
		char* val;
		Type* type;
		int line, col;
		Variable* v;

		bool isStaticCalling;
		char* VriableName;
		char* ClassName;
		BlockScope* curruntScope;

		bool isParentKeywordIssue;

		bool isInsideStaticFunction;

		TreeNode* CurrntPointer;
		
		unknowenVariablesCalling(Type* s, char* va, char* vl, int lin, int colm, bool isParentKeyword, bool isInsideStaticFunction2)
		{
			isStaticCalling = false;

			isParentKeywordIssue = isParentKeyword;

			type = s;
			var = va;
			val = vl;

			line = lin;
			col = colm;

			isInsideStaticFunction = isInsideStaticFunction2;

			CurrntPointer = AST::CurrntPointer;
		}

		unknowenVariablesCalling(char* vriableName, char* className, BlockScope* curruntScop, int lin, int colm)
		{
			isInsideStaticFunction = isParentKeywordIssue = false;
			isStaticCalling = true;

			curruntScope = curruntScop;
			VriableName = vriableName;
			ClassName = className;

			line = lin;
			col = colm;

			CurrntPointer = AST::CurrntPointer;
		}
	};

	class unknowenFunctionCalling
	{
	public:
		char* name;
		char* ClassName;
		BlockScope* CurrScope;

		Type* type;
		int line, col;

		bool isStaticCalling;

		bool isParentKeywordIssue;

		bool isInsideStaticFunction;

		TreeNode* CurrntPointer;

		unknowenFunctionCalling(Type* s, char* v, int lin, int colm, bool isParentKeyword, bool isInsideStaticFunction2)
		{
			type = s;
			name = v;
			line = lin;
			col = colm;

			isStaticCalling = false;

			isParentKeywordIssue = isParentKeyword;

			isInsideStaticFunction = isInsideStaticFunction2;
			CurrntPointer = AST::CurrntPointer;
		}

		unknowenFunctionCalling(char* v, char* className, BlockScope* currScope, int lin, int colm)
		{
			isInsideStaticFunction = isParentKeywordIssue = false;

			name = v;
			ClassName = className;
			CurrScope = currScope;

			line = lin;
			col = colm;

			isStaticCalling = true;
			CurrntPointer = AST::CurrntPointer;
		}
	};

	extern vector<unknowenStaticClassName*> unkowenStaticClassName;
	extern vector<unknowenClassName*> unkowenClassName;
	extern vector<unknowenVariablesCalling*> unkowenVariable;
	extern vector<unknowenFunctionCalling*> unkowenFunction;




	class UnknowenDataMember
	{
	public:
		Symbol* type;
		int line, col;
		char* name;
		BlockScope* curruntScope;
		TreeNode* CurrntPointer;
		UnknowenDataMember* previousOne;

		UnknowenDataMember(Symbol* s, char* n, int lin, int colm,BlockScope* b, UnknowenDataMember* p)
		{
			name = n;
			type = s;

			line = lin;
			col = colm;

			curruntScope = b;

			CurrntPointer = AST::CurrntPointer;
			previousOne = p;
		}
	};
	extern vector<UnknowenDataMember*> unkowenDataMember;


	class UnknowenInstanceFunctionCalling
	{
	public:
		Symbol* type;
		int line, col;
		char* name;
		BlockScope* curruntScope;
		TreeNode* CurrntPointer;

		UnknowenInstanceFunctionCalling(Symbol* s, char* n, int lin, int colm,BlockScope* b)
		{
			name = n;
			type = s;

			line = lin;
			col = colm;

			curruntScope = b;
			CurrntPointer = AST::CurrntPointer;
		}
	};
	extern vector<UnknowenInstanceFunctionCalling*> unknowenInstanceFunctionCalling;



	class RecheckSuperKeyword
	{
	public:
		Type* type;
		TreeNode* CurrntPointer;

		RecheckSuperKeyword(Type* s)
		{
			type = s;

			CurrntPointer = AST::CurrntPointer;
		}
	};
	extern vector<RecheckSuperKeyword*> recheckSuperKeyword;



	extern deque<Error_info> _errors;

	int PrintErrorsStack();


	void debuggerLEX(char * s);
	void debuggerLEX(char * s, int v);
	void debuggerLEX(char * s, char* v);

	void debuggerYACC(char * s);
	void debuggerYACC(char * s, int v);

	void debuggerYACC(char * s, char* v);


	void debugger(char * s);
	void debugger(char * s, int v);
	void debugger(char * s, char* v);

	void errorhandler(const char* s);
	void errorhandler(char* s);
	void errorhandler(char* msg, char* name);
	void warninghandler(char* s);

	void checkDivideByZeroError(int x, int y);




	////////////////////////////////////////////////////////////////////////////////////
	
	extern bool isClassStatic;
	extern bool isClassFinal;
	extern bool isClassAbstract;
	inline void ResetClassEnteryType() { isClassStatic = isClassAbstract = isClassFinal = false; }

	extern AccessSpecifier access;
	inline void MemberAccessPublic() { access = AccessSpecifier::_public; }
	inline void MemberAccessProtacted() { access = AccessSpecifier::_protected; }
	inline void MemberAccessPrivate() { access = AccessSpecifier::_private; }
	inline void ResetMemberAccess() { access = AccessSpecifier::_private; }

	extern StorageSpecifier storage;
	inline void MemberStorageFinal() { storage = StorageSpecifier::_final; }
	inline void MemberStorageAbstract() { storage = StorageSpecifier::_abstract; }
	inline void MemberStorageStatic() { storage = StorageSpecifier::_static; }
	inline void ResetMemberStorage() { storage = StorageSpecifier::_none; }

	extern bool Optional_ref;
	extern char* returnType;

	extern MyParser* _parser;


	extern stack<Type*> tmpType;
	void ClassDeclaration(char* name);

	void ClassDeclarationAddInheritedClass(char* name);
	bool checkForInheritenceLoop(Type* a, Type* b);
	void ClassDeclarationAddImplementInterface(char* name);
	Type* ClassDeclarationEnd(Type* = NULL);
	void DidThisClassImplementsItsBaseAbstractFunction(Type* t);

	extern stack<Function*> tmpfunction;
	extern Signature* sign;
	Variable* addParametertoFunction(char* type, char* name, char* value,TreeNode* = NULL);
	void FunctionDeclaration(char* name, bool isInClass);
	void checkAbstractFunction(bool isFunctionHasBody);
	void didThisFunctionIsOverrideOrNormal(Type *t, Function*f);
	Function* FunctionDeclarationEnd(bool isInsideClass = false);

	extern bool itsDataMember;
	void itsArrayVariable(bool);
	void addDataMemeberStart();
	void addDataMemeberEnd();
	Variable* addVariable(char* type, char* name, bool isConst);
	Variable* addVariable(char* type, char* name, char* value, bool isConst);
	Variable* addStaticVariable(char* type, char* name);
	Variable* addStaticVariable(char* type, char* name, char* value);
	//extern Variable* tmpVar;
	Variable* callVariable(char* name);


	void IncreceStatementNumber();
	void resetStatementNumber();
	Function* SuperKeywordShowedUp();


	//extern vector<Variable*> functionCallParameters;
	//extern bool isForFunctionCall;
	Function* callFunction(char* name);
	void checkFunctionCallParametersWithFunctionArguments(Function* f);


	void startNewScope();
	int closeScope();

	Variable* findInstanceVariable(Symbol* t, char* name);
	Function* findInstanceFunction(Symbol* tt, char* name);

	Variable* findStaticMember(char* Class, char* name);
	Function* findStaticFunction(char* Class, char* name);

	Type* findClassName(char* name, bool = false,Type* = NULL);
	Type* findStaticClassName(char*, char*, bool = false);
	Type* findInstanceClassName(char*, char*);

	void EndOfPhpCode();

	void EatUntilGetPhpTag();
	void EatUntilEndOfFile();
	void EatUntilNewLine();

	bool before_main();
	int after_main(TreeNode*);

	int generateCode(TreeNode * tree);

	void toClipboard(string);
	void CreateAsmFile(string s);

	bool includeFile(char*, bool);
}
#endif
