#include <cassert>
#include <string>
#include <iostream>
#include <limits>
#include "tads/Avl.h"
#include "tads/AvlImp.cpp"
#include <fstream>

using namespace std;

int main()
{
    // IMPORTANTE! BORRAR O COMENTAR LAS SIGUIENTES LINEAS  EN TODOS LOS EJERCICIOS DEL OBLIGATORIO. NO PUEDEN ESTAR EN NINGUNA ENTREGA!
    ifstream myFile("tests/ejercicio1/100000.in.txt");
    cin.rdbuf(myFile.rdbuf());
    // Si desean tirar la salida a un archivo, usen las siguientes líneas (si no, sáquenlas):
    ofstream myFile2("tests/ejercicio1/100000.mine.txt");
    cout.rdbuf(myFile2.rdbuf());

    // COMPILO
    //  ./a.exe ya lo hace
    //  diff --strip-trailing-cr arch1 arch2

    Avl avlId = crearAvl();
    Avl avlPun = crearAvl();
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
            add(avlId, id, nom, puntaje);
            add(avlPun, puntaje, nom, id);
        }
        else if (op == "FIND")
        {
            cin >> id;
            cout << find(avlId, id) << endl;
        }
        else if (op == "RANK")
        {
            cin >> puntaje;
            cout << rankear(avlPun, puntaje) << endl;
        }
        else if (op == "TOP1")
        {
            cout << top1(avlId) << endl;
        }
        else if (op == "COUNT")
        {
            cout << count(avlId) << endl;
        }
    }
    return 0;
}
