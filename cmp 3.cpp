#include <stdio.h>
#include <string.h>

int main()
{
    char a[30];
    int i;

    printf("Enter a string:");
    scanf("%[^\n]", a); // Read the whole line including spaces

    int len = strlen(a);

    if (a[0] == '/' && a[1] == '/')
    {
        printf("The whole input is a comment line");
    }
    else
    {
        for (i = 0; i < len; i++)
        {
            if (a[i] == '/' && a[i+1] == '/')
            {
                break;
            }
            else if (a[i] == '/' || a[i] == ' ')
            {
                continue;
            }
            printf("%c", a[i]);
        }
    }

    return 0;
}
