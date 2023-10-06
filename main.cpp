#include <stdio.h>
#include <stdlib.h>

// Defini��o da estrutura de n� da lista circular duplamente encadeada
typedef struct No {
    int dado;
    struct No* proximo;
    struct No* anterior;
} No;

// Fun��o para inicializar uma lista vazia
No* inicializarLista(void) {
    return NULL;
}

// Fun��o para inserir um elemento no in�cio da lista
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

// Fun��o para inserir um elemento no final da lista
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

// Fun��o para remover um elemento da lista com base em um valor espec�fico
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

// Fun��o para buscar um elemento na lista
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

// Fun��o para exibir todos os elementos da lista
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

int main(void) {
    No* lista = inicializarLista(void);
    int escolha, valor;

    do {
        printf("X------------------------------X\n");
        printf("| 1 - Inserir no In�cio         |\n");
        printf("| 2 - Inserir no Final          |\n");
        printf("| 3 - Remover Elemento          |\n");
        printf("| 4 - Buscar Elemento           |\n");
        printf("| 5 - Exibir Lista              |\n");
        printf("| 6 - Sair                      |\n");
        printf("X------------------------------X\n");

        printf("Digite uma op��o: ");
        scanf("%d", &escolha);

        switch (escolha) {
            case 1:
                printf("Digite o valor para inserir no in�cio: ");
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
                    printf("Valor n�o encontrado na lista.\n");
                }
                break;
            case 5:
                imprimirLista(lista);
                break;
            case 6:
                printf("Encerrando o programa.\n");
                break;
            default:
                printf("Op��o inv�lida. Por favor, tente novamente.\n");
                break;
        }
    } while (escolha != 6);

    // Liberar mem�ria alocada
    No* atual = lista;
    while (atual != NULL) {
        No* temp = atual;
        atual = atual->proximo;
        free(temp);
    }

    return 0;
}

