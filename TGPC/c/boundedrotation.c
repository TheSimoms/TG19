#include <stdio.h>
#include <stdlib.h>


#define min(x, y) (y ^ ((x ^ y) & -(x < y)))
#define max(x, y) (x ^ ((x ^ y) & -(x < y)))


int main() {
    int n;
    int x, y;

    scanf("%d", &n);

    int xMin = 0, xMax = -1000, yMin = 0, yMax = -1000;

    for (int i = 0; i < n; i++) {
        scanf("%d %d", &x, &y);

        xMin = min(xMin, x);
        xMax = max(xMax, x);
        yMin = min(yMin, y);
        yMax = max(yMax, y);
    }

    printf("%d\n", abs(xMin - xMax) * abs(yMin - yMax));

    return 0;
}
