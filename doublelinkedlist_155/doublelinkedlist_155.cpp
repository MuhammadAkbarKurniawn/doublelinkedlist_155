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