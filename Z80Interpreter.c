#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

// Main file for reading a hex dump of (hopefully) Z80 Assembly code: https://www.grimware.org/doku.php/documentations/devices/z80
// Other info: http://www.z80.info/

int main(int argc, char *argv[]) {
    FILE *file;
    int fd;
    unsigned char opcode;
    int set;
    // printf("Hello World\r\n");
    if (argc > 1)
    {
        // printf("%s\r\n", argv[1]);
        file = fopen(argv[1], "rb");
        while (fread(&opcode, sizeof opcode, 1, file) != 0)
        {
            switch (opcode)
            {
                case 0:
                    printf("NOP\r\n");
                    break;
                default:
                    printf("%2X\r\n", opcode);

            }
        }
        fclose(file);
    }
    else
        printf("Error: No file available\r\n");
}