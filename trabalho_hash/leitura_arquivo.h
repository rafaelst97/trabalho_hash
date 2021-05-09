#pragma once
#include <iostream>
#include <stdio.h>
#include <stdlib.h> //Biblioteca para trabalhar com strings
#include <fstream> //Biblioteca para operacoes com arquivos

using namespace std;

void primeira_hash(int& palavra_ascii) {

	int texto_ascii[25]; // Vetor para separar cada palavra
	int navegacao_texto = 0; // Variavel para auxiliar na navegacao do vetor e imprimir o mesmo

	texto_ascii[navegacao_texto] = palavra_ascii; //Se a palavra termnou, ela eh colocada no vetor do texto
	palavra_ascii = 0; // Zerando o valor da palavra
	navegacao_texto++; // Parte para a proxima posicao do vetor de texto

	for (int i = 0; i < navegacao_texto; i++) { // Impressao do vetor de texto
		cout << texto_ascii[i] << endl;
	}

}

void leitura_do_arquivo_menor() { // Funcao para ler arquivo menor

	ifstream arquivo_menor; //Arquivo com no maximo 25 palavras
	string linha; //Variavel para auxiliar na navegacao do arquivo
	int palavra_ascii = 0; // Variavel para somar valores ASCII

	
	arquivo_menor.open("arquivo_teste.txt"); //Abrindo o arquivo

	if (arquivo_menor.is_open()) { // Se o arquivo estiver aberto, realizar esta tarefa

		while (getline(arquivo_menor, linha)) { //lendo todo o arquivo

			for (int i = 0; i < linha.length(); i++) { // Percorre as strings lidas
				if (linha[i] != ' ' && linha[i] != '.') { // Verifica se nao ha espaco ou ponto
					palavra_ascii = palavra_ascii + ("%d", linha[i]); // Caso nao haja espaco ou ponto, vai somando os codigos ASCII em uma palavra
				}
				else {
					
					primeira_hash(palavra_ascii);

				}
			}

		}

		arquivo_menor.close(); // Fecha o arquivo
	}
	else {
		cout << "Nao foi possivel abrir o arquivo" << endl; // Mensagem de erro para o caso do arquivo nao poder ser aberto
	}

	
}