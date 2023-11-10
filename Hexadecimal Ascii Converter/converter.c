#include "lib.h"

char *stringToBinary(char *str)
{
    if (str == NULL)
    {
        return NULL;
    }
    int slen = strlen(str);
    errno = 0;
    char *binary = malloc(slen * CHAR_BIT + 1);
    if (binary == NULL)
    {
        fprintf(stderr, "malloc has failed in stringToBinary(%s): %s\n", str, strerror(errno));
        return NULL;
    }
    if (slen == 0)
    {
        *binary = '\0';
        return binary;
    }
    char *ptr;
    char *start = binary;
    int i;
    for (ptr = str; *ptr != '\0'; ptr++)
    {
        for (i = CHAR_BIT - 1; i >= 0; i--, binary++)
        {
            *binary = (*ptr & 1 << i) ? '1' : '0';
        }
    }
    *binary = '\0';
    binary = start;
    return binary;
}

char *binToHexadecimal(char *bin)
{
    if (bin == NULL)
    {
        return NULL;
    }
    int binSize = strlen(bin);
    int hexSize = binSize / 4;
    char part[4];
    char binValues[16][4] = {"0000", "0001", "0010", "0011", "0100", "0101", "0110", "0111", "1000", "1001", "1010", "1011", "1100", "1101", "1110", "1111"};
    char hexValues[16][1] = {"1", "2", "3", "4", "5", "6", "7", "8", "9", "A", "B", "C", "D", "E", "F"};
    char *hex = malloc(hexSize);
    int pos;

    for (int i = 0, pos = 0; i < binSize; pos++, i += 4)
    {
        part[i % 4] = bin[i];
        part[(i + 1) % 4] = bin[i + 1];
        part[(i + 2) % 4] = bin[i + 2];
        part[(i + 3) % 4] = bin[i + 3];
        for (int x = 0; x < 16; x++)
        {
            if (strcmp(part, binValues[x]) == 1)
            {
                hex[pos] = hexValues[x][0];
            }
        }
    }
    return hex;
}

int ascii(char s)
{
    int ascii_code = (int)s;
    return ascii_code;
}

void testconverters(){
    char *input="Cadena";
    char *bin=stringToBinary(input);
    char *hex=binToHexadecimal(bin);
    int ascii_code=ascii(input[0]);

    printf("%d\n",ascii_code);
    printf("%s\n",input);
    printf("%s\n",bin);
    printf("%s\n",hex);
}
