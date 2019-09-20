#include <stdio.h>
#include <stdlib.h>







typedef struct no
{
    int codigo;
    char nome[15];
    struct no *next, *back;
}no;

struct no *corrente, *auxiliar, *inicio,*auxiliar2, *fim;


void enterdata()
{
    system("cls");
    printf("Infome o codigo \n");
    scanf("%d", &corrente->codigo);
    printf("Informe o nomee \n");
    scanf("%s", &corrente->nome);
}

int insert(no**lista) // essa é a duplamente encadeada
{
    if(inicio==NULL)
    {

        corrente = (no*)malloc(sizeof(no));
        corrente->next = NULL;
        corrente->back = NULL;
        auxiliar = corrente;
        inicio = corrente;
        fim = corrente;
        enterdata();
    }
    else{
        corrente = (no*)malloc(sizeof(no));
        auxiliar->next = corrente;
        corrente->back = auxiliar;
        corrente->next = NULL;
        fim = corrente;
        auxiliar = corrente;
        enterdata();

    }
}

int exibir(no**lista) //coloooooocar no
{
    if (inicio == NULL)
    {
        printf("lista vazia");
        system("pause");
    }
    else{
        auxiliar = fim;
        while (auxiliar != NULL)
        {
            printf("\n\nCodigo: %d \n", auxiliar -> codigo);
            printf("Nome: %s \n", auxiliar -> nome);
            auxiliar = auxiliar -> back;

        }
        system("pause");
    }
}




int pesquisar(no**lista)
{
    if (inicio == NULL)
    {
        printf("lista vazia");
        system("pause");
    }
    else{
        int quale;
        auxiliar = fim;
        scanf("%i", &quale);
        while (auxiliar != NULL)
        {
            if (auxiliar->codigo == quale)
            {
                printf("codigo: %i", auxiliar->codigo);
                printf("nome: %s", auxiliar->nome);
                break;
            }

    else {
    auxiliar = auxiliar -> back;
    }

    }
    system("pause");
    }
}


int quanto()
{
    int i=1;
    int contador = 0;
    printf("\nQuantos dados deseja inserir\n");
    scanf("%i", &contador);
    system("cls");
    while(i<=contador)
    {
         insert(&inicio);
         i++;
    }
}


int remover(no**lista)
{
     if (inicio == NULL)
    {
        printf("lista vazia");
        system("pause");
    }
    else{
        int quale;
        auxiliar = fim;
        scanf("%i", &quale);
        while (auxiliar != NULL)
        {
            if (auxiliar->codigo == quale)
            {
                auxiliar2->back = auxiliar->back;
                free(auxiliar);


            }

            else {
                auxiliar2 = auxiliar;
                auxiliar = auxiliar -> back;

            }

    }
    system("pause");
    }
}


int alterar(no**lista)
{
    if (inicio == NULL)
    {
        printf("lista vazia");
        system("pause");
    }
    else{
        int quale;
        auxiliar = fim;
        printf("\n\nInforme o numero do codigo que deseja alterar: ");
        scanf("%i", &quale);
        while (auxiliar != NULL)
        {
            if (auxiliar->codigo == quale)
            {
                printf("digite o novo codigo \n");
                scanf("%d", &auxiliar->codigo);
                printf("digite o novo nome \n");
                scanf("%s", &auxiliar->nome);
                system("pause");
            }

            else {
            auxiliar = auxiliar -> back;
            }

    }
    }





}




int main()
{

    corrente = NULL;
    auxiliar = NULL;
    inicio = NULL;
    auxiliar2 = NULL;
    int op;
    do{
        system("cls");
        printf("\n[1] - Inserir registro na Lista");
        printf("\n[2] - Exibir registro da Lista");
        printf("\n[3] - Pesquisar registro da Lista");
        printf("\n[4] - Remover registro da Lista");
        printf("\n[5] - Alterar registro da Lista");
        printf("\n[6] - Sair do Sistema");
        printf("\n\n");
        printf("Digite a opcao: ");
        scanf("%d",&op);
        switch(op){

            case 1:
                quanto();
                break;
            case 2:
                exibir(&inicio);
                break;
            case 3:
                pesquisar(&inicio);
                break;
            case 4:
                remover(&inicio);
                break;
            case 5:
                alterar(&inicio);
                break;
            case 6:
                system("pause");

        }
    }while(op != 6);
}
