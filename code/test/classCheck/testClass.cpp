#include "testClass.h"

testClass::testClass()
{

}
testClass::~testClass()
{

}

testClass * testClass::getinstance()
{
    static testClass * instance = nullptr;

    if(instance == nullptr)
    {
        instance = new testClass();
    }
    printf("instance : %p\n", instance);
    return instance;
}


int main()
{
    testClass * t1 = testClass::getinstance();
    testClass * t2 = testClass::getinstance();

    printf("%p\n", t1);
    printf("%p\n", t2);
}