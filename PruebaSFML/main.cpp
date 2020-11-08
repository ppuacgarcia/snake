#include <SFML/Graphics.hpp>
#include "Cola.h"

using namespace sf;

int main()
{
    Cola serpiente = Cola();

    RenderWindow * laventana;

    laventana = new RenderWindow(VideoMode(600, 600), "Creando ventana");

    laventana->setFramerateLimit(150);
    Texture * textura;
    Sprite * sprait;

    textura = new Texture;
    textura->loadFromFile("1.jpg");

    int x=50,  y = 50;
    serpiente.Agregar(textura, x, y);

    int n=1;

    while(1){

        laventana->clear(Color::White);

        serpiente.Recorrer(laventana, x, y);

        laventana->display();

        if(n%50==0){
            if(y==50 && x<500){
                x+=50;
            }else if(x==500 && y<500){
                    y+=50;
            }else if(y==500 && x>50){
                x-=50;
            }else if(x==50 && y>50){
                y-=50;
            }

        }

        if(x==200 && y==50){
            serpiente.Agregar(textura, x, y);
        }

        n++;

    }

    return 0;
}
