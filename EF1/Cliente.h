#pragma once
#include "Librerias.h"

class Cliente
{
public:

    int edad, satisfaccion, celular, tipoPlan, contador;
    string dni;
    char sexo;


public:
    Cliente(string dni, int edad, char sexo, int satisfaccion, int celular, int tipoPlan)
    {
        this->edad = edad;
        this->satisfaccion = satisfaccion;
        this->celular = celular;
        this->contador = 0;
        this->tipoPlan = tipoPlan;
        this->sexo = sexo;
    };

    Cliente()
    {
        this->dni = "";
        this->edad = 0;
        this->satisfaccion = 0;
        this->celular = 0;
        this->tipoPlan = 0;
        this->sexo = NULL;
    }

    ~Cliente() {};

    void setDni(string dni) { this->dni = dni; }
    void setEdad(int edad) { this->edad = edad; }
    void setSatisfaccion(int satisfaccion) { this->satisfaccion = satisfaccion; }
    void setCelular(int celular) { this->celular = celular; }
    void setTipoPlan(int tipoPlan) { this->tipoPlan = tipoPlan; }
    void setSexo(char sexo) { this->sexo = sexo; }

    void typeDni();
    void typeEdad();
    void typeSatisfaccion();
    void typeCelular();
    void typeTipoPlan();
    void typeSexo();

    string getDni() { return this->dni; }
    int getEdad() { return this->edad; }
    int getSatisfaccion() { return this->satisfaccion; }
    int getCelular() { return this->celular; }
    int getTipoPlan() { return this->tipoPlan; }
    char getSexo() { return this->sexo; }
    int getContador() { return this->contador; }

    void typeCliente();
    void informacionCliente();
};
void Cliente::typeDni() {
    string* DniC = new string;
    bool* val = new bool;
    do
    {
        cout << "Ingrese el DNI del pasajero: ";
        cin >> *DniC;
        *val = (*DniC).size() == 8;
        if (*val)
        {
            for (int i = 0; i < (*DniC).size(); i++)
            {
                if (!(int((*DniC)[i]) >= 48 && int((*DniC)[i]) <= 57))
                {
                    *val = 0;
                }
            }
        }
        if (!(*val))
        {
            ClearKeyboard();
            cout << "DNI Incorrecto.\n";
        }
    } while (!(*val));
    this->dni = *DniC;
}
void Cliente::typeEdad()
{
    int edadC;

    do
    {
        cout << "Edad: ";
        cin >> edadC;
        if (!(edadC >= 1 && edadC <= 120))
        {
            ClearKeyboard();
            cout << "La edad no es valida";
        }
    } while (!(edadC >= 18 && edadC <= 80));

    this->edad = edadC;
}

void Cliente::typeCelular() {
    int CelularC;
    do
    {
        cout << "Celular: ";
        cin >> CelularC;
        if (!(CelularC >= 900000000 && CelularC <= 999999999))
        {
            ClearKeyboard();
            cout << "El celular no es valido";
        }
    } while (!(CelularC >= 900000000 && CelularC <= 999999999));
    this->celular = CelularC;
}
void Cliente::typeSatisfaccion() {
    int SatisfaccionC;
    do
    {
        cout << "Satisfaccion: ";
        cin >> SatisfaccionC;
        if (!(SatisfaccionC >= 1 && SatisfaccionC <= 2))
        {
            ClearKeyboard();
            cout << "Lo ingresado no es valido";
        }
    } while (!(SatisfaccionC >= 1 && SatisfaccionC <= 2));
    this->satisfaccion = SatisfaccionC;
}
void Cliente::typeTipoPlan() {
    int TipoplanC;
    do
    {
        cout << "TipoPlan: ";
        cin >> TipoplanC;
        if (!(TipoplanC >= 1 && TipoplanC <= 2))
        {
            ClearKeyboard();
            cout << "Lo ingresado no es valido";
        }
    } while (!(TipoplanC >= 1 && TipoplanC <= 2));
    this->tipoPlan = TipoplanC;
}

void Cliente::typeSexo() {
    char SexoC;
    do
    {
        cout << "Sexo: ";
        cin >> SexoC;
        if (SexoC != 'F' && SexoC != 'M')
        {
            ClearKeyboard();
            cout << "Lo ingresado no es valido";
        }
    } while (SexoC != 'F' && SexoC != 'M');
    this->sexo = SexoC;
}
void Cliente::typeCliente()
{
    clearScreen;
    cout << "Ingrese los datos de la Cliente: \n";
    ClearKeyboard();
    typeDni();
    ClearKeyboard();
    typeEdad();
    ClearKeyboard();
    typeSexo();
    ClearKeyboard();
    typeSatisfaccion();
    ClearKeyboard();
    typeCelular();
    ClearKeyboard();
    typeTipoPlan();

    clearScreen;
    informacionCliente();
}

void Cliente::informacionCliente()
{
    clearScreen;
    cout << "Los datos de la Cliente son: \n";
    cout << "Dni: " << this->dni << "\n";
    cout << "Edad: " << this->edad << "\n";
    cout << "Sexo: " << this->sexo << "\n";
    cout << "Satisfaccion: " << this->satisfaccion << "\n";
    cout << "Celular: " << this->celular << "\n";
    cout << "Tipo de plan: " << this->tipoPlan << "\n";
}

