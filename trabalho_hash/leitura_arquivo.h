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

// Funcao responsavel pela impressao das informacoes das tabelas
void impressao_hash(elementos texto[], const int TAMANHO, int metodo_hash) { //Funcao de impressao

	int menu = 0; // Inicializacao de variavel para o menu
	int quantidade_palavras = 1; // Variavel para contar a quantidade de palavras
	int colisoes = 0; // Variavel para controlar o numero de colisoes
	float taxa_ocupacao = 1.0; //Variavel para a taxa de ocupacao da tabela hash
	string hash;

	//Loop do menu
	while (menu != 7) {
		system("cls");
	cout << "Escolha '1' para exibir a tabela hash completa" << endl
		<< "Escolha '2' para exibir o tamanho da tabela" << endl
		<< "Escolha '3' para exibir a quantidade de palavras que ha no texto" << endl
		<< "Escolha '4' para exibir a ocupacao da tabela" << endl
		<< "Escolha '5' para exibir a quantidade de colisoes" << endl
		<< "Escolha '6' para exibir o metodo hash utilizado" << endl
		<< "Escolha '7' para voltar para a tela inicial" << endl
		<< "Digite sua opcao: ";
	cin >> menu;

		// Opcoes do menu
		switch (menu) {
		case 1:

			//impressao da tabela inteira
			system("cls");
			for (int i = 0; i < TAMANHO; i++) {
				cout << "Posicao: " << i << " Chave: " << texto[i].chave << " Palavra: " << texto[i].palavra << endl;
			}
			system("pause");
			break;

		case 2:

			//impressao do tamanho da tabela
			system("cls");
			cout << "Tamanho da tabela eh: " << TAMANHO << endl;
			system("pause");
			break;

		case 3:

			//Impressao da quantidade de palavras que ha na tabela
			for (int i = 0; i < TAMANHO; i++) {
				if (texto[i].chave != 0) {
					quantidade_palavras++;
				}
				
			}
			system("cls");
			cout << "Quantidade de palavras na tabela eh: " << quantidade_palavras << endl;
			system("pause");
			quantidade_palavras = 1;

			break;

		case 4:

			//Calculo e impressao da taxa de ocupacao da tabela
			for (int i = 0; i < TAMANHO; i++) {
				if (texto[i].chave != 0) {
					taxa_ocupacao = taxa_ocupacao + 1.0;
				}

			}
			taxa_ocupacao = taxa_ocupacao * 100;
			taxa_ocupacao = taxa_ocupacao / TAMANHO;

			system("cls");
			cout << "A taxa de ocupacao da tabela eh: " << taxa_ocupacao << "%" << endl;
			system("pause");

			taxa_ocupacao = 0;

			break;

		case 5:

			//Calculo e impressao da quantidade de colisoes que houve na tabela
			for (int i = 0; i < TAMANHO; i++) {
				if (texto[i].chave != 0 && texto[i].chave != i) {
					colisoes++;
				}
			}
			system("cls");
			cout << "O numero de colisoes foi: "<< colisoes << endl;
			colisoes = 0;
			system("pause");
			break;

		case 6:

			//Impressao do metodo hash utilizado
			system("cls");
			switch (metodo_hash) {
			case 1 :
				hash = "o primeiro";
				break;
			case 2:
				hash = "o segundo";
				break;
			case 3:
				hash = "o terceiro";
				break;
			}
			cout << "O metodo hash utilizado foi " << hash << endl;
			system("pause");
		case 7:

			//Voltar para a tela inicial
			for (int i = 0; i < TAMANHO; i++) {
				texto[i].chave = 0;
				texto[i].palavra = "";
			}
			break;

		default:

			system("cls");
			cout << "Opcao invalida" << endl;
			system("pause");

			break;
		}
	}
}

void primeira_hash(int palavra_ascii, string palavra, elementos texto[]) { //Primeiro metodo de hashing
	int navegacao_texto = 0; // Variavel para auxiliar na navegacao do vetor e imprimir o mesmo
	int aux = 0;
	navegacao_texto = palavra_ascii % 100 ;  // Metodo
	
	if (texto[navegacao_texto].chave != 0) { // Inicio do tratamento de colisao.
		aux = navegacao_texto;
		do {
			aux++;
		} while (texto[aux].chave != 0);

		texto[aux].chave = navegacao_texto;
		texto[aux].palavra = palavra;
		aux = 0;
	}
	else {
		texto[navegacao_texto].chave = navegacao_texto;
		texto[navegacao_texto].palavra = palavra;
	} // Fim do tratamento de colisao

}

void segunda_hash(int palavra_ascii, string palavra, elementos texto[]) { // Segunda funcao de hash
	int navegacao_texto = 0; // Variavel para auxiliar na navegacao do vetor e imprimir o mesmo
	int aux = 0;
	navegacao_texto = palavra_ascii / 5;  // Metodo

	if (texto[navegacao_texto].chave != 0) { // Inicio do tratamento de colisao.
		aux = navegacao_texto;
		do {
			aux++;
		} while (texto[aux].chave != 0);

		texto[aux].chave = navegacao_texto;
		texto[aux].palavra = palavra;
		aux = 0;
	}
	else {
		texto[navegacao_texto].chave = navegacao_texto;
		texto[navegacao_texto].palavra = palavra;
	} // Fim do tratamento de colisao
}

