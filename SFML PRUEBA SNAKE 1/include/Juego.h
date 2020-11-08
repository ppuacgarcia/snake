#pragma once
#include <SFML/Graphics.hpp>
#include <string>
#include <windows.h>
#include<stdlib.h>
#include<time.h>

using namespace sf;
using namespace std;

class Juego
{
    public:
        Juego(Vector2i dimension, std::string titulo);
        void dibujar();
        void gameLoop();
        void procesar_eventos();
        void procesar_mouse();
        void procesar_colisiones();

    private:
        RenderWindow * ventana1;
        int fps;
        Texture * textura1;
        Texture * Fondo;
        Texture * textura3;
        Sprite * sprite1;
        Sprite * sprite2;
        //FRUTAS
        Texture * TexturaManzana;
        Texture * TexturaPera;
        Texture * TexturaBanano;
        Texture * TexturaPinia;
        Texture * TexturaFresa;

        Sprite * Manzana;
        Sprite * Pera;
        Sprite * Banano;
        Sprite * Pinia;
        Sprite * Fresa;
        //OBSTACULOS
        Texture * TexturaLadrillo;
        Texture * TexturaColumna;
        Texture * TexturaPared;

        Sprite * Ladrillo;
        Sprite * Columna;
        Sprite * Pared;

        //EVENTOS
        Event * evento1;
        string Direccion = "DERECHA";

        Vector2i posicion_mouse;
};


