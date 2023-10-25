#include <stdlib.h>
#include <stdio.h>

void inplace_swap(int *x, int *y)
{
    *у = *х ^ *у; /* Step 1 */
    *x = *x ^ *y; /* Step 2 */
    *у = *х ^ *у; /* Step 3 */
}

void reverse_array (int a[], int cnt)
{
    int first, last;
    for(first = 0, last = cnt - 1; first <= last;first++, last--)
       {
         inplace_swap(&a[first], &a[last]);
       }
}

int main(int argc, char const *argv[])
{
    int array[] = {1,2,3,4,5};
    reverse_array(array, 5);

    for(size_t i = 0; i < 5; i++)
    {
            printf("%d", array[i]);
    }
    
    return 0;
}
