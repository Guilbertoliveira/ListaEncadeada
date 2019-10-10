#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<conio.h>

typedef struct no{
char nome[10];
int codigo;
struct no*next;
}no;

struct no *auxiliar, *corrente, *inicio;

void enterData()
{
    printf("digite o nome \n");
    scanf("%s", &corrente->nome);
    printf("digite o codigo \n");
    scanf("%i", &corrente->codigo);
}






int alterar(no**lista){ // quase mesma ideia do exibir porém pegando o codígo

    if(inicio==NULL){
        printf("nao existe numero para serem alterados");
    }
    else{
            auxiliar = inicio;
            int xcodigo;
            printf("escolha o codigo que deseja alterar");
            scanf("%i", &xcodigo);

            while(auxiliar != NULL)

            {
                if(auxiliar->codigo == xcodigo)
                {
                    printf("escolha o novo codigo: ");
                    scanf("%i", &auxiliar->codigo);
                    break;
                }
                else
                {
                    auxiliar = auxiliar->next;
                }
            }

            if (auxiliar == NULL)
            {
               printf("codigo nao encontrado");
            }

    }


}






int inserir(no**lista){
    system("cls");

    if(inicio==NULL) // SE O INICIO ESTIVER VAZIO PEGAMOS UM END DE MEMORIA PRO CORRENTE
    {
        corrente= (no*) malloc(sizeof(no));
        corrente->next=NULL;
        auxiliar= corrente;
        inicio=corrente;
        enterData();

    }else{ // SE NAO PERCORREMOS A PARTIR DO INICIO ATE O CORRENTE NO FIM DA LISTA
    auxiliar=inicio;
    corrente=inicio;
    while(corrente->next!= NULL)
    {
        corrente=corrente->next;
        auxiliar=auxiliar->next;
    }
    corrente=(no*)malloc(sizeof(no)); // DEPOIS DE PERCORRER ARMAZENAMOS UM END DE MEMORIA
    auxiliar->next=corrente;
    corrente->next=NULL;
    auxiliar= corrente;
    enterData();
    }

}

int exibir (no**lista) // VERIFICA SE A LISTA ESTA VAZIA, SENAO PERCORRE A PARTIR DO INICIO COM O AUXILIAR DEIXANDO O CORRENTE INTACTO
{
    if(inicio==NULL)
    {
        printf("lista vazia");
        system("pause");
    }

    else
    {
    auxiliar = inicio;

    while (auxiliar != NULL)
    {
        printf("nome %s \n", auxiliar->nome);
        printf("codigo %i \n", auxiliar->codigo);
        auxiliar = auxiliar->next;
        system("pause");
    }
    }
}




// PESQUISAR
 // pesquisando: obs: colocar achou 1 - verifica se existe alguma informação,2- digita o codigo que deseja, 3- while, enquanto auxiliar nao for nulo verifica no if se nao achar passa pro proximo procure em todos 4 - se nao achar

int pesquisar(no**lista){
    int achou= 0;
    int xcodigo;

    if (inicio == NULL)
    {
        printf("nenhuma informação foi encontrada");
        system("pause");
    }
    else{
        printf("digite o codigo que deseja procurar");
        scanf("%i", &xcodigo);

        auxiliar = inicio;
        while(auxiliar != NULL)
        {
            if(auxiliar->codigo == xcodigo)
            {
                printf("o nome foi encontrado: %s e o numero e: %i", auxiliar->nome, auxiliar->codigo);
                achou=1;
                system("pause");
                break;
            }
            else
            {
               auxiliar = auxiliar->next;
            }

        }
        if(achou == 0)
        {
            printf("nao foi encontrado o codigo");
            system("pause");
        }
    }
}

//REMOVENDO
int remover(no**lista) // OBS: TEM VARIAVEL ACHOU removendoooooo: 1-lista vazia , 2- apenas 1, 3- inicio, 4- meio, 5- fim, 6- se nao achou
{
    int achou = 0;

    if (inicio == NULL) // primeiro se a lista está vazia
    {
        printf("lista se encontra vazia");
    }
    else
    {
        auxiliar = inicio;

        int xcodigo;


        printf("digite o numero a ser removido");
        scanf("%i", &xcodigo);

        if(auxiliar->next == NULL && auxiliar->codigo!= xcodigo) //se existe apenas 1 na memoria
        {
            printf("existe apenas um numero na memoria");

        }
        else{
            if (auxiliar->codigo == xcodigo)
            {
                inicio = inicio->next;
                free(auxiliar);
                printf("o primeiro foi removido"); // o primeiro foi removido
                achou = 1;

            }
            else
            {
                corrente = auxiliar->next;
                while (corrente != NULL)
                {
                    if (corrente->codigo == xcodigo)
                    {
                        auxiliar->next = corrente->next;
                        printf("o elemento do meio foi removido !"); // elemento do meio foi removido
                        achou = 1;
                        break;
                    }
                    else
                    {
                        auxiliar = auxiliar->next;
                        corrente = corrente->next;
                    }
                }
            }
            if (achou == 0 && corrente->codigo == xcodigo)
            {
                auxiliar->next = NULL;
                free(corrente);
                achou = 1;
                printf("ultimo elemento foi removido"); // o ultimo elemento foi removido

            }
        }
    }

    if (achou ==0)
    {
        printf("numero nao encontrado"); // numero nao encontrado

    }
}

int main()
{
    auxiliar = NULL;
    inicio = NULL;
    corrente = NULL;

    int op;
do{
    system("cls");
    printf("\n[1]-Inserir registro na lista.");
    printf("\n[2]-Exibir registro da lista.");
    printf("\n[3]-Pesquisar registro da lista.");
    printf("\n[4]-Remover registro da lista.");
    printf("\n[5]-Alterar registro da lista.");
    printf("\n[6]-Sair do sistema.\n");
    printf("\n\n");
    printf("Informe a opcao.\n");
    scanf("%d",&op);

    switch(op)
    {
    case 1:
        inserir(&inicio);
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
        break;
        default:
        system("cls");
        printf("Opcao invalida, tente novamente.. \n");
        break;
    }

  }while(op!=6);

}
