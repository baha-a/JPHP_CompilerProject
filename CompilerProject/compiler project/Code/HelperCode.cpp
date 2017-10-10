#include "HelperCode.h"

#include <Windows.h> // delete this after finish of it
#include <winuser.h> // delete this after finish of it
#include <time.h>

#include <sstream>

#define OBJ "Object"

namespace banana
{
	// 0 = false ,,,,, 1 = true
	bool DEBUGMODE_LEX = 0;
	bool DEBUGMODE_YACC = 0;
	bool DEBUGMODE_ST = 0;

	bool DEBUGMODE_AST = 0;
	
	bool DEBUGMODE_ASM = 0;
	bool CommentingOnASMCode = 0;
	bool CopyResultToClipboard = 0;

	int errorsCount = 0;
	int line = 1;
	int col = 1;



	char* indexFile = "index.php";
	ofstream outputfile;

	void changeInputFile(char* x)
	{
		outputfile = ofstream((string(x) + ".yy.lex.st.txt").c_str());
		AST::outputfileAST = ofstream((string(x) + ".ast.txt").c_str());
		indexFile = x;
	}

	void enableOutPut(bool x) 
	{
		outputfile = ofstream((string(indexFile) + ".yy.lex.st.txt").c_str());
		DEBUGMODE_LEX = DEBUGMODE_YACC = DEBUGMODE_ST = x; 
	}
		
	void enableOutPutAST(bool x) 
	{
		AST::outputfileAST = ofstream((string(indexFile) + ".ast.txt").c_str());
		DEBUGMODE_AST = x; 
	}
	
	void enableCommentingASMCode(bool x) { CommentingOnASMCode = x; }
	void enableCopyResultToClipboard(bool x) { CopyResultToClipboard = x; }



	deque<Error_info> _errors;

	int PrintErrorsStack()
	{
		for (std::deque<Error_info>::iterator it = _errors.begin(); it < _errors.end(); ++it)
		{
			(*it).toString();
			cout << endl;
		}
		return _errors.size();
	}


	void debuggerLEX(char * s) 
	{
		if (DEBUGMODE_LEX)
			outputfile << s << endl;
	}
	void debuggerLEX(char * s, int v)
	{
		if (DEBUGMODE_LEX)  
			outputfile << s << v << endl;
	}
	void debuggerLEX(char * s, char* v) 
	{
		if (DEBUGMODE_LEX)  
			outputfile << s << v << endl;
	}

	void debuggerYACC(char * s) 
	{
		if (DEBUGMODE_YACC) 
			outputfile << s << endl;
	}
	void debuggerYACC(char * s, int v) 
	{
		if (DEBUGMODE_YACC) 
			outputfile << s << v << endl;
	}
	void debuggerYACC(char * s, char* v) 
	{
		if (DEBUGMODE_YACC) 
			outputfile << s << v << endl;
	}


	void debugger(char * s) 
	{
		if (DEBUGMODE_ST) 
			outputfile << s << endl;
	}
	void debugger(char * s, int v)
	{
		if (DEBUGMODE_ST)
			outputfile << s << v << endl;
	}
	void debugger(char * s, char* v) 
	{
		if (DEBUGMODE_ST) 
			outputfile << s << v << endl;
	}




	void errorhandler(const char* s)
	{
		errorsCount++;

		Error_info error;
		error.colNo = col;
		error.lineNo = line;
		error.msg = s;
		_errors.push_back(error);
	}
	void errorhandler(char* s)
	{
		errorsCount++;

		Error_info error;
		error.colNo = col;
		error.lineNo = line;
		error.msg = s;

		_errors.push_back(error);
	}
	void errorhandler(char* msg, char* name)
	{
		errorsCount++;
		Error_info error;
		error.colNo = col;
		error.lineNo = line;
		error.msg = msg;
		error.name = name;

		_errors.push_back(error);
	}
	void warninghandler(char* s)
	{
		cout << "WARNING >> " << s << endl;
	}

	void checkDivideByZeroError(int x, int y)
	{
		if (y == 0)
			errorhandler("divide by zero");
	}


	void EatUntilGetPhpTag()
	{
		string somethingBeforPHPcode = "";
		char* c = new char[5];
		while (cin.eof() == false)
		{
			int i = 0;
			if ((c[i++] = cin.get()) == '<' &&
				(c[i++] = cin.get()) == '?' &&
				(c[i++] = cin.get()) == 'p' &&
				(c[i++] = cin.get()) == 'h' &&
				(c[i++] = cin.get()) == 'p')
				break;

			for (int j = 0; j <= i; j++)
			if (c[j] == '\n')
			{
				line++;
				col = 1;
			}

			somethingBeforPHPcode.append(c, i);
		}

		for (int i = 0; i < 5; i++)
			cin.unget();

		cout << "";
		if (DEBUGMODE_ST)
			if (somethingBeforPHPcode.size() > 1)
				debugger(strdup(somethingBeforPHPcode.c_str()), "\n------STRING WAS BEFORE PHP CODE------\n");
	}
	void EatUntilEndOfFile()
	{
		string somethingAfterPHPcode = "";
		for (char c; (c = cin.get()) != EOF;)
			somethingAfterPHPcode += c;

		cin.unget();

		cout << "";
		if (DEBUGMODE_ST)
			if (somethingAfterPHPcode.size() > 1)
				debugger("\n------STRING AFTER PHP CODE------", strdup(somethingAfterPHPcode.c_str()));
	}
	void EatUntilNewLine()
	{
		if (col == 0)
			return;
		string error;
		cin.putback(' ');
		for (char c; ;)
		{
			error += (c = cin.get());
			if (c == ';' || c == EOF || c == ' ') break;
			if (c == '\n')
			{
				line++;
				col = 1;
				break;
			}
		}

		//cin.unget();
		cin.putback('\n');
		cin.putback('\r');
		//errorhandler(error.c_str());
	}



	////////////////////////////////////////////////////////////////////////////////////

	//////

	//////

	//////

	////////////////////////////////////////////////////////////////////////////////////

	bool isClassStatic = false;
	bool isClassFinal = false;
	bool isClassAbstract = false;
	
