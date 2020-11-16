#include "Nodo.h"

Nodo::Nodo() {
	this->nombre = 0;
	this->siguiente = NULL;
}

Nodo::Nodo(int nombre, Nodo* siguiente) {
	this->nombre = nombre;
	this->siguiente = siguiente;
}

int Nodo::ObtenerNombre() {
	return this->nombre;
}

Nodo* Nodo::ObtenerSiguiente() {
	return this->siguiente;
}

void Nodo::ModificarNombre(int nombre) {
	this->nombre = nombre;
}

void Nodo::ModificarSiguiente(Nodo* siguiente) {
	this->siguiente = siguiente;
}