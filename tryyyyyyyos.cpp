#include<stdio.h>
#include<conio.h>
int main()
{
  
  long int n,i=0,j=0,pos;
  printf("Enter Number of Processes : ");
  scanf("%ld",&n ); 
  if(n==0)
  {
  	printf("Please enter a valid input\n:");
  	printf("Enter Number of Processes : ");
  	scanf("%ld",&n ); 
  }
  
  double priority[n],avg_waiting,avg_turnaround,burstTime[n],arrivalTime[n],waitingTime[n],turnaroundTime[n], process[n], temp, completionTime[n],min,sum=0,sum2=0,wait_final, turnaround_final, wait_avg, turnaround_avg;
  for(i=0;i<n;i++)
  {
    printf("\n\nEnter Burst Time for P%d : ", i+1 );
    scanf("%lf", &burstTime[i]);
    printf("Enter Arrival Time for P%d : ", i+1 );
    scanf("%lf", &arrivalTime[i] );
    process[i]=i+1;
  }


  printf("\n\n\t\tTHE ENTERED VALUES ARE\n\n");

  for(i=0;i<n;i++)
  {
    for(j=0;j<n;j++)
    {
      if(arrivalTime[i]<arrivalTime[j])
      {
        
        temp = burstTime[j];
        burstTime[j] = burstTime[i];
        burstTime [i] = temp;
	
	      temp = process[j];
        process[j] = process[i];
        process[i] = temp;

	      temp = arrivalTime[j];
        arrivalTime[j] = arrivalTime[i];
        arrivalTime[i] = temp;
      
      }
    }
  }
  printf(" Process \t\tArrival Time \t\t\tBurst Time \n");
  for(i=0;i<n;i++)
  {
    printf(" P%0.0lf \t\t\t\t%0.0lf  \t\t\t\t%0.0lf      \n",process[i],arrivalTime[i],burstTime[i]);
  }

/*Arranging the table according to Burst time,
Execution time and Arrival Time*/


  long int k = 1;
  double b_time = 0;
  for(j=0;j<n;j++)
  {
    b_time = b_time + burstTime[j];
    min = burstTime[k];

    for(i=k;i<n;i++)
    {
      if((b_time >= arrivalTime[i])&&(burstTime[i]<min))
      {
        temp = burstTime[k];
        burstTime[k] = burstTime[i];
        burstTime[i] = temp;

        temp = arrivalTime[k];
        arrivalTime[k] = arrivalTime[i];
        arrivalTime[i] = temp;

        temp = process[k];
        process[k] = process[i];
        process[i] = temp;
      }
    }
    k++;
  }
  waitingTime[0] = 0;
  for(i=1;i<n;i++)
  {
    sum += burstTime[i-1];
    waitingTime[i] = sum - arrivalTime[i];
    wait_final += waitingTime[i]; 
  }
  wait_avg = wait_final/n;
  for(i=0;i<n;i++)
  {
    sum2 += burstTime[i];
    turnaroundTime[i] = sum2 - arrivalTime[i];
    turnaround_final += turnaroundTime[i];
  }
  turnaround_avg=turnaround_final/n;
 
 
  
  completionTime[0] = burstTime[0];
  for(i=1;i<n;i++)
  {
    completionTime[i] = completionTime[i-1] + burstTime[i];
  }

  for(i=0;i<n;i++)
  {
    priority[i] = 1+(waitingTime[i]/completionTime[i]);
  }
  printf("\n\n\t\tASSGNING PRIORITY TO EACH PROCESS(BEFORE ARRANGEMENT)\n\n");
  
  printf("Process  Arrival Time  Burst Time   Waiting Time    TurnAround Time      Priority \n");
  for(i=0;i<n;i++)
  {
    printf("P%0.0lf         %0.0lf          %0.0lf             %0.0lf               %0.0lf     \t\t %lf    \n",process[i],arrivalTime[i],burstTime[i],waitingTime[i],turnaroundTime[i],priority[i]);
  }

  
  printf("\nsorting process according to their priority:");
  for(i=0;i<n;i++)
    {
        pos=i;
        for(j=i+1;j<n;j++)
        {
            if(priority[j]>priority[pos])
            {
				    pos=j;
 			}
        	
		}
			temp=priority[i];
       		priority[i]=priority[pos];
        	priority[pos]=temp;
 
        	temp=burstTime[i];
        	burstTime[i]=burstTime[pos];
        	burstTime[pos]=temp;
        	
        	temp=process[i];
        	process[i]=process[pos];
        	process[pos]=temp;
			
			temp=arrivalTime[i];
			arrivalTime[i]=arrivalTime[pos];
			arrivalTime[pos]=temp;	
    			
	}
	  waitingTime[0] = 0;
	  sum=0;
	  sum2=0;
	  wait_final=0;
	  turnaround_final=0;
  for(i=1;i<n;i++)
  {
    sum += burstTime[i-1];
    waitingTime[i] = sum - arrivalTime[i];
    wait_final += waitingTime[i]; 
  }
  wait_avg = wait_final/n;
  for(i=0;i<n;i++)
  {
    sum2 += burstTime[i];
    turnaroundTime[i] = sum2 - arrivalTime[i];
    turnaround_final += turnaroundTime[i];
  }
  turnaround_avg=turnaround_final/n;
 completionTime[0] = burstTime[0];
  for(i=1;i<n;i++)
  {
    completionTime[i] = completionTime[i-1] + burstTime[i];
  }
  


  printf("\n\n\t\tFINAL VALUE(AFTER ARRANGEMENT)\n\n");
  printf(" Process   Arrival Time   Burst Time    Waiting Time     TurnAround Time       Priority \n");
  for(i=0;i<n;i++)
  {
    printf(" P%0.0lf\t\t%0.0lf\t\t%0.0lf\t\t%0.0lf\t\t%0.0lf\t\t%lf    \n",process[i],arrivalTime[i],burstTime[i],waitingTime[i],turnaroundTime[i],priority[i]);
  }

  printf("\n\n\n\t\t\tAverage Turn Around Time : %lf",turnaround_avg);
  printf("\n\t\t\tAverage Waiting Time     : %lf\n\n",wait_avg);
	
  getch();
  return 0;
}
