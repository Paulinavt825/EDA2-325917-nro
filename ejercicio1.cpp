#include <cassert>
#include <string>
#include <iostream>
#include <limits>
#include "tads/avl.h"
#include "tads/avl.cpp"

using namespace std;

int main()
{
    AVL avl = crearAVL();
    int cant, id, puntaje;
    string op, nom;

    cin >> cant;
    for (int i = 0; i < cant; i++)
    {
        cin >> op;

        if (op == "ADD")
        {
            cin >> id;
            cin >> nom;
            cin >> puntaje;
            add(avl, id, nom, puntaje);
        }
        else if (op == "FIND")
        {
            cin >> id;
            cout << find(avl, id) << endl;
        }
        else if (op == "RANK")
        {
            cin >> puntaje;

            cout << rankear(avl, puntaje) << endl;
        }
        else if (op == "TOP1")
        {
            cout << top1(avl) << endl;
        }
        else if (op == "COUNT")
        {
            cout << count(avl) << endl;
        }
        else
        {
            // TENGO QUE HACER UN FINAL O IGNORO
        }
    }

    return 0;
}
