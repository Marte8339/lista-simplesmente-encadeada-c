#include <stdio.h>
#include <stdlib.h>

typedef struct no{

    int cod;
    char nome[30];

    struct no *next;
} no;

struct no *inicio, *auxiliar, *corrente;

int main(){
    auxiliar = NULL;
    corrente = NULL;
    inicio = NULL;

    int select;

    do{
        system("cls");

        printf("\t\tSeja bem vindo");

        printf("\nSelecione uma opcao:");
        printf("\n\n1.Mostrar lista.");
        printf("\n2.Adicionar item.");
        printf("\n3.Consultar item.");
        printf("\n4.Remover item.");
        printf("\n5.Alterar item.");
        printf("\n6.Sair.");

        printf("\n\nDigite sua opcao: ");
        scanf("%d", &select);

        limparBuffer();

        switch(select){
        case 1:
            system("cls");
            mostrar_lista();
        break;
        case 2:
            system("cls");
            add();
        break;
        default:
            if(select<6){
                system("cls");
                buscar(select);
            }else{
                system("cls");
                printf("\t\t\tSaindo...\n");
            }
        }
    }
    while(select<6);
    return;
}

void limparBuffer(){
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

void add(){
    if(inicio==NULL){
        corrente = (no*)malloc(sizeof(no));
        auxiliar = corrente;
        inicio = corrente;
        corrente->next = NULL;
    }else{
        auxiliar=inicio;
        while(auxiliar->next!=NULL){
            auxiliar=auxiliar->next;
        }
        corrente = (no*)malloc(sizeof(no));
        auxiliar->next = corrente;
        auxiliar = corrente;
        corrente->next = NULL;
    }

    printf("\t\tColetando informacoes");

    printf("\nCodigo: ");
    scanf("%d", &corrente->cod);

    limparBuffer();

    printf("\nNome: ");
    gets(corrente->nome);
}

void mostrar_lista(){
    if(inicio==NULL){
        printf("\t\t\tLista vazia!!\n");
        system("pause");
    }else{
        printf("\tLista: ");
        auxiliar = inicio;

        while(auxiliar!=NULL){
            printf("\nCodigo: %d | Nome: %s", auxiliar->cod, auxiliar->nome);

            auxiliar=auxiliar->next;
        }
        printf("\n    Fim da lista\n");
        system("pause");
    }
}

void consultar(){
    printf("\nCodigo: %d | Nome: %s\n", auxiliar->cod, auxiliar->nome);
    system("pause");
}

void remover(){
    if(auxiliar == inicio){
        inicio = auxiliar->next;

        free(auxiliar);

        printf("\n\tRemovido com sucesso\n");
        system("pause");
    }else{
        corrente->next=auxiliar->next;

        free(auxiliar);

        printf("\n\tRemovido com sucesso\n");
        system("pause");
    }
}

void alterar(int opc){
    if(opc == 1){
        printf("\nDigite o novo Codigo: ");
        scanf("%d", &auxiliar->cod);
        system("pause");
    }else{
        printf("\nDigite o novo Nome: ");
        gets(auxiliar->nome);
        system("pause");
    }
}

void buscar(int select){
    int opc;

    char xnome[30];
    int xcod;

    int achou = 0;

    if(inicio==NULL){
        printf("Lista vazia!!\n");
        system("pause");
    }else{
        printf("\t\Buscando");

        printf("\nSelecione pelo o que gostaria de buscar: ");

        printf("\n\n1.Codigo");
        printf("\n2.Nome");
        printf("\n3.Voltar");

        printf("\n\nDigite sua opcao: ");
        scanf("%d", &opc);
        limparBuffer();

        switch(opc){
        case 1:
            printf("\n\nDigite o codigo: ");
            scanf("%d", &xcod);
            limparBuffer();

            auxiliar = inicio;

            while(auxiliar != NULL){
                if(xcod == auxiliar->cod){

                    achou=1;

                    switch(select){
                        case 3:
                            consultar();
                        break;
                        case 4:
                            remover();
                        break;
                        case 5:
                            alterar(opc);
                        break;
                    }

                    break;
                }else{
                    if(select==4){
                        corrente = auxiliar;
                        auxiliar = auxiliar->next;
                    }else{
                        auxiliar=auxiliar->next;
                    }
                }
            }
            if(auxiliar == NULL && achou == 0){
                printf("\nCodigo nao encontrado na lista!!\n");
                system("pause");
            }
        break;
        case 2:
            printf("\n\nDigite o nome: ");
            scanf("%s", &xnome);
            limparBuffer();

            auxiliar = inicio;

            while(auxiliar != NULL){
                if(strcmp(auxiliar->nome,xnome) == 0){

                    achou=1;

                    switch(select){
                        case 3:
                            consultar();
                        break;
                        case 4:
                            remover();
                        break;
                        case 5:
                            alterar(opc);
                        break;
                    }

                    break;
                }else{
                    if(select==4){
                        corrente = auxiliar;
                        auxiliar = auxiliar->next;
                    }else{
                        auxiliar=auxiliar->next;
                    }
                }
            }
            if(auxiliar == NULL && achou == 0){
                printf("\nNome nao encontrado na lista!!\n");
                system("pause");
            }
        break;
        }
    }
}
