#include "Avl.h"
#include <stdio.h>
#include <iostream>
#include <string>
using namespace std;

struct NodoAVL
{
    int id;
    string nombre;
    int puntaje;

    NodoAVL *izq;
    NodoAVL *der;
    int fVal;
    int tamano;

    NodoAVL(int clave, string nom, int punt) : id(clave), nombre(nom), puntaje(punt), izq(NULL), der(NULL), fVal(0), tamano(1) {}
};

struct RepresentacionAVL
{
    NodoAVL *raiz;
    NodoAVL *top;
    int cantElementos;

    RepresentacionAVL() : raiz(NULL), top(NULL), cantElementos(0) {}
};

Avl crearAvl()
{
    return new RepresentacionAVL();
}

// pre:
// post:
void actualizarTop(NodoAVL *nuevo, NodoAVL *&top)
{
    if (!top || (top->puntaje < nuevo->puntaje) || (top->puntaje == nuevo->puntaje && top->id > nuevo->id))
    {
        top = nuevo;
    }
}

// pre:
// post:
void actualizarTamano(NodoAVL *a)
{
    if (a)
    {
        int tIzq = 0;
        int tDer = 0;
        if (a->der)
        {
            tDer = a->der->tamano;
        }
        if (a->izq)
        {
            tIzq = a->izq->tamano;
        }
        a->tamano = 1 + tIzq + tDer;
    }
}

bool insertarAVLRec(NodoAVL *&pa, NodoAVL *&top, int puntaje, string nombre, int id, bool &varioAltura)
{
    bool insertado;
    if (pa == NULL)
    {
        pa = new NodoAVL(id, nombre, puntaje);
        actualizarTop(pa, top);
        varioAltura = true;
        return true;
    }
    if (id < pa->id)
    {
        insertado = insertarAVLRec(pa->izq, top, puntaje, nombre, id, varioAltura);
        actualizarTamano(pa);

        if (varioAltura)
        {
            switch (pa->fVal)
            {
            case 1:
                pa->fVal = 0;
                varioAltura = false;
                break;
            case 0:
                pa->fVal = -1;
                break;
            case -1:
                NodoAVL *p1 = pa->izq;
                if (p1->fVal == -1) // Rot Der
                {
                    pa->izq = p1->der;
                    p1->der = pa;
                    pa->fVal = 0;
                    pa = p1;

                    actualizarTamano(p1);
                    actualizarTamano(pa);
                }
                else // Rot Izq-Der
                {
                    NodoAVL *p2 = p1->der;
                    p1->der = p2->izq;
                    p2->izq = p1;
                    pa->izq = p2->der;
                    p2->der = pa;
                    pa->fVal = p2->fVal == -1 ? 1 : 0;
                    p1->fVal = p2->fVal == 1 ? -1 : 0;
                    pa = p2;

                    actualizarTamano(p1);
                    actualizarTamano(p2);
                    actualizarTamano(pa);
                }
                pa->fVal = 0;
                varioAltura = false;
                break;
            }
            varioAltura = false;
        }
        return insertado;
    }
    else if (id >= pa->id)
    {
        insertado = insertarAVLRec(pa->der, top, puntaje, nombre, id, varioAltura);
        actualizarTamano(pa);

        if (varioAltura)
        {
            switch (pa->fVal)
            {
            case -1:
                pa->fVal = 0;
                varioAltura = false;
                break;
            case 0:
                pa->fVal = 1;
                break;
            case 1:
                NodoAVL *p1 = pa->der;
                if (p1->fVal == 1) //Rot Izq
                {
                    pa->der = p1->izq;
                    p1->izq = pa;
                    pa->fVal = 0;
                    pa = p1;

                    actualizarTamano(p1);
                    actualizarTamano(pa);
                }
                else //Rot Der-Izq
                {
                    NodoAVL *p2 = p1->izq;
                    p1->izq = p2->der;
                    p2->der = p1;
                    pa->der = p2->izq;
                    p2->izq = pa;
                    pa->fVal = p2->fVal == 1 ? -1 : 0;
                    p1->fVal = p2->fVal == -1 ? 1 : 0;
                    pa = p2;

                    actualizarTamano(p1);
                    actualizarTamano(p2);
                    actualizarTamano(pa);

                    return insertado;
                }
                pa->fVal = 0;
                varioAltura = false;
                break;
            }
            varioAltura = false;
        }
        return insertado;
    }
    else
        return false;
}

void add(Avl avl, int id, string nombre, int puntaje)
{
    bool varioAltura = false;
    bool insertado = insertarAVLRec(avl->raiz, avl->top, puntaje, nombre, id, varioAltura);
    if (insertado)
    {
        avl->cantElementos++;
    }
}

string findRec(NodoAVL *raiz, int id)
{
    if (!raiz)
    {
        return "jugador_no_encontrado";
    }
    else
    {
        if (raiz->id == id)
        {
            string res = raiz->nombre + " " + to_string(raiz->puntaje);
            return res;
        }
        else if (raiz->id < id)
        {
            return findRec(raiz->der, id);
        }
        else
        {
            return findRec(raiz->izq, id);
        }
    }
}

string find(Avl avl, int id)
{
    return findRec(avl->raiz, id);
}

int rankear(Avl avl, int puntaje)
{
    return 0;
}

string top1(Avl avl)
{
    string res = avl->top->nombre + " " + to_string(avl->top->puntaje);
    return res;
}

int count(Avl avl)
{
    return avl->cantElementos;
}