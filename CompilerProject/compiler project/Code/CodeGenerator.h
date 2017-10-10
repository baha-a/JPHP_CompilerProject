
//
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//                                                                                                                                                //
//               C		O		M		P		I		L		E		R						2		0		1		6                         //
//                                                                                                                                                //
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////
////////////////////////////////////////
//////////////////////////////////////// done:
////////////////////////////////////////       echo
////////////////////////////////////////       if - elseif - else
////////////////////////////////////////       for - while - do while
////////////////////////////////////////       foreach
////////////////////////////////////////       switch_case_default
////////////////////////////////////////       ++
////////////////////////////////////////       --
////////////////////////////////////////       function
////////////////////////////////////////       staticfunction
////////////////////////////////////////       localVariables
////////////////////////////////////////       staticVariables
////////////////////////////////////////       arrays
////////////////////////////////////////       return
////////////////////////////////////////       break									 recheck in switch
////////////////////////////////////////       countine
////////////////////////////////////////	   += 
////////////////////////////////////////       -=
////////////////////////////////////////       *=
////////////////////////////////////////       /=
////////////////////////////////////////       if(9)  and    if(0)
////////////////////////////////////////       
////////////////////////////////////////       instance of class
////////////////////////////////////////       class
////////////////////////////////////////       inhertinece
////////////////////////////////////////       super()	and default one
////////////////////////////////////////       default consturctar  done
////////////////////////////////////////       
////////////////////////////////////////       no need for prototypes and no need to order the code coz it will work fine regardless of order
////////////////////////////////////////
////////////////////////////////////////	   Composition
////////////////////////////////////////
////////////////////////////////////////       optinal parameters
////////////////////////////////////////       ! not
////////////////////////////////////////       & and &&
////////////////////////////////////////       | and ||
////////////////////////////////////////       
////////////////////////////////////////       read int, double and string
////////////////////////////////////////       add error 'not initialized variable'
////////////////////////////////////////       
////////////////////////////////////////       null keyword
////////////////////////////////////////       false and true keyword
////////////////////////////////////////       
////////////////////////////////////////       int type
////////////////////////////////////////       bool type
////////////////////////////////////////       referenece parameters
////////////////////////////////////////       
////////////////////////////////////////       up/down cast
////////////////////////////////////////       type checkes
////////////////////////////////////////       
////////////////////////////////////////       array of class
////////////////////////////////////////       check types in return node          
////////////////////////////////////////       
////////////////////////////////////////       string
////////////////////////////////////////          
////////////////////////////////////////       inner class
////////////////////////////////////////       static inner class
////////////////////////////////////////          
////////////////////////////////////////       double (but it's 4byte only)
////////////////////////////////////////       const variables
////////////////////////////////////////       not all paths return values
////////////////////////////////////////
////////////////////////////////////////       divide by zero runtime error   
////////////////////////////////////////          
////////////////////////////////////////       check types in parameters and arguments
////////////////////////////////////////       
////////////////////////////////////////       the super class 'object'
////////////////////////////////////////          
////////////////////////////////////////          
////////////////////////////////////////          
////////////////////////////////////////          
////////////////////////////////////////          
//////////////////////////////////////// tasks to do later:
////////////////////////////////////////
////////////////////////////////////////      conditional operators for double vars
/////////////////// ////////////////////      
///////////////// //////////////////////        
//////////////// ///////////////////////
///////////////  ///////////////////////  
///////////////      /////////////////// 
/////////////////          /////////////        
////////////////////    2     //////////
///////////////////////    0     ///////        
//////////////////////////    1     ////      
////////////////////////////    6     //       
/////////////////////////////         //
/////////////////////////////         //
////////////////////////////    C     //
//////////////////////////    O     ////  P.S.:  reserved registers: 
////////////////////////    M     //////			1 - SHOULD NOT CHANGE THE $t9 VALUE EVER
//////////////////////    P     ////////			2 - $a3 FOR PASSING THE VTABEL TO INSTANCE FUNCTION
////////////////////    I     //////////				BE CARFUL IF U NEED TO USE IT
//////////////////    L     ////////////			3 - $t8 FOR SOLVE SOME PROBLME IN ASSIGN NODE
////////////////    E     //////////////
//////////////    R     ////////////////
///////////          ///////////////////
/////////       //////////////////////// last change :
///////      ///////////////////////////               2016-6-4
/////   ////////////////////////////////
/// ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////  by    baha'a  &  ziad
//__________________________________________________________________________________________________________________________________________________
//
//       H  E  R  E       W  H  E  R  E       A  S  S  E  M  B  L  Y        C   O  D  E       G  E  N  E  R  A  T  E  D
//
//
//


#include <vector>
#include <cstring>
#include <string>
#include <iostream>
#include <stack>
#include <queue>
#include "AST\AST.h"
#include "ST\SymbolTable.h"
using namespace std;



class CodeGenerator
{
public:
	bool stopPrintingASMCode;
	bool stopCommenting;
	vector<string> dataSetion;
	vector<string> textSetion;

	vector<string> stringsVarLabels;
	vector<string> doublesValuesLabels;
	vector<pair<string, string>> stringsValuesLabels;

	int justOnce;
	int StringCounter;
	int TRegister, SRegister, TRegisterf;
	int itoaCount;

	int fromA1register;
	bool youAreNowInsideSomeFunctionFlag;
	bool youAreNowInsideSomeConsturactorFlag;
	bool youAreNowInsideSomeNotStaticFunctionWhichInsideClassFlag;
	string lastFunctionReturntype;
	string lastFunctionEndOfFunctionLabel;

	bool youAreNowInsideSomeLoooooooooopFlag;
	string lastLoopEndLabel;
	string lastLoopStartLabel;

	int youAreNowInsideSwitch;
	stack<string> lastswitchEndLabel;
	vector<int> casesSwitch;


	CodeGenerator()
	{
		stopPrintingASMCode = stopCommenting = true;

		stopCommenting = false;

		youAreNowInsideSwitch = 0;
		fromA1register = 0;

		dataSetion.push_back(".data");
		dataSetion.push_back("");

		textSetion.push_back(".text");
		textSetion.push_back(".globl       main");
		textSetion.push_back("");
		textSetion.push_back("main:");
		textSetion.push_back("");

		TRegisterf = SRegister = TRegister = StringCounter = justOnce = itoaCount = 0;

		youAreNowInsideSomeNotStaticFunctionWhichInsideClassFlag = false;

		youAreNowInsideSomeConsturactorFlag = false;
		youAreNowInsideSomeFunctionFlag = false;
		lastFunctionEndOfFunctionLabel = "";
		lastFunctionReturntype = "";

		youAreNowInsideSomeLoooooooooopFlag = false;

		dataSetion.push_back("\tbuffer: .space 32");
		addCode("move", "$fp", "$sp");  // $fp is the frame pointer
		addCode("move", "$t9", "$sp");  // I use $t9 as global pointer to catch the variables of very outter space, don't change $t9 ever
	}


	int generate_hash(int i)
	{
		return i;
	}

	int generate_hash(string s)
	{
		int hash = 0;
		char c[100];
		for (int i = 0; i < s.length(); i++){ c[i] = s[i];  hash = static_cast<int>(c[i]) + hash*(c[i - 1] * hash); }

		return hash;
	}



	string addDataString(string msg)
	{
		addComment("addDataString");

		for (int i = 0; i < stringsValuesLabels.size(); i++)
		if (stringsValuesLabels.at(i).first == msg)
			return stringsValuesLabels.at(i).second;

		string id = generatRandomLabel();
		dataSetion.push_back("	" + id + " : .asciiz " + msg);
		stringsValuesLabels.push_back(make_pair(msg, id));
		Cout(true);
		return id;
	}

	string addVariableString(string astlabel, string msg)
	{
		addComment("addVariableString");

		for (int i = 0; i < stringsVarLabels.size(); i++)
		if (stringsVarLabels.at(i) == astlabel)
			return astlabel;

		dataSetion.push_back("	" + astlabel + " : .asciiz " + msg);
		stringsVarLabels.push_back(astlabel);

		Cout(true);
		return astlabel;
	}

	string addDataDouble(string label, double value = 0)
	{
		for (int i = 0; i < doublesValuesLabels.size(); i++)
		if (doublesValuesLabels.at(i) == label)
			return label;

		dataSetion.push_back("	" + label + " : .float " + to_string(value));
		doublesValuesLabels.push_back(label);
		Cout(true);
		return label;
	}

	vector<string> intLabels;
	void addDataInt(string label, int value = 0)
	{
		for (int i = 0; i < intLabels.size(); i++)
		if (intLabels.at(i) == label)
			return;
		intLabels.push_back(label);
		dataSetion.push_back("	" + label + " : .word " + to_string(value));
		Cout(true);
	}
	void addDataByte(string NameVarible, string value = "0")
	{
		dataSetion.push_back(" " + NameVarible + " : .byte " + value);
		Cout(true);
	}

	void addNewLine()
	{
		textSetion.push_back("");
		Cout();
	}
	void addCode(string ins, string result = "", string r1 = "", string r2 = "")
	{
		string instr = "	" + ins + "  " + result;

		if (r1 != "")
			instr += " , " + r1;
		if (r2 != "")
			instr += " , " + r2;

		textSetion.push_back(instr);
		Cout();
	}
	void addEcho(string NameMsg, int type, bool isref)
	{
		if (NameMsg.at(0) != '$')  // means it's label and not register
			addCode("la", "$a0", NameMsg);

		else if (type == 3)
		{
			if (isref)
				addCode("mov.s ", "$f12", NameMsg);
			else
				addCode("l.s ", "$f12", NameMsg);
		}
		else if (type == 2)
			addCode("mov.s", "$f12", NameMsg);
		else //if (type == 3 || type == 2 || type == 1)
			addCode("move", "$a0", NameMsg);

		addCode("li", "$v0", to_string(type));
		addCode("syscall", "");
	}
	void addLabel(string label)
	{
		textSetion.push_back(label + " :");
		Cout();
	}
	void addComment(string str)
	{
		if (stopCommenting)
			return;
		textSetion.push_back(" #" + str);
		Cout();
	}


	void Cout(bool data = false)
	{
		if (!stopPrintingASMCode)
			cout << (data ? dataSetion.at(dataSetion.size() - 1) : textSetion.at(textSetion.size() - 1)) << endl;
	}

	string NextRegister() { return "$t" + to_string(TRegister++ % 7); }
	void RelessRegister() { if (TRegister > 0) TRegister-- % 7; }

