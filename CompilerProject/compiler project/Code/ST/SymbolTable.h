#ifndef __Symbol_Table__
#define __Symbol_Table__
#include <iostream>
#include <list>
#include <vector>
#include <string>
using namespace std;

enum AccessSpecifier 
{
	_private,  // default 
	_protected,
	_public
};

enum StorageSpecifier 
{
	_none,
	_final,
	_static,
	_abstract
};

enum var_types
{
	_string,
	_char,

	_bool,

	_double,
	_float,

	_int,
	_uint,
	_byte,
	_ubyte,
	_long,
	_ulong,
};



class Symbol
{
	protected:
		char* name;
	public:
		Symbol()
		{
			this->name = new char[255];
			this->name[0] = ' ';
		}
		virtual ~Symbol() {} // don't change this ever

		void setName(char* name) 
		{
			this->name = name;
			//strcat(this->name, name);
		};
		char* getName() { return this->name; };

		string AstLabel;

		bool isSameName(char* m)
		{
			return strcmp(name, m) == 0;
		}
};



#define MAX_LENGTH 71

class MapElem
{
private:
	char* name;
	Symbol* elem;
	MapElem * next;
public:
	MapElem() { next = NULL; elem = NULL; }

	void setName(char* name) { this->name = name; }
	char* getName() { return this->name; }
	void setElem(Symbol* elem) { this->elem = elem; }
	Symbol* getElem() { return this->elem; }
	MapElem* getNext() { return this->next; }
	void setNext(MapElem * newMapElem) { this->next = newMapElem; }

};

class MyMap
{
public:
	static const int mapLength = MAX_LENGTH;
	MapElem* arr[mapLength];
	int hash(char* name)
	{
		unsigned int i;
		int retVal = 0;
		for (i = 0; i < strlen(name); i++)
		{
			retVal <<= 2;
			retVal ^= (int)(*name);
			name++;
		}
		return (retVal%mapLength);
	}


	MyMap()
	{
		for (int i = 0; i<this->mapLength; i++)
			this->arr[i] = 0;
	}

	~MyMap() { }

	void put(char* name, Symbol* element)
	{
		int index = this->hash(name);
		MapElem * newMapElem = new MapElem();
		newMapElem->setName(name);
		newMapElem->setElem(element);
		newMapElem->setNext(0);
		newMapElem->setNext(this->arr[index]);
		this->arr[index] = newMapElem;
	}



	//----------------------------------------------------------------------
	Symbol* get(char* name)
	{
		int index = this->hash(name);
		MapElem * temp = this->arr[index];

		while ((temp != 0) && (strcmp(temp->getName(), name) != 0))
		{
			temp = temp->getNext();
		}

		if (temp == 0)
			return 0;
		else
			return temp->getElem();
	}
	//---------------------------------------------------------------------
	vector<Symbol*> getAll()
	{
		vector<Symbol*> all;
		for (int i = 0; i < this->mapLength; i++)
			if (this->arr[i] != 0)
			{
				MapElem * temp = this->arr[i];
				while (temp != 0)
				{
					all.push_back(temp->getElem());
					temp = temp->getNext();
				}
			}

		return all;
	}

	vector<MapElem*> getAllWithScopes()
	{
		vector<MapElem*> all;
		for (int i = 0; i < this->mapLength; i++)
			if (this->arr[i] != 0)
			{
				MapElem * temp = this->arr[i];
				while (temp != 0)
				{
					all.push_back(temp);
					temp = temp->getNext();
				}
			}

		return all;
	}
};

//---------------------------------------------------------------------------


class Variable : public Symbol
{
private:
	char* type;
	char* value;

	Symbol* Type;
	bool initialed;
	bool isparamter;
	bool isReferenceParamter;
public:
	bool isConst;
	bool isStatic;
	bool inOuterSpace;
	bool isArray;

	int lengthIfArray;
	bool itsDataMember;

	bool getIsInitialed() { return initialed; }
	void setInitialed() { initialed = true; }
	bool isParamter() { return isparamter; }
	void setIsParamter(bool i = true) { isparamter = i; }

	bool getIsReferenceParamter() { return isReferenceParamter; }
	void setIsReferenceParamter(bool i = false) { isReferenceParamter = i; }

	static int staticVariablesLabelRandomNumber;
	void generateLabel()
	{
		AstLabel = "STATIC_VAR_" + string(getName()) + "_X" + to_string(staticVariablesLabelRandomNumber++);
	}

