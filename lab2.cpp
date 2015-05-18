#include <iostream>
#include <cstring>
#include <ctime>
#include <cstdlib>
#include <iomanip>
#include <cstring>
#include <stdio.h>
using namespace std;

void del(int** arr, int M)
{
    for(int i=0; i<M; i++)
        delete []arr[i];
    delete []arr;
}

void my_swap(int *a, int **arr)
{
    cout<<endl<<a[0]<<endl;
    int i=a[1];
    int j=a[2];
    int tmp = arr[i][j];
    arr[i][j]=arr[j][i];
    arr[j][i]=tmp;
}

void max_lowtr(int** arr, int const N, int *max_arr)
{
    for(int i=0;i<N;i++)
        for(int j=0;j<=i;j++)
            {
                if(arr[i][j]>max_arr[0])
                    {
                        max_arr[0]=arr[i][j];
                        max_arr[1]=i;
                        max_arr[2]=j;
                    }
            };
}

void max_uptr(int** arr, int const N, int *max_arr)
{
    for(int i=0;i<N;i++)
        for(int j=i;j<N;j++)
            {
                if(arr[i][j]>max_arr[0])
                    {
                        max_arr[0]=arr[i][j];
                        max_arr[1]=i;
                        max_arr[2]=j;
                    }
            }
}

int ** allocate(int const N)
{
    int **arr= new int* [N];

    for(int i=0; i<N; i++)
        arr[i] = new int[N];
    return arr;
}

void initial(int **arr,int const N)
{
    srand(time(0));
	for (int i = 0; i < N; i++)
	{
		for (int j=0; j < N; j++)
			arr[i][j] = rand()%100;
	}
}

void printArr(int** Arr,int const N)
{
    for(int i=0; i<N; i++)
    {
        for(int j=0; j<N; j++)
        {
            cout<<setw(5)<<Arr[i][j]<<" ";
        }
        cout<<endl;
    }
}

void programm()
{
    int **arr=0;
    int N=5;
    arr = allocate(N);
    initial(arr, N);
    printArr(arr, N);
    int mlow[3] = {0};//Массив, в котором хранится максимальный элемент и его индекс
    int mup[3]={0};//Массив, в котором хранится максимальный элемент и его индекс
    max_lowtr(arr, N, mlow);
    max_uptr(arr, N, mup);
    cout<<mlow[0]<<" "<<endl;
    my_swap(mlow, arr);
    my_swap(mup, arr);
    printArr(arr, N);
    del(arr, N);
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
            cout<<"В массиве А(N,N) поменять местами максимальные элементы нижнего и верхнего треугольников относительно главной диагонали.";
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
