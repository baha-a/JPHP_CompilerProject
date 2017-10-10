%{

    #include "Code\HelperCode.h"
	using namespace banana;

	#include "yacc.hpp"

	#include <iostream>
	#include <istream>
	#include <ostream>
	#include <stack>
	#include <stdlib.h>
	#include "FlexLexer.h"

	using namespace std;

	char* str;
	
	void updateLocation(int length)
	{
		col += length;

		yylval.r.myColno = col;
		yylval.r.myLineNo = line;
	}

	void copyTextToStrAndUpdateLocation(const char* x,int length)
	{
		yylval.r.str = new char[255];
		yylval.r.str[0] = '\0';
		strcpy_s(yylval.r.str,255 , x);

		updateLocation(length);		
	}

%}
%option c++
%option noyywrap
%option yylineno
%x multilinecomment
%%

"readInt()"			{ debuggerLEX(yytext); updateLocation(yyleng); return T_READ_INT;}
"readDouble()"		{ debuggerLEX(yytext); updateLocation(yyleng); return T_READ_DOUBLE;}
"readString()"		{ debuggerLEX(yytext); updateLocation(yyleng); return T_READ_STRING;}
"super"             { debuggerLEX(yytext); updateLocation(yyleng); return T_SUPER;}
"true"             { debuggerLEX(yytext); updateLocation(yyleng); return T_TRUE;}
"false"             { debuggerLEX(yytext); updateLocation(yyleng); return T_FALSE;}
"null"             { debuggerLEX(yytext); updateLocation(yyleng); return T_NULL;}

"abstract"			{ debuggerLEX(yytext); updateLocation(yyleng); return T_ABSTRACT;}
"&="				{ debuggerLEX(yytext); updateLocation(yyleng); return T_AND_EQUAL;}
"as"				{ debuggerLEX(yytext); updateLocation(yyleng); return T_AS;}
"&&"				{ debuggerLEX(yytext); updateLocation(yyleng); return T_BOOLEAN_AND;}
"||"				{ debuggerLEX(yytext); updateLocation(yyleng); return T_BOOLEAN_OR;}
"(bool)"			{ debuggerLEX(yytext); updateLocation(yyleng); return T_BOOL_CAST;}
"(boolean)"			{ debuggerLEX(yytext); updateLocation(yyleng); return T_BOOL_CAST;}
"break"				{ debuggerLEX(yytext); updateLocation(yyleng); return T_BREAK;}
"case"				{ debuggerLEX(yytext); updateLocation(yyleng); return T_CASE;}
"catch"				{ debuggerLEX(yytext); updateLocation(yyleng); return T_CATCH;}
"class"				{ debuggerLEX(yytext); updateLocation(yyleng); return T_CLASS;}
"clone"				{ debuggerLEX(yytext); updateLocation(yyleng); return T_CLONE;}
"?>"				{ debuggerLEX(yytext); updateLocation(yyleng); return T_CLOSE_TAG_PHP;}
".="				{ debuggerLEX(yytext); updateLocation(yyleng); return T_CONCAT_EQUAL;}
"const"				{ debuggerLEX(yytext); updateLocation(yyleng); return T_CONST;}
"continue"			{ debuggerLEX(yytext); updateLocation(yyleng); return T_CONTINUE;}
"--"				{ debuggerLEX(yytext); updateLocation(yyleng); return T_DEC;}
"default"			{ debuggerLEX(yytext); updateLocation(yyleng); return T_DEFAULT;}
"/="				{ debuggerLEX(yytext); updateLocation(yyleng); return T_DIV_EQUAL;}
"do"				{ debuggerLEX(yytext); updateLocation(yyleng); return T_DO;}
"=>"				{ debuggerLEX(yytext); updateLocation(yyleng); return T_DOUBLE_ARROW;}
"(real)"			{ debuggerLEX(yytext); updateLocation(yyleng); return T_DOUBLE_CAST;}
"(double)"			{ debuggerLEX(yytext); updateLocation(yyleng); return T_DOUBLE_CAST;}
"(float)"			{ debuggerLEX(yytext); updateLocation(yyleng); return T_DOUBLE_CAST;}
"echo"				{ debuggerLEX(yytext); updateLocation(yyleng); return T_ECHO;}
"..."				{ debuggerLEX(yytext); updateLocation(yyleng); return T_ELLIPSIS;}
"else"				{ debuggerLEX(yytext); updateLocation(yyleng); return T_ELSE;}
"elseif"			{ debuggerLEX(yytext); updateLocation(yyleng); return T_ELSEIF;}
"endfor"			{ debuggerLEX(yytext); updateLocation(yyleng); return T_ENDFOR;}
"endforeach"		{ debuggerLEX(yytext); updateLocation(yyleng); return T_ENDFOREACH;}
"endswitch"			{ debuggerLEX(yytext); updateLocation(yyleng); return T_ENDSWITCH;}
"endwhile"			{ debuggerLEX(yytext); updateLocation(yyleng); return T_ENDWHILE;}
"extends"			{ debuggerLEX(yytext); updateLocation(yyleng); return T_EXTENDS;}
"final"				{ debuggerLEX(yytext); updateLocation(yyleng); return T_FINAL;}
"finally"			{ debuggerLEX(yytext); updateLocation(yyleng); return T_FINALLY;}
"for"				{ debuggerLEX(yytext); updateLocation(yyleng); return T_FOR;}
"foreach"			{ debuggerLEX(yytext); updateLocation(yyleng); return T_FOREACH;}
"function"			{ debuggerLEX(yytext); updateLocation(yyleng); return T_FUNCTION;}
"cfunction"			{ debuggerLEX(yytext); updateLocation(yyleng); return T_FUNCTION;}
"goto"				{ debuggerLEX(yytext); updateLocation(yyleng); return T_GOTO;}
"if"				{ debuggerLEX(yytext); updateLocation(yyleng); return T_IF;}
"implements"		{ debuggerLEX(yytext); updateLocation(yyleng); return T_IMPLEMENTS;}
"++"				{ debuggerLEX(yytext); updateLocation(yyleng); return T_INC;}

