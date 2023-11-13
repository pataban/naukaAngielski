#include<iostream>
#include<stdio.h>
#include<cstdlib>
#include<math.h>
#include<string>
#include<vector>
#include <fstream>
#include <windows.h>
#include <time.h>
#define prt(a) printf("%d\n",a);
#define rand(a) (rand()%a)
#define aaa printf("a\n");
#define bbb printf("b\n");
#define ccc printf("c\n");
using namespace std;

int menu(string&plikn);
int otworz(fstream&plik,string&plikn);
void wczytaj(string*pol,string*ang,fstream&plik,const int&plikdl);
void mieszaj(int*kol,int siz);
bool sprawdz(string&a,string&s);

int main()
{
    string plikn="";
    if(menu(plikn)==0)      return 0;
    fstream plik;
    int plikdl=otworz(plik,plikn);
    if(plikdl==0)       return main();
    string*pol=new string[plikdl];
    string*ang=new string[plikdl];
    wczytaj(pol,ang,plik,plikdl);

    int*kol=new int[plikdl];
    for(int*w=kol;w<kol+plikdl;w++) *w=w-kol;
    int ile=0,iled=0;
    string odp="";
    while(odp!="0")
    {
        mieszaj(kol,plikdl);
        for(int i=0;i<plikdl;i++,ile++)
        {
            printf("%s - ",pol[kol[i]].c_str());
            getline(cin,odp);
            if(odp=="0")      break;
            if(sprawdz(ang[kol[i]],odp)==true)   iled++;
            else    i--;
        }
        printf("\n\nWykonano caly spis\n\n");
    }

    if(ile)     printf("\nPoprawnie wykonano %d na %d razy (%d%%)\n",iled,ile,(int)iled*100/ile);
    system("pause");
    delete[]pol;
    delete[]ang;
    return main();
}

int menu(string&plikn)
{
    system("cls");
    printf("Wybierz baze pytan:\n1. angielski\n2. angielski techniczny\n3. sprawdzian angielski\n4. sprawdzian angielski techniczny\n0. exit\n\nTwoj wybor: ");
    switch(getchar())
    {
    case '0':       return 0;           break;
    case '1':       plikn="spis1.txt";  break;
    case '2':       plikn="spis2.txt";  break;
    case '3':       plikn="spr1.txt";   break;
    case '4':       plikn="spr2.txt";   break;
    case '\n':      return menu(plikn);      break;
    default:
        while(getchar()!='\n');
        return menu(plikn);                  break;
    }
    getchar();//'\n'
    return 1;
}

int otworz(fstream&plik,string&plikn)
{
    plik.open(plikn.c_str(),ios::in);
    if(!plik.good())
    {
        printf("Brak bazy danych!\n");
        system("pause");
        return 0;
    }
    int plikdl=0;
    string s;
    while(getline(plik,s))    plikdl++;
    if(plikdl%2!=0)
    {
        printf("Bledna baza danych!\n");
        system("pause");
        return 0;
    }
    plikdl/=2;
    plik.close();
    plik.open(plikn.c_str(),ios::in);
    return plikdl;
}

void wczytaj(string*pol,string*ang,fstream&plik,const int&plikdl)
{
    for(string*wp=pol,*wa=ang;wp<pol+plikdl;wp++,wa++)
    {
        getline(plik,*wp);
        getline(plik,*wa);
    }
    plik.close();
    printf("\n\n");
}

void mieszaj(int*kol,int siz)
{
    srand(time(NULL));
    int ile_razy=siz*100;
    int *a,*b,buf;
    a=kol+rand(siz);
    while(ile_razy--)
    {
        b=kol+rand(siz);
        buf=*a;
        *a=*b;
        *b=buf;
    }
}

bool sprawdz(string&a,string&s)
{
    if(a==s)
    {
        printf("dobrze\n---------------------------------------\n");
        return true;
    }
    printf("zle\nPoprawna odpowiedz - %s\n---------------------------------------\n",a.c_str());
    return false;
}
