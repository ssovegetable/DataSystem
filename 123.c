#include<stdio.h>
#define N 100 
//�������ɴ洢100�� 

//�洢��Ϣ���ýṹ�� 
typedef struct inf
{
	int num;
	char name[20];
	char day[20];
	char way[20];
	int data;
} INF;

//�Ѿ��洢�ĸ��� 
int saveNumber;

//���ڴ洢��Ϣ��ȫ������ 
INF inf[N];

//��������Ƿ�Ϸ���������ʽ��δ�����Ƿ���ϵ�ǰʱ��㣬�·����������������� 
int islogical(char *s){
	int i;
	//����Ƿ�Ϊ���� 
	for(i = 0;i < 8;i++)
		if(s[i] < '0' || s[i] > '9') return 0;
	//����Ƿ�Ϊ8λ 
	if(s[i] == 0) return 1;
	else return 0;
} 

//�������� 
void saveInfo(){
	//������Ϣ���� 
	int number = 0;
	int i;
	
	//��ʾ�û������������������޶�����������100
	printf("�����뱣��������������󲻳���%d��, �Ѵ洢%d������", N, saveNumber);
	while(1){
		scanf("%d", &number);
		if(number <= N-saveNumber)	break;
		else printf("�������洢�޶ȣ����������룺"); 
	}
	
	//��ʾ�û�������Ϣ 
	for (i = 0; i < number; i++){
		printf("�������%d���⾮����: �����\t����\t����\t����\t���ݣ�\n", i+1);
		int k = saveNumber+i;
		scanf("%d%s%s%s%d", &inf[k].num, inf[k].name, inf[k].day, inf[k].way, &inf[k].data);
		//��������Ƿ�Ϸ� 
		while(!islogical(inf[k].day)){
			printf("���ڲ��Ϸ����������������ڣ�");
			scanf("%s", inf[k].day); 
		}
	}
	saveNumber+=number;
	
	return ; 
}

//���ڶ�ȡ�ļ��е����ݵ�ȫ�ֱ����� 
int readFromFile(){
	//�ļ�ָ��
	FILE* fp;
	int i;
	
	//��ʼ��saveNumber 
	saveNumber = 0; 
	if ((fp = fopen("./inf.txt", "a+")) == NULL){
		printf("cannot open file\n");
		return 0;
	}
	//���ļ�����Ϣ����ȫ�ֱ���inf�� 
	while(!feof(fp)){
		fscanf(fp, "%d%s%d%s%d", &inf[saveNumber].num, inf[saveNumber].name, 
		&inf[saveNumber].day, inf[saveNumber].way, &inf[saveNumber].data);
		saveNumber++;
	}
	saveNumber--;
	
	fclose(fp);
	return 1;
}

