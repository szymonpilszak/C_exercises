// count the length of a string


#include <stdio.h>
#include <string.h>

int main()
{
    
    char example[] = "Coding is fun";
    int result = strlen(example);

    printf( "%s", example);
    printf("\nIncluding whitespaces our string has %d charcters", result);

    return 0;
}