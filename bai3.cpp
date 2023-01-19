#include<iostream>
#include<string.h>
using namespace std;

class Printer{
    protected:
    float quantities;
    char *year;
    char *brand;
    public:
    Printer(const char *namsx="23/12/2000", const char *hangsx="Viet Nam airlines")
    {
        year=new char[strlen(namsx)+1];
        brand=new char[strlen(hangsx)+1];
    }
    ~Printer()
    {
        delete[]year;
        delete[]brand;
    }
};
class Mkim:public Printer{
    private:
    int amount;
    int speed_of_printer;
    static int soluong;
    public:
    Mkim(const int m=50,const int speed=40):Printer()
    {
        ++soluong;
        amount=m;
        
        speed_of_printer=speed;
    }
    friend istream &operator>>(istream &is,Mkim &mk);
    friend ostream &operator<<(ostream &os,Mkim &mk);

};
istream &operator>>(istream &is,Mkim &mk)
{
    cout<<"********** Nhap thong tin may in kim **********"<<endl;
    cout<<"******************************************"<<endl;
    cout<<"Nhap nhan hang: ";
    fflush(stdin);
    is.getline(mk.brand,30);
    cout<<"Nhap nam san xuat: ";
    fflush(stdin);
    is.getline(mk.year,30);
    cout<<"Nhap khoi luong: ";
    is>>mk.amount;
    cout<<"Nhap toc do in: ";
    is>>mk.speed_of_printer;
    cout<<"******************************************"<<endl;

}
ostream &operator<<(ostream &os,Mkim &mk)
{
    os<<"Thong tin hang cua May in kim"<<endl;
    os<<"******************************************"<<endl;
    os<<"Nhan hang la: "<<mk.brand<<endl;
    os<<"Nam san xuat la nam: "<<mk.year<<endl;
    os<<"Khoi luong la: "<<mk.amount<<" kg "<<endl;
    os<<"Toc do in la: "<<mk.speed_of_printer<<" vong/phut"<<endl;
    os<<"******************************************"<<endl;
}
class lazer:public Printer{
    private:
    int resolution;
    int speed_of_printer;
    static int numbers;
    public:
    lazer(const int DPG=10, const int speed=10):Printer()
    {
        ++numbers;
        resolution=DPG;
        speed_of_printer=speed;
    }
    friend istream &operator>>(istream &is,lazer &lz);
    friend ostream &operator<<(ostream &os,lazer &Lz);
};
int lazer::numbers=0;
int Mkim::soluong=0;
istream &operator>>(istream &is,lazer &lz)
{
    cout<<"********** Nhap thong tin may in lazer **********"<<endl;
    cout<<"******************************************"<<endl;
    cout<<"Nhap nhan hang: ";
    fflush(stdin);
    is.getline(lz.brand,30);
    cout<<"Nhap nam san xuat: ";
    fflush(stdin);
    is.getline(lz.year,30);
    cout<<"Nhap do phan giai: ";
    is>>lz.resolution;
    cout<<"Nhap toc do in: ";
    cin>>lz.speed_of_printer;
    cout<<"******************************************"<<endl;
}
ostream &operator<<(ostream &os,lazer &Lz)
{
    cout<<Lz.numbers<<endl;
    os<<"Thong tin hang cua May in lazer"<<endl;
    os<<"******************************************"<<endl;
    os<<"Nhan hang la: "<<Lz.brand<<endl;
    os<<"Nam san xuat la nam: "<<Lz.year<<endl;
    os<<"Do phan giai la: "<<Lz.resolution<<"pixels"<<endl;
    os<<"Toc do in la: "<<Lz.speed_of_printer<<" vong/phut"<<endl;
    os<<"******************************************"<<endl;
}
int main()
{
    do{
        int chucnang;
        cout<<"Nhap phim 1 de dung chuc nang may in kim"<<endl;
        cout<<"Nhap phim 2 de dung chuc nang may in lazer"<<endl;
        cout<<"Nhap chuc nang: ";
        cin>>chucnang;
        if(chucnang==1)
        {
            Mkim mk;
            cin>>mk;
            cout<<mk;
        }
        else if(chucnang==2){
            lazer lz;
            cin>>lz;
            cout<<lz;
        }
        else{
            return 0;
        }
    }while (1);
    
    
}