//���ڽ�ȫ�ֱ����������Ϣ�洢���ļ���
void saveToFile(){
	//�ļ�ָ�� 
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

//������Ϣ 
void readInfo(){
	int i, select;
	
	if(saveNumber <= 0){
		printf("�ļ����޴洢���ݣ�\n");
		return ; 
	}
	
	printf("��ѡ����ķ�ʽ��1Ϊȫ�����ģ�2Ϊ�������ģ���");
	scanf("%d", &select);
	while(select != 1 && select != 2){
		printf("���벻�Ϸ������������룺");
		scanf("%d", &select);
	}
	
	//ȫ����� 
	if(select == 1){
		printf("���\t����\t����\t����\t����\n");
		for (i = 0; i < saveNumber; i++) 
		printf("%-5d\t%-10s\t%-8s\t%-10s\t%-10d\n", inf[i].num, inf[i].name, inf[i].day, inf[i].way, inf[i].data);
	}
	//������ѯ 
	else if(select == 2){
		int readNumber = 0;
		printf("�������ѯ�ڼ������ݣ�Ŀǰ�Ѵ洢%d�����ݣ���", saveNumber);
		scanf("%d", &readNumber);
		while(readNumber <= 0 || readNumber > saveNumber){
			printf("���볬����ѯ��Χ�����������룺");
			scanf("%d", &readNumber);
		}
		readNumber--;
		printf("���\t����\t����\t����\t����\n");
		printf("%-5d\t%-10s\t%-8s\t%-10s\t%-10d\n", inf[readNumber].num, inf[readNumber].name, 
		inf[readNumber].day, inf[readNumber].way, inf[readNumber].data);
	}

}

//�Ա������Ƿ���ͬ 
int isequal(char *a, char *b){
	int i = 0;
	while(a[i] == b[i] && a[i] != 0 && b[i] != 0){
		i++;
	}
	if(a[i] == 0 && b[i] == 0)
	return 1;
	else return 0;
}

//��������У�� 
int checkPassword(){
	//�����Դ���� 
	int chance = 3;
	
	//�洢���� 
	char s[25] = {0};
	
	//�˶�����
	char correct[25] = "123456"; 
	 
	//������״��޸� 
	printf("                             ��ӭ����⾮���Ϲ���ϵͳ                                   \n");
	printf("���������루������%d�λ��ᣩ��", chance);
	int z;
	for (z = 0; z < chance; z++){
		gets(s);
		//�ж������Ƿ���ȷ 
		if (isequal(s, correct)){
			printf("������ȷ��\n");
			//��ȷ����1 
			return 1;
		}
		else printf("�������, ���������루������%d�λ��ᣩ��", chance-z-1);
	}
	//�������Դ������� 0 
	return 0;
}

void changeInfo(){
	int changeNumber = 0; 
	int d = 0;
	
	printf("�������޸����ݵ���ţ�Ŀǰ�Ѵ洢%d�����ݣ���", saveNumber);
	scanf("%d", &changeNumber);
	while(changeNumber <= 0 || changeNumber > saveNumber){
		printf("���볬���洢��Χ�����������룺");
		scanf("%d", &changeNumber);
	}
	//����������� 
	changeNumber--;
	printf("���\t����\t����\t����\t����\n");
	printf("%-5d\t%-10s\t%-8s\t%-10s\t%-10d\n", inf[changeNumber].num, inf[changeNumber].name, 
	inf[changeNumber].day, inf[changeNumber].way, inf[changeNumber].data);
	//ѯ���Ƿ���� 
	printf("�Ƿ����:����ʾ��1 ���ģ�2 �����ģ�\n");
	scanf("%d", &d);
	while(d != 1 && d != 2){
		printf("���벻�Ϸ������������룺");
		scanf("%d", &d);
	}
	//d == 1����� 
	if (d == 1){
		changeNumber++; 
		printf("��������ĺ�ĵ�%d���⾮����: �����\t����\t����\t����\t���ݣ�\n", changeNumber);
		scanf("%d%s%d%s%d", inf[changeNumber].num, inf[changeNumber].name, 
		inf[changeNumber].day, inf[changeNumber].way, inf[changeNumber].data);
		printf("�ѳɹ��洢!\n"); 
	}
	else printf("ȷ�ϲ����ģ�\n");

	return ;
}

int main(){

	int i, a, b;
	
	//�������������ȷ�������ϵͳ�������˳� 
	if (checkPassword()){
		//��ѭ�������ж�η����û������˳�ʱ�����˳� 
		while(1){
			printf("\n\t\t\t\t--------��ӭ����ϵͳ����ѡ�����Ϊ��--------\n");
			printf("\t\t\t\t------------����⾮���������� 1------------\n");
			printf("\t\t\t\t------------���Ĳ⾮���������� 2------------\n");
			printf("\t\t\t\t---------���������ݽ����޸������� 3---------\n");
			printf("\t\t\t\t--------------�˳�ϵͳ������ 4--------------\n");
			printf("����������ѡ�����"); 
			scanf("%d", &a);
			
			//�����ļ�������������Ϣ 
			b = readFromFile();
			if(!b) continue;
			
			if (a == 1)	saveInfo();
			else if(a == 2) readInfo();
			else if(a == 3) changeInfo();
			//����Ϊ4����breakѭ����ϵͳ�Զ��˳� 
			else if(a == 4){
				printf("ϵͳ���˳�����л����ʹ�ã�\n");
				break; 
			}
			//�������󣬽�����ִ��ѭ������ѡ�� 
			else printf("������������������ѡ��! \n"); 
			
			//ȫ������󣬽��б���
			saveToFile();
		}
	}
	else printf("����������Σ��˳�ϵͳ��\n");
	
	return 0;
}