	bool itisArrayVariable = false;


	AccessSpecifier access = AccessSpecifier::_private;
	StorageSpecifier storage = StorageSpecifier::_none;

	bool Optional_ref = false;
	char* returnType = "void";

	MyParser* _parser = new MyParser();

	stack<Type*> tmpType;

	void ClassDeclaration(char* name)
	{
		Type* t = new Type();
		t->setName(name);

		t = _parser->createType(t); // search in current scope
		if (t->thisClassHaveSomeErrors)
			errorhandler("Type is already exist", name);
		else
		{
			BlockScope* temp = t->getScope(); // this for searching in parents scopes
			while (temp != NULL)
			{
				Type* prnt = dynamic_cast<Type*>(temp->getOwner());
				if (prnt == NULL) break; // shouldn't happend but in case

				if (prnt != t && strcmp(prnt->getName(), name) == 0)
				{
					errorhandler("Type is already exist", name);
					break;
				}
				temp = temp->getParent();
			}
		}

		tmpType.push(t);
		tmpType.top()->setFinal(isClassFinal);
		tmpType.top()->setAbstract(isClassAbstract);
		tmpType.top()->setStatic(isClassStatic);

		ResetClassEnteryType();
		debugger("ST :: ClassDeclaration >> ", name);
	}

	vector<unknowenClassName*> unkowenClassName;
	void ClassDeclarationAddInheritedClass(char* name)
	{
		if (tmpType.empty())
			return;
		Type* t = _parser->FindClassByName(name);
		if (t == NULL)
		{
			unkowenClassName.push_back(new unknowenClassName(tmpType.top(), name, line, col));
		}
		else
		{
			if (t == tmpType.top())
			{
				errorhandler("a class cannot be its own base class", name);
				return;
			}

			if (t->getFinal())
			{
				errorhandler("Cannot inherit from final class", name);
				return;
			}

			if (t->hasPrivateConstructor())
			{
				errorhandler("Cannot inherit from class with private Constructor", name);
				return;
			}
			tmpType.top()->setInheritedType(t);
		}

		debugger("ST :: ClassDeclarationAddInheritedClass >> ", name);
	}
	bool checkForInheritenceLoop(Type* a, Type* b)
	{
		Type* mover = a;
		mover->setInheritedType(b);
		while (mover)
		{
			mover = mover->getInheritedType();
			if (mover == a)
				return false;
		}
		return true;
	}
	void ClassDeclarationAddImplementInterface(char* name)
	{
		debugger("ST :: ClassDeclarationAddImplementInterface >> ", name);
	}
	Type* ClassDeclarationEnd(Type * tt)
	{
		Type* t = tt;
		if (t == NULL)
			if (tmpType.empty())
				return NULL;
			else
				t = tmpType.top();

		if (!t->hasConstructor) // this for create defualt constructor if the class doesn't have one
		{
			Function* f = new Function(t->getName(), false);
			if(t->getAbstract())
				f->setAccess(AccessSpecifier::_protected);
			else
				f->setAccess(AccessSpecifier::_public);

			f->setStorage(StorageSpecifier::_none);
			f->setSignature(NULL);
			f->setReturnType("void");
			f->setIsConstructor(true);
			f->setReturnType(t->getName());
			f->isInsideClass = true;
			t->hasConstructor = true;

			f->isAutoGeneratedDefaultConsturactor = true;


			// create AST node for this autogenerated consturctor
			TreeNode *m = new TreeNode();
			m->symbolTableElement = f;
			m->left = NULL;
			m->right = NULL;
			m->nodeType = functionNode;

			TreeNode *n = new TreeNode();
			n->left = m;
			n->nodeType = classListNode;

			AST* ast = new AST();
			TreeNode* x = AST::CurrntPointer;
			x = x->left;
			while (x->right)
			{
				x = x->right;
			}
			x->right = n;


			_parser->createTypeFunctionHeader(f);
			_parser->finishFunctionDeclaration(f);

			debugger("ST :: ClassDeclarationEnd >> defualt constructor has been created for this class");
		}

		if (t->getInheritedType() != NULL && t->getFatherConsturactor()->getParametersCount() - 1 != 0 && t->getConsturactor()->getHasSuper() == false)
		{
			errorhandler("can't call parent Consturactor, you must add Consturactor to this class with super keyword");
		}

		DidThisClassImplementsItsBaseAbstractFunction(t);

		if (!t->getInheritedType()) //this for make all classes inherit form super class 'object'
			if (strcmp(t->getName(), OBJ) != 0)
				t->setInheritedType(_parser->FindClassByName(OBJ));

		if (tt == NULL)
		{
			_parser->finishTypeDeclaration(t);
			tmpType.pop();
		}

		debugger("ST :: ClassDeclarationEnd");
		return t;
	}

	void DidThisClassImplementsItsBaseAbstractFunction(Type* t)
	{
		if (t->getInheritedType() != NULL) // this for check if this class implemnts all its base class abstract functions
		{
			Type* father = t->getInheritedType();
			Type* son = t;
			if (father->getAbstract() && !son->getAbstract())
			{
				vector<Symbol*> f = father->getEverythingWithInherited();
				vector<Symbol*> s = son->getEverything();

				for (vector<Symbol*>::iterator it = f.begin(); it < f.end(); ++it)
				{
					Function* fun = (dynamic_cast<Function*>(*it));
					if (!fun)continue;
					if (fun->getStorage() == StorageSpecifier::_abstract)
					{
						bool notImplemented = true;
						for (vector<Symbol*>::iterator jt = s.begin(); jt < s.end(); ++jt)
							if (strcmp((*jt)->getName(), fun->getName()) == 0)
							{
								notImplemented = false;
								break;
							}

						if (notImplemented)
						{
							son->setAbstract(true);
							if (son->getConsturactor()->isAutoGeneratedDefaultConsturactor)
								son->getConsturactor()->setAccess(_protected);
							else if(son->getConsturactor()->getAccess() == _public)
								errorhandler("public constructor not allowed in abstract class", son->getName());

							//errorhandler("this class didn't implement its base abstract function", fun->getName());
							// did this must be error or just convert son class to abstract class
							////////////////////////////////////////////////////////////////////////////////////////////////////////
							////////////////////////////////////////////////////////////////////////////////////////////////////////
							////////////////////////////////////////////////////////////////////////////////////////////////////////
							////////////////////////////////////////////////////////////////////////////////////////////////////////
							////////////////////////////////////////////////////////////////////////////////////////////////////////
							////////////////////////////////////////////////////////////////////////////////////////////////////////
							////////////////////////////////////////////////////////////////////////////////////////////////////////
							////////////////////////////////////////////////////////////////////////////////////////////////////////
						}
					}
				}
			}
		}
	}

