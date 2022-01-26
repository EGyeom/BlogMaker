#include <iostream>
#include <cstdio>
#include <time.h>
#include <math.h>
int main()
{
    unsigned int num = 2359729;
    unsigned char * bitsOfNum = (unsigned char*)&num;
    unsigned int newNum = 0;
    timespec start, end;

    clock_gettime(CLOCK_REALTIME, &start); 
    for (int i =0; i < 400000000; i++)
    {
        int a = 0;
        a++;
    }
    clock_gettime(CLOCK_REALTIME, &end);
    long ms = round(end.tv_nsec/1.0e6);
    ms -=  round(start.tv_nsec/1.0e6);
    int s = end.tv_sec - start.tv_sec;
    printf("%d:%ld\n",s,ms);
    // printf("%.8x\n", num);
    // for(int i =0; i < sizeof(int); i++)
    // {
    //     printf("%.2x \n", *(bitsOfNum+i));
    //     newNum += *
    // }
}