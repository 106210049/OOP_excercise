#ifndef BAI1_MENU_H
#define BAI1_MENU_H  
#include <D:\OOP\bai1\bai1.cpp>
#include<windows.h>
Engineer *engineer=new Engineer[10];
int Menu_Function(int &function)
{
    cout<<"==================MENU===================="<<endl;
    cout<<"0. Write engineer's iformation "<<endl;
    cout<<"1. Enter engineer's information "<<endl;
    cout<<"2. Arrange for engineer's salary "<<endl;
    cout<<"3. Arrange for engineer's age "<<endl;
    cout<<"4. Search engineer's information "<<endl;
    cout<<"5. Arrange engineer's height "<<endl;
    cout<<"6. Arrange engineer's weight "<<endl;
    cout<<"=========================================="<<endl;
    cout<<"Enter function: ";cin>>function;
    return function;
}
void Operate_menu()
{
    int function=0;
    while(1)
    {
        switch(Menu_Function(function))
        {
            case 0:
            engineer->OUTPUT_DATA(engineer);
            break;
            case 1:
            engineer->INPUT_DATA(engineer);
            break;
            case 2:
            engineer->Arrange_for_Salary(engineer);
            break;
            case 3:
            engineer->Arrange_for_age(engineer);
            break;
            case 4:
            engineer->Search_information(engineer);
            break;
            case 5:
            engineer->Arrange_for_height(engineer);
            break;
            case 6:
            engineer->Arrange_for_weight(engineer);
            break;
            default:
            cout<<Engineer::quantity<<" People "<<endl;
            delete[]engineer;
            exit(0);
            break;
        }
    }
}
#endif