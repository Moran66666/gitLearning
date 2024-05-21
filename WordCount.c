#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_LINE 1024

int main(int argc, char *argv[]) {
    if (argc != 3) {
        printf("Usage: %s [-c | -w] [input_file_name]\n", argv[0]);
        return 1;
    }

    FILE *file;
    char line[MAX_LINE];
    int char_c = 0, word_c = 0;
    char *token;

    file = fopen(argv[2], "r");

    if (file == NULL) {
        printf("Error opening file.\n");
        return 1;
    }

    while (fgets(line, MAX_LINE, file)) {
        char_c += strlen(line);

        token = strtok(line, " ,\t\n");
        while (token != NULL) {
            word_c++;
            token = strtok(NULL, " ,\t\n");
        }
    }

    fclose(file);

    if (strcmp(argv[1], "-c") == 0) {
        printf("CharCount:%d\n", char_c);
    } else if (strcmp(argv[1], "-w") == 0) {
        printf("WordCount:%d\n", word_c);
    } else {
        printf("Invalid parameter.\n");
        return 1;
    }

    return 0;
}