	void SetClassType(Symbol * t)
	{
		Type = t;
	}
	Symbol* GetClassType()
	{
		return Type;
	}
	Variable(char * name, char * type)
	{
		Type = NULL;
		//AstOffest = 0;
		this->type = type;
		this->name = name;
		this->value = NULL;

		isStatic = false;
		inOuterSpace = false;
		isArray = false;
		lengthIfArray = 1;
		itsDataMember = false;
		generateLabel();

		initialed = false;
		isparamter = false;
		isConst = false;
		isReferenceParamter = false;
	}
	Variable(char * name, char * type, char* value)
	{
		Type = NULL;

		this->type = type;
		this->name = name;
		this->value = value;

		isStatic = false;
		inOuterSpace = false;
		isArray = false;
		lengthIfArray = 1;
		itsDataMember = false;
		generateLabel();

		initialed = ( value != NULL && strcmp(value,"") != 0);
		isparamter = false;
		isConst = false;
		isReferenceParamter = false;
	}
	void settype(char* type) { this->type = type; }
	char* gettype() 
	{
		if (type == NULL)
			return "";

		if (isArray)
			return strdup((string(type) + string("[]")).c_str());
		return type; 
	}

	void setvalue(char* value) { value = value; }
	char*getvalue() 
	{
		if (value == NULL)
			return "";
		return value; 
	}

	int AstOffest;

	bool isType(char * c) { return (strcmp(c, type) == 0); }



	//Symbol* getOwnerClass()
	//{
	//	return ownerclass;
	//}
	//Variable* setOwnerClass(Symbol* t)
	//{
	//	ownerclass = t;
	//	return this;
	//}
};
//-------------------------------------------------------------------------
class DataMember: public Variable   //Datamember in class 
{
	private:
		AccessSpecifier access;
		StorageSpecifier storage;

	public:
		DataMember(char *name, char * type) :Variable(name, type)
		{
			access = AccessSpecifier::_private;
			storage = StorageSpecifier::_none;
			itsDataMember = true;
		}
		DataMember(char *name, char * type, char* v) : Variable(name, type, v)
		{
			access = AccessSpecifier::_private;
			storage = StorageSpecifier::_none;
			itsDataMember = true;
		}


		void setAccess(AccessSpecifier a) 
		{
			access = a;;
		}
		void setStorage(StorageSpecifier a)
		{
			storage = a;
			if (a == _static)
				isStatic = true;
			else
				isStatic = false;
		}

		AccessSpecifier getAccess() { return access; }
		StorageSpecifier getStorage() { return storage; }

		bool IsStatic()
		{
			return storage == _static;
		}

		Variable* ConvertToVariable() { return dynamic_cast<Variable*>(this); }
};




//-----------------------------------------------------------------------
class Signature
{
private:
	vector<Variable*> parameters;
	vector<void*> optionalParamtersNode;
public:
	
	int getOptionalParamterStartIndex()
	{
		return parameters.size() - optionalParamtersNode.size();
	}
	void* getTreeNodeOfOptionalParamteresNumber(int i) 
	{
		if (optionalParamtersNode.empty())
			return NULL;
		return optionalParamtersNode.at(i);
	}

	Signature* addParamterToList(Variable* v, void* optionalValue = NULL)
	{
		parameters.push_back(v);
		if (optionalValue != NULL)
			optionalParamtersNode.push_back(optionalValue);
		return this;
	}
	Variable* getParameter(int i)
	{
		if (parameters.empty())
			return NULL;
		if (i >= parameters.size())
			return NULL;
		return parameters.at(i);
	}
	Variable* getParameter(char* name)
	{
		if (this == NULL || parameters.empty())
			return NULL;

		for (int i = 0; i < parameters.size(); i++)
		if (strcmp(parameters.at(i)->getName(), name) == 0)
				return parameters.at(i);
		return NULL;
	}

	int getCount()
	{
		if (this == NULL)
			return 0;
		return parameters.size();
	}


	static bool sameSignture(Signature* a, Signature* b)
	{
		if (a == NULL && b == NULL)
			return true;
		if (a == NULL || b == NULL || a->parameters.size() != b->parameters.size())
			return false;

		//list<Variable*>::iterator it2 = b->parameters.begin();
		//for (list<Variable*>::iterator it = a->parameters.begin(); it != a->parameters.end(); it++, it2++)
		//	if (strcmp((*it)->gettype(), (*it2)->gettype()) != 0)
		//		return false;

		return true;
	}

};







