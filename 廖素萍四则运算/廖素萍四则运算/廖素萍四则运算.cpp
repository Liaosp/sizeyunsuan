// ����Ƽ��������.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include "time.h"
#include "conio.h"
#include "stdlib.h"
//�������
void srand(unsigned int seed);
//�������
void getNumber(int &a,int &b,int &c,int &d)
{
	
	a=rand()%100;//����һ��100���ڵ��������
	b=rand()%100;
	c=rand()%100;
	d=rand()%100;
}
//����
void getmode(int &mode1,int &mode2,int &mode3)
{
	mode1=rand()%4;//����һ��0-4֮����������
	mode2=rand()%5;
	mode3=rand()%5;
}
//�жϷ���
void mode(int b,int m,int &i)
{
	if(m==0)
	{
		printf("+");
	}
	else if(m==1)
	{
		printf("-");
	}
	else if(m==2)
	{
		printf("*");
	}
	else if(m==3)
	{
		if(b==0)
		{
			return;
		}
		int a=rand()%100;//aû��ʼ�������ˣ�
		if(a%b!=0)
		{
			return;
		}
		printf("/");
	}
}
int _tmain(int argc, _TCHAR* argv[])
{
	int n=0;//��Ŀ����
	int a=0,b=0,c=0,d=0;
	int answer=0;//��
	int f1=0,f2=0,f3=0;//0��+   1:-   2:*   3:/
	printf("��������Ҫ������ɵ���Ŀ������");
	scanf("%d",&n);
	srand((int)time(NULL));//��ʼ���������
	int mode1,mode2,mode3;
	for(int i=0;i<n;i++)//iΪ��i����Ŀ
	{
		getNumber(a,b,c,d);//����4�������
		getmode(mode1,mode2,mode3);//����3�������
		//mode1  2����Ϊ+  -
		if(!(mode1==0 || mode1==1 || mode2==0 || mode2==1 ||mode2==4))
		{
			//�ж�mode1�������
			if(mode1==2)
			{
				answer=a*b;
			}
			else if(mode1==3)
			{
				if(b==0)
				{
					i--;
					goto part2;
				}
				else
				{
					answer=a/b;
				}
			}
			//�ж�mode2�������
			if(mode2==2)
			{
				answer=a*b*c;
			}
			else if(mode2=3)
			{
				if(c==0 || answer%c!=0)
				{
					i--;
					goto part2;
				}
				else
				{
					answer=a*b/c;
				}
			}
			//�ж�mode3��û�������
			if(mode3!=4)
			{
				if(mode3==0)
				{
					answer+=d;
				}
				else if(mode3==1)
				{
					answer-=d;
				}
				else if(mode3==2)
				{
					answer*=d;
				}
				else if(mode3==3)
				{
					if(d==0 || answer%d!=0)
					{
						i--;
						goto part2;
					}
					else
					{
						answer/=d;
					}
				}

			}
			else goto part2;
		}
		//mode1Ϊ*  /  mode2����Ϊ+  -
		if(!(mode1==0 || mode1==1 || mode2==2 || mode2==3 ||mode2==4))
		{
			int t=0;
			if(mode1==2)
			{
				answer=a*b;
			}
			else if(mode1==3)
			{
				if(b==0 || answer%b!=0)
				{
					i--;
					goto part2;
				}
				else
				{
					answer=a/b;
				}
			}
			if(!(mode3==4 || mode3==0 || mode3==1))//mode3Ϊ* /
			{
				if(mode3==2)
				{
					t=c*d;
				}
				else if(mode3==3)
				{
					if(d==0 || c%d!=0)
					{
						i--;
						goto part2;
					}
					else
					{
						t=c/d;
					}
				}
				if(mode2==0)
				{
					answer+=t;
				}
				else
				{
					answer-=t;
				}
			}
			else if(!(mode3==4 || mode3==2 || mode3==3))//mode3Ϊ+   -
			{
				if(mode2==0)
				{
					answer+=c;
				}
				else if(mode2==1)
				{
					answer-=c;
				}
				if(mode3==0)
				{
					answer+=d;
				}
				else if(mode3==1)
				{
					answer-=d;
				}
			}
			else
			{
				if(mode2==0)
				{
					answer+=c;
				}
				else if(mode2==1)
				{
					answer-=c;
				}
			}
		}
		//mode1Ϊ+  -  mode2Ϊ*  /
		if(!(mode1==2 || mode1==3|| mode2==0 || mode2==1|| mode2==4))
		{
			int x=0;
			if(mode2==2)
			{
				x=b*c;
			}
			else if(mode2==3)
			{
				if(c==0 || b%c!=0)
				{
					i--;
					goto part2;
				}
				else
				{
					x=b/c;
				}
			}
			answer=x;
			if(!(mode3==4 || mode3==0 || mode3==1))//mode3Ϊ*  /
			{
				if(mode3==2)
				{
					answer=x*d;
				}
				else if(mode3==3)
				{
					if(d==0 || x%d!=0)
					{
						i--;
						goto part2;
					}
					else
					{
						answer=x/d;
					}
				}
			}
			else if(!(mode3==4 || mode3==2 || mode3==3))//mode3Ϊ+  -
			{
				if(mode1==0)
				{
					answer+=a;
				}
				else if(mode1==1)
				{
					answer-=a;
				}
				if(mode3==0)
				{
					answer+=d;
				}
				else if(mode3==1)
				{
					answer-=d;
				}
			}
			else
			{
				if(mode1==0)
				{
					answer+=a;
				}
				else if(mode1==1)
				{
					answer-=a;
				}
			}
		}
		//mode1Ϊ+  -  mode2Ϊ+  -
		if(!(mode1==2 || mode1==3|| mode2==2 || mode2==3 || mode2==4))//
		{
			int y=0,s=0;
			if(!(mode3==4 || mode3==0 || mode3==1))//mode3Ϊ*  /
			{
				if(mode3==2)
				{
					y=c*d;
				}
				else if(mode3==3)
				{
					if(d==0 || c%d!=0)
					{
						i--;
						goto part2;
					}
					else
					{
						y=c/d;
					}
				}
				if(mode1==0)
				{
					answer=a+b;
				}
				else if(mode1==1)
				{
					answer=a-b;
				}
				if(mode2==0)
				{
					answer=answer+y;
				}
				else if(mode2==1)
				{
					answer=answer-y;
				}
			}
			else if(!(mode3==4 || mode3==2 || mode3==3))//mode3Ϊ+  -
			{
				if(mode1==0)
				{
					answer=a+b;
				}
				else if(mode1==2)
				{
					answer=a-b;
				}
				if(mode2==0)
				{
					answer=answer+c;
				}
				else if(mode2==2)
				{
					answer=answer-c;
				}
				if(mode3==0)
				{
					answer=answer+d;
				}
				else if(mode3==2)
				{
					answer=answer-d;
				}
			}
			else
			{
				if(mode1==0)
				{
					answer=a+b;
				}
				else if(mode1==2)
				{
					answer=a-b;
				}
				if(mode2==0)
				{
					answer=answer+c;
				}
				else if(mode2==2)
				{
					answer=answer-c;
				}
			}
		}
		if(mode2==4)
		{
			if(mode1==0)
			{
				answer=a+b;
			}
			else if(mode1==1)
			{
				answer=a-b;
			}
			else if(mode1==2)
			{
				answer=a*b;
			}
			else if(mode1==3)
			{
				if(b==0 || a%b!=0)
				{
					i--;
					goto part2;
				}
				else
				{
					answer=a/b;
				}
			}
		}
		if(answer<0)
		{
			i--;
			goto part2;
		}
		int m=i+1;
		printf("%d.",m);
		printf("%d",a);
		mode(b,mode1,i);
		printf("%d",b);
		if(mode2!=4)
		{
			mode(c,mode2,i);
		}
		else
		{
			printf("\n");
			printf("�𰸣�%d\n",answer);
			continue;
		}
		printf("%d",c);
		if(mode3!=4)
		{
			mode(d,mode3,i);
		}
		else
		{
			printf("\n");
			printf("�𰸣�%d\n",answer);
			continue;
		}
		printf("%d=\n",d);
		printf("�𰸣�%d\n",answer);
part2 :
		printf("");
	}
	return 0;
}

