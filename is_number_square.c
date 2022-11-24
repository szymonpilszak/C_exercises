// check if number is a perfect square

#include<stdio.h>
int main()
{

    int i, number;


    printf("Enter your number: ");
    scanf("%d", &number);


    for(i = 0; i <= number; i++)

    {
        if(number == i*i)

        {
            printf("\n\tnumber %d is a perfect square \n", number);
            return 0;   /
        }
    }
    
    printf("\n\tnumber %d is not a perfect square\n", number);
    return 0;
}