"include"			{ debuggerLEX(yytext); updateLocation(yyleng); return T_INCLUDE;} 
"require"			{ debuggerLEX(yytext); updateLocation(yyleng); return T_INCLUDE_ONCE;}


"(int)"				{ debuggerLEX(yytext); updateLocation(yyleng); return T_INT_CAST;}
"(integer)"			{ debuggerLEX(yytext); updateLocation(yyleng); return T_INT_CAST;}
"interface"			{ debuggerLEX(yytext); updateLocation(yyleng); return T_INTERFACE;}
"=="				{ debuggerLEX(yytext); updateLocation(yyleng); return T_IS_EQUAL;}
">="				{ debuggerLEX(yytext); updateLocation(yyleng); return T_IS_GREATER_OR_EQUAL;}
"!="				{ debuggerLEX(yytext); updateLocation(yyleng); return T_IS_NOT_EQUAL;}
"<>"				{ debuggerLEX(yytext); updateLocation(yyleng); return T_IS_NOT_EQUAL;}
"<="				{ debuggerLEX(yytext); updateLocation(yyleng); return T_IS_SMALLER_OR_EQUAL;}
"and"				{ debuggerLEX(yytext); updateLocation(yyleng); return T_LOGICAL_AND;}
"or"				{ debuggerLEX(yytext); updateLocation(yyleng); return T_LOGICAL_OR;}
"xor"				{ debuggerLEX(yytext); updateLocation(yyleng); return T_LOGICAL_XOR;}
"-="				{ debuggerLEX(yytext); updateLocation(yyleng); return T_MINUS_EQUAL;}
"%="				{ debuggerLEX(yytext); updateLocation(yyleng); return T_MOD_EQUAL;}
"*="				{ debuggerLEX(yytext); updateLocation(yyleng); return T_MUL_EQUAL;}
"new"				{ debuggerLEX(yytext); updateLocation(yyleng); return T_NEW;}
"->"				{ debuggerLEX(yytext); updateLocation(yyleng); return T_OBJECT_OPERATOR;}
"<?php"				{ debuggerLEX(yytext); updateLocation(yyleng); return T_OPEN_TAG_PHP;}
"|="				{ debuggerLEX(yytext); updateLocation(yyleng); return T_OR_EQUAL;}
"::"				{ debuggerLEX(yytext); updateLocation(yyleng); return T_PAAMAYIM_NEKUDOTAYIM;}
"+="				{ debuggerLEX(yytext); updateLocation(yyleng); return T_PLUS_EQUAL;}
"**"				{ debuggerLEX(yytext); updateLocation(yyleng); return T_POW;}
"**="				{ debuggerLEX(yytext); updateLocation(yyleng); return T_POW_EQUAL;}
"private"			{ debuggerLEX(yytext); updateLocation(yyleng); return T_PRIVATE;}
"public"			{ debuggerLEX(yytext); updateLocation(yyleng); return T_PUBLIC;}
"protected"			{ debuggerLEX(yytext); updateLocation(yyleng); return T_PROTECTED;}
"return"			{ debuggerLEX(yytext); updateLocation(yyleng); return T_RETURN;}
"<<"				{ debuggerLEX(yytext); updateLocation(yyleng); return T_SL;}
">>"				{ debuggerLEX(yytext); updateLocation(yyleng); return T_SR;}
">>="				{ debuggerLEX(yytext); updateLocation(yyleng); return T_SR_EQUAL;}
"static"			{ debuggerLEX(yytext); updateLocation(yyleng); return T_STATIC;}
"(string)"			{ debuggerLEX(yytext); updateLocation(yyleng); return T_STRING_CAST;}
"switch"			{ debuggerLEX(yytext); updateLocation(yyleng); return T_SWITCH;}
"throw"				{ debuggerLEX(yytext); updateLocation(yyleng); return T_THROW;}
"try"				{ debuggerLEX(yytext); updateLocation(yyleng); return T_TRY;}
"while"				{ debuggerLEX(yytext); updateLocation(yyleng); return T_WHILE;}
"^="				{ debuggerLEX(yytext); updateLocation(yyleng); return T_XOR_EQUAL;}


