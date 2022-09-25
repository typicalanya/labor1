#include <iostream>

#include "utils.h"
#include "staff.h"
#include "medical.h"

using namespace std;

namespace mdc {
    int menuCodes[MENU_SIZE_LIMIT];
    int curMenuCode = MC_MAIN;

    void loadData() {
        staff::loadData();

    }

    void clearMemory() {
        staff::clearMemory();

    }

    void loopMenu() {
        while (curMenuCode != MC_EXIT) {
            printPage();
            readUserMenuChoice();
            doUserChoiceAction();
        }
    }

    void printPage() {
        utl::clearScreen();

        cout << APP_TITLE << endl;
        cout << utl::HR_LINE << endl;

        if (utl::isMenuMessage()) {
            utl::printMenuMessage();
        }

        displayMenu();
    }

    void displayMenu() {
        string menu[MENU_SIZE_LIMIT];

        for (int& menuCode : menuCodes) {
            menuCode = MC_UNDECLARED;
        }

        switch (curMenuCode) {
        case MC_MAIN:
            cout << "Main menu:" << endl;
            pushMenuItem("Staff data", MC_STAFF_DATA, menu);
            break;
        case MC_STAFF_DATA:
            cout << "Staff data:" << endl;
            pushMenuItem("Add staff Begin", MC_STAFF_DATA_ADD_BEGIN, menu);
            pushMenuItem("Add staff End", MC_STAFF_DATA_ADD_END, menu);
            pushMenuItem("Add staff id", MC_STAFF_DATA_ADD, menu);
            pushMenuItem("Delete staff end", MC_STAFF_DATA_DELETE_END, menu);
            pushMenuItem("Delete staff begin", MC_STAFF_DATA_DELETE_BEGIN, menu);
            pushMenuItem("Delete all staff", MC_STAFF_DATA_DELETE_ALL, menu);
            pushMenuItem("Delete staff id", MC_STAFF_DATA_DELETE, menu);
            pushMenuItem("Find staff", MC_STAFF_DATA_FIND, menu);
            pushMenuItem("Print staff", MC_STAFF_DATA_PRINT, menu);
            pushMenuItem("List is empty?", MC_STAFF_DATA_EMPTY, menu);
            pushMenuItem("The dimension of the list", MC_STAFF_DATA_DIMENSION, menu);
            pushMenuItem("Replace data id", MC_STAFF_DATA_REPLACE, menu);

            break;

        default:
            cout << "Undefined operation!" << endl;
            break;
        }

        // Определяем куда будет вести кнопка назад
        switch (curMenuCode) {
        case MC_MAIN:
            pushMenuItem("Exit", MC_EXIT, menu);
            break;
       
        default:
            pushMenuItem("Main menu", MC_MAIN, menu);
            break;
        }

        for (int i = 0; i < MENU_SIZE_LIMIT; i++) {
            string& menuItem = menu[i];

            if (menuItem.empty()) {
                break;
            }

            cout << "[" << i + 1 << "] " << menuItem << endl;
        }
    }

    void pushMenuItem(const char* name, int code, string* menu) {
        for (int i = 0; i < MENU_SIZE_LIMIT; i++) {
            if (menu[i].empty()) {
                menu[i] = name;
                menuCodes[i] = code;
                break;
            }
        }
    }

    void readUserMenuChoice() {
        int choice = utl::readNumberFromConsole("Select action");

        if (choice != NULL) {
            if (choice <= 0 || choice > MENU_SIZE_LIMIT || menuCodes[choice - 1] == MC_UNDECLARED) {
                utl::setMenuMessage("Invalid choice!");
            }
            else {
                curMenuCode = menuCodes[choice - 1];
            }
        }
        else {
            utl::setMenuMessage("Input error for 4 attempts. Operation is interrupted!");
        }
    }

    void doUserChoiceAction() {
        switch (curMenuCode) {
            // Работа с данными по сотрудникам.
        case MC_STAFF_DATA_ADD_BEGIN:
            staff::addItemBegin();
            curMenuCode = MC_STAFF_DATA;
            break;
        case MC_STAFF_DATA_ADD_END:
            staff::addItemEnd();
            curMenuCode = MC_STAFF_DATA;
            break;
        case MC_STAFF_DATA_ADD:
            staff::addItem();
            curMenuCode = MC_STAFF_DATA;
            break;
        case MC_STAFF_DATA_DELETE_END:
            staff::deleteItemEnd();
            curMenuCode = MC_STAFF_DATA;
            break;
        case MC_STAFF_DATA_DELETE_BEGIN:
            staff::deleteItemBegin();
            curMenuCode = MC_STAFF_DATA;
            break;
        case MC_STAFF_DATA_DELETE_ALL:
            staff::deleteAllItem();
            curMenuCode = MC_STAFF_DATA;
            break;
        case MC_STAFF_DATA_DELETE:
            staff::deleteItemWeKnowID((utl:: readNumberFromConsole("Enter staff ID")));
            curMenuCode = MC_STAFF_DATA;
            break;
        case MC_STAFF_DATA_FIND:
            staff::findItems();
            curMenuCode = MC_STAFF_DATA;
            break;
        case MC_STAFF_DATA_PRINT:
            staff::printList();
            curMenuCode = MC_STAFF_DATA;
            break;
        case MC_STAFF_DATA_EMPTY:
            staff::emptyList();
            curMenuCode = MC_STAFF_DATA;
            break;
        case MC_STAFF_DATA_DIMENSION:
            staff::	dimensionList();
            curMenuCode = MC_STAFF_DATA;
            break;
        case MC_STAFF_DATA_REPLACE:
            staff::replace();
            curMenuCode = MC_STAFF_DATA;
            break;

        default:
            break;
        }
    }
}