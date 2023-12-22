#ifndef Queue_h
#define Queue_h

#include <iostream>

class QNode {
public:
	int value;
	QNode* next;
	QNode(int i = NULL) { value = i; }
};

class QUEUE {
public:
	QNode* first;
	int length = 0;
	QUEUE(int i = NULL) { first = new QNode(i); }

	bool isEmpty(void) {
		bool R = false;
		if (length == 0) { R = true; }
		return R;
	}

	void append(int i){
		length++;
		QNode* Itr = first;
		while (Itr->next != nullptr) {
			Itr = Itr->next;
		}
		Itr->next = new QNode(i);
	}

	int dequeue(void) {
		length--;
		int R = first->value;
		first = first->next;
		return R;
	}

	int pop(int pos) {
		length--;
		QNode* Itr = first;
		for (int i = 0; i < pos; i++) {
			Itr = Itr->next;
		}
		int R = Itr->next->value;
		Itr->next = (Itr->next)->next;

		return R;
	}

	int tempo(void) {return length * 2;}
};



#endif