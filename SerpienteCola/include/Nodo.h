#ifndef NODO_H
#define NODO_H
#include <SFML/Graphics.hpp>

using namespace sf;

class Nodo
{
    private:
        int x;
        int y;
        Nodo* siguiente;
    public:
        Nodo(Texture* t, int x, int y);

        bool frente;
        Sprite * sprait;

        int ObtenerX();
        int ObtenerY();
        Nodo* ObtenerSiguiente();

        void ModificarX(int x);
        void ModificarY( int y);
        void ModificarSprite();
        void ModificarSiguiente(Nodo* s);

        void DibujarSprite();
};

#endif // NODO_H
