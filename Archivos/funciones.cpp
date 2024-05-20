#include <string>
#include <iostream>
#include <fstream>

void pedirInput(std::string linea, std::ifstream file_read, std::ofstream file_input, int& checksum ) {

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