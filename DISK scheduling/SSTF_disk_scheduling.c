#include<stdio.h>
#include<stdlib.h>

int main(){
    int RQ[100], Total_Head_Moment = 0, count = 0;
    int initial_head_position;
    int n;

    printf("Enter the number of Requests: ");
    scanf("%d", &n);
    printf("Enter the Requests sequence: ");
    for(int i = 0; i < n; i++){
        scanf("%d", &RQ[i]);
    }

    printf("Enter initial head position: ");
    scanf("%d", &initial_head_position);


    // logic for sstf disk scheduling
    while(count != n){
        int min_distance = 1000, d, index;
        for(int i = 0; i < n; i++){
            d = abs(RQ[i] - initial_head_position);
            if(min_distance > d){
                min_distance = d;
                index = i;
            }
        }
        Total_Head_Moment += min_distance;
        initial_head_position = RQ[index];
        RQ[index] = 1000;
        count++;
    }

    printf("Total head movement is %d\n", Total_Head_Moment);
    return 0;
}