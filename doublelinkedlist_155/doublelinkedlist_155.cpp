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

}