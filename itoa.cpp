#include <iostream>
#include <cstdio>
using namespace std;

char* itoa(int value, char* str, int radix){
    char* tmp = "0123456789abcdefghijklmnopqrstuvwxyz";
    char* ptr = str;
    if(value == 0){
        *ptr++ = '0';
        *ptr++ = '\0';
        return str;
    }
    bool negative = false;;
    if(value < 0){
        *ptr++ = '-';
        negative = true;
        value = -value;
    }
    while(value != 0){
        *ptr++ = tmp[value % radix];
        value /= radix;
    }
    *ptr = '\0';
    char* left = str + (negative ? 1 : 0);
    char* right = --ptr;
    while(left < right){
        swap(*left++, *right--);
    }
    return str;
}



int main(){
    int value;
    while(cin >> value){
        char buffer[100];
        char* res = itoa(value,buffer, 16);
        cout << buffer <<endl;
        printf("%s\n", buffer);
    }
    return 0;
}