#include "Tienda.h"

Tienda::Tienda() {

}

Tienda::~Tienda() {
	for(int i = 0 ; i < categorias.size() ; i++)
		delete categorias[i];

	for(int i = 0; i < articulos.size(); i++) {
		delete articulos[i];
	}

}

void Tienda::agregarCategoria(Categoria* cat) {

	categorias.push_back(cat);

}
void Tienda::agregarArticulo(Articulo* art) {

	articulos.push_back(art);

}
int Tienda::menutallas() {
	int opcion = 0 ;
	cout<<"Elija talla: \n"
	    <<"1. S\n"
	    <<"2. M\n"
	    <<"3. L\n";
	cin >> opcion;
	return opcion;
}

void Tienda::mostrarCategorias() {
	string categoria = "";
	int opcion;

	for(int i = 0; i < categorias.size(); i++) {
		cout<< i << ") " <<categorias.at(i)->getCategoria() << "\n";
	}

}
vector<Categoria*>Tienda:: getCategorias() {
	return this->categorias;
}
void Tienda::borrarArticulo(int posicion) {
	articulos.erase(articulos.begin()+posicion);
}
void Tienda::printArticulos() {
	int opcion;
	for(int i = 0; i < articulos.size(); i++) {
		cout<< i << ") " << articulos.at(i)->toString() << "\n";
	}
}

void Tienda::modifArticulos(int x, int y) {

	switch(y) {
		case 1: {
			string nombre = "";
			cout<<"Ingrese nuevo nombre: ";
			cin>>nombre;
			articulos.at(x)->setNombre(nombre);
			break;
		}
		case 2: {
			double precio = 0;
			cout<<"Ingrese nuevo precio: ";
			cin>>precio;
			articulos.at(x)->setPrecio(precio);
			break;
		}
		case 3: {
			int cantidad = 0;
			cout<<"Ingrese nueva cantidad: ";
			cin>>cantidad;
			articulos.at(x)->setCantidad(cantidad);
			break;
		}
		case 4: {
			double descuento = 0;
			cout<<"Ingrese nuevo descuento: ";
			cin>>descuento;
			articulos.at(x)->setDescuento(descuento);
			break;
		}
		case 5: {
			int categoria = 0 ;
			mostrarCategorias();
			cout<<"Elija categoria del articulo: ";
			cin >> categoria;
			articulos.at(x)->setCategoria(categorias.at(categoria));
			break;
		}
	}
}

void Tienda::GeneralStats() {
	int unidades = 0;
	int preciototal = 0;

	for(int i = 0 ; i < categorias.size(); i++) {
		int unidades_categoria = 0;
		int preciocategoria = 0 ;
		cout<<categorias.at(i)->getCategoria()<<": "<<endl;
		for(int j = 0 ; j < articulos.size(); j++) {
			if(categorias.at(i)->getCategoria().compare(articulos.at(j)->getCategoria()->getCategoria())==0) {
				preciototal+=articulos.at(j)->getPrecio();
				cout<<j<<") "<<"Nombre: "<<articulos.at(j)->getNombre()<<endl;
				preciocategoria+=articulos.at(j)->getPrecio();
				unidades_categoria+=articulos.at(j)->getCantidad();

				unidades+=articulos.at(j)->getCantidad();
			}
		}
		cout<<"Total unidades en categoria: "<<unidades_categoria<<endl;
		cout<<"Precio por categoria: "<<preciocategoria<<endl<<endl;
	}
	cout<<"Precio total: "<<preciototal<<endl;
	cout<<"Total productos unicos: "<<articulos.size()<<endl;
	cout<<"Unidades totales: "<<unidades<<endl;
}
void Tienda::filtrar(int x,char y,int z) {
	vector<Articulo*> sorts;
	if(x == -1) {
		for(int j = 0 ; j < articulos.size(); j++) {
			for(int i = 0 ; i < articulos.at(j)->getTallas().size(); i ++) {
				if(y == articulos.at(j)->getTallas().at(i)) {
					//cout<<"Nombre de articulo: "<<articulos.at(j)->getNombre()<<endl;
					sorts.push_back(articulos.at(j));
				}
			}
		}
		if(z == 1){
		//	sort(sorts.begin(),sorts.end(),MenoraMayor);
		}else{
		//	sort(sorts.begin(),sorts.end(),MayoraMenor);
		}
		

	} else {
		for(int j = 0 ; j < articulos.size(); j++) {
			if(categorias.at(x)->getCategoria().compare(articulos.at(j)->getCategoria()->getCategoria())==0) {
				cout<<"Nombre de articulo: "<<articulos.at(j)->getNombre()<<endl;
				if(y == 'N') {
					cout<<"Nombre de articulo: "<<articulos.at(j)->getNombre()<<endl;
				sorts.push_back(articulos.at(j));
				} else {
					for(int i = 0 ; i < articulos.at(j)->getTallas().size(); i ++) {
						if(y == articulos.at(j)->getTallas().at(i)) {
							cout<<"Nombre de articulo: "<<articulos.at(j)->getNombre()<<endl;
							sorts.push_back(articulos.at(j));
						}
					}
				}
			}
			
		}
	//	if(z == 1){
			//sort(sorts.begin(),sorts.end(),MenoraMayor);
	//	}else{
	//	//	sort(sorts.begin(),sorts.end(),MayoraMenor);
	//	}
	}


}
/*bool Tienda::MenoraMayor(Articulo* i1, Articulo* i2)
{
	double precio1 = 0 ;
	double precio2 = 0 ;
	precio1 = (*i1).getPrecio();
	precio2 = (*i2).getPrecio();
    return(precio1 < precio2);
}
bool Tienda::MayoraMenor(Articulo* i1, Articulo* i2)
{
    return((*i1).getPrecio() > (*i2).getPrecio());
}*/

