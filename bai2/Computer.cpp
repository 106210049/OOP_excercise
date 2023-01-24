#include"D:\OOP\bai2\computer.h"

istream &operator>>(istream &is,Computer &computer)
{
    cout<<"Enter computer's brand: ";
    fflush(stdin);
    is.getline(computer.brand,20);
    cout<<"Enter computer's color: ";
    fflush(stdin);
    is.getline(computer.color,10);
    cout<<"Enter computer's mass: ";
    is>>computer.mass;
    cout<<"Enter computer's price: ";
    is>>computer.price;
    cout<<"Enter computer's chip: ";
    fflush(stdin);
    is.getline(computer.chip,20);
    cout<<"Enter computer's Hard disk drive: ";
    fflush(stdin);
    is.getline(computer.Hard_disk_drive,20);
    cout<<"Enter computer's hard disk size: ";
    is>>computer.Hard_disk_size;
    cout<<"Enter computer's RAM: ";
    is>>computer.RAM;
}
ostream &operator<<(ostream &os,Computer &computer)
{
    os<<"Computer's brand: "<<computer.brand<<endl;
    os<<"Computer's color: "<<computer.color<<endl;
    os<<"Computer's mass: "<<computer.mass<<endl;
    os<<"Computer's chip: "<<computer.chip<<endl;
    os<<"Computer's Hard disk drive: "<<computer.Hard_disk_drive<<endl;
    os<<"Computer's Hard disk size: "<<computer.Hard_disk_size<<endl;
    os<<"Computer's RAM: "<<computer.RAM<<endl;
    os<<"Price: "<<computer.price<<endl;
}

void Computer::Enter_Information(Computer *computer)
{
    int number=0;
    bool cancle=0;
    while(1)
    {
        cin>>computer[number];
        number++;
        Computer::quantity++;
        cout<<"Enter number 1 to continue enter information: ";
        cin>>cancle;
        if(cancle!=1)
        {
            break;
        }
    }
}
void Computer::Write_Information(Computer *computer)
{
    for(int location=0;location<Computer::quantity;location++)
    {
        cout<<computer[location];
    }
}
void Computer::Arrange_for_RAM(Computer *computer)
{
    for(int location=0;location<Computer::quantity-1;location++)
    {
        if(computer[location].RAM>computer[location+1].RAM)
        {
            swap(computer[location],computer[location+1]);
        }
    }
}
void Computer::Arrange_for_Price(Computer *computer)
{
    for(int location=0;location<Computer::quantity-1;location++)
    {
        if(computer[location].price>computer[location+1].price)
        {
            swap(computer[location],computer[location+1]);
        }
    }
}
void Computer::Arrange_for_Hard_disk_size(Computer *computer)
{
    for(int location=0;location<Computer::quantity-1;location++)
    {
        if(computer[location].Hard_disk_size>computer[location+1].RAM)
        {
            swap(computer[location],computer[location+1]);
        }
    }
}
void Computer::Search_Hard_disk_drive(Computer *computer)
{
    int Hard_disk_size=0;
    char Hard_disk_drive[30]="";
    cout<<"Enter Hard disk drive: ";
    fflush(stdin);
    cin.getline(Hard_disk_drive,20);
    cout<<"Enter hard disk size: ";
    cin>>Hard_disk_size;
    for(int location=0;location<Computer::quantity;location++)
    {
        if(computer[location].Hard_disk_drive==Hard_disk_drive&&computer[location].Hard_disk_size==Hard_disk_size)
        {
            cout<<computer[location];
        }
    }
}