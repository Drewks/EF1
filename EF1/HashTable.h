#pragma once
#include "Librerias.h"

template<typename T>
class HashTable
{
public:
    HashTable(int size) {
        this->hashSize = size;
        hashLists.resize(size);
    };
    ~HashTable() {};

    void insert(string key, T* objeto) {
        hashLists[generateHash(key)].push_back(objeto);
    }

    bool isEmpty() const {
        for (int i = 0; i < tableLists.size(); i++) {
            if (!tableLists[i].empty()) {
                return false;
            }
        }
        return true;
    }

    void mostrarInfo() {
        int pos = 0;
        int contCliente = 1;
        for (list<T>& linealList : hashLists)
        {
            for (T object : hashLists[pos]) {
                cout << "Cliente: " << contCliente << endl;
                cout << object->getValue() << endl;
                contCliente++;
            }
            pos++;
        }
    }

    size_t generateHash(string key) {
        size_t hash = 0;
        for (int i = 0; i < key.length(); i++)
        {
            hash = hash + key[i];
        }
        return hash % hashSize;
    }
private:
    vector<list<T*>> hashLists;
    int hashSize;
};