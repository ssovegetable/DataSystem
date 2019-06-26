#include<stdio.h>
#define N 2
int A;
struct inf
{
	int num;
	char name[20];
	int day;
	char way[20];
	int data;
}inf[N];


void save()
{
	FILE* fp;
	int i;
	if ((fp = fopen("D:\\CAN\\inf.txt", "a")) == NULL)
	{
		printf("cannot open file\n");
		return;
	}
	for (i = 0; i < N; i++)
		fprintf(fp, "%-5d %-10s %-10d %-10s %-10d\n", inf[i].num, inf[i].name, inf[i].day, inf[i].way, inf[i].data);
	fclose(fp);
}

void read()
{
	FILE* fp;
	int i;
	if ((fp = fopen("D:\\CAN\\inf.txt", "a+")) == NULL)
	{
		printf("cannot open file\n");
		return;
	}

	for (i = 0; i < N; i++)
		fscanf(fp, "%d%s%d%s%d", &inf[i].num, inf[i].name, &inf[i].day, inf[i].way, &inf[i].data);
	for (i = 0; i < N; i++)
		printf("%-5d %-10s %-10d %-10s %-10d\n", inf[i].num, inf[i].name, inf[i].day, inf[i].way, inf[i].data);
	fclose(fp);
}

int mima()
{
	int z;
	for (z = 0; z < 3; z++)
	{
		printf("                             测井资料管理系统                                   请输入密码：\n");
		scanf("%d", &A);
		if (A == 123456)
			break;
		else printf("密码错误：\n");
	}
	return(z);
}

void cha(int x)
{
	FILE* fp;
	int i;
	if ((fp = fopen("D:\\CAN\\inf.txt", "r")) == NULL)
	{
		printf("cannot open file\n");
		return;
	}
	for (i = 1; i <= N; i++)
	{
		fscanf(fp, "%d%s%d%s%d", &inf[i].num, inf[i].name, &inf[i].day, inf[i].way, &inf[i].data);
	}
	printf("%-5d %-10s %-10d %-10s %-10d\n", inf[x].num, inf[x].name, inf[x].day, inf[x].way, inf[x].data);

	fclose(fp);
}

void gai(int y)
{
	int i;
	FILE* fp;
	if ((fp = fopen("D:\\CAN\\inf.txt", "w+")) == NULL)
	{
		printf("cannot open file\n");
		return;
	}

	printf("请更改：                                                                        （编号 名称 日期 方法 数据）\n");
	for (i = 1; i <= N; i++)
	{
		fscanf(fp, "%d%s%d%s%d", &inf[i].num, inf[i].name, &inf[i].day, inf[i].way, &inf[i].data);
	}

	scanf("%d%s%d%s%d", &inf[y].num, inf[y].name, &inf[y].day, inf[y].way, &inf[y].data);



	for (i = 1; i <= N; i)
	{
		fprintf(fp, "%-5d %-10s %-10d %-10s %-10d\n", inf[i].num, inf[i].name, inf[i].day, inf[i].way, inf[i].data);
	}
	printf("更改成功：\n");
	fclose(fp);
}


int main()
{

	int i, a, b, c, d;
	int mima();
	int(*p)();
	p = mima;
	c = (*p)();
	if (c < 3)
	{
		printf("密码正确，进入系统（提示：1为输入测井数据 2为查阅测井资料 3为对已有数据进行修改）\n");
		scanf("%d", &a);
		if (a == 1)
		{
			printf("请输入测井数据:                                                                （编号 名称 日期 方法 数据）\n");
			for (i = 0; i < N; i++)
				scanf("%d%s%d%s%d", &inf[i].num, inf[i].name, &inf[i].day, inf[i].way, &inf[i].data);
			save();
		}
		else
		{
			if (a == 2)
			{
				printf("测井资料\n");
				read();
			}
			else
			{
				printf("请输入查找编号：\n");
				scanf("%d", &b);

				cha(b);

				printf("是否更改:（提示：1 更改；2 不更改）\n");
				scanf("%d", &d);
				if (d == 1)
				{

					gai(b);

				}
				else
				{
					printf("已确认不更改，按下回车键退出本系统：\n");
				}

			}
		}
	}
	else
	{
		printf("密码错误三次，退出系统\n");
	}
	return 0;
}

