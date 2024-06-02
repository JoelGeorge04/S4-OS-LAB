#include<stdio.h>
#include<string.h>
struct proc
{
	char name[10];
	int at,bt,wt,tt,status,pt;
}p[10];
struct gant
{
	char name[10];
	int st,ct,num;
}g[10];
void main()
{
	int n,i,j,k,idle,ls,flag,found,num;
	float sum1=0,sum2=0,awt,att;
	printf("Enter the no of process: ");
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		printf("\nEnter the name of process ");
		scanf("%s",p[i].name);
		printf("Enter the priority of process ");
		scanf("%d",&p[i].pt);
		printf("Enter the arrival time of process ");
		scanf("%d",&p[i].at);
		printf("Enter the burst time of process ");
		scanf("%d",&p[i].bt);
		p[i].status=0;
	}
	
	
	
	idle=0;
	ls=0;
	num=0;
	for(i=0;ls<n;)
	{
		flag=0;
		found=0;
		for(j=0;j<n;j++)
		{
			if(p[j].status==0 && p[j].at<=i && found ==0)
			{
				k=j;
				flag++;
				found++;
			
			}
			else if(found>0 && p[j].status==0 && p[j].at<=i)
			{
				if(p[j].pt<p[k].pt)
				{
					k=j;
				}
			}
			
		}
		if(flag==0 && idle==0)
		{
			strcpy(g[num].name,"idle");
			g[num].st=i;
			idle=1;
			i++;
		}
		else if(flag>0)
		{
			if(idle==1)
			{
				g[num].ct=i;
				num++;
			}
			strcpy(g[num].name,p[k].name);
			g[num].st=i;
			g[num].ct=i+p[k].bt;
			p[k].tt=g[num].ct-p[k].at;
			p[k].wt=p[k].tt-p[k].bt;
			i=g[num].ct;
			num++;
			p[k].status=1;
			idle=0;
			ls++;
			k++;
			
		}
		else
			i++;
	}
	printf("\n");
	printf("|\tProcess\t|\tAT\t|\tBT\t|\tCT\t|\tTAT\t\t|\tWT\t\t|");
	printf("\n");
	for(i=0;i<n;i++)
	{
		printf("|\t%s\t|\t%d\t|\t%d\t|\t%d\t|\t%d\t\t|\t%d\t\t|",p[i].name,p[i].at,p[i].bt,p[i].at+p[i].tt,p[i].tt,p[i].wt);
		printf("\n");
	}
	printf("\n");
	printf("\n___________________________________\n");
	for(i=0;i<num;i++)
	{
		printf("|%s\t",g[i].name);
		
	}
	printf("|");
	printf("\n___________________________________\n");
	for(i=0;i<num;i++)
	{
		printf("%d\t",g[i].st);
		
	}
	printf("%d\t",g[num-1].ct);
	printf("\n");
	for(i=0;i<n;i++)
	{
		sum1=sum1+p[i].tt;
		sum2=sum2+p[i].wt;
	}
	att=sum1/n;
	awt=sum2/n;
	printf("\nAverage turnaround time is %f",att);
	printf("\nAverage waiting time is %f",awt);
	printf("\n");
}