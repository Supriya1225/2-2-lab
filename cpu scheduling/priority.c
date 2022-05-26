#include<stdio.h>
 
int main()
{
    int bt[20],p[20],wt[20],tat[20],pr[20],i,j,n,total=0,pos,temp,avg_wt,avg_tat;
    printf("Enter Total Number of Process:");
    scanf("%d",&n);
 
    printf("\nEnter Burst Time and Priority\n");
    printf("Burst Time     Priority");
    for(i=0;i<n;i++)
    {
    
        scanf("%d%d",&bt[i],&pr[i]);
    }
    for(i=0;i<n;i++)
    {
        pos=i;
        for(j=i+1;j<n;j++)
        {
            if(pr[j]<pr[pos])
                pos=j;
        }
 
        temp=pr[i];
        pr[i]=pr[pos];
        pr[pos]=temp;
 
        temp=bt[i];
        bt[i]=bt[pos];
        bt[pos]=temp;
 
        temp=p[i];
        p[i]=p[pos];
        p[pos]=temp;
    }
 
    wt[0]=0;
 
    for(i=1;i<n;i++)
    {
        wt[i]=0;
        for(j=0;j<i;j++)
            wt[i]+=bt[j];
 
        total+=wt[i];
    }
 
    avg_wt=total/n;   
    total=0;
 
    printf("Process    Burst Time    Waiting Time   Turnaround Time\n");
    for(i=0;i<n;i++)
    {
        tat[i]=bt[i]+wt[i];    
        total+=tat[i];
        printf("P[%d]	    %d	            %d		%d\n",p[i],bt[i],wt[i],tat[i]);
    }
 
    avg_tat=total/n;    
    printf("Average Waiting Time=%d\n",avg_wt);
    printf("Average Turnaround Time=%d\n",avg_tat);
    return 0;
 }
 
