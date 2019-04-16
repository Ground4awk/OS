/*Write a program to implement pqity scheduling algorithm with context switching time.
 Prompt to user to enter the number of processes and then enter their pqity, burst time and arrival time also. 
 Now whenever operating system preempts a process and shifts cpu’s control to some another process of higher pqity assume that it takes 2 seconds for context 
 switching(dispatcher latency).Form a scenario, where we can give the processes are assigned with pqity where the lower integer number is higher pqity
  and then context switch .. as the process waits the pqity of the process increase at rate of one per 2 time units of wait. 
Calculate waiting time and turnaround time for each process.
*/
#include<stdio.h>
#include<conio.h>
int main()
{
    int bt[10],pno[10],wt[10],tat[10]; //arrays for burst time, number of processes,waiting time, and turnaround time respectively
    int at[10],pq[10],i,j,nop,tot=0,f,temp,aWt,aTat;//arrays for arrival time and priority queue. Loop variables(i ,j), number of processes, flag, 
													//temporary variable, average waiting time and average turn around time respectively. 
  
  
    printf("Enter the Number of Process:");
    scanf("%d",&nop);
    
	
	printf("\nEnter the Process details\n");
    
	
	for(i=0;i<nop;i++)
    {
    	// taking the burst, time arrival time and priority value from the user.
        printf("\nP[%d]\n",(i+1));
        printf("Enter Burst Time:");
        scanf("%d",&bt[i]);
        printf("Enter Arrival Time:");
        scanf("%d",&at[i]);
        printf("Enter priority:");
        scanf("%d",&pq[i]);
        pno[i]=i+1;
    }
    
    
    for(i=0;i<nop;i++)
    {
        f=i;
        for(j=i+1;j<nop;j++) // sorting the processes according to their priorities
        {
            if(pq[j]<pq[f])
            f=j;
        }
        temp=pq[i];
        pq[i]=pq[f];
        pq[f]=temp;
        temp=bt[i];
        bt[i]=bt[f];   // since the priority queue is being sorted, all the subsequent queues should also be sorted accordingly.
        bt[f]=temp;
        temp=pno[i];
        pno[i]=pno[f];
        pno[f]=temp;
    }
    
    
    wt[0]=0;  
    for(i=1;i<nop;i++)  // calculating the waiting time for each process
    {
        wt[i]=0;
        for(j=0;j<i;j++)
            wt[i]+=bt[j];
        tot+=wt[i];
    }
    aWt=tot/nop;  
    tot=0;
    
    printf("\n\nProcess\t       B T              W T                T A T"); // printing the values in a tabular format
    for(i=0;i<nop;i++)
    {
        tat[i]=bt[i]+wt[i];  
        tot+=tat[i];
        printf("\nProcess %d \t %d\t \t   %d\t\t%d",pno[i],bt[i],wt[i],tat[i]);
    }
      
    aTat=tot/nop; 
    printf("\n\nAverageg Waiting Time = %d",aWt);
    printf("\nAvg Turn Around Time= %d",aTat);
    return 0;
}
