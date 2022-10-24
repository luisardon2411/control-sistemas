#include <fstream>
#include <iostream>
#include <windows.h>
#include <string>
#include <conio.h>

using namespace std;
//Modificador de posicion 
 void gotoxy(int x,int y){  
      HANDLE hcon;  
      hcon = GetStdHandle(STD_OUTPUT_HANDLE);  
      COORD dwPos;  
      dwPos.X = x;  
      dwPos.Y= y;  
      SetConsoleCursorPosition(hcon,dwPos);  
 }
//Prototipos
void menu_principal(string);
void registrarTelefono();
void mostrarRegistros();
void mostrarPorCodigo();
void cerrarSesion();

//funciones
void menu_principal(string usuario){
	system("cls");
	cout<<"\a";
	gotoxy(40,13);
	cout<<" Bienvenido "<<usuario<<" "<<endl;
	Sleep(4000);
	int opciones = 0;
	do{
		system("cls");
		gotoxy(40,5);
		cout<<"********************************"<<endl;
		gotoxy(40,6);
		cout<<"        MENU PRINCIPAL          "<<endl;
		gotoxy(40,7);
		cout<<"********************************"<<endl;
		gotoxy(40,8);
		cout<<" 1. Registrar un telefono       "<<endl;
		gotoxy(40,9);
		cout<<" 2. Mostrar todos los registros "<<endl;
		gotoxy(40,10);
		cout<<" 3. Mostrar por codigo          "<<endl;
		gotoxy(40,11);
		cout<<" 4. Cerrar Sesion               "<<endl;
		gotoxy(40,12);
		cout<<"********************************"<<endl;
		gotoxy(10,2);
		cout<<"Usuario: "<<usuario<<endl;
		gotoxy(40,13);
		cout<<"Opcion -> ";cin>>opciones;
		switch(opciones){
			case 1:
				registrarTelefono();
				break;
			case 2:
				mostrarRegistros();
				break;
			case 3:
				mostrarPorCodigo();
				break;	
			case 4:
				cerrarSesion();
				break;
		}
	}while(opciones != 4);
}
//Funcion para cerrar sesion
void cerrarSesion(){
	system("cls");
	gotoxy(40,15);
	cout<<"Cerrando la sesion.... Espere un momento."<<endl;
	Sleep(2000);
	system("cls");
	gotoxy(40,15);
	cout<<"Se ha cerrado la sesion correctamente :)"<<endl;
	Sleep(1000);
	return;
}
//Funcion para registrar un telefono
void registrarTelefono(){
	system("cls");
	//define types
	string codigo, codigo_temporal;
	string numero_serie, numero_serie_temporal;
	string marca, marca_temporal;
	string modelo, modelo_temporal;
	double precio, precio_temporal;
	string fecha_ingreso, fecha_temporal;
	//variable booleana para saber si existe un codigo repetido al momento de registrar un telefono
	bool codigo_repetido = false;
	// variable para la escritura y lectura en el archivo .txt
	ofstream escritura;
	ifstream lectura;
	// inicializar la escritura del archivo .txt
	escritura.open( "telefonos.txt", ios::out | ios::app );
	lectura.open( "telefonos.txt", ios::in );
	// en caso que no ocurra error al abrir el archivo 
	if( escritura.is_open() && lectura.is_open() ){
		system("cls");
		gotoxy(25,4);
		cout<<"***********************************************"<<endl;
		gotoxy(25,5);
		cout<<"           ° Registro de Telefonos °           "<<endl;
		gotoxy(25,6);
		cout<<"***********************************************"<<endl;
		gotoxy(25,7);
		cout<<"   CODIGO DE TELEFONO: ";cin>>codigo;
		gotoxy(25,8);
		cout<<"    MARCA DE TELEFONO: ";cin>>marca;
		gotoxy(25,9);
		cout<<"   MODELO DE TELEFONO: ";cin>>modelo;
		gotoxy(25,10);
		cout<<"      NUMERO DE SERIE: ";cin>>numero_serie;
		gotoxy(25,11);
		cout<<"   PRECIO DE TELEFONO: ";cin>>precio;
		gotoxy(25,12);
		cout<<"     FECHA DE INGRESO: ";cin>>fecha_ingreso;
		gotoxy(25,13);
		cout<<"************************************************"<<endl;
		// verificar si el registro previo existe en el archivo .txt
		lectura>>codigo_temporal;
		while(!lectura.eof()){
			lectura>>marca_temporal>>modelo_temporal>>numero_serie_temporal>>precio_temporal>>fecha_temporal;
			if( codigo_temporal == codigo ){
				system("cls");
				gotoxy(30,10);
				cout<<"El codigo ingresado ya existe, intenta nuevamente..."<<endl;
				Sleep(2000);
				codigo_repetido = true;
				break;
			}
			lectura>>codigo_temporal;
		}
		if(!codigo_repetido){
			system("cls");
			gotoxy(30,5);
			cout<<" Realizando el registro del telefono, un momento..."<<endl;
			Sleep(2000);
			escritura<<codigo<<" "<<marca<<" "<<modelo<<" "<<numero_serie<<" "<<precio<<" "<<fecha_ingreso<<endl;
			system("cls");
			gotoxy(30,5);
			cout<<"Se realizo correctamente el registro "<<endl;
			Sleep(2000);
		}
		
	}else{
		system("cls");
		gotoxy(30,12);
		cout<<"ERROR FATAL: No se encontro el archivo telefonos.txt"<<endl;
		Sleep(2000);
	}
	escritura.close();
	lectura.close();
	
}
// Funcion para mostrar todos los registros
void mostrarRegistros(){
	//define types || definir tipos
	string codigo, marca, modelo, numero_serie, fecha_ingreso;
	double precio;
	//variables para la lectura de archivos .txt
	ifstream lectura;
	// inicializar la lectura
	lectura.open("telefonos.txt", ios::in );
	//en caso no falle la lectura del archivo se ejecutara la sentencia IF
	if(lectura.is_open()){
		lectura>>codigo;
		system("cls");
		cout<<"***************************************"<<endl;
		cout<<"     ° TOTAL DE REGISTROS °            "<<endl;
		cout<<"***************************************"<<endl;
		while(!lectura.eof()){
			lectura>>marca>>modelo>>numero_serie>>precio>>fecha_ingreso;
			cout<<" CODIGO DE TELEFONO: "<<codigo<<endl;
			cout<<"  MARCA DE TELEFONO: "<<marca<<endl;
			cout<<" MODELO DE TELEFONO: "<<modelo<<endl;
			cout<<"    NUMERO DE SERIE: "<<numero_serie<<endl;
			cout<<" PRECIO DE TELEFONO: "<<precio<<endl;
			cout<<"   FECHA DE INGRESO: "<<fecha_ingreso<<endl;
			cout<<"***********************************"<<endl;
			lectura>>codigo;
		}
		getch();
	}
	lectura.close();
}
//Funcion para mostrar por codigo
void mostrarPorCodigo(){
	//define types || definir tipos
	string codigo, codigo_temporal, marca, modelo, numero_serie, fecha_ingreso;
	double precio;
	//variable booleana para la busqueda del producto
	bool producto_encontrado = false;
	//variable para la lectura del archivo .txt
	ifstream lectura;
	//inicializar variable de lectura 
	lectura.open("telefonos.txt", ios::in );
	// en caso la lectura sea correcta ingresa a la sentencia IF
	if(lectura.is_open()){
		system("cls");
		gotoxy(30,5);
		cout<<" INGRESA EL CODIGO DEL PRODUCTO A BUSCAR: ";cin>>codigo; // se realiza la busqueda por medio del codigo ingresado por el usuario
		lectura>>codigo_temporal;
		// se crea un bucle para buscar en el archivo .txt
		while(!lectura.eof()){
			lectura>>marca>>modelo>>numero_serie>>precio>>fecha_ingreso;
			// si encuentra el codigo en al archivo .txt ingresa a la sentencia IF
			if( codigo_temporal == codigo ){
				producto_encontrado = true;
				system("cls");
				gotoxy(30,5);
				cout<<"*****************************"<<endl;
				gotoxy(30,6);
				cout<<"   RESULTADO DE LA BUSQUEDA  "<<endl;
				gotoxy(30,7);
				cout<<"*****************************"<<endl;
				gotoxy(30,8);
				cout<<" CODIGO DE TELEFONO: "<<codigo<<endl;
				gotoxy(30,9);
				cout<<"  MARCA DE TELEFONO: "<<marca<<endl;
				gotoxy(30,10);
				cout<<" MODELO DE TELEFONO: "<<modelo<<endl;
				gotoxy(30,11);
				cout<<"    NUMERO DE SERIE: "<<numero_serie<<endl;
				gotoxy(30,12);
				cout<<" PRECIO DE TELEFONO: "<<precio<<endl;
				gotoxy(30,13);
				cout<<"   FECHA DE INGRESO: "<<fecha_ingreso<<endl;
				gotoxy(30,14);
				cout<<"******************************"<<endl;
				getch();
			}
			lectura>>codigo_temporal;
			
		}
		// en caso contrario mostrar un mensaje de error
		if(!producto_encontrado){
			system("cls");
			gotoxy(30,5);
			cout<<" El codigo ingresado no existe. Intenta nuevamente..."<<endl;
			Sleep(2000);
			lectura.close();
			return;
		}
		// se cierra el archivo de lectura.
		lectura.close();
	}
}
