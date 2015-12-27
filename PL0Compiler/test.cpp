void main()
{
	getSym();
	statement();
}

void statement()
{
	if (sym == "IF")
	{
		getsym();
		expr();
		if (sym != "THEN") error();
		else
		{
			getsym();
			statement();
			if (sym == "ELSE")
			{
				getsym();
				statement();
			}
		}
	}
	else
	{
		var();
		if (sym != ":=") error();
		else
		{
			getsym();
			expr();
		}
	}
	printf("it is a statement.\n");
}

void var()
{
	if (sym != "i") error();
	else
	{
		getsym();
		if (sym == "[")
		{
			getsym();
			expr();
			if (sym != "]") error();
			else getsym();
		}
	}
	printf("it is a variable \n");
}

void expr()
{
	term();
	while (sym == "+")
	{
		getsym();
		term();
	}
	printf("it is a expression \n");
}
void term()
{
	factor();
	while (sym == "*")
	{
		getsym();
		factor();
	}
	printf("it is a term \n");
}
void factor()
{
	if (sym == "(")
	{
		getsym();
		expr();
		if (sym != ")") error();
		else getsym();
	}
	else var();
	printf("it is a factor \n");
}

void error()
{
	printf("syntax error!\n");
}