	string NextRegisterS() { return "$s" + to_string(SRegister++ % 7); }

	string NextRegisterf()
	{
		int x = 0;
		do x = ((++TRegisterf) - 1) % 32; while (x == 0 || x == 12);
		return "$f" + to_string(x);
	}
	string generatRandomLabel() { return "X" + to_string(StringCounter++); }

	string loadRegval(string reg)
	{
		addComment("loadRegval");
		string newid1 = NextRegister();
		addCode("la", newid1, reg);
		addCode("lw", newid1, "0(" + newid1 + ")");
		return newid1;
	}
	string loadRegvalf(string reg)
	{
		addComment("loadRegvalf");
		string newid1 = NextRegister();
		string tmp = NextRegisterf();
		addCode("la", newid1, reg);
		addCode("l.s", tmp, "0(" + newid1 + ")");
		RelessRegister();
		return tmp;
	}
	string loadRegAdress(string reg)
	{
		addComment("loadRegval");
		string newid1 = NextRegister();
		addCode("la", newid1, reg);
		return newid1;
	}

	string loadDataVal(Variable* v, string base)
	{
		addComment("loadDataVal");
		string id;
		if (v->isType("double"))
			addCode("l.s", id = NextRegisterf(), to_string(v->AstOffest) + "(" + base + ")");
		else
			addCode("lw", id = NextRegister(), to_string(v->AstOffest) + "(" + base + ")");
		return id;
	}
	void storeDataVal(Variable* v, string r, string base)
	{
		addComment("storeDataVal");
		if (v->isType("double"))
			addCode("s.s", r, to_string(v->AstOffest) + "(" + base + ")");
		else
			addCode("sw", r, to_string(v->AstOffest) + "(" + base + ")");
	}
	void storeRegVal(string label, string reg)
	{
		addComment("storeRegVal");
		string newid1 = NextRegister();
		addCode("la", newid1, label);
		addCode("sw", reg, "(" + newid1 + ")");
	}

	string referenceRegister(bool isInOuterSpace)
	{
		return isInOuterSpace ? "($t9)" : "($fp)";
	}

	string print()
	{
		//freopen("C:\\Users\\ziad hashem\\Desktop\\hh.txt","w",stdout);
		string str = "";
		for (int i = 0; i < dataSetion.size(); i++)
			str += dataSetion.at(i) + "\n";

		str += "\n";

		for (int i = 0; i < textSetion.size(); i++)
			str += textSetion.at(i) + "\n";
		return str;
	}
	void finishize()
	{
		if (justOnce++ != 0)
			return;

		addCode("li  $v0, 10", "");
		addCode("syscall", "");
	}

	string getArrayPointer(TreeNode* node, string &type)
	{
		addComment("getArrayPointer collecting data from right node");

		string id;
		generate(node->right, id, type); // go and get the desired index for array item
		if (type != "int")
			;//error

		addComment("getArrayPointer collecting data from left node");

		string id2;
		generate(node->left, id2, type); // go and search for variable-

		// todo later
		// check id value (in mips (in runtime)) if it is lesss than zero
		// then throw runtime error
		//

		addComment("getArrayPointer collecting data done");
		addCode("sll", id, id, "2");
		addCode("add", id2, id2, id);
		addComment("getArrayPointer done");
		return id2;
	}



	bool CheckTypesforAssign(string type1, string type2)
	{
		if (type1 == type2 || type2 == "null")
			return true;

		if ((type1 == "int" || type2 == "int") && (type1 == "bool" || type2 == "bool"))
			return true;

		if (type1 == "double" || type1 == "float")
			return type2 == "int" || type2 == "double" || type2 == "float";

		return false;
	}
	bool CheckTypesforAssign(Type* type1, string type2, bool isArray)
	{
		if (type1 == NULL || type2 == "string" || type2 == "int" || type2 == "double" || type2 == "float" || type2 == "void"
			|| type2 == "string[]" || type2 == "int[]" || type2 == "double[]" || type2 == "float[]")
			return false;

		bool isArray2 = false;
		if (isArray)
		{
			isArray2 = removeArrayArrows(type2) != type2;
			type2 = removeArrayArrows(type2);
		}
		return isArray == isArray2 && type1->isSameNameOrSameChildName(strdup(type2.c_str())); // this upcast, it is automaticly,
		// The downcast is manualy, for downcast use this:
		// || type1->isSameNameOrSameParentName(strdup(type2.c_str())) 
	}


	bool checkTypes(TreeNode* node, Type* t, bool isArray, string type, string type2)
	{
		if (t != NULL)
		{
			if (CheckTypesforAssign(t, type2, isArray) == false)
			{
				errorHandler(node, "can't assign \'" + type2 + "\' to \'" + string(t->getName()) + "\'");
				return false;
			}
		}
		else if (CheckTypesforAssign(type, type2) == false)
		{
			errorHandler(node, "can't assign \'" + type2 + "\' to \'" + type + "\'");
			return false;
		}
		return true;
	}



	vector<string> errors;
	int errorCount()
	{
		if (errors.empty())
			return 0;
		return errors.size();
	}
	void printErrors()
	{
		for (int i = 0; i < errors.size(); i++)
			cout << errors.at(i) << endl;
	}
	void errorHandler(TreeNode* x, string msg, string name = "")
	{
		errors.push_back("Ln(" + to_string(x->line) + ") Col(" + to_string(x->col) + ") name(" + name + ") Msg(" + msg + ")");
	}




	string removeArrayArrows(string type)
	{
		if (type.length() > 2 && type.substr(type.length() - 2, 2) == "[]")
			type = type.substr(0, type.length() - 2);
		return type;
	}

	string my_itoa(string number)
	{
		if (itoaCount++ == 0)
		{
			string skip = "ITOA_SKIP_" + generatRandomLabel();
			string loop = "ITOA_LOOP_" + generatRandomLabel();
			string iend = "ITOA_IEND_" + generatRandomLabel();
			string nolz = "ITOA_NOLZ_" + generatRandomLabel();

			string
				t1 = NextRegisterS(),
				t2 = NextRegisterS(),
				t3 = NextRegisterS(),
				t4 = NextRegisterS();

			addCode("j", skip);
			addLabel("ITOA_LABEL_XXX");
			addCode("la", "$a1", "buffer");
			addCode("add", "$a1", "$a1", "30");
			addCode("sb", "$0", "1($a1)");
			addCode("li", t1, "'0'");
			addCode("sb", t1, "($a1)");
			addCode("slt", t2, "$a0", "$0");
			addCode("li", t3, "10");
			addCode("beq", "$a0", "$0", iend);
			addCode("bgez", "$a0", loop);
			addCode("neg", "$a0", "$a0");

			addLabel(loop);
			addCode("div", "$a0", t3);
			addCode("mflo", "$a0");
			addCode("mfhi", t4);
			addCode("add", t4, t4, t1);
			addCode("sb", t4, "($a1)");
			addCode("sub", "$a1", "$a1", "1");
			addCode("bne", "$a0", "$0", loop);
			addCode("addi", "$a1", "$a1", "1"); //
			addLabel(iend);
			addCode("beq", t2, "$0", nolz);
			addCode("addi", "$a1", "$a1", "-1");
			addCode("li", t1, "'-'");
			addCode("sb", t1, "($a1)");
			addLabel(nolz);
			addCode("jr", "$ra");
			addLabel(skip);
		}

		addCode("move", "$a0", number);
		addCode("subi", "$sp", "$sp", "4");
		addCode("sw", "$ra", "($sp)");

		addCode("jal", "ITOA_LABEL_XXX");

		addCode("lw", "$ra", "($sp)");
		addCode("addi", "$sp", "$sp", "4");

		return "$a1";
	}

	string my_ftoa(string number)
	{
		string t = NextRegister();
		addCode("cvt.w.s", number, number);
		addCode("mfc1", t, number);
		return my_itoa(t);
	}

	string getType(TreeNode* t)
	{
		if (t == NULL)
			return "";

		switch (t->nodeType)
		{
		case nullNode:
			return "null";
		case falseNode:
		case trueNode:
			return "bool";
		case intValNode:
			return "int";
		case doubleValNode:
			return "double";
		case stringValNode:
			return "string";
		case functionCallNode:
			return ((Function*)t->symbolTableElement)->getReturnType();
		case callVariableNode:
			return ((Variable*)t->symbolTableElement)->gettype();
		case callArrayVariableNode:
			return removeArrayArrows(((Variable*)t->symbolTableElement)->gettype());
		case objectAccessToArrayElementNode:
		case objectAccessToFunctionNode:
		case objectAccessToVariableNode:
			////////////////////////////////////////////// complete this
			break;
		}

		string t1, t2;
		t1 = getType(t->left);
		t2 = getType(t->right);

		if (t1 == "string" || t2 == "string")
			return "string";

		if (t1 == "double" || t2 == "double")
			return "double";

		if (t1 == "int" || t2 == "int")
			return "int";

		return t1 != "" ? t1 : t2;
	}

	string loadImmidiateForDouble(double d)
	{
		string h = to_string(d);
		h.erase(h.find_last_not_of('0') + 1, std::string::npos);

		string h2 = "";
		int x = 0;
		for (int i = 0; i < h.length(); i++)
		{
			if (h.at(i) == '.')
				x = 1;
			else
			{
				h2 += h.at(i);

				if (x > 0)
					x *= 10;
			}
		}

		string r = NextRegister();
		string t = NextRegister();
		addCode("li", r, to_string(x));
		addCode("li", t, h2);

		string z = NextRegisterf();
		string y = NextRegisterf();
		addCode("mtc1", r, z);
		addCode("cvt.s.w", z, z);

		addCode("mtc1", t, y);
		addCode("cvt.s.w", y, y);

		addCode("div.s", z, y, z);

		return z;
	}

