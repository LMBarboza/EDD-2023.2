// PR - Quadtree.cpp : Este arquivo contém a função 'main'. A execução do programa começa e termina ali.
//
#include <cmath>
#include <iostream>

class Point {
public:
    int x = x;
    int y = y;
    Point(int px = 0, int py = 0){ 
        x = px;
        y = py;
    }
    
};

class Node {
    Point pos;
    int data;
    Node(Point ppos = Point(), int pdata = 0) {
        pos = ppos;
        data = pdata;
    }
};

class Rectangle {
    Rectangle(Point btmleft, Point toprght) {
        Point x = btmleft;
        Point y = toprght;
        Point w(btmleft.x, toprght.y);
        Point h(btmleft.y, toprght.x);
    }
};


class QuadTree {
    Rectangle boundary;
    QuadTree() {

    }

    QuadTree(Point btmleft, Point toprght) {
        boundary = Rectangle(btmleft, toprght);
    }



};



int main()
{
    std::cout << "Hello World!\n";
}
