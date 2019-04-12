#include <stdio.h>
#include <stdbool.h>
struct process{
    int index;
    int arrival_time,burst_time,waiting_time;
    float priority;
    bool flag;
};
void swap(struct process *first,struct process *second){
    int a,b,c;
    float d;
    int e;
    a=first->arrival_time;
    b=first->burst_time;
    c=first->waiting_time;
    d=first->priority;
    e=first->index;
    first->arrival_time=second->arrival_time;
    first->burst_time=second->burst_time;
    first->waiting_time=second->waiting_time;
    first->priority=second->priority;
    first->index=second->index;
    second->arrival_time=a;
    second->burst_time=b;
    second->waiting_time=c;
    second->priority=d;
    second->index=e;
}
void swap_n(struct process *first,struct process second){
    second.arrival_time=first->arrival_time;
    second.burst_time=first->burst_time;
    second.waiting_time=first->waiting_time;
    second.priority=first->priority;
    second.index=first->index;
}
void sort(struct process arr[],int n){
    for(int i=1;i<n;i++){
        struct process obj=arr[i];
        int j=i-1;
        while(j>=0&&arr[j].priority>=obj.priority){
            if(arr[j].priority==obj.priority){
                if(arr[j].arrival_time>obj.arrival_time){
                    swap(&arr[j],&arr[j+1]);
                }
            }else{
                swap(&arr[j],&arr[j+1]);
            }
            j--;
        }
        swap_n(&arr[j+1],obj);
    }
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
    sort(arr,p_no);
    print_waiting_burst(arr,p_no); //Display final answer for each process
    return 0;
}
