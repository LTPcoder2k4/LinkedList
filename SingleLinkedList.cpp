#include "SingleLinkedList.h"
#include <iostream>

using namespace std;

void initSingleLinkedList(SingleLinkedList& list) {
	list.head = NULL;
	list.size = 0;
}

int addHeadSLL(SingleLinkedList& list, Video newData) {
	//Allocate new node with new data
	LinearNode* newNode = new LinearNode;
	newNode->data = new Video;

	//In case of failed allocating
	if (!newNode || !(newNode->data)) return -1;

	//Assign new data to the new node
	videoCopy(newNode->data, newData);

	//Make new connection for new node
	newNode->next = (list.size) ? list.head : NULL;

	//Then the new becomes the head
	list.head = newNode;

	//Increase size of list
	list.size++;

	//Successful code
	return 0;
}

void deleteHeadSLL(SingleLinkedList& list) {
	//Check if list is empty
	if (list.size) {
		//Save new head before deleting old head
		LinearNode* newHead = list.head->next;
		
		//Empty the data before deleting the old head
		videoEmpty(list.head->data);

		//Delete the old head
		delete list.head;

		//Save the new head
		list.head = newHead;

		//Decrease size of list
		list.size--;
	}
}

void displaySLL(const SingleLinkedList& list) {
	if (list.size) {
		int index = 0;

		for (LinearNode* pCurr = list.head; pCurr; pCurr = pCurr->next) {
			cout << "\nAt the node [" << index++ << "]:\n";

			//Give the value of the memory that pCurr->data points to
			//So we have to put bracket arround pCurr->data before dereference
			videoDisplay(*(pCurr->data));
		}
	}
	else {
		cout << "\nList is empty!\n";
	}
	
}

void destroySingleLinkedList(SingleLinkedList& list) {
	while (list.size) {
		//Delete head of the list until it becomes empty
		deleteHeadSLL(list);
	}
}