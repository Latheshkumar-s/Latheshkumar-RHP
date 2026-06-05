#include <stdio.h>
#include <string.h>

int main()
{
    char s[100];
    scanf("%s", s);

    int n = strlen(s);

    for (int m = (1 << n) - 1; m >= 0; m--)
    {
        for (int i = 0; i < n; i++)
        {
            if (m & (1 << i))
                printf("%c", s[i]);
        }

        printf("\n");
    }

    return 0;
}