class BlockScope
{
private:
	BlockScope* parent;        //remember how to do inner scpoe
	Symbol* owner;
	MyMap* map;

public:
	int size;

	BlockScope() { parent = NULL; owner = NULL; this->map = new MyMap(); size = 0; }
	~BlockScope() {}
	
	void setParent(BlockScope* p){this->parent=p;}
	BlockScope* getParent(){return this->parent;}

	void setOwner(Symbol* owner) { this->owner = owner; }
	Symbol* getOwner() 
	{
		return this->owner; 
	}
	
	void addSymbol(Symbol* c) 
	{
		map->put(c->getName(), c); 
	}
	Symbol* get(char* name) 
	{
		return (Symbol*) map->get(name); 
	}
	//Symbol * get(char* name, Signature * sig);

	MyMap* getMap() { return this->map; }
};


class Function : public Symbol
{
	private:
		Signature* sign;
		bool isConsturctor;
		AccessSpecifier access;
		StorageSpecifier storage;

		char* returntype;
		bool hasSupper;

	public:
		bool isAutoGeneratedDefaultConsturactor;
		void setHasSuper(bool b)
		{
			hasSupper = b;
		}
		bool getHasSuper()
		{
			return hasSupper;
		}
		void setIsConstructor(bool x) { isConsturctor = x; }
		bool getIsConsturctor() { return isConsturctor; }


		static int labelRandomNumber;
		void generateLable()
		{
			AstLabel = "FUNCTION_LABEL_" + string(getName()) + "_L" + to_string(labelRandomNumber++);
		}

		BlockScope* scope;

		bool isExternal;
		bool isOverride;
		Function* fathersOverridedFunction;

		bool isInsideClass;
		Function(char* name ,bool ext=false)
		{
			if (name == NULL)
				return;
			setName(name);
			isInsideClass = false;
			isOverride = false;
			fathersOverridedFunction = NULL;
			isExternal = ext;
			scope = new BlockScope();
			sign = new Signature();

			access = AccessSpecifier::_private;
			storage = StorageSpecifier::_none;

			isConsturctor = false;
			hasSupper = false;
			isAutoGeneratedDefaultConsturactor = false;

			generateLable();
		}
		
		void setScope(BlockScope* scope) { this->scope = scope ; }
		BlockScope* getScope() { return this->scope; }
		void setSignature(Signature* sig) { sign = sig ; }
		Signature* getSignature() { return sign; } 

		int getParametersCount()
		{
			if (sign == NULL)
				if (isInsideClass && isStatic() == false)
					return 1;
				else
					return 0;
			if (isInsideClass && isStatic() == false)
				return sign->getCount() + 1;

			return sign->getCount();
		}

		void setAccess(AccessSpecifier a){access = a;}
		void setStorage(StorageSpecifier a){storage = a;}
		AccessSpecifier getAccess()
		{
			return access;
		}
		StorageSpecifier getStorage()
		{
			return storage;
		}
		bool isAbstract() 
		{
			return storage == _abstract; 
		}

		void setReturnType(char* x) { returntype = x;}
		char* getReturnType() {return returntype;}

		int getSize() { return scope->size; }
		bool isStatic()
		{
			return storage == _static;
		}


		vector<DataMember*> v_table;
		Function* setVtable(vector<DataMember*> v)
		{
			v_table = v;
			return this;
		}



		int AstOffest_ForAbstractFunctionsOnly;
};

class Type : public Symbol
{
	private:
		Type* inheritedType;
		vector<Type*> childTypes;
		bool isFinal;
		bool isAbstract;
		bool isStatic;

	public:
		BlockScope* scope;
		bool hasConstructor;
		bool thisClassHaveSomeErrors;

		bool hasPrivateConstructor()
		{
			if (getConsturactor() == NULL)
				return false;
			return getConsturactor()->getAccess() == _private;
		}
		bool hasProtectedConstructor()
		{
			if (getConsturactor() == NULL)
				return false;
			return getConsturactor()->getAccess() == _protected;
		}

		Function* getConsturactor()
		{
			if (this == NULL)
				return false;
			return getFunction(name);
		}
		Function* getFatherConsturactor()
		{
			if (inheritedType == NULL)
				return NULL;
			return getInheritedType()->getConsturactor();
		}

		Type() : Symbol()
		{
			hasConstructor = isFinal = isAbstract = isStatic =  false;
			scope = new BlockScope(); 
			thisClassHaveSomeErrors = false;
			inheritedType = NULL;
		}

