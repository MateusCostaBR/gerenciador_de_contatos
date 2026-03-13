#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "contatos.h"

int escolha;
int i;

void cadastrar(struct cadastro contatos[], int *total){
    int valido = 0;
    // verifica se atingiu o maximo de cadastro
    if(*total >= MAX){
        printf("Você atingiu o limite de cadastros\n\nPressione qualquer tecla para sair!\n");
        system("pause");
        system("cls");
        return;
    }
    printf("CADASTRAR\n\n");
	// nome
    printf("Nome: ");
    fgets(contatos[*total].nome, 50, stdin);
    contatos[*total].nome[strcspn(contatos[*total].nome, "\n")] = '\0';
    // telefone com verificação de caract.
    while(valido == 0){
        printf("Telefone: ");
        fgets(contatos[*total].telefone, 20, stdin);
        contatos[*total].telefone[strcspn(contatos[*total].telefone, "\n")] = '\0';
        if(strlen(contatos[*total].telefone) >= 8 && strlen(contatos[*total].telefone) <= 11){
            valido = 1;
        }else{
            printf("\nNúmero inválido!, Tente novamente!\n\n");
        }
    }
    valido = 0;
    // email com verificaoção de dominio
    while(valido == 0){
        printf("Email: ");
        fgets(contatos[*total].email, 50, stdin);
        contatos[*total].email[strcspn(contatos[*total].email, "\n")] = '\0';
        if(strstr(contatos[*total].email, "@gmail.com") || 
		   strstr(contatos[*total].email, "@outlook.com") ||
		   strstr(contatos[*total].email, "@hotmail.com") ||
		   strstr(contatos[*total].email, "@icloud.com") || 
		   strstr(contatos[*total].email, "@aluno.unievangelica.edu.br") || 
		   strstr(contatos[*total].email, "@unievangelica.edu.br")){
            valido = 1;
        }else{
            printf("\nEmail inválido!, Tente Novamente!\n\n");
        }
    }
    // parte final com a opção de cadastrar de novo
    (*total)++;
    system("cls");
    printf("Cadastro Finalizado!\n\n1-Fazer mais um cadastro\n2-Sair\nEscolha: ");
    scanf("%d", &escolha);
    getchar();
    system("cls");
    if(escolha == 1){
        cadastrar(contatos, total);
    }
}

void listar(struct cadastro contatos[], int total){
	printf("LISTA\n");
	// verifica se tem cadastro
	if(total == 0){
		printf("\nNenhum cadastro realizado\n");
	}
	// imprime todos
	for(i=0;i<total;i++){
		printf("\nContato %d \nNome: %s \nEmail: %s \nTelefone: %s \n", i + 1, contatos[i].nome, contatos[i].email, contatos[i].telefone);
	}
	system("pause");
	system("cls");
}

