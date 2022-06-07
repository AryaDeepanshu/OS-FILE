#include<stdio.h>

int main(){
    int n;
    printf("Enter Total Number of Process:");
    scanf("%d", &n);
    int BT[n], process_ID[n], WT[n], TAT[n], priority[n];
 
    printf("Enter Burst Time and Priority:\n");
    for(int i = 0; i < n; i++){
        printf("Forprocess %d:", i+1);
        scanf("%d %d", &BT[i], &priority[i]);
        process_ID[i] = i+1;         
    }
 
    //sorting burst time, priority and process number in ascending order using selection sort
    for(int i = 0; i < n; i++){
        int pos = i;
        for(int j = i+1; j < n; j++){
            if(priority[j] < priority[pos])
                pos = j;
        }
 
        int temp = priority[i];
        priority[i] = priority[pos];
        priority[pos] = temp;
 
        temp = BT[i];
        BT[i] = BT[pos];
        BT[pos] = temp;
 
        temp = process_ID[i];
        process_ID[i] = process_ID[pos];
        process_ID[pos] = temp;
    }
 
    //calculate waiting time
    WT[0]=0;
    int total_wt = 0;
    for(int i = 1; i < n; i++){
        WT[i] = 0;
        for(int j = 0; j < i; j++)
            WT[i] += BT[j];
 
        total_wt += WT[i];
    }
 
    int avg_wt;
    avg_wt = total_wt/n;

    //calculate turnaround time
    int total_tat=0;
    for(int i = 0; i < n; i++){
        TAT[i] = BT[i] + WT[i];     
        total_tat += TAT[i];
    }
    
    int avg_tat;
    avg_tat = total_tat/n;
    printf("Process \t priority \t Burst Time \t Waiting Time \t Turnaround Time \n");
    for(int i = 0; i < n; i++){
        printf("P[%d] \t\t %d \t\t %d \t\t %d \t\t %d \n",process_ID[i], priority[i] ,BT[i], WT[i], TAT[i]);
    }
    
    printf("Average Waiting Time = %d \n",avg_wt);
    printf("Average Turnaround Time = %d \n",avg_tat);
 
    return 0;
}
