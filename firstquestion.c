#include<stdio.h>
int main()
 {
   int n,temp,bt[25],awt,at[25],atat,i,j,lokesh,TQ;
   int p[25],py[25],w[25],t[25];
   printf("Enter the number of process : ");
   scanf("%d",&n);
   
   printf("\n\t Priorities :\n");
   for(i=0;i<n;i++)
    {
      printf("\n Process %d ",i+1);
      scanf("%d",&py[i]);
	  p[i]=i+1;
    }
    
   printf("\n\t Enter Burst time :\n"); 
   for(i=0;i<n;i++)
    {
      printf("\n Process %d ",i+1);
      scanf("%d",&bt[i]);
	  p[i]=i+1;
    }

    printf("\n\t Enter Arrival time  \n");
    for(i=0;i<n;i++)
    {
      printf("\n Process %d ",i+1);
      scanf("%d",&at[i]);
	  p[i]=i+1;
    }
    printf("Enter time quantum");
   scanf("%d",&TQ);
  for(i=0;i<n-1;i++)
   {
     for(j=i+1;j<n;j++)
     {
       if(py[i]<py[j])
       {
     temp=py[i];
     py[i]=py[j];
     py[j]=temp;
     temp=bt[i];
     bt[i]=bt[j];
     bt[j]=temp;
     temp=p[i];
     p[i]=p[j];
     p[j]=temp;
      }
   }
}
w[0]=0;
awt=0;
t[0]=bt[0];
atat=t[0];
for(i=1;i<n;i++)
 {
 	if(TQ<n || TQ>n)
	  {
   w[i]=t[i-1];
   awt+=w[i];
   t[i]=w[i]+bt[i];
   atat+=t[i];
	 }
 }
printf("\n\nProcess \t Burst Time \t Wait Time \t Turn Around Time   Priority \tArrival time \n");
for(i=0;i<n;i++)
{
printf("\n  %d",p[i]); printf("\t\t %d",bt[i]); printf("\t\t %d",w[i]); printf("\t\t %d",t[i]); printf("\t\t %d",py[i]); printf("\t\t %d",at[i]);
}
awt/=n;
atat/=n;
printf("\n Average Wait Time : %d ",awt);
printf("\n Average Turn Around Time : %d",atat);
 printf("\n");
 printf("Gantt chart\n");
 for(i=0;i<n;i++)
 {
 	printf("P%d ",p[i]);
 }
 lokesh=bt[0]+bt[1]+bt[2]+bt[3]+bt[4]+bt[5];
 printf("cpu maximun utilization rate is: %d",lokesh);
}
