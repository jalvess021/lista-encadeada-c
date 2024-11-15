#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node {
    int data;               
    struct Node* next;   
} Node;

Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (!newNode) {
        printf("Erro ao alocar memória.\n");
        exit(1);
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void insert(Node** head, int data) {
    Node* newNode = createNode(data);
    newNode->next = *head;
    *head = newNode;
    printf("Elemento %d inserido com sucesso!\n", data);
}

void listElements(Node* head) {
    if (!head) {
        printf("A lista está vazia.\n");
        return;
    }
    printf("Elementos na lista:\n");
    while (head) {
        printf("%d -> ", head->data);
        head = head->next;
    }
    printf("NULL\n");
}

void update(Node* head, int oldData, int newData) {
    Node* current = head;
    while (current) {
        if (current->data == oldData) {
            current->data = newData;
            printf("Elemento %d alterado para %d com sucesso!\n", oldData, newData);
            return;
        }
        current = current->next;
    }
    printf("Elemento %d não encontrado na lista.\n", oldData);
}

void removeElement(Node** head, int data) {
    Node *current = *head, *prev = NULL;

    while (current && current->data != data) {
        prev = current;
        current = current->next;
    }

    if (!current) {
        printf("Elemento %d não encontrado na lista.\n", data);
        return;
    }

    if (prev) {
        prev->next = current->next;
    } else {
        *head = current->next;
    }
    free(current);
    printf("Elemento %d removido com sucesso!\n", data);
}

int main() {
    Node* head = NULL;
    int option, data, oldData, newData;
    int validInput;

    do {
        printf("\nOperações na Lista Simplesmente Encadeada:\n");
        printf("1. Inserir elemento\n");
        printf("2. Listar elementos\n");
        printf("3. Alterar elemento\n");
        printf("4. Remover elemento\n");
        printf("5. Sair\n");
        printf("Escolha uma opção: ");

        validInput = scanf("%d", &option);
        
        //descarta qualquer coisa ate a proxima linha
        while(getchar() != '\n');

        if (validInput != 1) {
            printf("Entrada inválida! Por favor, insira um número inteiro.\n");
            continue; 
        }

        switch (option) {
            case 1:
                printf("Digite o valor a ser inserido: ");
                validInput = scanf("%d", &data);
                while(getchar() != '\n'); 
                if (validInput != 1) {
                    printf("Entrada inválida! Por favor, insira um número inteiro.\n");
                    continue;
                }
                insert(&head, data);
                break;
            case 2:
                listElements(head);
                break;
            case 3:
                printf("Digite o valor a ser alterado: ");
                validInput = scanf("%d", &oldData);
                while(getchar() != '\n');
                if (validInput != 1) {
                    printf("Entrada inválida! Por favor, insira um número inteiro.\n");
                    continue;
                }
                printf("Digite o novo valor: ");
                validInput = scanf("%d", &newData);
                while(getchar() != '\n');
                if (validInput != 1) {
                    printf("Entrada inválida! Por favor, insira um número inteiro.\n");
                    continue;
                }
                update(head, oldData, newData);
                break;
            case 4:
                printf("Digite o valor a ser removido: ");
                validInput = scanf("%d", &data);
                while(getchar() != '\n');
                if (validInput != 1) {
                    printf("Entrada inválida! Por favor, insira um número inteiro.\n");
                    continue;
                }
                removeElement(&head, data);
                break;
            case 5:
                printf("Saindo...\n");
                break;
            default:
                printf("Opção inválida. Tente novamente.\n");
        }
    } while (option != 5);

    return 0;
}
