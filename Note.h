#pragma once
#ifndef TP_2LABA_Note_H
#define TP_2LABA_Note_H
#include <iostream>

class Note
{
private:
    std::string fio;
    int number_phone;
    int dr[3];
public:
    Note();
    Note(std::string fio, int number_phone, int dr[]);
    Note(const Note& other);
    ~Note();
    std::string getFio();
    void setFio(std::string fio);
    int getNumber_phone();
    void setNumber_phone(int number_phone);
    int* getdr();
    void setdr(int dr[]);
    friend std::ostream& operator<<(std::ostream& os, const Note& obj);
    friend std::istream& operator>>(std::istream& is, Note& obj);
};


#endif //TP_2LABA_Note_H
