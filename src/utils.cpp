#include <cstdlib>
#include <iostream>
#include <string>
#include <sstream>
#include <iomanip>
#include <ctime>

#include "utils.h"

using namespace std;


namespace utl {
    string operationMessage;


    void clearScreen() {
        cout << string(10, '\n');
        system("cls");
    }

    bool readAnswerFromConsole(const char title[]) {
        cout << "[yes/no] ";
        string answer = readWordFromConsole(title);
        return tolower(answer[0]) == 'y';
    }

    int readNumberFromConsole(const char title[]) {
        int tries = 0;
        int buffer;
        string input;

        while (tries < MAX_INPUT_TRIES) {
            cout << title << ": ";
            cin >> input;

            try {
                buffer = stoi(input);
                return buffer;
            }
            catch (invalid_argument& err) {
                tries++;

                cout << "Not a number. Try again!" << endl;
            }
            catch (out_of_range& err) {
                tries++;

                cout << "Value is overflow. Try again!" << endl;
            }
        }

        return NULL;
    }

    string readWordFromConsole(const char title[]) {
        cout << title << ": ";
        string line;
        cin >> line;

        return line;
    }

    string readLineFromConsole(const char title[]) {
        cout << title << ":" << endl;

        int tries = 0;
        string line;

        do {
            getline(cin, line);
            tries++;
        } while (line.empty() || tries >= MAX_INPUT_TRIES);

        return line;
    }





    bool readLineFromConsoleTo(const char fieldName[], string& field) {
        char buffer[150];
        string detail, label;
        label += "Enter ";
        label += fieldName;

        string value = utl::readLineFromConsole(label.c_str());
        string::size_type pos = value.find(STORAGE_SEPARATOR);

        if (value.empty()) {
            detail = "is empty";
        }
        else if (pos != string::npos) {
            detail = "contain restrict char [";
            detail += STORAGE_SEPARATOR;
            detail += ']';
        }

        if (detail.empty()) {
            field = value;
            return true;
        }

        sprintf(buffer, FIELD_ERROR_TEMPLATE, fieldName, detail.c_str());
        utl::setMenuMessage(buffer);

        return false;
    }

    bool readNumberFromConsoleTo(const char fieldName[], int& field, int min, int max) {
        char buffer[150];
        string detail, label;
        label += "Enter ";
        label += fieldName;

        int number = utl::readNumberFromConsole(label.c_str());

        if (number < min) {
            detail = "less than " + to_string(min);
        }
        else if (number > max) {
            detail = "greater than " + to_string(max);
        }

        if (detail.empty()) {
            field = number;
            return true;
        }

        sprintf(buffer, FIELD_ERROR_TEMPLATE, fieldName, detail.c_str());
        utl::setMenuMessage(buffer);

        return false;
    }

    string strToLower(string& s) {
        string buffer;

        for (char c : s) {
            buffer += tolower(c);
        }

        return buffer;
    }

    bool isMenuMessage() {
        return !operationMessage.empty();
    }

    void setMenuMessage(const char title[]) {
        operationMessage += title;
        operationMessage += '\n';
        
    }
    
    void setResult(const char title[], int a) {
        
        operationMessage += title;
        operationMessage += to_string(a);
        operationMessage += '\n';
    }

    void clearMenuMessage() {
        operationMessage.clear();
    }

    void printMenuMessage() {
        cout << "Result: " << endl << operationMessage << endl;
        cout << utl::HR_LINE << endl;
        clearMenuMessage();
    }

}