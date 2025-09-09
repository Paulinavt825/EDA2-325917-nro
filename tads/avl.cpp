#include <stdio.h>
#include <iostream>
#include <string.h>
using namespace std;

struct NodoAVL
{
    int id;
    string nombre;
    int puntaje;

    NodoAVL *izq;
    NodoAVL *der;
    int fVal;

    NodoAVL(int clave, string nom, int punt) : id(clave), nombre(nom), puntaje(punt), izq(NULL), der(NULL), fVal(0) {}
};

struct RepresentacionAVL
{
    NodoAVL *raiz;
    NodoAVL *top;
    int cantElementos;

    RepresentacionAVL() : raiz(NULL), top(NULL), cantElementos(0) {}
};
typedef RepresentacionAVL *AVL;

AVL crearAVL()
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
                if (p1->fVal == -1)
                {
                    pa->izq = p1->der;
                    p1->der = pa;
                    pa->fVal = 0;
                    pa = p1;
                }
                else
                {
                    NodoAVL *p2 = p1->der;
                    p1->der = p2->izq;
                    p2->izq = p1;
                    pa->izq = p2->der;
                    p2->der = pa;
                    pa->fVal = p2->fVal == -1 ? 1 : 0;
                    p1->fVal = p2->fVal == 1 ? -1 : 0;
                    pa = p2;
                }
                pa->fVal = 0;
                varioAltura = false;
                break;
            }
            varioAltura = false;
        }
        return insertado;
    }
    else if (id > pa->id)
    {
        insertado = insertarAVLRec(pa->der, top, id, nombre, puntaje, varioAltura);
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
                if (p1->fVal == 1)
                {
                    pa->der = p1->izq;
                    p1->izq = pa;
                    pa->fVal = 0;
                    pa = p1;
                }
                else
                {
                    NodoAVL *p2 = p1->izq;
                    p1->izq = p2->der;
                    p2->der = p1;
                    pa->der = p2->izq;
                    p2->izq = pa;
                    pa->fVal = p2->fVal == 1 ? -1 : 0;
                    p1->fVal = p2->fVal == -1 ? 1 : 0;
                    pa = p2;
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

void add(AVL avl, int id, string nombre, int puntaje)
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

string find(AVL avl, int id)
{
    return findRec(avl->raiz, id);
}

int rankear(AVL avl, int puntaje)
{
}

string top1(AVL avl)
{
    cout << avl->top->nombre << " " << avl->top->puntaje << endl;
}

int count(AVL avl)
{
    cout << avl->cantElementos << endl;
}

void insertarAVL(AVL a, int puntaje, string nombre, int id)
{
    bool varioAltura = false;
    bool insertado = insertarAVLRec(a->raiz, a->top, puntaje, nombre, id, varioAltura);
    if (insertado)
    {
        a->cantElementos++;
    }
}