void terceira_hash(int palavra_ascii, string palavra, elementos texto[]) {
	int navegacao_texto = 0; // Variavel para auxiliar na navegacao do vetor e imprimir o mesmo
	int aux = 0;
	navegacao_texto = palavra_ascii % 50;  // Metodo hash

	if (texto[navegacao_texto].chave != 0) { // Inicio do tratamento de colisao. Metodo antigo >>>>> (navegacao_texto == texto[navegacao_texto].chave)
		aux = navegacao_texto;
		do {
			aux++;
		} while (texto[aux].chave != 0); // Metodo antigo >>>> (navegacao_texto == texto[aux].chave)

		texto[aux].chave = navegacao_texto;
		texto[aux].palavra = palavra;
		aux = 0;
	}
	else {
		texto[navegacao_texto].chave = navegacao_texto;
		texto[navegacao_texto].palavra = palavra;
	} // Fim do tratamento de colisao
}

void leitura_do_arquivo(elementos texto[], int tamanho_texto, int metodo_hash) { // Funcao para ler arquivo menor

	ifstream arquivo; //Arquivo com no maximo 25 palavras
	string linha; //Variavel para auxiliar na navegacao do arquivo
	string palavra; //Variavel para salvar palavras individualmente
	palavra.clear();
	int palavra_ascii = 0; // Variavel para somar valores ASCII
	int escolha_arquivo = 0; //Variavel para selecionar o arquivo que sera aberto

		switch (tamanho_texto) {
		case 1:
			arquivo.open("texto_menor.txt");
			break;

		case 2:
			arquivo.open("texto_medio.txt");
			break;

		case 3:
			arquivo.open("texto_maior.txt");
			break;

		}


	
	if (arquivo.is_open()) { // Se o arquivo estiver aberto, realizar esta tarefa

		while (getline(arquivo, linha)) { //lendo todo o arquivo

			for (int i = 0; i < linha.length(); i++) { // Percorre as strings lidas
				if (linha[i] != ' ' && linha[i] != ',' && linha[i] != '.' && linha[i] != '-') { // Verifica se nao ha espaco ou ponto
					palavra = palavra + linha[i];
					palavra_ascii = palavra_ascii + ("%d", linha[i]); // Caso nao haja espaco ou ponto, vai somando os codigos ASCII em uma palavra

				}
				else {

					switch (metodo_hash) {
					case 1: 
						primeira_hash(palavra_ascii, palavra, texto);
						palavra_ascii = 0; //Zera o somatorio de ASCII
						palavra.clear(); //Zera a palavra
						break;
					case 2:
						segunda_hash(palavra_ascii, palavra, texto);
						palavra_ascii = 0; //Zera o somatorio de ASCII
						palavra.clear(); //Zera a palavra
						break;
					case 3:
						terceira_hash(palavra_ascii, palavra, texto);
						palavra_ascii = 0; //Zera o somatorio de ASCII
						palavra.clear(); //Zera a palavra
						break;
					}

				}
			}

		}

		arquivo.close(); // Fecha o arquivo
	}
	else {
		cout << "Nao foi possivel abrir o arquivo" << endl; // Mensagem de erro para o caso do arquivo nao poder ser aberto
	}
}

int metodo_hash(elementos texto[], int escolha_menu, const int TAMANHO) {
	system("cls");

	while (escolha_menu != 0) {
		
		int tamanho_texto = escolha_menu;
		int metodo_hash = 0;
		system("cls");
		cout << "1 - Primeiro metodo hash" << endl
			<< "2 - Segundo metodo hash" << endl
			<< "3 - Terceiro metodo hash" << endl
			<< "0 - Voltar" << endl
			<< "Opcao: ";
		cin >> escolha_menu;

		switch (escolha_menu) {
		case 1:
			metodo_hash = 1;
			leitura_do_arquivo(texto, tamanho_texto, metodo_hash);
			impressao_hash(texto, TAMANHO, metodo_hash);
			escolha_menu = 0;
			break;
		case 2:
			metodo_hash = 2;
			leitura_do_arquivo(texto, tamanho_texto, metodo_hash);
			impressao_hash(texto, TAMANHO, metodo_hash);
			escolha_menu = 0;
			break;
		case 3:
			metodo_hash = 3;
			leitura_do_arquivo(texto, tamanho_texto, metodo_hash);
			impressao_hash(texto, TAMANHO, metodo_hash);
			escolha_menu = 0;
			break;
		case 0:
			return escolha_menu;
			break;
		default:
			system("cls");
			cout << "Opcao invalida" << endl;
			system("pause");
			break;

		}
	}
}

void menu_inicial(elementos texto[], const int TAMANHO) {

	//Menu inicial do programa

	int escolha_menu = 0;

	while (escolha_menu != 4) {

		int colisao = 0;
		system("cls");
		cout << "Escolha o tamanho do arquivo que sera aberto." << endl
			<< "1 - Para o arquivo pequeno (ate 25 palavras)" << endl
			<< "2 - Para o arquivo medio (ate 250 palavras)" << endl
			<< "3 - Para o arquivo grande (ate 1000 palavras)" << endl
			<< "4 - Para fechar o programa" << endl
			<< "Digite sua opcao: ";
		cin >> escolha_menu;

		switch (escolha_menu) {
		case 1:
			metodo_hash(texto, escolha_menu, TAMANHO);
			break;
		case 2:
			metodo_hash(texto, escolha_menu, TAMANHO);
			break;
		case 3:
			metodo_hash(texto, escolha_menu, TAMANHO);
			break;
		case 4:
			break;
		default:
			system("cls");
			cout << "Opcao invalida" << endl;
			system("pause");
			break;
		}
	}
}