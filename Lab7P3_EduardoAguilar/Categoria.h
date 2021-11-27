#ifndef CATEGORIA_H
#define CATEGORIA_H
#include <iostream>


using std::string;

class Categoria
{
	public:
		Categoria(string);
		~Categoria();
		void setCategoria(string);
        string getCategoria();
	private:
		string categoria;
};

#endif