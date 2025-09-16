#include <stdio.h>

int main()
{
    int num1 = 0;
    int num2 = 0;
    int start = 0;
    int primeStart = 0;
    int remainder = 0;
    int flag = 0;


    printf("Enter num1: ");
    scanf("%d", &num1);

    printf("Enter num2: ");
    scanf("%d", &num2);

    while (num2 < 2 || num2 <= num1)
    {
        printf("Invalid! End must be greater than %d. Enter num: ", num1);
        scanf("%d", &num2);
    }


    for (start = num1; start <= num2; start++)
    {
        flag = 1;
        for (primeStart = 2; primeStart <= start - 1; primeStart++)
        {
            remainder = start % primeStart;
            if (remainder == 0)
            {
                flag = 0;
                primeStart = start;
            }

        }
        if (flag == 1)
        {
            printf("%d\n", start);
        }
    }


    return 0;
}
