#include <iostream>
#include <cstring>
#include <stdio.h>
using namespace std;

void find_substr(char *strFin,char *str,char ch, char* strFind)
{
    strcat(strFin,str);
    char *pStr=0;
    pStr=strstr(str,strFind);
    while(pStr)
       {
            if(strlen(pStr)==strlen(strFind))
                strFin[strlen(strFin)]=ch;
            pStr++;
            pStr=strstr(pStr,strFind);
       }
    strFin[strlen(strFin)]=' ';

}

void programm()
{
    getchar();
    char *str=new char[1000];
    cout<<"Enter str:"<<" "<<endl;
    cin.getline(str,1000);
    cout<<str<<endl<<strlen(str);
    int len=strlen(str);
    char *str2=new char[strlen(str)];
    strcpy(str2,str);
    str2[strlen(str)]=0;
    int N=0;
    char* m = strtok(str2, " ");
    while (m)//Подсчитываем количество слов в строке
    {
        m = strtok(NULL, " ");
        N++;
    }
    len+=2*N;

    char *strFind = new char[strlen(str)];
    cout<<"Enter findStr:"<<" "<<endl;
    cin.getline(strFind,strlen(str));

    char ch;
    cout<<"Enter char";
    ch = getchar();

    char *strFin =new char[len];
    strFin[0]=0;

    strcpy(str2,str);
    char* k = strtok(str2, " ");
    while (k)//Подсчитываем количество слов в строке
    {
        find_substr(strFin,k,ch,strFind);
        k = strtok(NULL, " ");
    }

    cout<<endl<<endl<<strFin<<endl;
}

int main()
{
    char n;
    while(1)
    {
        cout<<endl<<"1 - condition"<<endl<<"2 - run"<<endl<<"3 - exit"<<endl;
        n=getchar();
        switch(n)
        {
        case '1':
            cout<<"После каждого слова строки, оканчивающегося заданной подстрокой, вставить указанный символ.";
            break;
        case '2':
        {
            programm();
            break;
        }
        case '3':
            return 0;
            break;
        default:
            cout<<"Choose the correct!";
        }
    }
}
