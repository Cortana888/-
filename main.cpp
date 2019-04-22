#include<bits/stdc++.h>
#include<windows.h>
#include<mmsystem.h>
#pragma comment(lib, "winmm.lib")
using namespace std;
const int Max = 1024;
char contents[Max][Max];       //目录名称
char name[Max];                //文件名
char str[Max];                 //临时字符串
char str2[Max];
FILE *fp1,*fp2;                //目录，文档的文件指针
int Count;                     //记录目录个数

typedef struct{
char data[Max][Max];           //存放字符
int wordcount;                 //存放字数
int linenumber;                //存放行数
}SqString;
SqString *s;

void fun(){

cout<<endl;
cout<<endl;
cout<<"                     ,----------------,              ,---------, "<<endl;
cout<<"                ,-----------------------,          ,'        ,'| "<<endl;
cout<<"              ,'                      ,'|        ,'        ,'  | "<<endl;
cout<<"             +-----------------------+  |      ,'        ,'    | "<<endl;
cout<<"             |  .-----------------.  |  |     +---------+      | "<<endl;
cout<<"             |  |                 |  |  |     | -==----'|      | "<<endl;
cout<<"             |  |  I LOVE C++!    |  |  |     |         |      | "<<endl;
cout<<"             |  |  欢迎使用编译器!|  |  |/----|`---=    |      | "<<endl;
cout<<"             |  |  C:\>_           |  |  |   ,/|==== ooo |      ; "<<endl;
cout<<"             |  |                 |  |  |  // |(((( [33]|    ,'  "<<endl;
cout<<"             |  `-----------------'  |,' .' | |((((     |  ,'    "<<endl;
cout<<"             +-----------------------+  ;;  | |         |,'      "<<endl;
cout<<"                /_)______________(_/  //'   | +---------+        "<<endl;
cout<<"           ___________________________/___  `,                   "<<endl;
cout<<"          /  oooooooooooooooo  .o.  oooo /,  \\,'-----------     "<<endl;
cout<<"         / ==ooooooooooooooo==.o.  ooo= //  ,`\\--{)      ,'     "<<endl;
cout<<"        /_==__==========__==_ooo__ooo=_/'   /___________,'       "<<endl;

cout<<endl;
cout<<endl;
cout<<endl;
cout<<endl;

}

void show1(){
   cout<<"┌────────── 简易文本编辑器───────────┐"<<endl;
   cout<<"│ 1.新建文档                         │"<<endl;
   cout<<"│ 2.打开文档                         │"<<endl;
   cout<<"│ 3.删除文档                         │"<<endl;
   cout<<"│ 4.退出程序                         │"<<endl;
   cout<<"└────────────────────────────────────┘"<<endl;
}

void show2(){
   cout<<"┌────────── 简易文本编辑器──────────┐"<<endl;
   cout<<"│ 1.字数行数统计                    │"<<endl;
   cout<<"│ 2.文字插入                        │"<<endl;
   cout<<"│ 3.文字删除                        │"<<endl;
   cout<<"│ 4.文字查找                        │"<<endl;
   cout<<"│ 5.文字替换                        │"<<endl;
   cout<<"│ 6.关闭文档并退出                  │"<<endl;
   cout<<"└───────────────────────────────────┘"<<endl;
}

void content(){                                                    //输出目录
   if((fp1=fopen("C:\\Users\\MA\\Desktop\\数据结构课设\\目录.txt","r"))==NULL){
        cout<<"cannot open this file"<<endl;
        exit(0);
      }
   char ch;
   Count=1;
   int j=0;
   while(!feof(fp1)){
        ch=fgetc(fp1);
        if(ch=='&'){
           contents[Count][j]='\0';
           Count++;
           j=0;
        }
        else{
           contents[Count][j]=ch;
           j++;
        }
   }
   for(int k=1;k<Count;k++){
        cout<<k<<"."<<contents[k]<<endl;
   }
}


