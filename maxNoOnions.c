#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    long long int N;
    scanf("%lli", &N);

    long long int walls[N];
    for (int i = 0; i < N; i++)
        scanf("%lli", &walls[i]);

    long long int maxElementIndex = 0, maxOnions = 0;

    for (int i = 1; i < N; i++)
    {
        if (walls[i] >= walls[maxElementIndex])
        {
            maxOnions += llabs(maxElementIndex - i) * walls[maxElementIndex];
            maxElementIndex = i;
        }
    }

    long long int maxElementFromLeft = N - 1;

    for (int i = N - 2; i >= maxElementIndex; i--)
    {
        if (walls[i] >= walls[maxElementFromLeft])
        {
            maxOnions += llabs(maxElementFromLeft - i) * walls[maxElementFromLeft];
            maxElementFromLeft = i;
        }
    }

    printf("%lli\n", maxOnions);
}
