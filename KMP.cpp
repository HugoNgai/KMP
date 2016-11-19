/*------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
																				KMP算法的实现
------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/
#include<iostream>
#include<stdlib.h>
#include<string.h>
#define Max 100
using namespace std;

void GetNextval(char p[],int next[])
{
	int plen=strlen(p);
	next[0]=-1;                                  //初始化next数组值为-1
	int k=-1,j=0;

	while(j<plen-1)
	{
		//p[k]表示前缀，p[j]表示后缀
		if (k==-1||p[j]==p[k])
		{
			++j;
			++k;
			if (p[j]!=p[k])
				next[j]=k;
			else
				next[j]=next[k];
		}
		else
			k=next[k];
	}
}

int KMP(char *p,char *s)
{
	int i=0;
	int j=0;
	int plen=strlen(p);
	int slen=strlen(s);
	int *next;
	next = (int *)malloc(slen * sizeof(int));
	GetNextval(s, next);

	while (i<plen&&j<slen)
	{
		if (j==-1||p[i]==s[j])
		{
				i++;
				j++;
		}
		else
			j=next[j];
	}
	if (j==slen)
		return i-j;
	else
		return -1;
	
}

int main(void)
{
	char *p,*s;
	p=(char *)malloc(Max*sizeof(char));
	s=(char *)malloc(Max*sizeof(char));

	cout<<"Please input the basic string:";
	cin>>p;
	cout<<"Then input the match string:";
	cin>>s;

	cout<<KMP(p,s);
}
