#ifndef HASHC_H
#define HASHC_H

class HashCerrado
{
public:
    // pre:
    // post: Agrega o actualiza un recurso en el cache. Si ya existe, actualiza título y tiempo.
    void put(string dominio, string path, string titulo, int tiempo);

    // pre: contains(dominio,path)
    // post: devuelve la información de un recurso específico.
    string get(string dominio, string path);

    // pre: -
    // post: elimina un recurso específico del cache.
    void remove(string dominio, string path);

    // pre:
    // post: devuelve true si el recurso esta en el cache
    bool contains(string dominio, string path);

    // pre: -
    // post: devuelve la cantidad de recursos con ese dominio
    int count_domain(string dominio);

    // pre: -
    // post: devuelve todos los paths del dominio ordenados por tiempo creciente
    string *list_domain(string dominio);

    // pre: -
    // post: elimina todos los paths del dominio
    void clear_domain(string dominio);

    // pre: -
    // post: devuelve la cantidad de recursos
    int size();

    // pre: -
    // post: vacia completamente el cache.
    void clear();
};

#endif