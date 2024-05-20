#include <string>
#include <iostream>
#include <fstream>

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
		//Reinicio el puntero al principio del archivo ya que ahora despues de leer las lineas esta al final
		file_read.clear();
		file_read.seekg(0);

		//Si empty es 0 significa que el archivo esta vacío
		if (empty == 0) {
			std::cout << "No se han encontrado mensajes nuevos" << std::endl;

			std::cout << "Escribe tantos mensajes como quieras, (esribe 'exit' cuando termines)" << std::endl;
			//Bucle para que el usuario pueda escribir hasta que escriba exit
			do {
				//Input del user
				std::cin >> linea;


				//Hago un if por si la palabra es exit que no se escriba en el archivo
				if (linea != "exit") {
					//Le paso el input a otra variable la cual voy a encriptar
					std::string lineaEncriptada = linea;

					//Aqui hago un bucle for each que va muy bien en esta situación ya que itera por cada char que haya dentro de la palabra (Encontrado en un post de StackOverflow)
					for (char c : lineaEncriptada) {
						//El char lo convierte en -5 de la tabla ascii
						c = c - 5;
						//Escribo ese char dentro del archivo
						file_input << c;
						//Voy calculando el checksum
						checksum = checksum + c;
					}
					//Despues de cada palabra hago un salto de linea
					file_input << std::endl;

				}
				//Este if esta para que se escriba el checksum una vez el usuario haya escrito exit, el checksum no esta en la cabecera porque no he sabido hacerlo correctamente
				if (linea == "exit") {
					file_input << checksum;
				}

				//Cuando el input es exit nos salimos del archivo
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

			//Si quiere recuperar los mensajes se metera en este condicional
			if (recuperar == 's') {

				//Esta parte es la que uso para desencriptar los mensajes
				while (getline(file_read, linea)) {
					//El bucle for each es exactamente igual pero en vez de restar 5 suma esos 5 y lo muestra en pantalla
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

				//Cierro los archivos ya que si hemos entrado en este else debemos abrir el archivo en truncal para borrar todo lo anterior
				file_read.close();
				file_input.close();

				//Los abro en modo truncal
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

	//Cierro los archivos para acabar
	file_read.close();
	file_input.close();
	
}