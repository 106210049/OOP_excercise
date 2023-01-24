#include "D:\OOP\bai2\phone.h"
istream &operator>>(istream &is,Phone &phone)
{
    cout<<"Enter phone's brand: ";
    fflush(stdin);
    is.getline(phone.brand,20);
    cout<<"Enter phone's color: ";
    fflush(stdin);
    is.getline(phone.color,10);
    cout<<"Enter phone's mass: ";
    is>>phone.mass;
    cout<<"Enter phone's price: ";
    is>>phone.price;
    cout<<"Enter phone's OS: ";
    fflush(stdin);
    is.getline(phone.OS,20);
    cout<<"Enter phone's resolution: ";
    is>>phone.resolution;
    cout<<"Enter phone's memory size: ";
    is>>phone.Memory_size;
    cout<<"Enter phone's RAM: ";
    is>>phone.RAM;
}
ostream &operator<<(ostream &os,Phone &phone)
{
    os<<"phone's brand: "<<phone.brand<<endl;
    os<<"phone's color: "<<phone.color<<endl;
    os<<"phone's mass: "<<phone.mass<<endl;
    os<<"phone's OS: "<<phone.OS<<endl;
    os<<"phone's resolution: "<<phone.resolution<<endl;
    os<<"phone's memory size: "<<phone.Memory_size<<endl;
    os<<"phone's RAM: "<<phone.RAM<<endl;
    os<<"Price: "<<phone.price<<endl;
}
bool check(bool cancle)
{
    cout<<"Enter number 1 to continue enter information: ";
    cin>>cancle;
    return cancle;
}
void Phone::Enter_Information(Phone *phone)
{
    int number=0;
    bool cancle=0;
    while(1)
    {
        cin>>phone[number];
        number++;
        Phone::quantity++;
        if(check(cancle)!=1)
        {
            break;
        }
    }
}
void Phone::Write_Information(Phone *phone)
{
    for(int location=0;location<Phone::quantity;location++)
    {
        cout<<phone[location];
    }
}
void Phone::Arrange_for_Resolution(Phone *phone)
{
    for(int location=0;location<Phone::quantity-1;location++)
    {
        if(phone[location].resolution>phone[location].resolution)
        {
            swap(phone[location],phone[location+1]);
        }
    }
}
void Phone::Arrange_for_Memory_size(Phone *phone)
{
    for(int location=0;location<Phone::quantity-1;location++)
    {
        if(phone[location].Memory_size>phone[location].Memory_size)
        {
            swap(phone[location],phone[location+1]);
        }
    }
}
void Phone::Arrange_for_Ram(Phone *phone)
{
    for(int location=0;location<Phone::quantity-1;location++)
    {
        if(phone[location].RAM>phone[location].RAM)
        {
            swap(phone[location],phone[location+1]);
        }
    }
}
void Phone::Arrange_for_Price(Phone *phone)
{
    for(int location=0;location<Phone::quantity-1;location++)
    {
        if(phone[location].price>phone[location].price)
        {
            swap(phone[location],phone[location+1]);
        }
    }
}
void Phone::Search_Phone(Phone *phone)
{
    char OS[20]="";
    int RAM=0;
    float price=0;
    cout<<"Enter phone's OS: ";
    fflush(stdin);
    cin.getline(OS,15);
    cout<<"Enter phone's RAM: ";
    cin>>RAM;
    cout<<"Enter phone's price: ";
    cin>>price;
    for(int location=0;location<Phone::quantity;location++)
    {
        if(phone[location].OS==OS&&phone[location].RAM==RAM&&phone[location].price==price)
        {
            cout<<phone[location];
        }
    }
}