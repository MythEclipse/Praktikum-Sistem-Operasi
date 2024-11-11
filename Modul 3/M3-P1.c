#include <stdio.h>
#include <conio.h>
int main()
{
    int bt[20], wt[20], tat[20], i, n;
    float wtavg, tatavg;
    // Input jumlah proses
    printf("\nEnter the number of processes -- ");
    scanf("%d", &n);
    // Input burst time untuk setiap proses
    for (i = 0; i < n; i++)
    {
        printf("\nEnter Burst Time for Process %d -- ", i);
        scanf("%d", &bt[i]);
    }
    // Inisialisasi waktu tunggu dan turnaround
    wt[0] = 0;
    wtavg = 0;
    tat[0] = bt[0];
    tatavg = bt[0];
    // Hitung rata-rata waktu tunggu dan turnaround
    for (i = 0; i < n; i++)
    {
        wt[i] = wt[i - 1] + bt[i - 1];
        tat[i] = tat[i - 1] + bt[i];
        wtavg+= wt[i];
        tatavg+= tat[i];
    }

    // Tampilkan hasil
    printf("\n\tPROCESS\tBURST TIME\tWAITING TIME\tTURNAROUND TIME\n");
    for (i = 0; i < n; i++)
    {
        printf("\n\tP%d\t\t%d\t\t%d\t\t%d", i, bt[i], wt[i], tat[i]);
    }

    printf("\n\nAverage Waiting Time --- %f", wtavg / n);
    printf("\nAverage Turnaround Time --- %f", tatavg / n);

    getch();
    return 0;
}
