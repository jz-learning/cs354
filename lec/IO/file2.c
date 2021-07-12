#include <stdio.h>

int main() {
    FILE *fp;

    fp = fopen("bar.txt", "wb");
    int num = 0x123;
    fwrite(&num, sizeof(int), 1, fp);
    fclose(fp);

    fp = fopen("gates_quote.txt", "r");
    // int readNum;
    // fread(&readNum, sizeof(int), 1, fp);
    // printf("readNum = 0x%x\n", readNum);
    // fclose(fp);

    char readChar;
    while (fread(&readChar, sizeof(char), 1, fp)) {
        printf("%c", readChar);
    }

   // printf("\n");


    return 0;
}