";"					{ debuggerLEX(yytext); updateLocation(yyleng); return ';' ;}
"}"					{ debuggerLEX(yytext); updateLocation(yyleng); return '}' ;}
","					{ debuggerLEX(yytext); updateLocation(yyleng); return ',' ;}
"="					{ debuggerLEX(yytext); updateLocation(yyleng); return '=' ;}
"{"					{ debuggerLEX(yytext); updateLocation(yyleng); return '{' ;}
":"					{ debuggerLEX(yytext); updateLocation(yyleng); return ':' ;}
"&"					{ debuggerLEX(yytext); updateLocation(yyleng); return '&' ;}
"$"					{ debuggerLEX(yytext); updateLocation(yyleng); return '$' ;}
"|"					{ debuggerLEX(yytext); updateLocation(yyleng); return '|' ;}
"^"					{ debuggerLEX(yytext); updateLocation(yyleng); return '^' ;}
"."					{ debuggerLEX(yytext); updateLocation(yyleng); return '.' ;}
"+"					{ debuggerLEX(yytext); updateLocation(yyleng); return '+' ;}
"-"					{ debuggerLEX(yytext); updateLocation(yyleng); return '-' ;}
"*"					{ debuggerLEX(yytext); updateLocation(yyleng); return '*' ;}
"/"					{ debuggerLEX(yytext); updateLocation(yyleng); return '/' ;}
"%"					{ debuggerLEX(yytext); updateLocation(yyleng); return '%' ;}
"!"					{ debuggerLEX(yytext); updateLocation(yyleng); return '!' ;}
"~"					{ debuggerLEX(yytext); updateLocation(yyleng); return '~' ;}
"<"					{ debuggerLEX(yytext); updateLocation(yyleng); return '<' ;}
">"					{ debuggerLEX(yytext); updateLocation(yyleng); return '>' ;}
"?"					{ debuggerLEX(yytext); updateLocation(yyleng); return '?' ;}
"@"					{ debuggerLEX(yytext); updateLocation(yyleng); return '@' ;}
"`"					{ debuggerLEX(yytext); updateLocation(yyleng); return '`' ;}
"]"					{ debuggerLEX(yytext); updateLocation(yyleng); return ']' ;}
"["					{ debuggerLEX(yytext); updateLocation(yyleng); return '[' ;}
"\""				{ debuggerLEX(yytext); updateLocation(yyleng); return '\"' ;}

"("					{ debuggerLEX(yytext); updateLocation(yyleng); return '(' ;}
")"					{ debuggerLEX(yytext); updateLocation(yyleng); return ')' ;}



"bool"				{ debuggerLEX(yytext); copyTextToStrAndUpdateLocation(yytext,yyleng); return T_V_BOOL;}

"string"			{ debuggerLEX(yytext); copyTextToStrAndUpdateLocation(yytext,yyleng); return T_V_STRING;}
"char"				{ debuggerLEX(yytext); copyTextToStrAndUpdateLocation(yytext,yyleng); return T_V_CHAR;}

"double"			{ debuggerLEX(yytext); copyTextToStrAndUpdateLocation(yytext,yyleng); return T_V_DOUBLE;}
"float"				{ debuggerLEX(yytext); copyTextToStrAndUpdateLocation(yytext,yyleng); return T_V_FLOAT;}

