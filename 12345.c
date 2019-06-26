#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
#include<ctype.h>

#define N 3
#define M 120
save();
read();
int ps();
find();
change();
tongj();
sort();
del();
deal();

struct 
{
	float m;
	float ac;
	float gr;
}sj[M];

struct 
{
	float por;
	float vsh;
}jg[M];

struct
{
	int num;
	char name[20];
	char day[20];
	char how[20];
	char date[20];
}stu[N];
struct
{
	int num;
	char name[20];
	char day[20];
	char how[20];
	char date[20];
}text[N];
struct
{
	int num;
	char name[20];
	char day[20];
	char how[20];
	char date[20];
}emm;


int main()
{

	int m,n,q;
	int a=ps();

	if(a==1)
	{

		printf("请输入数据，输入结束后正式进入管理系统\n");
		save();
		
A:
		system("CLS");
		printf("                       ______________________________________                             \n");
		printf("                      |        测井数据管理系统-1.00         |                            \n");
		printf("                      |______________________________________|                            \n");
		printf("                      |             选择操作                 |                            \n");
		printf("                      |______________________________________|                            \n");
		printf("                      |-----------1.查看数据-----------------|                            \n");
		printf("                      |-----------2.查找数据-----------------|                            \n");
		printf("                      |-----------3.修改数据-----------------|                            \n");
		printf("                      |-----------4.删除数据-----------------|                            \n");
		printf("                      |-----------5.统计数据-----------------|                            \n");
		printf("                      |-----------6.数据排序-----------------|                            \n");
		printf("                      |-----------7.数据处理-----------------|                            \n");
		printf("                      |-----------8.退出程序-----------------|                            \n");
		printf("                      |______________________________________|                            \n");
L:
		scanf("%d",&m);
		if(m!=1&&m!=2&&m!=3&&m!=4&&m!=5&&m!=6&&m!=7&&m!=8)
		{
			printf("输入错误，请重新输入\n");
			goto L;
		}
		if(m==1)
		{
			read();
			printf("输入任意数字返回主菜单\n");
			scanf("%d",&n);
			goto A;
		}
		if(m==2)
		{
B:
			find();
			printf("是否继续查找？1.是（除1外所有操作均会返回主菜单）");
			scanf("%d",&n);
			if(n==1)
			{
				goto B;
			}
			if(n!=1)
			{
				goto A;
			}
		}
		if(m==3)
		{
C:
			change();
			printf("是否继续修改？1.是（除1外所有操作均会返回主菜单）");
			scanf("%d",&n);
			if(n==1)
			{
				goto C;
			}
			if(n!=1)
			{
				goto A;
			}
		}
		if(m==4)
		{
D:
			del();
			printf("是否继续删除？1.是（除1外所有操作均会返回主菜单）");
			scanf("%d",&n);
			if(n==1)
			{
				goto D;
			}
			if(n!=1)
			{
				goto A;
			}
		}
		if(m==5)
		{
E:
			tongj();
			printf("是否继续统计？1.是（除1外所有操作均会返回主菜单）");
			scanf("%d",&n);
			if(n==1)
			{
				goto E;
			}
			if(n!=1)
			{
				goto A;
			}
		}
		if(m==6)
		{
F:
			sort();
			printf("是否继续排序？1.是（除1外所有操作均会返回主菜单）");
			scanf("%d",&n);
			if(n==1)
			{
				goto F;
			}
			if(n!=1)
			{
				goto A;
			}
		}
		if(m==7)
		{
			deal();
			printf("输入任意数字返回主菜单\n");
			scanf("%d",&n);
			goto A;
		}
		if(m==8)
		{
			return 0;
		}
	}
	else
	{
		return 0;
	}

}



