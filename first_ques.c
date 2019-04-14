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
void change_waiting_priority(struct process arr[],int n,int waiting,int start){
    for(int i=start;i<n;i++){
        if(arr[i].flag){
                arr[i].waiting_time+=(waiting-arr[i].arrival_time);
                arr[i].flag=false;
        }else{
                arr[i].waiting_time+=(waiting);
        }

        arr[i].priority=(1+((float)arr[i].waiting_time/arr[i].burst_time));
    }
}
void print(struct process a[],int n){
	for(int i=0;i<120;i++)
		printf("-");
	printf("\n");
	printf("|\tProcess id\t|");
	printf("|\tArrival Time\t|");
	printf("|\tBurst Time\t|");
	printf("|\tWaiting Time\t|");
	printf("|\tTurnaround Time\t|\n");
	for(int i=0;i<120;i++)
		printf("-");
	printf("\n");
	int tot_waiting=0,tot_turnaround=0;
	// float avg_waiting=0,tot_waiting=0;
	for(int i=0;i<n;i++){
		struct process demo=a[i];
		for(int j=0;j<n;j++){
			if(a[j].index==i+1){
				demo=a[j];
				break;
			}
		}
		printf("|\t  P%d\t\t|",demo.index);
		printf("|\t  %d\t\t|",demo.arrival_time);
		printf("|\t  %d\t\t|",demo.burst_time);
		printf("|\t  %d\t\t|",demo.waiting_time);
		tot_waiting+=demo.waiting_time;
		printf("|\t  %d\t\t|\n",demo.waiting_time+demo.burst_time);
		tot_turnaround+=(demo.waiting_time+demo.burst_time);
	}
	printf("Average Waiting time %0.2f\n", (float)(tot_waiting)/n);
	printf("Average Turnaround time %0.2f\n",(float)(tot_turnaround)/n);
}
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
        int curr=arr[0].index;
    printf("Order of processes being executed is :\n");
    for(int i=0;i<p_no;i++){
        printf("\t\tP%d\n",curr);
        change_waiting_priority(arr,p_no,arr[i].burst_time,i+1);
        sort(arr,p_no);
        curr=arr[i+1].index;
    }
    printf("\n");
    printf("Printing results for each process\n");
    print(arr,p_no);
    return 0;
}
