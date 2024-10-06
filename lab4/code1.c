#include <stdio.h>
#include <stdlib.h>

#define TD_CONV 8
#define TD_FG 7
#define TD 6
#define FG 3
#define SFTY 2

#define MAX_COMBO 1000


void score_combo(int score, int td, int fg, int sfty, int td_fg, int td_conv)
{
	int combinations[MAX_COMBO][5];
	int count = 0;

    //loop for providing possible combinations
	for (td_conv = 0; td_conv * TD_CONV <= score; td_conv++) {
        for (td_fg = 0; td_fg * TD_FG <= score - td_conv * TD_CONV; td_fg++) {
            for (td = 0; td * TD <= score - td_conv * TD_CONV - td_fg * TD_FG; td++) {
                for (fg = 0; fg * FG <= score - td_conv * TD_CONV - td_fg * TD_FG - td * TD; fg++) {
                    for (sfty = 0; sfty * SFTY <= score - td_conv * TD_CONV - td_fg * TD_FG - td * TD - fg * FG; sfty++) {
                        if (td_conv * TD_CONV + td_fg * TD_FG + td * TD + fg * FG + sfty * SFTY == score) {
                            combinations[count][0] = td_conv;
                            combinations[count][1] = td_fg;
                            combinations[count][2] = td;
                            combinations[count][3] = fg;
                            combinations[count][4] = sfty;
                            count++;
                        }
                    }
                }
            }
        }
    }

    printf("\nPossible combinations of scoring plays if a team’s score is %d:\n", score);

    for (int i = 0; i < count; i++) {
    	printf("%d TD + 2pt, %d TD + FG, %d TD, %d 3pt FG, %d Safety\n",
    		combinations[i][0], combinations[i][1], combinations[i][2], combinations[i][3], combinations[i][4]);

    }


}


int main()
{
	int score;

	while (1) {
		printf("\nEnter 0 or 1 to STOP");
		printf("\nEnter the NFL score: ");
		scanf("%d", &score);

		if (score <= 1){
			break;
		}
		score_combo(score, 0, 0, 0, 0, 0);
	}
	
	return 0;
}
