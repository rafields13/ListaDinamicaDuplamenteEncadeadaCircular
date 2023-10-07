#include <iostream>
#include <conio.h>

struct LISTA {
    int numero;
    LISTA *proximo;
    LISTA *anterior;
};

void inserirInicio(LISTA *&inicio, LISTA *&fim) {
    std::cout << "Digite o número a ser inserido no início da lista:";
    auto *novo = new LISTA();
    std::cin >> novo->numero;

    if (inicio == nullptr) {
        inicio = novo;
        fim = novo;
        novo->proximo = inicio;
        novo->anterior = inicio;
    } else {
        novo->proximo = inicio;
        inicio->anterior = novo;
        novo->anterior = fim;
        fim->proximo = novo;
        inicio = novo;
    }

    std::cout << "Número inserido no início da lista com sucesso!";
}

void inserirFim(LISTA *&inicio, LISTA *&fim) {
    std::cout << "Digite o número a ser inserido no fim da lista:";
    auto *novo = new LISTA();
    std::cin >> novo->numero;

    if (inicio == nullptr) {
        inicio = novo;
        fim = novo;
        novo->proximo = inicio;
        novo->anterior = inicio;
    } else {
        fim->proximo = novo;
        novo->anterior = fim;
        fim = novo;
        fim->proximo = inicio;
        inicio->anterior = fim;
    }

    std::cout << "Número inserido no fim da lista com sucesso!";
}

void consultarInicioFim(LISTA *inicio) {
    if (inicio == nullptr)
        std::cout << "A lista está vazia!";
    else {
        std::cout << "\nConsultando a lista do início ao fim...\n";
        LISTA *auxiliar = inicio;

        do {
            std::cout << auxiliar->numero << " ";
            auxiliar = auxiliar->proximo;
        } while (auxiliar != inicio);
    }
}

void consultarFimInicio(LISTA *fim) {
    if (fim == nullptr)
        std::cout << "A lista está vazia!";
    else {
        std::cout << "\nConsultando a lista do fim ao início...\n";
        LISTA *auxiliar = fim;

        do {
            std::cout << auxiliar->numero << " ";
            auxiliar = auxiliar->anterior;
        } while (auxiliar != fim);
    }
}

void removerElemento(LISTA *&inicio, LISTA *&fim) {
    if (inicio == nullptr)
        std::cout << "A lista está vazia!";
    else {
        std::cout << "\nDigite o elemento a ser removido:";
        int number;
        std::cin >> number;
        LISTA *auxiliar = inicio;
        int achou = 0;
        int quantidade = 0;
        auxiliar = inicio;

        do {
            quantidade++;
            auxiliar = auxiliar->proximo;
        } while (auxiliar != inicio);

        int elemento = 1;

        do {
            if (inicio == fim && inicio->numero == number) {
                inicio = nullptr;
                delete (inicio);
                achou++;
            } else {
                if (auxiliar->numero == number) {
                    achou++;
                    if (auxiliar == inicio) {
                        inicio = auxiliar->proximo;
                        inicio->anterior = fim;
                        fim->proximo = inicio;
                        delete (auxiliar);
                        auxiliar = inicio;
                    } else if (auxiliar == fim) {
                        fim = fim->anterior;
                        fim->proximo = inicio;
                        inicio->anterior = fim;
                        delete (auxiliar);
                        auxiliar = nullptr;
                    } else {
                        auxiliar->anterior->proximo = auxiliar->proximo;
                        auxiliar->proximo->anterior = auxiliar->anterior;
                        LISTA *auxiliar2;
                        auxiliar2 = auxiliar;
                        auxiliar = auxiliar->proximo;
                        delete (auxiliar2);
                    }
                } else
                    auxiliar = auxiliar->proximo;
            }

            elemento++;
        } while (elemento <= quantidade);

        if (achou == 0)
            std::cout << "Número não encontrado.";
        else if (achou == 1)
            std::cout << "Número removido uma vez.";
        else
            std::cout << "Número removido " << achou << " vezes.";
    }
}

void esvaziarLista(LISTA *&inicio, LISTA *&fim) {
    if (inicio == nullptr)
        std::cout << "A lista está vazia!";
    else {
        LISTA *auxiliar = inicio;

        if (inicio == fim) {
            inicio = nullptr;
            fim = nullptr;
            delete (auxiliar);
        } else {
            do {
                inicio = inicio->proximo;
                delete (auxiliar);
                auxiliar = inicio;
            } while (auxiliar != fim);

            delete (fim);
            inicio = nullptr;
            fim = nullptr;
        }

        std::cout << "A lista esvaziada com sucesso!";
    }
}

int main() {
    LISTA *inicio = nullptr;
    LISTA *fim = nullptr;

    int opcao;

    do {
        std::cout << "\nMenu de opções\n";
        std::cout << "1 - Inserir no início da lista\n";
        std::cout << "2 - Inserir no fim da lista\n";
        std::cout << "3 - Consultar a lista do início ao fim\n";
        std::cout << "4 - Consultar a lista do fim ao início\n";
        std::cout << "5 - Remover da lista\n";
        std::cout << "6 - Esvaziar a lista\n";
        std::cout << "7 - Sair\n";

        std::cout << "\nDigite sua opção:";
        std::cin >> opcao;

        if (opcao < 1 || opcao > 7)
            std::cout << "Opção inválida!";

        switch (opcao) {
            case 1:
                inserirInicio(inicio, fim);
                break;
            case 2:
                inserirFim(inicio, fim);
                break;
            case 3:
                consultarInicioFim(inicio);
                break;
            case 4:
                consultarFimInicio(fim);
                break;
            case 5:
                removerElemento(inicio, fim);
                break;
            case 6:
                esvaziarLista(inicio, fim);
                break;
            case 7:
                break;
            default:
                std::cout << "Opção inválida!";
                break;
        }

        getch();
    } while (opcao != 7);
}
