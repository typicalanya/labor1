#include <iostream>
#include <fstream>

#include "./utils.h"
#include "./staff.h"

using namespace std;

namespace staff {
	DoctorList* nodeList;
	int sortListIndex = LIST_SORT_TYPE_ID;

	void addItemBegin() {
		utl::clearScreen();

		auto* node = new Doctor;

		cout << "Enter staff data" << endl;
		cout << utl::HR_LINE << endl;

		bool validFullName = utl::readLineFromConsoleTo("full name", node->full_name);

		if (validFullName) {
			Doctor* tmp = nodeList->root;
			node->id = getLastID() + 1;
			if (tmp == nullptr)
			{
				nodeList->root = node;
				nodeList->curr = node;
				saveData();
				utl::setMenuMessage("Element successfully created!");
			}
			else {
				node->next = tmp;
				nodeList->root = node;
				saveData();
				utl::setMenuMessage("Element successfully created!");

			}
			
		}
		else {
			delete node;
			utl::setMenuMessage("Error adding element!");
		}
	}

	void addItemEnd() {
		utl::clearScreen();

		auto* node = new Doctor;

		cout << "Enter staff data" << endl;
		cout << utl::HR_LINE << endl;

		bool validFullName = utl::readLineFromConsoleTo("full name", node->full_name);

		if (validFullName) {
			Doctor* tmp = nodeList->root;
			node->id = getLastID() + 1;
			if (tmp == nullptr)
			{
				nodeList->root = node;
				nodeList->curr = node;
				saveData();
				utl::setMenuMessage("Element successfully created!");
			}
			else {
				Doctor* tmp = nodeList->root;
				while (tmp ->next != nullptr) {
					tmp = tmp->next;
				}
				tmp->next = node;
				node->next = nullptr;
				

				nodeList->curr = node;
				saveData();
				utl::setMenuMessage("Element successfully created!");
			}
		}
		else {
			delete node;
			utl::setMenuMessage("Error adding element!");
		}
	}

	void addItem() {
		utl::clearScreen();

		auto* node = new Doctor;

		cout << "Enter staff data" << endl;
		cout << utl::HR_LINE << endl;
		int insert_position = utl::readNumberFromConsole("Enter position to insert");

		bool validFullName = utl::readLineFromConsoleTo("full name", node->full_name);

		if (validFullName) {

			Doctor* tmp = nodeList->root;
			node->id = getLastID() + 1;
			if (tmp == nullptr)
			{
				nodeList->root = node;
				nodeList->curr = node;
				saveData();
				utl::setMenuMessage("Element successfully created!");
			}
			else {
				Doctor* tmp = nodeList->root;
				int schet = 0;
				while (tmp != nullptr) {
					if (tmp->id == insert_position) {
						schet++;
						node->next = tmp->next;
						tmp->next = node;
						break;
					}
					tmp = tmp->next;
				}
				if (schet == 0) {
					delete node;
					utl::setMenuMessage("Error adding element!");
				}
				else {
					nodeList->curr = node;
					saveData();
					utl::setMenuMessage("Element successfully created!");
				}

			}

		}
		else {
			delete node;
			utl::setMenuMessage("Error adding element!");
		}
	}

	void deleteItemEnd() {
		Doctor* tmp = nodeList->root;

		while (tmp->next != nullptr) 
			tmp = tmp->next;
		int id = tmp->id;
		deleteItemWeKnowID(id);
	}

	void deleteItemBegin() {
		Doctor* tmp = nodeList->root;
		if (tmp != nullptr) {
			int id = tmp->id;
			deleteItemWeKnowID(id);
		}
		else {
			utl::setMenuMessage("Doctor was not found!");
		}
	}

	void deleteItem() {
		utl::clearScreen();

		int staffID = utl::readNumberFromConsole("Enter staff ID");
		if (staffID != NULL) {

			if (deleteItemByID(staffID)) {
				utl::setMenuMessage("Doctor successfully deleted!");
			}
			else {
				utl::setMenuMessage("Doctor was not found!");
			}
		}
		else {
			utl::setMenuMessage("Incorrect ID!");
		}
	}


