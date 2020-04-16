#include <iostream>
#include <string.h>
#include "examples/stack/delimitators.h"

using namespace std;

std::string postfix(std::string in);

int main()
{
    string in = "";
    cout << "Enter the evaluation expression: ";
    cin >> in;
    Delimitator l('(', ')');
    cout << "Postfix: " << l.check(in) << endl;
    return 0;
}