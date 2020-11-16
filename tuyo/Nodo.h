#pragma once
#include <string>
using namespace std;
class Nodo
{
private:
	int nombre;
	Nodo* siguiente;
public:
	Nodo();
	Nodo(int nombre, Nodo* siguiente);
	int ObtenerNombre();
	Nodo* ObtenerSiguiente();
	void ModificarNombre(int nombre);
	void ModificarSiguiente(Nodo* siguiente);
};


