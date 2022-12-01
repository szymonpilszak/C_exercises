
#include<stdio.h>

int main()
{
    int number = 2;
     
    printf("number * 2  = %d \n",number<<1); // number shifted 1 position to the left
    printf("number * 4  = %d \n",number<<2); // number shifted 2 positions to the left
    printf("number * 8  = %d \n",number<<3); // number shifted 3 positions to the left
    printf("number * 16 = %d \n",number<<4); // number shifted 4 positions to the left
    printf("number * 32 = %d \n",number<<5); // number shifted 5 positions to the left
     
    return 0;

}