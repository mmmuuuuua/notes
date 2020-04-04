#include <iostream>

class A
{
    public:
        A(int a)
        {
            x = a;
        }

        int x;
};

int main()
{
    A a1(1);
    std::cout<<a1.x<<std::endl;
    A a2;
    std::cout<<a1.x<<std::endl;
}