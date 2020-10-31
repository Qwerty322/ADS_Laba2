#include <time.h>
#include <math.h>
#include <iostream>
#include "Tree.h"
using namespace std;
typedef unsigned long long INT_64;
//переменная и константы генератора LineRand()
static INT_64 RRand=15750;
const INT_64 mRand =(1<<63) -1;
const INT_64 aRand=6364136223846793005;
const INT_64 cRand=1442695040888963407;

//функция установки первого случайного числа от часов компьютера
void sRand () { srand(time(0)); RRand=(INT_64)rand();}

//функция генерации случайного числа
//линейный конгруэнтный генератор    Xi+1=(a*Xi+c)%m
//habr.com/ru/post/208178
INT_64 LineRand ()
{
    INT_64 y1,y2;
    y1= (aRand*RRand+cRand)%mRand;
    y2= (aRand*y1+cRand)%mRand;
    RRand = y1 & 0xFFFFFFFF00000000LL ^ (y2 & 0xFFFFFFFF00000000LL)>>32;
    return RRand;
}

void test_rand(int n)
{
    //создание дерева для 64 – разрядных ключей типа INT_64
    Tree< INT_64,int > tree;
    //массив для ключей, которые присутствуют в дереве
    INT_64* m=new INT_64 [n];
//установка первого случайного числа
    sRand();
//заполнение дерева и массива элементами со случайными ключами
    for(int i=0; i<n; i++)
    {
        m[i]=LineRand();
        tree.addNode(m[i],1);
    }
//вывод размера дерева до теста
    cout<<"items count:"<<tree.getSize()<<endl;
//обнуление счётчиков трудоёмкости вставки, удаления и поиска
    double I=0;
    double D=0;
    double S=0;
//генерация потока операций, 10% - промахи операций
    for(int i=0;i<n/2;i++)
        if(i%10==0)		//10% промахов
        {
            tree.removeNode(LineRand ());
            D+=tree.getViewNode();
            tree.addNode(m[rand()%n],1);
            I+=tree.getViewNode();
            try{
                tree.getData(LineRand ());
                S+=tree.getViewNode();
            }
                //обработка исключения при ошибке операции поиска
            catch(int){S+=tree.getViewNode();}}
        else  //90% успешных операций
        {
            int ind=rand()%n;
            tree.removeNode(m[ind]);
            D+=tree.getViewNode();
            INT_64 key=LineRand ();
            tree.addNode(key,1);
            I+=tree.getViewNode();
            m[ind]=key;
            try{
                tree.getData(m[rand()%n]);
                S+=tree.getViewNode();
            }
                //обработка исключения при ошибке операции поиска
            catch(int){S+=tree.getViewNode();}
        }	//конец теста

//вывод результатов:
//вывод размера дерева после теста
    cout<<"items count:"<<tree.getSize()<<endl;
//теоретической оценки трудоёмкости операций BST
    cout<<"1.39*log2(n)="<<1.39*(log((double)n)/log(2.0))<<endl;
//экспериментальной оценки трудоёмкости вставки
    cout<<"Count insert: " << I/(n/2) <<endl;
//экспериментальной оценки трудоёмкости удаления
    cout<<"Count delete: " << D/(n/2) <<endl;
//экспериментальной оценки трудоёмкости поиска
    cout<<"Count search: " << S/(n/2) <<endl;
//освобождение памяти массива m[]
    delete[] m;
}


