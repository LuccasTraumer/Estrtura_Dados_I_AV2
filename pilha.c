// Author: Lucas Jesus
// System Information Curse on 3º Period

#include <stdio.h>
#include <stdlib.h>


typedef struct tipo_no
{
    int valor;
    struct tipo_no *proximo;
} TNo;

void inserir(TNo **cabeca);
void listar(TNo *cabeca);
char menu();
void remover(TNo **cabeca);
void inserirPre(TNo **cabeca, int value);

void main()
{
    TNo *cabeca = NULL;
    char opcao;                         /* caracter para receber a op��o do usu�rio */
    do
    {
        opcao = menu();
        switch(opcao)
        {
        case '1':
            inserir(&cabeca);
            break;
        case '2':
            listar(cabeca);
            break;
        case '3':
            remover(&cabeca);
            break;
        case '4':
            inserirPre(&cabeca, 10);
            inserirPre(&cabeca, 20);
            inserirPre(&cabeca, 30);
            break;
        case '9':
            printf("\n\nSaindo do programa ...\n\n");
            break;
        default:
            printf("\n\nOpção não válida\n\n");
        }
        fflush(stdin);                  /* limpa o buffer de entrada */
    }
    while (opcao != '9');
}

void inserir(TNo **cabeca)
{
    TNo *noatual, *novono;
    int numeroDigitado;
    printf("\n Digite um número para armazenar na Pilha: ");
    scanf("%d", &numeroDigitado);

    if (numeroDigitado == -666) {
        printf("Este Valor é Invalido para inclusão, pois é utilizado pelo sistema!");
        return;
    }

    if (*cabeca == NULL){
        *cabeca = (TNo *) malloc(sizeof(TNo));
        (*cabeca)->valor = numeroDigitado;
        (*cabeca)->proximo = NULL;
    }
    else {
        noatual = *cabeca;

        while(noatual->proximo != NULL)
            noatual = noatual->proximo;

        if (noatual->valor == -666) {
            noatual->valor = numeroDigitado;
            noatual->proximo = NULL;
        } else {
            novono = (TNo *) malloc(sizeof(TNo));
            novono->valor = numeroDigitado;
            novono->proximo = NULL;
            noatual->proximo = novono;
        }
    }
}

void listar(TNo *noatual){
    int i=0;
    while(noatual != NULL && noatual->valor != -666)
    {
        i++;
        printf("Elemento numero %d - Valor: %d\n", i, noatual->valor);
        noatual = noatual->proximo;
    }
}

char menu()
{
    char opcao;
    printf("1 -> Empilhar um novo número inteiro\n");
    printf("2 -> Exibir todos os elementos da pilha\n");
    printf("3 -> Desempilhar \n");
    printf("9 -> Sair do programa\n");
    printf("Opção: ");
    scanf("%c", &opcao);
    return opcao;
}

void remover(TNo **cabeca) {
    int tamanhoPilha = 0;
    TNo *temp = *cabeca;
    while(temp != NULL) {
        temp = temp->proximo;
        tamanhoPilha = tamanhoPilha +1;
    }

    int auxTamanho = 0;
    TNo *aux = *cabeca;

    while(tamanhoPilha-1 != auxTamanho) {
        auxTamanho = auxTamanho +1;
        aux = aux->proximo;
    }
    // free(aux);
    // aux = NULL;
    aux->valor = -666;
}

void inserirPre(TNo **cabeca, int value)
{
    TNo *noatual, *novono;
    int v = value;
    if (*cabeca == NULL)
    {
        *cabeca = (TNo *) malloc(sizeof(TNo));
        (*cabeca)->valor = v;
        (*cabeca)->proximo = NULL;
    }
    else {
        noatual = *cabeca;

        while(noatual->proximo != NULL)
            noatual = noatual->proximo;

        novono = (TNo *) malloc(sizeof(TNo));
        novono->valor = v;
        novono->proximo = NULL;
        noatual->proximo = novono;
    }
}
