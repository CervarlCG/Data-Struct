#include <iostream>
#include <string.h>
#include "examples/stack/postfix.h"

using namespace std;

std::string postfix(std::string in);

int main()
{
    string in = "";
    cout << "Enter the infix expression: ";
    cin >> in;
    Postfix p(in);
    cout << "Postfix: " << p.convert() << endl;
    return 0;
}