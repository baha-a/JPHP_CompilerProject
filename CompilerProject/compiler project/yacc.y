%output ="yacc.cpp"
%{
    #define YYDEBUG 1
	 
	#include "Code\HelperCode.h"
	#include "Code\AST\AST.h"
	using namespace banana;

	#include <iostream>
	using namespace std;
	#include "FlexLexer.h"


	#define YYERROR_VERBOSE
	#define yyerrok		(yyerrstatus = 0)
	#define yyclearin	(yychar = YYEMPTY)
	int yyerrstatus;



	int yylex(void);
	int yyparse();
	void yyerror(const char *);
	

	FlexLexer* lexer = new yyFlexLexer();
	class Parser
	{
		public:
		int	parse()
		{
			return yyparse();
		}
	};


	AST * ast = new AST();

	TreeNode * finalTree = new TreeNode();
	TreeNode * TempTree = NULL;
%}

%nonassoc _def_val_2
%nonassoc test0
%nonassoc _def_val_ test test2
%nonassoc test3

%left T_INCLUDE T_INCLUDE_ONCE
%left ','
%left T_LOGICAL_OR
%left T_LOGICAL_XOR
%left T_LOGICAL_AND
%right T_DOUBLE_ARROW
%left '=' T_PLUS_EQUAL T_MINUS_EQUAL T_MUL_EQUAL T_DIV_EQUAL T_CONCAT_EQUAL T_MOD_EQUAL T_AND_EQUAL T_OR_EQUAL T_XOR_EQUAL T_SR_EQUAL T_POW_EQUAL
%left '?' ':'
%right T_COALESCE
%left T_BOOLEAN_OR
%left T_BOOLEAN_AND
%left '|'
%left '^'
%left '&'
%nonassoc T_IS_EQUAL T_IS_NOT_EQUAL
%nonassoc '<' T_IS_SMALLER_OR_EQUAL '>' T_IS_GREATER_OR_EQUAL
%left T_SL T_SR
%left '+' '-' '.'
%left '*' '/' '%'
%right '!'
%right '~' T_INC T_DEC T_INT_CAST T_DOUBLE_CAST T_STRING_CAST T_BOOL_CAST
%right T_POW

%nonassoc T_NEW T_CLONE
%token T_IF        "if (T_IF)"
%nonassoc elseif_list_test
%left T_ELSEIF		"elseif (T_ELSEIF)"
%left T_ELSE		"else (T_ELSE)"

%token T_LNUMBER   "integer number (T_LNUMBER)"
%token T_DNUMBER   "floating-point number (T_DNUMBER)"
%token T_STRING    "identifier (T_STRING)"
%token T_VARIABLE  "variable (T_VARIABLE)"
%token T_NUM_STRING "number (T_NUM_STRING)"
%token T_ENCAPSED_AND_WHITESPACE  "quoted-string and whitespace (T_ENCAPSED_AND_WHITESPACE)"
%token T_CONSTANT_ENCAPSED_STRING "quoted-string (T_CONSTANT_ENCAPSED_STRING)"

%token T_TRUE        "true (T_TRUE)"
%token T_FALSE       "false (T_FALSE)"
%token T_NULL        "null (T_NULL)"
%token T_SUPER       "super (T_SUPER)"
%token T_READ_INT       "read int (T_READ_INT)"
%token T_READ_DOUBLE       "read double (T_READ_DOUBLE)"
%token T_READ_STRING       "read string (T_READ_STRING)"
%token T_ECHO       "echo (T_ECHO)"
%token T_DO         "do (T_DO)"
%token T_WHILE      "while (T_WHILE)"
%token T_ENDWHILE   "endwhile (T_ENDWHILE)"
%token T_FOR        "for (T_FOR)"
%token T_ENDFOR     "endfor (T_ENDFOR)"
%token T_FOREACH    "foreach (T_FOREACH)"
%token T_ENDFOREACH "endforeach (T_ENDFOREACH)"
%token T_AS         "as (T_AS)"
%token T_SWITCH     "switch (T_SWITCH)"
%token T_ENDSWITCH  "endswitch (T_ENDSWITCH)"
%token T_CASE       "case (T_CASE)"
%token T_DEFAULT    "default (T_DEFAULT)"
%token T_BREAK      "break (T_BREAK)"
%token T_CONTINUE   "continue (T_CONTINUE)"
%token T_GOTO       "goto (T_GOTO)"
%token T_FUNCTION   "function (T_FUNCTION)"
%token T_CONST      "const (T_CONST)"
%token T_RETURN     "return (T_RETURN)"
%token T_TRY        "try (T_TRY)"
%token T_CATCH      "catch (T_CATCH)"
%token T_FINALLY    "finally (T_FINALLY)"
%token T_THROW      "throw (T_THROW)"
%right T_STATIC T_ABSTRACT T_FINAL T_PRIVATE T_PROTECTED T_PUBLIC
%token T_CLASS      "class (T_CLASS)"
%token T_INTERFACE  "interface (T_INTERFACE)"
%token T_EXTENDS    "extends (T_EXTENDS)"
%token T_IMPLEMENTS "implements (T_IMPLEMENTS)"
%token T_OBJECT_OPERATOR "-> (T_OBJECT_OPERATOR)"
%token T_DOUBLE_ARROW    "=> (T_DOUBLE_ARROW)"
%token T_OPEN_TAG_PHP
%token T_CLOSE_TAG_PHP
%token T_PAAMAYIM_NEKUDOTAYIM ":: (T_PAAMAYIM_NEKUDOTAYIM)"
%token T_ELLIPSIS        "... (T_ELLIPSIS)"


%token T_V_INT		"int (T_V_INT)"
%token T_V_STRING	"string (T_V_STRING)"
%token T_V_BOOL		"bool (T_V_BOOL)"
%token T_V_CHAR		"char (T_V_CHAR) "
%token T_V_DOUBLE	"double (T_V_DOUBLE) "
%token T_V_FLOAT	"float (T_V_FLOAT) "
%token T_V_REAL		"real (T_V_REAL) "
%token T_V_LONG		"long (T_V_LONG) "
%token T_V_BYTE		"byte (T_V_BYTE) "
%token T_V_UINT		"uint (T_V_UINT) "
%token T_V_ULONG	"ulong (T_V_ULONG) "
%token T_V_UBYTE	"ubyte (T_V_UBYTE) "


%nonassoc lowpriority
%nonassoc lowpriority2
%nonassoc lowpriority3
%nonassoc lowpriority4


%nonassoc '['
%nonassoc '{'

%nonassoc ')' '('

%union{
	struct R{

		int intvalue;
		double floatvalue;
		char* stringvalue;

		char* identifier;
		char* name;

		char* type_name;


		float f;
		char c;
		char* str;
		int myLineNo;
		int myColno;
		bool worngID;
		
		Type* type;
		
		}r;
		
		class TreeNode * ast;
	}

%%

start:
    { EatUntilGetPhpTag(); startNewScope();} T_OPEN_TAG_PHP top_statement_listX T_CLOSE_TAG_PHP { 
																						  EndOfPhpCode();
																						  debuggerYACC(" X205 - start << T_OPEN_TAG_PHP top_statement_list T_CLOSE_TAG_PHP");
																						  EatUntilEndOfFile();

																						  $<ast>$ = ast->createNode($<ast>3,0,scopeNode)->addScopeSize(closeScope());
																						  finalTree = $<ast>$;
																						}
;

top_statement_listX:
		{	 
			 ClassDeclaration("Object"); 
			 TempTree = ast->createNode(ast->createNode(0,0,classListNode),0,classNode);
			 TempTree->addSymbolTableElement(ClassDeclarationEnd());
		}
	top_statement_list 
		{
			 $<ast>$ = ast->addToLastRight(ast->createNode(TempTree,0,stmtListNode), $<ast>2);
		}
