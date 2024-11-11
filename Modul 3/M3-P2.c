#include<stdio.h>
#include<conio.h>

int main() {
	int p[20], bt[20], wt[20], tat[20], i, k, n, temp;
	float wtavg, tatavg;
	
	printf("\nEnter The Number of Processes -- ");
	scanf("%d", &n);
	
	for(i = 0; i < n; i++) {
		p[i] = i;
		printf("\nEnter burst time for Process %d -- ", i);
		scanf("%d", &bt[i]);
	}
	
	for(i = 0; i < n; i++)
		for(k = i + 1; k < n; k++)
			if(bt[i] > bt[k]) {
				
				temp = bt[i];
				bt[i] = bt[k];
				bt[k] = temp;

			}
			
	wt[0] = wtavg = 0;
	tat[0] = tatavg = bt[0];
	
	for(i = 1; i < n; i++) {
		wt[i] = wt[i-1] + bt[i-1];
		tat[i] = wt[i] + bt[i];
		wtavg = wtavg + wt[i];
		tatavg = tatavg + tat[i];
	}
	
	printf("\n\t PROCESS \t BURST TIME \t WAITING TIME \t TURN AROUND TIME \n");
	for(i = 0; i < n; i++)
		printf("\n\t p%d \t\t %d \t\t %d \t\t %d", p[i], bt[i], wt[i], tat[i]);
		
	printf("\n\nAverage Waiting Time -- %f", wtavg/n);
	printf("\nAverage Turn Around Time -- %f", tatavg/n);
	
	getch();
}