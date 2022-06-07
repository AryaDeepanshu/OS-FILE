#include<stdio.h>
#include<stdlib.h>
int main(){
    int RQ[100], Total_Head_Moment = 0;
    int initial_head_position;
    int size,move;
    int n, i;

    printf("Enter the number of Requests: ");
    scanf("%d", &n);

    printf("Enter the Requests sequence: ");
    for(i = 0; i < n; i++){
        scanf("%d",&RQ[i]);
    }

    printf("Enter initial head position\n");
    scanf("%d", &initial_head_position);

    printf("Enter total disk size: ");
    scanf("%d",&size);
    
    printf("Enter the head movement direction for high 1 and for low 0: ");
    scanf("%d",&move);

    // logic for Scan disk scheduling

    /*logic for sort the request array */
    for(i = 0; i < n; i++){
        for(int j = 0; j < n-i-1; j++){
            if(RQ[j] > RQ[j+1]){
                int temp = RQ[j];
                RQ[j] = RQ[j+1];
                RQ[j+1] = temp;
            }
        }
    }

    int index;
    for(i = 0; i < n; i++){
        if(initial_head_position < RQ[i]){
            index=i;
            break;
        }
    }

    // if movement is towards high value
    if(move == 1){
        for(i = index; i < n; i++){
            Total_Head_Moment += abs(RQ[i]-initial_head_position);
            initial_head_position = RQ[i];
        }
        
        //  last movement for max size 
        Total_Head_Moment += abs(size-RQ[i-1]-1);
        initial_head_position = size-1;
        
        for(i=index-1;i>=0;i--){
            Total_Head_Moment += abs(RQ[i]-initial_head_position);
            initial_head_position = RQ[i];
        }
    }
    else{ // move == 0
        for(i = index-1; i >= 0; i--){
            Total_Head_Moment += abs(RQ[i]-initial_head_position);
            initial_head_position = RQ[i];
        }

        //  last movement for min size 
        Total_Head_Moment += abs(RQ[i+1]-0);
        initial_head_position =0;
        
        for(i=index;i<n;i++){
            Total_Head_Moment += abs(RQ[i]-initial_head_position);
            initial_head_position = RQ[i];
        }
    }

    printf("Total head movement is %d\n", Total_Head_Moment);
    return 0;
}
