#include <fstream>
#include <iostream>
#include <windows.h>
#include <string>
#include <conio.h>
#include "menu.hpp"

using namespace std;
//definir caracteres (Teclas)
#define ENTER 13
#define RETROCESO 8
//Prototipos
void autenticar();
void restablecerContrasenia();
bool NuevaContrasenia(string, string);
bool buscarUsuario(string);
bool autenticarUsuario(string, string);
//Funciones
//@params estaAutenticado servira de referencia para saber si un usuario se autentico correctamente.
//@params ENTER en codigo ASCII el valor de ENTER es 13
//@params RETROCESO en codigo ASCII el valor de BACKSPIN o RETROCESO es 8
void autenticar(){
	//define types || definir tipos
	bool estaAutenticado = false;
	// Variables a usar para recoger datos digitados por usuario
	string usuario;
	string contrasenia;
	//bucle do-while
	do{
		system("cls");
		gotoxy(40,5);
		cout<<"******************************************"<<endl;
		gotoxy(40,6);
		cout<<"             ° INICIAR SESION °           "<<endl;
		gotoxy(40,7);
		cout<<"******************************************"<<endl;
		gotoxy(40,8);
		cout<<"Usuario: ";cin>>usuario;
		gotoxy(40,9);
		cout<<"Contrasenia: ";
		//Metodo para ocultar la contraseña al momento de escribirla en consola
		char contraseniaEncriptada;
		contraseniaEncriptada = getch();
		contrasenia = ""; // Al momento de repetirse este bucle se inicializa vacia
		 while( contraseniaEncriptada != ENTER ){
			if( contraseniaEncriptada != RETROCESO ){
				contrasenia.push_back(contraseniaEncriptada);
				cout<<" ";
			}else{
				// Al momento de borrar se eliminara el caracter antes escrito
				if(contrasenia.length() > 0 ){
					cout << "\b \b";
					contrasenia.substr(0,contrasenia.length()-1);
				}
			}
			contraseniaEncriptada = getch();
		}
		if(contrasenia.empty()){
			system("cls");
			gotoxy(25,10);
			cout<<"La contrasenia esta vacia, intenta nuevamente..."<<endl;
			Sleep(2000);
			return;
		}
		//Autenticacion de usuario
		gotoxy(40,10);
		cout<<"******************************************"<<endl;
		system("cls");
		gotoxy(40,15);
		//Preparando metodo para la autenticacion
		cout<<"Autenticando espere un momento..."<<endl;
		//Espera 3 segundos para ejecutar el siguiente bloque de codigo
		Sleep(3000);
		// Funcion retorna valor booleano para cambiar esta de autenticacion
		estaAutenticado = autenticarUsuario(usuario,contrasenia);
		// Si no son correctos los datos de autenticacion repite bucle
		if(!estaAutenticado){
			system("cls");
			cout<<"\a";
			gotoxy(30,15);
			cout<<"Usuario y/o contrasenia incorrectos"<<endl;
			Sleep(3000);
		}
		if(estaAutenticado){
			menu_principal(usuario);
		}
	}while(!estaAutenticado);
	
}
//funcion para autenticar a un usuario
bool autenticarUsuario(string user, string password){
	string usuario, contrasenia;
	//define types
	bool encontrado = false;
	//variable para la lectura de una archivo .txt
	ifstream lectura;
	lectura.open("login.txt", ios::out | ios::in);
	//Si no falla al momento de la lectura realiza la sentencia IF
	if(lectura.is_open()){
		lectura>>usuario;
		// Se crea un bucle para recorrer el archivo .txt y realizar la busqueda del usuario.
		while(!lectura.eof()){
			lectura>>contrasenia;
			if( usuario == user && contrasenia == password){ // se realiza la validacion si el usuario y contraseña estan correctos
				return !encontrado;
			}
			lectura>>usuario;
		}
		lectura.close();
	}else{
		system("cls");
		gotoxy(30,10);
		cout<<" No se encontro el fichero login.txt "<<endl;
	}
	
	return encontrado;
}
//Funcion para restablecer la contraseña
void restablecerContrasenia(){
	//define types  || definir tipos
	string usuario, nuevaContrasenia, confirmContrasenia;
	bool encontrado = false;
	//bucle do-while
	do{
		system("cls");
		gotoxy(25,13);
		cout<<"           CREAR NUEVA CONTRASENIA     "<<endl;
		gotoxy(25,14);
		cout<<" Ingrese el usuario a cambiar contrasenia: ";cin>>usuario;
		//Funcion retorna si valor true si fue encontrado el usuario
		encontrado = buscarUsuario(usuario);
		// en caso de que no se encontro el usuario
		if(!encontrado){
			system("cls");
			gotoxy(25,15);
			cout<<" Usuario no encontrado, intenta nuevamente..."<<endl;
			Sleep(2000);
			return;
		}
		// en caso que si se encontro el usuario
		gotoxy(25,16);
		cout<<"Ingresa la nueva contrasenia: "; // se ingresa la nueva contraseña
		char contraseniaEncriptada;
		contraseniaEncriptada = getch();
		nuevaContrasenia = "";
		while( contraseniaEncriptada != ENTER ){
			if(contraseniaEncriptada != RETROCESO ){
				nuevaContrasenia.push_back(contraseniaEncriptada);
				cout<<" ";
			}else{
				// Al momento de borrar se eliminara el caracter antes escrito
				if(nuevaContrasenia.length() > 0 ){
					cout << "\b \b";
					nuevaContrasenia.substr(0,nuevaContrasenia.length()-1);
				}
			}
			contraseniaEncriptada = getch();
		}
		// Confirmacion de contraseña, esto garantiza de que el usuario este seguro del cambio de la contraseña
		gotoxy(25,17);
		cout<<"Confirme nuevamente la contrasenia: ";
		char confirmContraseniaEncriptada;
		confirmContrasenia = getch();
		confirmContrasenia = "";
		while( confirmContraseniaEncriptada != ENTER ){
			if(confirmContraseniaEncriptada != RETROCESO ){
				confirmContrasenia.push_back(confirmContraseniaEncriptada);
				cout<<" ";
			}else{
				// Al momento de borrar se eliminara el caracter antes escrito
				if(confirmContrasenia.length() > 0 ){
					cout << "\b \b";
					confirmContrasenia.substr(0,confirmContrasenia.length()-1);
				}
			}
			confirmContraseniaEncriptada = getch();
		}
		// en caso que no coincida la confirmacion de la contraseña mostrara el siguiente error.

		//retorna un valor booleano si la contraseña es diferente a la que tenía
		encontrado = NuevaContrasenia(nuevaContrasenia, usuario);
		if(!encontrado){
			system("cls");
			gotoxy(40,5);
			cout<<"No se puede asignar la misma contrasenia... intenta nuevamente"<<endl;
			Sleep(2000);
			return;
		}
		system("cls");
		gotoxy(40,5);
		cout<<"Se ha cambiado la contrasenia exitasomente. Inicia sesion nuevamente. "<<endl;
		Sleep(3000);
		
	}while(!encontrado);
	
}
//funcion para buscar usuario
bool buscarUsuario(string user){
	//define types || definir tipos
	bool encontrado = false;
	string usuario;
	ifstream lectura;
	lectura.open("login.txt", ios::out | ios::in);
	if(lectura.is_open()){
		lectura>>usuario;
		while(!lectura.eof()){
			if( usuario == user ){
				return !encontrado;
			}
		lectura>>usuario;
		}
	}else{
		system("cls");
		gotoxy(40,5);
		cout<<"ERROR FATAL: No se pudo encontrar el archivo login.txt"<<endl;
		Sleep(4000);
		return !encontrado;
	}
	lectura.close();
	
	return encontrado;
}
bool NuevaContrasenia(string nuevaContrasenia, string user){
	//define types
	ofstream escritura;
	ifstream lectura;
	//variable booleana
	bool encontrado = false;
	//variables temporales
	string usuario, contrasenia;
	// inicializar lectura y escritura de archivo .txt
	escritura.open("login_temp.txt", ios::out);
	lectura.open("login.txt", ios::in);
	//verificar que exista el archivo .txt
	if(escritura.is_open() && lectura.is_open()){
		lectura>>usuario;
		while(!lectura.eof()){
			lectura>>contrasenia;
			// se realiza la validacion de que el usuario sea el correcto y la contraseña sea distinta a la anterior
			if( usuario == user && contrasenia != nuevaContrasenia ){
				escritura<<usuario<<" "<<nuevaContrasenia<<endl;
				encontrado = true;
			}else{ // en caso no se cumpla no se modifica
				escritura<<usuario<<" "<<contrasenia<<endl;
			}
			lectura>>usuario;
		}
		// se cierran los archivos de escritura y lectura
		escritura.close();
		lectura.close();
		// se elimina el archivo login.txt 
		remove("login.txt");
		// y se remplaza con el temporal que se creo para que haga la correcta modificacion de la contraseña
		rename("login_temp.txt","login.txt");
	}else{
		system("cls");
		gotoxy(40,5);
		cout<<"Fatal Error: No se encontro el archivo login.txt"<<endl;
		Sleep(3000);
		return !encontrado;
	}
	return encontrado;
}
