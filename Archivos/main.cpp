#include <string>
#include <iostream>
#include <fstream>
#include "funciones.h"

void main() {

	//Declaro el nombre de las variables al input y output del archivo
	std::ifstream file_read;
	std::ofstream file_input;
	//El input del usuario
	std::string linea;
	//Variable que usare para encriptar caracter a caracter
	char c;
	//La variable que utilizare para guardarme el checksum
	int checksum = 0;

	//Abro el mismo archivo en modo app desde un principio y los abro tanto en read como en input
	file_read.open("elemento.txt", std::ios::app);
	file_input.open("elemento.txt", std::ios::app);

	if (!file_read.is_open() && !file_input.is_open()) {

		//Mensaje de error
		std::cout << "No se a podido abrir el archivo";

	}
	else {
		//Mensaje de confirmacion
		std::cout << "Si se a podido abrir el archivo" << std::endl;
		//Con esta variable comprobare que el archivo esta vacio, si empty = 0 es que esta vacio
		int empty = 0;
		while (getline(file_read, linea)) {
			empty++;
		}
		//Reinicio el puntero al principio del archivo
		file_read.clear();
		file_read.seekg(0);

		
		if (empty == 0) {
			std::cout << "No se han encontrado mensajes nuevos" << std::endl;

			std::cout << "Escribe tantos mensajes como quieras, (esribe 'exit' cuando termines)" << std::endl;
			//Bucle para que el usuario pueda escribir hasta que escriba exit
			do {

				std::cin >> linea;


				//Hago un if por si la palabra es exit que no se escriba en el archivo
				if (linea != "exit") {
					std::string lineaEncriptada = linea;

					for (char c : lineaEncriptada) {
						c = c - 5;
						file_input << c;
						checksum = checksum + c;
					}
					file_input << std::endl;

				}
				if (linea == "exit") {
					file_input << checksum;
				}


			} while (linea != "exit");


		}



		//Si se han encontrado mensajes anteriores
		else {
			//Pido al usuario si quiere recuperar los mensajes con un char "s" o "n"
			std::cout << "Se han encontrado mensajes anteriores, quieres recuperarlos? s/n" << std::endl;
			char recuperar;
			//Bucle de validacion de input
			do {
				std::cin >> recuperar;
			} while (recuperar != 's' && recuperar != 'n');

			if (recuperar == 's') {

				while (getline(file_read, linea)) {
					for (char c : linea) {
						c = c + 5;
						std::cout << c;
					}
					std::cout << std::endl;
				}
				std::cout << "Escribe tantos mensajes como quieras, (esribe 'exit' cuando termines)" << std::endl;
				//Bucle para que el usuario pueda escribir hasta que escriba exit
				do {

					std::cin >> linea;


					//Hago un if por si la palabra es exit que no se escriba en el archivo
					if (linea != "exit") {
						std::string lineaEncriptada = linea;

						for (char c : lineaEncriptada) {
							c = c - 5;
							file_input << c;
							checksum = checksum + c;
						}
						file_input << std::endl;

					}
					if (linea == "exit") {
						file_input << checksum;
					}


				} while (linea != "exit");
			}




			else {

				file_read.close();
				file_input.close();

				file_read.open("elemento.txt", std::ios::trunc);
				file_input.open("elemento.txt", std::ios::trunc);

				std::cout << "Escribe tantos mensajes como quieras, (esribe 'exit' cuando termines)" << std::endl;
				//Bucle para que el usuario pueda escribir hasta que escriba exit
				do {

					std::cin >> linea;


					//Hago un if por si la palabra es exit que no se escriba en el archivo
					if (linea != "exit") {
						std::string lineaEncriptada = linea;

						for (char c : lineaEncriptada) {
							c = c - 5;
							file_input << c;
							checksum = checksum + c;
						}
						file_input << std::endl;

					}
					if (linea == "exit") {
						file_input << checksum;
					}


				} while (linea != "exit");
				

			}


		}

	}

	file_read.close();
	file_input.close();
	
}