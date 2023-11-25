int addent = 0;

void addvec(int *x, int *y, int *z, int n)
{
    int i;
    addent++;

    for (i = 0; i < n; i++)
        z[i] = x[i] + y[i];
}
