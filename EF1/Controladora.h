#pragma once
#include "Registro.h"
#include "Librerias.h"
#include "Grafo.h"

void CalcularDistanciaSedes();
void CalcularDistanciaSedes() {
    int V = 5, E = 6;
    vector<vector<int>> edges = { {1, 2, 7}, {2, 5, 5}, {2, 3, 8}, {1, 4, 9}, {4, 3, 10}, {3, 5, 6} };
    Grafo obj;
    int k = sedeInicial();
    int u = sedeFinal();
    int sumOfDistances = obj.SumaDeVertices(V, E, edges, k, u);
    cout << "La distancia entre la sede " << TraductorSedeInicial(k) << " y la sede " << TraductorSedeInicial(u) << " usando la ruta mas corta es de " << sumOfDistances << " kilometros.";
}

class Controladora
{
private:

public:
    Controladora();
    ~Controladora();

};

Controladora::Controladora()
{
}

Controladora::~Controladora()
{
}