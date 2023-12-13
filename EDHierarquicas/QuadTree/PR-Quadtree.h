#include <cmath>
#include <iostream>

using namespace std;

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
    Point btmL;
    Point topR;
    ///Rectangle boundary;
    QuadTree(Point btmleft, Point toprght) {

        Rectangle boundary(btmleft, toprght);
        btmL = btmleft;
        topR = toprght;
        


    }
    
    QuadTree* topleftT;
    QuadTree* toprghtT;
    QuadTree* btmleftT;
    QuadTree* btmrghtT;

   

    bool folha = true;
    Node* n;





    void insert(Node* point) {
        if (point == NULL) { return; }
        if (!inBoundary(point->pos)) { cout << "Boundary" << endl; return; }

        if (abs(topR.x - btmL.x <= 1) && abs(topR.y - btmL.y) <= 1) {
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

        cout << "subdivisoes" << endl;

        if (point->pos.x <= (topR.x + btmL.x) / 2) {
            if ((point->pos.y <= (topR.y + btmL.y) / 2)) {
                cout << point->pos.x << " , " << point->pos.y << "inferior esquerdo" << endl;
                if (topleftT == NULL) {
                    topleftT = new QuadTree(
                        Point(btmL.x, btmL.y),
                        Point((btmL.x + topR.x) / 2, (btmL.y + topR.y) / 2));

                }
                topleftT->insert(point);
            }
            else {
                cout << point->pos.x << " , " << point->pos.y << "superior esquerdo" << endl;
                if (topleftT == NULL) {
                    topleftT = new QuadTree(
                        Point(btmL.x, (btmL.y + topR.y) / 2),
                        Point(topR.y, (btmL.x + topR.x) / 2));
                }
                topleftT->insert(point);
            }

        }
        else {
            //direitos
            if (point->pos.y <= (btmL.y + topR.y) / 2) {
                cout << point->pos.x << " , " << point->pos.y << "inferior direito" << endl;
                if (btmrghtT == NULL) {
                    btmrghtT = new QuadTree(
                        Point(btmL.y, (btmL.x + topR.x) / 2),
                        Point(topR.x, (btmL.y + topR.y) / 2));
                }
                btmrghtT->insert(point);
            }
            else {
                cout << point->pos.x << " , " << point->pos.y << "superior direito" << endl;
                if (toprghtT == NULL) {
                    toprghtT = new QuadTree(
                        Point((btmL.x + topR.x) / 2, (btmL.y + topR.y) / 2),
                        Point(topR.x, topR.y));
                }
                toprghtT->insert(point);
            }
        }
    }

    Node* search(Point point) {

    }

    bool inBoundary(Point point) {
        return true;

    }
};