	stack<Function*> tmpfunction;
	Signature* sign = NULL;
	Variable* addParametertoFunction(char* type, char* name, char* value,TreeNode* t)
	{
		if (sign == NULL)
			sign = new Signature();
		if (sign->getParameter(name) != NULL)
			errorhandler("dublicate parameter name", name);

		if (value != NULL && strcmp(value, "") != 0)
			if(Optional_ref)
				errorhandler("optional parameter cannot pass by reference", name);

		Variable* v = new Variable(name, type, value);
		v->setIsParamter();
		v->setIsReferenceParamter(Optional_ref);
		v->isArray = itisArrayVariable;
		sign->addParamterToList(v, t);
		debugger("ST :: addParametertoFunction >> ", name);

		return v;
	}
	void FunctionDeclaration(char* name, bool isInClass = true)
	{
		Function* f = _parser->FindFunctionByName(name);

		if (f != NULL)
			errorhandler("Function is already exist in same scope", name);

		f = new Function(name, !isInClass);

		f->setReturnType(returnType);
		returnType = "void";

		f->setSignature(sign);
		sign = NULL;

		if (isInClass && !tmpType.empty())
		{
			f->setAccess(access);
			f->setStorage(storage);
			if (storage == StorageSpecifier::_abstract) // if any function is abstract than the whole class is abstract
				tmpType.top()->setAbstract(true);

			ResetMemberAccess();
			ResetMemberStorage();

			if (strcmp(tmpType.top()->getName(), name) == 0)
			{
				f->setIsConstructor(true);
				tmpType.top()->hasConstructor = true;

				if (strcmp(f->getReturnType(), "$") != 0)
					errorhandler("Constructor must have no return type", name);
				else
					f->setReturnType("void");

				if (tmpType.top()->getAbstract() && f->getAccess() == _public)
					errorhandler("public constructor not allowed in abstract class",name);

			}

			didThisFunctionIsOverrideOrNormal(tmpType.top(), f);
		}

		if (strcmp(f->getReturnType(), "$") == 0)
			f->setReturnType("void");

		tmpfunction.push(f);

		_parser->createTypeFunctionHeader(f);
		debugger("ST :: FunctionDeclaration >> ", name);
	}
	void didThisFunctionIsOverrideOrNormal(Type *t, Function*f)
	{
		if (!f || f->getStorage() == StorageSpecifier::_static)
			return;

		// check if this function is override function or not
		if (t->getInheritedType() != NULL)
		{
			vector<Symbol*> fatherClass = t->getInheritedType()->getEverythingWithInherited();

			for (vector<Symbol*>::iterator jt = fatherClass.begin(); jt < fatherClass.end(); ++jt)
			{
				Function* fatherFunction = dynamic_cast<Function*>(*jt);
				if (fatherFunction == NULL || fatherFunction->getStorage() == StorageSpecifier::_static)
					continue;

				if (fatherFunction != NULL && strcmp(fatherFunction->getName(), f->getName()) == 0)
				{
					if (fatherFunction->getStorage() == StorageSpecifier::_final)
					{
						errorhandler("cannot override final function", f->getName());
						break;
					}

					if (fatherFunction->getAccess() == AccessSpecifier::_public && f->getAccess() != AccessSpecifier::_public)
						errorhandler("base class function is public,this override function must be public", f->getName());
					if (fatherFunction->getAccess() == AccessSpecifier::_protected && f->getAccess() == AccessSpecifier::_private)
						errorhandler("base class function is protacted, this override function must be protacted or public", f->getName());

					f->isOverride = true;
					f->fathersOverridedFunction = fatherFunction;
					break;
				}
			}
		}
	}
	void checkAbstractFunction(bool isFunctionHasBody)
	{
		if (tmpType.empty())
			return;

		if (tmpfunction.top()->getStorage() == StorageSpecifier::_abstract)
		{
			if (isFunctionHasBody)
				errorhandler("abstract function should has no body", tmpfunction.top()->getName());
			if (tmpfunction.top()->getAccess() == AccessSpecifier::_private)
				errorhandler("abstract function cannot be private", tmpfunction.top()->getName());

			tmpType.top()->setAbstract(true);
		}
		else
		{
			if (!isFunctionHasBody)
				errorhandler("non-abstract function should has body", tmpfunction.top()->getName());
		}
	}

	Function* FunctionDeclarationEnd(bool isInsideClass)
	{
		if (tmpfunction.empty())
			return NULL;

		Function* f = tmpfunction.top();
		f->isInsideClass = isInsideClass;

		if (f->isInsideClass)
			if (f->getIsConsturctor())
				if (tmpType.top()->getInheritedType() != NULL)
					if (f->getHasSuper() == false)
						if (tmpType.top()->getFatherConsturactor() != NULL)
							if (tmpType.top()->getFatherConsturactor()->getParametersCount() - 1 != 0)
								errorhandler("can't call parent Consturactor, you must add super keyword");


		if (f->isAbstract() == false)
			if (f->getIsConsturctor() == false)
				if (strcmp(f->getReturnType(), "void") != 0)
					if (ASTHelper::recheckForAllPathReturnValue(AST::CurrntPointer) == false)
						errorhandler("not all paths return values", f->getName());

		_parser->finishFunctionDeclaration(f);
		tmpfunction.pop();
		debugger("ST :: FunctionDeclarationEnd");
		return f;
	}

	
	int statmentNumber = 0;
	void resetStatementNumber()
	{
		statmentNumber = 0;
	}
	void IncreceStatementNumber()
	{
		statmentNumber++;
	}
	vector<RecheckSuperKeyword*> recheckSuperKeyword;
	Function* SuperKeywordShowedUp()
	{
		if (tmpfunction.empty() || tmpfunction.top()->getIsConsturctor() == false)
			errorhandler("super keyword is not in Consturctor function");
		else if (tmpfunction.top()->getHasSuper() == true)
			errorhandler("too many super keywords");
		else
		{
			if (statmentNumber > 0)
				errorhandler("super keyword is not first statement");
			else
			{
				tmpfunction.top()->setHasSuper(true);
				recheckSuperKeyword.push_back(new RecheckSuperKeyword(tmpType.top()));
				return tmpType.top()->getFatherConsturactor();
			}
		}

		return NULL;
	}


