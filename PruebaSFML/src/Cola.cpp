#include "Cola.h"
#include "Nodo.h"
#include <SFML/Graphics.hpp>

using namespace sf;

Cola::Cola()
{
    this->tamanio = 0;
    this->maxx = -1;
    this->frente = NULL;
    this->fondo = NULL;
    this->posx=0;
    this->posy=0;
}

void Cola::Agregar(Texture* t,int x, int y){
    if(this->maxx > this->tamanio || this->maxx == -1){
        Nodo* nuevo = new Nodo(t,  x, y);
        nuevo->ModificarX(x);
        nuevo->ModificarY(y);
        nuevo->ModificarSprite();
        if(this->frente == NULL && this->fondo == NULL){
            this->frente = nuevo;
            this->fondo = nuevo;
        }else{
            Nodo* aux = this->fondo;
            this->fondo = nuevo;
            aux->ModificarSiguiente(nuevo);
        }
        this->tamanio++;
    }else{
        throw "DESBORDAMIENTO DE COLA";
    }
}

int Cola::ObtenerTamanio(){
    return this->tamanio;
}

void Cola::Recorrer(RenderWindow * &laventana, int x, int y){
    Nodo* aux = this->frente;
    while(aux !=NULL){
            if(aux==frente){
            posx=aux->ObtenerX();
            posy=aux->ObtenerY();
            aux->ModificarX(x);
            aux->ModificarY(y);
            aux->ModificarSprite();
            }else{

            x=posx;
            y=posy;

            posx=aux->ObtenerX();
            posy=aux->ObtenerY();

            aux->ModificarX(x);
            aux->ModificarY(y);
            aux->ModificarSprite();
            }

            laventana->draw(* aux->sprait);
            aux = aux->ObtenerSiguiente();
    }
}

void Cola::Eliminar(){
        if(this->frente == this->fondo){
            //Pierde
        }else{
            Nodo* aux = this->frente;
            this->frente = this->frente->ObtenerSiguiente();
            aux->ModificarSiguiente(NULL);
            this->tamanio--;
        }
    }

