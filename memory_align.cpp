#include <cstdio>
#include <iostream>
using namespace std;

struct struct1{
    int a;
    char b;
    int c;
    int d;
    char e;
    char f;
};
struct struct2{
    char a;
    int b;
    static long c;
};
int main(){
    struct1 s1;
    cout << sizeof(s1) <<endl;
    struct2 s2;
    cout << sizeof(s2) <<endl;
    return 0;
}