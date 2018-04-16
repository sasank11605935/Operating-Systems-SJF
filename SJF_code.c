#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

int main()
{
	FILE *file;
	int number,x;
	int process,i=0,j,pos,total=0;
	float Average_Turn_Around_Time,Average_Waiting_Time;
	printf("\nENTER THE NUMBER OF PROCESS YOU WANT TO ENTER\n");
	scanf("%d",&process);
	int p[process],Burst_Time[process],Waiting_Time[process],Turn_Around_Time[process];
	file = fopen("CPU_BURST.txt", "w");
	printf("\nENTER THE BURST TIME IN SEQUEENCE ORDER FOR %d PROCESS :  \n",process);
		scanf("%d",&number);
		fprintf(file,"%d",number);
	fclose(file);
	file = fopen("CPU_BURST.txt","r");
	while((x = fgetc(file)) != EOF)
	{
		Burst_Time[i]=x-48;
		p[i]=i+1;  
		i++;
	}	
	fclose(file);
	printf("\nTHE PROCESS WITH THERE BURST TIME ARE\n");
	for(i=0;i<process;i++)
	{
		printf("P%d : ",i+1);
		printf("%d\n",Burst_Time[i]);
	}
	 for(i=0;i<process;i++)
    {
        pos=i;
        for(j=i+1;j<process;j++)
        {
            if(Burst_Time[j]<Burst_Time[pos])
            {
            	pos=j;
			}
        }
 
        int temp=Burst_Time[i];
        Burst_Time[i]=Burst_Time[pos];
        Burst_Time[pos]=temp;
 
        temp=p[i];
         p[i]=p[pos];
        p[pos]=temp;
    }
  Waiting_Time[0]=0;            //waiting time for first process will be zero
 
    //calculate waiting time
    for(i=1;i<process;i++)
    {
        Waiting_Time[i]=0;
        for(j=0;j<i;j++)
           {
           		Waiting_Time[i]+=Burst_Time[j];
		   }
    }
    printf("\nProcess\t    Burst Time    \tWaiting Time\tTurnaround Time");
    for(i=0;i<process;i++)
    {
        Turn_Around_Time[i]=Burst_Time[i]+Waiting_Time[i];     //calculate turnaround time
        printf("\np%d\t\t  %d\t\t    %d\t\t\t%d",p[i],Burst_Time[i],Waiting_Time[i],Turn_Around_Time[i]);
    }
 
	for(i=0;i<process;i++)
	{
		total=total+Waiting_Time[i];
	}
	Average_Waiting_Time=(float)total/process;
    printf("\n\nAverage Waiting Time=%f",Average_Waiting_Time);
    total=0;
    for(i=0;i<process;i++)
	{
		total=total+Turn_Around_Time[i];
	}
	Average_Turn_Around_Time=(float)total/process;
    printf("\nAverage Turnaround Time=%f\n",Average_Turn_Around_Time);
  }
 
