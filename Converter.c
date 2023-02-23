#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

// Had to write this to convert the ASCII hex dump from the PSoC 6 back into binary lmao
// There was probably an easier way but this was kinda fun

typedef union Longtochar{
    unsigned char bytes[4];
    long int val;
} longchar;
int main(int argc, char *argv[])
{
    FILE *file = fopen(argv[1], "r");
    int fd = fileno(file);
    char buf[2];
    char *p;
    long int byte;
    FILE *out;
    longchar longval;
    if (argc > 2)
        out = fopen(argv[2], "wb");
    else 
        out = fopen("out.txt", "wb");
    while (fread(buf, 1, 2, file) > 0)
    {
        longval.val = strtol(buf, &p, 16);
        // printf("%s: %X\r\n", buf, longval.bytes[0]);
        size_t w = fwrite(&longval.bytes[0], sizeof longval.bytes[0], 1, out);
    }
    fclose(out);
    fclose(file);
}