;

top_statement_list:
      top_statement_list top_statement   { $<ast>$ = ast->addToLastRight($<ast>1, $<ast>2);     debuggerYACC(" X211 - top_statement_list << top_statement_list top_statement"); }
    | /* empty */           { $<ast>$ = ast->createNode(0,0,stmtListNode);       debuggerYACC(" X212 - top_statement_list << | /* empty */"); }
;

top_statement:
      statement                                  { $<ast>$ = ast->createNode($<ast>1,0,stmtListNode);  debuggerYACC(" X304 - top_statement << statement"); }
    | function_declaration_statement             { $<ast>$ = ast->createNode($<ast>1,0,stmtListNode); debuggerYACC(" X305 - top_statement << | function_declaration_statement"); }
    | class_declaration_statement                { $<ast>$ = ast->createNode($<ast>1,0,stmtListNode); debuggerYACC(" X306 - top_statement << | class_declaration_statement"); }
;

inner_statement_list:
      inner_statement_list inner_statement      { $<ast>$ = ast->addToLastRight($<ast>1,$<ast>2);   debuggerYACC(" X382 - inner_statement_list << inner_statement_list inner_statement"); }
    | /* empty */                               { $<ast>$ = ast->createNode(0,0,stmtListNode);    debuggerYACC(" X383 - inner_statement_list << | /* empty */"); }
;


inner_statement:
      statement                             { IncreceStatementNumber(); $<ast>$ = ast->createNode($<ast>1,0,stmtListNode); debuggerYACC(" X387 - inner_statement << statement"); }
    | function_declaration_statement        { $<ast>$ = ast->createNode($<ast>1,0,stmtListNode); debuggerYACC(" X388 - inner_statement << | function_declaration_statement"); }
    | class_declaration_statement           { $<ast>$ = ast->createNode($<ast>1,0,stmtListNode); debuggerYACC(" X389 - inner_statement << | class_declaration_statement"); }
;

scope:
'{'  { startNewScope(); }  inner_statement_list '}'  { $<ast>$ = ast->createNode($<ast>3,0,scopeNode)->addScopeSize(closeScope());  debuggerYACC(" X395 - scope << '{' inner_statement_list '}'"); }
;

statement:
    scope
    | T_IF parentheses_expr statement elseif_list T_ELSE statement                        
		{ 
			$<ast>$=ast->createNode(
						ast->createNode($<ast>2,$<ast>3,ifConditionAndBodyNode),
						
						ast->createNode($<ast>4,$<ast>6,elseNode),
						
						ifNode);
			debuggerYACC(" X396 - statement << | T_IF parentheses_expr statement elseif_list T_ELSE statement"); 
		}
    | T_IF parentheses_expr statement elseif_list %prec    elseif_list_test               
		{  
			$<ast>$=ast->createNode(
						ast->createNode($<ast>2,$<ast>3,ifConditionAndBodyNode),
						ast->createNode($<ast>4,0,elseNode),
						ifNode);
			debuggerYACC(" X397 - statement << | T_IF parentheses_expr statement elseif_list %prec    elseif_list_test"); 
		}

    | T_WHILE parentheses_expr while_statement                          { $<ast>$=ast->createNode($<ast>2,$<ast>3,whileNode);     debuggerYACC(" X401 - statement << | T_WHILE parentheses_expr while_statement"); }
    | T_DO statement T_WHILE parentheses_expr ';'                       { $<ast>$=ast->createNode($<ast>2,$<ast>4,doWhileNode);    debuggerYACC(" X402 - statement << | T_DO statement T_WHILE parentheses_expr ';'"); }
    | T_FOR { startNewScope(); } '(' for_expr ';'  for_expr ';' for_expr ')' for_statement 
		{
			$<ast>$=
				ast->createNode
				(
					ast->createNode
					(
						ast->createNode($<ast>4,$<ast>6,forHeaderNode),
						ast->createNode($<ast>10,$<ast>8,forBodyNode),
						forNode
					)
				,0,scopeNode)->addScopeSize(closeScope());

		    debuggerYACC(" X403 - statement << | T_FOR '(' for_expr ';'  for_expr ';' for_expr ')' for_statement"); 
		}
          
    | T_SWITCH parentheses_expr switch_case_list           { $<ast>$ = ast->createNode($<ast>2, $<ast>3,switchNode);  debuggerYACC(" X405 - statement << | T_SWITCH parentheses_expr switch_case_list"); }
    | T_BREAK ';'                                          { $<ast>$ = ast->createNode(0, 0,breakNode);                                                         debuggerYACC(" X406 - statement << | T_BREAK ';'"); }
    | T_BREAK expr ';'                                     { $<ast>$ = ast->createNode($<ast>2,0,breakNode);                               debuggerYACC(" X407 - statement << | T_BREAK expr ';'"); }
    | T_CONTINUE ';'                                       { $<ast>$ = ast->createNode(0,0,continueNode);     debuggerYACC(" X408 - statement << | T_CONTINUE ';'"); }
    | T_CONTINUE expr ';'                                  { $<ast>$ = ast->createNode($<ast>2,0,continueNode);       debuggerYACC(" X409 - statement << | T_CONTINUE expr ';'"); }
    | T_RETURN ';'                                         { $<ast>$ = ast->createNode(0,0,returnNode);                                                          debuggerYACC(" X410 - statement << | T_RETURN ';'"); }
    | T_RETURN expr ';'                                    { $<ast>$ = ast->createNode($<ast>2,0,returnNode);  debuggerYACC(" X411 - statement << | T_RETURN expr ';'"); }
    | T_STATIC static_var_list ';'   {  $<ast>$ = $<ast>2;  debuggerYACC(" X414 - statement << | T_STATIC static_var_list ';'"); }
    | T_ECHO expr_list ';'               { $<ast>$ = ast->createNode($<ast>2,0,echoNode);     debuggerYACC(" X415 - statement << | T_ECHO expr_list ';'"); }
    | expr ';'                           { $<ast>$ = $<ast>1; debuggerYACC(" X417 - statement << | expr ';'"); }
    | T_FOREACH '(' expr T_AS variable ')' foreach_statement { $<ast>$ = ast->createNode(ast->createNode($<ast>3,$<ast>5,asNode),$<ast>7,foreachNode); debuggerYACC(" X419 - statement << | T_FOREACH '('expr T_AS foreach_variable ')'foreach_statement"); }
          
    | ';'                                                             { $<ast>$ = ast->createNode(0,0,emptyNode); debuggerYACC(" X424 - statement << | ';'"); }
    | T_TRY scope catches optional_finally     { $<ast>$ = ast->createNode($<ast>2,$<ast>3,tryNode);  debuggerYACC(" X425 - statement << | T_TRY '{' inner_statement_list '}' catches optional_finally"); }
          
    | T_THROW expr ';'                                                                                  {  debuggerYACC(" X427 - statement << | T_THROW expr ';'"); }
    | T_GOTO T_STRING ';'                                                                               {  debuggerYACC(" X428 - statement << | T_GOTO T_STRING ';'"); }
    | T_STRING ':'                                                                                      {  debuggerYACC(" X429 - statement << | T_STRING ':'"); }
	| T_SUPER argument_list ';'							            {    $<ast>$=ast->createNode(0,$<ast>2,functionCallNode); $<ast>$->addSymbolTableElement(SuperKeywordShowedUp()); }
	| T_CONST var_type_or_name T_VARIABLE '=' static_scalar ';'     { $<ast>$ = ast->createNode($<ast>2,0,idVariableNode); $<ast>$->addSymbolTableElement(addVariable($<r.str>2,$<r.str>3,$<r.str>5,true));  debuggerYACC(" X369 -  << T_STRING '=' static_scalar"); }
	| error																								{ EatUntilNewLine(); $<ast>$=NULL;  debuggerYACC(" X430 - statement << | error"); }
