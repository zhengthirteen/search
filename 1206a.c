#include<stdio.h>
#include<string.h>
#include<stdlib.h>
struct identity{
	char name[11];
	char ID[19];
	char score[4];
	int num;
	struct identity *next;
}; 
void find_n(struct identity *first,char *m,int x[]);
int include(char* x,char* y);
void find_i(struct identity *first,char *m,int x[]);
void find_s(struct identity *first,char *m,int x[]);
int com(char* a,char* b)
{
	if(strlen(a)==strlen(b))
		return strcmp(a,b);
	else
		return strlen(a)-strlen(b);
}
int rank(struct identity *first,char *x);
int main(void)
{
	int n,x[10],*p,z=0;
	struct identity *first=NULL;
	struct identity *new_id;
	char m[19];
	scanf("%d",&n);
	scanf("%s",&m);
	for(int i=1;i<n+1;i++)
	{
		new_id=malloc(sizeof(struct identity));
		scanf("%s %s %s",&new_id->name,&new_id->ID,&new_id->score);
		new_id->num=i;
		new_id->next=first;
		first=new_id;
	}
	if(m[0]<'0'||m[0]>'9')
	find_n(first,m,x);
	else if(strlen(m)>3)
	find_i(first,m,x);
	else
	find_s(first,m,x);
	while(x[z])
	{
		struct identity *p;
	    for(p=first;p!=NULL;p=p->next)
	    {
	    	if((p->num)==x[z])
	    	{
	    		printf("%s %s %s ",p->name,p->ID,p->score);
	    		char *g;
	    		g=(char *)&(p->score);
	    		rank(first,g);
	    		z++;
			}
		}
	}
	return 0;
}
void find_n(struct identity *first,char* m,int x[])
{
	struct identity *p;
	int a=0;
	for(p=first;p!=NULL;p=p->next)
	{
		if(include((char *)(p->name),m))
		{
			x[a]=p->num;
			a++;
		}
	}
	return;
}
void find_i(struct identity *first,char *m,int x[])
{
	struct identity *p;
	int a=0;
	for(p=first;p!=NULL;p=p->next)
	{
		if(include((char *)(p->ID),m))
		{
			x[a]=p->num;
			a++;
		}
	}
	return;
}
void find_s(struct identity *first,char *m,int x[])
{
	struct identity *p;
	int a=0;
	for(p=first;p!=NULL;p=p->next)
	{
		if(strcmp((char *)(p->score),m)==0)
		{
			x[a]=p->num;
			a++;
		}
	}
	return;
}
int include(char* x,char* y)
{
	int j=0,k;
	if(strcmp(x,y)==0)
	return 1;
	else
	{
		for(int i=0;*(x+i)!='\0';i++)
		{
			if(*(x+i)==*(y+j))
			{
				k=i;
				while(y[j]!='\0')
				{
					if(*(x+k)!=*(y+j))
					break;
					k++;
					j++;
				}
				if(*(y+j)=='\0')
				return 1;
			}
			j=0;
		}
		return 0;
	}
}
int rank(struct identity *first,char *x)
{
	struct identity *p;
	int a=1;
	char temp[]="n/a";
	if(*x=='n'&&*(x+1)=='/'&&*(x+2)=='a')
	{
		printf("n/a\n");
		return 0;
	}
	else
	{
		for(p=first;p!=NULL;p=p->next)
		{
			if(strcmp(p->score,temp)==0)
			;
			else if(com((char *)(&p->score),x)>0)
			a++;
		}
		printf("%d",a);
		return 0;
	}
}
