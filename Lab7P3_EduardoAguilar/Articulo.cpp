#include "Articulo.h"

Articulo::Articulo(string x,vector<char> y,double z,int xx,double yy,Categoria* zz) {
	this->nombre = x;
	this->tallas = y;
	this->precio = z;
	this->cantidad = xx;
	this->descuento = yy;
	this->categoria = zz;

}

Articulo::~Articulo() {

	delete[] categoria;
}

void Articulo::setNombre(string name){
	this->nombre = name;
}
void Articulo::setPrecio(double precio){
	this->precio = precio;
}
void Articulo::setCantidad(int cant){
	this->cantidad= cant;
}
void Articulo::setDescuento(double dis){
	this->descuento = dis;
}
void Articulo::setCategoria(Categoria* cat){
	this->categoria = cat;
}
Categoria* Articulo::getCategoria(){
	return categoria;
}
double Articulo::getPrecio(){
	return precio;
}
int Articulo::getCantidad(){
	return cantidad;
}
string Articulo::getNombre(){
	return nombre;
}
vector<char> Articulo::getTallas(){
	return tallas;
}

string Articulo::printVector() {
	string print="";

	for(int i = 0 ; i <tallas.size(); i++) {
		print+= "(" ;
		print+= tallas.at(i);
		print+= ")";

	}
	
	return print;
}
string Articulo::toString() {
	string vectorr_tallas;
	vectorr_tallas = printVector();
	string print = "[";

	print += nombre;
	print += ",";
	print += to_string(precio);
	print += ",";
	print += to_string(cantidad);

	print +=",";
	print += to_string(descuento);
	print +=",";
	print +=categoria->getCategoria();
	print += ",";
	print += vectorr_tallas;

	print += "]";
	return print;
}