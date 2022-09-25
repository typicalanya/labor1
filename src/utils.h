#include "string"

#ifndef MEDICAL_UTILS_H
#define MEDICAL_UTILS_H
using namespace std;

namespace utl {
    const char STORAGE_SEPARATOR = ';';
    const char HR_LINE[] = "==============================================================";
    const char FIELD_ERROR_TEMPLATE[] = "Incorrect field value: [%s] %s";

    const int MAX_INPUT_TRIES = 4;

    void clearScreen();

    bool readAnswerFromConsole(const char title[]);

    int readNumberFromConsole(const char title[]);

    string readWordFromConsole(const char title[]);

    string readLineFromConsole(const char title[]);

    string getWeekDayName(int index, bool abbreviation = false);

    bool readLineFromConsoleTo(const char fieldName[], string& field);

    bool readNumberFromConsoleTo(const char fieldName[], int& field, int min, int max);

    string strToLower(string& s);

    bool isMenuMessage();

    void setMenuMessage(const char title[]);

    void setResult(const char title[], int a);

    void clearMenuMessage();

    void printMenuMessage();

}
#endif //MEDICAL_UTILS_H#pragma once
