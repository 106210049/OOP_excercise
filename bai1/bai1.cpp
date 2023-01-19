#include<D:\OOP\bai1\Class.h>

istream &operator>>(istream &is,Engineer &engineer)
{
    cout<<"Enter engineer's name: ";
    fflush(stdin);
    is.getline(engineer.name,30);
    cout<<"Enter engineer's ID: ";
    fflush(stdin);
    is.getline(engineer.ID,15);
    cout<<"Enter engineer's Birthday: ";
    fflush(stdin);
    is.getline(engineer.birthday,15);
    cout<<"Enter engineer's sex: ";
    fflush(stdin);
    is.getline(engineer.sex,8);
    cout<<"Enter engineer's height: ";
    is>>engineer.height;
    cout<<"Enter engineer's weight: ";
    is>>engineer.weight;
    cout<<"Enter engineer's job: ";
    fflush(stdin);
    is.getline(engineer.job,30);
    cout<<"Enter rank: ";
    fflush(stdin);
    is.getline(engineer.rank,20);    
}
ostream &operator<<(ostream &out,Engineer &engineer)
{
    cout<<"=========================================="<<endl;
    out<<"Engineer's name: "<<engineer.name<<endl;
    out<<"Engineer's ID: "<<engineer.ID<<endl;
    out<<"Engineer's Birthday: "<<engineer.birthday<<endl;
    out<<"Engineer's sex: "<<engineer.sex<<endl;
    out<<"Engineer's height: "<<engineer.height<<endl;
    out<<"Engineer's weight: "<<engineer.weight<<endl;
    out<<"Engineer's job: "<<engineer.job<<endl;
    out<<"Engineer's rank: "<<engineer.rank<<endl;
    out<<"Engineer's Salary: "<<engineer.salary<<endl;
    cout<<"=========================================="<<endl;
}
bool check(bool cancle)
{
    cout<<"Enter number 1 to continue enter information: ";
    cin>>cancle;
    return cancle;
}
void Engineer::INPUT_DATA(Engineer *engineer)
{
    int number=0;
    bool cancle=0;
    while(1)
    {
        cin>>engineer[number];
        number++;
        quantity++;
        if(check(cancle)!=1)
        {
            break;
        }
    }
}
void Engineer::OUTPUT_DATA(Engineer *engineer)
{
    cout<<"Company's name: "<<Company::name_company<<endl;
    cout<<"Company's address: "<<Company::address<<endl;
    for(int number=0;number<quantity;number++)
    {
        cout<<engineer[number];
    }
}
void Engineer::Arrange_for_height(Engineer *engineer)
{
    for(int number=0;number<quantity-1;number++)
    {
       if(engineer[number].height>engineer[number+1].height)
       {
            swap(engineer[number],engineer[number+1]);
       }
    }
}
void Engineer::Arrange_for_weight(Engineer *engineer)
{
    for(int number=0;number<quantity-1;number++)
    {
       if(engineer[number].weight>engineer[number+1].weight)
       {
            swap(engineer[number],engineer[number+1]);
       }
    }
}
void Engineer::Arrange_for_Salary(Engineer *engineer)
{
    for(int number=0;number<quantity-1;number++)
    {
       if(engineer[number].salary>engineer[number+1].salary)
       {
            swap(engineer[number],engineer[number+1]);
       }
    }
}
void Engineer::Search_information(Engineer *engineer)
{
    char ID[15];
    bool check=0;
    cout<<"Enter ID you want to search: ";
    fflush(stdin);
    cin.getline(ID,15);
    for(int number=0;number<quantity;number++)
    {
       if(ID==engineer[number].ID)
       {
            check=1;
            cout<<engineer[number];
       }
    }
    if(check==0)
    {
        cout<<"ID is not available !!!"<<endl;
    }
}
void Company::Enter_Company(Company &company)
{
    cout<<"Enter company's name: ";
    fflush(stdin);
    cin.getline(company.name_company,30);
    cout<<"Enter Company's address: ";
    fflush(stdin);
    cin.getline(company.address,30);
}
void Engineer::Arrange_for_age(Engineer *engineer)
{
    //14/03/2003
    for(int location=0;location<quantity;location++)
    {
        
    }
}
void Engineer::Calculate_salary(Engineer *engineer)
{

}

