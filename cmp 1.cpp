#include <stdio.h>
#include <string.h>

int main()
{
    char a[20];
    printf("Enter a comment:"); 
    scanf("%s", a);  // Corrected format specifier
    
    int len = strlen(a);  /* Calculate the length 
                         	of the string */
    
    if (a[0] == '/')
    {
        if (a[1] == '/' && len >= 2)
        {
            printf("It is a single comment line");
        }
        else if (a[1] == '*' && a[len - 2] == '*' && a[len - 1] == '/')
        {
            printf("It is a multi comment line");
        }
        else
        {
            printf("It is NOT a comment line");
        }
    }
    else
    {
        printf("It is NOT a comment line");
    }

    return 0;
}
