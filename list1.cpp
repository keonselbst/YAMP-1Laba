#pragma once
#include "list1.h"

// list initialization
void initList(TList& list) {
	list = nullptr;
}

// checking the list for emptiness
bool isEmpty(TList list) {
	return list == nullptr;
}

// function to create newNode in a linked list
TList newNode(TData data) {
	TList p = new Node;
	p->data = data;
	p->next = nullptr;
	return p;
}

// adding element to begin of list
void addToHead(TList& list, TData element) {
	TList p = new Node;
	p->data = element;
	p->next = list;
	list = p;
}

// adding data after node 
void addAfterNode(TList pNode, TData element) {
	TList p = new Node;
	p->data = element;
	p->next = pNode->next;
	pNode->next = p;
}

//// deleing node from head of list
TData deleteFromHead(TList& list) {
	TList current = list;
	list = list->next;
	current->next = nullptr;
	TData element = current->data;
	delete current;
	current = nullptr;
	return element;
}

//// deleting node from head of list
//TList deleteFromHead(TList& head)
//{
//	if (head != NULL) {
//		Node* p = head;
//		head = p->next;
//		p->next = nullptr;
//		delete p;
//		p = nullptr;
//		return head;
//	}
//}

// deleing data after node 
TData deleteAfterNode(TList pNode) {
	TList p = pNode->next;
	pNode->next = pNode->next->next; // pNode->next = p->next
	p->next = nullptr;
	TData element = p->data; 
	delete p;
	p = nullptr;
	return element;
}

/*
void deleteAfternode(TList head, TData elem) {
	Node* p = head;
	while (p->next != NULL && p->date != elem)
		p = p->next;
	Node* temp = p->next;
	Node* pNode = temp;
	p->next = pNode->next;
	pNode->next = nullptr;
	delete pNode;
	pNode = nullptr;
}
*/

// searching list
//TList search(TList head, TData element) {
//	Node* p = head;
//	while (p->data != element && p->next != nullptr)
//		p = p->next;
//	return p;
//}

/*
bool search(TList head, TData elem) {
	Node* p = head;
	while (p->date != elem && p->next != nullptr)
	{
		p = p->next;
	}
	if (p->date == elem)
		return true;
	else
		return false;
}*/

// clearing list
//void clearList(TList& list) {
//	while (!isEmpty(list)) {
//		deleteFromHead(list);
//	}
//}

// print list to console
void printList(TList list) {
	TList current = list;
	while (current != nullptr) {
		std::cout << current->data << " ";
		current = current->next;
	}
	std::cout << std::endl;
}

// adding element to tail of list
//void addTotail(TList head, TData element) {
//	Node* p = head;
//	while (p->next != nullptr) {
//		p = p->next;
//	}
//	Node* last = new Node;
//	p->next = last;
//	last->data = element;
//	last->next = nullptr;
//}

// deleing node from tail of list
//void deleteFromTail(TList head, TData element) {
//	Node* p = head;
//	while (p->next->next != NULL)
//		p = p->next;
//	deleteAfterNode(p);
//}
//
// 

// deleing data after el
void deleteAfterElement(TList head, TData element) {
	Node* p = head;
	while (p != nullptr) {
		if (p->next != nullptr) {
			if (p->data == element && p->next->data != element) {
				deleteAfterNode(p);
				p = p->next;
			}
			else p = p->next;
		}
		else p = p->next;
	}
}

// adding data after el
//void AddAfterElement(TList head, TData element, TData znach) {
//	Node* p = head;
//	while (p->data != element && p->next != nullptr) {
//		p = p->next;
//	}
//	Node* pNode = new Node;
//	pNode->next = p->next;
//	pNode->data = znach;
//	p->next = pNode;
//}

// Yдаление всех вхождений числа
void deleteAlloccur(TList head, TData elem)
{
	Node* p = head;
	if (p->data == elem) {
		deleteFromHead(p);
	}
	while (p->next != 0) {
		if (p->next->data == elem) {
			deleteAfterNode(p);
		}
		p = p->next;
	}
}