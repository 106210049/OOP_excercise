#include<iostream>
#include<bits/stdc++.h>
using namespace std;
class nhansu{
    private:
    char *ID;
    float heso; //GD:4; PGD:3; TP:2; PP:1.5; NN:1
    float Luong;
    static float luongcoban;
    static int songuoi;
    static float nhapluongcoban();
    float tinhheso();
    float tinhluong();

    public:
    char *hoten;
    int chucvu; //1: GD; 2: PGD; 3: TP; 4: PP; 5:NV
    nhansu(const char *id="106210049", const char *name="Nguyen Huynh Huu Chi")
    {
        ++songuoi;
        hoten=new char[strlen(name)+1];
        ID=new char[strlen(id)+1];
        this->heso=0;
    }
    
    ~nhansu()
    {
        --songuoi;
        delete[]hoten;
        delete[]ID;
    }
    friend istream &operator>>(istream &is, nhansu &ns)
    {
        nhapluongcoban();
        cout<<songuoi<<endl;
        cout<<"Nhap chuc vu: ";
        is>>ns.chucvu;
        cout<<"Nhap ho ten: ";
        is.ignore();
        is.getline(ns.hoten,30);
        cout<<"Nhap ma so ID: ";
        is.ignore();
        is.getline(ns.ID,30);
        ns.tinhheso();
    }
    friend ostream &operator<<(ostream &os, nhansu &ns)
    {
        os<<"Ten cua nhan vien la: "<<ns.hoten<<endl;
        os<<"Ma so ID cua nhan vien la: "<<ns.ID<<endl;
        os<<"Chuc vu cua nhan vien la: "<<ns.chucvu<<endl;
        os<<"he so cua nhan vien la: "<<ns.heso<<endl;
        cout<<"Luong: "<<ns.Luong<<endl;
    }
   
};
int nhansu::songuoi=0;
float nhansu::luongcoban=0;
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
    tinhluong();
}

float nhansu::nhapluongcoban()
{
    cout<<"Nhap luong co ban: ";
    cin>>luongcoban;
}

float nhansu::tinhluong()
{
    Luong=luongcoban*heso;
}

int main()
{
    int chucvu;
    system("cls");
    nhansu ns;
    cin>>ns;
    cout<<ns;
    nhansu ns1;
    cin>>ns1;
    cout<<ns1;
}