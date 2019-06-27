#include<stdio.h>
#define N 100 
//假设最大可存储100个 

//存储信息所用结构体 
typedef struct inf
{
	int num;
	char name[20];
	char day[20];
	char way[20];
	int data;
} INF;

//已经存储的个数 
int saveNumber;

//用于存储信息的全局数组 
INF inf[N];

//检测日期是否合法，仅检测格式，未考虑是否符合当前时间点，月份与天数及闰年等情况 
int islogical(char *s){
	int i;
	//检测是否为数字 
	for(i = 0;i < 8;i++)
		if(s[i] < '0' || s[i] > '9') return 0;
	//检测是否为8位 
	if(s[i] == 0) return 1;
	else return 0;
} 

//保存数据 
void saveInfo(){
	//保存信息条数 
	int number = 0;
	int i;
	
	//提示用户输入数据条数，但限定总条数少于100
	printf("请输入保存数据条数（最大不超过%d条, 已存储%d条）：", N, saveNumber);
	while(1){
		scanf("%d", &number);
		if(number <= N-saveNumber)	break;
		else printf("超过最大存储限度，请重新输入："); 
	}
	
	//提示用户输入信息 
	for (i = 0; i < number; i++){
		printf("请输入第%d条测井数据: （编号\t名称\t日期\t方法\t数据）\n", i+1);
		int k = saveNumber+i;
		scanf("%d%s%s%s%d", &inf[k].num, inf[k].name, inf[k].day, inf[k].way, &inf[k].data);
		//检测日期是否合法 
		while(!islogical(inf[k].day)){
			printf("日期不合法！请重新输入日期：");
			scanf("%s", inf[k].day); 
		}
	}
	saveNumber+=number;
	
	return ; 
}

//用于读取文件中的数据到全局变量中 
int readFromFile(){
	//文件指针
	FILE* fp;
	int i;
	
	//初始化saveNumber 
	saveNumber = 0; 
	if ((fp = fopen("./inf.txt", "a+")) == NULL){
		printf("cannot open file\n");
		return 0;
	}
	//将文件内信息放入全局变量inf内 
	while(!feof(fp)){
		fscanf(fp, "%d%s%d%s%d", &inf[saveNumber].num, inf[saveNumber].name, 
		&inf[saveNumber].day, inf[saveNumber].way, &inf[saveNumber].data);
		saveNumber++;
	}
	saveNumber--;
	
	fclose(fp);
	return 1;
}

//用于将全局变量保存的信息存储到文件中
void saveToFile(){
	//文件指针 
	FILE* fp;
	int i; 
	
	if ((fp = fopen("./inf.txt", "w")) == NULL){
		printf("cannot open file!\n");
		return;
	}
	for (i = 0; i < saveNumber; i++)
		fprintf(fp, "%-5d %-10s %-8s %-10s %-10d\n", inf[i].num, inf[i].name, inf[i].day, inf[i].way, inf[i].data);
	fclose(fp);
	
	return ;
 } 

//查阅信息 
void readInfo(){
	int i, select;
	
	if(saveNumber <= 0){
		printf("文件内无存储数据！\n");
		return ; 
	}
	
	printf("请选择查阅方式（1为全部查阅，2为单条查阅）：");
	scanf("%d", &select);
	while(select != 1 && select != 2){
		printf("输入不合法，请重新输入：");
		scanf("%d", &select);
	}
	
	//全部输出 
	if(select == 1){
		printf("编号\t名称\t日期\t方法\t数据\n");
		for (i = 0; i < saveNumber; i++) 
		printf("%-5d\t%-10s\t%-8s\t%-10s\t%-10d\n", inf[i].num, inf[i].name, inf[i].day, inf[i].way, inf[i].data);
	}
	//单个查询 
	else if(select == 2){
		int readNumber = 0;
		printf("请输入查询第几条数据（目前已存储%d条数据）：", saveNumber);
		scanf("%d", &readNumber);
		while(readNumber <= 0 || readNumber > saveNumber){
			printf("输入超出查询范围，请重新输入：");
			scanf("%d", &readNumber);
		}
		readNumber--;
		printf("编号\t名称\t日期\t方法\t数据\n");
		printf("%-5d\t%-10s\t%-8s\t%-10s\t%-10d\n", inf[readNumber].num, inf[readNumber].name, 
		inf[readNumber].day, inf[readNumber].way, inf[readNumber].data);
	}

}

