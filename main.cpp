#include <stdio.h>
#include <stdlib.h>

// Definição da estrutura de nó da lista circular duplamente encadeada
typedef struct No {
    int dado;
    struct No* proximo;
    struct No* anterior;
} No;

// Função para inicializar uma lista vazia
No* inicializarLista() {
    return NULL;
}

// Função para inserir um elemento no início da lista
No* inserirNoInicio(No* lista, int valor) {
    No* novoNo = (No*)malloc(sizeof(No));
    novoNo->dado = valor;

    if (lista == NULL) {
        novoNo->proximo = novoNo;
        novoNo->anterior = novoNo;
    } else {
        novoNo->proximo = lista;
        novoNo->anterior = lista->anterior;
        lista->anterior->proximo = novoNo;
        lista->anterior = novoNo;
    }

    return novoNo;
}

// Função para inserir um elemento no final da lista
No* inserirNoFinal(No* lista, int valor) {
    No* novoNo = (No*)malloc(sizeof(No));
    novoNo->dado = valor;

    if (lista == NULL) {
        novoNo->proximo = novoNo;
        novoNo->anterior = novoNo;
    } else {
        novoNo->proximo = lista;
        novoNo->anterior = lista->anterior;
        lista->anterior->proximo = novoNo;
        lista->anterior = novoNo;
    }

    return lista;
}

// Função para remover um elemento da lista com base em um valor específico
No* removerElemento(No* lista, int valor) {
    if (lista == NULL) {
        return NULL;
    }

    No* atual = lista;
    do {
        if (atual->dado == valor) {
            No* proximoNo = atual->proximo;
            No* noAnterior = atual->anterior;
            noAnterior->proximo = proximoNo;
            proximoNo->anterior = noAnterior;

            if (atual == lista) {
                lista = proximoNo;
            }

            free(atual);
            break;
        }

        atual = atual->proximo;
    } while (atual != lista);

    return lista;
}

// Função para buscar um elemento na lista
No* buscarElemento(No* lista, int valor) {
    No* atual = lista;
    if (atual == NULL) {
        return NULL;
    }

    do {
        if (atual->dado == valor) {
            return atual;
        }

        atual = atual->proximo;
    } while (atual != lista);

    return NULL;
}

// Função para exibir todos os elementos da lista
void imprimirLista(No* lista) {
    No* atual = lista;
    if (atual == NULL) {
        printf("Lista vazia.\n");
        return;
    }

    printf("Lista Atual: ");
    do {
        printf("%d ", atual->dado);
        atual = atual->proximo;
    } while (atual != lista);

    printf("\n");
}

int main() {
    No* lista = inicializarLista();
    int escolha, valor;

    do {
        printf("X------------------------------X\n");
        printf("| 1 - Inserir no Início         |\n");
        printf("| 2 - Inserir no Final          |\n");
        printf("| 3 - Remover Elemento          |\n");
        printf("| 4 - Buscar Elemento           |\n");
        printf("| 5 - Exibir Lista              |\n");
        printf("| 6 - Sair                      |\n");
        printf("X------------------------------X\n");

        printf("Digite uma opção: ");
        scanf("%d", &escolha);

        switch (escolha) {
            case 1:
                printf("Digite o valor para inserir no início: ");
                scanf("%d", &valor);
                lista = inserirNoInicio(lista, valor);
                break;
            case 2:
                printf("Digite o valor para inserir no final: ");
                scanf("%d", &valor);
                lista = inserirNoFinal(lista, valor);
                break;
            case 3:
                printf("Digite o valor para remover: ");
                scanf("%d", &valor);
                lista = removerElemento(lista, valor);
                break;
            case 4:
                printf("Digite o valor para buscar: ");
                scanf("%d", &valor);
                No* encontrado = buscarElemento(lista, valor);
                if (encontrado != NULL) {
                    printf("Valor encontrado na lista.\n");
                } else {
                    printf("Valor não encontrado na lista.\n");
                }
                break;
            case 5:
                imprimirLista(lista);
                break;
            case 6:
                printf("Encerrando o programa.\n");
                break;
            default:
                printf("Opção inválida. Por favor, tente novamente.\n");
                break;
        }
    } while (escolha != 6);

    // Liberar memória alocada
    No* atual = lista;
    while (atual != NULL) {
        No* temp = atual;
        atual = atual->proximo;
        free(temp);
    }

    return 0;
}
