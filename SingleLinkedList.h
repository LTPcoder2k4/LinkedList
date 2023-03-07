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
//Succesful: 0
//Fail: -1
int addHeadSLL(SingleLinkedList&, Video);

//Add new data into tail of Single Linked List
//Succesful: 0
//Fail: -1
int addTailSLL(SingleLinkedList&, Video);

//Add new data into tail of Single Linked List
//Succesful: 0
//Fail: -1
int insertIntoSLL(SingleLinkedList&, Video, int);

//Delete data in the head of Single Linked List
//Succesful: 0
//Fail: -1
int deleteHeadSLL(SingleLinkedList&);

//Delete data in the tail of Single Linked List
//Succesful: 0
//Fail: -1
int deleteTailSLL(SingleLinkedList&);

//Delete data in the tail of Single Linked List
//Succesful: 0
//Fail: -1
int deletePositionSLL(SingleLinkedList&, int);

//Query a node with the given position
//Succesful: pointer to the node
//Fail: 0
LinearNode* querySLL(const SingleLinkedList, int);

//Display entire list
void displaySLL(const SingleLinkedList&);

//Clear data
void destroySingleLinkedList(SingleLinkedList&);