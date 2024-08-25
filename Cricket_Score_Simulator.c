#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void playInnings(char teamName[], int *totalScore, int *totalOvers ,int score1) {
    int run, batsman_score = 0, i, wicket_strike = 1, batsman_faced, wicket = 0, team_score = 0, ball_count = 0, over_count = 0;
    char batsman_name[55];
    float ovr, RR;

    srand(time(NULL));
    printf("\n\nInnings of %s\n\n", teamName);

    for (i = 0; ball_count < 120 && wicket<10; i++) {
        printf("Enter Batsman name: ");
        scanf("%[^\n]%*c", batsman_name);
        printf("Timeline - ");
        
        for(batsman_faced=0;wicket_strike<3;batsman_faced++){
            run = rand() % 7;
            switch (run) {
                case 0:
                    if (wicket_strike == 3) {
                        printf("Wicket!");
                    } else {
                        printf("Byes ");
                        wicket_strike++;
                    }
                    ++ball_count;
                    break;
                
                case 1:
                    printf("1 ");
                    batsman_score += 1;
                    ++ball_count;
                    break;
                
                case 2:
                    printf("2 ");
                    batsman_score += 2;
                    ++ball_count;
                    break;
                
                case 4:
                    if(wicket<8){
                        printf("Four ");
                        batsman_score += 4;
                    }
                    ++ball_count;
                    break;
                
                case 6:
                    if (over_count >= 9 && over_count <= 14 || wicket>7) {
                        printf("Dot ");
                    } else {
                        printf("Six ");
                        batsman_score += 6;
                    }
                    ++ball_count;
                    break;
                
                default:
                    printf("Dot ");
                    ++ball_count;
                    break;
            }
            if(batsman_score+team_score>score1 && score1!=0){
                team_score += batsman_score;
                printf("\n\n%s = %d/%d\n",teamName, team_score, ++wicket);
                ovr = (float) ball_count / 6;
                printf("Overs (%.1f)\n", ovr);
                RR = (float) team_score / ovr;
                printf("Run Rate : %.2f\n", RR);
                printf("%s - %d(%d)\n\n",batsman_name , batsman_score, batsman_faced);
                 printf("\n%s won the match by %d wickets.\n", teamName,10-wicket);
                 exit(1);
            }
            
            if (ball_count % 6 == 0) {
                printf(" ||End of %d over|| ", ++over_count);
                if (over_count == 20) {
                    break;
                }
            }
        }

        team_score += batsman_score;
        printf("\n\n%s = %d/%d\n",teamName, team_score, ++wicket);
        ovr = (float) ball_count / 6;
        printf("Overs (%.1f)\n", ovr);
        RR = (float) team_score / ovr;
        printf("Run Rate : %.2f\n", RR);
        printf("%s - %d(%d)\n\n",batsman_name , batsman_score, batsman_faced);
        
        /*if (batsman_faced == 10) {
            break;
        }*/
        
        batsman_score = 0;
        wicket_strike = 1;
    }

    *totalScore = team_score;
    *totalOvers = ball_count;
    printf("End of the Innings for %s\n", teamName);
}

int main() {
    char team1[55], team2[55];
    int score1=0, score2=0, overs1, overs2;
    printf("Enter Home Team: ");
    scanf("%[^\n]%*c", team1);
    printf("Enter Away Team: ");
    scanf("%[^\n]%*c", team2);
    printf("Who is Batting First\n");
    printf("Enter\n1.%s\n2.%s\n",team1,team2);
    int toss;
    scanf("%d",&toss);
    char nul;
    scanf("%c",&nul);
    if(toss==2){
        printf("\nFirst Innings\n");
        playInnings(team2, &score1, &overs1,score1);
        printf("\n%s scored %d runs in %d overs.\n", team2, score1, overs1/6);

        printf("\nSecond Innings\n");
        playInnings(team1, &score2, &overs2,score1);
        printf("\n%s scored %d runs in %d overs.\n", team1, score2, overs2/6);
    }else if(toss==1){
        printf("\nFirst Innings\n");
        playInnings(team1, &score1, &overs1,score1);
        printf("\n%s scored %d runs in %d overs.\n", team1, score1, overs1/6);

        printf("\nSecond Innings\n");
        playInnings(team2, &score2, &overs2,score1);
        printf("\n%s scored %d runs in %d overs.\n", team2, score2, overs2/6);
    }else{
        printf("Invalid!");
        return 0;
    }
    if (score1 > score2) {
        printf("\n%s won the match by %d runs.\n", team1, score1 - score2);
    } else if (score2 > score1) {
        printf("\n%s won the match by %d wickets.\n", team2, 10 - (overs2 / 6));
    } else {
        printf("\nThe match is a tie.\n");
    }

    return 0;
} 