;

catches:
      /* empty */     { $<ast>$ = NULL;    debuggerYACC(" X438 - catches << /* empty */"); }
    | catches catch   { $<ast>$ = ast->addToLastRight($<ast>1,$<ast>2);    debuggerYACC(" X439 - catches << | catches catch"); }
;

catch:
    T_CATCH '(' T_STRING T_VARIABLE ')' scope    { $<ast>$ = ast->createNode($<ast>5,0,tryNode);    debuggerYACC(" X443 - catch << T_CATCH '('name T_VARIABLE ')''{' inner_statement_list '}'"); }
;

optional_finally:
      /* empty */                                                                                               {  debuggerYACC(" X447 - optional_finally << /* empty */"); }
    | T_FINALLY scope                                                                    {  debuggerYACC(" X448 - optional_finally << | T_FINALLY '{' inner_statement_list '}'"); }
;

optional_ref:
      /* empty */ { Optional_ref = false;  debuggerYACC(" X457 - optional_ref << /* empty */"); }
    | '&'         { Optional_ref = true;  debuggerYACC(" X458 - optional_ref << | '&'"); }
;

optional_ellipsis:
      /* empty */                                                                                               {  debuggerYACC(" X462 - optional_ellipsis << /* empty */"); }
    | T_ELLIPSIS                                                                                                {  debuggerYACC(" X463 - optional_ellipsis << | T_ELLIPSIS"); }
;

function_declaration_statement:
	T_FUNCTION optional_ref T_STRING '(' parameter_list ')' optional_return_type { FunctionDeclaration($<r.str>3,false); resetStatementNumber(); } scope { $<ast>$ = ast->createNode($<ast>5,$<ast>9,functionNode); $<ast>$->addSymbolTableElement(FunctionDeclarationEnd());                debuggerYACC(" X467 - function_declaration_statement << T_FUNCTION optional_ref T_STRING '('parameter_list ')' optional_return_type '{' inner_statement_list '}' "); }
;

class_declaration_statement:
      class_entry_type T_STRING { ClassDeclaration($<r.str>2); } extends_from implements_list '{' class_statement_list '}' { $<ast>$ = ast->createNode($<ast>7,0,classNode); $<ast>$->addSymbolTableElement(ClassDeclarationEnd()); debuggerYACC(" X472 - class_declaration_statement << class_entry_type T_STRING extends_from implements_list '{' class_statement_list '}'"); }
	| T_INTERFACE T_STRING interface_extends_list '{' class_statement_list '}'                                  {  debuggerYACC(" X474 - class_declaration_statement << | T_INTERFACE T_STRING interface_extends_list '{' class_statement_list '}'"); }
;


class_entry_type:
      T_CLASS                                                   {												debuggerYACC(" X480 - class_entry_type << T_CLASS"); }
    | T_ABSTRACT T_CLASS                                        { isClassAbstract = true;						debuggerYACC(" X481 - class_entry_type << | T_ABSTRACT T_CLASS"); }
    | T_FINAL T_CLASS                                           { isClassFinal = true;							debuggerYACC(" X482 - class_entry_type << | T_FINAL T_CLASS"); }
	
	| T_STATIC T_CLASS                                          { isClassStatic = true;							debuggerYACC(" X482 - class_entry_type << | T_FINAL T_CLASS"); }
    | T_STATIC T_ABSTRACT T_CLASS                               { isClassStatic = true; isClassAbstract = true; debuggerYACC(" X481 - class_entry_type << | T_ABSTRACT T_CLASS"); }
	| T_STATIC T_FINAL T_CLASS                                  { isClassStatic = true; isClassFinal = true;	debuggerYACC(" X482 - class_entry_type << | T_FINAL T_CLASS"); }
;

extends_from:
      /* empty */                                                                                               {  debuggerYACC(" X486 - extends_from << /* empty */"); }
    | T_EXTENDS T_STRING { ClassDeclarationAddInheritedClass($<r.str>2);      debuggerYACC(" X487 - extends_from << | T_EXTENDS name"); }
;

interface_extends_list:
      /* empty */                                                                                               {  debuggerYACC(" X491 - interface_extends_list << /* empty */"); }
    | T_EXTENDS name_list                                                                                       {  debuggerYACC(" X492 - interface_extends_list << | T_EXTENDS name_list"); }
;

implements_list:
      /* empty */                                                                                               {  debuggerYACC(" X496 - implements_list << /* empty */"); }
    | T_IMPLEMENTS name_list                                                                                    {  debuggerYACC(" X497 - implements_list << | T_IMPLEMENTS name_list"); }
;

name_list:
      T_STRING { ClassDeclarationAddImplementInterface($<r.str>1);   debuggerYACC(" X501 - name_list << name"); }
    | name_list ',' T_STRING {ClassDeclarationAddImplementInterface($<r.str>3);   debuggerYACC(" X502 - name_list << | name_list ',' name"); }
;

for_statement:
      statement                            { $<ast>$ = $<ast>1;   debuggerYACC(" X506 - for_statement << statement"); }
    | ':' inner_statement_list T_ENDFOR ';'     {  debuggerYACC(" X507 - for_statement << | ':' inner_statement_list T_ENDFOR ';'"); }
;

foreach_statement:
      statement                       { $<ast>$ = $<ast>1;     debuggerYACC(" X511 - foreach_statement << statement"); }
    | ':' inner_statement_list T_ENDFOREACH ';'                                                           {  debuggerYACC(" X512 - foreach_statement << | ':' inner_statement_list T_ENDFOREACH ';'"); }
;

switch_case_list:
      '{' case_list '}'                    {  $<ast>$ = $<ast>2;                                       debuggerYACC(" X530 - switch_case_list << '{' case_list '}'"); }
    | '{' ';' case_list '}'                {  $<ast>$ = $<ast>3;                                       debuggerYACC(" X531 - switch_case_list << | '{' ';' case_list '}'"); }
;

case_list:
      /* empty */                   {            $<ast>$ = ast->createNode(0,0,listcaseNode);                                           debuggerYACC(" X537 - case_list << /* empty */"); }
    | case case_list                 {           $<ast>$ = ast->addToLastRight($<ast>1,$<ast>2);                                                                     debuggerYACC(" X538 - case_list << | case_list case"); }
;

case:
      T_CASE expr ':' inner_statement_list   { $<ast>$ = ast->createNode($<ast>2,$<ast>4,caseNode); $<ast>$ = ast->createNode($<ast>$,0,listcaseNode); debuggerYACC(" X542 - case << T_CASE expr case_separator inner_statement_list"); }
    | T_DEFAULT ':' inner_statement_list     { $<ast>$ = ast->createNode(0,$<ast>3,defaultNode);   $<ast>$ = ast->createNode($<ast>$,0,listcaseNode);  debuggerYACC(" X543 - case << | T_DEFAULT case_separator inner_statement_list"); }
;


while_statement:
      statement                                           { $<ast>$ = $<ast>1;     debuggerYACC(" X552 - while_statement << statement"); }
    | ':' inner_statement_list T_ENDWHILE ';'                                                             {  debuggerYACC(" X553 - while_statement << | ':' inner_statement_list T_ENDWHILE ';'"); }
;

elseif_list:
      /* empty */        %prec    elseif_list_test         {  $<ast>$ = ast->createNode(0,0,elseNode); debuggerYACC(" X557 - elseif_list << /* empty */"); }
    | elseif_list elseif								   {  $<ast>$ = ast->addToLastRight($<ast>1,$<ast>2);  debuggerYACC(" X558 - elseif_list << | elseif_list elseif"); }
;

elseif:
      T_ELSEIF parentheses_expr statement             
				{ 
						$<ast>$ = ast->createNode(
												  ast->createNode($<ast>2,$<ast>3,elseifConditionAndBodyNode),
												  0,elseNode);
						
						debuggerYACC(" X563 - elseif << T_ELSEIF parentheses_expr statement"); 
				}
