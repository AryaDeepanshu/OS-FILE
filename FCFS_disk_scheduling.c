#include<stdio.h>
#include<stdlib.h>

int main(){
    int RQ[100], Total_Head_Moment = 0;
    int initial_head_position;
    int n;
    
    printf("Enter the number of Requests: ");
    scanf("%d",&n);
    
    printf("Enter the Requests sequence: ");
    for(int i  =0; i<  n; i++){
        scanf("%d", &RQ[i]);
    }

    printf("Enter initial head position: ");
    scanf("%d", &initial_head_position);

    // logic for FCFS disk scheduling
    for(int i = 0; i < n; i++){
        Total_Head_Moment += abs(RQ[i]-initial_head_position);
        initial_head_position = RQ[i];
    }

    printf("Total head moment is %d.\n", Total_Head_Moment);
    return 0;
}
