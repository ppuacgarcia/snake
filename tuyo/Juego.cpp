#include "Juego.h"
#include "Nodo.h"
#include <iostream>
Juego::Juego(int tamanio_x, int tamanio_y, string titulo) {
	this->colision = false;
	this->tamaniox = tamanio_x;
	this->tamanioy = tamanio_y;
	this->window = new RenderWindow(VideoMode(tamanio_x, tamanio_y), titulo);
	this->window->setFramerateLimit(60);
	//Texutra fondo inicial 
	this->fondoinicial = new Texture;
	this->sprfi = new Sprite;
	//Textura
	this->fondoinicial->loadFromFile("MENU.jpg");
	this->sprfi->setTexture(*fondoinicial);
	this->evento1 = new Event;
	//Texturas frutas
	this->TexturaBanano = new Texture;
	this->TexturaFresa = new Texture;
	this->TexturaPera = new Texture;
	this->TexturaManzana = new Texture;
	this->TexturaPinia = new Texture;
	//Sprites Frutas
	this->Banano = new Sprite;
	this->Fresa = new Sprite;
	this->Pera = new Sprite;
	this->Manzana = new Sprite;
	this->Pinia = new Sprite;
	//cargando frutas
	//Banano
	this->TexturaBanano->loadFromFile("Banana.png");
	//Fresa
	this->TexturaFresa->loadFromFile("Fresa.png");
	//Pera
	this->TexturaPera->loadFromFile("Pera.png");	
	//Manzana
	this->TexturaManzana->loadFromFile("Manzana.png");
	//Pinia
	this->TexturaPinia->loadFromFile("Piña.png");
	//Cargando Obstaculos;
	TexturaLadrillo = new Texture;
	TexturaColumna = new Texture;
	TexturaPared = new Texture;
	Ladrillo = new Sprite;
	Columna = new Sprite;
	Pared = new Sprite;
	this->TexturaLadrillo->loadFromFile("Ladrillo.png");
	this->TexturaColumna->loadFromFile("Columna.png");
	this->TexturaPared->loadFromFile("Pared.png");
	Ladrillo->setTexture(*TexturaLadrillo);
	Columna->setTexture(*TexturaLadrillo);
	Pared->setTexture(*TexturaPared);
	//Textos Dinamicos
	this->fuente1 = new Font;
	this->txt_puntaje = new Text;
	this->txt_velocidad = new Text;
	this->reloj1 = new Clock();
	this->tiempo = new Time();
	fuente1->loadFromFile("8_bit_party.ttf");
	this->txt_puntaje->setFont(*this->fuente1);
	
	this->txt_velocidad->setFont(*this->fuente1);
	this->posicion_puntaje.x = 150;
	this->posicion_puntaje.y = tamanioy-50;
	this->posicion_velocidad.x = 500;
	this->posicion_velocidad.y = tamanioy-50;
	//Serpiente
	textura_serpiente = new Texture;
	textura_serpiente->loadFromFile("serpiente.png");
	for (int i = 0; i < 200; i++)
	{
		serpiente[i] = new Sprite;
		serpiente[i]->setTexture(*textura_serpiente);
	}
	//texto puntajes
	txt_puntajes = new Text;
	this->txt_puntajes->setFont(*this->fuente1);
	ProcesarMouse();
	ProcesarEventos();
	Mostrar();
	Loop();
	

}
void Juego::Mostrar() {
	
	window->clear();
	//dibujar menu principal
	if (lugar == 0) {
		this->window->draw(*sprfi);

	}else if (lugar == 1)//dibujar selccion de niveles
	{
		this->window->draw(*sprni);
	}
	else if (lugar == 2)//dibujar puntajes
	{
		this->window->draw(*sprpu);
		this->txt_puntajes->setPosition({ 280,210 });
		this->txt_puntajes->setString(Recorrer());
		window->draw(*txt_puntajes);

	}
	else if(lugar==3||lugar==4||lugar==5||lugar==6)//dibujar tablero de nivel
	{
		this->window->draw(*sprta);
		if (colision == false) {
			do {
				this->posicionfrutas.x = rand() % this->tamaniox-20;
				this->posicionfrutas.y = rand() % this->tamanioy - 100;

			} while (posicionfrutas.x < 0 || posicionfrutas.y < 0 );
				
		}
		
		Vector2f anterior;
		Vector2f actual = posicions;
		int multiplicador = 6 - velocidad;
		for (int i = 0; i <= puntaje*multiplicador; i++)
		{
			anterior = serpiente[i]->getPosition();
			serpiente[i]->setPosition(actual);
			window->draw(*serpiente[i]);
			actual = anterior;
		}

        Ladrillo->setScale({ .30 , .4 });
		Columna->setScale({ .5,.5 });
		Pared->setScale({ .2,.5 });
		this->tamaniof.x = 0.20;
		this->tamaniof.y = 0.20;
		FrutasRandom()->setScale(tamaniof);
		FrutasRandom()->setPosition(posicionfrutas);
		this->window->draw(*FrutasRandom());
		this->window->draw(*this->txt_puntaje);
		this->window->draw(*this->txt_velocidad);
		
		if (lugar == 4) {
			Ladrillo->setPosition({ 90,90 });
			window->draw(*Ladrillo);
			Ladrillo->setPosition({ 400,90 });
			window->draw(*Ladrillo);
			Columna->setPosition({ 100,350});
			window->draw(*Columna);
		}
		else if (lugar > 4) {
			Ladrillo->setPosition({ 90,90 });
			window->draw(*Ladrillo);
			Ladrillo->setPosition({ 400,90 });
			window->draw(*Ladrillo);
			Columna->setPosition({ 100,350 });
			window->draw(*Columna);
			Columna->setPosition({ 500,350 });
			window->draw(*Columna);
			Pared->setPosition({ 400,200 });
			window->draw(*Pared);
		}
		

	}
	
    
	this->window->display();

}
void Juego::Loop() {
	while (this->window->isOpen()) {
		srand(time(NULL));
		ProcesarMouse(); 
		ProcesarEventos();
		Mostrar();
		Choque();
		if (lugar >2 && lugar<7) {
			*tiempo = reloj1->getElapsedTime();
			if (tiempo->asSeconds()> 30.0) {
				reloj1->restart();
				incrementar = incrementar + incrementar * 0.1;
				colision = false;
			}
			if (lugar == 6) {
			this->velocidad = this->incrementar;
			this->txt_velocidad->setString(to_string(incrementar));

			}
			
		}
		Avanzar(velocidad);
	}
}
void Juego::ProcesarEventos() {
	
	while (window->pollEvent(*evento1)) {
		//eventos de el menu
		
			switch (evento1->type)
			{
			case Event::Closed:
				exit(1);
				break;
			case Event::MouseButtonPressed:
				if (Mouse::isButtonPressed(Mouse::Left)) {
					if(lugar==0)//eventos mouse menu
					{
						
						colision = false;
						if (posicion_mouse.x > 266 && posicion_mouse.x < 533)
						{
							if (posicion_mouse.y > 190 && posicion_mouse.y < 270) {

								lugar = 1;
								fondoniveles = new Texture;
								sprni = new Sprite;
								fondoniveles->loadFromFile("Niveles.jpg");
								sprni->setTexture(*fondoniveles);
							}
							else if (posicion_mouse.y > 290 && posicion_mouse.y < 360) {
								lugar = 2;
								fondopuntajes = new Texture;
								sprpu = new Sprite;
								fondopuntajes->loadFromFile("puntajes.jpg");
								sprpu->setTexture(*fondopuntajes);
							}
							else if (posicion_mouse.y > 390 && posicion_mouse.y < 460) {
								exit(1);
							}

						}
					}
					else if (lugar == 1)//eventos mouse niveles
					{
						if (posicion_mouse.x > 600 && posicion_mouse.y > 470 && posicion_mouse.y < 540) {
							lugar = 0;
						}
						else if (posicion_mouse.x > 75 && posicion_mouse.x < 707 && posicion_mouse.y>240 && posicion_mouse.y<720) {
							tablero = new Texture;
							sprta = new Sprite;
							tablero->loadFromFile("tablero.jpg");
							sprta->setTexture(*tablero);
							//va a nivel facil
							if (posicion_mouse.x < 400 && posicion_mouse.y < 300) {
								lugar = 3;
							}//va a nivel medio
							else if(posicion_mouse.x > 400 && posicion_mouse.y<300)  {
								lugar = 4;
							}//va a nivel dificil
							else if (posicion_mouse.x < 400 && posicion_mouse.y>320) {
								lugar = 5;
							}//va a dinamico
							else if (posicion_mouse.x > 400 && posicion_mouse.y>320) {
								lugar = 6;
								this->incrementar = 1;
							}
							
						}
					}
					else if (lugar == 2)//eventos  puntajes
					{
						if (posicion_mouse.x>this->tamaniox-200 && posicion_mouse.y > this->tamanioy-150 && posicion_mouse.y < this->tamanioy-80) {
							lugar = 0;
						}
						

					}
				     if (lugar == 3)//Eventos Mouse Nivel facil
					{
						
						velocidad = 1;
						
						
					
					}
					if (lugar == 4)//Eventos Mouse Nivel Medio
					{
						
						
						velocidad = 2;
					}
					 if (lugar == 5)//Eventos Mouse Nivel Dificil
					{
						
						velocidad = 5;
					}
					 if (lugar == 6)//Eventos Mouse Nivel Dinamico
					 {
						 
						
					 }

					if (lugar == 3 || lugar == 4 || lugar == 5||lugar==6) {
						this->txt_puntaje->setPosition(this->posicion_puntaje);
						this->txt_velocidad->setString("X" + to_string(velocidad));
						this->txt_velocidad->setPosition(this->posicion_velocidad);
						this->puntaje = 0;
						if (posicion_mouse.x > tamaniox - 70 && posicion_mouse.y > tamanioy - 50) {
							 lugar = 0;
							 Perdiste();
						 }
					}
				
					
				}
				break;
            case Event::KeyPressed:
				if (Keyboard::isKeyPressed(Keyboard::Up)) {
					if (aid != 3)
					{
						aid = 1;
					}
					
				}else if (Keyboard::isKeyPressed(Keyboard::Down)) {
				
					if (aid != 1)
					{
						aid = 3;
					}
				}
				else if (Keyboard::isKeyPressed(Keyboard::Right)) {
					if (aid != 4)
					{
						aid = 2;
					}
				}
				else if (Keyboard::isKeyPressed(Keyboard::Left)) {
					if (aid != 2)
					{
						aid = 4;
					}
				}
			}

			
		}
		
}
void Juego::ProcesarMouse() {
	posicion_mouse = Mouse::getPosition(*window);
	posicion_mouse =(Vector2i)window->mapPixelToCoords(posicion_mouse);
}
Sprite* Juego::FrutasRandom() {
	
	/*
	* manzana 40% 
	* Fresa   25%
	* Banano  20% 
	* Pera    10%
	* Piña    5%
	* 
	*/
	
	if (this->colision == false) {
		this-> porcentaje = rand() % 100 + 1;
		this->colision = true;
	}
	
	
	if (porcentaje < 40) {
		this->Manzana->setTexture(*TexturaManzana);
		return this-> Manzana;
	}
	else if (porcentaje > 39 && porcentaje < 66) {
		this->Fresa->setTexture(*TexturaFresa);
		return this->Fresa;
	}
	else if (porcentaje > 65 && porcentaje < 86) {
		this->Banano->setTexture(*TexturaBanano);
		return this->Banano;
	}
	else if (porcentaje > 85 && porcentaje < 96) {
		this->Pera->setTexture(*TexturaPera);
		return this->Pera;
	}
	else if (porcentaje > 95) {
		this->Pinia->setTexture(*TexturaPinia);
		return this->Pinia;
	}
}
void Juego::Avanzar(int velocidad) {
	
	if (aid == 1) { 
		this->posicions.y -= 2*velocidad;

	}
	else if (aid == 2) {
		this->posicions.x += 2*velocidad;
	}
	else if (aid == 3) {
		this->posicions.y += 2*velocidad;
	}
	else if (aid == 4) {
		this->posicions.x -= 2*velocidad;
	}
	
	this->txt_puntaje->setString(to_string(this->puntaje));
}
void Juego::Choque() {
	//choque con frutas
	if (posicions.x > posicionfrutas.x - 20 && posicions.x<posicionfrutas.x + 50 && posicions.y>posicionfrutas.y - 20 && posicions.y < posicionfrutas.y + 30) {
		this->colision = false;
		if (this->porcentaje < 40) {
			this->puntaje += 1;
		}
		else if (porcentaje > 39 && porcentaje < 66) {
			this->puntaje += 2;
		}
		else if (porcentaje > 65 && porcentaje < 86) {
			this->puntaje += 3;
		}
		else if (porcentaje > 85 && porcentaje < 96) {
			this->puntaje -= 1;
		}
		else if (porcentaje > 95) {
			this->puntaje -= 5;
		}
		if (puntaje < 0) {
			Perdiste();
		}
	}
	if (lugar > 3) {
		//colision ladrillo 1
		if (posicions.x > 60 && posicions.x < 140 && posicions.y>60 && posicions.y < 115) {
			Perdiste();
		}
		//colision ladrillo 2
		if (posicions.x > 370 && posicions.x < 450 && posicions.y>60 && posicions.y < 115) {
			Perdiste();
		}
		//colision columna 1
		if (posicions.x > 70 && posicions.x < 170 && posicions.y>330 && posicions.y < 400) {
			Perdiste();
		}
		if (lugar > 4) {
			//colision columna 2
			if (posicions.x > 490 && posicions.x < 590 && posicions.y>330 && posicions.y < 400) {
				Perdiste();
			}
			//colision pared
			if (posicions.x > 390 && posicions.x < 440 && posicions.y>190 && posicions.y < 450) {
				Perdiste();
			}
		}
	}
	
	
		
	     
	
	if (posicions.x< 0 || posicions.x>this->tamaniox ||posicions.y<0 ||posicions.y>this->tamanioy-100){
		Perdiste();
	}
}
void Juego::Perdiste() {
	Agregar(this->puntaje);
	posicions.x = 20;
	posicions.y = 30;
	velocidad = 0;
	lugar = 0;
	aid = 2;
}
void Juego::Agregar(int punteo) {
	Nodo* nuevo = new Nodo();
	nuevo->ModificarNombre(punteo);
	if (this->frente == NULL && this->fondo == NULL) {
		this->frente = nuevo;
		this->fondo = nuevo;
	}
	else {
		Nodo* aux = this->fondo;
		this->fondo = nuevo;
		aux->ModificarSiguiente(nuevo);
	}
}
string Juego::Recorrer() {
	string resultado="Juego        Puntaje\n";
	if (frente == NULL) {
		resultado = "------";
	}
	else {

		int c = 1;
		Nodo* aux = this->frente;
		while (aux != nullptr) {
		resultado += " "+to_string(c)+"............................." + to_string(aux->ObtenerNombre());
		resultado += "\n";
		aux = aux->ObtenerSiguiente();
		c++;
		}
	}
	
	return resultado;
}
	
	