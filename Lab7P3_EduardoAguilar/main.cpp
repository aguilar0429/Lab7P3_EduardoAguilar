#include <iostream>
#include "Tienda.h"
#include <vector>
#include "Categoria.h"
using std::cout;
using std::string;
using std::cin;
using std::endl;
using std:: vector;
int menu();
int smenu();

int main(int argc, char** argv) {
	int opcion2 = 0;
	int opcion = 0 ;
	Tienda* t = new Tienda();
	vector<char> charsss;
	vector<char> charss;
	charss.push_back('S');
	charsss.push_back('S');
	charsss.push_back('M');
	t->agregarCategoria(new Categoria("camisa"));
	t->agregarCategoria(new Categoria("pants"));
	t->agregarArticulo(new Articulo("camisetas",charss,1000,200,300,t->getCategorias().at(0)));
	t->agregarArticulo(new Articulo("camisetas2",charsss,100,200,300,t->getCategorias().at(0)));
	t->agregarArticulo(new Articulo("pants",charsss,200,200,300,t->getCategorias().at(1)));
	while(opcion!=5) {
		switch(opcion = menu()) {
			case 1: {
				string categoria="";
				cout<<"Ingrese nombre de la categoria: ";
				cin>> categoria;
				t->agregarCategoria(new Categoria(categoria));

				break;
			}
			case 2: {
				switch(opcion2 = smenu()) {
					case 1: {
						t->mostrarCategorias();
						int categoria = 0 ;
						string nombre;
						double precio;
						int cantidad;
						double descuento;
						cout<<"Elija categoria del articulo: ";
						cin >> categoria;
						cout<<"Nombre: ";
						cin >> nombre;
						vector<char> tallas;
						char si = 'S';
						char talla=' ';
						while(si == 'S') {
							cout<<"Elija talla(S,M,L): ";
							cin>> talla;
							tallas.push_back(talla);
							cout<<"Desea seguir agregando?(S/N): ";
							cin>>si;
						}
						cout<<"Ingrese precio: ";
						cin>>precio;
						cout<<"Ingrese cantidad: ";
						cin>>cantidad;
						cout<<"Ingrese descuento: ";
						cin>>descuento;
						t->agregarArticulo(new Articulo(nombre,tallas,precio,cantidad,descuento,t->getCategorias().at(categoria)));
						break;
					}
					case 2: {
						int modif = 0 ;
						int cualidad = 0;
						t->printArticulos();
						cout<<"Ingrese articulo a modificar: ";
						cin>> modif;
						cout<<"Ingrese que modificar: \n"
						<<"1. Nombre\n"
						<<"2. Precio\n"
						<<"3. Cantidad\n"
						<<"4. Descuento\n"
						<<"5. Categoria\n";
						cin>>cualidad;
						t->modifArticulos(modif,cualidad);
						cout<<"Se modifico exitosamente!\n";
						
						
						break;
					}
					case 3: {
						cout << "Que articulo desea eliminar:\n";
                        t->printArticulos();
                        int articulo = 0;
                        cin >> articulo;
                        t->borrarArticulo(articulo);
                       
						break;
					}
					case 4: {
						t->printArticulos();
						break;
					}
				}
				break;
			}
			case 3: {
				t->GeneralStats();
				break;
			}
			case 4: {
				int categ = 0 ;
				char valor= '1';
				int prize = 0;
				t->mostrarCategorias();
				cout<<"Ingrese categoria a buscar: \n";
				cout<<"Ingrese -1 si no quiera filtrar por categoria\n";
				cin>>categ;
				/*please ingresalo en mayuscula
				y solo ingresa S L o M */
				
				
				cout<<"Ingrese talla: \n"
				<<"S\n"
				<<"M\n"
				<<"L\n"
				<<"N (NO TALLA)\n";
				cin>>valor;
				cout<<"1. Menor a mayor\n"
				<<"2. Mayor a menor";
				cin >> prize;
				t->filtrar(categ,valor,prize);
				cout<<endl;
				break;
			}
		}
	}
	return 0;
}

int menu() {
	int opcion = 0;
	cout<<"Menu\n"
	    <<"1. Agregar Categoria\n"
	    <<"2. Mantenimiento de Articulos\n"
	    <<"3. Estadisticas Generales\n"
	    <<"4. Busqueda por categoria y talla\n"
	    <<"5. Salir\n"
	    <<"Ingrese opcion: ";
	cin >> opcion;
	return opcion;
}
int smenu() {
	int opcion = 0;
	cout<<"Menu\n"
	    <<"1. Agregar Articulo\n"
	    <<"2. Modificar Articulo\n"
	    <<"3. Eliminar Articulo\n"
	    <<"4. Listar Articulos\n"
	    <<"Ingrese opcion: ";
	cin >> opcion;
	return opcion;
}
