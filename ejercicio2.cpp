#include <cassert>
#include <string>
#include <iostream>
#include <limits>
#include "HashCerrado.h"
#include "HashCImp.cpp"

using namespace std;


int main()
{
    // IMPORTANTE! BORRAR O COMENTAR LAS SIGUIENTES LINEAS  EN TODOS LOS EJERCICIOS DEL OBLIGATORIO. NO PUEDEN ESTAR EN NINGUNA ENTREGA!
    ifstream myFile("tests/ejercicio1/10.in.txt");
    cin.rdbuf(myFile.rdbuf());
    // Si desean tirar la salida a un archivo, usen las siguientes líneas (si no, sáquenlas):
    ofstream myFile2("tests/ejercicio1/10.mine.txt");
    cout.rdbuf(myFile2.rdbuf());

    // COMPILO
    //  ./a.exe ya lo hace
    //  diff --strip-trailing-cr arch1 arch2

    int cant, id, puntaje;
    string op, nom;
    HashCerrado h = HashCerrado(1);

    cin >> cant;
    for (int i = 0; i < cant; i++)
    {
        cin >> op;

        if (op == "ADD")
        {
            
        }
        else if (op == "FIND")
        {
            
        }
        else if (op == "RANK")
        {
           
        }
        else if (op == "TOP1")
        {
           
        }
        else if (op == "COUNT")
        {
           
        }
    }

    return 0;
}
