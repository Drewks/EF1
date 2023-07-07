#pragma once
#include "Librerias.h"

template <typename T>
class NodoArbol
{
public:
    NodoArbol() {
        l = NULL;
        r = NULL;
    };
    ~NodoArbol() {};

    void _preOrden(rama* ramaTMP, list<InformacionPersona>* listaPersonas)
    {
        ImprimirInformacionPersona(&ramaTMP->dato);
        listaPersonas->push_back(ramaTMP->dato);
        if (ramaTMP->left != nullptr) _preOrden(ramaTMP->left, listaPersonas);
        if (ramaTMP->right != nullptr) _preOrden(ramaTMP->right, listaPersonas);
    }

    void insertNode(NodoArbol& tree, T object) {
        if (tree == NULL)
        {
            NodoArbol* newNode = createNode(object);
            tree = newNode;
        }
        else
        {
            if (object->getValue() > tree->value->getValue())
            {
                insertNode(tree->r, object);
            }
            else
            {
                insertNode(tree->l, object);
            }
        }
    }

    void recorrerArbol(NodoArbol* tree) {
        if (tree)
        {
            recorrerArbol(tree->l);
            cout << tree->value->getValue() << endl;
            recorrerArbol(tree->r);
        }
    }

    NodoArbol* createNode(T* object) {
        NodoArbol* aux = new NodoArbol();
        aux->value = object;
        return aux;
    }

private:
    NodoArbol* l;
    NodoArbol* r;
    T* value;
};
