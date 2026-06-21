#include<stdlib.h>
#include<stdio.h>
#include<math.h>

int main()
{
    int bin, dec = 0, i;
    printf("\nEnter A Binary Number: \t");
    scanf("%d", &bin);
    for(i = 0; bin > 0; i++)
    {
        dec = dec + pow(2, i) * (bin % 10);
        bin = bin / 10;
    }
    printf("\nDecimal Equivalent of Binary Number: \t %d\n", dec);
    return 0;
}
   
