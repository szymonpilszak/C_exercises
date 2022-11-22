// print 10x10 multiplication table

#include <stdio.h>

int main(void)
{   
    int number;

    for( int i=1; i<=10 ; i++)

    {
        for(int j=1; j<=10 ; j++)

        {
            number = i*j;
            printf("%d\t", number);
        }
    printf("\n");

    }

    return 0;

} 