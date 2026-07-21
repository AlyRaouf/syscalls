#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    if (argc != 3) return 1;

    FILE *source = fopen(argv[1], "rb");
    if (!source) return 1;

    FILE *dest = fopen(argv[2], "wb");
    if (!dest) {
        fclose(source);
        return 1;
    }

    char buffer[4096];
    size_t bytes;

    while ((bytes = fread(buffer, 1, sizeof(buffer), source)) > 0) {
        fwrite(buffer, 1, bytes, dest);
    }

    fclose(source);
    fclose(dest);
    return 0;
}