	void itsArrayVariable(bool on)
	{
		itisArrayVariable = on;
	}
	bool itsDataMember = false;
	void addDataMemeberStart()
	{
		if (storage == StorageSpecifier::_abstract)
			errorhandler("Data Member cannot be abstract");
		itsDataMember = true;
		debugger("ST :: addDataMemeberStart");
	}
	void addDataMemeberEnd()
	{
		itsDataMember = false;
		ResetMemberAccess();
		ResetMemberStorage();
		debugger("ST :: addDataMemeberEnd");
	}
	Variable* addVariable(char* type, char* name, bool isConst)
	{
		return addVariable(type, name, "", isConst);
	}
	Variable* addVariable(char* type, char* name, char* value, bool isConst)
	{
		Variable* v = NULL;
		if (itsDataMember && !tmpType.empty())
		{
			DataMember* d = dynamic_cast<DataMember*>(tmpType.top()->getDataMemberFromCurrentScopeOnly(name));
			if (d != NULL)
				errorhandler("variable exist", name);
			else
			{
				d = new DataMember(name, type, value);
				d->setAccess(access);
				d->setStorage(storage);
				d->isConst = isConst;
				d->isArray = itisArrayVariable;
				
				_parser->st->currScope->addSymbol(d);

				v = d->ConvertToVariable();
			}
		}
		else
		{
			v = dynamic_cast<Variable*>(_parser->st->currScope->get(name));
			if (v != NULL)
				errorhandler("variable exist", name);
			else
			{
				v = new Variable(name, type, value);
				v->isConst = isConst;
				v->isArray = itisArrayVariable;
				_parser->st->currScope->addSymbol(v);

				//if (strcmp(type, "double") == 0)
				//	_parser->st->currScope->size += 8;
				//else
					_parser->st->currScope->size += 4;
			}
		}
		debugger("ST :: addVariable >> ", name);
		return v;
	}
	//Variable* tmpVar = NULL;

	Variable* addStaticVariable(char* type, char* name)
	{
		return addStaticVariable(type, name, "");
	}
	Variable* addStaticVariable(char* type, char* name, char* value)
	{
		StorageSpecifier tmp = storage;
		storage = StorageSpecifier::_static;
		Variable* v = addVariable(type, name, value, false);
		storage = tmp;

		_parser->st->currScope->size -= 4;

		return v;
	}

	vector<unknowenVariablesCalling*> unkowenVariable;
	Variable* callVariable(char* name)
	{
		Variable* v = _parser->st->getVariableFromCurrentScope(name);
		if (v == NULL)   // this for searcing in datamermber of class 
		{
			if (tmpType.empty())
				errorhandler("variable not found", name);
			else
			{
				bool staticFunction = _parser->st->isTheCurrntScopeBeingInsideStaticFunction();

				DataMember* d = NULL;
				if (!tmpType.empty())
					d = tmpType.top()->getDataMember(name);

				if (d == NULL)
				{
					if (!tmpType.empty())
					{
						unkowenVariable.push_back(new unknowenVariablesCalling(tmpType.top(), name, "", line, col, false, staticFunction));
						return NULL;
					}
				}
				else
				{
					if (staticFunction && d->getStorage() != StorageSpecifier::_static)
						errorhandler("static function cannot access to non-static members", name);
					else
						return d->ConvertToVariable();
				}
			}
		}

		debugger("ST :: callVariable >> ", name);
		return v;
	}

	vector<unknowenFunctionCalling*> unkowenFunction;
	Function* callFunction(char* name)
	{
		Function* f = _parser->st->getFunctionFromCurrentScope(name);

		bool staticFunction = _parser->st->isTheCurrntScopeBeingInsideStaticFunction();

		if (f == NULL)
		{
			if (tmpType.empty())
			{
				unknowenFunctionCalling* d = new unknowenFunctionCalling(NULL, name, line, col, false, staticFunction);
				d->CurrScope = _parser->st->currScope;
				unkowenFunction.push_back(d);
				return NULL;
			}
			else
			{
				unknowenFunctionCalling* d = new unknowenFunctionCalling(tmpType.top(), name, line, col, false, staticFunction);
				d->CurrScope = _parser->st->currScope;
				unkowenFunction.push_back(d);
				return NULL;
			}
		}
		else
		{
			if (staticFunction && f->getStorage() != StorageSpecifier::_static)
			{
				errorhandler("static function cannot access to non-static members", name);
				return NULL;
			}
		}

		debugger("ST :: callFunction >> ", name);

		return f;
	}
	/*void checkFunctionCallParametersWithFunctionArguments(Function* f)
	{
	Signature* s = f->getSignature();
	Variable* tmp;
	int j = 0;
	for (vector<Variable*>::iterator i = functionCallParameters.begin(); i < functionCallParameters.end(); i++)
	{
	if ((*i) == NULL)
	continue;

	tmp = s->getParameter(j);
	if (tmp == NULL)
	errorhandler("too many arguments in function call", (*i)->getName());
	else if (strcmp(tmp->gettype(), (*i)->gettype()) != 0)
	errorhandler("argument not match with parameter type", (*i)->getName());
	j++;
	}
	if (s->getParameter(j) != NULL)
	errorhandler("too few arguments in function call");
	}*/