void show(int number){                                             //输出文章名称和内容
   s = (SqString*)malloc(sizeof(SqString));
   s->wordcount=0;
   s->linenumber=0;
   cout<<"    <<"<<contents[number]<<">>"<<endl;
   char arr[Max]={"C:\\Users\\MA\\Desktop\\数据结构课设\\"};
   strcat(arr, contents[number]);
   strcat(arr,".txt");
   if((fp2=fopen(arr,"r"))==NULL){
      cout<<"cannot open this file"<<endl;
      exit(0);
      }
   int i=0;
   char ch;
   while(!feof(fp2)){
        ch=fgetc(fp2);
        if(ch=='&'){
           s->data[s->linenumber][i]='\0';
           i=0;
           s->linenumber++;
           s->wordcount++;
        }
        else{
           if(ch==' '){
              s->wordcount++;
           }
           s->data[s->linenumber][i]=ch;
           i++;
        }
   }
   for(int i=0;i<s->linenumber;i++){
        cout<<s->data[i]<<endl;
   }
}


void Search(){
   bool flag = false;
   int len = strlen(str);
   int k = 0;
   int line=1,row=1;
   for(int i=0;i<s->linenumber;i++){
        for(int j=0;s->data[i][j]!='\0';j++){
           if(s->data[i][j]==str[k]){
                k++;
           }
           else{
                k = 0;
                if(str[0]==s->data[i][j]){
                        j--;
                }
                if(s->data[i][j+1]=='\0'){
                        row=1;
                        line = i+2;
                }
                else{
                        line = i+1;
                        row = j+2;
                }
           }
           if(k==len){
                k = 0;
                flag = true;
                cout<<"您要查找的内容在第"<<line<<"行第"<<row<<"个"<<"字符处出现"<<endl;
                line = i+1;
                if(s->data[i][j+1]=='\0'){
                        row=1;
                        line = i+2;
                }
                else{
                        row = j+2;
                        line = i+1;
                }
           }
        }
        }
   if(!flag){
        cout<<"你要查找的内容不存在！"<<endl;
   }
}

void Insert(int a,int b){
   int len = strlen(str);
   int len2=strlen(s->data[a-1]);
   if(a>s->linenumber){
        for(int i=s->linenumber;i<a-1;i++){
                s->data[i][0]='\0';
        }
        for(int i=0;i<b-1;i++){
                s->data[a-1][i]=' ';
        }
         for(int i=0;i<=len;i++){
                s->data[a-1][b-1+i]=str[i];
        }
        s->linenumber=a;
   }
   else{
   if(b<len2){
   int ans=len2-1;
   for(int j=ans+len;j>=b+len-1;j--,ans--){
        s->data[a-1][j]=s->data[a-1][ans];
   }
   for(int j=b-1,k=0;k<len;k++,j++){
        s->data[a-1][j]=str[k];
   }
   }
   else{
        int ans=b-1-len2;
        for(int i=0;i<ans;i++){
                s->data[a-1][len2+i]=' ';
        }
        for(int i=0;i<=len;i++){
                s->data[a-1][b-1+i]=str[i];
        }
   }
   }
   cout<<"插入成功,插入后的结果为："<<endl;
   for(int i=0;i<s->linenumber;i++){
        cout<<s->data[i]<<endl;
   }
}


void Delete(int a1,int b1,int a2,int b2){
   if(a1>a2){}
   else if(a1==a2){
        for(int i=b2;s->data[a1-1][i]!='\0';i++){
                s->data[a1-1][b1-1]=s->data[a1-1][i];
                b1++;
        }
        s->data[a1-1][b1-1]='\0';
   }
   else{
        s->data[a1-1][b1-1]='\0';
        for(int i=a1+1;i!=a2;i++){
           s->data[i-1][0]='\0';
        }
        int i;
        for(i=0;s->data[a2-1][b2]!='\0';i++,b2++){
           s->data[a2-1][i]=s->data[a2-1][b2];
        }
        s->data[a2-1][i]='\0';
   }
   cout<<"删除成功,删除后的结果为："<<endl;
   for(int i=0;i<s->linenumber;i++){
        if(s->data[i][0]=='\0'){
                continue;
        }
        cout<<s->data[i]<<endl;
   }

}

