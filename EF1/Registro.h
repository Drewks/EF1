#pragma once
#include "Librerias.h"
int sedeInicial();
int sedeFinal();
char TraductorSedeInicial(int a);
int sedeInicial() {
    int k;
    do
    {
        clearScreen;
        cout << "Sedes Movistar: " << endl;
        cout << "1.- Sede A" << endl;
        cout << "2.- Sede B" << endl;
        cout << "3.- Sede C" << endl;
        cout << "4.- Sede D" << endl;
        cout << "5.- Sede E" << endl;
        cout << "Ingrese la sede inicial: ";
        cin >> k;
        if (!(k >= 1 && k <= 5))
        {
            ClearKeyboard();
            cout << "La posicion no es valida";
        }
    } while (!(k >= 1 && k <= 5));
    return k;
}
int sedeFinal() {
    int u;
    do
    {
        clearScreen;
        cout << "Sedes Movistar: " << endl;
        cout << "1.- Sede A" << endl;
        cout << "2.- Sede B" << endl;
        cout << "3.- Sede C" << endl;
        cout << "4.- Sede D" << endl;
        cout << "5.- Sede E" << endl;
        cout << "Ingrese la sede final: ";
        cin >> u;
        if (!(u >= 1 && u <= 5))
        {
            ClearKeyboard();
            cout << "La posicion no es valida";
        }
    } while (!(u >= 1 && u <= 5));
    return u;
}
char TraductorSedeInicial(int a) {
    char sede = NULL;
    switch (a)
    {
    case 1:
        sede = 'A';
        break;
    case 2:
        sede = 'B';
        break;
    case 3:
        sede = 'C';
        break;
    case 4:
        sede = 'D';
        break;
    case 5:
        sede = 'E';
        break;
    default:
        break;
    }
    return sede;
}