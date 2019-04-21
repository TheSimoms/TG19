#include <stdio.h>
#include <ctype.h>


int main() {
    char c = getchar();

    while(c != '\n') {
        // Convert to lowercase and increment by 3
        c = tolower(c);
        c += 3;

        if (c > 122) {
            c -= 26;
        }

        putchar(c);

        c = getchar();
    }

    putchar('\n');

    return 0;
}
