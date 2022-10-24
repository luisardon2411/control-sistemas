#include <fstream>
#include <iostream>
#include <windows.h>
#include <string>
#include "login.hpp"

using namespace std;
//Prototipos - Declaracion de funciones antes de la inicializacion
void menu();
void iniciarSesion();
void salir();

 //Funcion para Salir del sistema
 void salir(){
 	system("cls");
 	gotoxy(50,15);
 	cout<<"Saliendo del sistema..."<<endl;
 	Sleep(3000);
 	system("cls");
 	gotoxy(45,15);
 	cout<<"Se ha cerrado el sistema exitosamente!"<<endl;
 }
 //Funcion para crear el menu Login
 void iniciarSesion(){
 	int opcion = 0;
 	do{
 		system("cls");
 		system("Color 0A");
 		gotoxy(35,5);
 		cout<<"********************************************"<<endl;
 		gotoxy(35,6);
 		cout<<"     Control de inventarios de TELECOM      "<<endl;
 		gotoxy(35,7);
		cout<<"********************************************"<<endl;
		gotoxy(45,8);
		cout<<" 1. Iniciar Sesion"<<endl;
		gotoxy(45,9);
		cout<<" 2. Olvide mi contrasenia"<<endl;
		gotoxy(45,10);
		cout<<" 3. Salir"<<endl;
		gotoxy(35,11);
		cout<<"********************************************"<<endl;
		gotoxy(35,12);
		cout<<"Opcion ->   ";cin>>opcion;
		
		switch(opcion){
			case 1: 
				autenticar();
				break;
			case 2:
				restablecerContrasenia();
				break;	
			case 3:
				salir();
				break;
			default: 
					system("cls");
					gotoxy(35,10);
					cout<<"La opcion digitada no existe, intenta nuevamente..."<<endl;
					Sleep(2000);
		}
	 } while(opcion != 3);
 }
//Funcion principal
int main(){
	iniciarSesion();
	return 0;
}
