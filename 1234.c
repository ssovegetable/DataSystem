#include<stdio.h>
#include<string.h>
#include<process.h>
void signin(int a);
struct logging
{int num;char name[20];int date;char method[20];float data;}logg[30];
void input(struct logging logg[30],int n);
void print(int n);
void chazhao();
void zengjia();
void jianshao();
void bianji();
void tongji();
void paixu();
void paixu2();
int main()
{
	int i;
	int d;
	signin(123457);
	struct logging logg[30];
	input(logg,20);
	print(20);
	for(i=1;i>0;i++)
	{
        printf("�Ƿ���в��ң�����1���ң�����2�������ݣ�����3ɾ�����ݣ�����4�޸����ݣ�����5����ͳ�ƣ�����6����������������7����������������100�˳�\n");
        scanf("%d",&d);	
		if(d==100)
		{break;}
	    else if(d==1)
		{chazhao();}
		else if(d==2)
		{zengjia();}
		else if(d==3)
		{jianshao();}
		else if(d==4)
		{bianji();}
		else if(d==5)
		{tongji();}
		else if(d==6)
		{paixu();}
		else if(d==7)
		{paixu2();}
		else
		{printf("�����������������");}
	}
   
	return 0;
}

void signin(int a)
{
	int b;
    printf("���������룺");
    scanf("%d",&b);
    if(a-b==1)
    {printf("��½�ɹ�\n");return 0;}
    else
    {
    	printf("������󣬻���2�λ���\n");
		printf("���������룺");
	};
	scanf("%d",&b);
    if(a-b==1)
    {printf("��½�ɹ�\n");return 0;}
    else
    {
    	printf("������󣬻���1�λ���\n");
		printf("���������룺");
	};
	scanf("%d",&b);
    if(a-b==1)
    {printf("��½�ɹ�\n");return 0;}
    else
    {
    	printf("��������˳�����");exit(0);
	};
}


void input(struct logging logg[30],int n)
{
	FILE *fp;
	int i;
	printf("����������\n");
	fp=fopen("c:\\�⾮����.txt","w");
	for(i=0;i<n;i++)
	{
		scanf("%d %s %d %s %f",&logg[i].num,logg[i].name,&logg[i].date,logg[i].method,&logg[i].data);
		fprintf(fp,"%d %s %d %s %f\n",logg[i].num,logg[i].name,logg[i].date,logg[i].method,logg[i].data);
	}
	fclose(fp);
}



void print(int n)
{
	FILE *fp;
	int i;
	fp=fopen("c:\\�⾮����.txt","r");
	for(i=0;i<n;i++)
	{
		fscanf(fp,"%d %s %d %s %f",&logg[i].num,logg[i].name,&logg[i].date,logg[i].method,&logg[i].data);
		printf("%d %s %d %s %f\n",logg[i].num,logg[i].name,logg[i].date,logg[i].method,logg[i].data);
	}
	fclose(fp);
}


void chazhao()
{
	FILE *fp;
	int c;
	fp=fopen("c:\\�⾮����.txt","w");
	printf("��������ҵڼ�������\n");
    scanf("%d",&c);
    c=c-1;
	fscanf(fp,"%d %s %d %s %f",&logg[c].num,logg[c].name,&logg[c].date,logg[c].method,&logg[c].data);
	printf("%d %s %d %s %f\n",logg[c].num,logg[c].name,logg[c].date,logg[c].method,logg[c].data);
	fclose(fp);
}

void zengjia()
{
	FILE *fp;
	int i;
	int d;
	int j;
	int c;
	int n=0;
	fp=fopen("c:\\�⾮����.txt","w");
	for(i=0;i<30;i++)
	{
		fscanf(fp,"%d %s %d %s %f",&logg[i].num,logg[i].name,&logg[i].date,logg[i].method,&logg[i].data);
	}
	printf("���������Ӽ�������:\n");
	scanf("%d",&j);
	for(i=0;i<30;i++)
	{
	    if(logg[i].num!=0)
	    {
	    	n=n+1;//��������������Ϊ������� 
		}
	}
	c=n+j;//���Ӻ��ܹ���Ϊ������������ 
	printf("���������ӵ�����:\n");
	for(i=0;i<j;i++)
	{
	    d=n+i;
		scanf("%d %s %d %s %f",&logg[d].num,logg[d].name,&logg[d].date,logg[d].method,&logg[d].data);
	}
	for(i=0;i<c;i++)
	{
		fprintf(fp,"%d %s %d %s %f\n",logg[i].num,logg[i].name,logg[i].date,logg[i].method,logg[i].data);
	}
	fclose(fp);
}


void jianshao()
{
	FILE *fp;
	int c;
	int i;
	int x;
	fp=fopen("c:\\�⾮����.txt","w");
	printf("������ɾ���ڼ�������\n");
    scanf("%d",&c);
    for(i=0;i<c;i++)
    {
    	fscanf(fp,"%d %s %d %s %f",&logg[i].num,logg[i].name,&logg[i].date,logg[i].method,&logg[i].data);
	}
	for(i=0;i<30-c;i++)
	{
		x=i+c;
		logg[x-1]=logg[x];
	}
	for(i=0;i<30;i++)
	{
	    fprintf(fp,"%d %s %d %s %f\n",logg[i].num,logg[i].name,logg[i].date,logg[i].method,logg[i].data);	
	}
	
	fclose(fp);
}