;

parameter_list:
      non_empty_parameter_list ',' non_empty_optional_parameter_list            { $<ast>$ = ast->addToLastRight($<ast>1,$<ast>3); debuggerYACC(" X589 - parameter_list << non_empty_parameter_list ',' non_empty_optional_parameter_list"); }
      | non_empty_parameter_list                                                { $<ast>$ = $<ast>1;  debuggerYACC(" X590 - parameter_list << | non_empty_parameter_list"); }
      | non_empty_optional_parameter_list                                       { $<ast>$ = $<ast>1; debuggerYACC(" X591 - parameter_list << | non_empty_optional_parameter_list"); }
      |                                                                         { $<ast>$ = NULL; debuggerYACC(" X592 - parameter_list << |"); }
;

non_empty_parameter_list:
      parameter                                { $<ast>$ = $<ast>1;  debuggerYACC(" X596 - non_empty_parameter_list << parameter"); }
    | non_empty_parameter_list ',' parameter   { $<ast>$ = ast->addToLastRight($<ast>1,$<ast>3); debuggerYACC(" X597 - non_empty_parameter_list << | non_empty_parameter_list ',' parameter"); }
;

non_empty_optional_parameter_list:
      optional_parameter                                          { $<ast>$ = $<ast>1;  debuggerYACC(" X601 - non_empty_optional_parameter_list << optional_parameter"); }
    | non_empty_optional_parameter_list ',' optional_parameter    { $<ast>$ = ast->addToLastRight($<ast>1,$<ast>3);  debuggerYACC(" X602 - non_empty_optional_parameter_list << | non_empty_optional_parameter_list ',' optional_parameter"); }
	| non_empty_optional_parameter_list ',' parameter			  { $<ast>$ = ast->addToLastRight($<ast>1,$<ast>3);  errorhandler("optional parameter not at end of parameter list"); }
;

parameter:
      var_type_or_name optional_ref optional_ellipsis T_VARIABLE  { $<ast>$ = ast->createNode($<ast>1,0,paramNode); $<ast>$->addSymbolTableElement(addParametertoFunction($<r.str>1,$<r.str>4,NULL));  debuggerYACC(" X606 - parameter << optional_param_type optional_ref optional_ellipsis var_type_or_nameT_VARIABLE"); }
;

optional_parameter:
       var_type_or_name optional_ref optional_ellipsis T_VARIABLE '=' static_scalar { $<ast>$ = ast->createNode($<ast>1,0,paramNode); $<ast>$->addSymbolTableElement(addParametertoFunction($<r.str>1,$<r.str>4,$<r.str>6,$<ast>6));   debuggerYACC(" X610 - optional_parameter << optional_param_type optional_ref optional_ellipsis var_type_or_nameT_VARIABLE '=' static_scalar"); }
;

optional_return_type:
      ':' "void"            { returnType = "void"; }
    |  /* empty */          { returnType = "$";      debuggerYACC(" X626 - optional_return_type << /* empty */"); }
    | ':' var_type_or_name  { returnType = $<r.str>2; $<ast>$=ast->createNode($<ast>2,0,returnTypeNode);  debuggerYACC(" X628 - optional_return_type << | ':' var_type_or_name"); }
;

argument_list:
      '(' ')'                                     { $<ast>$= NULL; debuggerYACC(" X632 - argument_list << '('')'"); }
    | '(' non_empty_argument_list ')'             { $<ast>$= $<ast>2;  debuggerYACC(" X633 - argument_list << | '('non_empty_argument_list ')'"); }
;

non_empty_argument_list:
       non_empty_argument_list ',' argument        { $<ast>$ = ast->addToLastRight($<ast>1,$<ast>3); debuggerYACC(" X639 - non_empty_argument_list << | non_empty_argument_list ',' argument"); }
     | argument                                    { $<ast>$ = $<ast>1;     debuggerYACC(" X638 - non_empty_argument_list << argument"); }
;

argument:
      expr                                        { $<ast>$ = ast->createNode($<ast>1,0,argumentNode);      debuggerYACC(" X643 - argument << expr"); }
    | '&' variable                                { $<ast>$ = ast->createNode($<ast>2,0,argumentReferencNode);      debuggerYACC(" X644 - argument << | '&' variable"); }
    | T_ELLIPSIS expr                             { $<ast>$ = NULL;/*????*/      debuggerYACC(" X645 - argument << | T_ELLIPSIS expr"); }
;


static_var_list:
      static_var_list ',' static_var                             {  $<ast>$=ast->addToLastRight($<ast>1,$<ast>3); debuggerYACC(" X660 - static_var_list << static_var_list ',' static_var"); }
    | static_var                                                 {  $<ast>$=$<ast>1; debuggerYACC(" X661 - static_var_list << | static_var"); }
;

static_var:
     var_type_or_name T_VARIABLE                     { $<ast>$ = ast->createNode($<ast>1,0,staticVariableNode); $<ast>$->addSymbolTableElement(addStaticVariable($<r.str>1,$<r.str>2,0));                   debuggerYACC(" X665 - static_var << var_type_or_nameT_VARIABLE"); }
    | var_type_or_name T_VARIABLE '=' static_scalar  { $<ast>$ = ast->createNode($<ast>1,0,staticVariableNode); $<ast>$->addSymbolTableElement(addStaticVariable($<r.str>1,$<r.str>2,$<r.str>4));          debuggerYACC(" X666 - static_var << | var_type_or_nameT_VARIABLE '=' static_scalar"); }
;

class_statement_list:
      class_statement_list class_statement				  { $<ast>$ = ast->addToLastRight($<ast>1,$<ast>2);		  debuggerYACC(" X670 - class_statement_list << class_statement_list class_statement"); }
    | /* empty */										  { $<ast>$ = ast->createNode(0,0,classListNode);    debuggerYACC(" X671 - class_statement_list << | /* empty */"); }
;

class_statement:
      modifiers { addDataMemeberStart(); } property_declaration_list ';'    { addDataMemeberEnd(); $<ast>$ = ast->createNode($<ast>3,0,classListNode);  debuggerYACC(" X675 - class_statement << modifiers property_declaration_list ';'"); }
    | modifiers T_FUNCTION optional_ref T_STRING '(' parameter_list ')' optional_return_type { FunctionDeclaration($<r.str>4,true);  resetStatementNumber(); } method_body 
		{
		    $<ast>$ = ast->createNode($<ast>6,$<ast>10,functionNode);
		    $<ast>$->addSymbolTableElement(FunctionDeclarationEnd(true));
			
			$<ast>$ = ast->createNode($<ast>$,0,classListNode);

		    debuggerYACC(" X677 - class_statement << | modifiers T_FUNCTION optional_ref T_STRING '('parameter_list ')' optional_return_type method_body"); 
		}
	| class_declaration_statement				                   { $<ast>$ = ast->createNode($<ast>1,0,classListNode);  debuggerYACC(" X679.5 - class_statement << | class_declaration_statement"); }
	
	| error                  {EatUntilNewLine();  $<ast>$ = ast->createNode(0,0,classListNode);    debuggerYACC(" X430 - class_statement << | error"); }
;

method_body:
      ';' /* abstract method */				{ checkAbstractFunction(false); $<ast>$ = ast->createNode(0,0,functionBody);   debuggerYACC(" X718 - method_body << ';' /* abstract method */"); }
    | scope          { checkAbstractFunction(true);  $<ast>$ = ast->createNode($<ast>1,0,functionBody);  debuggerYACC(" X719 - method_body << | '{' inner_statement_list '}'"); }
;

