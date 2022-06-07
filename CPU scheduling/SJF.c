#include<stdio.h>

int main(){
    int n;
    printf("Enter number of process:");
    scanf("%d",&n);

    int BT[n], process_ID[n], WT[n], TAT[n];
    float avg_wt, avg_tat;
    
    printf("Enter Burst Time: ");
    for(int i = 0; i < n; i++){
        scanf("%d", &BT[i]);
        process_ID[i]=i+1;         
    }
  
   //sorting of process wrt. to burst time.
    for(int i = 0; i < n; i++){
        int pos = i;
        for(int j = i+1; j < n; j++){
            if(BT[j] < BT[pos])
            pos = j;
        }
  
        int temp = BT[i];
        BT[i] = BT[pos];
        BT[pos] = temp;
  
        temp = process_ID[i];
        process_ID[i] = process_ID[pos];
        process_ID[pos] = temp;
    }
   
   // computing waiting time.
    WT[0] = 0; 
    int total_wt = 0;          
    for(int i = 1; i < n; i++){
        WT[i]=0;
        for(int j = 0; j < i; j++){
            WT[i] += BT[j];
        }
  
        total_wt += WT[i];
    }
    avg_wt = (float)total_wt/n;      
    
    // computing turn around time.
    int total_tat = 0;
    for(int i = 0; i < n; i++){
        TAT[i] = BT[i] + WT[i];   
        total_tat += TAT[i];
    }
    avg_tat = (float)total_tat/n; 
  
    // printing table. 
    printf("Processt \t Burst Time \t Waiting Time \t Turnaround Time \n");
    for(int i = 0; i < n; i++){
        printf("%d \t\t %d \t\t %d \t\t %d \n", process_ID[i], BT[i], WT[i], TAT[i]);
    }

    printf("Average Waiting Time=%f \n",avg_wt);
    printf("Average Turnaround Time=%f \n",avg_tat);

    return 0;
}