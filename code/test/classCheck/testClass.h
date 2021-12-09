#include <iostream>
#include <cstdio>

class testClass
{
private:
    /* data */
public:
    static testClass * instance;
    static testClass * getinstance(); 
    testClass(/* args */);
    ~testClass();
};