modifiers:
      member_access_modifier member_storage_modifier                                                            {  debuggerYACC(" X723 - modifiers << member_access_modifier member_storage_modifier"); }
     | member_storage_modifier member_access_modifier                                                           {  debuggerYACC(" X724 - modifiers << | member_storage_modifier member_access_modifier"); }
     | member_storage_modifier                                                                                  {  debuggerYACC(" X725 - modifiers << | member_storage_modifier"); }
     | member_access_modifier                                                                                   {  debuggerYACC(" X726 - modifiers << |  member_access_modifier"); }
     |                                                                                                          {  debuggerYACC(" X727 - modifiers << |"); }
;

member_access_modifier:
      T_PUBLIC    { MemberAccessPublic();        debuggerYACC(" X731 - member_access_modifier << T_PUBLIC"); }
    | T_PROTECTED { MemberAccessProtacted();     debuggerYACC(" X732 - member_access_modifier << | T_PROTECTED"); }
    | T_PRIVATE   { MemberAccessPrivate();       debuggerYACC(" X733 - member_access_modifier << | T_PRIVATE"); }
;

member_storage_modifier:
      T_STATIC       { MemberStorageStatic();     debuggerYACC(" X738 - member_storage_modifier << T_STATIC"); }
    | T_ABSTRACT     { MemberStorageAbstract();   debuggerYACC(" X739 - member_storage_modifier << | T_ABSTRACT"); }
    | T_FINAL        { MemberStorageFinal();       debuggerYACC(" X740 - member_storage_modifier << | T_FINAL"); }
;

property_declaration_list:
      property_declaration                                       {  $<ast>$ = ast->createNode($<ast>1,0,classListNode);  debuggerYACC(" X745 - property_declaration_list << property_declaration"); }
    | property_declaration_list ',' property_declaration         {  $<ast>$ = ast->addToLastRight($<ast>1,ast->createNode($<ast>3,0,classListNode));  debuggerYACC(" X746 - property_declaration_list << | property_declaration_list ',' property_declaration"); }
;

property_declaration:
      var_type_or_name T_VARIABLE  { $<ast>$ = ast->createNode($<ast>1,0,idVariableNode); $<ast>$->addSymbolTableElement(addVariable($<r.str>1,$<r.str>2,false)); debuggerYACC(" X750 - property_declaration << var_type_or_nameT_VARIABLE"); }
    | var_type_or_name T_VARIABLE '=' static_scalar { 
														Variable* v = addVariable($<r.str>1,$<r.str>2,$<r.str>4,false);
														$<ast>$ = ast->createNode($<ast>1,$<ast>4,v->isStatic?staticVariableNode:idVariableNode); 
														$<ast>$->addSymbolTableElement(v);
	 
														debuggerYACC(" X751 - property_declaration << | var_type_or_nameT_VARIABLE '=' static_scalar"); 
													}
	| T_CONST var_type_or_name T_VARIABLE '=' static_scalar      { $<ast>$ = ast->createNode($<ast>2,0,idVariableNode); $<ast>$->addSymbolTableElement(addVariable($<r.str>2,$<r.str>3,$<r.str>5,true));   debuggerYACC(" X369 - constant_declaration << T_STRING '=' static_scalar"); }
;


var_type_or_name:
	  var_types optional_array  %prec lowpriority                   { $<ast>$ = ast->createNode(0,0,classTypeNameNode); $<ast>$->addSymbolTableElement(NULL); $<r.str>$ = $<r.str>1; debuggerYACC(" X7512 - var_type_or_name << var_types optional_array");}
	| T_STRING  optional_array   %prec lowpriority	                { $<ast>$ = ast->createNode(0,0,classTypeNameNode); $<ast>$->addSymbolTableElement(findClassName($<r.str>1)); $<r.str>$ = $<r.str>1;  debuggerYACC(" X7513 - var_type_or_name << T_STRING");}
	| T_STRING T_PAAMAYIM_NEKUDOTAYIM T_STRING optional_array       { $<ast>$ = ast->createNode(0,0,classTypeNameNode); $<ast>$->addSymbolTableElement(findStaticClassName($<r.str>1,$<r.str>3,false)); $<r.str>$ = $<r.str>3; debuggerYACC(" XXXXXXXXXXXXXXXXXXXXXXXXX ");}
;



optional_array:
      /* empty */			{   itsArrayVariable(false);    debuggerYACC(" X7514 - optional_array");}
    | '[' ']'				{   itsArrayVariable(true);    debuggerYACC(" X7515 - optional_array");}
;

var_types:
      T_V_INT             { $<ast>$ = ast->createNode(0,0,intTypeNode); debuggerYACC(" X759 - var_types << T_V_INT"); }
    | T_V_STRING          { $<ast>$ = ast->createNode(0,0,stringTypeNode); debuggerYACC(" X760 - var_types << | T_V_STRING"); }
    | T_V_BOOL            { $<ast>$ = ast->createNode(0,0,boolTypeNode); debuggerYACC(" X761 - var_types << | T_V_BOOL"); }
    | T_V_CHAR            { $<ast>$ = ast->createNode(0,0,charTypeNode); debuggerYACC(" X762 - var_types << | T_V_CHAR"); }
    | T_V_DOUBLE          { $<ast>$ = ast->createNode(0,0,doubleTypeNode); debuggerYACC(" X763 - var_types << | T_V_DOUBLE"); }
    | T_V_FLOAT           { $<ast>$ = ast->createNode(0,0,floatTypeNode); debuggerYACC(" X764 - var_types << | T_V_FLOAT"); }
    | T_V_REAL            { $<ast>$ = ast->createNode(0,0,realTypeNode); debuggerYACC(" X765 - var_types << | T_V_REAL"); }
    | T_V_LONG            { $<ast>$ = ast->createNode(0,0,longTypeNode); debuggerYACC(" X766 - var_types << | T_V_LONG"); }
    | T_V_BYTE            { $<ast>$ = ast->createNode(0,0,byteTypeNode); debuggerYACC(" X767 - var_types << | T_V_BYTE"); }
    | T_V_UINT            { $<ast>$ = ast->createNode(0,0,uintTypeNode); debuggerYACC(" X768 - var_types << | T_V_UINT"); }
    | T_V_ULONG           { $<ast>$ = ast->createNode(0,0,ulongTypeNode);  debuggerYACC(" X769 - var_types << | T_V_ULONG"); }
    | T_V_UBYTE           { $<ast>$ = ast->createNode(0,0,ubyteTypeNode); debuggerYACC(" X770 - var_types << | T_V_UBYTE"); }
;

expr_list:
      expr_list ',' expr     {  $<ast>$ = ast->addToLastRight($<ast>1,ast->createNode($<ast>3,0,expressionNode)); debuggerYACC(" X774 - expr_list << expr_list ',' expr"); }
    | expr                   {   $<ast>$ = ast->createNode($<ast>1,0,expressionNode); debuggerYACC(" X775 - expr_list << | expr"); }
;

for_expr:
      /* empty */                                 { $<ast>$ = NULL;  debuggerYACC(" X779 - for_expr << /* empty */"); }
    | expr_list                                   { $<ast>$ = $<ast>1;  debuggerYACC(" X780 - for_expr << | expr_list"); }
;

