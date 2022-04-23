#include<iostream>
using namespace std;

class Datos{

protected:string nombre, direccion, telefono;

protected:
	Datos(){}
	Datos(string nom, string dir, string tel){
	
		nombre = nom;
		direccion = dir;
		telefono = tel;

	}

};

