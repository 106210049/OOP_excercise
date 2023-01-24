#ifndef MACHINE_H
#define MACHINE_H
#include<iostream>
#include<string.h>
#include<stdio.h>
using namespace std;

class Manufacturer{
    private:
    char *manufacturer_name,*country,*address;
    public:
    friend class Computer;
    friend class Phone;
};
class Machine{
    protected:
    char *brand,*color;
    float mass;
    float price;
    public:
    Machine(const char *brand="Samsung",const char *color="Yellow")
    {
        this->brand=new char[strlen(brand)+10];
        strcpy(this->brand,brand);
        this->color=new char[strlen(color)+10];
        strcpy(this->color,color);
        this->mass=0;
        this->price=0;
    }
    ~Machine()
    {
        delete[]brand;
        delete[]color;
    }
};
#endif
