#include <stdio.h>

long long int max(long long int a, long long int b)
{
    if (a > b)
        return a;
    else
        return b;
}

int main(void)
{
    long long int N;
    scanf("%lli", &N);

    long long int arr[N + 1];
    for (int i = 0; i < N; i++)
        scanf("%lli", &arr[i]);
    
    arr[N] = 0;
    
    long long int stack[N + 5];
    long long int topElement = -1;

    long long int nextGreaterElementOnRight[N + 1];
    long long int nextGreaterElementOnLeft[N + 1];

    for (int i = 0; i < N + 1; i++)
    {
        nextGreaterElementOnRight[i] = N;
        nextGreaterElementOnLeft[i] = N;
    }
    
    stack[++topElement] = 0;
    for (int i = 1; i < N; i++)
    {
        if (arr[i] > arr[stack[topElement]])
        {
            while(topElement != -1 && arr[i] > arr[stack[topElement]])
            {
                nextGreaterElementOnRight[stack[topElement]] = i;
                topElement--;
            }
        }
        stack[++topElement] = i;
    }

    topElement = -1;

    stack[++topElement] = N - 1;
    for (int i = N - 2; i >= 0; i--)
    {
        if (arr[i] > arr[stack[topElement]])
        {
            while(topElement != -1 && arr[i] > arr[stack[topElement]])
            {
                nextGreaterElementOnLeft[stack[topElement]] = i;
                topElement--;
            }
        }
        stack[++topElement] = i;
    }

    long long int maximumProductOfNextGreaterElements = 0;
    for (int i = 0; i < N ; i++)
        maximumProductOfNextGreaterElements = max(maximumProductOfNextGreaterElements, arr[nextGreaterElementOnRight[i]] * arr[nextGreaterElementOnLeft[i]]);

    printf("%lli\N", maximumProductOfNextGreaterElements);
}
