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
		printf("                             �⾮���Ϲ���ϵͳ                                   ���������룺\n");
		scanf("%d", &A);
		if (A == 123456)
			break;
		else printf("�������\n");
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

	printf("����ģ�                                                                        ����� ���� ���� ���� ���ݣ�\n");
	for (i = 1; i <= N; i++)
	{
		fscanf(fp, "%d%s%d%s%d", &inf[i].num, inf[i].name, &inf[i].day, inf[i].way, &inf[i].data);
	}

	scanf("%d%s%d%s%d", &inf[y].num, inf[y].name, &inf[y].day, inf[y].way, &inf[y].data);



	for (i = 1; i <= N; i)
	{
		fprintf(fp, "%-5d %-10s %-10d %-10s %-10d\n", inf[i].num, inf[i].name, inf[i].day, inf[i].way, inf[i].data);
	}
	printf("���ĳɹ���\n");
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
		printf("������ȷ������ϵͳ����ʾ��1Ϊ����⾮���� 2Ϊ���Ĳ⾮���� 3Ϊ���������ݽ����޸ģ�\n");
		scanf("%d", &a);
		if (a == 1)
		{
			printf("������⾮����:                                                                ����� ���� ���� ���� ���ݣ�\n");
			for (i = 0; i < N; i++)
				scanf("%d%s%d%s%d", &inf[i].num, inf[i].name, &inf[i].day, inf[i].way, &inf[i].data);
			save();
		}
		else
		{
			if (a == 2)
			{
				printf("�⾮����\n");
				read();
			}
			else
			{
				printf("��������ұ�ţ�\n");
				scanf("%d", &b);

				cha(b);

				printf("�Ƿ����:����ʾ��1 ���ģ�2 �����ģ�\n");
				scanf("%d", &d);
				if (d == 1)
				{

					gai(b);

				}
				else
				{
					printf("��ȷ�ϲ����ģ����»س����˳���ϵͳ��\n");
				}

			}
		}
	}
	else
	{
		printf("����������Σ��˳�ϵͳ\n");
	}
	return 0;
}

