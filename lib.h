#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <errno.h>
#include <ctype.h>
struct row
{
    char *original;
    char *binary;
    char *hexadecimal;
    int ascii;
};

char *stringToBinary(char *str);
char *binToHexadecimal(char *bin);
int ascii(char s);
void testconverters();
void getFileLine(int strSize,char *path, char *text, char *bin, char *hex);
void init(int argc, char **argv);