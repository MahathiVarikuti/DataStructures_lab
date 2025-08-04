#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void beep() {
    printf("\a"); // Beep sound
}

void conductElection(int num_students, int num_candidates, char candidates[][50]) {
    int *votes = (int *)calloc(num_candidates, sizeof(int));
    int foul_votes = 0;

    printf("Election started. Enter candidate number to vote:\n");
    for (int i = 0; i < num_students; i++) {
        int vote;
        printf("Student %d, enter your vote: ", i + 1);
        scanf("%d", &vote);
        if (vote >= 1 && vote <= num_candidates) {
            votes[vote - 1]++;
        } else {
            foul_votes++;
        }
        beep();
    }

    printf("\nElection Results:\n");
    for (int i = 0; i < num_candidates; i++) {
        printf("%s: %d votes\n", candidates[i], votes[i]);
    }
    printf("Foul votes: %d\n", foul_votes);

    int max_votes = 0;
    int winner = -1;
    for (int i = 0; i < num_candidates; i++) {
        if (votes[i] > max_votes) {
            max_votes = votes[i];
            winner = i;
        }
    }

    if (winner != -1) {
        printf("Class Representative: %s\n", candidates[winner]);
    } else {
        printf("No valid votes cast.\n");
    }

    free(votes);
}

int main() {
    int num_students, num_candidates;
    printf("Enter the number of students (voters): ");
    scanf("%d", &num_students);
    printf("Enter the number of candidates: ");
    scanf("%d", &num_candidates);

    char candidates[num_candidates][50];
    for (int i = 0; i < num_candidates; i++) {
        printf("Enter name of candidate %d: ", i + 1);
        scanf("%s", candidates[i]);
    }

    conductElection(num_students, num_candidates, candidates);

    return 0;
}
