#include "D:\OOP\bai2\Computer.cpp"
#include "D:\OOP\bai2\Phone.cpp"
#include <windows.h>
Computer *computer=new Computer[100];
Phone *phone=new Phone[100];
int Menu_Function(int number_function)
{
    cout<<"====================MENU FUNCTION==================="<<endl;
    cout<<"Enter button 1 to operate computer function: "<<endl;
    cout<<"Enter button 2 to operate phone function: "<<endl;
    cout<<"====================================================="<<endl;
    cin>>number_function;
    return number_function;
}
void Operate_computer_function(int &number_Function)
{
    switch (number_Function)
    {
        case 1:
            computer->Enter_Information(computer);
            break;
        case 2:
            computer->Write_Information(computer);
            break;
        case 3:
            computer->Arrange_for_RAM(computer);
            break;
        case 4:
            computer->Arrange_for_Price(computer);
            break;
        case 5:
            computer->Arrange_for_Hard_disk_size(computer);
            break;
        case 6:
            computer->Search_Hard_disk_drive(computer);
            break;
    }
}
int Computer_function(int &number_Function)
{
    while(1)
    {
        cout<<"====================COMPUTER FUNCTION=================="<<endl;
        cout<<"0. Exit function "<<endl;
        cout<<"1. Enter information "<<endl;
        cout<<"2. Write information "<<endl;
        cout<<"3. Arrange for RAM "<<endl;
        cout<<"4. Arrange for price "<<endl;
        cout<<"5. Arrange for Hard disk size "<<endl;
        cout<<"6. Search for hard disk drive "<<endl;
        cout<<"========================================================"<<endl;
        cout<<"Enter number function you want to do: ";
        cin>>number_Function;
        if(number_Function!=0)
        {
            Operate_computer_function(number_Function);
        }
        else{
            break;
        }
    }
}
void Operate_phone_function(int &number_Function)
{
    switch (number_Function)
    {
        case 1:
            phone->Enter_Information(phone);
            break;
        case 2:
            phone->Write_Information(phone);
            break;
        case 3:
            phone->Arrange_for_Resolution(phone);
            break;
        case 4:
            phone->Arrange_for_Memory_size(phone);
            break;
        case 5:
            phone->Arrange_for_Ram(phone);
            break;
        case 6:
            phone->Arrange_for_Price(phone);
            break;
        case 7:
            phone->Search_Phone(phone);
            break;
    }
}
int Phone_function(int number_Function)
{
    while(1)
    {
        cout<<"=====================PHONE FUNCTION================="<<endl;
        cout<<"0. Exit function "<<endl;
        cout<<"1. Enter information "<<endl;
        cout<<"2. Write information "<<endl;
        cout<<"3. Arrange for resolution "<<endl;
        cout<<"4. Arrange for memory size "<<endl;
        cout<<"5. Arrange for RAM "<<endl;
        cout<<"6. Arrange for price "<<endl;
        cout<<"7. Search phone information "<<endl;
        cout<<"====================================================="<<endl;
        cout<<"Enter number function you want to do: ";
        cin>>number_Function;
        if(number_Function!=0)
        {
            Operate_phone_function(number_Function);
        }
        else{
            break;
        }
    }
}
void check(int number_Function)
{
    while(1)
    {
        number_Function=Menu_Function(number_Function);
        if(number_Function==1)
        {
            Computer_function(number_Function);
        }
        if(number_Function==2)
        {
            Phone_function(number_Function);
        }
        else{
            delete[]computer;
            delete[]phone;
        }
    }
    
}