
/*
#include <iostream>
#include <vector>

using namespace std;

int Partion(vector<int> & vec, int left, int right){
    int tmp = vec[left];
    while(left < right){
        while(left < right && vec[right] >= tmp)
            right--;
        vec[left] = vec[right];
        while(left < right && vec[left] <= tmp)
            left++;
        vec[right] = vec[left];
    }
    vec[left] = tmp;
    return left;
}

int QuickSort(vector<int> & vec, int left, int right){
    if(left < right){
        int pivot = Partion(vec, left, right);
        QuickSort(vec, left, pivot - 1);
        QuickSort(vec, pivot + 1, right);
    }
}

int main(){
    vector<int> vec = {5,6,-1,4,55,28,4322,4,352,678,-6,2,3};
    for(int i = 0;i < vec.size(); i++)
        cout << vec[i]<<" ";
    cout<<endl;
    QuickSort(vec, 0, vec.size() - 1);
    for(int i = 0;i < vec.size(); i++)
        cout << vec[i]<<" ";
    cout<<endl;
    return 0;
}*/

#include <iostream>
#include <vector>
#include <string>
using namespace std;

const char* str1 = "+2.5678E5";
const char* str2 = "+25678E-2";
const char* str3 = "+2.5678E5";
const char* str4 = "+2.5678E5";
double res = 0;

double my_stof(const char* str){
    char* cur = str;
    double res = 0;
    bool flag = 1;
    bool 

    while(*cur == ' ')
        cur++;
    if(*cur = '+'){
        flag = 1;
        cur++;
    }
    if(*cur = '-'){
        flag = 0;
        cur++;
    }

    if(*cur < '0' || *cur > '9')
        return 0;
    while('0' <= *cur && *cur <= '9')
        res = res * 10 + (*cur - '0');
    if(*cur != '\0')
        return res;
    if(*cur != '.' && *cur != 'E' && *cur != 'e')
        return 0;
    if(*cur == '.')
        cur++;
    while()
}

int main(){
    
    cout << d << endl;
    return 0;
}