expr:
      variable                        { $<ast>$ = $<ast>1;														   debuggerYACC(" X784 - expr << variable"); }
    | variable '=' expr				  { $<ast>$ = ast->createNode($<ast>1,$<ast>3,assignNode);                     debuggerYACC(" X786 - expr << | variable '=' expr"); }
    | new_expr      %prec _def_val_                                                                             {  debuggerYACC(" X789 - expr << | new_expr      %prec _def_val_"); }
	| '=' T_VARIABLE T_OBJECT_OPERATOR T_STRING argument_list           {}
    | T_CLONE expr                                                                                              {  debuggerYACC(" X790 - expr << | T_CLONE expr"); }
    | variable T_PLUS_EQUAL expr        {  $<ast>$ = ast->createNode($<ast>1,ast->createNode($<ast>3,$<ast>1,plusNode),assignNode);  debuggerYACC(" X791 - expr << | variable T_PLUS_EQUAL expr"); }
    | variable T_MINUS_EQUAL expr       {  $<ast>$ = ast->createNode($<ast>1,ast->createNode($<ast>1,$<ast>3,minusNode),assignNode);  debuggerYACC(" X792 - expr << | variable T_MINUS_EQUAL expr"); }
    | variable T_MUL_EQUAL expr         {  $<ast>$ = ast->createNode($<ast>1,ast->createNode($<ast>3,$<ast>1,multNode),assignNode);  debuggerYACC(" X793 - expr << | variable T_MUL_EQUAL expr"); }
    | variable T_DIV_EQUAL expr         {  $<ast>$ = ast->createNode($<ast>1,ast->createNode($<ast>1,$<ast>3,divNode),assignNode);  debuggerYACC(" X794 - expr << | variable T_DIV_EQUAL expr"); }
    | variable T_CONCAT_EQUAL expr																				{   debuggerYACC(" X795 - expr << | variable T_CONCAT_EQUAL expr"); }
    | variable T_MOD_EQUAL expr         {  $<ast>$ = ast->createNode($<ast>1,ast->createNode($<ast>3,$<ast>1,modNode),assignNode);  debuggerYACC(" X796 - expr << | variable T_MOD_EQUAL expr"); }
    | variable T_AND_EQUAL expr                                                                                 {  debuggerYACC(" X797 - expr << | variable T_AND_EQUAL expr"); }
    | variable T_OR_EQUAL expr                                                                                  {  debuggerYACC(" X798 - expr << | variable T_OR_EQUAL expr"); }
    | variable T_XOR_EQUAL expr                                                                                 {  debuggerYACC(" X799 - expr << | variable T_XOR_EQUAL expr"); }
    | variable T_SR_EQUAL expr                                                                                  {  debuggerYACC(" X800 - expr << | variable T_SR_EQUAL expr"); }
    | variable T_POW_EQUAL expr                                                                                 {  debuggerYACC(" X801 - expr << | variable T_POW_EQUAL expr"); }
    | variable T_INC                           {      $<ast>$ = ast->createNode($<ast>1,0,plusplusNode);                       debuggerYACC(" X802 - expr << | variable T_INC"); }
    | T_INC variable                           {      $<ast>$ = ast->createNode(0,$<ast>2,plusplusNode);                       debuggerYACC(" X803 - expr << | T_INC variable"); }
    | variable T_DEC                           {      $<ast>$ = ast->createNode($<ast>1,0,minusminusNode);               debuggerYACC(" X804 - expr << | variable T_DEC"); }
    | T_DEC variable                           {      $<ast>$ = ast->createNode(0,$<ast>2,minusminusNode);               debuggerYACC(" X805 - expr << | T_DEC variable"); }
    | expr T_BOOLEAN_OR expr     {   $<ast>$ = ast->createNode($<ast>1,$<ast>3,booleanOrOrNode);					   debuggerYACC(" X806 - expr << | expr T_BOOLEAN_OR expr"); }
    | expr T_BOOLEAN_AND expr    {   $<ast>$ = ast->createNode($<ast>1,$<ast>3,booleanAndAndNode);					   debuggerYACC(" X807 - expr << | expr T_BOOLEAN_AND expr"); }
    | expr T_LOGICAL_OR expr                                                                                    {  debuggerYACC(" X808 - expr << | expr T_LOGICAL_OR expr"); }
    | expr T_LOGICAL_AND expr                                                                                   {  debuggerYACC(" X809 - expr << | expr T_LOGICAL_AND expr"); }
    | expr T_LOGICAL_XOR expr                                                                                   {  debuggerYACC(" X810 - expr << | expr T_LOGICAL_XOR expr"); }
    | expr '|' expr              { $<ast>$ = ast->createNode($<ast>1,$<ast>3,booleanOrNode);  debuggerYACC(" X811 - expr << | expr '|' expr"); }
    | expr '&' expr              { $<ast>$ = ast->createNode($<ast>1,$<ast>3,booleanAndNode);  debuggerYACC(" X812 - expr << | expr '&' expr"); }
    | expr '^' expr                                                                                             {  debuggerYACC(" X813 - expr << | expr '^' expr"); }
    | expr '.' expr                                                                                             {  debuggerYACC(" X814 - expr << | expr '.' expr"); }
    | expr '+' expr               {   $<ast>$ = ast->createNode($<ast>1,$<ast>3,plusNode);                         debuggerYACC(" X815 - expr << | expr '+' expr"); }
    | expr '-' expr               {   $<ast>$ = ast->createNode($<ast>1,$<ast>3,minusNode);						   debuggerYACC(" X816 - expr << | expr '-' expr"); }
    | expr '*' expr               {   $<ast>$ = ast->createNode($<ast>1,$<ast>3,multNode);	                       debuggerYACC(" X817 - expr << | expr '*' expr"); }
    | expr '/' expr               {   $<ast>$ = ast->createNode($<ast>1,$<ast>3,divNode);                          debuggerYACC(" X818 - expr << | expr '/' expr"); }
    | expr '%' expr               {   $<ast>$ = ast->createNode($<ast>1,$<ast>3,modNode);                          debuggerYACC(" X819 - expr << | expr '%' expr"); }
    | expr T_SL expr                                                                                            {  debuggerYACC(" X820 - expr << | expr T_SL expr"); }
    | expr T_SR expr                                                                                            {  debuggerYACC(" X821 - expr << | expr T_SR expr"); }
    | expr T_POW expr                                                                                           {  debuggerYACC(" X822 - expr << | expr T_POW expr"); }
    | '+' expr %prec T_INC       {  $<ast>$ = $<ast>2; debuggerYACC(" X823 - expr << | '+' expr %prec T_INC"); }
    | '-' expr %prec T_INC       {  $<ast>$ = ast->createNode($<ast>2,0,uneryPreMinusNode);             debuggerYACC(" X824 - expr << | '-' expr %prec T_INC"); }
    | '!' expr                   {	$<ast>$ = ast->createNode($<ast>2,0,NotBooleanNode);																		debuggerYACC(" X825 - expr << | '!' expr"); }
    | '~' expr                                                                                                  {  debuggerYACC(" X826 - expr << | '~' expr"); }
    | expr T_IS_EQUAL expr             {   $<ast>$ = ast->createNode($<ast>1,$<ast>3,IsEqualNode);                                                                            debuggerYACC(" X829 - expr << | expr T_IS_EQUAL expr"); }
    | expr T_IS_NOT_EQUAL expr         {   $<ast>$ = ast->createNode($<ast>1,$<ast>3,IsNotEqualNode);                                                                           debuggerYACC(" X830 - expr << | expr T_IS_NOT_EQUAL expr"); }
    | expr '<' expr                    {   $<ast>$ = ast->createNode($<ast>1,$<ast>3,lessThanNode);                debuggerYACC(" X832 - expr << | expr '<' expr"); }
    | expr T_IS_SMALLER_OR_EQUAL expr  {   $<ast>$ = ast->createNode($<ast>1,$<ast>3,lessOrEqualNode);             debuggerYACC(" X833 - expr << | expr T_IS_SMALLER_OR_EQUAL expr"); }
    | expr '>' expr                    {   $<ast>$ = ast->createNode($<ast>1,$<ast>3,moreThanNode);                debuggerYACC(" X834 - expr << | expr '>' expr"); }
    | expr T_IS_GREATER_OR_EQUAL expr  {   $<ast>$ = ast->createNode($<ast>1,$<ast>3,moreOrEqualNode);             debuggerYACC(" X835 - expr << | expr T_IS_GREATER_OR_EQUAL expr"); }
    | parentheses_expr                 {   $<ast>$ =  $<ast>1;													   debuggerYACC(" X837 - expr << | parentheses_expr"); }
    | '(' new_expr ')'                  {   $<ast>$ =  $<ast>2;                                                    debuggerYACC(" X838 - expr << | '('new_expr ')' "); }
    | expr '?' expr ':' expr                                                                                    {  debuggerYACC(" X839 - expr << | expr '?' expr ':' expr"); }
    | expr '?' ':' expr                                                                                         {  debuggerYACC(" X840 - expr << | expr '?' ':' expr"); }
    | expr T_COALESCE expr                                                                                      {  debuggerYACC(" X841 - expr << | expr T_COALESCE expr"); }
	| T_INT_CAST expr                        { $<ast>$=ast->createNode($<ast>2,0,intCastNode);                                    debuggerYACC(" X849 - expr << | T_INT_CAST expr"); }
    | T_DOUBLE_CAST expr                     { $<ast>$=ast->createNode($<ast>2,0,doubleCastNode);                                    debuggerYACC(" X850 - expr << | T_DOUBLE_CAST expr"); }
    | T_STRING_CAST expr                     { $<ast>$=ast->createNode($<ast>2,0,stringCastNode);                                    debuggerYACC(" X851 - expr << | T_STRING_CAST expr"); }
    | T_BOOL_CAST expr                       { $<ast>$=ast->createNode($<ast>2,0,boolCastNode);                                    debuggerYACC(" X854 - expr << | T_BOOL_CAST expr"); }
	| '(' T_STRING ')' expr                  { $<ast>$=ast->createNode($<ast>4,0,classTypeCastNode);    $<ast>$->addSymbolTableElement(findClassName($<r.str>2));                                debuggerYACC(" X854 - expr << | '(' T_STRING ')' expr"); }
	| '(' T_STRING '['']' ')' expr                  { $<ast>$=ast->createNode($<ast>4,0,classTypeCastArrayNode);    $<ast>$->addSymbolTableElement(findClassName($<r.str>2));                                debuggerYACC(" X854 - expr << | '(' T_STRING ')' expr"); }

    | scalar				{ $<ast>$ = $<ast>1;																   debuggerYACC(" X858 - expr << | scalar"); }

	| T_READ_INT           {    $<ast>$=ast->createNode(0,0,readIntNode);         }
	| T_READ_STRING        {    $<ast>$=ast->createNode(0,0,readStringNode);      }
	| T_READ_DOUBLE        {    $<ast>$=ast->createNode(0,0,readDoubleNode);      }