char *strrpl(char *s,const char *s1,const char *s2){
   char *ptr;
   while(ptr = strstr(s,s1)){
        memmove(ptr+strlen(s2),ptr+strlen(s1),strlen(ptr)-strlen(s1)+1);
        memcpy(ptr,&s2[0],strlen(s2));
   }
   return s;
}

void Repect(){
   for(int i=0;i<s->linenumber;i++){
        char *p=strrpl(s->data[i],str,str2);
        for(int j=0;;p++,j++){
                s->data[i][j]=*p;
                if(*p=='\0'){
                        break;
                }
        }
   }
   cout<<"替换成功,删替换后的结果为："<<endl;
   for(int i=0;i<s->linenumber;i++){
        if(s->data[i][0]=='\0'){
                continue;
        }
        cout<<s->data[i]<<endl;
   }
}


void closefile(){                                                  //关闭打开的文件
   fclose(fp1);
   fclose(fp2);
}

void savefile(){                                                   //保存编辑好的文档
   if((fp1=fopen("C:\\Users\\MA\\Desktop\\数据结构课设\\目录.txt","a"))==NULL){
      cout<<"cannot open this file"<<endl;
      exit(0);
      }
   fputs(name,fp1);
   fputc('&',fp1);
   char arr[Max]={"C:\\Users\\MA\\Desktop\\数据结构课设\\"};
   strcat(arr,name);
   strcat(arr,".txt");
   if((fp2=fopen(arr,"w"))==NULL){
      cout<<"cannot open this file"<<endl;
      exit(0);
      }
   for(int i=0;strcmp(s->data[i],"EOF")!=0;i++){
        fputs(s->data[i],fp2);
        fputc('&',fp2);
   }
}

void  creatfile(){                                                 //新建文档
   s = (SqString*)malloc(sizeof(SqString));
   cout<<"请输入新建文档的名称以回车结束：";
   gets(name);
   cout<<"请输入文档的内容以EOF结束："<<endl;
   int i=0;
   gets(s->data[i]);
   while(strcmp(s->data[i],"EOF")!=0){
        i++;
        gets(s->data[i]);
   }
   while(1){
        cout<<"文档编辑完成，是否需要保存？(Yes/No)"<<endl;
        char judge[20];
        gets(judge);
        if(strcmp(judge,"Yes")==0){
           savefile();
           cout<<"文档保存成功！"<<endl;
           free(s);
           closefile();
           break;
        }
        else if(strcmp(judge,"No")==0){
           free(s);
           break;
        }
        else{
           cout<<"输入错误!请输入英文字母Yes/No"<<endl;
           continue;
        }
}
}

bool deletefile(){                                                 //删除文档
   bool flag;
   cout<<"目录："<<endl;
   content();
   int number;
   char ans[Max];
   while(1){
      cout<<"请选择要删除文档的序号：";
      cin>>ans;
      if(ans[0]-'0'<=0||ans[0]-'0'>=Count || ans[1]!='\0'){
        cout<<"输入的序号有误，请输入1-"<<Count-1<<"之间的整数"<<endl;
      }
      else{
        number = ans[0]-'0';
        break;
      }
   }
   static int mark = number;
   char arr[Max]={"C:\\Users\\MA\\Desktop\\数据结构课设\\"};
   strcat(arr,contents[number]);
   strcat(arr,".txt");
   flag = remove(arr)==0?true:false;
   if((fp1=fopen("C:\\Users\\MA\\Desktop\\数据结构课设\\目录.txt","w"))==NULL){
      cout<<"cannot open this file"<<endl;
      exit(0);
      }
   for(int i=1;i<Count;i++){
        if(i==mark){
                continue;
        }
        else{
                fputs(contents[i],fp1);
                fputc('&',fp1);
        }
   }
   fclose(fp1);
   return flag;
}

