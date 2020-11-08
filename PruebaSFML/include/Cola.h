#ifndef COLA_H
#define COLA_H
#include "Nodo.h"
#include <SFML/Graphics.hpp>

using namespace sf;


class Cola
{
   private:
       int tamanio;
       int maxx;
       Nodo* frente;
       Nodo* fondo;
       int posx;
       int posy;
   public:
       Cola();
       void Agregar(Texture* t,int x, int y);
       void Eliminar();
       void Recorrer(RenderWindow * &laventana, int x, int y);
       int ObtenerTamanio();

};

#endif // COLA_H
