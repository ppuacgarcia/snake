#include "Juego.h"

Juego::Juego(Vector2i dimension,std::string titulo)
{
    fps = 60;
    ventana1 = new RenderWindow(VideoMode(dimension.x, dimension.y),titulo);

    ventana1->setFramerateLimit(fps);

    //TEXTURAS DE ARCHIVOS
    textura1 = new Texture;
    textura1->loadFromFile("Serpiente 1.png");

    Fondo = new Texture;
    Fondo->loadFromFile("Escenario de Prueba 1.png");

    TexturaManzana = new Texture;
    TexturaManzana->loadFromFile("Manzana.png");
    TexturaPera = new Texture;
    TexturaPera->loadFromFile("Pera.png");
    TexturaBanano = new Texture;
    TexturaBanano->loadFromFile("Banana.png");
    TexturaPinia = new Texture;
    TexturaPinia->loadFromFile("Piña.png");
    TexturaFresa = new Texture;
    TexturaFresa->loadFromFile("Fresa.png");

    TexturaLadrillo = new Texture;
    TexturaLadrillo->loadFromFile("Ladrillo.png");
    TexturaColumna = new Texture;
    TexturaColumna->loadFromFile("Columna.png");
    TexturaPared = new Texture;
    TexturaPared->loadFromFile("Pared.png");


    //SPRITES DE TEXTURAS
    sprite1 = new Sprite;
    sprite1->setTexture(*Fondo);//SPRITE 1 ES FONDO

    sprite2 = new Sprite(*textura1);//SPRITE 2 ES LA SERPIENTE

    Manzana = new Sprite(*TexturaManzana);
    Pera = new Sprite(*TexturaPera);
    Fresa = new Sprite(*TexturaFresa);
    Pinia = new Sprite(*TexturaPinia);
    Banano = new Sprite(*TexturaBanano);

    Ladrillo = new Sprite(*TexturaLadrillo);
    Columna = new Sprite(*TexturaColumna);
    Pared = new Sprite(*TexturaPared);

    //POSICION
    sprite2->setPosition(400, 300);

    sprite2->setOrigin((float)(sprite2->getTexture()->getSize().x / 2), (float)(sprite2->getTexture()->getSize().y / 2));//PARA ROTAR DESDE EL CENTRO DE LA IMAGEN
    //EL FLOAT AL INICIO SIRVE PARA CONVERTIR EL RESULTADO DE LA DIVISION A FLOAT

    //CAMBIAR DE TAMAÑO DE LA IMAGEN
    sprite2->setScale(50.f / sprite2->getTexture()->getSize().x,50.f / sprite2->getTexture()->getSize().y);//DIMENSION DESEADA O TAMAÑO, DIVIDIDO EL TAMAÑO ACTUAL

    //CAMBIAR TAMAÑO PARA QUE SEA DE TODA LA VENTANA Y ASI CREAR UN FONDO
    sprite1->setScale(((float)ventana1->getSize().x / (float)sprite1->getTexture()->getSize().x) , ((float)ventana1->getSize().y / (float)sprite1->getTexture()->getSize().y));
    //EL FLOAT VA ADENTRO PORQUE DEBE CONVERTIR ESE VALOR A FLOAT Y LUEGO HACER LA OPERACION, DE LO CONTRARIO SALDRA UN ERROR

    //GENERAR FRUTAS Y OBSTACULOS EN POSICIONES RANDOM
    srand(time(NULL));
    int ManzaX = rand()%750;
    int PerX = rand()%750;
    int FresX = rand()%750;
    int PiniX = rand()%750;
    int BanaX = rand()%750;
    int ManzaY = rand()%550;
    int PerY = rand()%550;
    int FresY = rand()%550;
    int PiniY = rand()%550;
    int BanaY = rand()%550;

    int LadriX = rand()%750;
    int ColumX = rand()%750;
    int PareX = rand()%750;
    int LadriY = rand()%550;
    int ColumY = rand()%550;
    int PareY = rand()%550;

    Manzana->setPosition(ManzaX,ManzaY);
    Pinia->setPosition(PiniX,PiniY);
    Banano->setPosition(BanaX,BanaY);
    Pera->setPosition(PerX,PerY);
    Fresa->setPosition(FresX,FresY);

    Ladrillo->setPosition(LadriX,LadriY);
    Columna->setPosition(ColumX,ColumY);
    Pared->setPosition(PareX,PareY);

    Manzana->setScale(50.f / Manzana->getTexture()->getSize().x,50.f / Manzana->getTexture()->getSize().y);
    Pera->setScale(50.f / Pera->getTexture()->getSize().x,50.f / Pera->getTexture()->getSize().y);
    Pinia->setScale(50.f / Pinia->getTexture()->getSize().x,50.f / Pinia->getTexture()->getSize().y);
    Banano->setScale(50.f / Banano->getTexture()->getSize().x,50.f / Banano->getTexture()->getSize().y);
    Fresa->setScale(50.f / Fresa->getTexture()->getSize().x,50.f / Fresa->getTexture()->getSize().y);

    Ladrillo->setScale(50.f / Ladrillo->getTexture()->getSize().x,50.f / Ladrillo->getTexture()->getSize().y);
    Columna->setScale(50.f / Columna->getTexture()->getSize().x,50.f / Columna->getTexture()->getSize().y);
    Pared->setScale(50.f / Pared->getTexture()->getSize().x,50.f / Pared->getTexture()->getSize().y);

    evento1 = new Event;

    gameLoop();
}

