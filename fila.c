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
    printf("\n Digite um número para armazenar na Fila: ");
    scanf("%d", &numeroDigitado);
    if (*cabeca == NULL)     /* se ainda n�o existe nenhum n� na lista */
    {
        /* cria o n� cabeca, que � um ponteiro para o primeiro elemento da lista */
        *cabeca = (TNo *) malloc(sizeof(TNo));
        (*cabeca)->valor = numeroDigitado;
        (*cabeca)->proximo = NULL;
    }
    else
    {
        /* Se ja existem elementos na lista, deve percorre-la ate' o seu final e inserir o novo elemento */
        noatual = *cabeca;

        while(noatual->proximo != NULL)
            noatual = noatual->proximo;    /* Ao final do while, noatual aponta para o ultimo no */

        novono = (TNo *) malloc(sizeof(TNo));/* Aloca memoria para o novo no */
        novono->valor = numeroDigitado;
        novono->proximo = NULL;
        noatual->proximo = novono;     /* Faz o ultimo no apontar para o novo no */
    }
}

void listar(TNo *noatual)
{
    int i=0;
    while( noatual != NULL)    /* Enquanto nao chega no fim da lista */
    {
        i++;
        printf("Elemento numero %d - Valor: %d\n", i, noatual->valor);
        noatual = noatual->proximo;     /* Faz noatual apontar para o proximo no */
    }
}

char menu()
{
    char opcao;
    printf("1 -> Enfileirar um novo número inteiro\n");
    printf("2 -> Exibir todos os elementos da fila\n");
    printf("3 -> Desenfileirar \n");
    printf("9 -> Sair do programa\n");
    printf("Opção: ");
    scanf("%c", &opcao);                /* l� a op��o do usu�rio */
    return opcao;
}

void remover(TNo** cabeca) {
    TNo *temp = *cabeca, *anterior;
    int posicaoRemover;
    
    if (temp != NULL) {
        (*cabeca) = temp->proximo;
        free(temp);
        return;
    } else {
        printf("Fila Vazia!");
        return;
    }

    anterior->proximo = temp->proximo;
    free(temp);
}

void inserirPre(TNo **cabeca, int value)
{
    TNo *noatual, *novono;
    int v = value;
    if (*cabeca == NULL)     /* se ainda n�o existe nenhum n� na lista */
    {
        /* cria o n� cabeca, que � um ponteiro para o primeiro elemento da lista */
        *cabeca = (TNo *) malloc(sizeof(TNo));
        (*cabeca)->valor = v;
        (*cabeca)->proximo = NULL;
    }
    else
    {
        /* Se ja existem elementos na lista, deve percorre-la ate' o seu final e inserir o novo elemento */
        noatual = *cabeca;

        while(noatual->proximo != NULL)
            noatual = noatual->proximo;    /* Ao final do while, noatual aponta para o ultimo no */

        novono = (TNo *) malloc(sizeof(TNo));/* Aloca memoria para o novo no */
        novono->valor = v;
        novono->proximo = NULL;
        noatual->proximo = novono;     /* Faz o ultimo no apontar para o novo no */
    }
}
