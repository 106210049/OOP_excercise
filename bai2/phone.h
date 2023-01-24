// #include "D:\OOP\bai2\machine.h"
#ifndef PHONE_H
#define PHONE_H
class Phone:public Machine{
    private:
    float resolution;
    char *OS;
    int RAM, Memory_size;
    static int quantity;
    Manufacturer manufactures;
    public:
    Phone(const char *OS="Android",const char *manufacturer_name="Samsung",const char *country="The United Kingdom",const char *address="113 Oxford Street"):Machine()
    {
        this->OS=new char[strlen(OS)+20];
        manufactures.manufacturer_name=new char[strlen(manufacturer_name)+20];
        strcpy(manufactures.manufacturer_name,manufacturer_name);
        manufactures.country=new char[strlen(country)+20];
        strcpy(manufactures.country,country);
        manufactures.address=new char[strlen(address)+20];
        strcpy(manufactures.address,address);
    }
    ~Phone()
    {
        delete[]OS;
        delete[]manufactures.manufacturer_name;
        delete[]manufactures.country;
        delete[]manufactures.address;
    }
    friend istream &operator>>(istream &is,Phone &phone);
    friend ostream &operator<<(ostream &os, Phone &phone);
    friend void Calculate_Price(Phone *phone);
    void Enter_Information(Phone *phone);
    void Write_Information(Phone *phone);
    void Arrange_for_Resolution(Phone *phone);
    void Arrange_for_Memory_size(Phone *phone);
    void Arrange_for_Ram(Phone *phone);
    void Arrange_for_Price(Phone *phone);
    void Search_Phone(Phone *phone);
};
int Phone::quantity=0;
#endif