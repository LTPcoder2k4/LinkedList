#include <iostream>
#include "SingleLinkedList.h"
using namespace std;

int main() {
	SingleLinkedList list{};
	initSingleLinkedList(list);
	displaySLL(list);
	Video newData = videoInput();
	addHeadSLL(list, newData);
	displaySLL(list);
	destroySingleLinkedList(list);
	return 0;
}