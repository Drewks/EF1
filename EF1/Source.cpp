#pragma once
#include "Librerias.h"
#include "Datos.h"
#include "HashTable.h"
#include "Cliente.h"
#include "Controladora.h"


void menu() {
	int op;
	do
	{
		system("CLS");
		cout << "MENU Examen Final" << endl << endl;
		cout << "1. Grafos" << endl;
		cout << "2. Clientes con tipo de plan pospago y se encuentran satisfechos con el servicio" << endl;
		cout << "3. Clientes cuya edad se encuentra entre 18 y 30 años y no se encuentran satisfechos con el servicio." << endl;
		cout << "4. Generar Lista Preorden y Mostrar" << endl;
		cout << "5. Mostrar lista" << endl;
		cout << "6. Ordenamiento avanzado por edad" << endl;
		cout << "7. Salir" << endl << endl;
		cout << "Escoger opcion: ";
		cin >> op;

		if (op < 1 || op >7)
		{
			cout << "Eliga una opcion valida.";
			_getch();
		}
		switch (op)
		{
		case 1:
			system("CLS");
			CalcularDistanciaSedes();
			_getch();
			menu();
			break;
		case 2:
			system("CLS");
			Reporte_Pospago_Satisfecho();
			_getch();
			menu();
			break;
		case 3:
			system("CLS");
			Reporte_18y30_NoSatisfecho();
			_getch();
			menu();
			break;
		case 4:
			system("CLS");

			_getch();
			menu();
			break;
		case 5:
			system("CLS");
			lecturaIndexacion();
			_getch();
			menu();
			break;
		case 6:
			system("CLS");
			Reporte_ordenamiento_Edad();
			_getch();
			menu();
			break;
		case 7:
			cout << endl << "Gracias por usar el programa!";
			break;
		}
	} while (op < 1 || op >7);
}

int main() {
	//generarDataset(cantidadPersonas);
	menu();
	_getch();
	return 0;
}