	void startNewScope()
	{
		_parser->addNewScopeOfNoObject();
		debugger("ST :: startNewScope >> ");
	}
	int closeScope()
	{
		int size = 0;
		_parser->closeNewScopeOfNoObject(size);
		debugger("ST :: closeScope >> ");
		return size;
	}

	vector<UnknowenDataMember*> unkowenDataMember;
	Variable* findInstanceVariable(Symbol* tt, char* name)
	{
		if (tt == NULL && unkowenDataMember.size() > 0)
			unkowenDataMember.push_back(new UnknowenDataMember(tt, name, line, col, _parser->st->currScope, unkowenDataMember.at(unkowenDataMember.size() - 1)));
		else
			unkowenDataMember.push_back(new UnknowenDataMember(tt, name, line, col, _parser->st->currScope, NULL));
		return NULL;
	}
	Variable* findInstanceVariableHelper(char* name, Variable* t)
	{
		if (t == NULL)
			return NULL;
		Type* tt = (Type*)t->GetClassType();
		if (tt == NULL)
			return NULL;
		DataMember*d = tt->getDataMember(name);

		if (d == NULL)   // this for searcing in datamermber of class 
			errorhandler("variable not found", name);
		else
		{
			if (d->getStorage() == _static)
				errorhandler("can't access to static variable with the object operetor -> ", name);
			else
			{
				bool isCurrntScopeIsInSameClass = _parser->st->isCurrntScopeIsInSameClass(tt);
				if (!isCurrntScopeIsInSameClass)
				{
					if (d->getAccess() == _private)
						errorhandler("can't access to private variable in the class", name);
					else if (d->getAccess() == _protected)
						errorhandler("can't access to protected variable in the class", name);
					else
						return d->ConvertToVariable();
				}
				else
					return d->ConvertToVariable();
			}
		}
		return NULL;
	}

	vector<UnknowenInstanceFunctionCalling*> unknowenInstanceFunctionCalling;
	Function* findInstanceFunction(Symbol* tt, char* name)
	{
		if (tt)
			unknowenInstanceFunctionCalling.push_back(new UnknowenInstanceFunctionCalling(tt, name, line, col, _parser->st->currScope));
		return NULL;
	}
	Function* findInstanceFunctionHelper(char* name, Variable* t)
	{
		if (t == NULL)
			return NULL;
		Type* tt = (Type*)(t->GetClassType());
		if (tt == NULL)
			return NULL;
		Function*d = tt->getFunction(name);

		if (d == NULL)
			errorhandler("function not found", name);
		else
		{
			if (d->getStorage() == _static)
				errorhandler("can't access to static Function with the object operetor -> ", name);
			else
			{
				bool isCurrntScopeIsInSameClass = _parser->st->isCurrntScopeIsInSameClass(tt);
				if (!isCurrntScopeIsInSameClass)
				{
					if (d->getAccess() == _private)
						errorhandler("can't access to private Function in the class", name);
					else if (d->getAccess() == _protected)
						errorhandler("can't access to protected Function in the class", name);
					else
						return d;
				}
				else
					return d;
			}
		}
		return NULL;
	}

	Variable* findStaticMember(char* ClassName, char* name)
	{
		Variable* v = NULL;
		bool Self = strcmp(ClassName, "self") == 0;
		bool Parent = strcmp(ClassName, "parent") == 0;

		bool staticFunction = _parser->st->isTheCurrntScopeBeingInsideStaticFunction();
		if ((Self || Parent) && staticFunction)
		{
			errorhandler(Self ? "cannot use 'self' inside static function" : "cannot use 'parent' inside static function");
		}
		else
		{
			if (Self)
			{
				BlockScope* tmp = _parser->st->currScope;
				Type * Class = NULL;
				while (tmp != NULL)
				{
					Class = dynamic_cast<Type*>(tmp->getOwner());
					if (Class)
						break;
					tmp = tmp->getParent();
				}
				if (!Class)
					errorhandler("the 'self' Keyword cannot be used outside a class");
				else
				{
					DataMember* d = Class->getDataMember(name);
					if (d == NULL)
					{
						unkowenVariable.push_back(new unknowenVariablesCalling(Class, name, "", line, col, false, false));
						return NULL;
					}
					else // means the variable was found and everything is ok
						v = d->ConvertToVariable();
				}
			}
			else if (Parent)
			{
				BlockScope* tmp = _parser->st->currScope;
				Type * Class = NULL;
				while (tmp != NULL)
				{
					Class = dynamic_cast<Type*>(tmp->getOwner());
					if (Class)
					{
						if (Class->getInheritedType())
							Class = Class->getInheritedType();
						else
						{
							unkowenVariable.push_back(new unknowenVariablesCalling(Class, name, "", line, col, true, false));
							return NULL;
						}
						break;
					}
					tmp = tmp->getParent();
				}
				if (!Class)
					errorhandler("the 'parent' Keyword cannot be used outside a class");
				else
				{
					DataMember* d = Class->getDataMember(name);
					if (d == NULL)
						errorhandler("Cannot find the variable in parent class", name);
					//unkowenVariable.push_back(new unknowenVariablesCalling(Class, name, "", line, col));
					else
					{
						if (d->getAccess() == AccessSpecifier::_private)
							errorhandler("Cannot access to private variable");
					}
				}
			}
			else
			{
				Type* className = _parser->FindClassByNameWithoutInheritance(ClassName);
				if (className == NULL)
				{
					unkowenVariable.push_back(new unknowenVariablesCalling(name, ClassName, _parser->st->currScope, line, col));
					return NULL;
				}
				else
				{
					DataMember* d = dynamic_cast<DataMember*>(className->get(name));
					if (!d)
					{
						unkowenVariable.push_back(new unknowenVariablesCalling(name, ClassName, _parser->st->currScope, line, col));
						return NULL;
					}
					else
						if (d->getAccess() != AccessSpecifier::_public || d->getStorage() != StorageSpecifier::_static)
							errorhandler("the variable is not public or it is not static", name);
						else // the variable was found and it's ok
							v = d->ConvertToVariable();
				}
			}
		}
		return v;
	}
	Function* findStaticFunction(char* ClassName, char* name)
	{
		bool Self = strcmp(ClassName, "self") == 0;
		bool Parent = strcmp(ClassName, "parent") == 0;

		bool staticFunction = _parser->st->isTheCurrntScopeBeingInsideStaticFunction();
		if ((Self || Parent) && staticFunction)
			errorhandler(Self ? "cannot use 'self' inside static function" : "cannot use 'parent' inside static function");
		else
		{
			if (Self)
			{
				BlockScope* tmp = _parser->st->currScope;
				Type * Class = NULL;
				while (tmp != NULL)
				{
					Class = dynamic_cast<Type*>(tmp->getOwner());
					if (Class)
						break;
					tmp = tmp->getParent();
				}
				if (!Class)
					errorhandler("the 'self' Keyword cannot be used outside a class");
				else
				{
					Function* d = dynamic_cast<Function*>(Class->get(name));
					if (d == NULL)
						unkowenFunction.push_back(new unknowenFunctionCalling(Class, name, line, col, false, false));
					return d;
				}
			}
			else if (Parent)
			{
				BlockScope* tmp = _parser->st->currScope;
				Type * Class = NULL;
				while (tmp != NULL)
				{
					Class = dynamic_cast<Type*>(tmp->getOwner());
					if (Class)
					{
						if (Class->getInheritedType())
							Class = Class->getInheritedType();
						else
						{
							unkowenFunction.push_back(new unknowenFunctionCalling(Class, name, line, col, true, false));
							return NULL;
						}
						break;
					}
					tmp = tmp->getParent();
				}
				if (!Class)
					errorhandler("the 'parent' Keyword cannot be used outside a class");
				else
				{
					Function* d = dynamic_cast<Function*>(Class->get(name));
					if (d == NULL)
						errorhandler("Cannot find function in parent class");
					else
					{
						if (d->getAccess() == AccessSpecifier::_private)
							errorhandler("Cannot access to private function");
					}
				}
			}
			else
			{
				Type* className = _parser->FindClassByNameWithoutInheritance(ClassName);
				if (className == NULL)
				{
					unkowenFunction.push_back(new unknowenFunctionCalling(name, ClassName, _parser->st->currScope, line, col));
					return NULL;
				}
				else
				{
					Function* v = dynamic_cast<Function*>(className->get(name));
					if (!v)
					{
						unkowenFunction.push_back(new unknowenFunctionCalling(name, ClassName, _parser->st->currScope, line, col));
						return NULL;
					}
					else
						if (v->getAccess() != AccessSpecifier::_public || v->getStorage() != StorageSpecifier::_static)
							errorhandler("the function is not public or it is not static", name);
						else
							return v;
				}
			}
		}
		return NULL;
	}

