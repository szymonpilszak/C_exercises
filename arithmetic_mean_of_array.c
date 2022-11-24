// calculate arithmetic_mean of an array

#include <stdio.h>

int array[10] = { 5, 5, 9, 1, 10, 1, 4, 8, 5, 6};
float mean();


int main(void)
{
    float meanx = mean();
    printf("%f", meanx);
    return 0;

}

float mean()
{

    int sum;

    for( int i = 0; i < 10; i++ ) 
    {
        sum += array[i];
    }

    return (sum/10.0);
}