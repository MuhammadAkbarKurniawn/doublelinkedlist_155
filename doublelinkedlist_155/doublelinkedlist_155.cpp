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
};