#include<stdio.h>

struct process_str{
    int id, AT, BT, WT, TAT, initial_BT;
};
struct process_str process[100];

// declaration of the ready queue
int queue[100];
int front = -1;
int rear = -1;

// function for insert the element into queue
void insert(int n){
    if(front == -1){
        front = 0;
    }
    rear = rear+1;
    queue[rear] = n;
}

// function for delete the element from queue
int delete(){
    int n;
    n = queue[front];
    front = front+1;
    return n;
}

int main(){
    int n;
    printf("Enter the number of the process: ");
    scanf("%d", &n);
    
    int temp[n], exist[n];
    int TQ, p, TIME = 0;
    float total_wt = 0, total_tat = 0, Avg_WT, Avg_TAT;

    for(int i = 0; i < n; i++) exist[i] = 0;
    
    printf("Enter the arrival time and burst time of the processes: \n");
    for(int i = 0; i < n; i++){
        printf("process%d: ", i+1);
        scanf("%d %d", &process[i].AT, &process[i].BT);
        process[i].id = i+1;
        temp[i] = process[i].BT;
        process[i].initial_BT = process[i].BT;
    }

    printf("Enter the time quantum: ");
    scanf("%d", &TQ);
    
    /* logic for round robin scheduling */

    // insert first process into ready queue
    insert(0);
    exist[0] = 1;

    while(front <= rear){
        p = delete();
        if(process[p].BT >= TQ){
            process[p].BT = process[p].BT-TQ;
            TIME = TIME+TQ;
        }else{
            TIME = TIME + process[p].BT;
            process[p].BT = 0;
        }

        //if process is not exist in the ready queue even a single time then insert it if it arrive 
        //at time 'TIME'
        for(int i = 0; i < n; i++){
            if(exist[i] == 0 && process[i].AT <= TIME){
                insert(i);
                exist[i]=1;
            }
        }
        
        // if process is completed
        if(process[p].BT == 0){
            process[p].TAT = TIME - process[p].AT;
            process[p].WT = process[p].TAT - temp[p];
            total_tat = total_tat + process[p].TAT;
            total_wt = total_wt + process[p].WT;
        }else{
            insert(p);
        }
    }

    Avg_TAT=total_tat/n;
    Avg_WT=total_wt/n;

    // printing table. 
    printf("Processt \t Arrival Time \t Burst Time \t Waiting Time \t Turnaround Time \n");
    for(int i = 0; i < n; i++){
        printf("%d \t\t %d \t\t %d \t\t %d \t\t %d \n", process[i].id, process[i].AT, process[i].initial_BT, process[i].WT, process[i].TAT);
    }

    printf("Average Waiting Time = %f \n",Avg_WT);
    printf("Average Turnaround Time = %f \n",Avg_TAT);

    return 0;
}