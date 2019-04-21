#include <stdio.h>
#include <stdlib.h>


int main() {
    int occurences[26] = {0};
    int count = 0;

    int character;

    while(1) {
        // Read character
        character = getchar();

        // Break on newline
        if(character == '\n') {
            break;
        }

        int index = character - 'a';

        if(occurences[index] == 0) {
            occurences[index] = 1;

            count++;
        }
    }

    printf("%d\n", count);

    return 0;
}
