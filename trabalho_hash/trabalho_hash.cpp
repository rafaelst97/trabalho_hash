// trabalho_hash.cpp : Este arquivo contém a função 'main'. A execução do programa começa e termina ali.
//

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string> //Biblioteca para trabalhar com strings
#include <fstream> //Biblioteca para operacoes com arquivos
#include "leitura_arquivo.h"

using namespace std;

int main()
{
	const int TAMANHO = 1000;
	elementos texto[TAMANHO]; // Tabela

	leitura_do_arquivo(texto);
	impressao_hash(texto, TAMANHO);
}