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
		cout<<" 3. Cerrar Sesion               "<<endl;
		gotoxy(40,10);
		cout<<"********************************"<<endl;
		gotoxy(10,2);
		cout<<"Usuario: "<<usuario<<endl;
		gotoxy(40,11);
		cout<<"Opcion -> ";cin>>opciones;
		switch(opciones){
			case 1:
				break;
			case 2:
				break;
			case 3:
				cerrarSesion();
				break;
		}
	}while(opciones != 3);
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
	int codigo_telefono;
	
	
}
