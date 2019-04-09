#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
int main()
{
	int num_cats,num_mice,n1,n2;
	int i,n,x=0,y=0;
	
	printf("Enter the total no of cats\n");
	scanf("%d",&num_cats);
	printf("Enter the total no of mice :\n");
	scanf("%d",&num_mice);
	int a=num_cats;
	int b=num_mice;
	int cat[a],mice[b];
	for(i=0;i<a;i++)
		cat[i]=0;
	for(i=0;i<b;i++)
		mice[i]=0;
	while(x!=a&&y!=b)
	{
		n1=(rand()%2)+1;
		if(n1==1)
		{
			n2=(rand()%a)+1;
			printf("\ncat %d is eating the food ",n2);
			n=0;
			for(i=0;i<x;i++)
			{
				if(cat[i]==n2)
				{
					n=1;
					break;
				}
				else
					continue;			
			}
			if(n!=1)
			{
				cat[x]=n2;
				x++;
			}
		}
		if(n1==2)
		{
			n2=(rand()%a)+1;
			printf("\nmouse %d is eating the food ",n2);
			n=0;
			for(i=0;i<y;i++)
			{
				if(mice[i]==n2)
				{
					n=1;
					break;
				}
				else
					continue;
				
			}
			if(n!=1)
			{
				mice[y]=n2;
				y++;
			}
		}

	}
	printf("\ncat counts");
	for(i=0;i<a;i++)
		printf("\n%d ",cat[i]);
	printf("\nmice counts");
	for(i=0;i<b;i++)
		printf("\n%d ",mice[i]);
}
