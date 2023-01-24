#ifndef COMPUTER_H
#define COMPUTER_h
#include "D:\OOP\bai2\machine.h"
class Computer:public Machine{
    private:
    char *chip;
    int Hard_disk_size,RAM;
    char *Hard_disk_drive;
    static int quantity;
    Manufacturer manufactures;
    public:
    Computer(const char *manufacturer_name="Samsung",const char *country="The United Kingdom",const char *address="113 Oxford Street",const char *chip="AMD Ryzen 7",const char *Hard_disk_drive="SSD 512GB"):Machine()
    {
        this->RAM=0;
        this->Hard_disk_size=0;
        this->Hard_disk_drive=new char[strlen(Hard_disk_drive)+30];
        strcpy(this->Hard_disk_drive,Hard_disk_drive);
        this->chip=new char[strlen(chip)+10];
        strcpy(this->chip,chip);
        manufactures.manufacturer_name=new char[strlen(manufacturer_name)+20];
        strcpy(manufactures.manufacturer_name,manufacturer_name);
        manufactures.country=new char[strlen(country)+20];
        strcpy(manufactures.country,country);
        manufactures.address=new char[strlen(address)+20];
        strcpy(manufactures.address,address);
    }
    ~Computer()
    {
        delete[]manufactures.manufacturer_name;
        delete[]manufactures.country;
        delete[]manufactures.address;
    }
    friend istream &operator>>(istream &is,Computer &computer);
    friend ostream &operator<<(ostream &os, Computer &computer);
    friend void Calculate_Price(Computer *computer);
    void Enter_Information(Computer *computer);
    void Write_Information(Computer *computer);
    void Arrange_for_RAM(Computer *computer);
    void Arrange_for_Price(Computer *computer);
    void Arrange_for_Hard_disk_size(Computer *computer);
    void Search_Hard_disk_drive(Computer *computer);
};
int Computer::quantity=0;
#endif