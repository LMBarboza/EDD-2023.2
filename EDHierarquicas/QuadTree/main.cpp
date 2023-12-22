#include <iostream>]
#include "PR-Quadtree.h"


int main() {
	Point ponto1(0, 0);
	Point ponto2(10, 10);

	Point ponto3(1, 1);
	Point ponto4(4, 4);
	Point ponto5(6, 6);
	Point ponto6(1, 7);
	Point ponto7(7, 1);

	Node n3(ponto3, 3);
	Node n4(ponto4, 4);
	Node n5(ponto5, 5);
	Node n6(ponto6, 6);
	Node n7(ponto7, 7);

	QuadTree QT(ponto1, ponto2);

	QT.insert(&n3);
	QT.insert(&n4);
	QT.insert(&n5);
	QT.insert(&n6);

	Node no = *QT.search(ponto6);
	cout << no.data << " <- dado / x = " << no.pos.x << " y =" << no.pos.y << endl;

	return 0;
}