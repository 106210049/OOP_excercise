#include<iostream>
#include<string.h>
#include<windows.h>
using namespace std;

class Person{
    protected:
    char *name;
    int tuoi;
    float chieucao,cannang;
    public:
    Person(const char *hoten="Nguyen Huynh Huu Duyen")
    {
        name=new char[strlen(hoten)+1];
        strcpy(name,hoten);
        this->tuoi=0;
        this->chieucao=0;
        this->cannang=0;
    }
};
class Hospital{
    public:
    static char *TenBV;
    static char *address;
    Hospital(const char *tenbv="Benh vien da khoa da nang", const char *diachi="136 Hai Phong")
    {
        TenBV=new char[strlen(tenbv)+1];
        address=new char[strlen(diachi)+1];
        strcpy(TenBV,tenbv);
        strcpy(address,diachi);
    }
    friend class BN;
    static void nhap();
    static void xuat();
};
char *Hospital::TenBV="";
char *Hospital::address="";
class BN: public Person{
    private:
    char *TS;
    char *CD;
    char *ngay_nhap_vien;
    Hospital BV;
    public:
    BN(const char *tiensu="Nguyen Hoang Ha", const char *chuandoan="Benh Viem gan B",const char *date="26/12/2004"):Person()
    {
        TS=new char[strlen(tiensu)+1];
        CD=new char[strlen(chuandoan)+1];
        ngay_nhap_vien=new char[strlen(date)+1];
        strcpy(TS,tiensu);
        strcpy(CD,chuandoan);
    }
    friend istream &operator >>(istream &is, BN &bn);
    friend ostream &operator <<(ostream &os, BN &bn);
    friend void nhap();
    friend void xuat();
    void Arrange_for_age(BN *bn, int &n);
    void Arrange_for_chieucao(BN *bn, int &n);
    void Arrange_for_cannang(BN *bn, int &n);
};
istream &operator >>(istream &is, BN &bn)
{
    cout<<"Nhap ten benh nhan: ";
    fflush(stdin);
    cin.getline(bn.name,30);
    cout<<"Nhap tuoi: ";
    cin>>bn.tuoi;
    cout<<"Nhap can nang: ";
    cin>>bn.cannang;
    cout<<"Nhap chieu cao: ";
    cin>>bn.chieucao;
    cout<<"Nhap tien su: ";
    fflush(stdin);
    cin.getline(bn.TS,30);
    cout<<"Nhap chan doan cua bac si: ";
    fflush(stdin);
    cin.getline(bn.CD,30);
}
ostream &operator <<(ostream &os, BN &bn)
{
    os<<"Ho ten: "<<bn.name<<endl;
    os<<"Tuoi: "<<bn.tuoi<<endl;
    os<<"can nang= "<<bn.cannang<<endl;
    os<<"chieu cao= "<<bn.chieucao<<endl;
    os<<"Tien su: "<<bn.TS<<endl;
    os<<"Chan doan: "<<bn.CD<<endl;
}
void Hospital::nhap()
{
    cout<<"Nhap ten Benh vien: ";
    fflush(stdin);
    cin.getline(TenBV,30);
    cout<<"Nhap dia chi cua benh vien: ";
    fflush(stdin);
    cin.getline(address,30);
}
void nhap(BN *bn,int &n)
{
    for(int i=0;i<n;i++)
    {
        cin>>bn[i];
    }
}
void xuat(BN *bn, int &n)
{
    for(int i=0;i<n;i++)
    {
        cout<<bn[i];
    }
}
void BN::Arrange_for_age(BN *bn, int &n)
{
    for(int i=0;i<n-1;i++)
    {
        if(bn[i].tuoi>bn[i+1].tuoi)
        {
            BN x;
            x=bn[i];
            bn[i]=bn[i+1];
            bn[i+1]=x;
        }
    }
}
void BN::Arrange_for_chieucao(BN *bn, int &n)
{
    for(int i=0;i<n-1;i++)
    {
       if(bn[i].chieucao>bn[i+1].chieucao)
       {
            BN x;
            x=bn[i];
            bn[i]=bn[i+1];
            bn[i+1]=x;
       }
    }
}
void BN::Arrange_for_cannang(BN *bn, int &n)
{
    for(int i=0;i<n-1;i++)
    {
       if(bn[i].cannang>bn[i+1].cannang)
       {
            BN x;
            x=bn[i];
            bn[i]=bn[i+1];
            bn[i+1]=x;
       }
    }
}
int main()
{
    system("cls");
    Hospital a;
    a.nhap();
    cout<<"Nhap so luong: ";
    int n;
    cin>>n;
    BN *bn;
    bn=new BN[50];
    nhap(bn,n);
    cout<<"Nhap chuc nang sap xep: ";
    int chucnang;
    cin>>chucnang;
    switch (chucnang)
    {
    case 1:
        bn->Arrange_for_age(bn,n);
        break;
    case 2:
        bn->Arrange_for_cannang(bn,n);
        break;
    case 3:
        bn->Arrange_for_chieucao(bn,n);
        break;
    default:
    return 0;
        break;
    }
    xuat(bn,n);
}