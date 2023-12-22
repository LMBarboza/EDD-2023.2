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
    QuadTree(Point btmleft, Point toprght) {

        Rectangle boundary(btmleft, toprght);
        btmL = btmleft;
        topR = toprght;



    }

    QuadTree* topleftT;
    QuadTree* toprghtT;
    QuadTree* btmleftT;
    QuadTree* btmrghtT;
    int n_pontos = 0;



    bool folha = true;
    Node* n;


    void insert(Node* point) {
        if (point == NULL) { return; }

        n_pontos++;
        if (!inBoundary(point->pos)) { return; }

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

        //subdivisoes

        if (point->pos.x <= (topR.x + btmL.x) / 2) {
            if ((point->pos.y <= (topR.y + btmL.y) / 2)) {
                cout << point->pos.x << " , " << point->pos.y << "inferior esquerdo" << endl;
                if (btmleftT == NULL) {
                    btmleftT = new QuadTree(
                        Point(btmL.x, btmL.y),
                        Point((btmL.x + topR.x) / 2, (btmL.y + topR.y) / 2));

                }
                btmleftT->insert(point);
            }
            else {
                cout << point->pos.x << " , " << point->pos.y << "superior esquerdo" << endl;
                if (topleftT == NULL) {
                    topleftT = new QuadTree(
                        Point(btmL.x, (btmL.y + topR.y) / 2),
                        Point((btmL.x + topR.x) / 2, topR.y));
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
                        Point((btmL.x + topR.x) / 2, btmL.y),
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

        if (!inBoundary(point)) {
            cout << "Ponto fora da malha" << endl;
            return NULL;
        }

        if (folha) {
            cout << "folha" << endl;
            if (n == NULL) {
                return NULL;
            }
            if (n->pos.x == point.x and n->pos.y == point.y) {
                return n;
            }
            else {
                return NULL;
            }
        }

        QuadTree* Itr;
        Itr = new QuadTree(btmL, topR);



        if (topleftT->inBoundary(point)) { Itr = topleftT; }
        else if (toprghtT->inBoundary(point)) { Itr = toprghtT; }
        else if (btmleftT->inBoundary(point)) { Itr = btmleftT; }
        else if (btmrghtT->inBoundary(point)) { Itr = btmrghtT; }

        while (!Itr->folha) {

            if ((*Itr->topleftT).inBoundary(point)) {
                Itr = Itr->topleftT;
            }
            else if ((*Itr->toprghtT).inBoundary(point)) {
                Itr = Itr->toprghtT;
            }
            else if ((*Itr->btmleftT).inBoundary(point)) {
                Itr = Itr->btmleftT;

            }
            else if ((*Itr->btmrghtT).inBoundary(point)) {
                Itr = Itr->btmrghtT;
            }
        }

        if (Itr->n == NULL) {
            cout << "Não encontrei nada" << endl;
            return NULL;
        }
        if (Itr->n->pos.x == point.x && Itr->n->pos.y == point.y) {
            return n;
        }
    }

    bool inBoundary(Point point) {
        bool R = false;
        if ((point.x <= topR.x && point.x >= btmL.x) &&
            (point.y <= topR.y && point.y >= btmL.y))
        {
            R = true;
        }
        return R;

    }


};
