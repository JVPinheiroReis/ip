#include <stdio.h>

int main() {
    int rows, cols;
    int grid[10][10];
    int r, c, i;
    int top, bottom, left, right;

    if (scanf("%d %d", &rows, &cols) != 2) {
        return 0;
    }

    if (rows <= 0 || rows > 10 || cols <= 0 || cols > 10) {
        printf("Dimensao invalida\n");
        return 0;
    }

    for (r = 0; r < rows; r++) {
        for (c = 0; c < cols; c++) {
            scanf("%d", &grid[r][c]);
        }
    }

    top = 0;
    bottom = rows - 1;
    left = 0;
    right = cols - 1;

    while (top <= bottom && left <= right) {
        for (i = left; i <= right; i++) {
            printf("%d ", grid[top][i]);
        }
        top++;

        for (i = top; i <= bottom; i++) {
            printf("%d ", grid[i][right]);
        }
        right--;

        if (top <= bottom) {
            for (i = right; i >= left; i--) {
                printf("%d ", grid[bottom][i]);
            }
            bottom--;
        }

        if (left <= right) {
            for (i = bottom; i >= top; i--) {
                printf("%d ", grid[i][left]);
            }
            left++;
        }
    }

    printf("\n");

    return 0;
}