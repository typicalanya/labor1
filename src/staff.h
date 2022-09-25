#include <string>


using namespace std;

#ifndef MEDICAL_STAFF_H
#define MEDICAL_STAFF_H
namespace staff {

	struct Doctor {
		int id = NULL;
		string full_name;
		Doctor* next = nullptr;
	};

	struct DoctorList {
		Doctor* root = nullptr;// корневой
		Doctor* curr = nullptr;
	};


	const char STORAGE_FILEPATH[] = "./staff.txt";
	const int LIST_SORT_TYPE_ID = 0;
	const int LIST_SORT_TYPE_NAME = 1;
	const string LIST_SORT_TYPES[] = { "ID", "full name" };

	void addItemBegin();

	void addItemEnd();

	void addItem(); //3

	void deleteItemEnd();

	void deleteItemBegin();

	void deleteItem(); //4

	void findItems(); //4

	void printList(); //3

	void deleteAllItem();

	void emptyList();

	void dimensionList();

	void replace();

	void loadData(); //3

	void saveData(); //3

	void clearMemory(); //3-4

	bool deleteItemByID(int id); //4

	void sortList(); //4

	bool isNeedSwapBySortType(Doctor* curr, Doctor* next); //4

	int getLastID();

	Doctor* getLastNode();

	bool findItemByID(); //4

	Doctor* getItemByID(int id);

	string getListRepresentation();

	string getItemRepresentation(Doctor* node);

	void deleteItemWeKnowID(int staffID);

}
#endif //MEDICAL_STAFF_H#pragma once