#pragma once
#include "Librerias.h"

class Grafo
{
public:
    int SumaDeVertices(int n, int m, vector<vector<int>>& edges, int k, int u)
    {
        vector<vector<pair<int, int>>> adj(n + 1);
        for (auto it : edges)
        {
            adj[it[0]].push_back({ it[1], it[2] });
            adj[it[1]].push_back({ it[0], it[2] });
        }

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        vector<int> distanciaT(n + 1, INT_MAX), padre(n + 1);
        for (int i = 1; i <= n; i++)
            padre[i] = i;

        distanciaT[k] = 0;
        pq.push({ 0, k });

        while (!pq.empty())
        {
            auto It = pq.top();
            pq.pop();
            int nodo = It.second;
            int distancia = It.first;

            if (distancia > distanciaT[nodo])
                continue;

            if (nodo == u)
                return distancia;

            for (auto It : adj[nodo])
            {
                int adjnodo = It.first;
                int edW = It.second;

                if (distancia + edW < distanciaT[adjnodo])
                {
                    distanciaT[adjnodo] = distancia + edW;
                    pq.push({ distanciaT[adjnodo], adjnodo });
                    padre[adjnodo] = nodo;
                }
            }
        }
        return -1;
    }
};