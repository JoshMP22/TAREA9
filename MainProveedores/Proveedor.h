#include<iostream>
#include<mysql.h>
#include<string>
#include<sstream>
#include "DatosPersonales.h"
#include "Conector.h"

using namespace std;

class Proveedor : Datos {

protected: string nit;
		 int buscador = 0, idproveedor=0;

public: 
	Proveedor(){}
	Proveedor(int id, string nom, string n, string dir, string tel, int bus) : Datos(nom, dir, tel) {

		idproveedor = id;
		nit = n;
		buscador = bus;

	}

	void setId(int id) { idproveedor = id; }
	void setNombre(string nom) { nombre = nom; }
	void setNit(string n) { nit = n; }
	void setDireccion(string dir) { direccion = dir; }
	void setTelefono(string tel) { telefono = tel; }
	void setBuscar(int bus) { buscador = bus; }

	int getId() { return idproveedor; }
	string getNombre() { return nombre; }
	string getNit() { return nit; }
	string getDireccion() { return direccion; }
	string getTelefono() { return telefono; }
	int getBuscar() { return buscador; }

	void crear() {

		int q_estado;
		Conector cn = Conector();

		cn.abrir_coneccion();

		if (cn.getConectar()) {

			
			string insert="INSERT INTO `proveedores`.`proveedores` (`proveedor`, `nit`, `direccion`, `telefono`) VALUES('"+nombre+"', '"+nit+"', '"+direccion+"', '"+telefono+"')";
			const char* i = insert.c_str();
			q_estado = mysql_query(cn.getConectar(), i);
			if (!q_estado) {
				cout << "INGRESADO CON EXITO .... \n";

			}
			else {
				cout << "ERROR DE CONECCION.... \n";
			}
		}
		else {
			cout << "ERROR DE CONECCION.... \n";
		}
		cn.cerrar_coneccion();

	}

	void leer() {
		int q_estado;
		Conector cn = Conector();
		MYSQL_ROW fila = 0;
		MYSQL_RES* resultado = 0;
		cn.abrir_coneccion();

		if (cn.getConectar()) {

			string consulta = "SELECT * FROM proveedores.proveedores";
			const char* i = consulta.c_str();
			q_estado = mysql_query(cn.getConectar(), i);

			if (!q_estado) {
				resultado = mysql_store_result(cn.getConectar());
				cout << "         ********* PRODUCTOS ******" << endl;
				cout << " ID   |  PROVEEDIR  |  NIT     | DIRECCION        |  TELEFONO" << endl;
				while (fila = mysql_fetch_row(resultado)) {
					cout << fila[0] << " | " << fila[1] << " | " << fila[2] << " | " << fila[3] << " | " << fila[4] << endl;
				}
			}
			else {
				cout << "ERROR DE CONECCION.... \n";
			}
		}
		else {
			cout << "ERROR DE CONECCION.... \n";
		}
		cn.cerrar_coneccion();


	}

