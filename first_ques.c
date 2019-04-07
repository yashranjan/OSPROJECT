#include <stdio.h>
#include <stdbool.h>
struct process{
    int index;
    int arrival_time,burst_time,waiting_time;
    float priority;
    bool flag;
};
int main(int argc, char const *argv[]) {
    printf("Enter number of process\n");
    int p_no;
    scanf("%d",&p_no);
    struct process arr[p_no];
    for(int i=0;i<p_no;i++){
            arr[i].priority=1;
            arr[i].waiting_time=0;
            arr[i].index=i+1;
            arr[i].flag=true;
    }
    int at,bt;
    for(int i=0;i<p_no;i++){
        printf("For process %d:\n",i+1);
        printf("Enter arrival time and burst time:\n");
        scanf("%d %d",&at,&bt);
        arr[i].arrival_time=at;
        arr[i].burst_time=bt;
    }
    sort(arr,p_no); //Implement sort function
    print_waiting_burst(arr,p_no); //Display final answer for each process
    return 0;
}