;

parentheses_expr:
      '(' expr ')'                             { $<ast>$ = $<ast>2; debuggerYACC(" X872 - parentheses_expr << '('expr ')'"); }
;

dim_offset:
      /* empty */                          { $<ast>$ = NULL;  debuggerYACC(" X1142 - dim_offset << /* empty */"); }
    | expr                                 { $<ast>$ = $<ast>1; debuggerYACC(" X1143 - dim_offset << | expr"); }
;


new_expr:
      T_NEW T_STRING argument_list                                       {  $<ast>$ = ast->createNode($<ast>3,0,newClassInstance); $<ast>$->addSymbolTableElement(findClassName($<r.str>2,true));                  debuggerYACC(" X898 - new_expr << T_NEW namespace_name_parts ctor_arguments"); }
	| T_NEW T_STRING T_PAAMAYIM_NEKUDOTAYIM T_STRING argument_list       {  $<ast>$ = ast->createNode($<ast>5,0,newClassInstance); $<ast>$->addSymbolTableElement(findStaticClassName($<r.str>2,$<r.str>4,true));  debuggerYACC(" X898 - new_expr << T_NEW namespace_name_parts ctor_arguments"); }
	| T_VARIABLE T_DOUBLE_ARROW T_NEW T_STRING argument_list                        {  $<ast>$ = ast->createNode($<ast>5,0,newClassInstance); $<ast>$->addSymbolTableElement(findInstanceClassName($<r.str>1,$<r.str>4));  debuggerYACC(" X898 - new_expr << T_NEW namespace_name_parts ctor_arguments"); }

	|T_NEW array_type '[' expr ']'						      { $<ast>$ = ast->createNode($<ast>2,ast->createNode($<ast>4,0      ,arrayInitializingNode),arrayNode)->addValuestring($<r.str>2);					debuggerYACC(" X882 - array_expr <<  var_types '[' T_LNUMBER ']'"); }
	|T_NEW array_type '[' expr ']' '{' array_pair_list '}'    {	$<ast>$ = ast->createNode($<ast>2,ast->createNode($<ast>4,$<ast>7,arrayInitializingNode),arrayNode)->addValuestring($<r.str>2);	                debuggerYACC(" X883 - array_expr <<  var_types '[' T_LNUMBER ']'  '{' array_pair_list '}'"); }
	|T_NEW array_type '[' ']' '{' array_pair_list '}'         {	$<ast>$ = ast->createNode($<ast>2,ast->createNode(0      ,$<ast>6,arrayInitializingNode),arrayNode)->addValuestring($<r.str>2);	                debuggerYACC(" X883 - array_expr <<  var_types '[' T_LNUMBER ']'  '{' array_pair_list '}'"); }	
;

array_type:
	  var_types     %prec lowpriority2   { $<r.str>$ = $<r.str>1;  $<ast>$ = NULL;                        debuggerYACC(" X884 - array_type << var_types"); }
	| T_STRING		%prec lowpriority2   { $<r.str>$ = $<r.str>1;  $<ast>$ = ast->createNode(0,0,classTypeNameNode); $<ast>$->addSymbolTableElement(findClassName($<r.str>1)); debuggerYACC(" X885 - array_type << T_STRING"); }
;


variable_without_objects:
      variable_without_objects '[' expr ']'       { $<ast>$ = ast->createNode($<ast>1,$<ast>3,callArrayVariableNode); $<ast>$->addSymbolTableElement($<ast>1->symbolTableElement); debuggerYACC(" X1134 - reference_variable << reference_variable '[' T_LNUMBER ']'"); }
    | T_VARIABLE	                   %prec lowpriority3       { $<ast>$ = ast->createNode(0,0,callVariableNode); $<ast>$->addSymbolTableElement(callVariable($<r.str>1));   debuggerYACC(" X1136 - reference_variable << | T_VARIABLE"); }

    | var_type_or_name T_VARIABLE
					{ 
             			    $<ast>$ = ast->createNode($<ast>1,0,idVariableNode);
						    $<ast>$->addSymbolTableElement(addVariable($<r.str>1,$<r.str>2,false));
								
						    debuggerYACC(" X1110 - variable_without_objects << | var_type_or_name T_VARIABLE"); 
					}
;

function_call:
      T_STRING argument_list { $<ast>$ = ast->createNode(0,$<ast>2,functionCallNode); $<ast>$->addSymbolTableElement(callFunction($<r.str>1))->addValuestring($<r.str>1);  debuggerYACC(" X918 - function_call << namespace_name_parts argument_list"); }
    | T_STRING T_PAAMAYIM_NEKUDOTAYIM T_STRING argument_list { $<ast>$ = ast->createNode(0,$<ast>4,functionCallNode); $<ast>$->addSymbolTableElement(findStaticFunction($<r.str>1,$<r.str>3)); debuggerYACC(" X919 - function_call << | class_name_or_var T_PAAMAYIM_NEKUDOTAYIM identifier argument_list");}      
;

