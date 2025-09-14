#ifndef AVL_IMP
#define AVL_IMP

#include "Avl.h"
#include < cassert>
#include < string.h>
using namespace std;

typedef AvlImp Avl;

class AvlImp
{
private:
    class NodoAvl
    {
    public:
        int clave;
        string datoS;
        int datoI;
        NodoAvl *der;
        NodoAvl *izq;
        int fVal;
        NodoAvl(int clave, string datoS, int datoI) : clave(clave), datoS(datoS), datoI(datoI), der(NULL), izq(NULL), fVal(0) {}
    };

    NodoAvl *raizIds;
    NodoAvl *raizPuntajes;
    NodoAvl *top;
    int cantElementos;

public:
    AvlImp() : raizIds(NULL), raizPuntajes(NULL), top(NULL), cantElementos(0) {}
    
    void actualizarTop(NodoAvl *nuevo, NodoAvl *&top)
    {
        if (!top || (top->datoI < nuevo->datoI) || (top->datoI == nuevo->datoI && top->clave > nuevo->clave))
        {
            top = nuevo;
        }
    }
    bool insertarAVLRec(NodoAvl *&pa, NodoAvl *&top, int datoI, string datoS, int clave, bool &varioAltura)
    {
        bool insertado;
        if (pa == NULL)
        {
            pa = new NodoAvl(clave, datoS, datoI);
            actualizarTop(pa, top);
            varioAltura = true;
            return true;
        }
        if (clave < pa->clave)
        {
            insertado = insertarAVLRec(pa->izq, top, datoI, datoS, clave, varioAltura);
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
                    NodoAvl *p1 = pa->izq;
                    if (p1->fVal == -1)
                    {
                        pa->izq = p1->der;
                        p1->der = pa;
                        pa->fVal = 0;
                        pa = p1;
                    }
                    else
                    {
                        NodoAvl *p2 = p1->der;
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
        else if (clave > pa->clave)
        {
            insertado = insertarAVLRec(pa->der, top, datoI, datoS, clave, varioAltura);
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
                    NodoAvl *p1 = pa->der;
                    if (p1->fVal == 1)
                    {
                        pa->der = p1->izq;
                        p1->izq = pa;
                        pa->fVal = 0;
                        pa = p1;
                    }
                    else
                    {
                        NodoAvl *p2 = p1->izq;
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
    void add(Avl a, int clave, string datoS, int datoI)
    {
        bool varioAltura = false;
        bool insertado = insertarAVLRec(a., a->top, datoI, datoS, clave, varioAltura);
        if (insertado)
        {
            a->cantElementos++;
        }
    }
    string findRec(NodoAvl *raiz, int clave)
    {
        if (!raiz)
        {
            return "jugador_no_encontrado";
        }
        else
        {
            if (raiz->clave == clave)
            {
                string res = raiz->datoS + " " + to_string(raiz->datoI);
                return res;
            }
            else if (raiz->clave < clave)
            {
                return findRec(raiz->der, clave);
            }
            else
            {
                return findRec(raiz->izq, clave);
            }
        }
    }
    
    string find(Avl avl, int clave) { return findRec(avl->raiz, clave); }
    
    int rankear(Avl avl, int datoI) { return 0; }
    
    string top1(Avl avl)
    {
        string res = avl->top->datoS + " " + to_string(avl->top->datoI);
        return res;
    }
    int count(Avl avl) { return avl->cantElementos; }
};
#endif