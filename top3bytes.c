#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    FILE *fp = fopen(argv[1], "rb");
    if (!fp) {
        perror("fopen");
        return 1;
    }

    int present[256] = {0};
    int c;

    while ((c = fgetc(fp)) != EOF)
        present[c & 0xFF] = 1;

    fclose(fp);

    int top[3] = {0};
    int count = 0;

    for (int i = 255; i >= 0 && count < 3; i--) {
        if (present[i])
            top[count++] = i;
    }

    if (count < 3) {
        fprintf(stderr, "File contains fewer than 3 unique byte values.\n");
        return 1;
    }

    for (int i = 0; i < 3; i++)
        printf("0x%02X\n", top[i]);

    return 0;
}