common_scalar:
      T_LNUMBER                   { $<r.str>$ = strdup(to_string($<r.intvalue>1).c_str()); $<ast>$ = ast->createNode(0,0,intValNode)->addValueint($<r.intvalue>1);        debuggerYACC(" X983 - common_scalar << T_LNUMBER"); }
    | T_DNUMBER                   { $<r.str>$ = strdup(to_string($<r.floatvalue>1).c_str()); $<ast>$ = ast->createNode(0,0,doubleValNode)->addValuedouble($<r.floatvalue>1);								   debuggerYACC(" X984 - common_scalar << | T_DNUMBER"); }
   
    | T_CONSTANT_ENCAPSED_STRING  { $<r.str>$ = $<r.str>1; $<ast>$ = ast->createNode(0,0,stringValNode)->addValuestring($<r.str>1);       debuggerYACC(" X985 - common_scalar << | T_CONSTANT_ENCAPSED_STRING"); }
	| T_TRUE               {    $<ast>$=ast->createNode(0,0,trueNode);            }
	| T_FALSE              {    $<ast>$=ast->createNode(0,0,falseNode);           }
	| T_NULL               {    $<ast>$=ast->createNode(0,0,nullNode);            }
;

static_scalar:
      common_scalar                             { $<r.str>$ = $<r.str>1; $<ast>$ = $<ast>1; debuggerYACC(" X1001 - static_scalar << common_scalar"); }
    | T_STRING T_PAAMAYIM_NEKUDOTAYIM T_STRING    { $<ast>$ = ast->createNode(0,0,callVariableNode); $<ast>$->addSymbolTableElement(findStaticMember($<r.str>1,$<r.str>3)); debuggerYACC(" X1002 - static_scalar << | class_name T_PAAMAYIM_NEKUDOTAYIM identifier"); }
    | '-' T_LNUMBER                         { $<r.str>$ = strdup(to_string($<r.intvalue>2 * -1).c_str()); $<ast>$ = ast->createNode(0,0,intValNode)->addValueint($<r.intvalue>2*-1);    debuggerYACC(" X1006 - static_scalar << | '-' common_scalar"); }
	| '-' T_DNUMBER                         { $<r.str>$ = strdup(to_string($<r.floatvalue>2 * -1).c_str()); $<ast>$ = ast->createNode(0,0,doubleValNode)->addValueint($<r.floatvalue>2*-1);   debuggerYACC(" X1006 - static_scalar << | '-' common_scalar"); }
;
scalar:
      common_scalar                                     { $<ast>$ = $<ast>1;  debuggerYACC(" X1052 - scalar << common_scalar"); }
    | T_STRING T_PAAMAYIM_NEKUDOTAYIM T_STRING          { $<ast>$ = ast->createNode(0,0,callVariableNode); $<ast>$->addSymbolTableElement(findStaticMember($<r.str>1,$<r.str>3));       debuggerYACC(" X1047 - constant << | class_name_or_var T_PAAMAYIM_NEKUDOTAYIM identifier"); }
;

optional_comma:
      /* empty */                                                                                               {  debuggerYACC(" X1066 - optional_comma << /* empty */"); }
    | ','                                                                                                       {  debuggerYACC(" X1067 - optional_comma << | ','"); }
;

variable:
      object_access               { $<ast>$=$<ast>1; debuggerYACC(" X1081 - variable << object_access"); }
    | base_variable               { $<ast>$=$<ast>1; debuggerYACC(" X1082 - variable << | base_variable"); }
    | function_call               { $<ast>$=$<ast>1; debuggerYACC(" X1083 - variable << | function_call"); }
;

object_access:
      variable_or_new_expr T_OBJECT_OPERATOR T_VARIABLE            %prec test2         { $<ast>$ = ast->createNode($<ast>1,0,objectAccessToVariableNode)->addValuestring($<r.str>3);     $<ast>$->addSymbolTableElement(findInstanceVariable($<ast>1->symbolTableElement,$<r.str>3));			  debuggerYACC(" X1093 - object_access << variable_or_new_expr T_OBJECT_OPERATOR object_property %prec test2"); }    
    | variable_or_new_expr T_OBJECT_OPERATOR T_STRING argument_list                     { $<ast>$ = ast->createNode($<ast>1,$<ast>4,objectAccessToFunctionNode)->addValuestring($<r.str>3);    $<ast>$->addSymbolTableElement(findInstanceFunction($<ast>1->symbolTableElement,$<r.str>3));;							debuggerYACC(" X1095 - object_access << | variable_or_new_expr T_OBJECT_OPERATOR object_property argument_list"); }

    | object_access argument_list                                                                               {  debuggerYACC(" X1097 - object_access << | object_access argument_list"); }
    | object_access '[' dim_offset ']'                    {  $<ast>$ = ast->createNode($<ast>1,$<ast>3,objectAccessToArrayElementNode); debuggerYACC(" X1098 - object_access << | object_access '[' T_LNUMBER ']'");  }
;

variable_or_new_expr:
      variable                                  { $<ast>$ = $<ast>1;  debuggerYACC(" X1103 - variable_or_new_expr << variable"); }
    | '(' new_expr ')'                          { $<ast>$ = $<ast>2; debuggerYACC(" X1104 - variable_or_new_expr << | '('new_expr ')'"); }
;

base_variable:
      variable_without_objects      { $<ast>$ = $<ast>1;  debuggerYACC(" X1114 - base_variable << variable_without_objects"); }
    | static_property               { $<ast>$ = $<ast>1; debuggerYACC(" X1115 - base_variable << | static_property"); }
;

static_property:
      T_STRING T_PAAMAYIM_NEKUDOTAYIM T_VARIABLE                     { $<ast>$ = ast->createNode(0,0,callVariableNode);                  $<ast>$->addSymbolTableElement(findStaticMember($<r.str>1,$<r.str>3));              debuggerYACC(" X1125 - static_property_with_arrays << class_name_or_var T_PAAMAYIM_NEKUDOTAYIM T_VARIABLE"); } 
	  | static_property '[' expr ']'      { $<ast>$ = ast->createNode($<ast>1,$<ast>3,callArrayVariableNode);       $<ast>$->addSymbolTableElement($<ast>1->symbolTableElement);               debuggerYACC(" X1134 - reference_variable << reference_variable '[' T_LNUMBER ']'"); }
;

array_pair_list:
      /* empty */                                                       { $<ast>$=NULL;   debuggerYACC(" X1168 - array_pair_list << /* empty */"); }
    | non_empty_array_pair_list optional_comma                          { $<ast>$=$<ast>1;  debuggerYACC(" X1169 - array_pair_list << | non_empty_array_pair_list optional_comma"); }
;

non_empty_array_pair_list:
      non_empty_array_pair_list ',' array_pair                          { $<ast>$=ast->addToLastRight($<ast>1,ast->createNode($<ast>3,0,arrayPairListNode)); debuggerYACC(" X1173 - non_empty_array_pair_list << non_empty_array_pair_list ',' array_pair"); }
    | array_pair                                                        { $<ast>$=ast->createNode($<ast>1,0,arrayPairListNode); debuggerYACC(" X1174 - non_empty_array_pair_list << | array_pair"); }
;

array_pair:
      expr                                                              { $<ast>$=$<ast>1; debuggerYACC(" X1179 - array_pair << | expr"); }
    | '&' variable                                                      { $<ast>$=$<ast>2; debuggerYACC(" X1181 - array_pair << | '&' variable"); }
;

%%

void yyerror(const char *s)
{
	yyerrok; yyclearin; errorhandler(s);
}

int yylex() 
{
	return lexer->yylex(); 
}


void main(int argc,char *argv[])
{
    for(int i = 1; i < argc; i++)
	{
	     if(string(argv[i])=="-o")
				enableOutPut(true);
		 else if(string(argv[i])=="-a")
				enableOutPutAST(true);
		 else if(string(argv[i])=="-c")
				enableCommentingASMCode(true);
         else if(string(argv[i])=="-q")
				enableCopyResultToClipboard(true);
		 else
				changeInputFile(argv[i]);
	}

	if(before_main())
	{
		Parser* p = new Parser();
		p->parse();
	}
		
	after_main(finalTree);
}