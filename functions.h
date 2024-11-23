#pragma once
#ifndef TP_2LABA_FUNCTIONS_H
#define TP_2LABA_FUNCTIONS_H
#include "Note.h"
#include "Exception.h"

void Menu()
{
    std::cout << "\nMenu:\n"
        "1. Add Note\n"
        "2. Add Note by index\n"
        "3. Remove Note\n"
        "4. Print Notes\n"
        "5. Edit Note\n"
        "6. Sort Notes\n"
        "7. Check Notes\n"
        "8. Exit\n"
        "Enter a command:\n";
}

void addNote(Note*& Notes, int& cnt)
{
    Note note;
    std::cin >> note;
    cnt++;
    Note* temp = new Note[cnt];
    for (int i = 0; i < cnt - 1; i++)
    {
        Note copy_Note(Notes[i]);
        temp[i] = copy_Note;
    }
    delete[] Notes;
    temp[cnt - 1] = note;
    Notes = temp;

}

void addNoteByIndex(Note*& Notes, int& cnt)
{
    int index;
    if (!cnt)
        throw Exception("There is no place for the object!\n");
    std::cout << "Enter index from 0 to " << cnt - 1 << ":\n";
    std::cin >> index;
    if (0 > index >= cnt)
        throw Exception("It is impossible to insert into this position!\n");
    Note Note;
    std::cin >> Note;
    Notes[index] = Note;
}

void removeNote(Note*& Notes, int& cnt)
{
    if (!cnt)
        throw Exception("There is no place for the object!\n");
    int index;
    std::cout << "Enter Note index to remove:\n";
    std::cin >> index;
    if (0 > index || index >= cnt)
        throw Exception("There is no such Note!\n");
    Note* temp = new Note[cnt - 1];
    for (int i = 0; i < index; i++)
    {
        temp[i] = Notes[i];
    }
    for (int i = index + 1; i < cnt; i++)
    {
        temp[i - 1] = Notes[i];
    }
    delete[] Notes;
    Notes = temp;
    cnt--;
}

void printNotes(Note*& Notes, int& cnt)
{
    if (!cnt)
        throw Exception("The list of Notes is empty!\n");
    std::cout << "There are " << cnt << " Notes:\n";
    for (int i = 0; i < cnt; i++) {
        std::cout << i + 1 << ". \n" << Notes[i] << "\n";
    }
}

void editNotes(Note*& Notes, int& cnt)
{
    if (!cnt)
        throw Exception("The list of Notes is empty!\n");
    int index;
    std::cout << "Enter Note index to edit from 0 to " << cnt - 1 << ":\n";
    std::cin >> index;
    if (0 > index || index >= cnt)
        throw Exception("There is no such Note!\n");
    Note Note;
    std::cin >> Note;
    Notes[index] = Note;
}

int convert_date(int* date)
{
    return date[0] + date[1] * 31 + date[2] * 365;
}
void sortNotes(Note*& Notes, int& cnt)
{
    for (int i = 0; i < cnt; i++)
    {
        for (int j = 0; j < cnt - 1; j++)
        {
            if (convert_date(Notes[j].getdr()) > convert_date(Notes[j + 1].getdr()))
            {
                Note temp(Notes[j]);
                Notes[j] = Notes[j + 1];
                Notes[j + 1] = temp;
            }
        }
    }
}

void checkNote(Note*& Notes, int& cnt)
{
    int phone;
    std::cout << "Enter phone:\n";
    std::cin >> phone;
    bool flag = false;
    for (int i = 0; i < cnt; i++)
    {
        if (phone == Notes[i].getNumber_phone())
        {
            std::cout << "Phone number: " << Notes[i].getNumber_phone() << ", "
                << "Fio: " << Notes[i].getFio() << std::endl;
            flag = true;
        }
    }
    if (!flag)
        std::cout << "There are no such Notes!\n";
}

#endif //TP_2LABA_FUNCTIONS_H