	void deleteItemWeKnowID(int staffID) {
		utl::clearScreen();

		//сохранить идишник для поиска записей удаляемых по этому доктору
		if (staffID != NULL) {
			if (deleteItemByID(staffID)) {
				utl::setMenuMessage("Doctor successfully deleted!");
			}
			else {
				utl::setMenuMessage("Doctor was not found!");
			}
		}
		else {
			utl::setMenuMessage("Incorrect ID!");
		}
	}

	void deleteAllItem() {
		Doctor* tmp = nodeList->root;
		Doctor* tmp1 = nodeList->root;
		if (tmp != nullptr) {
			while (tmp1 != nullptr) {
				tmp = tmp1;
				tmp1 = tmp1->next;
				nodeList->root = tmp1;
				delete tmp;
			}

			utl::setMenuMessage("Doctors successfully deleted!");
		}
		else {
			utl::setMenuMessage("Doctor was not found!");
		}
	}

	void findItems() {
		string search = utl::readLineFromConsole("Enter search string");
		search = utl::strToLower(search);

		Doctor* node = nodeList->root;

		string buffer;

		while (node != nullptr) {
			string representation = getItemRepresentation(node);
			string representationLower = utl::strToLower(representation);
			string::size_type matchPos = representationLower.find(search);

			if (matchPos != string::npos) {
				buffer.append(representation);
			}

			node = node->next;
		}

		if (buffer.empty()) {
			utl::setMenuMessage("Matches not found!");
		}
		else {
			utl::setMenuMessage(buffer.c_str());
		}
	}
	void emptyList() {
		Doctor* node = nodeList->root;
		int counter = 0;

		while (node != nullptr) {
			counter++;
			node = node->next;
		}

		if (counter == 0) {
			
			utl::setMenuMessage("List is empty.");
		}
		else {
			utl::setMenuMessage("List is not empty.");
		}
	}

	void dimensionList() {
		Doctor* node = nodeList->root;
		int counter = 0;

		while (node != nullptr) {
			counter=counter+1;
			node = node->next;
		}

		if (counter == 0) {

			utl::setMenuMessage("List is empty.");
		}
		else {
			utl::setResult("The dimension of the list: ", counter);
			
		}
	}

	void replace() {
		utl::clearScreen();
		Doctor* tmp = nodeList->root;
		auto* node = new Doctor;
		int schet = 0;
		int staffID = utl::readNumberFromConsole("Enter staff ID");
		bool validFullName = utl::readLineFromConsoleTo("replace full name", node->full_name);
		if (validFullName) {
			while (tmp != nullptr) {
				if ((staffID != NULL) && (tmp->id == staffID)) {
					tmp->full_name = node->full_name;
					utl::setMenuMessage("Element successfully created!");
					break;
				}
				else {
					utl::setMenuMessage("ID not found!");
				}
				tmp = tmp->next;
			}
		}
		saveData();
	}

	void printList() {
		string buffer = getListRepresentation();
		utl::setMenuMessage(buffer.c_str());
	}

	bool deleteItemByID(int id) {
		Doctor* node = nodeList->root;
		Doctor* prev = nullptr;
		int schet = 0;

		while (node != nullptr) {

			if (node->id == id) {
				schet += 1;
				if (prev == nullptr) {
					nodeList->root = node->next;
					
					delete node;
					node = nodeList->root;

				}
				else {
					prev->next = node->next;
					
					delete node;
					node = prev->next;

				}
				//continue;
				break;

			}

			prev = node;
			node = node->next;
		}
		saveData();
		if (schet == 0) {
			return false;
		}
		else {
			return true;
		}
	}

	void sortList() {
		bool unsorted = true;
		Doctor* curr, * next, * prev, * buffer;

		while (unsorted) {
			unsorted = false;
			curr = nodeList->root;
			prev = nullptr;

			while (curr) {
				next = curr->next;

				if (isNeedSwapBySortType(curr, next)) {
					// Меняем значения местами.
					swap(curr, next);

					if (prev != nullptr) {
						prev->next = curr;
					}
					else {
						nodeList->root = curr;
					}

					buffer = curr->next;
					curr->next = next;
					next->next = buffer;
					unsorted = true;
				}

				nodeList->curr = curr;

				prev = curr;
				curr = next;
			}
		}
	}

