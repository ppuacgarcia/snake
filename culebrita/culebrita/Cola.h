#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include "Nodo.h"

using namespace sf;
using namespace std;

class Cola
{
private:
	Nodo* frente;
	Nodo* fondo;
	int tamano;
	float anterior_x;
	float anterior_y;
	float aumento_x;
	float aumento_y;
	float pixeles;
	float velocidad;
	string apariencia;
	Event* evento1;
	RenderWindow* ventana;
	bool perdiste;

public:
	Cola();
	Cola(RenderWindow* ventana, float pixeles, string apariencia, float velocidad);
	int ObtenerTamano();
	Nodo* ObtenerFrente();
	void ModificarApariencia(string apariencia);
	void Insertar(float x, float y);
	void Recorrer();
	void ProcesarEventos();
	void gameloop();
	void Perdida();
};

