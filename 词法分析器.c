#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//�����ֱ�1-10
char keywords[15][10]={"int","break","else","char","return","continue","for","if","while","void"};   //int��1 
//�ָ�����11-23
char delimiters[20][5]={"=","+","*","**",";","(",")","{","}","<",">","#","."};   //=��11
//��ʶ����24
char id[30][10]={""};    
//������25
int digitals[50]={};



//int j=0;
//int n=0;
int i;
int p=0,q=0;

int main(void){

	FILE *file,*file1;
	file1=fopen("�ʷ��������������.txt","w");
	char string[100];
	int j0,k0=0;
	file=fopen("�ʷ�������.txt","r");//��TXST.TxT�ļ�
	char ch0;
	while((ch0=fgetc(file))!=EOF){
		string[k0++]=ch0;
	}
	string[k0]='\0';
//	printf("%s\n",string);




	
	char str[100]={};
	strcpy(str,string);
	str[k0]='\0';
//	printf("%s\n",str);



	
//	int w;
//	for(w=0;w<100;w++){
//		str[w]=getchar();
//		if(str[w]=='~'){
//			str[w]='\0';
//			break;
//		}
//	}	
	char ch;
		
	int length=getLength(str);
	printf("�ɹ�����ǰ���ļ�:�ʷ��������������.txt�в鿴��"); 
	fprintf(file1,"class   value\n");																						
	for(i=0;i<length;i++){
		char strToken[]={""};
		ch=str[i];
		if(ch==' '|| ch=='\n' ||ch=='\t'){
			
		}
		else if(IsLetter(ch)){      //��һλΪ��ĸ 
			while((IsLetter(ch) || IsDigit(ch)) && i<length){
				Concat(getLength(strToken),strToken,ch);      //��ch������strToken���� 
//				printf("%d  %s\n",i,strToken);
				i=i+1;     //ָ�������һλ 
				ch=str[i];   //ch��Ϊ��һ��ch 
			}
			i=i-1;   //ָ����ǰ��һλ 
			int keyword=IsKeyword(strToken);    //�ж��Ƿ�Ϊ������ 
//			printf("%d",keyword);
			if(keyword==0){      //Ϊ��ʶ�� 
				InsertId(strToken);
//				printf("%s",id[0]);
			
//				printf("24   %s\n",strToken);
				fprintf(file1,"24   %s\n",strToken);      
			}
			else{       //Ϊ������ 
			 
//				printf("%d    %s\n",keyword,strToken);
				fprintf(file1,"%d    %s\n",keyword,strToken); 
			}
		}
		else if(IsDigit(ch)){   //Ϊ���� 
			while(IsDigit(ch)){
				Concat(getLength(strToken),strToken,ch);
				i=i+1;
				ch=str[i];
			}
			i=i-1;
//			printf("%s",strToken);
			InsertDigit(Binary(atoi(strToken)));    //��strToken�ַ���ת��Ϊ���ֲ��뵽�������� 
//			printf("%d\n",digitals[0]);
//			printf("25   %d\n",Binary(atoi(strToken)));
			fprintf(file1,"25   %d\n",Binary(atoi(strToken)));
		}
		else if(ch=='='){
//			printf("%d    =\n",IsDelimiter(ch));
			fprintf(file1,"%d    =\n",IsDelimiter(ch));
		}
		else if(ch=='+'){
//			printf("%d    +\n",IsDelimiter(ch));
			fprintf(file1,"%d    +\n",IsDelimiter(ch));
		}
		else if(ch=='*'){
			i=i+1;
			ch=str[i];
			if(ch=='*'){
//				printf("14   **\n");
				fprintf(file1,"14   **\n");
				
			}else{
//				printf("13   *\n");
				fprintf(file1,"13   *\n");
				i=i-1;
			} 
//			i=i-1;
//			printf("%d   *\n",IsDelimiter(str[i]));
		}
		else if(ch==';'){
			fprintf(file1,"%d    ;\n",IsDelimiter(ch));
		}
		else if(ch=='('){
			fprintf(file1,"%d    (\n",IsDelimiter(ch));
		}
		else if(ch==')'){
			fprintf(file1,"%d    )\n",IsDelimiter(ch));
		}
		else if(ch=='{'){
			fprintf(file1,"%d    {\n",IsDelimiter(ch));
		}
		else if(ch=='}'){
			fprintf(file1,"%d    }\n",IsDelimiter(ch));
		}
		else if(ch=='>'){
			fprintf(file1,"%d    >\n",IsDelimiter(ch));
		}
		else if(ch=='<'){
			fprintf(file1,"%d    <\n",IsDelimiter(ch));
		}
		else if(ch=='#'){
			fprintf(file1,"%d    #\n",IsDelimiter(ch));
		}
		else if(ch=='.'){
			fprintf(file1,"%d    .\n",IsDelimiter(ch));
		}
		
		else{
			fprintf(file1,"����\n"); 
		}
	}
	
	
	
	
	
	
	
//	while(j<100){
//		if(ch[j]){
//			strToken[j]=ch[j];
//			j++;
//		}else{
//			strToken[j]='\0';
//			break;
//		}
//	}
//	int key=IsKeyword(strToken);
//	printf("%d    %s",key,strToken);



	return 0;
}
//������ַ����ĳ��ȵĺ���
int getLength(char *str){
	int len=0,k;
	for(k=0;k<100;k++){
		if(str[k]!='\0'){
			len++;
		}else{
			break;
		} 
	}
	return len;
} 
//�ж϶�����ַ��Ƿ�Ϊ��ĸ 
int IsLetter(char *ch){
	if(ch>='A'&&ch<='Z' || ch>='a'&&ch<='z'){
		return 1;
	}
	return 0;
} 
//�ж϶�����ַ��Ƿ�Ϊ����
int IsDigit(char *ch){
	if(ch>=48&&ch<=57){
		return 1;
	}
	return 0;
}
//���ַ����ӵ��ַ�������
void Concat(int len,char *str,char ch){
	str+=len;
	*str=ch; 	
	*(++str)='\0'; 
	return;
} 
//�ж��Ƿ�Ϊ������
int IsKeyword(char *ch){
	int s;
	for(s=0;s<15;s++){
		if(strcmp(keywords[s],ch)==0){
			return s+1;     //���Ǳ����֣��򷵻���������� 
		}
	}
	return 0;
}
//����ʶ�����뵽��ʶ������
InsertId(char *ch){
	int t,j=0;
	for(t=0;t<getLength(ch);t++){
		id[p][j]=ch[j];
		j++;
	} 
	p++;	
}
//���������뵽��������
InsertDigit(int d){
	digitals[q]=d;
	q++;
} 
//��һ������ת��Ϊ������
int Binary(int d){
	int sum=0;int r=1;
	while(d){
		sum+=(d%2*r);
		r*=10;
		d=d/2;
	}
	return sum;  
}
//�ж��Ƿ�Ϊ�ָ���
int IsDelimiter(char *ch){
	int h;
	for(h=0;h<20;h++){
		if(delimiters[h][0]==ch){
			return h+11;     //���Ǳ����֣��򷵻���������� 
		}
	}
	return 0;
}

 
