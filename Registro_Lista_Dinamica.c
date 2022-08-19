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

Para isso, implemente uma lista dinâmica tipo Funcionario de tamanho MAX e crie funções para o seguinte:

§ Inicializar a lista: um registro será considerado vazio caso a matrícula seja igual a zero;
§ Tamanho da lista: retorna um inteiro com a quantidade de posições não vazias a lista;
§ Inserir registro:um novo registro deve ser armazenado em uma posição vazia da lista, caso disponível;
§ Alterar registro: realiza a alteração dos dados de um registro de uma posição da lista informada, caso exista;
§ Apagar registro: modifica um registro de uma posição da lista informada para que se torne vazio, caso exista;
§ Listar registros: exibe em tela uma listagem dos registros armazenados na lista.


-------------------------------------------------------------------------------------------------------------
  
  #include <stdio.h>
#include <stdlib.h>

typedef struct No
{
    int valor;
    int matricula;
    char nome[30];
    float salario;
    struct No *next;

} No;

typedef struct
{
    No *inicio;
    int tam;
} Lista;

void inicializar();
void inserir_inicio();
void inserir_final();
void alterar();
void apagar();
void menu();
void exibir_registro();
void exibir_listagem();
void tamanho();

int main()
{
    Lista lista;
    lista.inicio = NULL;

    int entrada;

    do
    {
        printf("\n\tCadastro de Funcionario\n");
        printf("\n1. Inserir Registro");
        printf("\n2. Alterar Registro");
        printf("\n3. Apagar Registro");
        printf("\n4. Exibir Registro");
        printf("\n5. Exibir Listagem");
        printf("\n0. Sair\n");

        printf("\nDigite o que deseja: ");
        scanf("%d", &entrada);

        switch (entrada)
        {
        case 1:
            inserir_final(&lista);
            break;
        case 2:
            alterar(&lista);
            break;
        case 3:
            apagar(&lista);
            break;
        case 4:
            exibir_registro(&lista);
            break;
        case 5:
            exibir_listagem(&lista);
            break;
        default:
            printf("\nInsira um valor valido\n");
            break;
        }
    } while (entrada > 0);

    return 0;
}

void inicializar(Lista *lista)
{
    lista->inicio = NULL;
    lista->tam = 0;
}

void inserir_inicio(Lista *lista, int valor)
{
    No *new = (No *)malloc(sizeof(No));
    scanf("%d", &valor);
    new->next = lista->inicio;
    lista->inicio = new;
    lista->tam++;
}

void inserir_final(Lista *lista)
{
    No *no, *new = (No *)malloc(sizeof(No));

    printf("\nDigite a matricula: ");
    scanf("%d", &new->matricula);
    printf("\nDigite o nome: ");
    scanf("%s", new->nome);
    printf("\nDigite o salario: ");
    scanf("%f", &new->salario);

    new->next = NULL;

    if (lista->inicio == NULL)
    {
        lista->inicio = new;
    }
    else
    {
        no = lista->inicio;
        while (no->next != NULL)
            no = no->next;
        no->next = new;
    }
    lista->tam++;
    return;
}
void alterar(Lista *lista)
{
    int x;
    No *aux;
    aux = lista->inicio;
    printf("\nQual registro deseja alterar? ");
    scanf("%d", &x);

    while (aux->matricula != x)
    {
        aux = aux->next;
    }
    if (aux->matricula == x)
    {
        printf("\nDigite a nova matricula: ");
        scanf("%d", &aux->matricula);
        printf("\nDigite o novo nome: ");
        scanf("%s", aux->nome);
        printf("\nDigite o novo salario: ");
        scanf("%f", &aux->salario);
    }
}

void apagar(Lista *lista)
{

    int x;

    No *atual, *ant, *aux;
    No *inicio = lista->inicio;

    printf("\nQual registro deseja excluir? ");
    scanf("%d", &x);

    if (x == inicio->matricula)
    {
        aux = inicio;
        inicio = inicio->next;
        free(aux);
        return;
    }
    else
    {
        ant = inicio;
        atual = inicio->next;

        while (atual != NULL && atual->matricula != x)
        {
            ant = atual;
            atual = atual->next;
        }

        if (atual != NULL)
        {
            aux = atual;
            ant->next = atual->next;
            free(aux);
            return;
        }
        else
            printf("\nNão foi possivel encontrar registro.");
    }
}

void exibir_registro(Lista *lista)
{
    int x;
    No *aux;
    aux = lista->inicio;
    printf("\nQual registro deseja exibir? ");
    scanf("%d", &x);

    while (aux->matricula != x)
    {
        aux = aux->next;
    }
    if (aux->matricula == x)
    {
        printf("\n\n---- REGISTRO ----\n");
        printf("\nMatricula: %d", aux->matricula);
        printf("\nNome: %s", aux->nome);
        printf("\nSalario: R$ %2.f\n", aux->salario);
    }
}

void exibir_listagem(Lista *lista)
{
    No *inicio = lista->inicio;

    printf("\nMATRICULA\t-\tNOME\t-\t SALARIO\t\t");
    while (inicio != NULL)
    {
        printf("\n%d\t\t\t%s\t\tR$ %.2f\n\n", inicio->matricula, inicio->nome, inicio->salario);
        inicio = inicio->next;
    }
}
void tamanho(Lista *lista)
{
    No *pi;
    int count = 0;
    for (pi = lista->inicio; pi != NULL; pi = pi->next)
    {
        count++;
    }
}


