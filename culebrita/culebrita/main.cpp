#include <SFML/Graphics.hpp>
#include <iostream>
#include "Cola.h"

using namespace sf;
using namespace std;

int main(int argc, char* args[])
{
	RenderWindow* ventana1 = new RenderWindow(VideoMode(800, 600), "prueba");
	ventana1->setFramerateLimit(1000);
	Cola serpiente = Cola(ventana1, 80, "corrin.png",1);
	serpiente.Insertar(400, 300);
	serpiente.Insertar(2, 2);
	serpiente.Insertar(2, 2);
	serpiente.gameloop();

    return 0;
}