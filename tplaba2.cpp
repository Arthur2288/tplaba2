#include <iostream>
#include "Note.h"
#include "functions.h"
#include "Strings.h"

using namespace std;

int main()
{
    int command;
    int cnt = 0;
    Note* notes = new Note[cnt];
    cout << "1. Task 1\n"
            "2. Task 2\n"
            "Enter a command:\n";
    cin >> command;
    switch (command) {
        case 1: {
            while (true) {
                Menu();
                cin >> command;
                try {
                    switch (command) {
                        case 1: {
                            addNote(notes, cnt);
                            break;
                        }
                        case 2: {
                            addNoteByIndex(notes, cnt); // commit
                            break;
                        }
                        case 3: {
                            removeNote(notes, cnt);
                            break;
                        }
                        case 4: {
                            printNotes(notes, cnt);
                            break;
                        }
                        case 5: {
                            editNotes(notes, cnt);
                            break;
                        }
                        case 6: {
                            sortNotes(notes, cnt);
                            break;
                        }
                        case 7: {
                            checkNote(notes, cnt);
                            break;
                        }
                        case 8: {
                            cout << "Goodbye!\n";
                            delete[] notes;
                            return 0;
                        }
                        default: {
                            cout << "Command is not found!\n";
                        }
                    }
                }
                catch (Exception error) {
                    cout << error;
                }
            }
        }
        case 2:{
            while (true)
            {
                try
                {
                    cout << "Enter file name:\n";
                    std::string file;
                    cin >> file;
                    Strings object;
                    object.checkFile(file);
                    return 0;
                }
                catch (Exception error) {
                    cout << error;}
            }
        }
    }
}
