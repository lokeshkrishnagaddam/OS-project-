#include<stdio.h>   
typedef struct 
{ 
      int pid, AT,BT,PR;
      int q, ready; 
}object; 

int main() 
{ 
      int n,i,t, time, j, y; 
      object obj; 
      printf("Enter Total Number of Processes:\t"); 
      scanf("%d",&n);  
      object p[n]; 
      for(i=0;i<n;i++) 
      { 
            printf("\nProcess ID:\t"); 
            scanf("%d", &p[i].pid); 
     }
     for(i=0;i<n;i++)
     {
            printf("Arrival Time: "); 
            scanf("%d", &p[i].AT); 
    }
    for(i=0;i<n;i++)
    {
            printf("Burst Time: "); 
            scanf("%d", &p[i].BT);
	}
	for(i=0;i<n;i++)
	{
            printf("Process Priority: "); 
            scanf("%d", &p[i].PR); 
    }
    int Queue(int A) 
{ 
      if(A==0 || A==1 || A==2 || A==3) 
      { 
            return 1; 
      } 
      else
      {
            return 2; 
      }
}
    for(i=0;i<n;i++)
    {
            t = p[i].PR; 
            p[i].q = Queue(t);
            p[i].ready = 0; 
      }
      time = p[0].BT; 
      for(y=0;y<n;y++) 
      { 
            for(i=y;i<n;i++) 
            { 
                  if(p[i].AT < time) 
                  {
                        p[i].ready = 1; 
                  } 
            } 
            for(i=y;i<n-1;i++) 
            {
                  for(j=i+1; j<n; j++) 
                  { 
                        if(p[i].ready == 1 && p[j].ready == 1) 
                        { 
                              if(p[i].q == 2 && p[j].q == 1) 
                              { 
                                    obj = p[i]; 
                                    p[i] = p[j]; 
                                    p[j] = obj; 
                              } 
                        } 
                  } 
            } 
            for(i=y;i<n-1;i++) 
            { 
                  for(j=i+1;j<n;j++) 
                  {
                        if(p[i].ready==1 && p[j].ready==1) 
                        { 
                              if(p[i].q==1 && p[j].q==1) 
                              { 
                                    if(p[i].BT > p[j].BT) 
                                    { 
                                          obj=p[i]; 
                                          p[i]=p[j]; 
                                          p[j]=obj; 
                                    } 
                                    else 
                                    { 
                                          break; 
                                    } 
                              } 
                        } 
                  } 
            } 
            printf("\nProcess[%d]:\tTime:\t%d To %d\n", p[y].pid, time, time + p[y].BT); 
            time = time + p[y].BT; 
            for(i=y; i<n;i++) 
            { 
                  if(p[i].ready==1) 
                  { 
                        p[i].ready=0; 
                  } 
            } 
      } 
      return 0; 
} 
