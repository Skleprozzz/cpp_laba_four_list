#include <iostream>
#include "node.hpp"

class List
{
	Node *head;
	int count = 0;
	Node* previous(Node *); // Переход к предыдущему узлу (не интерфейсный метод)
public:
	List() { head = NULL; } // Инициализация списка
	int getCount() { return count; } // Получение количества узлов списка
	bool isEmpty() { return head == NULL; }  // Проверка, пуст ли список
	int getValue(Node* p) { return p->field; } // Получение значения узла списка
	void setValue(Node *p, int val) { p->field = val; } // Установка значения узла списка
	Node* getFirst() { return head; } // Получение корневого узла списка
	Node* getLast();			// Получение последнего узла списка
	void clear();				// Очистка списка
	Node* next(Node *);			// Переход к следующему узлу
	Node* add(int, Node*);		// Добавление узла списка
	Node* del(Node*);		// Удаление узла списка
	void print();				// Вывод значений узлов списка
	void swap(Node*, Node*);	// Взаимообмен двух узлов
	Node* find(int);
	void printNode(Node*);
};