	void generate(TreeNode* node, string& id, string& type)
	{
		if (node == NULL)
			return;

		switch (node->nodeType)
		{

		case trueNode:
		{
						 id = NextRegister();
						 addCode("li", id, "1");
						 type = "bool";
						 break;
		}
		case falseNode:
		{
						  id = NextRegister();
						  addCode("li", id, "0");
						  type = "bool";
						  break;
		}
		case nullNode:
		{
						 id = NextRegister();
						 addCode("li", id, "0");
						 type = "null";
						 break;
		}
		case intValNode:
		{
						   addComment("intValNode");
						   id = NextRegister();
						   addCode("li", id, to_string(node->intval));
						   type = "int";
						   break;
		}
		case doubleValNode:
		{
							  addComment("doubleValNode");
							  id = loadImmidiateForDouble(node->doubleval);
							  type = "double";
							  break;
		}
		case stringValNode:
		{
							  addComment("stringValNode");

							  id = addDataString(node->stringval);
							  if (type != "echo")
								  id = loadRegval(id);
							  type = "string";
							  break;
		}
		case staticVariableNode:
		{
								   addComment("staticVariableNode");

								   Variable* v = (Variable*)node->symbolTableElement;
								   if (v->isType("int"))
									   addDataInt(v->AstLabel, atoi(v->getvalue()));
								   else if (v->isType("double") || v->isType("float"))
									   addDataDouble(v->AstLabel, atof(v->getvalue()));
								   else if (v->isType("string"))
									   addVariableString(v->AstLabel, string(v->getvalue()));
								   else
									   addDataInt(v->AstLabel, atoi(v->getvalue()));

								   v->setInitialed();
								   if (v->isType("double"))
									   id = loadRegvalf(v->AstLabel);
								   else
									   id = loadRegval(v->AstLabel);
								   type = v->gettype();
								   break;
		}
		case arrayNode:
		{
						  generate(node->left, id, type);
						  generate(node->right, id, type);

						  type = (node->left == NULL ? node->stringval : node->left->symbolTableElement->getName()) + string("[]");
						  break;
		}
		case arrayInitializingNode:
		{
									  addComment("arrayInitializingNode");

									  if (node->left && node->right)
										  ;//error should not happend

									  if (node->left == NULL) // means the user did not enter any size for array,so it's like this:    = new int[]{1,2,3,5,5,6,....}
									  {
										  int length = 0;
										  for (TreeNode* mover = node->right; mover; mover = mover->right)          // Compiler will count array's length by itself
											  length++;

										  node->left = new TreeNode();
										  node->left->nodeType = intValNode;
										  node->left->intval = length;
									  }
									  string type2;
									  generate(node->left, id, type2);

									  if (type2 != "int")
										  errorHandler(node, "size of the array must be intger", "");

									  addCode("li", "$a0", to_string(node->left->intval));

									  // todo later
									  // check id value (in mips (in runtime)) if it is zero or less
									  // then throw runtime error
									  //

									  // allocate space for array in heap
									  addCode("sll", "$a0", id, "2"); // id = id * 4  where the  'id'  is holding the size of array
									  addCode("li", "$v0", "9");
									  addCode("syscall");

									  TreeNode* mover = node->right; // if there any explicit values ( {1,2,3,4,....} ) so put theme 
									  int counter = 0;
									  while (mover)
									  {
										  // the left node is holding the value
										  // the right node is the next arrayPairListNode
										  string id2, type2;
										  generate(mover->left, id2, type2);
										  addCode("sw", id2, to_string(counter++ * 4) + "($v0)");

										  mover = mover->right;
									  }

									  addCode("move", id = NextRegister(), "$v0");
									  break;
		}
		case idVariableNode:
		{
							   addComment("idVariableNode");

							   Variable* v = (Variable*)node->symbolTableElement;
							   if (v == NULL)
								   break;

							   if (v->isConst)
								   v->isStatic = true;

							   if (v->isStatic)
							   {
								   node->nodeType = staticVariableNode;
								   generate(node, id, type);
								   break;
							   }
							   else if (v->itsDataMember)
								   ; // do nothing coz I handled this in newClassInstance


							   if (youAreNowInsideSomeFunctionFlag == false)
								   v->inOuterSpace = true;

							   id = to_string(v->AstOffest);
							   type = v->gettype();

							   addComment("VAR: " + string(v->getName()) + "   offest: " + to_string(v->AstOffest) + "   insideFunction: " + (youAreNowInsideSomeFunctionFlag ? "Y" : "N"));
							   break;
		}
		case uneryPreMinusNode:
		{
								  if (node->left->nodeType == intValNode)
								  {
									  node->intval = node->left->intval * -1;
									  node->left = NULL;
									  node->nodeType = intValNode;
									  generate(node, id, type);

								  }
								  else if (node->left->nodeType == doubleValNode)
								  {
									  node->doubleval = node->left->doubleval * -1;
									  node->left = NULL;
									  node->nodeType = doubleValNode;
									  generate(node, id, type);
								  }
								  else
								  {
									  generate(node->left, id, type);
									  //string id2 = NextRegister();
									  //addCode("li", id2, "-1");
									  //addCode("mult", id, id, id2);
									  addCode("neg", id, id);
								  }
								  break;
		}
		case callVariableNode:
		{
								 addComment("callVariableNode");

								 Variable* tmp = (Variable*)node->symbolTableElement;
								 if (tmp->itsDataMember == false && tmp->isParamter() == false && tmp->getIsInitialed() == false)
									 errorHandler(node, "using un-initialized variable", string(tmp->getName()));

								 if (tmp->isStatic)
								 {
									 if (tmp->isType("double"))
										 id = loadRegvalf(tmp->AstLabel);
									 else if (tmp->isType("string"))
										 id = loadRegAdress(tmp->AstLabel);
									 else
										 id = loadRegval(tmp->AstLabel);
								 }
								 else if (tmp->itsDataMember)
								 {
									 // here we get the variable from the VTABLE parameter
									 string t = NextRegister();
									 addCode("lw", t, "-4($fp)");  // load the VTABLE  which is always the first paramater
									 id = loadDataVal(tmp, t);
								 }
								 else
								 {
									 if (tmp->getIsReferenceParamter())
									 {
										 string t = NextRegister();
										 addCode("lw", t, to_string(tmp->AstOffest) + "($fp)");

										 if (tmp->isType("double"))
											 addCode("l.s", id = NextRegisterf(), "(" + t + ")");
										 else
											 addCode("lw", id = t, "(" + t + ")");
									 }
									 else
									 {
										 if (tmp->isType("double"))
											 addCode("l.s", id = NextRegisterf(), to_string(tmp->AstOffest) + referenceRegister(tmp->inOuterSpace));
										 else
											 addCode("lw", id = NextRegister(), to_string(tmp->AstOffest) + referenceRegister(tmp->inOuterSpace));
									 }
								 }
								 type = tmp->gettype();

								 break;
		}
		case callArrayVariableNode: // here only for reading
		{
										addComment("callArrayVariableNode");
										addCode("lw", id = NextRegister(), "0(" + getArrayPointer(node, type) + ")");
										type = removeArrayArrows(type);
										break;
		}
		case intCastNode:
		{
							string id2, type2;
							generate(node->left, id2, type2);
							if (type2 == "int" || type2 == "double" || type2 == "bool")
							{
								id = id2;
								type = "int";

								if (type2 == "double")
								{
									addCode("cvt.w.s", id2, id2);
									addCode("mfc1", id = NextRegister(), id2);
								}
							}
							else
								errorHandler(node, "can't convert to int");
							break;
		}
		case doubleCastNode:
		{
							   string id2, type2;
							   generate(node->left, id2, type2);
							   if (type2 == "int" || type2 == "double" || type2 == "bool")
							   {
								   id = id2;
								   type = "double";

								   if (type2 != "double")
								   {

									   addCode("mtc1", id2, id = NextRegisterf());
									   addCode("cvt.s.w", id, id);
								   }
							   }
							   else
								   errorHandler(node, "can't convert to double");
							   break;
		}
		case stringCastNode:
		{
							   string id2, type2;
							   generate(node->left, id2, type2);
							   if (type2 == "string" || type2 == "int" || type2 == "double" || type2 == "bool")
							   {
								   if (type2 == "int" || type2 == "bool")
									   id = my_itoa(id2);
								   else if (type2 == "double")
									   id = my_ftoa(id2);
								   else
									   id = id2;
								   type = "string";
							   }
							   else
								   errorHandler(node, "can't convert to string");
							   break;
		}
		case boolCastNode:
		{
							 string id2, type2;
							 generate(node->left, id2, type2);
							 if (type2 == "int" || type2 == "bool")
							 {
								 id = id2;
								 type = "bool";
							 }
							 else
								 errorHandler(node, "can't convert to bool");
							 break;
		}
		case classTypeCastNode:
		{
								  string type2;
								  generate(node->left, id, type2);
								  Type* t = (Type*)node->symbolTableElement;

								  if (CheckTypesforAssign(t, type2, false) || t->isSameNameOrSameParentName(strdup(type2.c_str())))
									  type = t->getName();
								  else
									  errorHandler(node, "can't convert  " + type2 + "  to " + string(t->getName()));
								  break;
		}
		case classTypeCastArrayNode:
		{
									   string id2, type2;
									   generate(node->left, id2, type2);
									   Type* t = (Type*)node->symbolTableElement;

									   if (CheckTypesforAssign(t, type2, true) || t->isSameNameOrSameParentName(strdup(type2.c_str())))
										   type = t->getName();
									   else
										   errorHandler(node, "can't convert  " + type2 + "  to " + string(t->getName()));
									   break;
		}
		case assignNode:
		{
						   addComment("assignNode");

						   string offest, _id2, type1, type2;
						   Variable * v = (Variable*)node->left->symbolTableElement;


						   if (node->left && node->right && node->right->nodeType == newClassInstance)
						   {
							   addComment("assign optimaizing 1");

							   generate(node->right, id, type2);
							   addCode("move", "$t8", id);

							   type = v->gettype();
							   bool isArray = v->isArray;
							   if (node->left->nodeType == callArrayVariableNode)
							   {
								   type = removeArrayArrows(type);
								   isArray = false;
							   }


							   checkTypes(node, (Type*)v->GetClassType(), isArray, type, type2);


							   if (node->left->nodeType == objectAccessToVariableNode)
							   {
								   string idbase = "";
								   generate(node->left->left, idbase, type2);
								   addCode("sw", "$t8", to_string(v->AstOffest) + "(" + idbase + ")");
								   break;
							   }
							   if (node->left->nodeType == callArrayVariableNode)
							   {
								   //generate(node->left, idbase, type2);
								   addCode("sw", "$t8", "(" + getArrayPointer(node->left, type) + ")");
								   break;
							   }

							   if (v->itsDataMember)
							   {
								   string idbase = "";
								   addCode("lw", idbase = NextRegister(), "-4($fp)");
								   addCode("sw", "$t8", to_string(v->AstOffest) + "(" + idbase + ")");
								   break;
							   }
							   else if (node->left->nodeType == idVariableNode)
								   ; // do nothing
							   else if (v->getIsReferenceParamter())
							   {
								   string t = NextRegister();
								   addCode("lw", t, to_string(v->AstOffest) + "($fp)");
								   //					if (v->isType("double"))
								   //						addCode("s.s", "$t8", "(" + t + ")");     ////// check later
								   //					else
								   addCode("sw", "$t8", "(" + t + ")");

								   v->setInitialed();
								   break;
							   }
							   //else
							   //	generate(node->left, id, type);

							   addCode("sw", "$t8", to_string(v->AstOffest) + referenceRegister(v->inOuterSpace));
							   v->setInitialed();
							   break;
						   }
						   else if (node->left && node->left->nodeType == objectAccessToArrayElementNode)
						   {
							   addComment("assign optimaizing 1.5");
							   //right node is the index
							   //left node is varaible ex:   x->a[]

							   string index, value;
							   generate(node->right, value, type);
							   if (type != "int")
								   errorHandler(node, "bad index for array");

							   string left_id, left_type;
							   generate(node->left->left->left, left_id, left_type); // this the pointer of array (address for first element)

							   Variable* v = (Variable*)node->left->left->symbolTableElement;
							   if (v->itsDataMember == false && v->isParamter() == false && v->getIsInitialed() == false)
								   errorHandler(node, "using non-initialized variable ", string(v->getName()));

							   id = loadDataVal(v, left_id);
							   generate(node->left->right, index, type);

							   addCode("sll", index, index, "2");
							   addCode("add", index, index, id);
							   addCode("sw", value, "(" + index + ")");

							   type = v->gettype();
							   break;
						   }
						   else if (node->left && node->left->nodeType == objectAccessToVariableNode)
						   {
							   addComment("assign optimaizing 2");
							   generate(node->right, id, type2);

							   string left_id, left_type;
							   generate(node->left->left, left_id, left_type);

							   if (v == NULL)
								   v = (Variable*)node->left->left->symbolTableElement;

							   type = v->gettype();

							   checkTypes(node, (Type*)v->GetClassType(), v->isArray, type, type2);


							   if (((DataMember*)node->left->left->symbolTableElement)->getStorage() == _final)
							   {
								   errorHandler(node, "final Varaible must not change", string(node->left->left->symbolTableElement->getName()));
								   //break;
							   }

							   storeDataVal(v, id, left_id);
							   break;
						   }
						   else if (node->left && node->left->nodeType == callArrayVariableNode)
						   {
							   addComment("assign optimaizing 3");

							   id = getArrayPointer(node->left, type);
							   generate(node->right, _id2, type2);
							   type = removeArrayArrows(type);

							   checkTypes(node, (Type*)v->GetClassType(), false, type, type2);

							   addCode("sw", _id2, "0(" + id + ")");
							   break;
						   }
						   else if (node->left && node->left->nodeType == callVariableNode)
						   {
							   addComment("assign optimaizing 4");
							   if (v->isConst)
								   errorHandler(node, "Const Varaible must not change", string(v->getName()));


							   offest = to_string((v)->AstOffest);
							   type = (v)->gettype();

							   generate(node->right, _id2, type2);

							   checkTypes(node, (Type*)v->GetClassType(), v->isArray, type, type2);

							   if (v && v->isStatic)
								   storeRegVal(v->AstLabel, _id2);
							   else if (v && v->itsDataMember)
							   {
								   string t = NextRegister();
								   addCode("lw", t, "-4($fp)");  // load the VTABLE  which is always the first paramater
								   storeDataVal(v, _id2, t);
							   }
							   else
							   {
								   if (v && v->getIsReferenceParamter())
								   {
									   string t = NextRegister();
									   addCode("lw", t, to_string(v->AstOffest) + "($fp)");

									   if (type == "double" && type2 == "double")
										   addCode("s.s", _id2, "(" + t + ")");
									   else if (type == "double" && type2 == "int")
									   {
										   string tmpf = NextRegisterf();
										   addCode("mtc1", _id2, tmpf);
										   addCode("cvt.s.w", tmpf, tmpf);
										   addCode("s.s", tmpf, "(" + t + ")");
									   }
									   else
										   addCode("sw", _id2, "(" + t + ")");
								   }
								   else
								   {
									   if (type == "double" && type2 == "double")
										   addCode("s.s", _id2, offest + referenceRegister(v->inOuterSpace));
									   else if (type == "double" && type2 == "int")
									   {
										   string tmpf = NextRegisterf();
										   addCode("mtc1", _id2, tmpf);
										   addCode("cvt.s.w", tmpf, tmpf);

										   addCode("s.s", tmpf, offest + referenceRegister(v->inOuterSpace));
									   }
									   else
										   addCode("sw", _id2, offest + referenceRegister(v->inOuterSpace));
								   }
							   }
							   id = _id2;
							   v->setInitialed();
							   break;
						   }
						   else
							   generate(node->left, offest, type1);


						   if (node->right->nodeType == stringValNode)
						   {
							   type2 = "string";
							   addCode("la", _id2 = NextRegister(), addDataString(node->right->stringval));
						   }
						   else
								generate(node->right, _id2, type2);

						   type = type1;

						   checkTypes(node, (Type*)v->GetClassType(), v->isArray, type, type2);

						   if (v && v->isStatic)
							   storeRegVal(v->AstLabel, _id2);
						   else
						   {
							   if (type1 == "double" && type2 == "double")
								   addCode("s.s", _id2, offest + referenceRegister(v->inOuterSpace));
							   else if (type1 == "double" && type2 == "int")
							   {
								   string tmpf = NextRegisterf();
								   addCode("mtc1", _id2, tmpf);
								   addCode("cvt.s.w", tmpf, tmpf);

								   addCode("s.s", tmpf, offest + referenceRegister(v->inOuterSpace));
							   }
							   else
								   addCode("sw", _id2, offest + referenceRegister(v->inOuterSpace));
						   }
						   id = _id2;
						   v->setInitialed();
						   break;
		}
		case objectAccessToArrayElementNode:
		{
											   //right node is the index
											   //left node is varaible ex:   x->a[0]

											   string index;
											   generate(node->right, index, type);
											   if (type != "int")
												   errorHandler(node, "bad index for array");


											   string left_id, left_type;
											   generate(node->left->left, left_id, left_type);

											   Variable* v = (Variable*)node->left->symbolTableElement;

											   id = loadDataVal(v, left_id);

											   addCode("sll", index, index, "2");
											   addCode("add", index, index, id);
											   addCode("lw", id, "(" + index + ")");

											   type = v->gettype();

											   type = removeArrayArrows(type);
											   break;
		}
		case argumentReferencNode:
		{
									 /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
									 break;
		}
		case assignReferencNode:
		{
								   //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
								   break;
		}

		case echoNode:
		{
						 addComment("echoNode");
						 TreeNode* m = node->left;
						 bool isref = false;      ///////////// ziad

						 while (m)
						 {
							 string _id = "", typ = "echo";

							 generate(m->left, _id, typ);
							 int t = 1;
							 if (typ == "float")
								 t = 2;
							 if (typ == "double")
								 t = 2;          ////////////////////////////////// 3
							 if (typ == "string")
								 t = 4;

							 ///////////// by ziad
							 switch (node->left->left->nodeType)
							 {
							 case callVariableNode:
							 case doubleValNode:
							 case plusNode:
							 case minusNode:
							 case multNode:
							 case modNode:
							 case divNode:
								 isref = true; break;
							 default:
								 isref = false; break;
							 }
							 ///////////// end

							 addEcho(_id, t, isref);
							 m = m->right;
						 }
						 break;
		}
		case readIntNode:
		{
							addComment("readIntNode");
							type = "int";
							addCode("li", "$v0", "5");
							addCode("syscall");
							addCode("move", id = NextRegister(), "$v0");
							break;
		}
		case readDoubleNode:
		{
							   addComment("readDoubleNode");
							   type = "double";
							   addCode("li", "$v0", "6");
							   addCode("syscall");
							   id = "$f0";
							   break;
		}
		case readStringNode:
		{
							   addComment("readStringNode");
							   type = "string";

							   addCode("li", "$a0", "2048");
							   addCode("li", "$v0", "9");
							   addCode("syscall");
							   addCode("move", "$a0", "$v0");
							   addCode("li", "$a1", "2048");
							   addCode("li", "$v0", "8");
							   addCode("syscall");
							   addCode("move", id = NextRegister(), "$a0");



							   ///// delete last char which is '\n'
							   string tmp = NextRegister();
							   string str1 = "STR1_LOOP_" + generatRandomLabel();
							   string end = "STR_END_LOOP_" + generatRandomLabel();

							   addLabel(str1);
							   addCode("lb", tmp, "($a0)");
							   addCode("beq", tmp, "$0", end);
							   addCode("addi", "$a0", "$a0", "1");
							   addCode("j", str1);
							   addLabel(end);
							   addCode("addi", "$a0", "$a0", "-1");
							   addCode("sb", "$0", "($a0)");
							   break;
		}
		case minusminusNode:
		case plusplusNode:
		{
							 addComment((node->nodeType == plusplusNode) ? "plusplusNode" : "minusminusNode");

							 if (node->left)
							 {
								 // means: $i++;
								 Variable*v = (Variable*)node->left->symbolTableElement;
								 if (v->isType("int") == false)
									 errorHandler(node, "++ and -- operators is only for int variables");

								 if (v->isConst)
									 errorHandler(node, "Const Varaible must not change", string(v->getName()));

								 string tmp = NextRegister(), tmp2;
								 if (v->isStatic)
								 {
									 tmp2 = loadRegval(v->AstLabel);
									 addCode(((node->nodeType == plusplusNode) ? "addi" : "subi"), tmp, tmp2, "1");
									 storeRegVal(v->AstLabel, tmp);
								 }
								 else
								 {
									 tmp2 = NextRegister();
									 addCode("lw", tmp2, to_string(v->AstOffest) + referenceRegister(v->inOuterSpace));
									 addCode(((node->nodeType == plusplusNode) ? "addi" : "subi"), tmp, tmp2, "1");
									 addCode("sw", tmp, to_string(v->AstOffest) + referenceRegister(v->inOuterSpace));
								 }
								 type = v->gettype();
								 id = tmp2;
							 }
							 else
							 {
								 // means: ++$i;
								 Variable*v = (Variable*)node->right->symbolTableElement;
								 if (v->isType("int") == false)
									 errorHandler(node, "++ and -- operators is only for int variables");

								 if (v->isConst)
									 errorHandler(node, "Const Varaible must not change", string(v->getName()));

								 string tmp;
								 if (v->isStatic)
								 {
									 tmp = loadRegval(v->AstLabel);
									 addCode(((node->nodeType == plusplusNode) ? "addi" : "subi"), tmp, tmp, "1");
									 storeRegVal(v->AstLabel, tmp);
								 }
								 else
								 {
									 tmp = NextRegister();
									 addCode("lw", tmp, to_string(v->AstOffest) + referenceRegister(v->inOuterSpace));
									 addCode(((node->nodeType == plusplusNode) ? "addi" : "subi"), tmp, tmp, "1");
									 addCode("sw", tmp, to_string(v->AstOffest) + referenceRegister(v->inOuterSpace));
								 }
								 type = v->gettype();
								 id = tmp;
							 }
							 break;
		}
		case plusNode:
		{
																																										/*
							///////////////////////////////////////////////////////////////////////////////////////////////////////////
							///////////////////////////////////////////////////////////////////////////////////////////////////////////
							///////////////////////////////////////////////////////////////////////////////////////////////////////////
							///////////////////////////////////////////////////////////////////////////////////////////////////////////
							;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
							{} {} {} {} {} {} {} {} {} {} {} {} {} {} {} {} {} {} {} {} {} {} {} {} {} {} {} {} {} {} {} {} {} {} {} {}
							;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
							{} {} {} {} {} {} {} {} {} {} {} {} {} {} {} {} {} {} {} {} {} {} {} {} {} {} {} {} {} {} {} {} {} {} {} {}
							;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
							{} {} {} {} {} {} {} {} {} {} {} {} {} {} {} {} {} {} {} {} {} {} {} {} {} {} {} {} {} {} {} {} {} {} {} {}
							;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
							{} {} {} {} {} {} {} {} {} {} {} {} {} {} {} {} {} {} {} {} {} {} {} {} {} {} {} {} {} {} {} {} {} {} {} {}
							;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
							{} {} {} {} {} {} {} {} {} {} {} {} {} {} {} {} {} {} {} {} {} {} {} {} {} {} {} {} {} {} {} {} {} {} {} {}
							{} {} {} {} {} {} {} {} {} {} {} {} {} {} {} {} {} {} {} {} {} {} {} {} {} {} {} {} {} {} {} {} {} {} {} {}
							{} {} {} {} {} {} {} {} {} {} {} {} {} {} {} {} {} {} {} {} {} {} {} {} {} {} {} {} {} {} {} {} {} {} {} {}
							{} {} {} {} {} {} {} {} {} {} {} {} {} {} {} {} {} {} {} {} {} {} {} {} {} {} {} {} {} {} {} {} {} {} {} {}
							{} {} {} {} {} {} {} {} {} {} {} {} {} {} {} {} {} {} {} {} {} {} {} {} {} {} {} {} {} {} {} {} {} {} {} {}
							{} {} {} {} {} {} {} {} {} {} {} {} {} {} {} {} {} {} {} {} {} {} {} {} {} {} {} {} {} {} {} {} {} {} {} {}
							;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
							;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
							;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
							;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
							true; true; true; true; true; true; true; true; true; true; true; true; true; true; true; true; true; true;
							true; true; true; true; true; true; true; true; true; true; true; true; true; true; true; true; true; true;
							false; false; false; false; false; false; false; false; false; false; false; false; false; false; false;;;
							true; true; true; true; true; true; true; true; true; true; true; true; true; true; true; true; true; true;
							false; false; false; false; false; false; false; false; false; false; false; false; false; false; false;;;
							true; true; true; true; true; true; true; true; true; true; true; true; true; true; true; true; true; true;
							false; false; false; false; false; false; false; false; false; false; false; false; false; false; false;;;
							false; false; false; false; false; false; false; false; false; false; false; false; false; false; false;;;
							true; true; true; true; true; true; true; true; true; true; true; true; true; true; true; true; true; true;
							false; false; false; false; false; false; false; false; false; false; false; false; false; false; false;;;
							true; true; true; true; true; true; true; true; true; true; true; true; true; true; true; true; true; true;
							false; false; false; false; false; false; false; false; false; false; false; false; false; false; false;;;
							true; true; true; true; true; true; true; true; true; true; true; true; true; true; true; true; true; true;
							0000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000;
							0000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000;
							0000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000;
							0000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000;
							0000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000;
							0000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000;
							0000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000;
							0000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000;
							0000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000;
							0000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000;
							0000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000;
							0000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000;
							0000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000;
							0000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000;
							0000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000;
							0000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000;
							0000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000;
							0000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000;
							0000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000;
							0000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000;
							0000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000;												*/


						 string id1, id2, type1, type2;
						 type1 = getType(node->left);     // get the type of the tree without generate any code
						 type2 = getType(node->right);

						 addComment("plusNode");

						 if (type1 == "int" && type2 == "int")
						 {
							 generate(node->left, id1, type1);
							 generate(node->right, id2, type2);

							 id = NextRegister();
							 addCode("add", id, id1, id2);
							 type = "int";
						 }
						 else if ((type1 == "double" && type2 == "int") || (type1 == "int"  && type2 == "double") || (type1 == "double" && type2 == "double"))
						 {
							 generate(node->left, id1, type1);
							 generate(node->right, id2, type2);

							 id = NextRegisterf();

							 if (type1 == "int"  && type2 == "double")
							 {
								 addCode("mtc1", id1, id);
								 addCode("cvt.s.w", id, id);
								 addCode("add.s", id, id2, id);
							 }
							 else if (type1 == "double" && type2 == "int")
							 {
								 addCode("mtc1", id2, id);
								 addCode("cvt.s.w", id, id);
								 addCode("add.s", id, id1, id);
							 }
							 else
								 addCode("add.s", id, id1, id2);
							 type = "double";
						 }
						 else
						 {
							 if (type1 == "string" || type2 == "string")
							 {
								 if (node->left->nodeType == stringValNode)
									 id1 = loadRegAdress(addDataString(node->left->stringval));
								 else
									 generate(node->left, id1, type1);

								 if (type1 == "double")
									 id1 = my_ftoa(id1);
								 else  if (type1 == "int")
									 id1 = my_itoa(id1);

								 if (node->right->nodeType == stringValNode)
									 id2 = loadRegAdress(addDataString(node->right->stringval));
								 else
									 generate(node->right, id2, type2); // reload the string

								 if (type2 == "double")
									 id2 = my_ftoa(id2);
								 else if (type2 == "int")
									 id2 = my_itoa(id2);


								 addCode("li", "$a0", "2048");
								 addCode("li", "$v0", "9");
								 addCode("syscall");

								 addCode("subi", "$sp", "$sp", "4");
								 addCode("sw", "$v0", "($sp)");

								 string tmp = NextRegister();
								 string str1 = "STR1_LOOP_" + generatRandomLabel();
								 string str2 = "STR2_LOOP_" + generatRandomLabel();
								 string str22 = "STR22_LOOP_" + generatRandomLabel();
								 string end = "STR_END_LOOP_" + generatRandomLabel();


								 addLabel(str1);
								 addCode("lb", tmp, "(" + id1 + ")");
								 addCode("beq", tmp, "$0", str2);
								 addCode("sb", tmp, "($v0)");
								 addCode("addi", id1, id1, "1");
								 addCode("addi", "$v0", "$v0", "1");
								 addCode("j", str1);

								 addLabel(str2);

								 //tmp = NextRegister();
								 addLabel(str22);
								 addCode("lb", tmp, "(" + id2 + ")");
								 addCode("sb", tmp, "($v0)");
								 addCode("beq", tmp, "$0", end);
								 addCode("addi", id2, id2, "1");
								 addCode("addi", "$v0", "$v0", "1");
								 addCode("j", str22);
								 addLabel(end);

								 addCode("lw", tmp, "($sp)");
								 addCode("addi", "$sp", "$sp", "4");
								 id = tmp;
								 type = "string";
							 }
						 }

						 break;
		}
		case minusNode:
		{
						  string id1, id2, type1, type2;
						  generate(node->left, id1, type1);
						  generate(node->right, id2, type2);

						  addComment("minusNode");

						  id = NextRegister();

						  if (type1 == "int" && type2 == "int") {
							  addCode("sub", id, id1, id2);
							  type = "int";
						  }
						  else if ((type1 == "double" && type2 == "int") || (type1 == "int"    && type2 == "double") || (type1 == "double" && type2 == "double"))
						  {
							  id = NextRegisterf();
							  if (type1 == "double" && type2 == "int")
							  {
								  addCode("mtc1", id2, id);
								  addCode("cvt.s.w", id, id);
								  addCode("sub.s", id, id1, id);
							  }
							  else if (type1 == "int" && type2 == "double")
							  {
								  addCode("mtc1", id1, id);
								  addCode("cvt.s.w", id, id);
								  addCode("sub.s", id, id, id2);
							  }
							  else if (type1 == "double" && type2 == "double")
								  addCode("sub.s", id, id1, id2);
							  type = "double";
						  }

						  break;
		}
		case multNode:
		{
						 string id1, id2, type1, type2;
						 generate(node->left, id1, type1);
						 generate(node->right, id2, type2);
						 id = NextRegister();

						 addComment("multNode");

						 if (type1 == "int" && type2 == "int") {
							 addCode("mul", id, id1, id2);
							 type = "int";
						 }
						 else if ((type1 == "double" && type2 == "int") || (type1 == "int"    && type2 == "double") || (type1 == "double" && type2 == "double"))
						 {
							 id = NextRegisterf();
							 if (type1 == "double" && type2 == "int")
							 {
								 addCode("mtc1", id2, id);
								 addCode("cvt.s.w", id, id);
								 addCode("mul.s", id, id1, id);
							 }
							 else if (type1 == "int"    && type2 == "double")
							 {
								 addCode("mtc1", id1, id);
								 addCode("cvt.s.w", id, id);
								 addCode("mul.s", id, id, id2);
							 }
							 else if (type1 == "double" && type2 == "double")
								 addCode("mul.s", id, id1, id2);
							 type = "double";
						 }

						 break;
		}
		case divNode:
		{
						string id1, id2, type1, type2;
						generate(node->left, id1, type1);
						generate(node->right, id2, type2);
						id = NextRegister();

						addComment("divNode");

						string itsNotZero = "IT_S__NOT_ZERO_" + generatRandomLabel();
						addCode("bne", "$0", id2, itsNotZero);
						addEcho(addDataString("\"dividing by zero error\""), 4, false);
						addCode("break");
						addLabel(itsNotZero);

						if (type1 == "int" && type2 == "int")
						{
							addCode("div", id, id1, id2);
							type = "int";
						}
						else if ((type1 == "double" && type2 == "int") || (type1 == "int"    && type2 == "double") || (type1 == "double" && type2 == "double"))
						{
							id = NextRegisterf();
							if (type1 == "double" && type2 == "int")
							{
								addCode("mtc1", id2, id);
								addCode("cvt.s.w", id, id);
								addCode("div.s", id, id1, id);
							}
							else if (type1 == "int"    && type2 == "double")
							{
								addCode("mtc1", id1, id);
								addCode("cvt.s.w", id, id);
								addCode("div.s", id, id, id2);
							}
							else if (type1 == "double" && type2 == "double")
								addCode("div.s", id, id1, id2);

							type = "double";
						}
						else
							errorHandler(node, "bad type for div");

						break;
		}
		case modNode:
		{
						string id1, id2, type1, type2;
						generate(node->left, id1, type1);
						generate(node->right, id2, type2);
						id = NextRegister();

						addComment("modNode");
						if (type1 == type2 && type1 == "int")
						{
							addCode("mod", id, id1, id2);  // change this later
						}
						else
							errorHandler(node, "only int type in mod");
						type = "int";
						break;
		}

		case lessThanNode:
		{
							 string id1, id2, type1, type2;
							 generate(node->left, id1, type1);
							 generate(node->right, id2, type2);

							 addComment("lessThanNode");

							 addCode("slt", id = id1, id1, id2);
							 type = "bool";
							 break;
		}
		case moreThanNode:
		{
							 string id1, id2, type1, type2;
							 generate(node->left, id1, type1);
							 generate(node->right, id2, type2);

							 addComment("moreThanNode");

							 addCode("slt", id = id1, id2, id1);
							 type = "bool";
							 //addCode("bge", id1, id2, id);
							 break;
		}
		case IsEqualNode:
		{
							string id1, id2, type1, type2;
							generate(node->left, id1, type1);
							generate(node->right, id2, type2);

							addComment("IsEqualNode");

							type = "bool";
							string truelabel = "TRUELABEL" + generatRandomLabel();
							string falselabel = "FALSELABEL" + generatRandomLabel();

							addCode("beq", id2, id1, truelabel);
							addCode("addi", id1, "$0", "0");
							addCode("j", falselabel);
							addLabel(truelabel);
							addCode("addi", id1, "$0", "1");
							addLabel(falselabel);
							id = id1;
							break;
		}

		case IsNotEqualNode:
		{
							   string id1, id2, type1, type2;
							   generate(node->left, id1, type1);
							   generate(node->right, id2, type2);

							   addComment("IsNotEqualNode");

							   type = "bool";

							   string truelabel = "TRUELABEL" + generatRandomLabel();
							   string falselabel = "FALSELABEL" + generatRandomLabel();

							   addCode("bne", id2, id1, truelabel);
							   addCode("addi", id1, "$0", "0");
							   addCode("j", falselabel);
							   addLabel(truelabel);
							   addCode("addi", id1, "$0", "1");
							   addLabel(falselabel);
							   id = id1;
							   break;
		}
		case lessOrEqualNode:
		{
								string id1, id2, type1, type2;
								generate(node->left, id1, type1);
								generate(node->right, id2, type2);

								addComment("lessOrEqualNode");

								type = "bool";

								string truelabel = "TRUELABEL" + generatRandomLabel();
								string falselabel = "FALSELABEL" + generatRandomLabel();

								addCode("slt", id2, id1, id2);
								addCode("bgtz", id2, truelabel);

								addCode("addi", id1, "$0", "0");
								addCode("j", falselabel);
								addLabel(truelabel);
								addCode("addi", id1, "$0", "1");
								addLabel(falselabel);

								id = id1;
								break;
		}
		case moreOrEqualNode:
		{
								string id1, id2, type1, type2;
								generate(node->left, id1, type1);
								generate(node->right, id2, type2);

								addComment("moreOrEqualNode");

								type = "bool";

								string truelabel = "TRUELABEL" + generatRandomLabel();
								string falselabel = "FALSELABEL" + generatRandomLabel();

								addCode("slt", id2, id2, id1);
								addCode("bgtz", id2, truelabel);

								addCode("addi", id1, "$0", "0");
								addCode("j", falselabel);
								addLabel(truelabel);
								addCode("addi", id1, "$0", "1");
								addLabel(falselabel);
								id = id1;
								break;
		}
		case NotBooleanNode:
		{
							   addComment("NotBooleanNode");

							   string id1, type1;
							   generate(node->left, id1, type1);

							   string truelabel = "TRUELABEL" + generatRandomLabel();
							   string falselabel = "FALSELABEL" + generatRandomLabel();

							   addCode("beq", "$0", id1, truelabel);
							   addCode("addi", id1, "$0", "0");
							   addCode("j", falselabel);
							   addLabel(truelabel);
							   addCode("addi", id1, "$0", "1");
							   addLabel(falselabel);

							   id = id1;
							   type = "bool";

							   break;
		}
		case booleanOrNode:
		{
							  addComment("booleanOrNode");

							  string id1, id2, type1, type2;
							  generate(node->left, id1, type1);
							  generate(node->right, id2, type2);

							  string falselabel = "FASLELABEL" + generatRandomLabel();
							  string truelabel = "TRUELABEL" + generatRandomLabel();

							  addCode("bne", "$0", id1, truelabel);
							  addCode("bne", "$0", id2, truelabel);

							  addCode("j", falselabel);
							  addLabel(truelabel);
							  addCode("li", id1, "1");
							  addLabel(falselabel);
							  id = id1;
							  break;
		}
		case booleanAndNode:
		{
							   addComment("booleanAndNode");

							   string id1, id2, type1, type2;
							   generate(node->left, id1, type1);
							   generate(node->right, id2, type2);

							   string truelabel = "TRUELABEL" + generatRandomLabel();
							   string falselabel = "FALSELABEL" + generatRandomLabel();

							   addCode("beq", "$0", id1, falselabel);
							   addCode("beq", "$0", id2, falselabel);
							   addCode("j", truelabel);
							   addLabel(falselabel);
							   addCode("li", id1, "0");
							   addLabel(truelabel);

							   id = id1;
							   break;
		}
		case booleanOrOrNode:
		{
								addComment("booleanOrNode");

								string falselabel = "FASLELABEL" + generatRandomLabel();
								string truelabel = "TRUELABEL" + generatRandomLabel();

								string id1, id2, type1, type2;
								generate(node->left, id1, type1);
								addCode("bne", "$0", id1, truelabel);
								generate(node->right, id2, type2);
								addCode("bne", "$0", id2, truelabel);

								addCode("j", falselabel);
								addLabel(truelabel);
								addCode("li", id1, "1");
								addLabel(falselabel);
								id = id1;
								break;
		}
		case booleanAndAndNode:
		{
								  addComment("booleanAndNode");
								  string truelabel = "TRUELABEL" + generatRandomLabel();
								  string falselabel = "FALSELABEL" + generatRandomLabel();

								  string id1, id2, type1, type2;
								  generate(node->left, id1, type1);
								  addCode("beq", "$0", id1, falselabel);
								  generate(node->right, id2, type2);
								  addCode("beq", "$0", id2, falselabel);

								  addCode("j", truelabel);
								  addLabel(falselabel);
								  addCode("li", id1, "0");
								  addLabel(truelabel);

								  id = id1;
								  break;
		}

		case ifNode:
		{
					   addComment("ifNode");

					   string endif = "ENDIF" + generatRandomLabel();
					   generate(node->left, endif, type);  // LEFT NODE is the main if statment (ifConditionAndBodyNode)
					   generate(node->right, endif, type); // RIGHT NODE is else statment which contain elseif list  (elseNode)

					   addLabel(endif);
					   break;
		}
		case ifConditionAndBodyNode:
		case elseifConditionAndBodyNode:
		{
										   // LEFT NODE is the condition Node and
										   // RIGHT NODE is if's body

										   addComment("ifConditionAndBodyNode");

										   string idx = "";
										   string body = "BODY_" + generatRandomLabel();
										   string els = "ELSE_" + generatRandomLabel();
										   generate(node->left, idx, type); // generate the if condtion
										   addCode("bne", idx, "$0", body);

										   addCode("j", els, "", "");

										   addLabel(body); // add label
										   string id2;
										   generate(node->right, id2, type);
										   addCode("j", id, "", "");

										   addLabel(els); // add label
										   break;
		}

		case whileNode:
		{
						  addComment("whileNode");

						  string
							  startLabel = "WHILE_START_" + generatRandomLabel(),
							  bodyLabel = "WHILE_BODY_" + generatRandomLabel(),
							  endLoopLabel = "WHILE_EXIT_" + generatRandomLabel(),
							  idx = "";


						  youAreNowInsideSomeLoooooooooopFlag = true;
						  lastLoopEndLabel = endLoopLabel;
						  lastLoopStartLabel = startLabel;


						  addLabel(startLabel);
						  generate(node->left, idx, type); // generate the while condtion

						  addCode("bne", idx, "$0", bodyLabel);

						  addCode("j", endLoopLabel);

						  addLabel(bodyLabel);
						  generate(node->right, id, type);  // generate the body
						  addCode("j", startLabel, "", "");

						  addLabel(endLoopLabel);


						  youAreNowInsideSomeLoooooooooopFlag = false;

						  break;
		}
		case doWhileNode:
		{
							addComment("doWhileNode");

							string startLabel = "WHILE_START_" + generatRandomLabel(),
								endLoopLabel = "WHILE_END_" + generatRandomLabel(),
								idx = "";

							youAreNowInsideSomeLoooooooooopFlag = true;
							lastLoopEndLabel = endLoopLabel;
							lastLoopStartLabel = startLabel;

							addLabel(startLabel);
							generate(node->left, id, type);          // generate the do while body
							generate(node->right, idx, type);        // generate the do while condtion
							addCode("bne", idx, "$0", startLabel);
							addLabel(endLoopLabel);

							youAreNowInsideSomeLoooooooooopFlag = false;
							break;
		}
		case forNode:
		{
						addComment("forNode");

						string
							startLabel = "FOR_START_" + generatRandomLabel(),
							bodyLabel = "FOR_BODY_" + generatRandomLabel(),
							endLoopLabel = "END_FOR_" + generatRandomLabel(),
							end_FOR_LoopLabel = "END_FOR_BUT_BEFORE_THIRD_STATMENT_" + generatRandomLabel(),
							idx = "";

						youAreNowInsideSomeLoooooooooopFlag = true;
						lastLoopEndLabel = endLoopLabel;
						lastLoopStartLabel = end_FOR_LoopLabel;

						if (node->left)
							generate(node->left->left, id, type);   // generate the for's first statment             int i
						addLabel(startLabel);
						if (node->left)
							generate(node->left->right, idx, type); // generate the for's second statment (condtion)    i < 10
						addCode("bne", idx, "$0", bodyLabel);

						if (node->left->right != NULL) // if there is condition on second statment then just jump to endLoopLabel
							addCode("j", endLoopLabel);

						addLabel(bodyLabel);
						generate(node->right->left, id, type);             // generate the for's body

						addLabel(end_FOR_LoopLabel);
						generate(node->right->right, id, type);             // generate the for's third statment   i++
						addCode("j", startLabel);
						addLabel(endLoopLabel);

						youAreNowInsideSomeLoooooooooopFlag = false;

						break;
		}

			//===================================================================
			//=========================   by ziad   =======================
			//===================================================================
		case switchNode:
		{
						   addComment("switchNode");

						   youAreNowInsideSwitch++;
						   string ExtLbl = "SWITCH_EXT_" + generatRandomLabel();
						   lastswitchEndLabel.push(ExtLbl);

						   string  left_id, left_type, right_id, right_type, lable_case;
						   generate(node->left, left_id, left_type);     //  <<<generate for condition Switch >>>
						   if (!(left_type == "int" || left_type == "string"))
						   {
							   errorHandler(node, "bad varaible's type in switch");
							   break;
						   }

						   addCode("move", "$a2", left_id);

						   TreeNode* m = node->right;
						   queue<string> caseLabels;
						   string tmpR = "$a1";
						   while (m && m->left)
						   {
							   lable_case = "Case_" + generatRandomLabel();

							   if (m->left->left)  // it's not default
							   {
								   //generate(m->left->left, left_id, right_type);

								   // foreach  for  find to case in The Cases vector 
								   if (m->left->left->nodeType == intValNode)
								   {
									   right_type = "int";
									   addCode("li", "$a1", to_string(m->left->left->intval));
									   for each (int case_exp in casesSwitch)
									   if (generate_hash(m->left->left->intval) == case_exp)
										   errorHandler(m->left->left, " case   " + to_string(m->left->left->intval) + " is existing");

									   casesSwitch.push_back(generate_hash(m->left->left->intval));
								   }
								   else if (m->left->left->nodeType == stringValNode)
								   {
									   right_type = "string";
									   addCode("la", "$a1", addDataString(m->left->left->stringval));

									   for each (int case_exp in casesSwitch)
									   if (generate_hash(m->left->left->stringval) == case_exp)
										   errorHandler(m->left->left, " case is existing");

									   casesSwitch.push_back(generate_hash(m->left->left->stringval));
								   }

								   //==============================================

								   if (CheckTypesforAssign(left_type, right_type) == false)
									   errorHandler(node, "bad varaible's type in case");

								   addCode("beq", left_id, "$a1", lable_case);
							   }
							   else
								   addCode("j", lable_case);

							   caseLabels.push(lable_case);

							   m = m->right;
						   }

						   addCode("j", ExtLbl);

						   m = node->right;
						   while (m)
						   {
							   if (caseLabels.empty() == false)
							   {
								   addLabel(caseLabels.front());
								   caseLabels.pop();
								   if (m->left)
									   generate(m->left->right, right_id, right_type);
							   }
							   m = m->right;
						   }

						   addLabel(ExtLbl);
						   youAreNowInsideSwitch--;
						   lastswitchEndLabel.pop();
						   break;
		}


		case foreachNode:
		{
							//generate(node->left, id, type);
							string r_id, l_id, r_type, l_type;
							if (node->left == NULL)
								break;

							generate(node->left->left, l_id, l_type);
							generate(node->left->right, r_id, r_type);
							if (node->left->left->symbolTableElement == NULL)
								break;

							((Variable*)node->left->left->symbolTableElement)->setInitialed();

							string foreachStartLable = "FOREACH_START_LABEL_" + generatRandomLabel();
							string foreachENDLable = "FOREACH_END_LABEL_" + generatRandomLabel();
							addLabel(foreachStartLable);
							string tmp = NextRegister();
							addCode("lw", tmp, "(" + r_id + ")");
							addCode("beq", "$0", tmp, foreachENDLable);
							addCode("sw", tmp, l_id + "($fp)");

							generate(node->right, id, type);
							addCode("addi", r_id, r_id, "4");

							addCode("j", foreachStartLable);
							addLabel(foreachENDLable);
							break;
		}

			//================================================================================
			//================================================================================
			//================================================================================

		case returnNode:
		{
						   addComment("returnNode");
						   if (youAreNowInsideSomeFunctionFlag == false)
							   errorHandler(node, "return keyword not allowed outside the functions");

						   if (youAreNowInsideSomeConsturactorFlag == true)
							   errorHandler(node, "return keyword not allowed inside Conturactors");

						   if (node->left != NULL)
						   {
							   string id1 = "", type1 = "";
							   generate(node->left, id1, type1);

							   if (lastFunctionReturntype == "void")
								   errorHandler(node, "void functions should not return value");
							   else
							   if (CheckTypesforAssign(lastFunctionReturntype, type1) == false)
								   errorHandler(node, "the type \'" + type1 + "\' not match the function's return type \'" + lastFunctionReturntype + "\'");

							   if (type1 == "double")
								   addCode("mfc1", "$v0", id1);
							   else
								   addCode("move", "$v0", id1);
						   }

						   type = lastFunctionReturntype;
						   //id = "$v0";
						   addCode("j", lastFunctionEndOfFunctionLabel);
						   break;
		}

		case breakNode:
		{
						  addComment("breakNode");
						  if (youAreNowInsideSwitch > 0)
						  {
							  addCode("j", lastswitchEndLabel.top());
						  }
						  else if (youAreNowInsideSomeLoooooooooopFlag)
						  {
							  if (node->left == NULL)
								  addCode("j", lastLoopEndLabel);
							  else
							  {
								  // todo later 
								  //       generate the node->left and do stuff
							  }
						  }
						  else
						  {
							  errorHandler(node, "break keyword not allowed outside loops or switch case");
						  }

						  break;
		}
		case continueNode:
		{
							 addComment("continueNode");
							 if (youAreNowInsideSomeLoooooooooopFlag)
							 {
								 if (node->left == NULL)
									 addCode("j", lastLoopStartLabel);
								 else
								 {
									 // todo later 
									 //       generate the node->left and do stuff
								 }
							 }
							 else
								 errorHandler(node, "continue keyword not allowed outside loops");
							 break;
		}

		case scopeNode:
		{
						  addComment("scopeNode start");

						  //lastScopeSize = node->size;

						  if (node->size > 0)
						  {
							  addCode("subi", "$sp", "$sp", to_string(node->size));
							  //pushLocalVariableCounter();
						  }

						  generate(node->left, id, type);

						  addComment("scopeNode end");
						  if (node->size > 0)
						  {
							  addCode("addi", "$sp", "$sp", to_string(node->size));
							  //popLocalVariableCounter();
						  }

						  break;
		}
		case functionCallNode:
		{
								 Function* f = (Function*)(node->symbolTableElement);
								 addComment("functionCallNode " + f->AstLabel);

								 // save last used register														this need some improving
								 string previous_reqister_that_may_was_in_use = "$t" + to_string((TRegister <= 1) ? 0 : ((TRegister - 2) % 7));
								 string previous_reqister_that_may_was_in_use2 = "$t" + to_string((TRegister <= 0) ? 0 : ((TRegister - 1) % 7));
								 addCode("subi", "$sp", "$sp", "4");
								 addCode("sw", previous_reqister_that_may_was_in_use, "0($sp)");
								 addCode("subi", "$sp", "$sp", "4");
								 addCode("sw", previous_reqister_that_may_was_in_use2, "0($sp)");



								 addComment("pushing arguments");
								 // push all argument in the stack
								 int paramterCount = f->getParametersCount();
								 int size = paramterCount * 4;
								 TreeNode* mover = node->right;
								 
								 if (f->getParametersCount() > 0)
								 {
									 addCode("subi", "$sp", "$sp", to_string(size));
									 if (f->isInsideClass && !f->isStatic()) // if calling instance function so pushing the vtable paramater here as first parameter
									 {
										 size -= 4;
										 paramterCount--;

										 if (fromA1register > 0)
										 {
											 addCode("sw", "$a3", to_string(size) + "($sp)   # vtable");    // must contain the vtable
										 }
										 else
										 {
											 string t = NextRegister();
											 addCode("lw", t, "-4($fp)");                   // $fp  must contain the vtable
											 addCode("sw", t, to_string(size) + "($sp)   # vtable");
										 }
									 }

									 // pushing the arguments' values to stack
									 string tmp = NextRegister();
									 string tmpf = NextRegisterf();
									 for (; mover; mover = mover->right) // for all parameters
									 {
										 Variable * Param = NULL;
										 if (f->getSignature() != NULL)
											 Param = f->getSignature()->getParameter((f->getParametersCount() - (f->isInsideClass && !f->isStatic() ? 1 : 0)) - paramterCount);

										 if (Param == NULL)
										 {
											 errorHandler(node, "too many argumnet in function call", string(f->getName()));
											 break;
										 }

										 if (Param->getIsReferenceParamter())
										 {
											 if (mover->left->nodeType != callVariableNode)
												 errorHandler(node, "reference parameter must be variable", string(f->getName()));
											 else
											 {
												 Variable* t = (Variable*)mover->left->symbolTableElement;
												 if (t->itsDataMember == false && t->isParamter() == false && t->getIsInitialed() == false)
												 {
													 errorHandler(node, "using non-initialized variable", string(t->getName()));
												 }


												 if (t->isStatic)
													 addCode("la", tmp, t->AstLabel);
												 else if (t->itsDataMember)
													 addCode("lw", tmp, "-4($fp)");  // load the VTABLE  which is always the first paramater
												 else
													if (t->getIsReferenceParamter())
														 addCode("lw", tmp, to_string(t->AstOffest) + "($fp)"); // or la
													else
														addCode("addi", tmp, t->inOuterSpace ? "$t9" : "$fp", to_string(t->AstOffest));

													if (CheckTypesforAssign(Param->gettype(), string(t->gettype())) == false)
														errorHandler(mover, "argument of type \'" + string(t->gettype()) + "\' is incompatible with parameter of type \'" + string(Param->gettype()) + "\'", f->getName());
											 }
										 }
										 else
										 {
											 switch (mover->left->nodeType)
											 {
											 case intValNode:
												 //if (strcmp(params->getParameter(i)->gettype(), "int") != 0) //	;// error //else;
												 addCode("addi", tmp, "$0", to_string(mover->left->intval));
												 type = "int";
												 break;

											 case doubleValNode:
												 //addCode("addi", tmp, "$0", to_string(mover->left->doubleval));
												 tmpf = loadImmidiateForDouble(mover->left->doubleval);
												 type = "double";
												 break;

											 case stringValNode:
												 addCode("la", tmp, addDataString(mover->left->stringval));
												 type = "string";
												 break;

											 default:
												 generate(mover->left, tmp, type);
												 break;
											 }

											 if (CheckTypesforAssign(Param->gettype(), type) == false)
												 errorHandler(mover, "argument of type \'" + type + "\' is incompatible with parameter of type \'" + string(Param->gettype()) + "\'", f->getName());
										 }
										 size -= 4;
										 paramterCount--;

										 if (type == "double")
											 addCode("s.s", tmpf, to_string(size) + "($sp)");
										 else
											 addCode("sw", tmp, to_string(size) + "($sp)");
									 }
								 }

								 int x = 0;
								 while (paramterCount > 0) // it means that there are optional paramaters
								 {
									 paramterCount--;

									 string tmp, typet;
									 TreeNode* t = (TreeNode*)(f->getSignature()->getTreeNodeOfOptionalParamteresNumber(x++));
									 if (t == NULL)
										 break; // some error

									 typet = "echo";
									 generate(t, tmp, typet);

									 size -= 4;
									 if (typet == "double")
										 addCode("s.s", tmp, to_string(size) + "($sp)");
									 else if (typet == "string")
										 addCode("sw", loadRegAdress(tmp), to_string(size) + "($sp)");
									 else
										 addCode("sw", tmp, to_string(size) + "($sp)");
								 }

								 if (paramterCount < 0)
									 errorHandler(node, "too many argumnet in function call", string(f->getName()));

								 if (size > 0)
									 errorHandler(node, "too few argumnet in function call", string(f->getName()));

								 if (f->isAbstract())
								 {
									 // I fetch the child function's address for vtable and jump to it,
									 string tmp = NextRegister();
									 if (fromA1register > 0)
										 addCode("move", tmp, "$a3");
									 else
										 addCode("lw", tmp, "-4($fp)");  // load the VTABLE  which is always the first paramater

									 addCode("lw", tmp, to_string(f->AstOffest_ForAbstractFunctionsOnly) + "(" + tmp + ")");
									 addCode("jalr", tmp);
								 }
								 else
									 addCode("jal", f->AstLabel); // jump and link

								 addCode("lw", previous_reqister_that_may_was_in_use, "0($sp)");
								 addCode("addi", "$sp", "$sp", "4");
								 addCode("lw", previous_reqister_that_may_was_in_use2, "0($sp)");
								 addCode("addi", "$sp", "$sp", "4");


								 if (strcmp(f->getReturnType(), "void") != 0)
								 if (strcmp(f->getReturnType(), "double") == 0)
									 addCode("mtc1", "$v0", id = NextRegisterf());
								 else
									 addCode("move", id = NextRegister(), "$v0");

								 //else
								 //	id = "";
								 type = f->getReturnType();
								 break;
		}
		case functionNode:
		{
							 Function* f = (Function*)(node->symbolTableElement);
							 if (f->isAbstract())
							 {
								 break;
							 }
							 string skipLable = "SKIP_" + generatRandomLabel();
							 string EOFLable = "EOF_" + string(f->getName()) + "_" + generatRandomLabel();

							 addCode("j", skipLable);
							 addComment("functionNode start");
							 addNewLine();

							 youAreNowInsideSomeConsturactorFlag = f->getIsConsturctor();
							 youAreNowInsideSomeFunctionFlag = true;
							 lastFunctionReturntype = f->getReturnType();
							 lastFunctionEndOfFunctionLabel = EOFLable;

							 addLabel(f->AstLabel);

							 youAreNowInsideSomeNotStaticFunctionWhichInsideClassFlag = (f->isInsideClass && !f->isStatic());

							 addCode("subi", "$sp", "$sp", "4");
							 addCode("sw", "$ra", "0($sp)");
							 addCode("subi", "$sp", "$sp", "4");
							 addCode("sw", "$fp", "0($sp)");

							 addCode("addi", "$fp", "$sp", to_string(4 * (2 + f->getParametersCount())));


							 // this will call the default consturctor of base class (from inheretince)
							 if (f->isInsideClass && f->getIsConsturctor() == true && f->getHasSuper() == false)
							 {
								 TreeNode * t = new TreeNode();
								 t->nodeType = functionCallNode;
								 t->left = 0;
								 t->right = 0;
								 t->symbolTableElement = SymbolTable::getFatherConsturactor(f);
								 if (t->symbolTableElement)
									 generate(t, id, type);
							 }

							 generate(node->right, id, type); // function's body

							 addLabel(EOFLable);
							 string x = NextRegister();
							 addCode("move", x, "$fp");
							 addCode("lw", "$ra", to_string((f->getParametersCount() + 1) * -4) + "($fp)");
							 addCode("lw", "$fp", to_string((f->getParametersCount() + 2) * -4) + "($fp)");
							 addCode("move", "$sp", x);
							 addCode("addi", "$sp", "$sp", "-4");
							 addCode("jr", "$ra");


							 type = f->getReturnType();
							 addComment("functionNode end");
							 addNewLine();
							 addLabel(skipLable);

							 youAreNowInsideSomeConsturactorFlag = false;
							 youAreNowInsideSomeFunctionFlag = false;
							 youAreNowInsideSomeNotStaticFunctionWhichInsideClassFlag = false;
							 lastFunctionReturntype = "";
							 break;
		}
			//case classNode:
			//{
			//	addComment("classNode");
			//	generate(node->left, id, type);
			//	break;
			//}
		case newClassInstance:
		{
								 addComment("newClassInstance");
								 Type* t = ((Type*)node->symbolTableElement);
								 vector<DataMember*> v = t->get__V_TABLE__forCodeGenerating();

								 addCode("li", "$a0", to_string(t->gaveMeNumberOfTheVariable() * 4));
								 addCode("li", "$v0", "9");
								 addCode("syscall", "");
								 addCode("move", id = NextRegister(), "$v0");
								 type = t->getName();

								 string tmp2 = NextRegister(), value;
								 for (int i = 0; i < v.size(); i++)
								 {
									 if (strcmp(v.at(i)->getvalue(), "") == 0)
									 {
										 value = "0";
										 if (v.at(i)->isType("double"))
											 value = "0.0";
										 else if (v.at(i)->isType("string"))
											 value = "\"\"";
									 }
									 else
										 value = v.at(i)->getvalue(); // here must check the value type too ?

									 if (v.at(i)->isType("double"))
									 {
										 tmp2 = loadImmidiateForDouble(atof(value.c_str()));
										 addCode("s.s", tmp2, to_string(v.at(i)->AstOffest) + "(" + id + ")");
									 }
									 else if (v.at(i)->isType("string"))
									 {
										 tmp2 = loadRegAdress(addDataString(value));
										 addCode("sw", tmp2, to_string(v.at(i)->AstOffest) + "(" + id + ")");
									 }
									 else //if (v.at(i)->isType("int") || v.at(i)->isType("bool"))  // or pointer
									 {
										 addCode("li", tmp2, value);
										 addCode("sw", tmp2, to_string(v.at(i)->AstOffest) + "(" + id + ")");
									 }
								 }

								 //for each function if it override an abstract function then :
								 vector<Function*> ff = t->getOverridedFunctionForAbstractFunctions();
								 for (int i = 0; i < ff.size(); i++)
								 {
									 addCode("la", tmp2, ff.at(i)->AstLabel);  // load the address of function
									 addCode("sw", tmp2, to_string(ff.at(i)->fathersOverridedFunction->AstOffest_ForAbstractFunctionsOnly) + "(" + id + ")");
								 }

								 TreeNode * tmp = new TreeNode();
								 tmp->nodeType = functionCallNode;
								 tmp->right = node->left;
								 tmp->symbolTableElement = t->getConsturactor();

								 addCode("subi", "$sp", "$sp", "4");
								 addCode("sw", "$a3", "0($sp)");

								 addCode("move", "$a3", id);

								 fromA1register++;

								 string id2, type2;
								 generate(tmp, id2, type2);

								 fromA1register--;

								 addCode("lw", "$a3", "0($sp)");
								 addCode("addi", "$sp", "$sp", "4");

								 break;
		}
		case objectAccessToVariableNode:
		{
										   // symboltableElement of  node->left  is the object pointer
										   // symboltableElement of  node        is the datamember
										   //
										   addComment("objectAccessToVariableNode");

										   string left_id, left_type;
										   generate(node->left, left_id, left_type); // the object pointer

										   Variable* v = (Variable*)node->symbolTableElement;
										   if (v == NULL)
											   v = (Variable*)node->left->symbolTableElement;

										   id = loadDataVal(v, left_id);
										   type = v->gettype();

										   break;
		}
		case objectAccessToFunctionNode:
		{
										   addComment("objectAccessToFunctionNode");
										   generate(node->left, id, type); // the object pointer

										   node->nodeType = functionCallNode;

										   // pushing the vtable valuee here
										   //
										   // store $fp
										   // $fp <-- id
										   // generate
										   // restore $fp
										   //

										   addCode("subi", "$sp", "$sp", "4");
										   addCode("sw", "$a3", "0($sp)");
										   addCode("move", "$a3", id);
										   fromA1register++;

										   generate(node, id, type);   // functionCallNode

										   fromA1register--;

										   addCode("lw", "$a3", "0($sp)");
										   addCode("addi", "$sp", "$sp", "4");

										   break;
		}
		case stmtListNode:
		{
							 // to avoid  'stackoverflow' exeption I reduce recursivly travaling in the tree
							 // so don't remove this
							 // p.s. : this expetion occur when the code is big and there are a lot of stmtListNode
							 //

							 for (TreeNode * m = node; m; m = m->right)
								 generate(m->left, id, type);
							 break;
		}
		default:
			generate(node->left, id, type);
			generate(node->right, id, type);
			break;
		}
	}


	string Generate(TreeNode * t)
	{
		string q, e;
		generate(t, q, e);
		finishize();
		return print();
	}
};
