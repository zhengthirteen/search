#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int include(char* x,char* y);
int com(char* a,char* b)
{
	if(strlen(a)==strlen(b))
		return strcmp(a,b);
	else
		return strlen(a)-strlen(b);
}
int main(void)
{
	int n,x[10]={0},z=0,j=0,rank;
	char name[100][11],ID[100][19],score[100][4],m[19];
	scanf("%d",&n);
	scanf("%s",&m);
	for(int i=0;i<n;i++)
	scanf("%s %s %s",name[i],ID[i],score[i]);
	if(m[0]<='z'&&m[0]>='a')
	{
		for(int i=0;i<n;i++)
		if(include(name[i],m))
		x[j++]=i;
	}
	else if(m[0]<='Z'&&m[0]>='A')
	{
		for(int i=0;i<n;i++)
		if(include(name[i],m))
		x[j++]=i;
	}
	else if(strlen(m)>3)
	{
		for(int i=0;i<n;i++)
		if(include(ID[i],m))
		x[j++]=i;
	}
	else
	{
		for(int i=0;i<n;i++)
		if(strcmp(score[i],m)==0)
		x[j++]=i;	
		if(j==0)
		{
			for(int i=0;i<n;i++)
			if(include(ID[i],m))
			x[j++]=i;
		}
	}
	for(int i=0;i<n;i++)
	    {
	    	rank=1;
	    	if(i==x[z++])
	    	{
	    		if(z!=1)
	    		printf("\n");
	    		printf("%s %s %s ",name[i],ID[i],score[i]);
	    		if(strcmp(score[i],"n/a")==0)
	    		printf("n/a\n");
	    		else
	    		{
	    			for(int f=0;f<n;f++)
	    		{
	    			if(strcmp(score[f],"n/a")==0)
	    			continue;
	    			else if(com(score[f],score[i])>0)
	    			rank++;
				}
				printf("%d",rank);
				}
			}
		}
	return 0;
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
