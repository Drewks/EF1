#pragma once
#include "Librerias.h"

int cantidadPersonas = 800;
ifstream archivo;
char delimitador = ',';

struct Persona
{
    int dni, edad, satisfaccion, celular, tipoPlan;
    char sexo;
};

int generarNumeroAleatorio(int min, int max) {
    return min + rand() % (max - min + 1);
}

char generarSexoAleatorio() {
    return (rand() % 2 == 0) ? 'M' : 'F';
}

bool generarValorBooleanoAleatorio() {
    return (rand() % 2 == 0);
}

int generarDniAleatorio() {
    int DNI = 0;
    for (int i = 0; i < 8; i++)
    {
        if (i == 0) DNI = DNI * 10 + rand() % 9 + 1;
        else DNI = DNI * 10 + rand() % 10;
    }
    return DNI;
}

int generarCelularAleatorio() {
    int Celular = 0;
    for (int i = 0; i < 9; i++)
    {
        if (i == 0)
            Celular = 9;
        else
            Celular = Celular * 10 + rand() % 10;
    }
    return Celular;
}

void generarDataset(int cantidadPersonas) {
    ofstream archivo("dataset_personas.csv");
    archivo << "DNI,Edad,Sexo,Satisfaccion,Celular,TipoPlan" << endl;

    srand(time(nullptr));

    for (int i = 0; i < cantidadPersonas; i++) {
        int dni = generarDniAleatorio();
        int edad = generarNumeroAleatorio(18, 80);
        char sexo = generarSexoAleatorio();
        bool satisfaccion = generarValorBooleanoAleatorio();
        int celular = generarCelularAleatorio();
        bool tipoPlan = generarValorBooleanoAleatorio();

        archivo << dni << "," << edad << "," << sexo << "," << satisfaccion << "," << celular << "," << tipoPlan << endl;
    }

    archivo.close();
}

