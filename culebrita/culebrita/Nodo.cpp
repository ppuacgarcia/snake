#include "Nodo.h"

Nodo::Nodo()
{
	this->posicion_x = 0;
	this->posicion_y = 0;
	this->anterior_x = 0;
	this->anterior_y = 0;
	this->siguiente = nullptr;
	this->velocidad = 0;
}

Nodo::Nodo(float x, float y, string apariencia)
{
	this->apariencia_t = new Texture;
	this->apariencia_s = new Sprite;
	this->apariencia_t->loadFromFile(apariencia);
	this->apariencia_s->setTexture(*this->apariencia_t);
	this->posicion_x = x;
	this->posicion_y = y;
	this->anterior_x = this->ObtenerSiguiente()->ObtenerX();
	this->anterior_y = this->ObtenerSiguiente()->ObtenerY();
	this->siguiente = nullptr;
	this->velocidad = 1;
}

float Nodo::ObtenerX()
{
	return this->posicion_x;
}

float Nodo::ObtenerY()
{
	return this->posicion_y;
}

float Nodo::ObtenerAnteriorX()
{
	return this->anterior_x;
}

float Nodo::ObtenerAnteriorY()
{
	return this->anterior_y;
}

float Nodo::ObtenerVelocidad()
{
	return this->velocidad;
}

Sprite* Nodo::ObtenerSprite()
{
	return this->apariencia_s;
}

Texture* Nodo::ObtenerTextura()
{
	return this->apariencia_t;
}

Sprite Nodo::ObtenerApariencia()
{
	return *(this->apariencia_s);
}

Nodo* Nodo::ObtenerSiguiente()
{
	return this->siguiente;
}

void Nodo::ModificarX(float x)
{	
	this->posicion_x = x;
}

void Nodo::ModificarY(float y)
{
	this->posicion_y = y;
}

void Nodo::ModificarAnteriorX(float x)
{
	this->anterior_x = x;
}

void Nodo::ModificarAnteriorY(float y)
{
	this->anterior_y = y;
}

void Nodo::ModificarVelocidad(float velocidad)
{
	this->velocidad = velocidad;
}

void Nodo::ModificarTextura(Texture* textura)
{
	this->apariencia_t = textura;
}

void Nodo::ModificarSprite(Sprite* sprite)
{
	this->apariencia_s = sprite;
}

void Nodo::ModificarSiguiente(Nodo* siguiente)
{
	this->siguiente = siguiente;
}

void Nodo::ModificarApariencia(string apariencia, float pixeles)
{
	this->apariencia_t = new Texture;
	this->apariencia_s = new Sprite;
	this->apariencia_t->loadFromFile(apariencia);
	this->apariencia_s->setTexture(*this->apariencia_t);
	this->apariencia_s->setScale((pixeles / this->apariencia_s->getTexture()->getSize().x), (pixeles / this->apariencia_s->getTexture()->getSize().y));
	this->apariencia_s->setOrigin(this->apariencia_s->getTexture()->getSize().x / 2, this->apariencia_s->getTexture()->getSize().y / 2);
}

