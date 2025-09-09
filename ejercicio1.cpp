#include <cassert>
#include <string>
#include <iostream>
#include <limits>
#include "tads/avl.h"
#include "tads/avl.cpp"
#include <fstream>

using namespace std;

int main()
{
    // IMPORTANTE! BORRAR O COMENTAR LAS SIGUIENTES LINEAS  EN TODOS LOS EJERCICIOS DEL OBLIGATORIO. NO PUEDEN ESTAR EN NINGUNA ENTREGA!
    ifstream myFile("tests/ejercicio1/10.in.txt");
    cin.rdbuf(myFile.rdbuf());
    // Si desean tirar la salida a un archivo, usen las siguientes líneas (si no, sáquenlas):
    ofstream myFile2("tests/ejercicio1/10.mine.txt");
    cout.rdbuf(myFile2.rdbuf());
    
    //COMPILO
    // ./a.exe ya lo hace
    // diff --strip-trailing-cr arch1 arch2

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
    }

    return 0;
}
