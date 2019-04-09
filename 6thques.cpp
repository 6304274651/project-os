#include<stdio.h>
#include<conio.h>
int main()
{
	int process[10],x,i,j;
	float b_time[10],w_time[10],ta_time[10],avg_w_time=0,avg_ta_time=0,a_time[i],min,temp;
	float w_time1[10],ta_time1[10],avg_w_time1=0,avg_ta_time1=0,min1,min2;
	float w_time2[10],ta_time2[10],avg_w_time2=0,avg_ta_time2=0;
	printf("\nenter total no of processes(maximum of 10)");
	scanf("%d",&x);
	printf("\nenter the burst time of the processes");
	for(i=0;i<x;i++)
	{
		process[i]=i+1;
		printf("\tp%d:",process[i]);
		scanf("%f",&b_time[i]);
	}
	printf("\nenter the arrival time of the processes");
	for(i=0;i<x;i++)
	{
		printf("\tp[%d] ",i+1);
		scanf("%f",&a_time[i]);
	}
	printf("FIRST COME FIRST SERVE\n");
	for(i=0;i<x;i++)//soarting arrival time
    {
		min=a_time[0];
		if(a_time[i]<min)
		{
			min=a_time[i];
		}
		temp=a_time[0];//swapping arrival time values
		a_time[0]=a_time[i];
		a_time[i]=temp;
		
		temp=process[0];//swapping positions
		process[0]=process[i];
		process[i]=temp;
		
		temp=b_time[0];//swapping btime values
		b_time[0]=b_time[i];
		b_time[i]=temp;
	}
	w_time[0]=0;//waiting time of first process is 0
    for(i=0;i<x;i++)//waiting time
    {
    	w_time[i]=0;
		for(j=0;j<i;j++)
		 	w_time[i]=w_time[i]+b_time[j]-a_time[i];	
    }
    for(i=0;i<x;i++)//turn around time
	{
		ta_time[i]=b_time[i]+w_time[i];	
		avg_w_time=avg_w_time+w_time[i];
		avg_ta_time=avg_ta_time+ta_time[i];
	}
	avg_ta_time=avg_ta_time/x;
	printf("\nAverage turn around time =%f",avg_ta_time);
	printf("\n******************************************************************************");
	printf("\nSHORTEST JOB FIRST\n");
	for(i=0;i<x;i++)//soarting arrival time
    {
		min1=a_time[0];
		if(a_time[i]<min1)
		{
			min1=a_time[i];
		}
		temp=a_time[0];//swapping arrival time values
		a_time[0]=a_time[i];
		a_time[i]=temp;
		
		temp=process[0];//swapping positions
		process[0]=process[i];
		process[i]=temp;
		
		temp=b_time[0];//swapping btime values
		b_time[0]=b_time[i];
		b_time[i]=temp;
	}
	for(i=1;i<x;i++)//soarting burst time
    {
		min1=b_time[0];
		if(b_time[i]<min1)
		{
			min1=b_time[i];
		}
		temp=b_time[0];//swapping arrival time values
		b_time[0]=b_time[i];
		b_time[i]=temp;
		
		temp=process[0];//swapping positions
		process[0]=process[i];
		process[i]=temp;
		
		temp=a_time[0];//swapping btime values
		a_time[0]=a_time[i];
		a_time[i]=temp;
	}
	w_time1[0]=0;
    for(i=0;i<x;i++)//waiting time
    {
    	w_time1[i]=0;
		for(j=0;j<i;j++)
		 	w_time1[i]=w_time1[i]+b_time[j]-a_time[i];	
    }
	for(i=0;i<x;i++)//turn around time
	{
		ta_time1[i]=b_time[i]+w_time1[i];
		avg_ta_time1=avg_ta_time1+ta_time1[i];
	}
	avg_ta_time1=avg_ta_time1/x;
	printf("\nAverage turnaround time=%f",avg_ta_time1);
	printf("\n******************************************************************************");

int idle=1,total=0;
w_time2[0]=1;//as first unit is left idle
for(i=1;i<x;i++)
{
	int sum=0;
	for(j=0;j<i;i++)
		w_time2[i]=sum+b_time[j]+1;	
		sum=w_time[i];
}
for(i=0;i<x;i++)//turn around time
	{
		ta_time2[i]=b_time[i]+w_time2[i];
		total=total+ta_time2[i];
	}
	avg_ta_time2=total/x;
	printf("\nAverage turnaround time=%f",avg_ta_time2);
}
	
