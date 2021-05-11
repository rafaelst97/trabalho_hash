// trabalho_hash.cpp : Este arquivo contém a função 'main'. A execução do programa começa e termina ali.
//

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string> //Biblioteca para trabalhar com strings
#include <fstream> //Biblioteca para operacoes com arquivos
#include "leitura_arquivo.h" //Biblioteca da leitura do arquivo e hash

using namespace std;

int main()
{
	const int TAMANHO = 1000; //Tamanho da tabela
	elementos texto[TAMANHO]; // Tabela

	menu_inicial(texto, TAMANHO); //Inicializazao do menu
}