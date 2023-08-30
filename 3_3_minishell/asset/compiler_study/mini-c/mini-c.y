%{
// mini-c
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
%}

%token	TIDENT, TNUMBER, ...
%token	TPLUS, TMINUS, TMUL, TDIV, ...

%%
mini_c: translation_unit
	;
translation_unit: external_dcl
	| translation_unit external_dcl
	;
external_dcl: function_def
	| declaration
	;
fuction_def: function_header compound_st
	;
function_header: dcl_spec function_name formal_param
	;
dcl_spec: dcl_specifiers
	;
dcl_specifiers:	dcl_specifier
	| dcl_specifiers dcl_specifier
	;
dcl_specifier: type_qualifier
	| type_specifier
	;
type_qualifier: 'const'
	;
type_specifier: 'int'
	| 'void'
	;
function_name: ident
	;
formal_param: '(' opt_formal_param ')'
	;
opt_formal_param:	// epsilon
	| formal_param_list
	;
formal_param_list: param_dcl
	| formal_param_list ',' param_dcl
	;
param_dcl: dcl_spec declarator
	;
compound_st: '{' opt_dcl_list opt_stat_list '}'
	;
opt_dcl_list: // epsilon
	| declaration_list
	;
declaration_list: declaration
	| declaration_list declaration
	;
declaration: dcl_spec init_dcl_list ';'
	;
init_dcl_list: init_declarator
	| init_dcl_list ',' init_declarator
	;
init_declarator: declarator
	| declarator '=' number
declarator: ident
	| ident '[' opt_number ']'
	;
opt_number:	// epsilon
	| number
	;
opt_stat_list:	// epsilon
	| statement_list
	;
statement_list: statement
	| statement_list statement
	;
statement: compund_st
	| expression_st
	| if_st
	| while_st
	| return_st
	; // for문, do-while문, switch문을 추가해 보세요
expression_st: opt_expression ';'
	;
opt_expression:	// epsilon
	| expression
	;
if_st: 'if' '(' expression ')' statement
	| 'if' '(' expression ')' statement 'else' statement
	;
while_st: 'while' '(' expression ')' statement
	;
return_st: 'return' opt_statement
	;
expression: assignment_exp
	;
assignment_exp: logical_or_exp
	| unary_exp '=' assignment_exp
	| unary_exp '+=' assignment_exp
	| unary_exp '-=' assignment_exp
	| unary_exp '*=' assignment_exp
	| unary_exp '/=' assignment_exp
	| unary_exp '%=' assignment_exp
	;
logical_or_exp: logical_and_exp
	| logical_or_exp '||' logical_and_exp
	;
logical_and_exp: equality_exp
	| logical_and_exp '&&' equality_exp
	;
equality_exp: relational_exp
	| equality_exp '==' relational_exp
	| equality_exp '!=' relational_exp
	;
relational_exp: additive_exp
	| relational_exp '>' additive_exp
	| relational_exp '<' additive_exp
	| relational_exp '>=' additive_exp
	| relational_exp '<=' additive_exp
	;
additive_exp: multiplicative_exp
	| additive_exp '+' multiplicative_exp
	| additive_exp '-' multiplicative_exp
	;
multiplicative_exp: unary_exp
	| multiplicative_exp '*' unary_exp
	| multiplicative_exp '/' unary_exp
	| multiplicative_exp '%' unary_exp
	;
unary_exp: postfix_exp
	| '-' unary_exp
	| '!' unary_exp
	| '++' unary_exp
	| '--' unary_exp
	;
postfix_exp: primary_exp
	| postfix_exp '[' expression ']'
	| postfix_exp '(' opt_actual_param ')'
	| postfix_exp '++'
	| postfix_exp '--'
	;
opt_actual_param:	// epsilon
	| acutal_param
	;
acutal_param: acutal_param_list
	;
acutal_param_list: assignment_exp
	| acutal_param_list ',' assignment_exp
	;
primary_exp: ident
	| number
	| '(' expression ')'
	;
%%
