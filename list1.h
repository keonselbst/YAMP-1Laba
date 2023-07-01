#include <iostream>

typedef int TData;

struct Node {
	TData data;
	Node* next;
};

typedef Node* TList;

void initList(TList& head);
bool isEmpty(TList head);
TList newNode(TData);
void addToHead(TList& head, TData newelem);
void addAfterNode(TList pnode, TData newelem);
TData deleteFromHead(TList& head);
//TList deleteFromHead(TList& head);
TData deleteAfterNode(TList pnode);
void clearList(TList& head);
void printList(TList);
TList search(TList head, TData newelem);
void addTotail(TList head, TData newelem);
void deleteFromTail(TList head, TData newelem);
void deleteAfterElement(TList head, TData newelem);
void AddAfterElement(TList head, TData newelem, TData znach);
void deleteAllZnach(TList head, TData elem);
