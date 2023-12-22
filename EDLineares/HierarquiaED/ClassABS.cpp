#ifndef ClassABS_h
#define ClassAB_h

#include <iostream>

#pragma once

template <class NodeABS >
class C_ABS {
public:
	int length = 0;
	NodeABS* head;

	C_ABS() {}
	C_ABS(int i) { head->value = i; }

	bool isEmpty(void) {
		if (length == 0) {
			return true;
		}
		else { return false; }
	}

	int operator[](int index) {
		NodeABS* Itr = head;
		for (int i = 0; i < index; i++) {
			Itr = Itr->next;
		}
		return Itr->value;
	};
};


#endif