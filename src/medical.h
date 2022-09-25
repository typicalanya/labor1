#include <string>

#ifndef MEDICAL_MEDICAL_H
#define MEDICAL_MEDICAL_H

using namespace std;

namespace mdc {
    const char APP_TITLE[] = "Medical CRM system";
    const int MENU_SIZE_LIMIT = 20;

    // Системные коды.
    const int MC_EXIT = 1;
    const int MC_MAIN = 2;
    const int MC_UNDECLARED = 3;

    // Коды основного меню.
    const int MC_STAFF_DATA = 100;

    // Коды меню: Данные персонала.
    const int MC_STAFF_DATA_ADD_BEGIN = 998;
    const int MC_STAFF_DATA_ADD_END = 999;
    const int MC_STAFF_DATA_ADD = 1000;
    const int MC_STAFF_DATA_DELETE = 1001;
    const int MC_STAFF_DATA_DELETE_END = 1005;
    const int MC_STAFF_DATA_DELETE_BEGIN = 1006;
    const int MC_STAFF_DATA_DELETE_ALL = 1007;
    const int MC_STAFF_DATA_EDIT = 1002;
    const int MC_STAFF_DATA_FIND = 1003;
    const int MC_STAFF_DATA_PRINT = 1004;
    const int MC_STAFF_DATA_EMPTY = 1008;
    const int MC_STAFF_DATA_DIMENSION = 1009;
    const int MC_STAFF_DATA_REPLACE = 1010;

    void loopMenu();

    void printPage();

    void displayMenu();

    void pushMenuItem(const char* name, int code, string* menu);

    void readUserMenuChoice();

    void doUserChoiceAction();

    void loadData();

    void clearMemory();
}
#endif //MEDICAL_MEDICAL_H#pragma once