		void setScope(BlockScope * m) { scope = m; }
		BlockScope* getScope() { return scope; }

		void setInheritedType(Type* e)
		{
			inheritedType = e;
			if (e != NULL)
				inheritedType->childTypes.push_back(this);
		}
		Type* getInheritedType() 
		{
			return inheritedType; 
		}

		bool isThisOneOfThatClassChildren(Type* base)
		{
			Type* t = getInheritedType();
			while (t != NULL)
			{
				if (t == base)
					return true;
				t = t->getInheritedType();
			}
			return false;
		}

		Symbol* add(Symbol * dm) { scope->addSymbol(dm); return dm;}
		Symbol* get(char* name) { return scope->get(name); }

		void setFinal(bool x) { isFinal = x; }
		void setAbstract(bool x) { isAbstract = x; }
        void setStatic(bool x) { isStatic = x; }

		bool getFinal(){return isFinal;}
		bool getAbstract() { return isAbstract; }
		bool getStatic() { return isStatic;}

		vector<Symbol*> getEverything()
		{
			return scope->getMap()->getAll();
		}
		vector<Symbol*> getEverythingWithInherited()
		{
			// this method Gets all the element from this Type and then it Gets all element from father class Type
			// and marge the to elements togither but,it ignore the base function of overrided function and add only 
			// the overrided function
			//
			//
			// p.s. 1: class X cannot inhetince a private or static elements from class Y
			//
			// p.s. 2: I like this code 
			//

			vector<Symbol*> A = getEverything();
			if (inheritedType == NULL)
				return A;

			vector<Symbol*> B = inheritedType->getEverythingWithInherited();
			vector<Symbol*> res;

			// marge two vectors togther
			for (vector<Symbol*>::iterator it = A.begin(); it < A.end(); ++it)
			{
				Function* f = dynamic_cast<Function*>(*it);
				if (f != NULL && (f->getAccess() == AccessSpecifier::_private))// || f->getStorage() == StorageSpecifier::_static))
					continue;

				DataMember* v = dynamic_cast<DataMember*>(*it);
				if (v != NULL && (v->getAccess() == AccessSpecifier::_private || v->getStorage() == StorageSpecifier::_static))
					continue;

				res.push_back(*it);
			}

			for (vector<Symbol*>::iterator it = B.begin(); it < B.end(); ++it)
			{
				Function* f = dynamic_cast<Function*>(*it);
				if (f != NULL)
				{
					if (f->getAccess() == AccessSpecifier::_private)//|| f->getStorage() == StorageSpecifier::_static)
						continue;

					Function* ff = dynamic_cast<Function*>(get(f->getName()));
					if (ff != NULL && ff->isOverride)
						continue; // if the function is overrided from father class than ignore the 
								  // father class function and just add the new one (the overrided one)
								  // which I did above when I marge 'res' with 'A' vectors
				}
				
				res.push_back(*it);
			}

			return res;
		}


		DataMember* getDataMember(char* name)
		{
			if (this == NULL)
				return NULL;
			BlockScope* temp = scope;
			DataMember* v = NULL;
			while (temp && !v)
			{
				v = dynamic_cast<DataMember*>(temp->get(name));
				if (!v)
				{
					Type* t = dynamic_cast<Type*>(temp->getOwner());
					if(t)
						v = t->getDataMemberFromInheritedType(name);
				}

				temp = temp->getParent();
			}
			return v;
		}
		DataMember* getDataMemberFromInheritedType(char* name)
		{
			if (!getInheritedType())
				return NULL;

			DataMember* d = dynamic_cast<DataMember*>(getInheritedType()->getDataMemberFromCurrentScopeOnly(name));
			if (!d)
			{
				return getInheritedType()->getDataMemberFromInheritedType(name);
			}

			if (d->getAccess() == AccessSpecifier::_private)
				return NULL;

			return d;
		}
		
		DataMember* getDataMemberFromCurrentScopeOnly(char* name)
		{
			return dynamic_cast<DataMember*>(scope->get(name));
		}

		Function* getFunction(char* name)
		{
			BlockScope* temp = scope;
			Function* v = NULL;
			while (temp && !v)
			{
				v = dynamic_cast<Function*>(temp->get(name));
				if (v == NULL)
				{
					Type* t = dynamic_cast<Type*>(temp->getOwner());
					if (t)
						v = t->getFunctionFromInheritedType(name);
				}

				temp = temp->getParent();
			}
			return v;
		}
		Function* getFunctionFromInheritedType(char* name)
		{
			if (!getInheritedType())
				return NULL;

			Function* d = dynamic_cast<Function*>(getInheritedType()->geFunctionFromCurrentScopeOnly(name));
			if (d == NULL)
				return getInheritedType()->getFunctionFromInheritedType(name);

			if (d->getAccess() == AccessSpecifier::_private)
				return NULL;

			return d;
		}
		Function* geFunctionFromCurrentScopeOnly(char* name)
		{
			return dynamic_cast<Function*>(scope->get(name));
		}


