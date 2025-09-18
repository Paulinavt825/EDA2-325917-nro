#include <cassert>
#include <string>
#include <iostream>
#include <limits>
//#include "tads/HashCerrado.h"
#include "tads/HashCImp.cpp"

using namespace std;

int main()
{
    // IMPORTANTE! BORRAR O COMENTAR LAS SIGUIENTES LINEAS  EN TODOS LOS EJERCICIOS DEL OBLIGATORIO. NO PUEDEN ESTAR EN NINGUNA ENTREGA!
    ifstream myFile("tests/ejercicio2/100.in.txt");
    cin.rdbuf(myFile.rdbuf());
    // Si desean tirar la salida a un archivo, usen las siguientes líneas (si no, sáquenlas):
    ofstream myFile2("tests/ejercicio2/100.mine.txt");
    cout.rdbuf(myFile2.rdbuf());

    // COMPILO
    //  ./a.exe ya lo hace
    //  diff --strip-trailing-cr arch1 arch2

    int cant, tiempo;
    string op, dominio, path, titulo;

    cin >> cant;
    HashCerrado h = HashCerrado(cant);

    for (int i = 0; i < cant; i++)
    {
        cin >> op;

        if (op == "PUT")
        {
            cin >> dominio;
            cin >> path;
            cin >> titulo;
            cin >> tiempo;
            h.put(dominio, path, titulo, tiempo);
        }
        else if (op == "GET")
        {
            cin >> dominio;
            cin >> path;
            h.get(dominio, path);
        }
        else if (op == "REMOVE")
        {
            cin >> dominio;
            cin >> path;
            h.remove(dominio, path);
        }
        else if (op == "CONTAINS")
        {
            cin >> dominio;
            cin >> path;
            cout << h.contains(dominio, path) << endl;
        }
        else if (op == "COUNT_DOMAIN")
        {
            cin >> dominio;
            cout << h.count_domain(dominio) << endl;
        }
        else if (op == "LIST_DOMAIN")
        {
            cin >> dominio;
            cout << h.list_domain(dominio) << endl;
        }
        else if (op == "CLEAR_DOMAIN")
        {
            cin >> dominio;
            h.clear_domain(dominio);
        }
        else if (op == "SIZE")
        {
            cout << h.size() << endl;
        }
        else if (op == "CLEAR")
        {
            h.clear();
        }
    }

    return 0;
}