void Juego::dibujar()
{
    ventana1->clear();
    //PRIMERO DIBUJAR EL FONDO
    ventana1->draw(*sprite1);//FONDO
    ventana1->draw(*sprite2);//SERPIENTE

    ventana1->draw(* Manzana);
    ventana1->draw(* Pera);
    ventana1->draw(* Banano);
    ventana1->draw(* Fresa);
    ventana1->draw(* Pinia);

    ventana1->display();
}

void Juego::gameLoop()
{
    while(ventana1->isOpen())
    {
        procesar_mouse();
        procesar_eventos();
        procesar_colisiones();
        dibujar();

        if(Direccion=="ARRIBA")
        {
            sprite2->setPosition(sprite2->getPosition().x, sprite2->getPosition().y - 3);
        }
        else if(Direccion == "ABAJO")
        {
             sprite2->setPosition(sprite2->getPosition().x, sprite2->getPosition().y + 3);
        }
        else if(Direccion=="IZQUIERDA")
        {
            sprite2->setPosition(sprite2->getPosition().x - 3, sprite2->getPosition().y);
        }
        else if(Direccion=="DERECHA")
        {
            sprite2->setPosition(sprite2->getPosition().x + 3, sprite2->getPosition().y);
        }
    }
}

void Juego::procesar_eventos()
{
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

void Juego::procesar_mouse()
{
    posicion_mouse = Mouse::getPosition(*ventana1);
    posicion_mouse = (Vector2i)ventana1->mapPixelToCoords(posicion_mouse);
}

void Juego::procesar_colisiones()
{
    if(sprite2->getGlobalBounds().intersects(Manzana->getGlobalBounds()))
    {
        Manzana->setColor(Color::Black);
    }
    else if(sprite2->getGlobalBounds().intersects(Pera->getGlobalBounds()))
    {
        Pera->setColor(Color::Black);
    }
    else if(sprite2->getGlobalBounds().intersects(Banano->getGlobalBounds()))
    {
        Banano->setColor(Color::Black);
    }
    else if(sprite2->getGlobalBounds().intersects(Pinia->getGlobalBounds()))
    {
        Pinia->setColor(Color::Black);
    }
    else if(sprite2->getGlobalBounds().intersects(Fresa->getGlobalBounds()))
    {
        Fresa->setColor(Color::Black);
    }

}



