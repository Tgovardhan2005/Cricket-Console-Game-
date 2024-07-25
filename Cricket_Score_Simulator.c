#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void playInnings(char teamName[], int *totalScore, int *totalOvers) {
    int ball, ballsum = 0, i, count = 0, j, l = 1, ts = 0, over = 0, w = 0;
    char name[55];
    float ovr, RR;

    srand(time(NULL));

    printf("\n\nInnings of %s\n\n", teamName);

    for (i = 0; over < 120; i++) {
        printf("Enter Batsman name: ");
        scanf("%s", name);
        printf("Timeline - ");

        for (j = 0; count < 3; j++) {
            ball = rand() % 7;
            switch (ball) {
                case 0:
                    if (count == 3) {
                        printf("Wicket!");
                        ++over;
                    } else {
                        printf("Byes ");
                        count++;
                        ++over;
                    }
                    break;
                
                case 1:
                    printf("1 ");
                    ballsum += 1;
                    ++over;
                    break;
                
                case 2:
                    printf("2 ");
                    ballsum += 2;
                    ++over;
                    break;
                
                case 4:
                    printf("Four ");
                    ballsum += 4;
                    ++over;
                    break;
                
                case 6:
                    if (w >= 9 && w <= 14) {
                        printf("Dot ");
                    } else {
                        printf("Six ");
                        ballsum += 6;
                    }
                    ++over;
                    break;
                
                default:
                    printf("Dot ");
                    ++over;
                    break;
            }
            
            if (over % 6 == 0) {
                printf(" ||End of %d over|| ", ++w);
                if (w == 20) {
                    break;
                }
            }
        }

        ts += ballsum;
        printf("\n\nTeamscore = %d/%d\n", ts, l++);
        ovr = (float) over / 6;
        printf("Overs (%.1f)\n", ovr);
        RR = (float) ts / ovr;
        printf("Run Rate : %.2f\n", RR);
        printf("%s - %d(%d)\n\n", name, ballsum, j);
        
        if (j == 10) {
            break;
        }
        
        ballsum = 0;
        count = 0;
    }

    *totalScore = ts;
    *totalOvers = over;
    printf("End of the Innings for %s\n", teamName);
}

int main() {
    char team1[55], team2[55];
    int score1, score2, overs1, overs2;

    printf("Enter the name of Team 1: ");
    scanf("%s", team1);
    printf("Enter the name of Team 2: ");
    scanf("%s", team2);

    printf("\nFirst Innings\n");
    playInnings(team1, &score1, &overs1);
    printf("\n%s scored %d runs in %d overs.\n", team1, score1, overs1/6);

    printf("\nSecond Innings\n");
    playInnings(team2, &score2, &overs2);
    printf("\n%s scored %d runs in %d overs.\n", team2, score2, overs2/6);

    if (score1 > score2) {
        printf("\n%s won the match by %d runs.\n", team1, score1 - score2);
    } else if (score2 > score1) {
        printf("\n%s won the match by %d wickets.\n", team2, 10 - (overs2 / 6));
    } else {
        printf("\nThe match is a tie.\n");
    }

    return 0;
}
