#include "Cola.h"


Cola::Cola()
{
	this->tamano = 0;
	this->frente = nullptr;
	this->fondo = nullptr;
	this->anterior_x = 0;
	this->anterior_y = 0;
	this->aumento_x = 0;
	this->aumento_y = 0;
	this->velocidad = 0;
	this->pixeles = 0;
	this->evento1 = new Event;
	this->perdiste = false;
}

Cola::Cola(RenderWindow* ventana, float pixeles, string apariencia, float velocidad)
{
	this->tamano = 0;
	this->frente = nullptr;
	this->fondo = nullptr;
	this->anterior_x = 0;
	this->anterior_y = 0;
	this->aumento_x = 0;
	this->aumento_y = 0;
	this->pixeles = pixeles;
	this->apariencia = apariencia;
	this->velocidad = velocidad;
	this->ventana = ventana;
	this->evento1 = new Event;
	this->perdiste = false;
}

int Cola::ObtenerTamano()
{
	return this->tamano;
}

Nodo* Cola::ObtenerFrente()
{
	return this->frente;
}

void Cola::Insertar(float x, float y)
{
	Nodo* nuevo = new Nodo;
	nuevo->ModificarApariencia(this->apariencia, this->pixeles);
	nuevo->ModificarX(x);
	nuevo->ModificarY(y);
	if (this->frente == nullptr && this->fondo == nullptr)
	{
		this->frente = nuevo;
		this->fondo = nuevo;
		nuevo->ModificarAnteriorX(x);
		nuevo->ModificarAnteriorY(y);
	}
	else
	{
		nuevo->ModificarX(this->fondo->ObtenerX()- this->pixeles);
		nuevo->ModificarY(this->fondo->ObtenerY());
		nuevo->ModificarAnteriorX(this->fondo->ObtenerX() - this->pixeles);
		nuevo->ModificarAnteriorY(this->fondo->ObtenerY());
		this->fondo->ModificarSiguiente(nuevo);
		this->fondo = nuevo;
	}
	this->tamano++;
}

void Cola::ModificarApariencia(string apariencia)
{
	this->apariencia = apariencia;
}

void Cola::Recorrer()
{
	float x, y;
	Nodo* aux = this->frente;
	Nodo* siguiente = aux->ObtenerSiguiente();
	while (aux != nullptr) {
			if (aux == frente) {
				this->anterior_x = aux->ObtenerX();
				this->anterior_y = aux->ObtenerY();
				aux->ModificarX(aux->ObtenerX() + this->aumento_x);
				aux->ModificarY(aux->ObtenerY() + this->aumento_y);
				aux->ModificarApariencia(this->apariencia, this->pixeles);
				if ((aux->ObtenerX() < 0) || (aux->ObtenerX() > 800) || (aux->ObtenerY() < 0) || (aux->ObtenerY() > 500))
				{
					this->perdiste = true;
				}
			}
			else {

				x = this->anterior_x;
				y = this->anterior_y;

				this->anterior_x = aux->ObtenerX();
				this->anterior_y = aux->ObtenerY();

				aux->ModificarX(x);
				aux->ModificarY(y);
				aux->ModificarApariencia(this->apariencia, this->pixeles);
			}
		aux->ObtenerSprite()->setPosition(aux->ObtenerX(), aux->ObtenerY());
		this->ventana->draw(aux->ObtenerApariencia());
		aux = aux->ObtenerSiguiente();
	}
}

void Cola::ProcesarEventos()
{
	while (this->ventana->pollEvent(*this->evento1))
	{
		switch (this->evento1->type)
		{
		case Event::Closed:
			this->ventana->close();
			break;

		case Event::KeyPressed:
			if (Keyboard::isKeyPressed(Keyboard::Up))
			{
				if (this->aumento_y != this->velocidad)
				{
					this->aumento_y = -1 * this->velocidad * this->pixeles;
					this->aumento_x = 0;
				}
			}
			else if (Keyboard::isKeyPressed(Keyboard::Down))
			{
				if (this->aumento_y != -1 * this->velocidad)
				{
					
					this->aumento_y = this->velocidad * this->pixeles;
					this->aumento_x = 0;
				}
			}
			else if (Keyboard::isKeyPressed(Keyboard::Right))
			{
				if (this->aumento_x != -1 * this->velocidad)
				{
					
					this->aumento_x = this->velocidad * this->pixeles;
					this->aumento_y = 0;
				}
			}
			else if (Keyboard::isKeyPressed(Keyboard::Left))
			{
				if (this->aumento_x != this->velocidad)
				{
					
					this->aumento_x = -1 * this->velocidad * this->pixeles;
					this->aumento_y = 0;
				}
			}
			else if (Keyboard::isKeyPressed(Keyboard::Space))
			{
				this->aumento_y = 0;
				this->aumento_x = 0;
			}
			else if (Keyboard::isKeyPressed(Keyboard::Escape))
			{
				this->ventana->close();
			}
			break;

		default:
			break;
		}
	}
}

void Cola::gameloop()
{
	while (this->perdiste == false)
	{
		this->ventana->clear();
		this->ProcesarEventos();
		this->Recorrer();
		this->ProcesarEventos();
		this->Perdida();
		this->ventana->display();
	}
}

void Cola::Perdida()
{
	Nodo* aux = this->frente;
	aux = aux->ObtenerSiguiente();
	aux = aux->ObtenerSiguiente();
	aux = aux->ObtenerSiguiente();
	while (aux != nullptr)
	{
		if ((aux->ObtenerX() == this->frente->ObtenerX()) && (aux->ObtenerY() == this->frente->ObtenerY()))
		{
			this->perdiste = true;
		}
	}
}