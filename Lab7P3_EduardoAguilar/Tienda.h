#ifndef TIENDA_H
#define TIENDA_H
#include <vector>
#include <iostream>
#include "Articulo.h"
#include "Categoria.h"
#include <bits/stdc++.h>
using std::string;
using std:: vector;

using std::cout;

using std::cin;
using std::endl;


class Tienda
{
	public:
		Tienda();
		~Tienda();
		void agregarCategoria(Categoria*);
		vector<Categoria*> getCategorias();
		void agregarArticulo(Articulo*);
		void mostrarCategorias();
		int menutallas();
		void borrarArticulo(int);
		void printArticulos();
		void modifArticulos(int, int);
		void GeneralStats();
		void filtrar(int,char,int);
		bool MenoraMayor(Articulo*, Articulo*);
		bool MayoraMenor(Articulo*, Articulo*);
	private:
		vector<Categoria*> categorias;
		vector<Articulo*> articulos;
	protected:
};

#endif