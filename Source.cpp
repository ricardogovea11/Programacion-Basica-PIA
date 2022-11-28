#include <iostream>
#include <string>
#include <windows.h>
#include <fstream>

using namespace std;

struct videojuegos {
	int id, año;
	char nombre[250], clasif[5], genero[250];
	char caract[1000], descrip[1000];
	double precio, impuesto, total;
}juego[100];

int contador = 0, opMenu, cantidad, opBuscar, buscarAño;
char buscarNombre[250], buscarClasif[5];
bool menu = true, buscador = false, encontrar = false;

void agregar();
void guardar();
void buscar();
void lista();
void modificar();
void eliminar();

ofstream archivo("PlayTheGame.txt");

void main() {

	if (!archivo) {

		cout << "No se pudo abrir el archivo";
		exit(EXIT_FAILURE);
	}

	cout << "BIENVENIDO..." << endl << endl;

	while (menu == true) {

		cout << "===PLAY THE GAME===\n";
		cout << "1. Lista de juegos\n";
		cout << "2. Buscar juego\n";
		cout << "3. Agregar juego\n";
		cout << "4. Modificar juego\n";
		cout << "5. Eliminar juego\n";
		cout << "6. Salir\n\n";

		printf("Elige una opci%cn...\t", 162);
		cin >> opMenu;

		switch (opMenu) {

		case 1:

			system("cls");
			lista();
			break;

		case 2:

			system("cls");
			buscar();
			break;

		case 3:

			system("cls");
			agregar();
			break;

		case 4:

			system("cls");
			modificar();
			break;

		case 5:

			system("cls");
			eliminar();
			break;

		case 6:

			system("cls");
			menu = false;
			printf("Est%cs saliendo...\tHASTA LUEGO.\n", 160);
			break;

		default:

			system("cls");
			printf("ERROR... Opci%cn no v%clida...\n\n", 162, 160);
			break;
		}
	}
}

void agregar() {

	cout << "===========AGREGAR JUEGO===========\n";
	printf("%cCu%cntos juegos deseas agregar?...\t", 168, 160);
	cin >> cantidad;

	if (cantidad != 0) {

		system("cls");
		cout << "Ingrese los datos correspondientes...\n\n";

		for (int i = 0; i < cantidad; i++) {

			juego[contador].id = contador + 1;
			cout << "Juego #" << juego[contador].id << endl;
			cin.ignore();

			cout << "Nombre: ";
			cin.getline(juego[contador].nombre, 250, '\n');

			printf("A%co de lanzamiento: ", 164);
			cin >> juego[contador].año;
			cin.ignore();

			printf("Clasificaci%cn: ", 162);
			cin.getline(juego[contador].clasif, 5, '\n');

			printf("Caracter%csticas:\n", 161);
			cin.getline(juego[contador].caract, 1000, '\n');

			printf("Descripci%cn:\n", 162);
			cin.getline(juego[contador].descrip, 1000, '\n');

			printf("G%cnero: ", 130);
			cin.getline(juego[contador].genero, 250, '\n');

			cout << "Precio: ";
			cin >> juego[contador].precio;

			juego[contador].impuesto = juego[contador].precio * 0.16;

			juego[contador].total = juego[contador].precio + juego[contador].impuesto;


			system("cls");
			cout << "Datos capturados:\n\n";

			cout << "#" << juego[contador].id << endl;

			cout << "Nombre: " << juego[contador].nombre << endl;

			printf("A%co de lanzamiento: ", 164);
			cout << juego[contador].año << endl;

			printf("Clasificaci%cn: ", 162);
			cout << juego[contador].clasif << endl;

			printf("Caracter%csticas:\n", 161);
			cout << juego[contador].caract << endl;

			printf("Descripci%cn:\n", 162);
			cout << juego[contador].descrip << endl;

			printf("G%cnero: ", 130);
			cout << juego[contador].genero << endl;

			cout << "Precio unitario: $" << juego[contador].precio << endl;

			cout << "IVA: $" << juego[contador].impuesto << endl;

			cout << "Precio total: $" << juego[contador].total << endl << endl;

			guardar();
		}
	}

	else {

		system("cls");
		cout << "Regresando al MENU...\n\n";
	}
}

void guardar() {

	archivo << "#" << juego[contador].id << endl;
	archivo << juego[contador].nombre << endl;
	archivo << juego[contador].año << endl;
	archivo << juego[contador].clasif << endl;
	archivo << juego[contador].caract << endl;
	archivo << juego[contador].descrip << endl;
	archivo << juego[contador].genero << endl;
	archivo << "$" << juego[contador].precio << endl;
	archivo << "$" << juego[contador].impuesto << endl;
	archivo << "$" << juego[contador].total << endl << endl;
	contador++;
}

void lista() {

	cout << "=====LISTA DE JUEGOS=====" << endl << endl;

	for (int j = 0; j < contador; j++) {

		cout << "#" << juego[j].id << endl;

		cout << "Nombre: " << juego[j].nombre << endl;

		printf("A%co de lanzamiento: ", 164);
		cout << juego[j].año << endl;

		printf("Clasificaci%cn: ", 162);
		cout << juego[j].clasif << endl;

		printf("Caracter%csticas:\n", 161);
		cout << juego[j].caract << endl;

		printf("Descripci%cn:\n", 162);
		cout << juego[j].descrip << endl;

		printf("G%cnero: ", 130);
		cout << juego[j].genero << endl;

		cout << "Precio unitario: $" << juego[j].precio << endl;

		cout << "IVA: $" << juego[j].impuesto << endl;

		cout << "Precio total: $" << juego[j].total << endl << endl;
	}
}

void buscar() {

	buscador = true;

	while (buscador == true) {

		cout << "========BUSCADOR========\n";
		printf("%cQu%c deseas buscar?...\n", 168, 130);
		cout << "1. Nombre\n";
		printf("2. A%co\n", 164);
		printf("3. Clasificaci%cn\n", 162);
		cout << "4. Regresar\n\n";

		printf("Elige una opci%cn...\t", 162);
		cin >> opBuscar;

		switch (opBuscar) {

		case 2:

			system("cls");
			printf("Ingresa el a%co...\t", 164);
			cin >> buscarAño;

			for (int b = 0; b < contador; b++) {

				if (buscarAño == juego[b].año) {

					system("cls");
					cout << "#" << juego[b].id << endl;

					cout << "Nombre: " << juego[b].nombre << endl;

					printf("A%co de lanzamiento: ", 164);
					cout << juego[b].año << endl;

					printf("Clasificaci%cn: ", 162);
					cout << juego[b].clasif << endl;

					printf("Caracter%csticas:\n", 161);
					cout << juego[b].caract << endl;

					printf("Descripci%cn:\n", 162);
					cout << juego[b].descrip << endl;

					printf("G%cnero: ", 130);
					cout << juego[b].genero << endl;

					cout << "Precio unitario: $" << juego[b].precio << endl;

					cout << "IVA: $" << juego[b].impuesto << endl;

					cout << "Precio total: $" << juego[b].total << endl << endl;
					encontrar = true;
				}
			}

			if (encontrar == false) {

				system("cls");
				printf("No se encontr%c el juego...\n\n", 162);
			}

			break;

		case 4:

			system("cls");
			buscador = false;
			cout << "Regresando al MENU...\n\n";
			break;

		default:

			system("cls");
			printf("ERROR... Opci%cn no v%clida...\n\n", 162, 160);
			break;
		}
	}
}

void modificar() {


}

void eliminar() {


}