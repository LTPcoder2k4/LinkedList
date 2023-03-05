#pragma once
#include "SampleData.h"

struct LinearNode {
	Video* data;
	LinearNode* next;
};

struct SingleLinkedList {
	LinearNode* head;
	int size;
};

//Initialize default data
void initSingleLinkedList(SingleLinkedList&);

//Add new data into head of Single Linked List
int addHeadSLL(SingleLinkedList&, Video);

//Delete data in the head of Single Linked List
void deleteHeadSLL(SingleLinkedList&);

//Display entire list
void displaySLL(const SingleLinkedList&);

//Clear data
void destroySingleLinkedList(SingleLinkedList&);