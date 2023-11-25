#include <stdio.h>

typedef unsigned char *byte_pointer;

void show_bytes(byte_pointer start, size_t len)
{
    size_t i;
    for (i = 0; i < len; i++)
    {
        printf(" %.2x ", start[i]);
    }
    printf("\n");
}

int main()
{
    short sx = -12345;      /* -12345 */
    unsigned uy = sx;       /* Mystery */

    printf("uy = %u:\t", uy);
    show_bytes((byte_pointer)&uy, sizeof(unsigned));
}