	Type* findClassName(char* name, bool forConstruactor, Type*lastClass)
	{
		if (strcmp(name, "void") == 0)
			return NULL;
		
		if (lastClass == NULL && tmpType.empty() != true)
			lastClass = tmpType.top();

		Type* className = _parser->FindClassByNameWithoutInheritance(name);
		if (className == NULL)
			unkowenClassName.push_back(new unknowenClassName(name, lastClass, _parser->st->currScope, line, col, forConstruactor));
		if (forConstruactor)
			if (className->hasPrivateConstructor() && !(_parser->st->isCurrntScopeIsInSameClass(className)))
				errorhandler("unable to create instance from class with private consturactor", name);
			else
			{
				if (lastClass != NULL)
				{
					if (className->hasProtectedConstructor() && !(_parser->st->isCurrntScopeIsInSameClass(className)) && !(lastClass->isThisOneOfThatClassChildren(className)))
						errorhandler("unable to create instance from class with protected consturactor", name);
				}
				else if (className->hasProtectedConstructor() && !(_parser->st->isCurrntScopeIsInSameClass(className)))
					errorhandler("unable to create instance from class with protected consturactor", name);
			}

		return className;
	}

	vector<unknowenStaticClassName*> unkowenStaticClassName;
	Type* findStaticClassName(char* name1, char* name2, bool forConstruactor)
	{
		if ((strcmp(name1, "void") * strcmp(name2, "void")) == 0)
			return NULL;

		unkowenStaticClassName.push_back(
			new unknowenStaticClassName(
				name1,
				name2,
				_parser->st->currScope, 
				line,
				col,
				forConstruactor,
				true));
		return NULL;
	}

	Type* findInstanceClassName(char* var, char* cla)
	{
		if ((strcmp(cla, "void") == 0))
			return NULL;

		unkowenStaticClassName.push_back(
			new unknowenStaticClassName(
				var,
				cla,
				_parser->st->currScope,
				line,
				col,
				true,
				false));
		return NULL;
	}

