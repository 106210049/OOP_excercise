#include<iostream>
#include<bits/stdc++.h>
#include<string.h>

#include<windows.h>
using namespace std;
class nhansu{

    private:
    string ID;
    float heso; //GD:4; PGD:3; TP:2; PP:1.5; NN:1
    float Luong;
    static float luongcoban;
    static int songuoi;
    static float nhapluongcoban(nhansu &ns);
    float tinhheso();
    float tinhluong();

    public:
    string hoten;
    int chucvu; //1: GD; 2: PGD; 3: TP; 4: PP; 5:NV
    nhansu(const char *ID="106210049",const float heso=0,const float Luong=0)
    {
        ++songuoi;
        // hoten=new char[strlen(hoten)+1];
        // ID=new char[strlen(ID)+1];
        this->heso=1;
    }
    
    ~nhansu()
    {
        --songuoi;
        // delete[]hoten;
        // delete[]ID;
    }
    friend istream &operator>>(istream &is, nhansu &ns)
    {
        cout<<"Nhap chuc vu: ";
        is>>ns.chucvu;
        cout<<"Nhap ho ten: ";
        fflush(stdin);
        // is.getline(ns.hoten,1000);
        getline(is,ns.hoten);
        cout<<"Nhap ma so ID: ";
        // is.ignore();
        fflush(stdin);
        getline(is,ns.ID);
        // is.getline(ns.ID,1000);
        ns.nhapluongcoban(ns);
    }
    friend ostream &operator<<(ostream &os, nhansu &ns);
    
   
};

int nhansu::songuoi=0;
float nhansu::luongcoban=0;
ostream &operator<<(ostream &os, nhansu &ns)
{
    cout<<nhansu::songuoi<<endl;
    os<<"Ten cua nhan vien la: "<<ns.hoten<<endl;
    os<<"Ma so ID cua nhan vien la: "<<ns.ID<<endl;
    os<<"Chuc vu cua nhan vien la: "<<ns.chucvu<<endl;
    os<<"he so cua nhan vien la: "<<ns.heso<<endl;
    os<<"Luong cua nhan vien la: "<<ns.Luong<<endl;
}
float nhansu::tinhheso()
{
    if(chucvu==1)
    {
        heso=4;
    }
    else if(chucvu==2)
    {
        heso=3;
    }
    else if(chucvu==3)
    {
        heso=2;
    }
    else if(chucvu==4)
    {
        heso=1.5;
    }
    else if(chucvu==5)
    {
        heso=1;
    }
    return heso;
}
float nhansu::nhapluongcoban(nhansu &ns)
{
    cout<<"Nhap luong co ban: ";
    cin>>ns.luongcoban;
    ns.tinhheso();
    ns.tinhluong();
}

float nhansu::tinhluong()
{
    Luong=luongcoban*heso;
    return Luong;
}

int main()
{
    system("cls");
    nhansu ns("123",2,123);
    cin>>ns;
    cout<<"Thong tin nhan su: "<<endl;
    cout<<ns;
    system("PAUSE");
    nhansu ns1("456",2,123);
    cin>>ns1;
    cout<<ns1;
}
