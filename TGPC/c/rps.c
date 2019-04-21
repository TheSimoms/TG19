#include <stdio.h>
#include <string.h>


int main() {
    char player_one[6];
    char player_two[6];

    scanf("%s %s", player_one, player_two);

    if (strcmp(player_one, player_two) == 0) {
        printf("Uavgjort, %s vs %s", player_one, player_two);

        return 0;
    }

    int player_one_int = (strcmp(player_one, "stein") == 0) * 1 + (strcmp(player_one, "saks") == 0) * 2 + (strcmp(player_one, "papir") == 0) * 5;
    int player_two_int = (strcmp(player_two, "stein") == 0) * 1 + (strcmp(player_two, "saks") == 0) * 2 + (strcmp(player_two, "papir") == 0) * 5;

    switch (player_one_int - player_two_int) {
        // Stone vs scissors
        case -1:
            printf("Spiller en vant");
            break;
        // Stone vs paper
        case -4:
            printf("Spiller to vant");
            break;
        // Scissors vs stone
        case 1:
            printf("Spiller to vant");
            break;
        // Scissors vs paper
        case -3:
            printf("Spiller en vant");
            break;
        // Paper vs stone
        case 4:
            printf("Spiller en vant");
            break;
        // Paper vs scissors
        case 3:
            printf("Spiller to vant");
            break;
        default:
            break;
    }

    printf(", %s vs %s\n", player_one, player_two);

    return 0;
}
