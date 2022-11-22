#include <stdio.h>

int array[10] = { 5, 5, 9, 1, 10, 1, 4, 8, 5, 6};



int main(void)
{
    int sum;

    for( int i = 0; i < 10; i++ ) 
    {
        sum += array[i];
    }

    printf("%d", sum);
    return 0;

}

