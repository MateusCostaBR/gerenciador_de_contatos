#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <windows.h>
#include "contatos.h"

int main(int argc, char *argv[]) {
	SetConsoleOutputCP(1252);
    SetConsoleCP(1252);
	setlocale(LC_ALL, "");
	int total = 0;
	int opcao = 0;
	struct cadastro contatos[MAX];
	carregar(contatos, &total);
	while(opcao !=7){
		printf("GERENCIADOR-DE-CONTATOS\n\n");
		printf("1-Cadastrar \n2-Listar \n3-Buscar por nome \n4-Editar \n5-Excluir \n6-Estatisticas \n7-Sair \n\nescolha uma opção: ");
		scanf("%d", &opcao);
		getchar();
		system("cls");
		switch(opcao){
			case 1:
				cadastrar(contatos, &total);
				break;
			case 2:
				listar(contatos, total);
				break;
			case 3:
				buscar_editar_excluir(contatos, &total, 0, 0);
				break;
			case 4:
				buscar_editar_excluir(contatos, &total, 1, 0);
				break;
			case 5:
				buscar_editar_excluir(contatos, &total, 0, 1);
				break;
			case 6:
				estatisticas(contatos, total);
				break;
			case 7:
				salvar(contatos, total);
				system("cls");
				printf("Saindo!");
				Sleep(1000);
				break;
		}
	}
	return 0;
}

