#include <bits/stdc++.h>

class testClass{
    public:
    testClass() : num(0), ptr(&num) {}
    
    int * getNumPtr() const {return ptr;}
    void print() const {
    std::cout << num << "\n";
    throw "hello";
    }
    const testClass* getThis() {return this;}
    // int * getNumPtr() {return &num;}
    private:
    int *ptr;
    int num;
};

int main()
{
    // testClass * t = new testClass();
    // int* ptr = t->getNumPtr();
    // std::cout << *ptr << "\n";

    // const testClass * tptr = t->getThis();
    // tptr->print();
    try{
        testClass * t = new testClass();
        t->print();
    }
    catch (int num)
    {
        std::cout << num << "\n";
    }
    return 0;
}