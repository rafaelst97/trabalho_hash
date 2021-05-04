// trabalho_hash.cpp : Este arquivo contém a função 'main'. A execução do programa começa e termina ali.
//

#include <iostream>
#include <stdio.h>  
#include <stdlib.h>
#include <string> //Biblioteca para trabalhar com strings
#include <fstream> //Biblioteca para operações com arquivos
#include <locale.h> //Biblioteca para utilização de acentos

using namespace std;

int main()
{
    setlocale(LC_ALL, "pt_BR.UTF - 8"); //Localização para identificar acentos da língua portuguesa

    ifstream arquivo_teste;
    string linha;

    arquivo_teste.open("arquivo_teste.txt"); //Verifica se o arquivo foi aberto
    if (arquivo_teste.is_open()) {
        while (getline(arquivo_teste, linha)) { // Função para exibir texto do arquivo na tela
            cout << linha << endl;
        }
    }
    else {
        cout << "Não foi possível abrir o arquivo" << endl; //Mensagem de erro para o caso do arquivo não ter sido aberto
    }

    arquivo_teste.close();
}