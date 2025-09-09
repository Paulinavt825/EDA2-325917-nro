#ifndef AVL_H
#define AVL_H

template <class T>
class List
{
public:
    //
    virtual void add(int id, const char *nombre, int puntaje) =0;

    // pre:
    // post: 
    virtual void find(int id)=0;

    // pre:
    // post: 
    virtual int rankear(int puntaje)=0;

    // pre:
    // post: 
    virtual void top1()=0;
 
    // pre:
    // post: 
    virtual void count()=0;

    // pre:
    // post: 
};

#endif