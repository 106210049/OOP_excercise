#ifndef BAI1_CLASS_H
#define BAI1_CLASS_H
#include<string.h>
#include<iostream>

using namespace std;

class Person{
    protected:
    char *name,*birthday,*sex,*ID;
    int height;
    int age;
    float weight;
    public:
    static int quantity;
    Person(const char *name=" Ngo Viet Huy Hoang ",const char *birthday="18/12/2002",const char *sex="Female", int height=160,float weight=65.6,const char *ID="106210049")
    {
        this->name=new char[strlen(name)+10];
        strcpy(this->name,name);
        this->birthday=new char[strlen(birthday)+10];
        strcpy(this->birthday,birthday);
        this->sex=new char[strlen(sex)+10];
        strcpy(this->sex,sex);
        this->ID=new char[strlen(ID)+10];
        strcpy(this->ID,ID);
        this->height=170;
        this->weight=55;
    }
    ~Person()
    {
        delete[]name;
        delete[]birthday;
        delete[]sex;
    }
};
int Person::quantity=0;

class Company{
    protected:
    static char *name_company,*address;
    public:
    friend class Engineer;
    void Enter_Company(Company &company);
};
char *Company::name_company="";
char *Company::address="";
class Engineer:public Person{
    private:
    char *job,*rank;
    static double basic_salary;
    double salary;
    Company company;
    public:
    Engineer(const char *job="Chuyen nganh Phan tich du lieu",const char *rank="Manager",double salary=3000,const char *name_company="Cong ty TNHH Truong Hai",const char *address="113 Nguyen Tri Phuong"):Person()
    {
        this->job=new char[strlen(job)+10];
        strcpy(this->job,job);
        this->rank=new char[strlen(rank)+10];
        strcpy(this->rank,rank);
        this->salary=3500;
        company.name_company=new char[strlen(name_company)+10];
        strcpy(company.name_company,name_company);
        company.address=new char[strlen(address)+10];
        strcpy(company.address,address);
    }
    ~Engineer()
    {
        delete []job;
        delete []rank;
        delete[]company.name_company;
        delete[]company.address;
    }
    friend istream &operator>>(istream &is,Engineer &engineer);
    friend ostream &operator<<(ostream &out,Engineer &engineer);
    void INPUT_DATA(Engineer *engineer);
    void OUTPUT_DATA(Engineer *engineer);
    void Calculate_salary(Engineer *engineer);
    void Arrange_for_Salary(Engineer *engineer);
    void Search_information(Engineer *engineer);
    void Arrange_for_age(Engineer *engineer);
    void Arrange_for_height(Engineer *engineer);
    void Arrange_for_weight(Engineer *engineer);
};
double Engineer::basic_salary=3000;

#endif