#include "Nodo.h"
#include <SFML/Graphics.hpp>

using namespace sf;

Nodo::Nodo(Texture* t, int x, int y)
{
    this->x=x;
    this->y=y;
    this->sprait = new Sprite(*t);
    this->siguiente= NULL ;
}

int Nodo::ObtenerX(){
    return this->x;
}

int Nodo::ObtenerY(){
    return this->y;
}

Nodo* Nodo::ObtenerSiguiente(){
    return this->siguiente;
}

void Nodo::ModificarX(int x){
    this->x=x;
}

void Nodo::ModificarY(int y){
    this->y=y;
}

void Nodo::ModificarSprite(){
    this->sprait->setScale(0.1, 0.1);
    this->sprait->setPosition(this->x, this->y);
}

void Nodo::ModificarSiguiente(Nodo* s){
    this->siguiente = s;
}

