#pragma once
#include <iostream>
#include <stdio.h>
#include <stdlib.h> //Biblioteca para trabalhar com strings
#include <fstream> //Biblioteca para operacoes com arquivos

using namespace std;

struct elementos {
	int chave = 0;
	string palavra;
};

void impressao_hash(elementos texto[]) {

	for (int i = 0; i < 1000; i++) {
		cout << "Posicao: " << i << " Chave: " << texto[i].chave << " Palavra: " << texto[i].palavra << endl;
	}
}

void primeira_hash(int& palavra_ascii, string &palavra, elementos texto[]) { //Primeiro metodo hash, recebe como parametro a palavra lida do texto menor
	int navegacao_texto = 0; // Variavel para auxiliar na navegacao do vetor e imprimir o mesmo
	int aux = 0;
	navegacao_texto = palavra_ascii % 100;  // Metodo hash
	
	if (navegacao_texto == texto[navegacao_texto].chave) { // Inicio do tratamento de colisao
		aux = navegacao_texto;
		do {
			aux++;
		} while (navegacao_texto == texto[aux].chave);

		texto[aux].chave = navegacao_texto;
		texto[aux].palavra = palavra;
		aux = 0;
	}
	else {
		texto[navegacao_texto].chave = navegacao_texto;
		texto[navegacao_texto].palavra = palavra;
	} // Fim do tratamento de colisao

}

void leitura_do_arquivo_menor(elementos texto[]) { // Funcao para ler arquivo menor

	ifstream arquivo_menor; //Arquivo com no maximo 25 palavras
	string linha; //Variavel para auxiliar na navegacao do arquivo
	string palavra; //Variavel para salvar palavras individualmente
	palavra.clear();
	int palavra_ascii = 0; // Variavel para somar valores ASCII

	
	arquivo_menor.open("arquivo_teste.txt"); //Abrindo o arquivo

	if (arquivo_menor.is_open()) { // Se o arquivo estiver aberto, realizar esta tarefa

		while (getline(arquivo_menor, linha)) { //lendo todo o arquivo

			for (int i = 0; i < linha.length(); i++) { // Percorre as strings lidas
				if (linha[i] != ' ' && linha[i] != '.') { // Verifica se nao ha espaco ou ponto
					palavra = palavra + linha[i];
					palavra_ascii = palavra_ascii + ("%d", linha[i]); // Caso nao haja espaco ou ponto, vai somando os codigos ASCII em uma palavra
					primeira_hash(palavra_ascii, palavra, texto);
					
				}
				else {
					
					palavra_ascii = 0;
					palavra.clear();

				}
			}

		}

		arquivo_menor.close(); // Fecha o arquivo
	}
	else {
		cout << "Nao foi possivel abrir o arquivo" << endl; // Mensagem de erro para o caso do arquivo nao poder ser aberto
	}

	
}