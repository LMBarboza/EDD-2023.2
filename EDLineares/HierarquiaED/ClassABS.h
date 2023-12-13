#include <iostream>

template <class NodeABS>
class C_ABS {
public:
	int length = 0;

	NodeABS head;
	C_ABS() {}
	C_ABS(int i) { head.value = i; }

	bool isEmpty(void) {
		if (length == 0) {
			return true;
		}
		else { return false; }
	}

	int operator[](int index) {
		Node* Itr = &head;
		for (int i = 0; i < index; i++) {
			Itr = Itr->next;
		}
		return Itr->value;
	}
	

};