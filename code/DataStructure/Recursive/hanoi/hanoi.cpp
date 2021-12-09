#include <cstdio>

int hanoi(int num, int start, int dest, int pass)
{
    static int count = 0;
    count++;
    if(num == 1) return count; 
    hanoi(num-1,start,pass,dest);
    hanoi(num-1,pass,dest,start);
}

int main()
{
    int n = 5;
    int count = hanoi(n,1,3,2);
    printf("%d\n", count);
}