void openfile(){                                                   // 打开文档
   cout<<"目录："<<endl;
   content();
   int number;
   char ans[Max];
   while(1){
      cout<<"请选择要打开文档的序号：";
      cin>>ans;
      if(ans[0]-'0'<=0||ans[0]-'0'>=Count || ans[1]!='\0'){
        cout<<"输入的序号有误，请输入1-"<<Count-1<<"之间的整数"<<endl;
      }
      else{
        number = ans[0]-'0';
        break;
      }
   }
   show(number);
   while(1){
        show2();
        char ans;
        cout<<"请选择以上功能对文本进行编辑:";
        cin>>ans;
        getchar();
        switch(ans-'0'){
           case 1:
                cout<<"文章字数："<<s->wordcount<<"  "<<"行数："<<s->linenumber<<endl;
                cout<<endl;
                break;
           case 2:
                cout<<"请输入插入位置和内容，以回车结束(行 列 内容)"<<endl;
                int a,b;
                cin>>a>>b;
                getchar();
                gets(str);
                Insert(a,b);
                break;
           case 3:
                cout<<"请输入要删除内容的开始位置和结束位置(行 列 行 列)"<<endl;
                int a1,b1,a2,b2;
                cin>>a1>>b1>>a2>>b2;
                Delete(a1,b1,a2,b2);
                break;
           case 4:
                cout<<"请输入要查找的内容，以回车结束:"<<endl;
                gets(str);
                Search();
                break;
           case 5:
                cout<<"请输入要查找的内容:";
                gets(str);
                cout<<"替换为:";
                gets(str2);
                Repect();
                break;
           case 6:
                while(1){
                   cout<<"是否保存对文本的修改？Yes/No"<<endl;
                   char judge[20];
                   gets(judge);
                   if(strcmp(judge,"Yes")==0){
                        char arr[]={"C:\\Users\\MA\\Desktop\\数据结构课设\\"};
                        strcat(arr,contents[number]);
                        strcat(arr,".txt");
                        if((fp2=fopen(arr,"w"))==NULL){
                           cout<<"cannot open this file"<<endl;
                           exit(0);
                        }
                        for(int i=0;i<s->linenumber;i++){
                           for(int j=0;s->data[i][j]!='\0';j++){
                                fputc(s->data[i][j],fp2);
                           }
                           if(s->data[i][0]!='\0'){
                               fputc('&',fp2);
                           }
                        }
                        cout<<"文档保存成功！"<<endl;
                        break;
                   }
                   else if(strcmp(judge,"No")==0){
                        break;
                   }
                   else{
                        cout<<"输入错误!请输入英文字母Yes/No"<<endl;
                        continue;
                   }
                }
                closefile();
                goto loop;
           default:
                cout<<"输入错误!请输入1-6之间的整数"<<endl;
                break;
   }
}
loop:
free(s);
}


int main(){                                                                      //主函数
fun();
system("color B0");
char number;
while(1){
        show1();
        cout<<"请选择以上功能:";
        cin>>number;
        getchar();
        switch(number-'0'){
           case 1:
                creatfile();
                break;
           case 2:
                openfile();
                break;
           case 3:
                if(deletefile()){
                   cout<<"删除成功"<<endl;
                }
                else{
                   cout<<"删除失败，请重试！"<<endl;
                }
                break;
           case 4:
                while(1){
                   cout<<"您是否要退出？Yes/No"<<endl;
                   char judge[20];
                   gets(judge);
                   if(strcmp(judge,"Yes")==0){
                        exit(0);
                   }
                   else if(strcmp(judge,"No")==0){
                        break;
                   }
                   else{
                        cout<<"输入错误!请输入英文字母Yes/No"<<endl;
                        continue;
                   }
                }
                break;
           default:
                cout<<"输入错误!请输入1-4之间的整数"<<endl;
                break;
        }
}
return 0;
}
