#include "list.hpp"
#include <iostream>

using namespace std;

Node *List::add(int num, Node *node = NULL)
{
	Node *elem = new Node();
	elem->field = num;
	count++;
	if (node == NULL) // Добавление нового корня
	{
		elem->ptr = NULL;
		if (head == NULL)
		{
			head = elem;
		}
		else
		{
			elem->ptr = head;
			head = elem;
		}
		return elem;
	}
	elem->ptr = node->ptr; // Добавление узла после текущего
	node->ptr = elem;
	return elem;
}

Node *List::del(Node *node)
{
	if (node == NULL)
	{
		return NULL;
	} // В списке нет узлов
	count--;
	if (node == head) // Удаление корневого узла
	{
		head = node->ptr;
		delete node;
		return head;
	}
	Node *prev = previous(node); // Удаление промежуточного узла
	prev->ptr = node->ptr;
	delete node;
	return prev;
}

void List::print()
{
	if (isEmpty())
	{
		cout << "List is empty" << endl;
		return;
	}
	Node *p = head;
	do
	{
		cout << getValue(p) << " ";
		p = next(p);
	} while (p != NULL);
	cout << endl;
}

void List::clear()
{
	Node *p = head;
	if (p == NULL)
		return;
	do
	{
		Node *d = p;
		p = next(p);
		delete d;
	} while (p != NULL);
	count = 0;
	head = NULL;
}

Node *List::getLast()
{
	Node *p = head;
	while (next(p) != NULL)
		p = next(p);
	return p;
}

Node *List::next(Node *node)
{
	if (isEmpty())
		return NULL;
	return node->ptr;
}

Node *List::previous(Node *node)
{
	if (isEmpty())
		return NULL;
	if (node == head)
		return NULL;
	Node *p = head;
	while (p->ptr != node)
		p = p->ptr;
	return p;
}

void List::swap(Node *node1, Node *node2)
{
	if (node1 == NULL || node2 == NULL)
		return;
	if (node1 == node2)
		return;
	if (node2->ptr == node1)
	{
		Node *p = node1;
		node1 = node2;
		node2 = p;
	}
	Node *prev1 = previous(node1);
	Node *prev2 = previous(node2);
	Node *next1 = next(node1);
	Node *next2 = next(node2);
	if (next1 == node2)
	{
		if (prev1 != NULL)
			prev1->ptr = node2;
		else
			head = node2;
		node2->ptr = node1;
		node1->ptr = next2;
		return;
	}
	if (prev1 != NULL)
		prev1->ptr = node2;
	else
		head = node2;
	if (prev2 != NULL)
		prev2->ptr = node1;
	else
		head = node1;
	node2->ptr = next1;
	node1->ptr = next2;
}

Node *List::find(int value)
{
	int counter = 0;
	Node *node = getFirst();
	while (node->field != value)
	{
		node = next(node);
		counter++;
		if (node == NULL)
		{
			cout << "Node not fould" << endl;
			return NULL;
		}
	}
	cout << "Fould at position: " << counter << endl;
	return node;
}
