#include <iostream>

using namespace std;

class Node
{
	int field;
	Node *ptr;
	friend class List;

public:
	void printField() { cout << field << endl; } // Вывод значения в узле
};