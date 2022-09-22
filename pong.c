#include <stdio.h>

int main() {
    int TL1 = 2, TL2 = TL1 + 1 , TL3 = TL2+1, TR1 = 2,
    TR2 = TR1 + 1 , TR3 = TR2 + 1 , i, b, xball = 39, yball = 12, score_L = 0,
    score_R = 0;
    int vector_x = 1, vector_y = 1;
    for (i = 1; i < 1e20; i++) {
        for (int y = 1; y <= 26; y++) {
            for (int x = 1; x <= 80; x ++) {
                if (x == 1 && y == 1) {
                    printf("┌");
                } else if (x == 1 && y == 25) {
                    printf("└");
                } else if (x == 80 && y == 1) {
                    printf("┐");
                } else if (x == 80 && y == 25) {
                    printf("┘");
                } else if ((y == 1 || y == 25) && (x != 1)) {
                    printf("─");
                } else if (y >= 0 && y < 25 && (x == 1 || x == 80)) {
                    printf("│");
                } else if (y == yball && x == xball) {
                    printf("O");
                } else if (x == 40) {
                    printf("|");
                } else if (x == 38 && y == 26) {
                    printf("%d", score_L);
                } else if (x == 42 && y == 26) {
                    printf("%d", score_R);
                } else if (TL1 == y && x == 2) {
                    printf("|");
                } else if (TL2 == y && x == 2) {
                    printf("|");
                } else if (TL3 == y && x == 2) {
                    printf("|");
                } else if (TR1 == y && x == 78) {
                    printf("|");
                } else if (TR2 == y && x == 78) {
                    printf("|");
                } else if (TR3 == y && x == 78) {
                    printf("|");
                } else {
                printf(" ");
                }
            }
            printf("\n");
        }
        char enter;
        enter = getchar();
        if (enter == 'a' && TL1 != 2) {
            TL1--;
            TL2--;
            TL3--;
        } else if (enter == 'z' && TL3 != 24) {
            TL1++;
            TL2++;
            TL3++;
        } else if (enter == 'k' && TR1 !=2) {
            TR1--;
            TR2--;
            TR3--;
        } else if (enter == 'm' && TR3 !=24) {
            TR1++;
            TR2++;
            TR3++;
        }
        if (vector_y > 0) {
            yball++;
        }
        if (vector_y < 0) {
            yball--;
        }
        if (vector_x > 0) {
            xball++;
        }
        if (vector_x < 0) {
            xball--;
        }
        if (yball == 2 || yball == 24) {
            vector_y = vector_y * -1;
        }
        if (xball == 80) {
            score_L += 10;
        }
        if (xball == 0) {
            score_R += 10;
        }
        if (xball == 3 && (yball == TL1 || yball == TL2 || yball == TL3)) {
            vector_x = 1;
        if (yball == TL1) {
                vector_y = -1;
        } else if (yball == TL2) {
                vector_y = 0;
        } else if (yball == TR3) {
                vector_y = 1;
            }
        }
        if (xball == 77 && (yball == TR1 || yball == TR2 || yball == TR3)) {
            vector_x = -1;
        if (yball == TR1) {
            vector_y = -1;
        } else if (yball == TR2) {
            vector_y = 0;
        } else if (yball == TR3) {
            vector_y = 1;
        }
        }
        if (xball == 80 || xball == 0) {
            yball = 12;
            xball = 39;
        }
        if (xball == 0) {
            yball = 13;
            xball = 41;
            vector_x = -1;
        }
        if (score_L == 21) {
            printf("\t\t\t\tPLAYER 1 WINS\n");
            break; }
        if (score_R == 21) {
            printf("\t\t\t\tPLAYER 2 WINS\n");
            break; }
    }
}