deal()
{
	FILE*fp1;
	FILE*fp2;
	int i;
	float a;
	if((fp1=fopen("D:\\CC\\well.txt","r"))==NULL)
	{
		printf("无法打开文件\n");
		return 0;
	}
	for(i=0;i<M;i++)
		fscanf(fp1,"%f%f%f",&sj[i].m,&sj[i].ac,&sj[i].gr);
	printf("深度        纵波时差  自然伽马值：\n");
	for(i=0;i<M;i++) 
	printf("%-10.4f %-10.3f %-10.3f\n",sj[i].m,sj[i].ac,sj[i].gr);
	
	if((fp2=fopen("D:\\CC\\jieguo.csv","w"))==NULL)
	{
		printf("无法打开文件\n");
		return 0;
	}
	

	for(i=0;i<M;i++)
	{
		a=((sj[i].gr-15)/75);
		jg[i].vsh=((sj[i].ac-182)/438);
		jg[i].por=((pow(2,2*a)-1)/3);
	}


     printf("计算结果：\n地层孔隙度  泥质含量\n");
	 fprintf(fp2,"%-10s,%-10s,%-10s\n","地层深度","泥质含量","地层孔隙度");
	for(i=0;i<M;i++)
	{
		fprintf(fp2,"%-10.4f,%-10.6f, %-10.5f\n",sj[i].m,jg[i].por,jg[i].vsh);

	    printf("%-10.3f  %-10.3f\n",jg[i].por,jg[i].vsh);
	}
	fclose(fp1);
	fclose(fp2);
	return 0;
}


int ps()
{
	char pw[6]={0};
	int i;
	printf("请输入密码\n");
	for(i=0;i<3;i++)
	{
		scanf("%s",pw);
		if(strcmp(pw,"2017011100")==0)
		{
			printf("登陆成功。\n");
			return (1);
		
		}
		else
		{
			printf("密码输入错误，请重新输入。\n");
		
		}
	}
	if(3==i)
	{
		printf("登陆失败，退出程序。\n");	
		return (0);
	
	}

}



save()
{
	FILE*fp;
	int i;
	printf("编号  名称  采集日期  采集方法  数据大小\n");
    fp=fopen("D:\\stu.txt","w");
	fprintf(fp,"%-10s%-10s%-10s%-10s%-10s\n","编号","名称","采集日期","采集方法","数据大小");
	for(i=0;i<N;i++)
	{
		scanf("%d%s%s%s%s",&stu[i].num,stu[i].name,stu[i].day,stu[i].how,stu[i].date);
	}
	for(i=0;i<N;i++)
	{
		fprintf(fp,"%-10d%-10s%-10s%-10s%-10s\n",stu[i].num,stu[i].name,stu[i].day,stu[i].how,stu[i].date);
	
	}
	fclose(fp);
}

read()
{
	FILE*fp;
	int i;
    fp=fopen("D:\\stu.txt","r");
	for(i=0;i<N;i++)
	{
		fscanf(fp,"%d%s%s%s%s",&stu[i].num,stu[i].name,stu[i].day,stu[i].how,stu[i].date);
		printf("%-10d%-10s%-10s%-10s%-10s\n",stu[i].num,stu[i].name,stu[i].day,stu[i].how,stu[i].date);
	}
	fclose(fp);
}