//对比密码是否相同 
int isequal(char *a, char *b){
	int i = 0;
	while(a[i] == b[i] && a[i] != 0 && b[i] != 0){
		i++;
	}
	if(a[i] == 0 && b[i] == 0)
	return 1;
	else return 0;
}

//进行密码校验 
int checkPassword(){
	//密码试错机会 
	int chance = 3;
	
	//存储密码 
	char s[25] = {0};
	
	//核对密码
	char correct[25] = "123456"; 
	 
	//进入后首次修改 
	printf("                             欢迎进入测井资料管理系统                                   \n");
	printf("请输入密码（您共有%d次机会）：", chance);
	int z;
	for (z = 0; z < chance; z++){
		gets(s);
		//判断密码是否正确 
		if (isequal(s, correct)){
			printf("密码正确！\n");
			//正确返回1 
			return 1;
		}
		else printf("密码错误, 请重新输入（您还有%d次机会）：", chance-z-1);
	}
	//超过尝试次数返回 0 
	return 0;
}

void changeInfo(){
	int changeNumber = 0; 
	int d = 0;
	
	printf("请输入修改数据的组号（目前已存储%d条数据）：", saveNumber);
	scanf("%d", &changeNumber);
	while(changeNumber <= 0 || changeNumber > saveNumber){
		printf("输入超出存储范围，请重新输入：");
		scanf("%d", &changeNumber);
	}
	//输出此条数据 
	changeNumber--;
	printf("编号\t名称\t日期\t方法\t数据\n");
	printf("%-5d\t%-10s\t%-8s\t%-10s\t%-10d\n", inf[changeNumber].num, inf[changeNumber].name, 
	inf[changeNumber].day, inf[changeNumber].way, inf[changeNumber].data);
	//询问是否更改 
	printf("是否更改:（提示：1 更改；2 不更改）\n");
	scanf("%d", &d);
	while(d != 1 && d != 2){
		printf("输入不合法，请重新输入：");
		scanf("%d", &d);
	}
	//d == 1则更改 
	if (d == 1){
		changeNumber++; 
		printf("请输入更改后的第%d条测井数据: （编号\t名称\t日期\t方法\t数据）\n", changeNumber);
		scanf("%d%s%d%s%d", inf[changeNumber].num, inf[changeNumber].name, 
		inf[changeNumber].day, inf[changeNumber].way, inf[changeNumber].data);
		printf("已成功存储!\n"); 
	}
	else printf("确认不更改！\n");

	return ;
}

int main(){

	int i, a, b;
	
	//如果密码输入正确，则进入系统，否则退出 
	if (checkPassword()){
		//死循环，进行多次服务，用户输入退出时方可退出 
		while(1){
			printf("\n\t\t\t\t--------欢迎进入系统，可选择服务为：--------\n");
			printf("\t\t\t\t------------输入测井数据请输入 1------------\n");
			printf("\t\t\t\t------------查阅测井资料请输入 2------------\n");
			printf("\t\t\t\t---------对已有数据进行修改请输入 3---------\n");
			printf("\t\t\t\t--------------退出系统请输入 4--------------\n");
			printf("请输入数字选择服务："); 
			scanf("%d", &a);
			
			//读入文件内所有数据信息 
			b = readFromFile();
			if(!b) continue;
			
			if (a == 1)	saveInfo();
			else if(a == 2) readInfo();
			else if(a == 3) changeInfo();
			//输入为4，则break循环，系统自动退出 
			else if(a == 4){
				printf("系统已退出，感谢您的使用！\n");
				break; 
			}
			//输入有误，将重新执行循环进行选择 
			else printf("您的输入有误，请重新选择! \n"); 
			
			//全部输入后，进行保存
			saveToFile();
		}
	}
	else printf("密码错误三次，退出系统！\n");
	
	return 0;
}