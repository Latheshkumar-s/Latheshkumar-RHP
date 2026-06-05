#include <stdio.h>

int main()
{
    char s[1000001];
    scanf("%s", s);

    int m = 0;

    for(int i = 0; s[i]; i++)
    {
        if(s[i] >= '0' && s[i] <= '9')
            m |= (1 << (s[i] - '1'));
    }

    if(m == ((1 << 9) - 1))
        printf("Yes");
    else
        printf("No");

    return 0;
}