		int gaveMeNumberOfAbstractFunctions()
		{
			vector<Symbol*> all = scope->getMap()->getAll();
			Function* tmp;
			int count = 0;
			for (int i = 0; i < all.size(); i++)
			{
				tmp = dynamic_cast<Function*>(all.at(i));
				if (tmp != NULL && tmp->isStatic() == false && tmp->isAbstract())
					count++;
			}
			all.clear();
			return count;
		}
		
		vector<Function*> getOverridedFunctionForAbstractFunctions()
		{
			vector<Function*> result;
			vector<Symbol*> all = scope->getMap()->getAll();
			Function* tmp;
			for (int i = 0; i < all.size(); i++)
			{
				tmp = dynamic_cast<Function*>(all.at(i));
				if (tmp != NULL && tmp->isStatic() == false && tmp->isOverride && tmp->fathersOverridedFunction->isAbstract())
					result.push_back(tmp);
			}
			return result;
		}

		int gaveMeNumberOfTheVariableInParentClass()
		{
			int i = 0;
			if (inheritedType)
				i = inheritedType->get__V_TABLE__forCodeGenerating().size() + inheritedType->gaveMeNumberOfAbstractFunctions();

			return i;
		}

		int gaveMeNumberOfTheVariable()
		{
			return get__V_TABLE__forCodeGenerating().size() + gaveMeNumberOfAbstractFunctions() + (inheritedType == NULL ? 0 : inheritedType->gaveMeNumberOfAbstractFunctions());
		}

		vector<DataMember*> get__V_TABLE__forCodeGenerating()
		{
			vector<DataMember*> result;
			if (inheritedType)
			{
				result = inheritedType->get__V_TABLE__forCodeGenerating();
			}
			vector<Symbol*> all = scope->getMap()->getAll();
			DataMember * tmp;
			for (int i = all.size() -1 ; i >= 0; i--)
			{
				tmp = dynamic_cast<DataMember*>(all.at(i));
				if (tmp != NULL && tmp->isStatic == false)
				{
					result.push_back(tmp);
					//if (tmp->isType("double"))
					//	result.push_back(NULL);
				}
			}
			return result;
		}

		vector<Function*> get__F_TABLE__forCodeGenerating() 
		{
			vector<Function*> result;
			if (inheritedType)
			{
				result = inheritedType->get__F_TABLE__forCodeGenerating();
			}

			vector<Symbol*> all = scope->getMap()->getAll();
			Function* tmp;
			vector<DataMember*> vtable = get__V_TABLE__forCodeGenerating();
			for (int i = 0; i < all.size(); i++)
			{
				tmp = dynamic_cast<Function*>(all.at(i));
				if (tmp != NULL && tmp->isStatic() == false)
					result.push_back(tmp->setVtable(vtable));
			}
			return result;
		}



		bool isSameNameOrSameParentName(char* m)
		{
			return   strcmp(name, m) == 0     ||    (inheritedType != NULL && inheritedType->isSameNameOrSameParentName(m));
		}

		bool isSameNameOrSameChildName(char* m)
		{
			if (strcmp(name, m) == 0)
				return true;

			for (int i = 0; i < childTypes.size(); i++)
				if (childTypes.at(i)->isSameNameOrSameChildName(m) == true)
					return true;

			return false;
		}
};


class SymbolTable
{
public:
	SymbolTable()
	{
		this->rootScope = new BlockScope();
		this->currScope = this->rootScope;
	}
	BlockScope * currScope;
	BlockScope * rootScope;

	bool isCurrntScopeIsInSameClass(Type * t)
	{
		BlockScope* mover = this->currScope;
		while (
			mover &&
			(mover->getOwner() == NULL || dynamic_cast<Type*>(mover->getOwner()) != t)
			)
		{
			if (mover->getOwner() && (dynamic_cast<Function*>(mover->getOwner()) && dynamic_cast<Function*>(mover->getOwner())->getStorage() == _static))
				return false;
			//else if ((dynamic_cast<Function*>(mover->getOwner()) && dynamic_cast<Function*>(mover->getOwner())->getStorage() != _static))
			mover = mover->getParent();
		}
		return (mover && mover->getOwner() && t && dynamic_cast<Type*>(mover->getOwner()) == t);
	}


