#include <iostream>
using namespace std;
#include"AA_Vector.h"
/**
 * @brief main function
 * @return int
*/
int main()
{
    int arr[5] = { 1,2,3,4,5 };
    AA_Vector <int>v(arr, 4);
    AA_Vector <int>v2(arr, 4);
    AA_Vector <int>v3(v2);
    printf("-----------------------{ABDULLAH}-----------------------\n");
    cout << "______________" << "print_vector" << "_______________" << endl;
    cout << v << endl;
    cout << "______________" << "Push_back(5)(6)" << "_______________" << endl;
    v.push_back(5);
    v.push_back(6);
    cout << v << endl;
    cout << "______________" << "pop_back()" << "_______________" << endl;
    v.pop_back();
    cout << v << endl;
    printf("____________________[earase(it1)]____________________\n");
    v.erase(v.begin());
    cout << v << endl;
    cout << "______________" << "if (v3 == v2)" << "_______________" << endl;
    if (v3 == v2)
        cout << "True" << endl;
    else
    {
        cout << "False" << endl;
    }
    printf("-----------------------{ADHAM}--------------------------\n");
    printf("__________________[iterator begin()]________________\n");
    auto it = v.begin();
    cout << *it << endl;
    printf("__________________[iterator end()]__________________\n");
    it = v.end() - 1;
    cout << *it << endl;
    printf("__________________[earase(it1, it2)]________________\n");
    v.erase(v.begin() + 1, v.end() - 1);
    cout << v << endl;
    printf("_______________________[clear()]____________________\n");
    v.clear();
    //v.print();
    printf("NULL\n");
    printf("________________[insert(iterator, n)]_______________\n");
    v2.insert(v2.begin(), 8);
    cout << v2 << endl;
    printf("____________________[operator (<)]__________________\n");
    if (v3 < v2)
        cout << "True" << endl;
    else
    {
        cout << "False" << endl;
    }
    printf("______________________[size(n)]_____________________\n");
    cout << v3.size() << endl;
    printf("______________________[empty()]_____________________\n");
    if (v2.empty()) printf("True\n");
    else printf("False\n");
    printf("_____________________[resize(n)]____________________\n");
    v3.resize();
    cout << v3 << endl;
    
}