	void actualizar() {
			
			int q_estado;
			int men = 0;
			Conector cn = Conector();

			cn.abrir_coneccion();
			string bus = to_string(buscador);

			if (cn.getConectar()) {
				system("cls");
				cout << "   ********** MENU ACTUALIZAR ********** " << endl;
				cout << " 1. NOMBRE DEL PROVEEDOR" << endl;
				cout << " 2. NIT DEL PROVEEDOR" << endl;
				cout << " 3. DIRECCION DEL PROVEEDOR" << endl;
				cout << " 4. TELEFONO DEL PROVEEDOR" << endl;
				cout << " 5. MODIFICAR TODOS LOS CAMPOS" << endl;
				cout << " QUE CAMPO DESEA MODIFICAR:  ";
				cin >> men;
				cin.ignore();

				if (men == 1) {

					cout << endl << " INGRESE NOMBRE DEL PROVEEDOR:   ";
					getline(cin, nombre); 

					string update = "UPDATE `proveedores`.`proveedores` SET `proveedor` = '"+nombre+"' WHERE (`idProveedor` = "+bus+")"; 
					const char* i = update.c_str();
					q_estado = mysql_query(cn.getConectar(), i);
					if (!q_estado) {
						cout << "MODIFICADO CON EXITO .... \n";
					}
					else {
						cout << "ERROR DE CONECCION.... \n";
					}
				}

				else if (men == 2) {

					cout << endl << " INGRESE NOMBRE DEL PROVEEDOR:   ";
					getline(cin, nit);
					
					string update = "UPDATE `proveedores`.`proveedores` SET `nit` = '" + nit + "' WHERE (`idProveedor` = " + bus + ")";
					const char* i = update.c_str();
					q_estado = mysql_query(cn.getConectar(), i);
					if (!q_estado) {
						cout << "MODIFICADO CON EXITO .... \n";
					}
					else {
						cout << "ERROR DE CONECCION.... \n";
					}
				}

				else if (men == 3) {

					cout << endl << " INGRESE LA DIRECCION DEL PROVEEDOR:   ";
					getline(cin, direccion);

					string update = "UPDATE `proveedores`.`proveedores` SET `direccion` = '" + direccion + "' WHERE (`idProveedor` = " + bus + ")";
					const char* i = update.c_str();
					q_estado = mysql_query(cn.getConectar(), i);
					if (!q_estado) {
						cout << "MODIFICADO CON EXITO .... \n";
					}
					else {
						cout << "ERROR DE CONECCION.... \n";
					}
				}

				else if (men == 4) {

					cout << endl << " INGRESE TELEFONO DEL PROVEEDOR:   ";
					getline(cin, telefono);

					string update = "UPDATE `proveedores`.`proveedores` SET `telefono` = '" + telefono + "' WHERE (`idProveedor` = " + bus + ")";
					const char* i = update.c_str();
					q_estado = mysql_query(cn.getConectar(), i);
					if (!q_estado) {
						cout << "MODIFICADO CON EXITO .... \n";
					}
					else {
						cout << "ERROR DE CONECCION.... \n";
					}
				}

				else if (men == 5) {
					cout << endl;

					cout << " INGRESE PROVEEDOR:                ";
					getline(cin, nombre);
					cout << "INGRESE NIT DEL PROVEEDOR:         ";
					getline(cin, nit);
					cout << "INGRESE DIRECCION DEL PROVEEDOR:   ";
					getline(cin, direccion);
					cout << "INGRESE NUMERO DE TELEFONO:        ";
					getline(cin, telefono);

					string update = "UPDATE `proveedores`.`proveedores` SET `proveedor` = '"+nombre+"', `nit` = '"+nit+"', `direccion` = '"+ direccion +" ', `telefono` = '"+telefono+"' WHERE (`idProveedor` = " + bus + ")";
					const char* i = update.c_str();
					q_estado = mysql_query(cn.getConectar(), i);
					if (!q_estado) {
						cout << "MODIFICADO CON EXITO .... \n";
					}
					else {
						cout << "ERROR DE CONECCION.... \n";
					}
				}


			}
			else {
				cout << "ERROR DE CONECCION.... \n";
			}
			system("pause");
			cn.cerrar_coneccion();

	}

	void eliminar() {

		int q_estado, q_stado;
		int c = 1, r = 0, im = 0;
		Conector cn = Conector();
		MYSQL_ROW fila = 0;
		MYSQL_RES* resultado = 0;

		cn.abrir_coneccion();
		string id = to_string(idproveedor);
		if (cn.getConectar()) {

			string delite = "DELETE FROM proveedores.proveedores WHERE idProveedor= " + id + "";

			const char* i = delite.c_str();

			q_estado = mysql_query(cn.getConectar(), i);
			if (!q_estado) {

				cout << "ELIMINADO CON EXITO .... \n";


				string consulta = "SELECT * FROM proveedores.proveedores";
				const char* j = consulta.c_str();
				q_stado = mysql_query(cn.getConectar(), j);
				string cc = to_string(c);
				if (!q_stado) {
					resultado = mysql_store_result(cn.getConectar());

					while (fila = mysql_fetch_row(resultado)) {

						string imm = to_string(im);
						imm = fila[0];
						istringstream(imm) >> im;
						int ii = idproveedor;

						if (c == im) {
							c++;
							cc = to_string(c);
						}
						else {
							r = im - 1;
							string rr = to_string(r);
							string mod = "UPDATE `proveedores`.`proveedores` SET `idProveedor` = " + rr + " WHERE(`idProveedor` = " + imm + ")";
							const char* m = mod.c_str();
							q_stado = mysql_query(cn.getConectar(), m);

							c++;
							cc = to_string(c);

						}

					}
					cout << cc << endl;
					string auto_inc = "alter table proveedores auto_increment = " + cc + "";
					const char* a = auto_inc.c_str();
					q_stado = mysql_query(cn.getConectar(), a);
				}
				else {
					cout << "ERROR DE CONECCION.... \n";
				}
			}
		}
		else {
			cout << "ERROR DE CONECCION.... \n";
		}
		cn.cerrar_coneccion();


	}


};

