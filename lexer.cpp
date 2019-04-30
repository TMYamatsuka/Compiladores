#include <cstdio>
#include <string>
#include <iostream>
#include <cstdlib>
#include "symbolTable.cpp"


#define NUM 256
#define PLUS 257
#define VAR 258
#define EQ 259
#define PRINT 260
#define EOL 261
#define ERR 8000

using namespace std;

struct token
{
	int type;
	int value;
};

string input;
int pos = 0;
char c = EOF;
int current_line = 0;

string token_name(int t)
{
    switch (t)
    {
    case NUM:
        return "NUM";
    case PLUS:
        return "PLUS";
    case VAR:
        return "VAR";
	case EQ:
        return "EQ";
	case PRINT:
        return "PRINT";
	case EOL:
        return "EOL";
    }
    return "ERROR";
}

char get_char()
{
	if (pos < input.length())
	{
		return input[pos++];
	}
	else
	{
		return EOF;
	}
}

token next_token()
{
	token t;
	char peek;
	if (c == EOF)
	{
		peek = get_char();
	}
	else
	{
		peek = c;
		c = EOF;
	}
	do
	{
		if (peek == ' ' || peek == '\t')
			continue;
		else if (peek == '\n')
			current_line++;
		else
			break;
	} while (peek = get_char());
	if (isdigit(peek))
	{
		int v = 0;
		double r = 0.0;
		do
		{
			v = v * 10 + atoi(&peek);
			peek = get_char();
		} while (isdigit(peek));
		t.type = NUM;
		t.value = v;
		c = peek;
	}
	else if (isalpha(peek))
	{
		string aux = "";
		do
		{
			aux += peek;
			peek = get_char();
		} while (isalpha(peek));
		if (aux == "print")
		{
			t.type = PRINT;
		}
		else
		{
			t.type = VAR;
			int pos = key_insertion(aux);
			if (pos != -1)
            {
                t.value = pos;
            }
            else
            {
                t.value = get_index(aux);
            }
		}
		c = peek;
	}
	else if (peek == '+')
	{
		t.type = PLUS;
	}
	else if (peek == '=')
	{
		t.type = EQ;
	}
	else if (peek == EOF)
	{
		t.type = EOF;
	}
	else if (peek == ';')
	{
		t.type = EOL;
	}
	else
	{
		t.type = ERR;
	}
	return t;
}

int teste() {
    input = "x = 66+2+1; print x;";
    token lookahead = next_token();
    while (lookahead.type!=EOF)
	{
        cout << "<"<< token_name(lookahead.type);
        if (lookahead.type == NUM || lookahead.type == VAR)
            cout << "," << lookahead.value;
        cout <<">"<< endl;
        lookahead = next_token();
    }
	return 0;
}
