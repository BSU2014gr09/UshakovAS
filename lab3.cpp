#include <iostream>
#include <cstring>
#include <iomanip>
#include <stdio.h>
using namespace std;

struct Sets
{
    char *lett = new char[1000];
    int pow;
};

char *find_set(char *str)
{

    int i=0;
    char *pStr= 0;
    str[strlen(str)]=0;
    char *str2=new char[strlen(str)];
    str2[strlen(str)] =0;
    pStr=str;
    while(*pStr)
    {
        for(int j=0; j<=strlen(str2); j++)
        {
            if(str2[j]==*pStr)
                break;
            if(j==strlen(str2))
            {
                str2[strlen(str2)]=*pStr;
                break;
            }
        }
        pStr++;
    }
    return str2;
}

void sets_init(Sets *tmp)
{
    cout<<"Enter set:";
    tmp->lett = new char[1000];
    cin.getline(tmp->lett,1000);
    tmp->lett=find_set(tmp->lett);
    tmp->pow = strlen(tmp->lett);
}

void sets_print(Sets *tmp)
{
    cout<<"set:"<<endl<<tmp->lett<<endl<<"pow"<<endl<<tmp->pow;
}

Sets sets_union(Sets set1,Sets set2)
{
    Sets tmp;
    char *str = new char[strlen(set1.lett)+strlen(set2.lett)];
    str[0]=0;
    strcat(str,set1.lett);
    strcat(str,set2.lett);
    tmp.lett = find_set(str);
    tmp.pow = strlen(tmp.lett);
    return tmp;

}

Sets intersection_sets(Sets set1,Sets set2)
{
    Sets tmp;
    int k=0;
    char *str = new char[strlen(set1.lett)+strlen(set2.lett)];
    str[0]=0;
    for(int i=0;i<strlen(set1.lett);i++)
        for(int j=0;j<strlen(set2.lett);j++)
            {
                if(set1.lett[i]==set2.lett[j]);
                    str[k]=set1.lett[i];
                    k++;
            };
    tmp.lett = find_set(str);
    tmp.pow = strlen(tmp.lett);
    return tmp;
}

void programm()
{
    getchar();
    Sets set1,set2,set3,set4;
    sets_init(&set1);
    sets_print(&set1);
    sets_init(&set2);
    sets_print(&set2);
    set3 = sets_union(set1, set2);
    sets_print(&set3);
    set4 = intersection_sets(set1, set2);
    sets_print(&set4);
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
            cout<<" Написать программу работы с множествами, элементами которого являются буквы (char). Хранить мощность множества и сами элементы в виде массива. Должны быть функции ввода, вывода, основных операций (объединение, пересечение).";
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