	bool isTheCurrntScopeBeingInsideStaticFunction()
	{
		BlockScope* mover = this->currScope;
		while (mover != NULL && mover->getOwner() == NULL) // it means this scope is inner scope for another scope (not class or function)
			mover = mover->getParent();

		if (mover && mover->getOwner())
		{
			Function* f = dynamic_cast<Function*>(mover->getOwner());
			if (f)
				return (f->getStorage() == StorageSpecifier::_static);
		}

		return false;
	}



	Variable * insertVariableInCurrentScope(char* name, char* type)
	{
		Variable * v = this->getVariableFromCurrentScope(name);
		if (v)
			return NULL; //item is exist previously				 // PRINT ERROR VARIABLE EXIST
		else
		{
			v = new Variable(name, type);
			this->currScope->addSymbol(v);
		}
		return v;
	}
	Variable * getVariableFromCurrentScope(char* name)
	{
		Variable * v = NULL;

		BlockScope* mover = this->currScope;
		while (mover != NULL && mover->getOwner() == NULL) // it means this scope is inner scope for another scope (not class or function)
		{
			v = dynamic_cast<Variable*>(this->currScope->get(name));
			if (v)
				break;
			mover = mover->getParent();
		}

		if (!v)
		{
			bool staticFuntion = isTheCurrntScopeBeingInsideStaticFunction();
			BlockScope* temp = this->currScope;
			while (temp && !v)
			{
				// 'temp' or 'this->currscop->' ???
				Function* f = dynamic_cast<Function*>(temp->getOwner()); // this for search in parameters of function
				if (f)
				{
					v = dynamic_cast<Variable*>(f->getSignature()->getParameter(name));
					if (v)
						return v;
				}
				// 'temp' or 'this->currscop->' ???
				Type* t = dynamic_cast<Type*>(temp->getOwner()); // this for search in class and outter class and inherited class too
				if (t)
				{
					DataMember* d = t->getDataMember(name);
					if (d)
						if (staticFuntion && d->getStorage() != StorageSpecifier::_static)
							return NULL;
						else
						{
							v = d->ConvertToVariable();
							break;
						}
				}

				v = dynamic_cast<Variable*>(temp->get(name));
				temp = temp->getParent();
			}
		}
		return v;
	}



	Function* getFunctionFromCurrentScope(char* name, BlockScope* b = NULL)
	{
		if (b == NULL)
			b = this->currScope;

		Function* f = dynamic_cast<Function*>(b->get(name));

		if (f == NULL)
		{
			BlockScope* temp = b;
			while (temp && !f)
			{
				Type* t = dynamic_cast<Type*>(temp->getOwner());

				if (t)
				{
					vector<Symbol*> v = t->getEverythingWithInherited(); // this for search in class and outter class and inherited class too
					for (vector<Symbol*>::iterator jt = v.begin(); jt < v.end(); ++jt)
					{
						Function* F = dynamic_cast<Function*>(*jt);
						if (F != NULL && strcmp(F->getName(), name) == 0)
							return F;
					}
				}
				else
					f = dynamic_cast<Function*>(temp->get(name));

				temp = temp->getParent();
			}
		}

		return f;
	}

	Function* insertFunctionInCurrentScope(Function* f) // not used
	{
		Function * v = this->getFunctionFromCurrentScope(f->getName());
		if (!v)
			return NULL; //item is exist previously				 // PRINT ERROR VARIABLE EXIST
		else
		{
			this->currScope->addSymbol(f);
		}
		return v;
	}

	Type* insertTypeInCurrentScope(char* name) // not used
	{
		Type * t = (Type*)this->currScope->get(name);
		if (t)
			return NULL;								// PRINT ERROR VARIABLE EXIST
		t = new Type();
		t->setName(name);
		t->setInheritedType(NULL);                        ////////////////

		currScope->addSymbol(t);

		return t;
	}

	static Function* getFatherConsturactor(Function* f)
	{
		BlockScope* b = f->getScope();
		while (b)
		{
			Type* t = dynamic_cast<Type*>(b->getOwner());
			if (t != NULL && t->getInheritedType() != NULL)
				return t->getFatherConsturactor();
			b = b->getParent();
		}
		return NULL;
	}
};
#endif
