#include <iostream>
#include <fstream>
#include <string>
using namespace std;

// template<class T>
class nodoHash
{
public:
    string dominio;
    string path;
    string titulo;
    int tiempo;
    bool estaBorrado;

    nodoHash(string dominio, string path, string titulo, int tiempo) : dominio(dominio), path(path), titulo(titulo), tiempo(tiempo), estaBorrado(false) {}
};

// template<class T>
class HashCerrado
{
private:
    nodoHash **tabla;
    int maxElementos;
    int cantElementos;
    int largoVec;

    bool esPrimo(int num)
    {
        if (num <= 1 || num % 2 == 0 && num != 2)
            return false;
        if (num == 2)
            return true;
        for (int i = 3; i < num / 2; i += 2)
        {
            if (num % i == 0)
            {
                return false;
            }
        }
        return true;
    }

    int primoSupMinimo(int dato)
    {
        while (!esPrimo(++dato));
        return dato;
    }

    int fHash1(string key)
    {
        int h = 0;
        for (int i = 0; i < key.length(); i++)
            h = h + key[i];
        return h;
    }

    int fHash2(string key)
    {
        int h = 0;
        for (int i = 0; i < key.length(); i++)
            h = 31 * h + int(key[i]);
        return h;
    }

public:
    HashCerrado(int maxElementos)
    {
        this->maxElementos = maxElementos;
        this->cantElementos = 0;
        this->largoVec = primoSupMinimo(maxElementos);
        this->tabla = new nodoHash *[this->largoVec];
        for (int i = 0; i < this->largoVec; i++)
        {
            this->tabla[i] = NULL;
        }
    }

    // Pre: !esLleno(h) && !pertenece(h, dato)
    void put(string dominio, string path, string titulo, int tiempo)
    {
        int i = fHash1(dominio) % largoVec;
        int j = 1;
        while (tabla[i] && !tabla[i]->estaBorrado)
        {
            i = abs(i + j * fHash2(dominio + path)) % largoVec;
            j++;
        }
        if (tabla[i])
        {
            tabla[i]->estaBorrado = false;
            tabla[i]->dominio = dominio;
            tabla[i]->path = path;
            tabla[i]->titulo = titulo;
            tabla[i]->tiempo = tiempo;
        }
        else
        {
            tabla[i] = new nodoHash(dominio, path, titulo, tiempo);
        }
        cantElementos++;
    }

    bool esLleno()
    {
        return cantElementos == maxElementos;
        // Si uso rehashing:
        // return cantElementos >= (maxElementos * 0.7);
    }

    string get(string dominio, string path)
    {
        int i = fHash2(dominio) % largoVec;
        int j = 1;
        while (tabla[i] && (tabla[i]->estaBorrado || tabla[i]->dominio != dominio || tabla[i]->path !=path))
        {
            i = abs(i + j * fHash1(dominio + path)) % largoVec;
            j++;
        }
        if(tabla[i]){
            return tabla[i]->dominio + " " + to_string(tabla[i]->tiempo);
        } else {
            return "recurso_no_encontrado";
        }
    }

    void remove(string dominio, string path)
    {
        int i = fHash2(dominio) % largoVec;
        int j = 1;
        while (tabla[i] && (tabla[i]->estaBorrado || tabla[i]->dominio != dominio || tabla[i]->path !=path))
        {
            i = abs(i + j * fHash1(dominio + path)) % largoVec;
            j++;
        }
        if(tabla[i]){
            tabla[i]->estaBorrado=true;
        }
    }

    bool contains(string dominio, string path)
    {
        int i = fHash2(dominio) % largoVec;
        int j = 1;
        while (tabla[i] && (tabla[i]->estaBorrado || tabla[i]->dominio != dominio || tabla[i]->path !=path))
        {
            i = abs(i + j * fHash1(dominio + path)) % largoVec;
            j++;
        }
        return tabla[i]!=NULL;
    }

    int count_domain(string dominio)
    {
        int i = fHash2(dominio) % largoVec;
        int j = 1;
        while (tabla[i] && (tabla[i]->estaBorrado || tabla[i]->dominio != dominio))
        {
            i = abs(i + j * fHash1(dominio)) % largoVec;
            j++;
        }
        return ;
    }

    string *list_domain(string dominio)
    {
        
    }

    void clear_domain(string dominio)
    {
    }

    int size()
    {
        return cantElementos;
    }

    void clear()
    {
        for(int i=0; i<largoVec && tabla[i]; i++){

        }

    }
};