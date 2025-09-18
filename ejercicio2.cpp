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

    int cant;
    string op;
    cin >> cant;
    HashCerrado h = HashCerrado(cant);

    for (int i = 0; i < cant; i++)
    {
        cin >> op;

        if (op == "PUT")
        {
        }
        else if (op == "GET")
        {
        }
        else if (op == "REMOVE")
        {
        }
        else if (op == "CONTAINS")
        {
        }
        else if (op == "COUNT_DOMAIN")
        {
        }
        else if (op == "LIST_DOMAIN")
        {
        }
        else if (op == "CLEAR_DOMAIN")
        {
        }
        else if (op == "SIZE")
        {
        }
        else if (op == "CLEAR")
        {
        }
    }

    return 0;
}
