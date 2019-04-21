#include <stdio.h>
#include <string.h>


#define CONSONANTS "wnjxzqhmdtlbksrpfvgcWNJXZQHMDTLBKSRPFVGC"
#define STRING_SIZE 100


int main() {
    char string[STRING_SIZE];
    char * match;

    fgets(string, STRING_SIZE, stdin);

    for (int i = 0; i < STRING_SIZE; i++) {
        if (string[i] == '\0' || string[i] == '\n') {
            break;
        }

        match = strchr(CONSONANTS, string[i]);

        if (match == NULL) {
            printf("%c", string[i]);
        } else {
            printf("%co%c", string[i], string[i] | ' ');
        }
    }

    printf("\n");

    return 0;
}
