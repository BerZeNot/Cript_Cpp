#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void getInterface(int interface)
{
    // 0 = interface do menu
    // 1 = interface da função de criptografar
    // 2 = interface da função de descriptografar

    if(interface==0)
    {
        printf("--------------------------------------------\n");
        printf("|              CRIPTOGRAFADOR              |\n");
        printf("|------------------------------------------|\n");
        printf("| 1 - Criptografar                         |\n");
        printf("| 2 - Descriptografar                      |\n");
        printf("| 3 - Sair                                 |\n");
        printf("|------------------------------------------|\n");
    }

    if(interface==1)
    {
        printf("--------------------------------------------\n");
        printf("|              CRIPTOGRAFAR                |\n");
        printf("|------------------------------------------|\n");
    }

    if(interface==2)
    {
        printf("--------------------------------------------\n");
        printf("|              DESCRIPTOGRAFAR             |\n");
        printf("|------------------------------------------|\n");
    }
}

void criptografar()
{
    system("cls");
    getInterface(1);

    char texto[1000];
    char palavraChave[20];
    setbuf(stdin, NULL);
    printf("Digite o texto para criptografar: \n");
    scanf("%[^\n]s", texto);
    setbuf(stdin, NULL);
    printf("Digite a palavra chave:\n");
    scanf("%s", palavraChave);

    int controller=1;
    for(int i = 0; i < strlen(texto); i++)
    {
        texto[i] = texto[i] + palavraChave[controller];
        controller++;
        if(controller==strlen(palavraChave))
        {
            controller = 0;
        }
    }
    printf("%s\n", texto);
    system("pause");

}

void descriptografar()
{
    system("cls");
    getInterface(2);

    char texto[1000];
    char palavraChave[20];
    setbuf(stdin, NULL);
    printf("Digite o texto para descriptografar: \n");
    scanf("%[^\n]s", texto);
    setbuf(stdin, NULL);
    printf("Digite a palavra chave:\n");
    scanf("%s", palavraChave);

    int controller=1;
    for(int i = 0; i < strlen(texto); i++)
    {
        texto[i] = texto[i] - palavraChave[controller];
        controller++;
        if(controller==strlen(palavraChave))
        {
            controller = 0;
        }
    }
    printf("%s\n", texto);
    system("pause");

}

void menu()
{
    int opt;
    while(true)
    {
        system("cls");
        getInterface(0);
        printf("Escolha uma opcao: ");
        scanf("%d", &opt);
        if(opt==1)
        {
            criptografar();
        }
        else if(opt==2)
        {
            descriptografar();
        }
        else if(opt==3)
        {
            return;
        }
        else
        {
            printf("Opcao Invalida!\n");
            system("pause");
        }
    }
}

int main()
{
    menu();
    return 0;
}
