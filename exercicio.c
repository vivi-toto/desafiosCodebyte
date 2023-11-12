#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>

struct Elemento {
    char letra;   // dado
    char data[11]; // data (assumindo formato "dd/mm/yyyy" com 10 caracteres + nulo)
    char hora[9]; // hora (assumindo formato "hh:mm:ss" com 8 caracteres + nulo)
    Elemento* anterior;
};

struct Pilha {
    Elemento* topo;
};

Elemento* aux;

Pilha* criarPilha() {
    Pilha* pilhaP = (Pilha*)malloc(sizeof(Pilha));
    pilhaP->topo = NULL;
    return pilhaP;
}

int estaVazia(Pilha* pilhaP) {
    if (pilhaP->topo == NULL) {
        return 1;
    }
    else {
        return 0;
    }
}

void inserir(Pilha* pilhaP) {
    Elemento* novo = (Elemento*)malloc(sizeof(Elemento));
    getchar();
    printf("Informe uma letra: ");
    scanf(" %c", &novo->letra);
    printf("Informe a data (dd/mm/yyyy): ");
    scanf("%10s", novo->data);
    printf("Informe a hora (hh:mm:ss): ");
    scanf("%8s", novo->hora);

    novo->anterior = pilhaP->topo;
    pilhaP->topo = novo;
}

void remover(Pilha* pilhaP) {
    if (estaVazia(pilhaP)) {
        printf("Pilha esta vazia!\n");
    }
    else {
        aux = pilhaP->topo;
        pilhaP->topo = aux->anterior;
        free(aux);
        printf("Elemento removido com sucesso!\n");
    }
}

void listar(Pilha* pilhaP) {
    if (estaVazia(pilhaP)) {
        printf("Pilha esta vazia!\n");
    }
    else {
        aux = pilhaP->topo;
        do {
            printf("Letra: %c, Data: %s, Hora: %s\n", aux->letra, aux->data, aux->hora);
            aux = aux->anterior;
        } while (aux != NULL);
        system("pause");
    }
}

int main() {
    Pilha* pilhaP = criarPilha();
    int op;

    do {
        printf("1 - Inserir\n");
        printf("2 - Remover\n");
        printf("3 - Listar\n");
        printf("4 - Sair\n");
        scanf("%d", &op);

        switch (op) {
        case 1:
            system("cls");
            inserir(pilhaP);
            system("pause");
            system("cls");
            break;

        case 2:
            system("cls");
            remover(pilhaP);
            system("pause");
            system("cls");
            break;

        case 3:
            system("cls");
            listar(pilhaP);
            system("pause");
            system("cls");
            break;

        case 4:
            system("cls");
            printf("Saindo do sistema\n");
            system("pause");
            system("cls");
            break;
        }
    } while (op != 4);

    free(pilhaP);
    return 0;
}
