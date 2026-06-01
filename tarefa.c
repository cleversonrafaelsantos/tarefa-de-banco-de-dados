#include <stdio.h>
#include <string.h>

struct Cliente {
    int codigo;
    char nome[50];
};

struct Servico {
    int codigo;
    char descricao[50];
    float valor;
};

int main() {
    struct Cliente cliente[10];
    struct Servico servico[10];

    int qtdClientes = 0;
    int qtdServicos = 0;
    int opcao;

    do {
        printf("\n===== SISTEMA COMERCIAL =====\n");
        printf("1 - Cadastrar Cliente\n");
        printf("2 - Cadastrar Servico\n");
        printf("3 - Listar Clientes\n");
        printf("4 - Listar Servicos\n");
        printf("5 - Realizar Venda\n");
        printf("0 - Sair\n");
        printf("Opcao: ");
        scanf("%d", &opcao);

        switch(opcao) {

        case 1:
            printf("\nCodigo do cliente: ");
            scanf("%d", &cliente[qtdClientes].codigo);

            printf("Nome do cliente: ");
            scanf(" %[^\n]", cliente[qtdClientes].nome);

            qtdClientes++;
            printf("Cliente cadastrado com sucesso!\n");
            break;

        case 2:
            printf("\nCodigo do servico: ");
            scanf("%d", &servico[qtdServicos].codigo);

            printf("Descricao do servico: ");
            scanf(" %[^\n]", servico[qtdServicos].descricao);

            printf("Valor do servico: ");
            scanf("%f", &servico[qtdServicos].valor);

            qtdServicos++;
            printf("Servico cadastrado com sucesso!\n");
            break;

        case 3:
            printf("\n--- CLIENTES ---\n");
            for(int i = 0; i < qtdClientes; i++) {
                printf("Codigo: %d | Nome: %s\n",
                       cliente[i].codigo,
                       cliente[i].nome);
            }
            break;

        case 4:
            printf("\n--- SERVICOS ---\n");
            for(int i = 0; i < qtdServicos; i++) {
                printf("Codigo: %d | Servico: %s | Valor: R$ %.2f\n",
                       servico[i].codigo,
                       servico[i].descricao,
                       servico[i].valor);
            }
            break;

        case 5: {
            int codCliente, codServico;
            int clienteEncontrado = -1;
            int servicoEncontrado = -1;

            printf("\nCodigo do cliente: ");
            scanf("%d", &codCliente);

            printf("Codigo do servico: ");
            scanf("%d", &codServico);

            for(int i = 0; i < qtdClientes; i++) {
                if(cliente[i].codigo == codCliente) {
                    clienteEncontrado = i;
                }
            }

            for(int i = 0; i < qtdServicos; i++) {
                if(servico[i].codigo == codServico) {
                    servicoEncontrado = i;
                }
            }

            if(clienteEncontrado != -1 && servicoEncontrado != -1) {
                printf("\n===== VENDA REALIZADA =====\n");
                printf("Cliente: %s\n",
                       cliente[clienteEncontrado].nome);

                printf("Servico: %s\n",
                       servico[servicoEncontrado].descricao);

                printf("Valor: R$ %.2f\n",
                       servico[servicoEncontrado].valor);
            } else {
                printf("Cliente ou servico nao encontrado!\n");
            }
            break;
        }

        case 0:
            printf("Encerrando sistema...\n");
            break;

        default:
            printf("Opcao invalida!\n");
        }

    } while(opcao != 0);

    return 0;
}