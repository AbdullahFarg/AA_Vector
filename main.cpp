
#include <iostream>
using namespace std;
#include"AA_Vector.h"

int main()
{
    
    AA_Vector <int>v(0, 4);
    AA_Vector <int>v2(2, 4);
    AA_Vector <int>v3(v2);
    cout << "______________" << "print_vector" << "_______________"<<endl;
    v.print();
    cout << "______________" << "Push_back(5)(6)" << "_______________" << endl;
    v.push_back(5);
    v.push_back(6);
    v.print();
    cout << "______________" << "pop_back()" << "_______________" << endl;
    v.pop_back();
    v.print();
    cout << "______________" << "if (v3 == v2)" << "_______________" << endl;
    if (v3 == v2)
        cout << "True" << endl;
    else
    {
        cout << "False" << endl;
    }

}