"real"				{ debuggerLEX(yytext); copyTextToStrAndUpdateLocation(yytext,yyleng); return T_V_REAL;}
"int"				{ debuggerLEX(yytext); copyTextToStrAndUpdateLocation(yytext,yyleng);  return T_V_INT;}
"long"				{ debuggerLEX(yytext); copyTextToStrAndUpdateLocation(yytext,yyleng); return T_V_LONG;}
"byte"				{ debuggerLEX(yytext); copyTextToStrAndUpdateLocation(yytext,yyleng); return T_V_BYTE;}
"uint"				{ debuggerLEX(yytext); copyTextToStrAndUpdateLocation(yytext,yyleng); return T_V_UINT;}
"ulong"				{ debuggerLEX(yytext); copyTextToStrAndUpdateLocation(yytext,yyleng); return T_V_ULONG;}
"ubyte"				{ debuggerLEX(yytext); copyTextToStrAndUpdateLocation(yytext,yyleng); return T_V_UBYTE;}



\"([^\\\"]|\\.)*\"				{
						debuggerLEX("stringvalue = ", yytext);
						
						copyTextToStrAndUpdateLocation(yytext,yyleng);
						
						for(int i = 0; i < yyleng;i++)
						{
							 if(yytext[i] == '\n')
							 {
								 line++;
								 col = 1;
							 }
							 else
								col++;
						}

						yylval.r.stringvalue = yytext;
						return T_CONSTANT_ENCAPSED_STRING;
					}


\'([^\\\']|\\.)*\' {
						debuggerLEX("stringvalue = ", yytext);

						copyTextToStrAndUpdateLocation(yytext,yyleng); 
						for(int i = 0; i < yyleng;i++)
						{
								if(yytext[i] == '\n')
								{
									line++;
									col = 1;
								}
								else
									col++;
						}
				
						yylval.r.stringvalue = yytext;
						return T_CONSTANT_ENCAPSED_STRING;
					}

0("x"|"X")[a-fA-F0-9]+		{ debuggerLEX("Hex value = " , yytext); copyTextToStrAndUpdateLocation(yytext,yyleng); yylval.r.intvalue = atoi(yytext); return T_LNUMBER; }
0("o"|"O")[0-7]+			{ debuggerLEX("Octa value = " , yytext); copyTextToStrAndUpdateLocation(yytext,yyleng); yylval.r.intvalue = atoi(yytext); return T_LNUMBER; }
0("b"|"B")(0|1)+			{ debuggerLEX("Bin value = " ,yytext); copyTextToStrAndUpdateLocation(yytext,yyleng); yylval.r.intvalue = atoi(yytext); return T_LNUMBER; }

[1-9][0-9]*|0  				{ /// \s*[+-]?\s*[0-9]+\s*
	debuggerLEX("Integer value = ", yytext);

								copyTextToStrAndUpdateLocation(yytext,yyleng);
								yylval.r.intvalue = atoi(yytext);

								return T_LNUMBER;
							}

(((([0-9]+)?)((".")[0-9]+))|(([0-9]+)(".")))|((([0-9]+)|(((([0-9]+)?)((".")[0-9]+))|(([0-9]+)("."))))(("e"|"E")(("+"|"-")?)[0-9]+))	{
								 debuggerLEX("float point value = " , yytext); 
			
								 copyTextToStrAndUpdateLocation(yytext,yyleng);
								 yylval.r.floatvalue = atof(yytext);

								 return T_DNUMBER;
							}

[$][a-zA-Z_][a-zA-Z0-9_]*	{
								debuggerLEX("ID = " , yytext);
								
								copyTextToStrAndUpdateLocation(yytext,yyleng);
							
								return T_VARIABLE;
							}
[$][0-9][a-zA-Z0-9_]*	{ 
							debuggerLEX("ID = " , yytext);
							
							errorhandler("wrong identifier",yytext);
							copyTextToStrAndUpdateLocation(yytext,yyleng);

							return T_VARIABLE;
						}

[a-zA-Z_][a-zA-Z0-9_]*	{
							debuggerLEX("Name = ", yytext);
							
							copyTextToStrAndUpdateLocation(yytext,yyleng);

							return T_STRING;
						}

"//".*								{ debuggerLEX("it is a Single Line Comment"); }

\/\*                                        { BEGIN multilinecomment; }
<multilinecomment>[\n]						{ line++; col = 1;}
<multilinecomment>"*"+"/"                   { BEGIN INITIAL; debuggerLEX("it is a Multi Line Comment");}

[\n]    { line++; col = 1;  }

%%