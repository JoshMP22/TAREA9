#include <iostream>
#include <string>
#include "Proveedor.h"
using namespace std;

int main()
{
    
    int selec=0, bus=0, id=0;
    char op = 's';
    string nom, n, dir, tel;
    
    do {
        system("cls");
        cout << "___________________________________________________________" << endl;
        cout << "       ********** MENU PROVEEDORES *********" << endl;
        cout << "___________________________________________________________" << endl;
        cout << "     1. INGRESE NUEVO PROVEEDOR" << endl;
        cout << "     2. VER BASE DE DATOS DE PROVEEDORES" << endl;
        cout << "     3. MODIFICAR DATOS DE PROVEEDORES" << endl;
        cout << "     4. ELIMINAR PROVEEDORES" << endl;
        cout << "     0. SALIR" << endl;
        cin >> selec;
        cin.ignore();

        if (selec == 1) {
            char op = 's';
            system("cls");

            do {
                cout << " INGRESE PROVEEDOR:                ";
                getline(cin, nom);
                cout << "INGRESE NIT DEL PROVEEDOR:         ";
                getline(cin, n);
                cout << "INGRESE DIRECCION DEL PROVEEDOR:   ";
                getline(cin, dir);
                cout << "INGRESE NUMERO DE TELEFONO:        ";
                getline(cin, tel);

                Proveedor pro = Proveedor(id, nom, n, dir, tel, bus);
                pro.crear();
                cout << endl << "DESEA INGRESAR OTRO PROVEEDOR (s/n):  ";
                cin >> op;
                cin.ignore();
            } while (op == 's' || op == 'S');
        }
        else if (selec == 2) {
            system("cls");
            Proveedor pro = Proveedor();
            pro.leer();

            system("pause");

        }
        else if (selec == 3) {

            char b = 's';

            system("cls");
            do {
                cout << "INGRESE EL ID DEL PROVEEDOR QUE DESEA ACTUALIZAR: ";
                cin >> bus;
                cin.ignore();


                Proveedor pro = Proveedor(id, nom, n, dir, tel, bus);
                pro.actualizar();
                
                system("cls");
                cout << "MODIFICAR OTRO PROVEEDOR (s/n): ";
                cin >> b;
                cin.ignore();

            } while (b == 's' || b == 'S');

        }
        else if (selec == 4) {

            system("cls"); 
            cout << "INGRESE EL ID DEL PROVEEDOR QUE DESEA ELIMINAR: ";
            cin >> id;
            cin.ignore();

            Proveedor pro = Proveedor(id, nom, n, dir, tel, bus);
            pro.eliminar();
            system("pause");

        }
        
    } while (selec!=0);

}
