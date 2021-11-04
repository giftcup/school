#include <stdio.h>

int exponent(int exp, int base);

int main(void)
{
    int expo, base, result;

    printf("Enter base: ");
    scanf("%d", &base);
    printf("Enter exponent: ");
    scanf("%d", &expo);

    result = exponent(expo, base);
    printf("%d raised to %d is %d\n", base, expo, result);

    return 0;
}

int exponent(int exp, int base)
{
    int res = 1;

    if (exp == 0)
        return 1;
    
    res = exponent(--exp, base);
    return res * base;
}