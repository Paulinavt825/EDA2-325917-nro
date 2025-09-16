#ifndef AVL_H
#define AVL_H

struct RepresentacionAVL;
//struct NodoAVL;
typedef RepresentacionAVL* Avl;


#include <string>
using namespace std;

// pre:
// post:
Avl crearAvl();

// pre:
// post:
void add(Avl a, int id, string nombre, int puntaje);

// pre:
// post:
string find(Avl a,int id);

// pre:
// post:
int rankear(Avl a, int puntaje);

// pre:
// post:
string top1(Avl a);

// pre:
// post:
int count(Avl a);

#endif