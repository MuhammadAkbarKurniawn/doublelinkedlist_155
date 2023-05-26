#include<iostream>
#include<string>
using namespace std;

class Node {
public:
	int noMhs;
	string nama;
	Node* next;
	Node* prev;
};

class Doublelinkedlist {
private:
	Node* START;
public:
	Doublelinkedlist();
	void addNode();
	bool search(int rollNo, Node** previous, Node** current);
	bool deleteNode(int rollNo);
	bool listEmpty();
	void traverse();
	void revtraverse();
	void hapus();
	void searchData();
};

Doublelinkedlist::Doublelinkedlist() {
	START = NULL;
}

void Doublelinkedlist::addNode() {
	int nim;
	string nm;
	cout << "\Enter the roll number of the student: ";
	cin >> nim;
	cout << "\Enter the name of the student: ";
	cin >> nm;
	Node* newNode = new Node();		//step 1
	newNode->noMhs = nim;		//step 2
	newNode->nama = nm;		//step 2

	//insert a node in the beginning of a doubly - linked list
	if (START == NULL || nim <= START->noMhs) {
		if (START != NULL && nim == START->noMhs) {
			cout << "\nDuplicate number not allowed";
			return;
		}
		newNode->next = START;		//step 3
		if (START != NULL)
			START->prev = newNode;  //step 4
		newNode->prev = NULL;		//step 5
		START = newNode;		//step 6
		return;
	}

	/*Inserting a Node Between Two Nodes in the list */
	Node* current = START;	//step1.a
	Node* previous = NULL;	//step1.b
	while (current->next != NULL && current->next->noMhs < nim) //step 1.c
	{
		previous = current;		//step 1.d
		current = current->next;	//step 1.e
	}

	if (current->next != NULL && nim == current->next->noMhs) {
		cout << "\nDuplicate roll number not allowed" << endl;
		return;
	}

	newNode->next = current->next;		//step 4
	newNode->prev = current;		//step 5
	if (current->next != NULL)
		current->next->prev = newNode; //step 6
	current->next = newNode;		//step 7
}

bool Doublelinkedlist::search(int rollNo, Node** previous, Node** current) {
	*previous = NULL;	//step 1.a
	*current = START;	//step 1.b
	while (*current != NULL &&  rollNo != (*current)->noMhs) { //step 1.c
		*previous = *current;		//step 1.d
		*current = (*current)->next; // step 1.e
	}
	return (*current != NULL);
}

bool Doublelinkedlist::deleteNode(int rollNo) {
	Node* previous, * current;
	previous = current = NULL;
	if (search(rollNo, &previous, &current) == false)
		return false;
	if (current->next != NULL)
		current->next->prev = previous;
	if (previous != NULL)
		previous->next = current->next;
	else
		START = current->next;

	delete current;
	return true;
}

bool Doublelinkedlist::listEmpty() {
	return (START == NULL);
}

void Doublelinkedlist::traverse() {
	if (listEmpty())
		cout << "\nlist is empty" << endl;
	else {
		cout << "\nRecord in ascending order of roll number are: " << endl;
		Node* currentNode = START;
		while (currentNode != NULL) {
			cout << currentNode->noMhs << "  " << currentNode->nama << endl;
			currentNode = currentNode->next;
		}
	}
}

void Doublelinkedlist::revtraverse() {
	if (listEmpty()) {
		cout << "\nList is empty" << endl;
	}

	else {
		cout << "\nRecords in descending order of roll number are:" << endl;
		Node* currentNode = START;
		while (currentNode->next != NULL)
			currentNode = currentNode->next;

		while (currentNode != NULL) {
			cout << currentNode->noMhs << " " << currentNode->nama << endl;
			currentNode = currentNode->prev;
		}
	}
}

void Doublelinkedlist::hapus() {
	if (listEmpty()) {
		cout << "\nList is empty" << endl;

	}
	cout << "\nEnter the roll number of the student whose record is to be deleted: ";
	int rollNo;
	cin >> rollNo;
	cout << endl;
	if (Doublelinkedlist::deleteNode(rollNo) == false)
		cout << "Record wnot found" << endl;
	else
		cout << "Record with roll number " << rollNo << "deleted" << endl;
}   
void Doublelinkedlist::searchData() {
	if (listEmpty() == true) {
		cout << "\nList is empty" << endl;

	}
	Node* prev, * curr;
	prev = curr = NULL;
	cout << "\nEnter the roll number of the student whose record you want to search: ";
	int num;
	cin >> num;
	if (Doublelinkedlist::search(num, &prev, &curr) == false)
		cout << "\nRecord not found" << endl;
	else {
		cout << "\nRecord found" << endl;
		cout << "\nRoll number: " << curr->noMhs << endl;
		cout << "\nName: " << curr->nama << endl;
	}
} 

int main() {
	Doublelinkedlist obj;
	while (true) {
		try {
			cout << "\nMenu" << endl;
			cout << "1. Add a record to the list" << endl;
			cout << "2. Delete a record from the list" << endl;
			cout << "3. View all records in the ascending order of roll numbers" << endl;
			cout << "4. View all records in the descending order of roll numbers" << endl;
			cout << "5. Search for all record in the list" << endl;
			cout << "6. Exit" << endl;
			cout << "\nEnter your choice (1-6): " << endl;
			char ch;
			cin >> ch;

			switch (ch) {
			case '1':
				obj.addNode();
				break;
			case '2':
				obj.hapus();
				break;
			case '3':
				obj.traverse();
				break;
			case'4':
				obj.revtraverse();
				break;
			case'5':
				obj.searchData();
				break;
			case'6':
				return 0;
			default:
				cout << "\nInvalid option" << endl;
				break;
			}
		}
		catch (exception& e) {
			cout << "Check for the values entered." << endl;
		}
	}
}