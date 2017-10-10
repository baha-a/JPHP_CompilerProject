#pragma once
#ifndef __My_Parser__
#define __My_Parser__
#include "SymbolTable.h"
class MyParser
{
	public:
		SymbolTable * st;
		MyParser();
	
		Function* createTypeFunctionHeader(Function* f);
		Function* finishFunctionDeclaration(Function* f);
		
		Function* FindFunctionByName(char* f);

		Type* createType(Type* t);
		Type* finishTypeDeclaration(Type* t);

		Type* FindClassByName(char* name);

		Type* FindClassByNameWithoutInheritance(char* name, BlockScope* startFromHere = NULL);

		BlockScope* addNewScopeOfNoObject();
		BlockScope* closeNewScopeOfNoObject(int&);

		static Type* getOwnerclass(Function* f)
		{
			for (BlockScope* searcher = f->getScope(); searcher; searcher = searcher->getParent())
				if (dynamic_cast<Type*>(searcher->getOwner()))
					return dynamic_cast<Type*>(searcher->getOwner());

			return NULL;
		}
};
#endif