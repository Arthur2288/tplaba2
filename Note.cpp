#include <iostream>
#include <string>
#include "Note.h"

using namespace std;

Note::Note()
{
    cout << "Note default constructor called\n" << endl;
}

Note::Note(std::string Fio, int Number_phone, int Dr[])
{
    fio = Fio;
    number_phone = Number_phone;
    for (int i = 0; i < 3; i++)
    {
        dr[i] = Dr[i];
    } 
    cout << "Note constructor with parameters called\n" << endl;
}

Note::Note(const Note& other)
{
    fio = other.fio;
    number_phone = other.number_phone;
    for (int i = 0; i < 3; i++)
    {
        dr[i] = other.dr[i];
    } 

    cout << "Note copy-constructor called\n" << endl;
}

Note::~Note()
{
    cout << "Note default destructor called\n" << endl;
}

string Note::getFio()
{
    return fio;
}

void Note::setFio(string dest)
{
    fio = dest;
}

int Note::getNumber_phone()
{
    return number_phone;
}

void Note::setNumber_phone(int flightNum)
{
    number_phone = flightNum;
}

int* Note::getdr()
{
    return dr;
}

void Note::setdr(int Dr[])
{
    for (int i = 0; i < 3; i++)
    {
        dr[i] = Dr[i];
    }
}

ostream& operator<<(ostream& os, const Note& obj)
{
    os << "Fio: " << obj.fio << endl;
    os << "Number_phone: " << obj.number_phone << endl;
    os << "Dr: " << obj.dr[0] << "." << obj.dr[1] << "." << obj.dr[2] << endl;
    return os;
}

istream& operator>>(istream& is, Note& obj) {
    cout << "Enter Fio: \n";
    is >> obj.fio;
    cout << "Enter Number_phone: \n";
    is >> obj.number_phone;
    cout << "Enter dr day: \n";
    is >> obj.dr[0];
    cout << "Enter dr month: \n";
    is >> obj.dr[1];
    cout << "Enter dr year: \n";
    is >> obj.dr[2];

    return is;
}
