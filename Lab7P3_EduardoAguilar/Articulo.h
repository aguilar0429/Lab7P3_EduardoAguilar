#ifndef ARTICULO_H
#define ARTICULO_H
#include <iostream>
#include <vector>
#include "Categoria.h"
#include <string>

using namespace std;
class Articulo
{
	public:
		Articulo(string,vector<char>,double,int,double,Categoria*);
		~Articulo();
		void setNombre(string);
		string getNombre();
		void setTallas(vector<char>);
		vector<char> getTallas();
		void setPrecio(double);
		double getPrecio();
		void setCantidad(int);
		int getCantidad();
		void setDescuento(double);
		double getDescuento();
		void setCategoria(Categoria*);
		Categoria* getCategoria();
		
	
		string toString();
		string printVector();
	private:
		string nombre;
		vector<char> tallas;
		double precio;
		int cantidad;
		double descuento;
		Categoria* categoria;
	protected:
};

#endif