void lecturaIndexacion()
{
    archivo.open("dataset_personas.csv", ios::in);
    if (!archivo.is_open())
    {
        cout << "Error: No se pudo abrir el archivo!" << endl;
        exit(1);
    }
    //Variables del dataSet
    string dni, edad, satisfaccion, celular, tipoPlan;
    string sexo;
    string linea;
    //Saltea la primera linea
    getline(archivo, linea);
    while (getline(archivo, linea))
    {
        stringstream stream(linea);
        getline(stream, dni, delimitador);
        getline(stream, edad, delimitador);
        getline(stream, sexo, delimitador);
        getline(stream, satisfaccion, delimitador);
        getline(stream, celular, delimitador);
        getline(stream, tipoPlan, delimitador);

        cout << "========================================================================================" << endl;
        cout << "Dni : " << dni;
        cout << ", Edad : " << edad;
        cout << ", Sexo : " << sexo;
        cout << ", Satisfaccion : " << satisfaccion;
        cout << ", Celular : " << celular;
        cout << ", TipoPlan : " << tipoPlan;
        cout << endl;

    }
    archivo.close();
}
void Reporte_Pospago_Satisfecho() {
    archivo.open("dataset_personas.csv", ios::in);
    if (!archivo.is_open())
    {
        cout << "Error: No se pudo abrir el archivo!" << endl;
        exit(1);
    }

    string dni, edad, satisfaccion, celular, tipoPlan;
    string sexo;
    string linea;
    string buscar;
    string sa;
    string ti;

    buscar = "1";
    bool existe = false;


    getline(archivo, linea);
    while (getline(archivo, linea))
    {
        stringstream stream(linea);

        getline(stream, dni, delimitador);
        getline(stream, edad, delimitador);
        getline(stream, sexo, delimitador);
        getline(stream, satisfaccion, delimitador);
        getline(stream, celular, delimitador);
        getline(stream, tipoPlan, delimitador);

        if (buscar.compare(satisfaccion) == 0 && buscar.compare(tipoPlan) == 0) {
            existe = true;
            if (satisfaccion == "1")
            {
                sa = "Satisfecho";
            }
            else
            {
                sa = "No satisfecho";
            }
            if (tipoPlan == "1")
            {
                ti = "Pospago";
            }
            else
            {
                ti = "Prepago";
            }
            cout << "Dni: " << dni << endl;
            cout << "Satisfaccion: " << sa << endl;
            cout << "Tipo de plan: " << ti << endl << endl;

        }
    }
    archivo.close();
}
void Reporte_18y30_NoSatisfecho() {
    archivo.open("dataset_personas.csv", ios::in);
    if (!archivo.is_open())
    {
        cout << "Error: No se pudo abrir el archivo!" << endl;
        exit(1);
    }

    string dni, edad, satisfaccion, celular, tipoPlan;
    string sexo;
    string linea;
    string satisfaccionE;
    string sa;

    satisfaccionE = "0";
    bool existe = false;

    getline(archivo, linea);
    while (getline(archivo, linea))
    {
        stringstream stream(linea);

        getline(stream, dni, delimitador);
        getline(stream, edad, delimitador);
        getline(stream, sexo, delimitador);
        getline(stream, satisfaccion, delimitador);
        getline(stream, celular, delimitador);
        getline(stream, tipoPlan, delimitador);

        int edad1 = stoi(edad);

        if ((satisfaccionE.compare(satisfaccion) == 0) && (edad1 >= 18 && edad1 <= 30)) {
            existe = true;
            if (satisfaccion == "1")
            {
                sa = "Satisfecho";
            }
            else
            {
                sa = "No satisfecho";
            }
            cout << "Dni: " << dni << endl;
            cout << "Edad: " << edad << endl;
            cout << "Satisfaccion: " << sa << endl << endl;

        }
    }
    archivo.close();
}
int Partition(vector<vector<string>>& datos, int low, int high) {
    vector<string> pivot = datos[high];
    int i = low - 1;

    for (int j = low; j <= high - 1; j++) {
        if (stoi(datos[j][1]) <= stoi(pivot[1])) {
            i++;
            swap(datos[i], datos[j]);
        }
    }
    swap(datos[i + 1], datos[high]);
    return (i + 1);
}

void QuickSort(vector<vector<string>>& datos, int low, int high) {
    if (low < high) {
        int pi = Partition(datos, low, high);

        // Ordenar las dos particiones
        QuickSort(datos, low, pi - 1);
        QuickSort(datos, pi + 1, high);
    }
}
void Reporte_ordenamiento_Edad() {
    archivo.open("dataset_personas.csv", ios::in);
    if (!archivo.is_open())
    {
        cout << "Error: No se pudo abrir el archivo!" << endl;
        exit(1);
    }

    string dni, edad, satisfaccion, celular, tipoPlan;
    string sexo;
    string linea;
    vector<vector<string>> datos;

    getline(archivo, linea);
    while (getline(archivo, linea))
    {
        stringstream stream(linea);

        getline(stream, dni, delimitador);
        getline(stream, edad, delimitador);
        getline(stream, sexo, delimitador);
        getline(stream, satisfaccion, delimitador);
        getline(stream, celular, delimitador);
        getline(stream, tipoPlan, delimitador);

        vector<string> fila = { dni, edad, sexo, satisfaccion, celular, tipoPlan };
        datos.push_back(fila);

    }
    archivo.close();
    QuickSort(datos, 0, datos.size() - 1);

    // Imprimir los datos ordenados
    for (const vector<string>& fila : datos) {
        cout << "========================================================================================" << endl;
        cout << "Dni : " << fila[0];
        cout << ", Edad : " << fila[1];
        cout << ", Sexo : " << fila[2];
        cout << ", Satisfaccion : " << fila[3];
        cout << ", Celular : " << fila[4];
        cout << ", TipoPlan : " << fila[5];
        cout << endl;
    }
}