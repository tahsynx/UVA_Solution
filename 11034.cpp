#include<stdio.h>
#include<string.h>
#include<queue>
using namespace std;
queue<long>qll,qlr;
long l,m,v,t,cnt,now,now1,fg;
char ch[10],c,c1;

int main()
{
	scanf("%ld",&t);
	while(t--)
	{
		scanf("%ld%ld",&l,&m);
		while(m--)
		{
			scanf("%ld%s",&v,ch);
			if(ch[0]=='l')
				qll.push(v);
			else
				qlr.push(v);
		}
		cnt=now=fg=0;
		l*=100;
		while(1)
		{
			if(!fg)
			{
				if(qll.empty())
				{
					now=0;
					fg=1;
					cnt++;
				}
				else
				{
					now1=qll.front();
					now+=now1;
					if(now>l)
					{
						now=0;
						cnt++;
						fg=1;
						continue;
					}
					qll.pop();
				}
			}
			else
			{
				if(qlr.empty())
				{
					now=0;
					fg=0;
					cnt++;
				}
				else
				{
					now1=qlr.front();
					now+=now1;
					if(now>l)
					{
						now=0;
						cnt++;
						fg=0;
						continue;
					}
					qlr.pop();
				}
			}
			if(qlr.empty()&&qll.empty())
			{
				cnt++;
				break;
			}
		}
		printf("%ld\n",cnt);
	}
	return 0;
}