	Type* findStaticClassNameHelper(char* name1, char* name2, bool forConstruactor,bool staticCalling)
	{
		Type* outer = NULL;
		if (staticCalling)
			outer = _parser->FindClassByName(name1);
		else
		{
			Variable * v = callVariable(name1);
			if (v)
				outer = (Type*)v->GetClassType();
		}
		if (outer == NULL)
		{
			errorhandler("cannot find the class", name1);
			return NULL;
		}


		Type* iner = dynamic_cast<Type*>(outer->get(name2));
		if (iner == NULL)
			errorhandler("cannot find the class", name2);
		else
		{
			if (forConstruactor)
				if (iner->getStatic() == false && staticCalling)
					errorhandler("the class is not static", name2);
				else if (iner->hasPrivateConstructor())
					errorhandler("unable to create instance from class with private consturactor", name2);
				else if (iner->hasProtectedConstructor())
					errorhandler("unable to create instance from class with protected consturactor", name2);
		}
		return iner;
	}
	void EndOfPhpCode()
	{


		for (vector<unknowenClassName*>::iterator it = unkowenClassName.begin(); it < unkowenClassName.end(); ++it)
		{
			line = (*it)->line;
			col = (*it)->col;

			if ((*it)->isForInheritnce)
			{
				_parser->st->currScope = (*it)->child->getScope();
				Type* t = _parser->FindClassByName((*it)->base);

				if (t)
				{
					if (t->getFinal())
						errorhandler("Cannot inherit from final class", (*it)->child->getName());
					else if (t->hasPrivateConstructor())
						errorhandler("Cannot inherit from class with private Constructor", (*it)->child->getName());
					else if (!checkForInheritenceLoop((*it)->child, t))
						errorhandler("there is inheritence loop", (*it)->child->getName());
					else
					{
						(*it)->child->setInheritedType(t);
						DidThisClassImplementsItsBaseAbstractFunction((*it)->child);

						// for each functions in son, search for error in overriding function
						vector<Symbol*> Class = (*it)->child->getEverything();
						for (vector<Symbol*>::iterator jt = Class.begin(); jt < Class.end(); ++jt)
						{
							Function* F = dynamic_cast<Function*>(*jt);
							if (F)
								didThisFunctionIsOverrideOrNormal((*it)->child, F);
						}

						ClassDeclarationEnd((*it)->child);
					}
				}
				else
					errorhandler("Cannot find base class", (*it)->child->getName());
			}
			else // means it's for create veriable or return type or something other
			{
				Type* className = _parser->FindClassByNameWithoutInheritance((*it)->base, (*it)->currntScope);
				if (className == NULL)
					errorhandler("Cannot find the class", (*it)->base);
				else
				{
					(*it)->CurrntPointer->addSymbolTableElement(className);

					if ((*it)->forConstruactor)
						if (className->hasPrivateConstructor() && !(_parser->st->isCurrntScopeIsInSameClass(className)))
							errorhandler("unable to create instance from class with private consturactor", (*it)->base);
						else 
						{
							if ((*it)->thisClass != NULL)
							{
								if (className->hasProtectedConstructor() && !(_parser->st->isCurrntScopeIsInSameClass(className)) && !((*it)->thisClass->isThisOneOfThatClassChildren(className)))
									errorhandler("unable to create instance from class with protected consturactor", (*it)->base);
							}
							else if (className->hasProtectedConstructor() && !(_parser->st->isCurrntScopeIsInSameClass(className)))
								errorhandler("unable to create instance from class with protected consturactor", (*it)->base);
						}
				}
			}
		}
		unkowenClassName.clear();

		RecheckSuperKeyword * R;
		for (int i = 0; i < recheckSuperKeyword.size(); i++)
		{
			R = recheckSuperKeyword.at(i);
			R->CurrntPointer->symbolTableElement = R->type->getFatherConsturactor();
		}

		ASTHelper::recheckForSymbolTableElements(AST::CurrntPointer);


		for (int i = 0; i < unkowenStaticClassName.size(); i++)
		{
			unknowenStaticClassName *d = unkowenStaticClassName.at(i);
			line = d->line;
			col = d->col;
			_parser->st->currScope = d->currntScope;

			Type* t = findStaticClassNameHelper(d->outter, d->inner, d->forConstruactor,d->staticCalling);
			if (t)
				d->CurrntPointer->addSymbolTableElement(t);
		}
		unkowenStaticClassName.clear();


		ASTHelper::recheckForSymbolTableElements(AST::CurrntPointer);


		for (vector<unknowenVariablesCalling*>::iterator it = unkowenVariable.begin(); it < unkowenVariable.end(); ++it)
		{
			line = (*it)->line;
			col = (*it)->col;

			if ((*it)->isParentKeywordIssue)
			{
				if ((*it)->type == NULL)
					continue;

				if ((*it)->type->getInheritedType() == NULL)
					errorhandler("the 'parent' Keyword cannot be used without inheritence");
				else
				{
					Type* t = (*it)->type->getInheritedType();
					DataMember* d = t->getDataMember((*it)->var);
					if (d == NULL)
						errorhandler("Cannot find variable in parent class");
					else if (d->getAccess() == AccessSpecifier::_private)
						errorhandler("Cannot access to private variable");
					else
						(*it)->CurrntPointer->addSymbolTableElement(d->ConvertToVariable());
				}
			}
			else if ((*it)->isStaticCalling)
			{
				Type* className = _parser->FindClassByNameWithoutInheritance((*it)->ClassName);
				if (className == NULL)
					errorhandler("Cannot find the class", (*it)->ClassName);
				else
				{
					DataMember* v = dynamic_cast<DataMember*>(className->get((*it)->VriableName));
					if (!v)
						errorhandler("Cannot find the static varible in class", (*it)->VriableName);
					else
						if (v->getAccess() != AccessSpecifier::_public || v->getStorage() != StorageSpecifier::_static)
							errorhandler("the variable is not public or is not static", (*it)->VriableName);
						else // the variable was found and it's ok
							(*it)->CurrntPointer->addSymbolTableElement(v->ConvertToVariable());
				}
			}
			else
			{
				Type* t = (*it)->type;
				DataMember* d = NULL;

				if (t)
					d = t->getDataMember((*it)->var);

				if (d == NULL)
					errorhandler("variable not found", (*it)->var);
				else
				{
					if ((*it)->isInsideStaticFunction && d->getStorage() != StorageSpecifier::_static)
						errorhandler("static function cannot access to non-static members", (*it)->var);
					else
					{
						//if (d->getAccess() == AccessSpecifier::_private)
						//	errorhandler("cannot access to private members", (*it)->var);
						//else
						(*it)->CurrntPointer->addSymbolTableElement(d->ConvertToVariable());
					}
				}
			}
		}
		unkowenVariable.clear();

		for (vector<unknowenFunctionCalling*>::iterator it = unkowenFunction.begin(); it < unkowenFunction.end(); ++it)
		{
			line = (*it)->line;
			col = (*it)->col;

			if ((*it)->isParentKeywordIssue)
			{
				if ((*it)->type == NULL)
					continue;

				if ((*it)->type->getInheritedType() == NULL)
					errorhandler("the 'parent' Keyword cannot be used without inheritence");
				else
				{
					Type* t = (*it)->type->getInheritedType();
					Function* d = dynamic_cast<Function*>(t->get((*it)->name));
					if (d == NULL)
						errorhandler("Cannot find funtion in parent class");
					else if (d->getAccess() == AccessSpecifier::_private)
						errorhandler("Cannot access to private function");
				}
			}
			else if ((*it)->isStaticCalling)
			{
				Type* className = _parser->FindClassByNameWithoutInheritance((*it)->ClassName);
				if (className == NULL)
					errorhandler("Cannot find the class", (*it)->ClassName);
				else
				{
					Function* v = dynamic_cast<Function*>(className->get((*it)->name));
					if (!v)
						errorhandler("Cannot find the function in the class", (*it)->name);
					else
						if (v->getAccess() != AccessSpecifier::_public || v->getStorage() != StorageSpecifier::_static)
							errorhandler("the function is not public or it is not static", (*it)->name);
						else // the function was found and it's ok
							(*it)->CurrntPointer->addSymbolTableElement(v);
				}
			}
			else
			{
				Type* t = (*it)->type;
				Function* f = _parser->st->getFunctionFromCurrentScope((*it)->name, (*it)->CurrScope);

				if (f == NULL)
					errorhandler("Function not found", (*it)->name);
				else if ((*it)->isInsideStaticFunction && f->getStorage() != StorageSpecifier::_static)
					errorhandler("static function cannot access to non-static members", (*it)->name);
				else
					(*it)->CurrntPointer->addSymbolTableElement(f);
			}
		}
		unkowenFunction.clear();

		Variable* pv = NULL;
		for (int i = 0; i < unkowenDataMember.size(); i++)
		{
			UnknowenDataMember* d = unkowenDataMember.at(i);
			line = d->line;
			col = d->col;
			_parser->st->currScope = d->curruntScope;

			Variable * v = NULL;
			
			if (d->type != NULL)
				v = findInstanceVariableHelper(d->name, (Variable*)d->type);
			else
				v = findInstanceVariableHelper(d->name, pv);

			if (v)
				d->CurrntPointer->addSymbolTableElement(v);

			pv = v;
		}
		unkowenDataMember.clear();

		for (int i = 0; i < unknowenInstanceFunctionCalling.size(); i++)
		{
			UnknowenInstanceFunctionCalling* f = unknowenInstanceFunctionCalling.at(i);
			line = f->line;
			col = f->col;
			_parser->st->currScope = f->curruntScope;

			Function * v = NULL;
			//if (f->CurrntPointer->left && f->CurrntPointer->left->nodeType == classTypeNameNode && f->CurrntPointer->left->symbolTableElement)
			//	v = findInstanceFunctionHelper(f->name, (Type*)f->CurrntPointer->left->symbolTableElement); 
			//else if ((Variable*)f->type && ((Variable*)f->type)->GetClassType())
				v = findInstanceFunctionHelper(f->name, (Variable*)f->type);
			if (v)
				f->CurrntPointer->addSymbolTableElement(v);
		}
		unknowenInstanceFunctionCalling.clear();


		ASTHelper::recheckForSymbolTableElements(AST::CurrntPointer);
		ASTHelper::recheckForVariablesOffest(AST::CurrntPointer);
	}

