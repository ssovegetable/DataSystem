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
        printf("是否进行查找？输入1查找，输入2增加数据，输入3删除数据，输入4修改数据，输入5进行统计，输入6进行日期排序，输入7进行数据排序，输入100退出\n");
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
		{printf("输入错误，请重新输入");}
	}
   
	return 0;
}

void signin(int a)
{
	int b;
    printf("请输入密码：");
    scanf("%d",&b);
    if(a-b==1)
    {printf("登陆成功\n");return 0;}
    else
    {
    	printf("密码错误，还有2次机会\n");
		printf("请输入密码：");
	};
	scanf("%d",&b);
    if(a-b==1)
    {printf("登陆成功\n");return 0;}
    else
    {
    	printf("密码错误，还有1次机会\n");
		printf("请输入密码：");
	};
	scanf("%d",&b);
    if(a-b==1)
    {printf("登陆成功\n");return 0;}
    else
    {
    	printf("密码错误，退出程序");exit(0);
	};
}


void input(struct logging logg[30],int n)
{
	FILE *fp;
	int i;
	printf("请输入数据\n");
	fp=fopen("c:\\测井数据.txt","w");
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
	fp=fopen("c:\\测井数据.txt","r");
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
	fp=fopen("c:\\测井数据.txt","w");
	printf("请输入查找第几组数据\n");
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
	fp=fopen("c:\\测井数据.txt","w");
	for(i=0;i<30;i++)
	{
		fscanf(fp,"%d %s %d %s %f",&logg[i].num,logg[i].name,&logg[i].date,logg[i].method,&logg[i].data);
	}
	printf("请输入增加几组数据:\n");
	scanf("%d",&j);
	for(i=0;i<30;i++)
	{
	    if(logg[i].num!=0)
	    {
	    	n=n+1;//计数器，计数不为零的项数 
		}
	}
	c=n+j;//增加后总共不为零项数的组数 
	printf("请输入增加的数据:\n");
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
	fp=fopen("c:\\测井数据.txt","w");
	printf("请输入删除第几组数据\n");
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
	fp=fopen("c:\\测井数据.txt","w");
	printf("请输入要修改第几组数据:\n");
    scanf("%d",&c);
    c=c-1;
    printf("请输入修改数据内容:\n");
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
	fp=fopen("c:\\测井数据.txt","r");
	printf("统计声波测井输入1，电测井输入2，核测井输入3\n");
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
	    printf("声波测井所占比例为%f\n",l);
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
	    printf("电测井所占比例为%f\n",l);
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
	    printf("核测井所占比例为%f\n",l);
	}
	else
	    {printf("输入错误请重新输入\n");}
	fclose(fp);
}


void paixu()
{
	FILE *fp;
	FILE *fp1;
	int i,j,x;
	int c=0;
	struct logging shuju;
	fp=fopen("c:\\测井数据.txt","r");
	fp1=fopen("c:\\排序文件.txt","w");
	
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
		memset(&logg[x],0,sizeof(struct logging));//把结构体里第x个初始化为0，sizeof是这一项的长度 
	}
	printf("排序后为\n");
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
	fp=fopen("c:\\测井数据.txt","r");
	fp1=fopen("c:\\排序文件.txt","w");
	
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
		memset(&logg[x],0,sizeof(struct logging));//把结构体里第x个初始化为0，sizeof是这一项的长度 
	}
	printf("排序后为\n");
	for(i=0;i<30;i++)
		{printf("%d %s %d %s %f\n",logg[i].num,logg[i].name,logg[i].date,logg[i].method,logg[i].data);}

	for(i=0;i<30;i++)
	{
	    fprintf(fp1,"%d %s %d %s %f\n",logg[i].num,logg[i].name,logg[i].date,logg[i].method,logg[i].data);	
	}
    fclose(fp);
    fclose(fp1);
}





















