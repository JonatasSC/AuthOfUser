#include <stdio.h>
#include <locale.h>
#include <stdlib.h>
#include <string.h>

//Função de autenticação dos usuários com 2 parametros que nesse caso são nossos ponteiros.
int autenticarUsuario(const char *login, const char *senha){
    char arquivoLogin[50], arquivoSenha[50];
    FILE *arquivo;

    //Função que serve para abrir um arquivo utilizando o parametro "r" ou seja leitura.
    arquivo = fopen("UserData.txt", "r");
    if(arquivo == NULL)
    {
        printf("Erro ao abrir o arquivo\n");
        return 0;
    }

    //Percorrendo todo o arquivo linha por linha.
    while (fscanf(arquivo, "%s %s", arquivoLogin, arquivoSenha) != EOF)
    {
        //Verificando se os dados passados realmente estão gravados no arquivo.
        if(strcmp(login, arquivoLogin) == 0 && strcmp(senha, arquivoSenha) == 0)
        {
            fclose(arquivo);
            return 1;
        }
    }

    fclose(arquivo);
    return 0;
}

//Função para criar os usuários com senha e guardar em um arquivo txt.
void criarUsuario()
{
    char login[50], senha[50];
    FILE *arquivo;

    printf("Digite o nome do usuário: ");
    scanf("%s", login);

    printf("Digite a senha: ");
    scanf("%s", senha);

    /* 
    Abrindo o arquivo com o prametro "a" 
    para apendar informações ao arquivo e 
    posteriormente verificando se ele existe. 
    */
    arquivo = fopen("UserData.txt", "a");
    if (arquivo == NULL)
    {
        printf("Erro ao abrir o arquivo.");
        return;
    }
    
    //Escrevendo no arquivo utilizando a função fprintf.
    fprintf(arquivo, "%s %s\n", login, senha);
    fclose(arquivo); 

    system("clear");
    printf("Usuario %s criado com sucesso!\n", login);
}

int main ()
{
    int opcao;
    char login[50], senha[50];

    system("clear");
    do
    {
        printf("\t\t:: Bem-Vindo ::\n\n");
        printf("\t\t 1 - Cadastrar\n");
        printf("\t\t 2 - Entrar\n");
        printf("\t\t 3 - Sair\n\n");
        printf("\t\t Opção: ");
        scanf("%d", &opcao);

        getchar();

        switch (opcao)
        {
        case 1:            
            criarUsuario(); //chamando a função de criação de usuários.
            break;

        case 2:
            printf("Digite o Nome de usuário: ");
            scanf("%s", login);

            printf("Digite a senha: ");
            scanf("%s", senha);
            system("clear");

            /*
            chamando a função de autenticação e passando
            os dois valores armazenados como parametro para 
            receber um retorno.
            */
            if (autenticarUsuario(login, senha)) 
            {
                printf("autenticação bem sucedida! Usuário %s!\n", login);
            }
            else 
            {
                printf("Falha n autenticação, Login ou senha incorretos.\n");
            }
            break;

        case 3:
            printf("Fim");
            break;

        
        default:
            printf("Opção invalida!");
        
        }

    } while (opcao != 3);
    return 0;
}