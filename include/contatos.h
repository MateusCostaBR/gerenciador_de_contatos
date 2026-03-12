#ifndef CONTATOS_H
#define CONTATOS_H
#define MAX 100

struct cadastro {
	char nome[50];
	char telefone[20];
	char email[50];
};

void cadastrar(struct cadastro contatos[], int *total);
void listar(struct cadastro contatos[], int total);
void buscar_editar_excluir(struct cadastro contatos[], int *total, int editar, int excluir);
int contarGmail(struct cadastro contatos[], int total);
void estatisticas(struct cadastro contatos[], int total);
void salvar(struct cadastro contatos[], int total);
void carregar(struct cadastro contatos[], int *total);

#endif
