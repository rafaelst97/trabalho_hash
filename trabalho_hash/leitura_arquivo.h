#pragma once
#include <iostream>
#include <stdio.h>
#include <stdlib.h> //Biblioteca para trabalhar com strings
#include <fstream> //Biblioteca para operacoes com arquivos

using namespace std;

void leitura_do_arquivo_menor() {

	ifstream arquivo_menor;
	string linha;
	int ascii = 0;
	int soma_ascii = 0;
	
	arquivo_menor.open("arquivo_teste.txt");

	if (arquivo_menor.is_open()) {

		while (getline(arquivo_menor, linha)) {

			
			/*for (int i = 0; i < linha.length(); i++) {
				if (("%d", linha[1] != 32)) {
					soma_ascii = soma_ascii + ("%d", linha[i]);
				}
				else {
					cout << soma_ascii << endl;
					soma_ascii = 0;
				}
			}*/

		}

		arquivo_menor.close();
	}
	else {
		cout << "Nao foi possivel abrir o arquivo" << endl;
	}
}