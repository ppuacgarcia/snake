#pragma once
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <cstdlib>
#include <iostream>
#include "Nodo.h"
using namespace sf;
using namespace std;

class Juego
{
public:
	Juego(int tamanio_x,int tamanio_y, string titulo);
	void Mostrar();
	void Loop();
	void ProcesarEventos();
	void ProcesarMouse();
	Sprite * FrutasRandom();
	void Avanzar(int velocidad);
	void Choque();
	void Perdiste();
	void Agregar(int puntaje);
	string Recorrer();
	//INICIO
	RenderWindow* window;

private:
	Nodo* frente;
	Nodo* fondo;
	double velocidad;
	int tamaniox;
	int tamanioy;
	//fondo inicial
	Texture* fondoinicial;
	Sprite* sprfi;
	//Fondo de puntajes
	Texture* fondopuntajes;
	Sprite* sprpu;
	//Fondo de niveles
	Texture* fondoniveles;
	Sprite* sprni;
	//fondo de jugando
	Texture* tablero;
	Sprite* sprta;
	//eventos
	Event* evento1;
	Vector2i posicion_mouse;
    int lugar=0;
	//Frutas
	Texture* TexturaManzana;
	Texture* TexturaPera;
	Texture* TexturaBanano;
	Texture* TexturaPinia;
	Texture* TexturaFresa;

	Sprite* Manzana;
	Sprite* Pera;
	Sprite* Banano;
	Sprite* Pinia;
	Sprite* Fresa;
	int porcentaje;
	Vector2f posicionfrutas;
	Vector2f tamaniof;
	int posicion_frutasx;
	int posicion_frutasy;
	int tipo_de_fruta;
	//Obstaculos
	Texture* TexturaColumna;
	Texture* TexturaPared;
	Texture* TexturaLadrillo;
	Sprite* Ladrillo;
	Sprite* Columna;
	Sprite* Pared;
	Vector2f posicionObstaculos;
	//Texto Dinamico 
	//niveles
	Font* fuente1;
	Text* txt_puntaje;
	Text* txt_velocidad;
	Vector2f posicion_puntaje;
	Vector2f posicion_velocidad;
	Clock* reloj1;
	Time* tiempo;
	double incrementar = 1;
	//Puntajes
	int puntaje;
	Text* txt_puntajes;
	//Serpiente 
	Texture* textura_serpiente;
	Sprite* serpiente[200];
	Vector2f posicions;
	Vector2f posicionsans;
	int aid=2;
	bool colision;
	
};

