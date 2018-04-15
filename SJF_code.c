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
