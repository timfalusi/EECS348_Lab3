#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TD 6
#define TDP 7
#define TDC 8
#define FG 3
#define SF 2

void print_combinations(int score);

int main() {
    int score = 2;

    while (score > 1) {
        printf("Enter 0 or 1 to stop combination generator\n");
        printf("Enter a Football score: ");
        scanf("%d", &score);
        printf("Possible scoring combinations for this score:\n");
        print_combinations(score);

    }

    return 0;

}

 

void print_combinations(int score) {
    for (int i = 0; i <= score; i++) {
        for (int k = 0; k <= score; k++) {
            for (int l = 0; l <= score; l++) {
                for (int m = 0; m <= score; m++) {
                    for (int n = 0; n <= score; n++) {
                        if (score == (i * TDC + k * TDP + l * TD + m * FG + n * SF)) {
                            printf("%d touchdown + 2pt, %d touchdown + FG, %d touchdown, %d FG 3pts, %d Safety\n", i, k, l, m, n);
                        }
                    }
                }
            }
        }
    }
}