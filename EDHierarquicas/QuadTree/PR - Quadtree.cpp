#include <cmath>
#include <iostream>

class Point {
public:
    int x = x;
    int y = y;
    Point(int px = 0, int py = 0) {
        x = px;
        y = py;
    }

};

class Node {
public:
    Point pos;
    int data;
    Node(Point ppos = Point(), int pdata = 0) {
        pos = ppos;
        data = pdata;
    }
};

class Rectangle {
public:
    Rectangle(Point btmleft, Point toprght) {
        Point x = btmleft;
        Point y = toprght;
        Point w(btmleft.x, toprght.y);
        Point h(btmleft.y, toprght.x);
    }
};


class QuadTree {
public:
    QuadTree(Point btmleft, Point toprght) {

        Rectangle boundary(btmleft, toprght);
        Point btmL = btmleft;
        Point topR = toprght;

        
    }

    QuadTree* topleftT;
    QuadTree* toprghtT;
    QuadTree* btmleftT;
    QuadTree* btmrghtT;

    bool folha = true;
    Node* n;





    void insert(Node* point) {
        if (point == NULL) { return; }
        if (!inBoundary(point->pos)) { return; }

        if (abs(topR.x - btmL.x <= 1) && abs(topR.y - btmL.y) <= 1){
            if (n == NULL) {
                n = point;
            }
            return;
        }

        if (folha && n == NULL) {
            n = point;
            return;
        }

        if (folha && n != NULL) {
            folha = false;
            insert(n);
        }

        if ((point->pos.x <= (topR.x + btmL.x) / 2) {
            if ((point->pos.y <= (topR.y + btmL.y) / 2)) {
                //inferior esquerdo
            }
            else {
                //inferior direito
            }

        }
        else {
            //superiores
        }
   
    }

    Node* search(Point point) {

    }

    bool inBoundary(Point point){
        return true;
    
    }
};
