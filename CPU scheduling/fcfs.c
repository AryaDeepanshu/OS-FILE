#include<stdio.h>

int main(){
    int n;
    printf("Enter number of the process : ");
    scanf("%d",&n);
    int AT[n], BT[n], WT[n], TAT[n], CT[n];
    float Avg_WT, Avg_TT, Total_T = 0;

    printf("Enter Arrival time and Burst time of the process :\n");
    for(int i = 0; i < n; i++){
        scanf("%d %d", &AT[i], &BT[i]);
    }

    // Logic for calculating Waiting time.
    int burst_T = 0;
    for(int i = 0;i < n; i++){
        if(i == 0) WT[i] = AT[i];
        else WT[i] = burst_T-AT[i];
        burst_T += BT[i];
        Total_T += WT[i];
    }
    Avg_WT = Total_T/n;

    // Logic for calculating Completion time.
    CT[0] = BT[0];
    for(int i = 1; i < n; i++){
        CT[i] = BT[i] + CT[i-1];
    }

    // Logic for calculating Turn around time
    Total_T = 0;
    for(int i = 0; i < n; i++){
        TAT[i] = CT[i]-AT[i];
        Total_T += TAT[i];
    }
    Avg_TT = Total_T/n;

    // printing of outputs
    printf("Process \t Burst_time \t Arrival_time \t Waiting_time \t Turn_around_time \t completion_time \t \n");
    for(int i = 0;i < n;i++){
        printf("%d \t\t %d \t\t %d \t\t %d \t\t %d \t\t\t %d \n",i+1, BT[i], AT[i], WT[i], TAT[i], CT[i]);
    }
    
    printf("Average waiting time is : %f\n",Avg_WT);
    printf("Average turn around time is : %f\n",Avg_TT);
    return 0;
}
