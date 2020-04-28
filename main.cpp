#include <iostream>
#include "list.hpp"
using namespace std;

int main()
{
	List list;
	list.print();
	Node *s = list.getLast();
	for (int i = 0; i < 5; i++)
	{
		int z;
		cout << ">> ";
		cin >> z;
		s = list.add(z, s);
	}
	list.print();
	cout << "Last element: " << list.getValue(list.getLast()) << endl;
	// Удаляем элементы, равные 0
	Node *p = list.getFirst();
	do
	{
		if (list.getValue(p) == 0)
			p = list.del(p);
		else
			p = list.next(p);
	} while (p != NULL);
	list.print();
	cout << "in list " << list.getCount() << " elents" << endl;
	list.swap(list.getFirst(), list.getLast());
	list.print();
	cout << "Seaching for node with value 4" << endl;
	Node *findedNode = list.find(4);
	if (findedNode)
	{
		findedNode->printField();
		cout << "Next node value:" << endl;
		list.next(findedNode)->printField();
	}
	list.clear();
	list.print();
	cout << "In list  " << list.getCount() << " elents" << endl;
	cin.get();
	cin.get();
	return 0;
}
