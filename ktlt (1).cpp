#include<iostream>
#include<string.h>
#include<windows.h>
using namespace std;
class nv{
    protected:
    char *hoten;
    char *quequan;
    int thamnien; //thâm niên
    float heso;
    static float luongcoban; // lương cơ bản
    public:
    nv(const char *name=" Nguyen Huynh Huu Duyen", const char *que="Thanh pho Ho Chi Minh")
    {
        hoten=new char[strlen(name)+1];
        quequan=new char[strlen(que)+1];
        strcpy(hoten,name);
        strcpy(quequan,que);
        heso=0;
    }
    ~nv()
    {
        delete[]hoten;
        delete[]quequan;
    }
};
float nv::luongcoban=0;
class nvkythuat:public nv{
    private:
    float thunhap,phucap;
    int cadem;
    float hesocadem; // hệ số ca đêm;
    char *phong; // phòng
    public:
    static void nhapluongcoban();
    nvkythuat(const char *phong="Quan ly nhan su"):nv()
    {
        this->phong=new char[strlen(phong)+1];
        strcpy(this->phong,phong);
        this->thunhap=0;
        this->phucap=0;
        this->cadem=0;
    }
    ~nvkythuat()
    {
        delete[]phong;
    }
    friend istream &operator>>(istream &is, nvkythuat &a);
    friend ostream &operator<<(ostream &os, nvkythuat &a);
    void tinhthunhap();

};
void nvkythuat::nhapluongcoban()
{
    cout<<"Nhap luong co ban: ";
    cin>>luongcoban;
}
istream &operator>>(istream &is, nvkythuat &a)
{
    cout<<"Nhap ho ten: ";
    fflush(stdin);
    is.getline(a.hoten,30);
    cout<<"Nhap que quan: ";
    fflush(stdin);
    is.getline(a.quequan,30);
    cout<<"Nhap tham nien lam viec: ";
    is>>a.thamnien;
    cout<<"Nhap he so luong: ";
    is>>a.heso;
    cout<<"Nhap so ca dem: ";
    is>>a.cadem;
    cout<<"Nhap he so ca dem: ";
    is>>a.hesocadem;
    cout<<"Nhap so phong: ";
    is>>a.phong;
    a.tinhthunhap();
}
ostream &operator<<(ostream &os, nvkythuat &a)
{
    os<<"Ho va ten nhan vien: "<<a.hoten<<endl;
    os<<"Que quan: "<<a.quequan<<endl;
    os<<"Tham nien lam viec: "<<a.thamnien<<" nam "<<endl;
    os<<"Luong co ban: "<<a.luongcoban<<endl;
    os<<"He so luong: "<<a.heso<<endl;
    os<<"So ca dem: "<<a.cadem<<endl;
    os<<"He so ca dem: "<<a.hesocadem<<endl;
    os<<"So phong: "<<a.phong<<endl;
    cout<<"Thu nhap cua nhan vien: "<<a.thunhap<<" $/thang"<<endl;
}
void nvkythuat::tinhthunhap()
{
    if(thamnien>4)
    {
        phucap=luongcoban*0.05*thamnien;
    }
    else{
        phucap=0;
    }
    thunhap=(luongcoban+phucap)*heso*cadem*hesocadem;
}
int main()
{
    system("cls");
    int temp=0;
    nvkythuat::nhapluongcoban();
    do{
        cout<<"Chon phim 1 de nhap thong tin nhan vien: "<<endl;
        cout<<"Chon phim 2 de xuat thong tin nhan vien: "<<endl;
        cout<<"Nhap phim 0 de thoat: "<<endl;
        cin>>temp;
        if(temp!=0)
        {
            nvkythuat kysu;
            if(temp==1)
            {
                cin>>kysu;
            }
            if(temp==2)
            {
                cout<<kysu;
            }
        }
        else{
            return 0;
        }
    }while(1);
}