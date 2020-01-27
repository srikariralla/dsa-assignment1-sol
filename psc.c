#include <stdio.h>
#include <stdbool.h>

int main(void)
{
    long long int testCases;
    scanf("%lli", &testCases);

    while(testCases--)
    {
        long long int N;
        scanf("%lli", &N);

        long long int cars[N];
        for (int i = 0; i < N; i++)
            scanf("%lli", &cars[i]);

        long long int stack[N + 5];
        long long int topElement = -1;

        long long int currentCorrectOrderCar = 1;
        bool isPossible = true;

        for (int i = 0; i < N; i++)
        {
            if (cars[i] == currentCorrectOrderCar)
            {
                currentCorrectOrderCar++;

                while(topElement != -1 && stack[topElement] == currentCorrectOrderCar)
                    currentCorrectOrderCar++, topElement--;
            }
            else
                stack[++topElement] = cars[i];
        }

        while(topElement != -1)
        {
            if (stack[topElement] != currentCorrectOrderCar)
            {
                isPossible = false;
                break;
            }
            topElement--, currentCorrectOrderCar++;
        }

        if (isPossible)
            printf("%s\N", "Yes");
        else
            printf("%s\N", "No");
    }
}
