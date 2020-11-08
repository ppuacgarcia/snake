#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <Juego.h>

using namespace sf;

int main(int argc, char* args[])
{
    //Vector2i dimension;
    //dimension.x = 800;
    //dimension.y = 600;

    Juego * partida1;
    partida1 = new Juego({800,600},"Snake");

    return 0;
}
