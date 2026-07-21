#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    if (argc != 3) exit(-1);

    FILE *source = fopen(argv[1], "rb");
    if (!source) exit(-2);

    FILE *dest = fopen(argv[2], "wb");
    if (!dest) {
        fclose(source);
        exit(-3);
    }

    char buf[1024];
    size_t bytes;

    while ((bytes = fread(buf, 1, 1024, source)) > 0) {
        fwrite(buf, 1, bytes, dest);
    }

    fclose(source);
    fclose(dest);
    return 0;
}
