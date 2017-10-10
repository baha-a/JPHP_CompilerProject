#include "MyParser.h"

MyParser::MyParser()
{
	this->st = new SymbolTable();

	//Type* object = new Type();
	//object->setName("object");
	//object->hasConstructor=true;

	//Function* f = new Function("object",false);
	//f->setAccess(AccessSpecifier::_public);
	//f->setStorage(StorageSpecifier::_none);
	//f->setSignature(NULL);
	//f->setReturnType("void");
	//f->setIsConstructor(true);
	//
	////////// to do later : 
	//////////  add all the function you want to class object
	//////////  like toString() ..... etc
	//////////

	//createType(object);
	//createTypeFunctionHeader(f);
	//finishFunctionDeclaration(f);
	//finishTypeDeclaration(object);
}


Function* MyParser::createTypeFunctionHeader(Function* f)
{
	f->getScope()->setOwner(f);
	f->getScope()->setParent(this->st->currScope);

	this->st->currScope->addSymbol(f);

	this->st->currScope = f->getScope();
	return f;
}
Function * MyParser::finishFunctionDeclaration(Function * f)
{
	this->st->currScope = this->st->currScope->getParent();
	return f;
}
Function * MyParser::FindFunctionByName(char* f)
{
	Function* t = (Function*) this->st->currScope->get(f);
	return t;
}

Type * MyParser::createType(Type* t)
{	
	t->thisClassHaveSomeErrors = ((Type*)this->st->currScope->get(t->getName()) != NULL); // means: there is another class with same name

	t->getScope()->setOwner(t);
	t->getScope()->setParent(this->st->currScope);

	this->st->currScope->addSymbol(t);
	this->st->currScope = t->getScope();
	return t;
}

Type * MyParser::finishTypeDeclaration(Type* t)
{
	this->st->currScope = this->st->currScope->getParent();
	return t;
}

Type* MyParser::FindClassByName(char* name)
{
	Type* t, *d;

	BlockScope* s = this->st->currScope;
	while (s != NULL)
	{
		t = dynamic_cast<Type*>(s->get(name));
		if (t != NULL)
			return t;

		d = dynamic_cast<Type*>(s->getOwner());
		if (d && d->getInheritedType())
		{
			t = dynamic_cast<Type*>(d->getInheritedType()->get(name));
			if (t != NULL)
				return t;
		}

		s = s->getParent();
	}

	return t;
}

Type* MyParser::FindClassByNameWithoutInheritance(char* name,BlockScope* startFromHere)
{
	Type* t, *d;

	BlockScope* s = startFromHere;
	if (s == NULL)
		s = this->st->currScope;

	while (s != NULL)
	{
		t = dynamic_cast<Type*>(s->get(name));
		if (t != NULL)
			return t;

		s = s->getParent();
	}

	return NULL;
}



BlockScope* MyParser::addNewScopeOfNoObject()
{
	BlockScope* p = new BlockScope();
	p->setParent(this->st->currScope);
	p->setOwner(NULL);
	this->st->currScope = p;
	return p;
}
BlockScope* MyParser::closeNewScopeOfNoObject(int& size)
{
	size = this->st->currScope->size;
	this->st->currScope = this->st->currScope->getParent();
	return this->st->currScope;
}