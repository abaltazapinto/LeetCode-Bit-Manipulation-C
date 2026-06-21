#include <stdio.h>
#include <stdlib.h>

int binary_to_decimal(int bin)
{
    int dec;
    int base;
    int digit;

    dec = 0;
    base = 1;

    while (bin > 0)
    {
        digit = bin % 10;

        if (digit != 0 && digit != 1)
            return -1;

        dec = dec + digit * base;
        base = base * 2;
        bin = bin / 10;
    }

    return dec;
}

void decimal_to_binary(int dec)
{
    int bits[32];
    int i;

    if (dec < 0)
    {
        printf("Negative numbers are not supported yet\n");
        return;
    }

    if (dec == 0)
    {
        printf("Binary: 0\n");
        return;
    }

    i = 0;

    while (dec > 0)
    {
        bits[i] = dec % 2;
        dec = dec / 2;
        i++;
    }

    printf("Binary: ");

    while (i > 0)
    {
        i--;
        printf("%d", bits[i]);
    }

    printf("\n");
}

#include <stdint.h>

int hammingWeight(uint32_t n)
{
    int count;

    count = 0;
    while (n != 0)
    {
	if (n & 1)
		count++;
	n = n >> 1;
    }
    return count;
}
int main(void)
{
    int option;

    printf("1 - Binary to decimal\n");
    printf("2 - Decimal to binary\n");
	printf("3 - Count option: ");
    printf("Choose option: ");

    if (scanf("%d", &option) != 1)
    {
        printf("Invalid input\n");
        return 1;
    }

    if (option == 1)
    {
        int bin;
        int dec;

        printf("Enter a binary number: ");

        if (scanf("%d", &bin) != 1)
        {
            printf("Invalid input\n");
            return 1;
        }

        dec = binary_to_decimal(bin);

        if (dec == -1)
            printf("Invalid binary number\n");
        else
            printf("Decimal: %d\n", dec);
    }
    else if (option == 2)
    {
        int dec;

        printf("Enter a decimal number: ");

        if (scanf("%d", &dec) != 1)
        {
            printf("Invalid input\n");
            return 1;
        }

        decimal_to_binary(dec);
    }else if (option == 3){

    uint32_t n;
    int ones;

    printf("Enter a decimal number: ");
    scanf("%u", &n);

    ones = hammingWeight(n);

    printf("Number of bits set to 1: %d\n", ones);
	}
	else
	{
        printf("Invalid option\n");
        return 1;
    }

    return 0;
}
