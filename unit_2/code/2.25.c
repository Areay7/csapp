#include <stdio.h>
#include <limits.h>

int main()
{
    long x = -1;
    unsigned long u = 2147483648; /* 2 to the 31st */

    int o = -2147483647;
    unsigned int p = -1u;

    unsigned r = o - p -2147483647;


    printf("%d - %u = %u\n", o , p, r);

    printf(" x = %lu  =  %ld\n", x, x);
    printf(" u = %lu  =  %ld\n", u, u);

    return 0;
}