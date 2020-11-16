#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>

using namespace sf;
using namespace std;

class Nodo
{
public:
	Nodo();
	Nodo(float x, float y, string apariencia);
	float ObtenerX();
	float ObtenerY();
	float ObtenerAnteriorX();
	float ObtenerAnteriorY();
	float ObtenerVelocidad();
	Sprite* ObtenerSprite();
	Texture* ObtenerTextura();
	Sprite ObtenerApariencia();
	Nodo* ObtenerSiguiente();
	void ModificarX(float x);
	void ModificarY(float y);
	void ModificarAnteriorX(float x);
	void ModificarAnteriorY(float y);
	void ModificarVelocidad(float velocidad);
	void ModificarTextura(Texture* textura);
	void ModificarSprite(Sprite* sprite);
	void ModificarApariencia(string apariencia, float pixeles);
	void ModificarSiguiente(Nodo* siguiente);

private:
	float posicion_x;
	float posicion_y;
	float anterior_x;
	float anterior_y;
	float velocidad;
	Sprite* apariencia_s;
	Texture* apariencia_t;
	Nodo* siguiente;

};