void buscar_editar_excluir(struct cadastro contatos[], int *total, int editar, int excluir){
	int confirmacao;
	int encontrado = 0;
	escolha = 0;
	// inicia o loop
	while(!(escolha == 2)){
	system("cls");
	printf("PROCURAR\n\n");
	char nome[50];
	// busca atraves do nome
	printf("Digite um nome: ");
	fgets(nome, 50, stdin);
	nome[strcspn(nome, "\n")] = '\0';
	for(i=0;i<*total;i++){
		if(strstr(contatos[i].nome, nome)){
			printf("\nContato %d \nNome: %s \nEmail: %s \nTelefone: %s \n", i + 1, contatos[i].nome, contatos[i].email, contatos[i].telefone);
			encontrado = 1;
		}
	}
	if(encontrado == 0){
		printf("Nenhum contato encontrado com esse nome!\n");
		printf("\nDeseja fazer outra busca?\n1-Sim\n2-Sair\nEscolha: ");
		scanf("%d", &escolha);
		getchar();
	}else{
		if(editar == 0 && excluir == 0){
		printf("\nVocê deseja procurar por outro nome?\n1-Sim\n2-Sair\nEscolha: ");
		scanf("%d", &escolha);
		getchar();
	}
	// editar(se a pessoa veio pela opção editar)
	if(editar == 1){
		printf("\nQual contato você deseja editar?\nEscolha: ");
		scanf("%d", &escolha);
		getchar();
		system("cls");
		printf("Antigo:\nContato %d \nNome: %s \nEmail: %s \nTelefone: %s \n\nNovo:\n", escolha, contatos[escolha - 1].nome, contatos[escolha - 1].email, contatos[escolha - 1].telefone);
		//nome
		printf("Nome: ");
		fgets(contatos[escolha - 1].nome, 50, stdin);
		contatos[escolha - 1].nome[strcspn(contatos[escolha - 1].nome, "\n")] = '\0';
		//telefone
		printf("Telefone: ");
		fgets(contatos[escolha - 1].telefone, 20, stdin);
		contatos[escolha - 1].telefone[strcspn(contatos[escolha - 1].telefone, "\n")] = '\0';
		//email
		printf("Email: ");
		fgets(contatos[escolha - 1].email, 50, stdin);
		contatos[escolha - 1].email[strcspn(contatos[escolha - 1].email, "\n")] = '\0';
		system("cls");
		printf("Atualizado com sucesso!\n");
		printf("\nDeseja atualizar mais algum contato?\n1-Sim\n2-Não\nEscolha: ");
		scanf("%d", &escolha);
		getchar();
	}
	// excluir(se a pessoa veio pela opção excluir)
	if(excluir == 1){
		printf("\nQual contato você deseja excluir? ");
		scanf("%d", &escolha);
		getchar();
		system("cls");
		printf("\nContato %d \nNome: %s \nEmail: %s \nTelefone: %s \n\nTem certeza que deseja excluir este cadastro?\n1-sim\n2-não\nEscolha: ", escolha, contatos[escolha - 1].nome, contatos[escolha - 1].email, contatos[escolha - 1].telefone);
		scanf("%d", &confirmacao);
		getchar();
		if(confirmacao == 1){
			for(i=escolha-1;i<*total-1;i++){
				contatos[i] = contatos[i+1];
			}
			(*total)--;
			system("cls");
			printf("Contato excluido com sucesso!\n\nDeseja excluir mais um contato?\n1-Sim\n2-Não\nEscolha: ");
			scanf("%d", &escolha);
			getchar();
		}else if(confirmacao == 2){
			printf("Exclusão cancelada!\n\nDeseja excluir outro contato?\n1-Sim\n2-Não\nEscolha: ");
			scanf("%d", &escolha);
			getchar();
		}
	}
	}
	system("cls");
	}
}

int contarGmail(struct cadastro contatos[], int total){
    if(total == 0){
        return 0;
    }
    if(strstr(contatos[total-1].email, "@gmail")){
        return 1 + contarGmail(contatos, total-1);
    }
    return contarGmail(contatos, total-1);
}

void estatisticas(struct cadastro contatos[], int total){
	int gmail;
	int capacidade = 0;
	gmail = contarGmail(contatos, total);
	capacidade = MAX - total;
	printf("ESTATISTICAS\n\n");
	printf("Numero de contatos cadastrados: %d\n", total);
	printf("Espaço livre: %d\n", capacidade);
	printf("Contatos que usam Gmail: %d\n", gmail);
	system("pause");
	system("cls");
}

void salvar(struct cadastro contatos[], int total){
	FILE *arquivo = fopen("contatos.txt", "w");
	if(arquivo == NULL){
		printf("Erro ao abrir arquivo!\n");
		return;
	}
	for(i = 0; i < total; i++){
	    fprintf(arquivo,"%s;%s;%s\n", contatos[i].nome, contatos[i].telefone, contatos[i].email);
	}
	fclose(arquivo);
}

void carregar(struct cadastro contatos[], int *total){
	FILE *arquivo = fopen("contatos.txt", "r");
	if(arquivo == NULL){
		return;
	}
	*total = 0;
	while(fscanf(arquivo,"%49[^;];%19[^;];%49[^\n]\n", contatos[*total].nome, contatos[*total].telefone, contatos[*total].email) == 3){
		(*total)++;
	}
	fclose(arquivo);
}

