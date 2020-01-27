#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

#define MAX (long long int)(1e5 + 5)

int main(void)
{
    long long int testCases;
    scanf("%lli", &testCases);
    getchar();
    while(testCases--)
    {
        char expression[MAX];

        long double stack[MAX];
        long long int top = -1;

        gets(expression);

        char* token = strtok(expression, " "); 
  
        while (token != NULL)
        { 
            if(isdigit(token[0]))
            {
                long double number = atof(token);

                top++;
                stack[top] = number;
            }
            else
            {
                long double secondNumber = stack[top];
                top--;
                long double firstNumber = stack[top];

                char operator = token[0];
                switch (operator)
                {
                case '+':
                    stack[top] = firstNumber + secondNumber;
                    break;
                case '-':
                    stack[top] = firstNumber - secondNumber;
                    break;
                case '*':
                    stack[top] = firstNumber * secondNumber;
                    break;
                case '/':
                    stack[top] = firstNumber / secondNumber;
                }
            }
            
            token = strtok(NULL, " ");
        }

        long double finalAnswer = stack[top];
        printf("%.6Lf\n", finalAnswer);
    }
}
