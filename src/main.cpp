#include <iostream>
#include "../libs/datastruct/Stack.h"
//#include "../libs/datastruct/a.h"

using namespace std;

int main()
{
    Stack<int> s;
    s.push(5);
    s.push(10);
    cout << s.pop() << endl;
    cout << s.getSize() << endl;
    cout << s.pop() << endl;
    cout << s.getSize() << endl;
    cout << s.pop() << endl;
    cout << s.getSize() << endl;
    return 0;
}