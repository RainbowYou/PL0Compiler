%{
	/*Author:Bluefish*/
	/*Date:2015-12*/
	/*Description:lex file for PL0 syntax */
%}


// declarations section


/* regular definitions */
program					partial_program								
partial_program			(const_des)?(var_des)?(pro_des)?(sentence)
/*********************const description*************************/
const_des				("const")(" ")(const_def)(","const_def)*";"
const_def				(identifier)("=")(unsigned_integer)
unsigned_integer		(digit)+
identifier				letter(letter|digit)*
letter					[a-z]
digit					[0-9]
/*********************variable description*******************/
var_des					("var")(" ")identifier(","" "identifier)*";"
/********************procedure description******************/
pro_des					(pro_header)(partial_program)(";"pro_des)*";"
pro_header				"procedure"" "(identifier)";"
/********************sentence******************************/
sentence				(assign_sen)|(condition_sen)|(while_sen)|(procedure_call_sen)|(composite_sen)|(read_sen)|(write_sen)|(null)
assign_sen				(identifier)" "":="" "(expression)
expression				(0|1)?(item)((add_operation)(item))*
item					(factor)((mul_operation)(factor))*
factor					(identifier)|(unsigned_integer)|("("(expression)")")
add_operation			[+-]
mul_operation			[*/]
condition				(expression)(relation)(expression)|("odd"" "(expression))
relation				"="|"<>"|"<"|"<="|">"|">="
condition_sen			"if"(condition)"then"(sentence)
while_sen				"while"(condition)"do"(sentence)
procedure_call_sen		"call"" "(identifier)
composite_sen			"begin"(sentence)(";"sentence)*"end"
read_sen				"read"(\((identifier)(","(identifier))*\))
write_sen				"write"(\((expression)(","(expression))*\))



// lexical analyser name
%name mylexer

// class definition
{
	// place any extra class members here
}

// constructor
{
	// place any extra initialisation code here
}

// destructor
{
	// place any extra cleanup code here
}

// place any declarations here

%%


// rules section

// place your Lex rules here





%%


// programs section

int main(void)
{
	int n = 1;
	mylexer lexer;
	if (lexer.yycreate()) {
		n = lexer.yylex();
	}
	return n;
}

