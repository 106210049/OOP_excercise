#include<iostream>
#include<windows.h>
#include<stdio.h>
#include<math.h>
#include<string.h>
using namespace std;

class person{
    protected:
    char *HT;
    char *NS;
    char *Q;
    public:
    person(const char *hoten="Nguyen Van An", const char *ns="14/3/2003",const char *quequan="Quang Nam")
    {
        HT=new char[strlen(hoten)+1000];
        NS=new char[strlen(ns)+1000];
        Q=new char[strlen(quequan)+1000];
        strcpy(HT,hoten);
        strcpy(NS,ns);
        strcpy(Q,quequan);
    }
};
class Kysu:public person{
    protected:
    char *NH;
    int NTN;
    static int soluong;
    // Kysu *ks;
    public:
    Kysu(const char *nganh="Ky thuat may tinh"):person()
    {
        NH=new char[strlen(nganh)+1000];
        // ks=new Kysu[50];
    }
    void Nhap(Kysu *);
    void Xuat(Kysu *);
};
int Kysu::soluong=0;

void Kysu::Nhap(Kysu *ks)
{
    int temp;
    do{
        soluong++;
        cout<<"Nhap Ho ten: ";
        fflush(stdin);
        cin.getline(ks[soluong].HT,30);
        cout<<"Nhap ngay sinh: ";
        fflush(stdin);
        cin.getline(ks[soluong].NS,30);
        cout<<"Nhap que quan: ";
        fflush(stdin);
        cin.getline(ks[soluong].Q,30);
        cout<<"Nhap nganh hoc: ";
        fflush(stdin);
        cin.getline(ks[soluong].NH,30);
        cout<<"Nhap phim 1 de tiep tuc nhap: ";
        cin>>temp;
    }while(temp==1);
    
}

void Kysu::Xuat(Kysu *ks)
{
    for(int i=1;i<=soluong;i++)
    {
        cout<<"Ho ten cua ky su thu "<<i<<"la: "<<ks[i].HT<<endl;
        cout<<"Ngay sinh cua ky su thu "<<i<<"la: "<<ks[i].NS<<endl;
        cout<<"Que quan cua ky su thu "<<i<<"la: "<<ks[i].Q<<endl;
        cout<<"Nganh hoc cua ky su thu "<<i<<"la: "<<ks[i].NH<<endl;
    }
}

int main()
{
    Kysu *ks;
    ks=new Kysu[50];
    ks->Nhap(ks);
    ks->Xuat(ks);
}