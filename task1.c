#include <stdio.h>

void print_combinations(int score) {
    printf("Possible combinations of scoring plays if a team's score is %d:\n", score);
    
    // Scoring plays:
    // TD + 2pt = 8
    // TD + 1pt FG = 7
    // TD = 6
    // 3pt FG = 3
    // Safety = 2
    for (int td2 = 0; td2 * 8 <= score; td2++) {
        for (int td1 = 0; td2 * 8 + td1 * 7 <= score; td1++) {
            for (int td = 0; td2 * 8 + td1 * 7 + td * 6 <= score; td++) {
                for (int fg = 0; td2 * 8 + td1 * 7 + td * 6 + fg * 3 <= score; fg++) {
                    int remaining = score - (td2 * 8 + td1 * 7 + td * 6 + fg * 3);
                    if (remaining % 2 == 0) {
                        int safety = remaining / 2;
                        printf("%d TD + 2pt, %d TD + FG, %d TD, %d 3pt FG, %d Safety\n",
                               td2, td1, td, fg, safety);
                    }
                }
            }
        }
    }
}

int main(void) {
    int score;

    while (1) {
        printf("Enter the NFL score (Enter 1 to stop): ");
        if (scanf("%d", &score) != 1) {
            while (getchar() != '\n');
            printf("Invalid input. Please enter a valid integer.\n\n");
            continue;
        }

        if (score == 1) {
            break;
        }

        if (score <= 1) {
            printf("Invalid score. Negative scores and scores <= 1 are not valid in this context.\n\n");
            continue;
        }

        print_combinations(score);
        printf("\n");
    }

    return 0;
}
