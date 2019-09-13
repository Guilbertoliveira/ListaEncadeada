#include <stdio.h>
#include <stdlib.h>





typedef struct no
{
    int codigo;
    char nome[15];
    struct no *next;
}no;

struct no *corrente, *auxiliar, *inicio,*auxiliar2;


void enterdata()
{
    system("cls");
    printf("Infome o codigo \n");
    scanf("%d", &corrente->codigo);
    printf("Informe o nomee \n");
    scanf("%s", &corrente->nome);
}

int insert(no**lista)
{
    if(inicio==NULL)
    {

        corrente = (no*)malloc(sizeof(no));
        corrente->next = NULL;
        auxiliar = corrente;
        inicio = corrente;
        enterdata();
    }
    else{
        corrente = (no*)malloc(sizeof(no));
        auxiliar->next = corrente;
        corrente->next = NULL;
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
        auxiliar = inicio;
        while (auxiliar != NULL)
        {
            printf("\n\nCodigo: %d \n", auxiliar -> codigo);
            printf("Nome: %s \n", auxiliar -> nome);
            auxiliar = auxiliar -> next;

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
        auxiliar = inicio;
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
    auxiliar = auxiliar -> next;
    }

    }
    system("pause");
    }
}


int quanto()
{
    int i=0;
    int contador = 0;
    printf("\nQuantos dados deseja inserir\n");
    scanf("%i", &contador);
    system("cls");
    while(i<contador)
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
        auxiliar = inicio;
        scanf("%i", &quale);
        while (auxiliar != NULL)
        {

            if (inicio->codigo == quale)
            {
                inicio = auxiliar->next;
                free(auxiliar);
                printf("o inicio foi movido");
            }


            if (auxiliar->codigo == quale)
            {
                auxiliar2->next = auxiliar->next;
                free(auxiliar);


            }

            else {
                auxiliar2 = auxiliar;
                auxiliar = auxiliar -> next;

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
        auxiliar = inicio;
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
            auxiliar = auxiliar -> next;
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
