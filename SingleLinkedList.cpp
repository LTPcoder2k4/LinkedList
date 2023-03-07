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

int addTailSLL(SingleLinkedList& list, Video newData) {
	//In case of empty list, new tail is the new head
	if (list.size == 0) return addHeadSLL(list, newData);

	//Get the tail node
	LinearNode* pTail = querySLL(list, list.size - 1);

	//Allocate new node
	LinearNode* pNewTail = new LinearNode;
	pNewTail->data = new Video;

	//In case of failed allocating
	if (!pNewTail || !(pNewTail->data)) return -1;

	//Assign new data to the new node
	videoCopy(pNewTail->data, newData);

	//Make the old tail connect to new tail
	pTail->next = pNewTail;

	//New tail connect to null
	pNewTail->next = NULL;

	//Increase size of list
	list.size++;

	//Successful code
	return 0;
}

int insertIntoSLL(SingleLinkedList& list, Video newData, int position) {
	//In case of adding to the head
	if (position == 0) return addHeadSLL(list, newData);

	//In case of adding to the tail
	if (position == list.size - 1) return addTailSLL(list, newData);

	//Get the previous node
	LinearNode* pPre = querySLL(list, position - 1);

	//Make sure the node is exist
	if (pPre) {
		//Allocate new node with new data
		LinearNode* newNode = new LinearNode;
		newNode->data = new Video;

		//In case of failed allocating
		if (!newNode || !(newNode->data)) return -1;

		//Assign new data to the new node
		videoCopy(newNode->data, newData);

		//New node point to the old one
		newNode->next = pPre->next;

		//Then take the position of the old node
		pPre->next = newNode;

		//Increase size of list
		list.size++;

		//Successful code
		return 0;
	}

	//position is out of list
	return -1;
}

int deleteHeadSLL(SingleLinkedList& list) {
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

		//Successful code
		return 0;
	}

	//Can not delete anymore
	return -1;
}

int deleteTailSLL(SingleLinkedList& list) {
	//Check if list is empty
	if (list.size) {
		//Get the tail
		LinearNode* tail = querySLL(list, list.size - 1);

		//Get the preTail
		LinearNode* preTail = querySLL(list, list.size - 2);

		//In case of only 1 element, delete tail mean delete head
		if (list.size == 1) return deleteHeadSLL(list);

		//Empty the data before deleting the old tail
		videoEmpty(tail->data);

		//Delete the old tail
		delete tail;

		//Destroy the connection of new tail and the old one
		preTail->next = NULL;

		//Decrease size of list
		list.size--;

		//Successful code
		return 0;
	}

	//Can not delete anymore
	return -1;
}

int deletePositionSLL(SingleLinkedList& list, int position) {
	//In case of deleting head
	if (position == 0) return deleteHeadSLL(list);

	//In case of deleting tail
	if (position == list.size - 1) return deleteTailSLL(list);

	//Get the node and the previous one
	LinearNode* pCurr = querySLL(list, position);
	LinearNode* pPre = querySLL(list, position - 1);

	//Make sure the node is exist
	if (pCurr && pPre) {
		//Make the previous point to the next one
		pPre->next = pCurr->next;
		
		//Empty the data before deleting the node
		videoEmpty(pCurr->data);

		//Delete the node
		delete pCurr;

		//Decrease size of list
		list.size--;

		//Successful code
		return 0;
	}

	//Can not delete the node in the given position
	return -1;
}

LinearNode* querySLL(const SingleLinkedList list, int position) {
	//Position is out of list
	if (position >= list.size) return 0;

	//Declare the result and move to the position
	LinearNode* pResult = list.head;
	while (position--) pResult = pResult->next;

	//Return the pointer point to the node
	return pResult;
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