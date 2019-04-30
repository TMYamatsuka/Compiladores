#include "cstdio"
#include "string"
#include "iostream"
#include "cstdlib"
#include <vector>

using namespace std;

struct info
{
    string lexeme;
    int value;
};

typedef vector<info> table;

table symbols;

bool is_there(string lexeme)
{
    for (int i = 0; i < symbols.size(); i++)
    {
        info aux = symbols[i];
        if (aux.lexeme == lexeme)
        {
            return true;
        }
    }
    return false;
}

int key_insertion(string lexeme)
{
    if (!is_there(lexeme))
    {
        info aux;
        aux.lexeme = lexeme;
        symbols.push_back(aux);
        return symbols.size() - 1;
    }
    else
    {
        return -1;
    }
}

bool value_insertion(int index, int value)
{
    if (index >= 0 && index < symbols.size())
    {
        info aux = symbols[index];
        aux.value = value;
        symbols[index] = aux;
        return true;
    }
    else
    {
        return false;
    }
}

int get_value(int index)
{
   if (index >= 0 && index < symbols.size())
    {
        info aux = symbols[index];
        return aux.value;
    }
    else
    {
        return -1;
    }
}

int get_index(string lexeme)
{
   for (int i = 0; i < symbols.size(); i++)
    {
        info aux = symbols[i];
        if (aux.lexeme == lexeme)
        {
            return i;
        }
    }
    return -1;
}
int w()
{
    int aux;
    cout << is_there("x") << endl;
    aux = key_insertion("x");
    cout << aux << endl;
    cout << is_there("x") << endl;
    cout << value_insertion(aux, 3) << endl;
    cout << get_value(aux) << endl;
}