	bool isNeedSwapBySortType(Doctor* curr, Doctor* next) {
		if (next == nullptr) {
			return false;
		}

		switch (sortListIndex) {
		case LIST_SORT_TYPE_ID:
			return curr->id > next->id;
		case LIST_SORT_TYPE_NAME:
			return curr->full_name > next->full_name;
		default:
			return false;
		}
	}


	void loadData() {
		nodeList = new DoctorList;
		ifstream storage(STORAGE_FILEPATH);

		if (storage) {
			string line;
			Doctor* node, * prev = nullptr;

			while (getline(storage, line)) {
				if (!line.empty()) {
					node = new Doctor;

					short cell_counter = 0;
					string::size_type lastSeparatorPosition = 0;
					string::size_type currentSeparatorPosition = line.find(utl::STORAGE_SEPARATOR,
						lastSeparatorPosition);
					while (currentSeparatorPosition != string::npos) {
						string value = line.substr(lastSeparatorPosition,
							currentSeparatorPosition - lastSeparatorPosition);
						switch (cell_counter) {
						case 0:
							node->id = stoi(value);
							break;
						case 1:
							node->full_name = value;
							break;

						default:

							break;
						}

						cell_counter++;
						lastSeparatorPosition = currentSeparatorPosition + sizeof(utl::STORAGE_SEPARATOR);
						currentSeparatorPosition = line.find(utl::STORAGE_SEPARATOR, lastSeparatorPosition);
					}



					if (prev != nullptr) {
						prev->next = node;
					}

					prev = node;

					if (nodeList->root == nullptr) {
						nodeList->root = node;
					}

					nodeList->curr = node;
				}
			}

		}
	}

	void saveData() {
		ofstream storage(STORAGE_FILEPATH);
		Doctor* node = nodeList->root;

		while (node != nullptr) {
			string line;

			line.append(to_string(node->id) + utl::STORAGE_SEPARATOR);
			line.append(node->full_name + utl::STORAGE_SEPARATOR);

			storage << line << endl;

			node = node->next;
		}
	}

	void clearMemory() {
		Doctor* node = nodeList->root;

		while (node != nullptr) {
			Doctor* buffer = node->next;

			delete node;

			node = buffer;
		}

		delete nodeList;
	}

	int getLastID() {
		int last_id = 0;
		Doctor* node = nodeList->root;

		while (node != nullptr) {
			if (last_id < node->id) {
				last_id = node->id;
			}

			node = node->next;
		}

		return last_id;
	}

	Doctor* getLastNode() {
		Doctor* prev = nullptr;
		Doctor* curr = nodeList->root;

		while (curr != nullptr) {
			prev = curr;
			curr = curr->next;
		}

		return prev;
	}

	bool findItemByID() {
		int staffID = utl::readNumberFromConsole("Enter staff ID");
		Doctor* node = getItemByID(staffID);

		if (node != nullptr) {
			nodeList->curr = node;
			return true;
		}

		return false;
	}

	Doctor* getItemByID(int id) {
		Doctor* node = nodeList->root;

		while (node != nullptr) {
			if (node->id == id) {
				return node;
			}

			node = node->next;
		}

		return nullptr;
	}

	string getListRepresentation() {
		Doctor* node = nodeList->root;
		string buffer;

		buffer.append("ID\tDATA\n");

		int counter = 0;

		while (node != nullptr) {
			string line = getItemRepresentation(node);
			buffer.append(line);
			counter++;
			node = node->next;
		}

		if (counter == 0) {
			buffer.clear();
			buffer.append("Nothing to show...");
		}

		return buffer;
	}

	string getItemRepresentation(Doctor* node) {
		string buffer;

		buffer.append(to_string(node->id) + '\t');
		buffer.append(node->full_name);

		buffer += '\n';

		return buffer;
	}


}