void bianji()
{
	FILE *fp;
	int c;
	int i;
	fp=fopen("c:\\�⾮����.txt","w");
	printf("������Ҫ�޸ĵڼ�������:\n");
    scanf("%d",&c);
    c=c-1;
    printf("�������޸���������:\n");
    scanf("%d %s %d %s %f",&logg[c].num,logg[c].name,&logg[c].date,logg[c].method,&logg[c].data);
    for(i=0;i<30;i++)
    {
	    fprintf(fp,"%d %s %d %s %f\n",logg[i].num,logg[i].name,logg[i].date,logg[i].method,logg[i].data);
	}
	fclose(fp);
}

void tongji()
{
	FILE *fp;
	int a;
	int i;
	float n=1;
	float m=1;
	float l;
	char b[20]={"a"};
	char c[20]={"b"};
	char d[20]={"c"};
	fp=fopen("c:\\�⾮����.txt","r");
	printf("ͳ�������⾮����1����⾮����2���˲⾮����3\n");
	scanf("%d",&a);
	for(i=0;i<30;i++)
	{
		fscanf(fp,"%d %s %d %s %f",&logg[i].num,logg[i].name,&logg[i].date,logg[i].method,&logg[i].data);
	}
	if(a==1)
	{
		for(i=0;i<30;i++)
		{
			if(logg[i].num==0) continue;
		    else
		    {
		    	if(strcmp(b,logg[i].method)==0)
		    	{n=n+1;}
		    	else
		    	{m=m+1;}	  
			}
	    }
	    l=(n-1)/(m+n-2);
	    printf("�����⾮��ռ����Ϊ%f\n",l);
	}
	else if(a==2)
	{
		for(i=0;i<30;i++)
		{
			if(logg[i].num==0) continue;
		    else
		    {
		    	if(strcmp(c,logg[i].method)==0)
		    	{n=n+1;}
		    	else
		    	{m=m+1;}	  
			}
	    }
	    l=(n-1)/(m+n-2);
	    printf("��⾮��ռ����Ϊ%f\n",l);
	}
	else if(a==3)
	{
		for(i=0;i<30;i++)
		{
			if(logg[i].num==0) continue;
		    else
		    {
		    	if(strcmp(d,logg[i].method)==0)
		    	{n=n+1;}
		    	else
		    	{m=m+1;}	  
			}
	    }
	    l=(n-1)/(m+n-2);
	    printf("�˲⾮��ռ����Ϊ%f\n",l);
	}
	else
	    {printf("�����������������\n");}
	fclose(fp);
}


void paixu()
{
	FILE *fp;
	FILE *fp1;
	int i,j,x;
	int c=0;
	struct logging shuju;
	fp=fopen("c:\\�⾮����.txt","r");
	fp1=fopen("c:\\�����ļ�.txt","w");
	
	for(i=0;i<30;i++)
    {
	    fscanf(fp,"%d %s %d %s %f\n",&logg[i].num,logg[i].name,&logg[i].date,logg[i].method,&logg[i].data);
	}
	for(j=0;j<30;j++)
    {
		for(i=0;i<29-j;i++)
			if(logg[i].date>logg[i+1].date)
			{
				shuju=logg[i];
				logg[i]=logg[i+1];
				logg[i+1]=shuju;
			}
		    if(logg[i].date==0)
			{c=c+1;}
		    else continue;
	}
	for(i=0;i<30-c;i++)
	{
		x=c+i;
		logg[i]=logg[x];
		memset(&logg[x],0,sizeof(struct logging));//�ѽṹ�����x����ʼ��Ϊ0��sizeof����һ��ĳ��� 
	}
	printf("�����Ϊ\n");
	for(i=0;i<30;i++)
		{printf("%d %s %d %s %f\n",logg[i].num,logg[i].name,logg[i].date,logg[i].method,logg[i].data);}

	for(i=0;i<30;i++)
	{
	    fprintf(fp1,"%d %s %d %s %f\n",logg[i].num,logg[i].name,logg[i].date,logg[i].method,logg[i].data);	
	}
    fclose(fp);
    fclose(fp1);
}

void paixu2()
{
	FILE *fp;
	FILE *fp1;
	int i,j,x;
	int c=0;
	struct logging shuju;
	fp=fopen("c:\\�⾮����.txt","r");
	fp1=fopen("c:\\�����ļ�.txt","w");
	
	for(i=0;i<30;i++)
    {
	    fscanf(fp,"%d %s %d %s %f\n",&logg[i].num,logg[i].name,&logg[i].date,logg[i].method,&logg[i].data);
	}
	for(j=0;j<30;j++)
    {
		for(i=0;i<29-j;i++)
			if(logg[i].data>logg[i+1].data)
			{
				shuju=logg[i];
				logg[i]=logg[i+1];
				logg[i+1]=shuju;
			}
		    if(logg[i].date==0)
			{c=c+1;}
		    else continue;
	}
	for(i=0;i<30-c;i++)
	{
		x=c+i;
		logg[i]=logg[x];
		memset(&logg[x],0,sizeof(struct logging));//�ѽṹ�����x����ʼ��Ϊ0��sizeof����һ��ĳ��� 
	}
	printf("�����Ϊ\n");
	for(i=0;i<30;i++)
		{printf("%d %s %d %s %f\n",logg[i].num,logg[i].name,logg[i].date,logg[i].method,logg[i].data);}

	for(i=0;i<30;i++)
	{
	    fprintf(fp1,"%d %s %d %s %f\n",logg[i].num,logg[i].name,logg[i].date,logg[i].method,logg[i].data);	
	}
    fclose(fp);
    fclose(fp1);
}





















