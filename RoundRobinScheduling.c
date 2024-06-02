#include<stdio.h>
#include<string.h>
int q[100],front=-1,rear=-1;

struct process
{
	char name[20];
	int at,bt,wt,tt,status,left;
	
}p[20];

struct done
{
	char name[20];
	int st,ct;
	
}d[20];

void enqueue(int a)
{
    if(front==-1)
        front=0;
    q[++rear]=a;
}
int dequeue()
{
    if(front==-1 && rear==-1)
        return -1;
    else if(front==rear)
    {
        int a=q[front];
        front=-1;
        rear=-1;
        return a;
    }
    else
        return q[front++];
}

void main()
{
	int n,i,j,t,ls=0,idle=0,m=0,k;
	float avgwt,avgtt,sum1=0,sum2=0;
	printf("Enter the no of process\t:");
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		printf("\nEnter the process name:");
		scanf("%s",p[i].name);
		printf("Enter the arrival time of process:");
		scanf("%d",&p[i].at);
		printf("Enter the burst time of process:");
		scanf("%d",&p[i].bt);
		p[i].status=0;
		p[i].left=p[i].bt;
	}
	printf("Enter the time quantum:");
	scanf("%d",&t);
	
	for(i=0;ls<n;)
	{
		for(j=0;j<n;j++)
		{
			if(p[j].status==0 && p[j].at<=i)
			{
				enqueue(j);
				p[j].status=1;
			}
		}
		if(idle==0&&front==-1)
		{
			strcpy(d[m].name,"idle");
			d[m].st=i;
			idle=1;
			i++;
		}
		else if(front!=-1)
		{
			if(idle==1)
			{
				d[m].ct=i;
				
				idle=0;
				m++;
				
			}
			k=dequeue();
			d[m].st=i;
			strcpy(d[m].name,p[k].name);
			if(p[k].left<=t)
			{
				d[m].ct=i+p[k].left;
				i=d[m].ct;
				p[k].tt=i-p[k].at;
				p[k].wt=p[k].tt-p[k].bt;
				p[k].status=2;
				
				
				ls++;
				m++;
			}
			else
			{
				d[m].ct=i+t;
				i=i+t;
				p[k].left=p[k].left-t;
				m++;
				for(j=0;j<n;j++)
				{
					if(p[j].status==0&&p[j].at<=i)
					{
						enqueue(j);
						p[j].status=1;
					}
				}
				enqueue(k);
			}
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
	printf("\n________________________________________________________________\n");
	for(i=0;i<m;i++)
	{
		printf("|%s\t",d[i].name);
		
	}
	printf("|");
	printf("\n________________________________________________________________\n");
	for(i=0;i<m;i++)
	{
		printf("%d\t",d[i].st);
		
	}
	printf("%d\t",d[m-1].ct);
	printf("\n");
	for(i=0;i<n;i++)
	{
		sum1=sum1+p[i].tt;
		sum2=sum2+p[i].wt;
	}
	avgtt=sum1/n;
	avgwt=sum2/n;
	printf("\nAverage turnaround time is %f",avgtt);
	printf("\nAerage waiting time is %f",avgwt);
	printf("\n");
	
}