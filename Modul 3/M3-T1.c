#include <stdio.h>

int main() {
    int bt[100], wt[100], tat[100], prt[100], prcs[100], i, l, n, temp;
    float wtavg, tatavg;

    printf("\n============================================================================\n");
    printf("\nEnter The Number of Processes : ");
    scanf("%d", &n);
    printf("\n============================================================================\n");

    for(i = 0; i < n; i++) {
        prcs[i] = i + 1;
        printf("\nEnter Burst Time for Process %d : ", i + 1);
        scanf("%d", &bt[i]);
        printf("\nEnter Priority for Process %d : ", i + 1);
        scanf("%d", &prt[i]);
    }

    for(i = 0; i < n; i++) {
        for(l = i + 1; l < n; l++) {
            if(prt[i] > prt[l]) {

                temp = prt[i];
                prt[i] = prt[l];
                prt[l] = temp;

                temp = bt[i];
                bt[i] = bt[l];
                bt[l] = temp;

                temp = prcs[i];
                prcs[i] = prcs[l];
                prcs[l] = temp;
            }
        }
    }

    wt[0] = 0;
    tat[0] = bt[0];
    wtavg = 0;
    tatavg = bt[0];

    for(i = 1; i < n; i++) {
        wt[i] = wt[i - 1] + bt[i - 1];
        tat[i] = wt[i] + bt[i];
        wtavg += wt[i];
        tatavg += tat[i];
    }

    printf("\n============================================================================\n");
    printf("\nPROCESS\tPRIORITY\tBURST TIME\tWAITING TIME\tTURNAROUND TIME\n");
    for(i = 0; i < n; i++) {
        printf("P%d\t\t%d\t\t%d\t\t%d\t\t%d\n", prcs[i], prt[i], bt[i], wt[i], tat[i]);
    }

    printf("\n============================================================================\n");
    printf("\nAverage Waiting Time : %f", wtavg / n);
    printf("\nAverage Turnaround Time : %f\n", tatavg / n);
    printf("\n");

    return 0;
}