find()
{
	FILE*fp;
	int i=0;
	int m;
	int n=N+1;
	printf("请输入要查询的信息\n1.姓名\n2.日期\n3.方法\n4.数据\n5.返回\n");
	scanf("%d",&m);
	while(m!=1&&m!=2&&m!=3&&m!=4&&m!=5)
	{
		printf("输入错误\n");
		scanf("%d",&m);
	}
	if((fp=fopen("D:/stu.txt","r"))==NULL)
	{
		printf("cannot open the files\n");
	}
	if(m==1)
	{
		char s[10];
		int i=0;
		printf("输入查询姓名\n");
		scanf("\t%s",s);
		
		while(strcmp(stu[i].name,s)!=0&&i<n)i++;
		if(i==n)
		{
			printf("无");
		}
		else
			printf("\t编号:%d\n",stu[i].num);
		    printf("\t姓名:%s\n",stu[i].name);
		    printf("\t日期:%s\n",stu[i].day);
	    	printf("\t方法:%s\n",stu[i].how);
		    printf("\t数据:%s\n",stu[i].date);
		fclose(fp);
	}
	if(m==2)
	{
	    char s[10];
		int j=0;
		printf("输入查询日期\n");
		scanf("\t%s",s);
		while(strcmp(stu[j].day,s)!=0&&j<n)j++;
		if(j==n)
		{
			printf("无");
		}
		else
		printf("\t编号:%d\n",stu[j].num);
		printf("\t姓名:%s\n",stu[j].name);
		printf("\t日期:%s\n",stu[j].day);
		printf("\t方法:%s\n",stu[j].how);
		printf("\t数据:%s\n",stu[j].date);
		fclose(fp);

	}
	if(m==3)
	{
		char s[20];
		int i=0;
		printf("输入查询方法\n");
		scanf("\t%s",s);
		while(strcmp(stu[i].how,s)!=0&&i<n)i++;
		if(i==n)
		{
			printf("无");
		}
		else
		printf("\t编号:%d\n",stu[i].num);
		printf("\t姓名:%s\n",stu[i].name);
		printf("\t日期:%s\n",stu[i].day);
		printf("\t方法:%s\n",stu[i].how);
		printf("\t数据:%s\n",stu[i].date);
		fclose(fp);
	}
		if(m==4)
	{
		char s[20];
		int i=0;
		printf("输入查询数据\n");
		scanf("\t%s",s);
		while(strcmp(stu[i].date,s)!=0&&i<n)i++;
		if(i==n)
		{
			printf("无");
		}
		else
		printf("\t编号:%d\n",stu[i].num);
		printf("\t姓名:%s\n",stu[i].name);
		printf("\t日期:%s\n",stu[i].day);
		printf("\t方法:%s\n",stu[i].how);
		printf("\t数据:%s\n",stu[i].date);
		fclose(fp);
	}
		if(m==5)
		{
			return 0;
		}

}






change()
{
	FILE*fp;
	int i;
	int a;
	int b;
	fp=fopen("D:\\stu.txt","w");
	printf("是否要修改数据\n1.是\n2.否\n");
	scanf("%d",&a);
	if(a==1)
	{
		printf("请输入要修改的数据编号\n");
		scanf("%d",&b);
		if(b<=N)
		{
			fscanf(fp,"%d%s%s%s%s",&stu[b].num,stu[b].name,stu[b].day,stu[b].how,stu[b].date);
			printf("该编号数据为\n");
			printf("%-10d%-10s%-10s%-10s%-10s\n",stu[b].num,stu[b].name,stu[b].day,stu[b].how,stu[b].date);
			printf("请修改该编号数据\n");
			scanf("%d%s%s%s%s",&stu[b].num,stu[b].name,stu[b].day,stu[b].how,stu[b].date);
			for(i=0;i<N;i++)
			{
				fprintf(fp,"%-10d%-10s%-10s%-10s%-10s\n",stu[i].num,stu[i].name,stu[i].day,stu[i].how,stu[i].date);
				printf("%-10d%-10s%-10s%-10s%-10s\n",stu[i].num,stu[i].name,stu[i].day,stu[i].how,stu[i].date);
			}

		}
		else
			printf("无该编号，请重新输入\n");
	}
	if(a==2)
	{
		return 0;
	}
	if(a!=1&&a!=2)
	{
		printf("输入错误，请重新输入\n");
	}


	fclose(fp);
}





del()
{

	FILE*fp;
	int i;
	int a;
	int b;
	int c;
	fp=fopen("D:\\stu.txt","w");
	printf("是否要删除数据\n1.是\n2.否\n");
	scanf("%d",&a);
	if(a==1)
	{
		printf("请输入要删除的数据编号\n");
		scanf("%d",&b);
		if(b<=N)
		{
			b=b-1;
			for(c=b;c<N;c++)
			{
				stu[c]=stu[c+1];
			}
			for(i=0;i<N-1;i++)
			{
				fprintf(fp,"%-10d%-10s%-10s%-10s%-10s\n",stu[i].num,stu[i].name,stu[i].day,stu[i].how,stu[i].date);
				printf("%-10d%-10s%-10s%-10s%-10s\n",stu[i].num,stu[i].name,stu[i].day,stu[i].how,stu[i].date);
			}

		}
		else
			printf("无该编号，请重新输入\n");
	}
	if(a==2)
	{
		return 0;
	}
	if(a!=1&&a!=2)
	{
		printf("输入错误，请重新输入\n");
	}


	fclose(fp);
}





