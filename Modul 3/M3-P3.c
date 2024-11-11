#include<stdio.h>
int main(){
    int i, j, n, bu[10], wa[10], tat[10], t, ct[10], max;
    float awt = 0, att = 0, temp = 0;

    printf("Enter the number of processes: ");
    scanf("%d", &n);

    for(i = 0; i < n; i++){
        printf("\nEnter Burst Time for process %d: ", i + 1);
        scanf("%d", &bu[i]);
        ct[i] = bu[i];
    }

    printf("\nEnter the size of time slice: ");
    scanf("%d", &t);

    max = bu[0];
    for(i = 1; i < n; i++){
        if (max < bu[i]){
            max = bu[i];
        }
    }
    while(1){
        int done = 1;

        for(i = 0; i < n; i++){
            if (bu[i] > 0){
                done = 0;

                if (bu[i] > t){
                temp += t;
                bu[i] -= t;
                } else {
                    temp += bu[i];
                    tat[i] = temp;
                    bu[i] = 0;
                }
            }
        }

        if (done == 1)
        break;
    }
    for (i = 0; i < n; i++){
        wa[i] = tat[i] - ct[i];
        att += tat[i];
        awt += wa[i];
    }

    printf("\nThe Average Turnaround Time is: %f", att/n);
    printf("\nThe Average Waiting Time is: %f", awt/n);
    printf("\n\n\tPROCESS\tBURST TIME\tWAITING TIME\tTURNAROUND TIME\n");

    for (i = 0; i < n; i++){
        printf("\t%d\t%d\t\t%d\t\t%d\n", i + 1, ct[i], wa[i], tat[i]);
    }
    return 0;
}