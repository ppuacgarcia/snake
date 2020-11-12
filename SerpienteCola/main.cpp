#include <SFML/Graphics.hpp>
#include "Cola.h"
#include <string>


using namespace sf;

Cola serpiente = Cola();

void procesar_eventos(RenderWindow * &lventana1);
void ActivarSerpiente(RenderWindow * &laventana);
std::string Direccion  = "DERECHA";

void procesar_eventos(RenderWindow * &ventana1){
    Event * evento1;
    evento1 = new Event;
    while(ventana1->pollEvent(*evento1))
    {
        switch(evento1->type)
        {
        case Event::Closed:
            ventana1->close();
            exit(1);
            break;

        case Event::KeyPressed:
            if(Keyboard::isKeyPressed(Keyboard::Up))
            {
                if(Direccion != "ABAJO")
                {

                Direccion = "ARRIBA";
                }
            }
            else if(Keyboard::isKeyPressed(Keyboard::Down))
            {
                if(Direccion != "ARRIBA")
                {

                Direccion = "ABAJO";
                }
            }
            else if(Keyboard::isKeyPressed(Keyboard::Left))
            {
                if(Direccion != "DERECHA")
                {

                Direccion = "IZQUIERDA";
                }
            }
            else if(Keyboard::isKeyPressed(Keyboard::Right))
            {
                if(Direccion != "IZQUIERDA")
                {

                Direccion = "DERECHA";
                }
            }
        break;

        }
    }
}

void ActivarSerpiente(RenderWindow * &laventana){
     Texture * textura;
    Sprite * sprait;

    textura = new Texture;
    textura->loadFromFile("Nodo.jpg");

    int x=60,  y = 60;
    serpiente.Agregar(textura, x, y);

    int n=1;

    while(1){

        laventana->clear(Color::White);

        serpiente.Recorrer(laventana, x, y);

        laventana->display();

        procesar_eventos(laventana);

        if(n%20==0){
            if(Direccion=="DERECHA"){
                 if(x>40 && x<580)   x+=20;
            }else if(Direccion=="ABAJO"){
                    if(y>40 && y<580) y+=20;
            }else if(Direccion=="IZQUIERDA"){
                if(x>40 &&x<580) x-=20;
            }else if(Direccion == "ARRIBA"){
                if(y>40 && y<580) y-=20;
            }

        }

        if(n%200==0){
            serpiente.Agregar(textura, x, y);
        }

        n++;

    }
}

int main()
{

    RenderWindow * laventana;

    laventana = new RenderWindow(VideoMode(600, 600), "Creando ventana");

    laventana->setFramerateLimit(150);

   ActivarSerpiente(laventana);

    return 0;
}
