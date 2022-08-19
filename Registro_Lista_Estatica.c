Dada a estrutura a seguir:

typedef struct {
int matricula;
char nome[30];
float salario;
} Funcionario;

Implemente um programa completo em C que contenha um menu com as seguintes opções:
1.Inserir Registro
2.Alterar Registro
3.Apagar Registro
4.Exibir Registro
5.Exibir Listagem
0.Sair

Para isso, implemente uma lista estáticado tipo Funcionario de tamanho MAX e crie funções para o seguinte:

§ Inicializar a lista: um registro será considerado vaziocaso a matrícula seja igual a zero;
§ Tamanho da lista: retorna um inteiro com a quantidade de posições não vaziasda lista;
§ Pesquisarregistro: retornao índiceda lista contendoregistro conforme matriculainformada;
§ Inserir registro:um novo registro deve ser armazenado em umaposição vaziada lista, caso disponível;
§ Alterar registro: realizaa alteração dos dados de um registrode uma posição da listainformada, caso exista;
§ Apagar registro: modifica um registro de uma posição da listainformadapara que se torne vazio, caso exista;
§ Listar registros: exibe em tela uma listagemdos registrosarmazenadosna lista.


-------------------------------------------------------------------------------------------------------------


#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#define LIMPA_TELA system("cls")
#define MAX 1000

typedef struct
{
    int matricula;
    char nome[30];
    float salario;
} Funcionario;

Funcionario lista[MAX];

void menu();
void inicializar();
void inserir();
void alterar();
void apagar();
void exibir_registro();
void exibir_listagem();
void tamanho();
void pesquisar();

int main()
{
    LIMPA_TELA;

    menu();

    return 0;
}

void inicializar()
{
    for (int i = 0; i < MAX; i++)
        lista[i].matricula = 0;
}

void tamanho()
{
    int count = 0;
    for (int i = 0; i <= MAX; i++)
    {
        if (lista[i].matricula == 0)
            continue;
        else
            count++;
    }
}

void pesquisar()
{
    int indice, x;
    printf("Digite a matricula do registro que deseja encontrar: ");
    scanf("%d", &x);

    for (int i = 0; i < MAX; i++)
    {
        if (x == lista[i].matricula)
            indice = i;
        else
        {
            printf("Registro não encontrado.");
        }
    }
}

void menu()
{
    int entrada;
    do
    {
        printf("\n\tCadastro de Funcionario\n");
        printf("\n1. Inserir Registro.");
        printf("\n2. Alterar Registro.");
        printf("\n3. Apagar Registro.");
        printf("\n4. Exibir Registro.");
        printf("\n5. Exibir Listagem.");
        printf("\n0. Sair.\n");

        printf("\nDigite o que deseja: ");
        scanf("%d", &entrada);

        switch (entrada)
        {
        case 1:
            inserir();
            break;
        case 2:
            alterar();
            break;
        case 3:
            apagar();
            break;
        case 4:
            exibir_registro();
            break;
        case 5:
            exibir_listagem();
            break;
        case 0:
            printf("\n\nFim do programa.\n");
            break;
        default:
            printf("\nInsira um valor valido.\n");
            break;
        }
    } while (entrada > 0);
}

void inserir()
{

    for (int i = 0; i < MAX; i++)
    {
        if (lista[i].matricula == 0)
        {
            printf("\nDigite a matricula: ");
            scanf("%d", &lista[i].matricula);
            if (lista[i].matricula == 0)
            {
                printf("\nLista invalida.\n");
                return;
            }
            printf("\nDigite o nome: ");
            scanf("%s", lista[i].nome);
            printf("\nDigite o salario: ");
            scanf("%f", &lista[i].salario);
            return;
        }
    }
}

void alterar()
{
    int x, i;
    for (i = 0; i < MAX; i++)
    {
        printf("\nQual registro deseja alterar? ");
        scanf("%d", &x);
        if (lista[i].matricula != x)
        {
            printf("\nO registro não foi encontrado.");
            return;
        }
        if (lista[x].matricula == i)
        {
            printf("\nDigite uma nova matricula: ");
            scanf("%d", &lista[i].matricula);
            printf("\nDigite um novo nome: ");
            scanf("%s", lista[i].nome);
            printf("\nDigite um novo salario: ");
            scanf("%f", &lista[i].salario);
            return;
        }
    }
}

void apagar()
{
    int x, i;

    printf("\nQual registro deseja apagar? ");
    scanf("%d", &x);

    for (i = 0; i < MAX; i++)

    {
        if (lista[i].matricula == x)
        {
            lista[i].matricula = 0;
            printf("\nRegistro apagado.");
        }
    }
}

void exibir_registro()
{
    int x, i = 0;
    printf("\nQual registro deseja exibir? ");
    scanf("%d", &x);

    if (lista[i].matricula == 0)
    {
        printf("\nNão existe registro.");
    }
    for (i = 0; i < MAX; i++)
    {
        if (lista[i].matricula == x)
        {
            printf("\n\nREGISTRO\n\n");
            printf("\nMatricula : %d\t", lista[i].matricula);
            printf("\nNome: %s\t", lista[i].nome);
            printf("\nSalario: R$ %.2f\t", lista[i].salario);
            printf("\n\n");
        }
    }
}

void exibir_listagem()
{
    printf("\nMATRICULA\t-\tNOME\t-\tSALARIO\t\t");
    for (int i = 0; i < MAX; i++)
    {
        if (lista[i].matricula == 0)
            continue;

        else
        {
            printf("\n%d\t\t\t%s\t\tR$ %.2f", lista[i].matricula, lista[i].nome, lista[i].salario);
        }
    }
}