	clock_t tStart;


	bool before_main()
	{
		cout << "welcome to compiler project\n";

		if (!ifstream(indexFile))
		{
			errorhandler("Cannot find the file", indexFile);
			return false;
		}
		cout << "reading the input file . . .\n";

		freopen(indexFile, "r", stdin);

		tStart = clock();
		return true;
	}
	int after_main(TreeNode* t)
	{
		cout << "\n------------------------------------------------------\n";
		cout << "\n\tErrors count: " << errorsCount << endl;
		cout << "\n------------------------------------------------------\n";
		if (errorsCount == 0)
			cout << "\n\tbuild Ast Tree successfuly" << endl;
		else
			cout << "\n\tbuild failed, fix the error and try again" << endl;
		cout << "\n------------------------------------------------------\n";

		if (PrintErrorsStack() == 0)
		{
			if (DEBUGMODE_AST)
				AST::print(t, 0);

			if (generateCode(t) == 0)
			{
				cout << "\n\t Code has been generated to index.asm" << endl;
				cout << "\n------------------------------------------------------\n";
			}

		}

		cout << "\n\n\nFinish in: " << ((double)(clock() - tStart) / CLOCKS_PER_SEC) << " s\n";

		freopen("CON", "r", stdin);		

		system("pause");
		return errorsCount;
	}

	bool includeFile(char* f, bool require)
	{
		string file = string(f);
		if (file.empty() || file.size() <= 2)
			return false;
		file = file.substr(1, file.length() - 2);

		if (!ifstream(file))
		{
			if (require)
				errorhandler("Cannot find the file", f);
			return false;
		}
		return true;
	}

	int generateCode(TreeNode * tree)
	{
		cout << "\nGenerating Code...\n";
		CodeGenerator* code = new CodeGenerator();
		code->stopPrintingASMCode = !DEBUGMODE_ASM;
		code->stopCommenting = !CommentingOnASMCode;

		string asmCode = code->Generate(tree);
		if (code->errorCount() == 0)
		{
			if (CopyResultToClipboard)
				toClipboard(asmCode);
			CreateAsmFile(asmCode);
		} 
		else
		{
			cout << "\nGenerating code failed, fix the error and try again" << endl << endl;
			cout << "\n------------------------------------------------------\n";
			cout << "\n\tErrors count: " << code->errorCount() << endl;
			cout << "\n------------------------------------------------------\n";
			code->printErrors();
		}
		return code->errorCount();
	}

	void toClipboard(string s) // delete this after use it
	{
		HWND hwnd = GetDesktopWindow();
		OpenClipboard(hwnd);
		EmptyClipboard();
		HGLOBAL hg = GlobalAlloc(GMEM_MOVEABLE, s.size() + 1);
		if (!hg) { CloseClipboard(); return; }
		memcpy(GlobalLock(hg), s.c_str(), s.size() + 1);
		GlobalUnlock(hg);
		SetClipboardData(CF_TEXT, hg);
		CloseClipboard();
		GlobalFree(hg);
	}

	void CreateAsmFile(string s)
	{
		//freopen("index.asm", "w", stdout);
		ofstream outputFile("index.asm");
		outputFile << s;
		outputFile.close();
	}
}