sort()
{
	int n=N+1,m;
	int i,j,k,l;
	for(k=0;k<n;k++)
	{
		text[k].num=stu[k].num;
		strcpy(text[k].name,stu[k].name);
		strcpy(text[k].day,stu[k].day);
		strcpy(text[k].how,stu[k].how);
		strcpy(text[k].date,stu[k].date);
		

	}
	printf("请输入要排序的数据类型\n1.测井日期\n2.测井数据\n");
	scanf("%d",&m);
	while(m!=1&&m!=2)
	{
		printf("输入错误，请重新输入\n");
		scanf("%d",&m);
	}
	if(m==1)
	{
		for(i=0;i<n;i++)
		{
			for(j=0;j<n-i-1;j++)
			{
				if(strcmp(text[j].day,text[j+1].day)<0)
				{
					emm.num=text[j+1].num;
					strcpy(emm.name,text[j+1].name);
					strcpy(emm.day,text[j+1].day);
					strcpy(emm.how,text[j+1].how);
					strcpy(emm.date,text[j+1].date);

					text[j+1].num=text[j].num;
					strcpy(text[j+1].name,text[j].name);
					strcpy(text[j+1].day,text[j].day);
					strcpy(text[j+1].how,text[j].how);
					strcpy(text[j+1].date,text[j].date);

	                text[j+1].num=emm.num;
					strcpy(text[j].name,emm.name);
					strcpy(text[j].day,emm.day);
					strcpy(text[j].how,emm.how);
					strcpy(text[j].date,emm.date);

				}
			}
		}
	}
	if(m==2)
	{
		for(i=0;i<n;i++)
		{
			for(j=0;j<n-i-1;j++)
			{
				if(strcmp(text[j].date,text[j+1].date)<0)
				{
	                emm.num=text[j+1].num;
					strcpy(emm.name,text[j+1].name);
					strcpy(emm.day,text[j+1].day);
					strcpy(emm.how,text[j+1].how);
					strcpy(emm.date,text[j+1].date);

					text[j+1].num=text[j].num;
					strcpy(text[j+1].name,text[j].name);
					strcpy(text[j+1].day,text[j].day);
					strcpy(text[j+1].how,text[j].how);
					strcpy(text[j+1].date,text[j].date);

	                text[j+1].num=emm.num;
					strcpy(text[j].name,emm.name);
					strcpy(text[j].day,emm.day);
					strcpy(text[j].how,emm.how);
					strcpy(text[j].date,emm.date);
				}
			}
		}
		
	}
	printf("排序结果如下\n");
	printf("编号  名称  采集日期  采集方法  数据大小\n");
	
	for(l=0;l<n;l++)
	{
	
		printf("%-10d%-10s%-10s%-10s%-10s\n",text[l].num,text[l].name,text[l].day,text[l].how,text[l].date);
	}



}



tongj()
{
	FILE*fp;
	int i;
	int m=0;
	int n=N+1;
	int q=0;
	char E[20];
	fp=fopen("D:\\stu.txt","r");
	if((fp=fopen("D:\\stu.txt","r"))==NULL)
	{
		printf("cannot open the files\n");
	}
	printf("请输入要统计的信息\n1.测井名称\n2.测井方法\n");
	scanf("%d",&m);
	while(m!=1&&m!=2)
	{
		printf("输入错误，请重新输入\n");
		scanf("%d",&m);
	}

	if(m==1)
	{
		printf("请输入要统计的名称\n");
		scanf("%s",E);
		for(i=1;i<n;i++)
		{
			if(strcmp(stu[i].name,E)==0)
			{
				q++;
			}
		}
		printf("要统计名称共%d个，占总数的%d/%d",q,q,N);


	}
	if(m==2)
	{
		printf("请输入要统计的方法\n");
		scanf("%s",E);
		for(i=1;i<n;i++)
		{
			if(strcmp(stu[i].how,E)==0)
			{
				q++;
			}
		}
		printf("要统计方法共%d个，占总数的%d/%d",q,q,N);


	}
	


}