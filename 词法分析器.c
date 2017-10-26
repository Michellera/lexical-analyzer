#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//保留字表1-10
char keywords[15][10]={"int","break","else","char","return","continue","for","if","while","void"};   //int是1 
//分隔符表11-23
char delimiters[20][5]={"=","+","*","**",";","(",")","{","}","<",">","#","."};   //=是11
//标识符表24
char id[30][10]={""};    
//常数表25
int digitals[50]={};



//int j=0;
//int n=0;
int i;
int p=0,q=0;

int main(void){

	FILE *file,*file1;
	file1=fopen("词法分析器（结果）.txt","w");
	char string[100];
	int j0,k0=0;
	file=fopen("词法分析器.txt","r");//打开TXST.TxT文件
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
	printf("成功，请前往文件:词法分析器（结果）.txt中查看！"); 
	fprintf(file1,"class   value\n");																						
	for(i=0;i<length;i++){
		char strToken[]={""};
		ch=str[i];
		if(ch==' '|| ch=='\n' ||ch=='\t'){
			
		}
		else if(IsLetter(ch)){      //第一位为字母 
			while((IsLetter(ch) || IsDigit(ch)) && i<length){
				Concat(getLength(strToken),strToken,ch);      //将ch连接在strToken后面 
//				printf("%d  %s\n",i,strToken);
				i=i+1;     //指针向后移一位 
				ch=str[i];   //ch变为下一个ch 
			}
			i=i-1;   //指针向前移一位 
			int keyword=IsKeyword(strToken);    //判断是否为保留字 
//			printf("%d",keyword);
			if(keyword==0){      //为标识符 
				InsertId(strToken);
//				printf("%s",id[0]);
			
//				printf("24   %s\n",strToken);
				fprintf(file1,"24   %s\n",strToken);      
			}
			else{       //为保留字 
			 
//				printf("%d    %s\n",keyword,strToken);
				fprintf(file1,"%d    %s\n",keyword,strToken); 
			}
		}
		else if(IsDigit(ch)){   //为数字 
			while(IsDigit(ch)){
				Concat(getLength(strToken),strToken,ch);
				i=i+1;
				ch=str[i];
			}
			i=i-1;
//			printf("%s",strToken);
			InsertDigit(Binary(atoi(strToken)));    //将strToken字符串转化为数字插入到常数表中 
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
			fprintf(file1,"错误！\n"); 
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
//输入的字符串的长度的函数
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
//判断读入的字符是否为字母 
int IsLetter(char *ch){
	if(ch>='A'&&ch<='Z' || ch>='a'&&ch<='z'){
		return 1;
	}
	return 0;
} 
//判断读入的字符是否为数字
int IsDigit(char *ch){
	if(ch>=48&&ch<=57){
		return 1;
	}
	return 0;
}
//将字符连接到字符串后面
void Concat(int len,char *str,char ch){
	str+=len;
	*str=ch; 	
	*(++str)='\0'; 
	return;
} 
//判断是否为保留字
int IsKeyword(char *ch){
	int s;
	for(s=0;s<15;s++){
		if(strcmp(keywords[s],ch)==0){
			return s+1;     //若是保留字，则返回它的类别码 
		}
	}
	return 0;
}
//将标识符插入到标识符表中
InsertId(char *ch){
	int t,j=0;
	for(t=0;t<getLength(ch);t++){
		id[p][j]=ch[j];
		j++;
	} 
	p++;	
}
//将常数插入到常数表中
InsertDigit(int d){
	digitals[q]=d;
	q++;
} 
//将一个数字转化为二进制
int Binary(int d){
	int sum=0;int r=1;
	while(d){
		sum+=(d%2*r);
		r*=10;
		d=d/2;
	}
	return sum;  
}
//判断是否为分隔符
int IsDelimiter(char *ch){
	int h;
	for(h=0;h<20;h++){
		if(delimiters[h][0]==ch){
			return h+11;     //若是保留字，则返回它的类别码 
		}
	}
	return 0;
}

 
