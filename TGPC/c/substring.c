#include <stdio.h>
#include <string.h>


#define STRING_SIZE 100000


void find_longest_common_substring(char* a, char* b, int a_len, int b_len) {
    int common_matrix[a_len + 1][b_len + 1];
    int common_length = 0;
    int common_index = 0;

    for (int i = 0; i <= a_len; i++) {
        for (int j = 0; j <= b_len; j++) {
            if (i == 0 || j == 0) {
                common_matrix[i][j] = 0;
            } else if (a[i - 1] == b[j - 1]) {
                common_matrix[i][j] = common_matrix[i - 1][j - 1] + 1;

                if (common_matrix[i][j] > common_length) {
                    common_length = common_matrix[i][j];
                    common_index = i;
                }
            } else {
                common_matrix[i][j] = 0;
            }
        }
    }

    if (common_length == 0) {
        printf("None");
    } else {
        for (int i = common_index - common_length; i < common_length; i++) {
            printf("%c", a[i]);
        }
    }

    printf("\n");
}


void split_strings(int split_factor, char* input, char* a, char* b) {
    int input_length = strlen(input);

    int a_index = 0;
    int b_index = 0;
    int string_index = 1;

    for (int i = 0; i < input_length; i++){
        if (i % split_factor == 0) {
            string_index++;
            string_index %= 2;
        }

        char character = input[i];

        if (string_index == 0) {
            a[a_index] = character;

            a_index++;
        } else {
            b[b_index] = character;

            b_index++;
        }
    }
}


int main() {
    int split_factor;
    char input[STRING_SIZE];

    scanf("%d\n%s\n", &split_factor, input);

    char* a;
    char* b;

    split_strings(split_factor, input, a, b);

    printf("%s", a);
    printf("%s", b);

    int a_len = strlen(a);
    int b_len = strlen(b);

    //find_longest_common_substring(a, b, a_len, b_len);

    return 0;
}
