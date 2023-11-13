#include <iostream>
#include <vector>
#include <fstream>
#include <windows.h>
#include <time.h>
#include <stdio.h>
using namespace std;

bool sprawdz(string&a,string&s);

int main()
{
    system("cls");
    srand(time(NULL));
    printf("Wybierz baze pytan:\n1. angielski\n2. angielski techniczny\n3. sprawdzian angielski\n4. sprawdzian angielski techniczny\n0. exit\n\nTwoj wybor: ");
    fstream plik;
    switch(getchar())
    {
    case '0':       return 0;                           break;
    case '1':       plik.open("spis1.txt",ios::in);     break;
    case '2':       plik.open("spis2.txt",ios::in);     break;
    case '3':       plik.open("spr1.txt",ios::in);      break;
    case '4':       plik.open("spr2.txt",ios::in);      break;
    case '\n':      return main();                      break;
    default:
        while(getchar()!='\n');
        return main();                  break;
    }
    getchar();//'\n'
    string s;
    vector<string>polski;
    vector<string>angielski;
    polski.reserve(500);
    angielski.reserve(500);
    while(getline(plik,s))
    {
        polski.push_back(s);
        getline(plik,s);
        angielski.push_back(s);
    }
    plik.close();
    printf("\n\n");

    int w,l=0,z=0;
    for(int i=rand()%polski.size();i>=0;i--)    w=rand()%polski.size();
    for(;;l++)
    {
        cout<<polski[w]<<" - ";
        getline(cin,s);
        if(s=="0")      break;
        if(sprawdz(angielski[w],s)==true)
            for(int i=(l+1)*(z+1);i>=0;i--)    w=rand()%polski.size();
        else    z++;
    }
    printf("\nPoprawnie wykonano %d na %d razy (%d%%)\n",l-z,l,(int)(l-z)*100/l);
    system("pause");
    polski.clear();
    angielski.clear();
    return main();
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
