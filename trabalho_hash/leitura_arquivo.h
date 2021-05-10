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

void impressao_hash(elementos texto[], const int TAMANHO) { //Funcao de impressao

	int menu = 0; // Inicializacao de variavel para o menu
	int quantidade_palavras = 1; // Variavel para contar a quantidade de palavras
	float taxa_ocupacao = 1.0; //Variavel para a taxa de ocupacao da tabela hash
	int colisoes = 0; // Variavel para tratar as colisoes

	//Loop do menu
	while (menu != 7) {
	cout << "Escolha '1' para exibir a tabela hash completa" << endl
		<< "Escolha '2' para exibir o tamanho da tabela" << endl
		<< "Escolha '3' para exibir a quantidade de palavras que ha no texto" << endl
		<< "Escolha '4' para exibir a ocupacao da tabela" << endl
		<< "Escolha '5' para exibir a quantidade de colisoes" << endl
		<< "Escolha '6' para exibir o metodo hash utilizado" << endl
		<< "Escolha '7' para sair" << endl
		<< "Digite sua opcao: ";
	cin >> menu;

		// Opcoes do menu
		switch (menu) {
		case 1:
			for (int i = 0; i < TAMANHO; i++) {
				cout << "Posicao: " << i << " Chave: " << texto[i].chave << " Palavra: " << texto[i].palavra << endl;
			}
			cout << "\n";
			break;

		case 2:
			system("cls");
			cout << "Tamanho da tabela eh: " << TAMANHO << endl;
			break;

		case 3:
			for (int i = 0; i < TAMANHO; i++) {
				if (texto[i].chave != 0) {
					quantidade_palavras++;
				}
				
			}
			system("cls");
			cout << "Quantidade de palavras na tabela eh: " << quantidade_palavras << endl;

			quantidade_palavras = 1;

			break;

		case 4:
			for (int i = 0; i < TAMANHO; i++) {
				if (texto[i].chave != 0) {
					taxa_ocupacao = taxa_ocupacao + 1.0;
				}

			}
			taxa_ocupacao = taxa_ocupacao * 100;
			taxa_ocupacao = taxa_ocupacao / TAMANHO;

			system("cls");
			cout << "A taxa de ocupacao da tabela eh: " << taxa_ocupacao << "%" << endl;

			taxa_ocupacao = 0;

			break;

		case 5:
			for (int i = 0; i < TAMANHO; i++) {
				if 
			}

		default:

			system("cls");
			cout << "Opcao invalida" << endl;

			break;
		}
	}
}

void primeira_hash(int palavra_ascii, string palavra, elementos texto[]) { //Primeiro metodo hash, recebe como parametro a palavra lida do texto menor
	int navegacao_texto = 0; // Variavel para auxiliar na navegacao do vetor e imprimir o mesmo
	int aux = 0;
	navegacao_texto = palavra_ascii % 100 ;  // Metodo hash
	
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
				if (linha[i] != ' ') { // Verifica se nao ha espaco ou ponto
					palavra = palavra + linha[i];
					palavra_ascii = palavra_ascii + ("%d", linha[i]); // Caso nao haja espaco ou ponto, vai somando os codigos ASCII em uma palavra
					
				}
				else {
					
					primeira_hash(palavra_ascii, palavra, texto); //Funcao para colocar na tabela hash
					palavra_ascii = 0; //Zera o somatorio de ASCII
					palavra.clear(); //Zera a palavra

				}
			}

		}

		arquivo_menor.close(); // Fecha o arquivo
	}
	else {
		cout << "Nao foi possivel abrir o arquivo" << endl; // Mensagem de erro para o caso do arquivo nao poder ser aberto
	}

	
}