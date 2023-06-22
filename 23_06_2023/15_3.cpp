/*
Grupo:
Aser Junior
Ebert Ian
Israel Benvindo
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int item;
    struct Node* next;
} Node;

// Função para criar um novo nó
Node* newNode(int item, Node* next) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->item = item;
    newNode->next = next;
    return newNode;
}

// Definition of the adjacency list
Node* Adj[6]; // Lista de adjacência com 6 elementos

// Função para inicializar a lista de adjacência
void initializeAdjList() {
    Adj[0] = newNode(1, NULL);
    Adj[1] = newNode(2, newNode(3, NULL));
    Adj[2] = newNode(4, NULL);
    Adj[3] = newNode(2, newNode(4,  newNode(5, NULL)));
    Adj[4] = newNode(5, NULL);
    Adj[5] = NULL;
}

// Função para realizar a busca em largura (BFS) e imprimir todos os caminhos
void bfs(Node* Adj[]) {
    int visited[6] = {0}; // Array para manter o controle dos vértices visitados
    int parent[6] = {-1}; // Array para manter o controle dos vértices pais
    Node* queue = NULL;   // Fila para a BFS

    visited[0] = 1;       // Marca o primeiro vértice como visitado

    // Insere o primeiro vértice na fila
    queue = newNode(0, NULL);

    while (queue != NULL) {
        Node* current = queue;
        queue = queue->next;

        // Imprime o caminho atual
        int vertex = current->item;
        while (vertex != -1) {
            printf("%d ", vertex);
            vertex = parent[vertex];
        }
        printf("\n");

        // Itera pela lista de adjacência do vértice atual
        for (Node* neighbor = Adj[current->item]; neighbor != NULL; neighbor = neighbor->next) {
            if (!visited[neighbor->item]) {
                visited[neighbor->item] = 1;
                parent[neighbor->item] = current->item;
                Node* newNodePtr = newNode(neighbor->item, NULL);
                // Insere os vizinhos não visitados na fila
                if (queue == NULL) {
                    queue = newNodePtr;
                } else {
                    Node* temp = queue;
                    while (temp->next != NULL) {
                        temp = temp->next;
                    }
                    temp->next = newNodePtr;
                }
            }
        }

        free(current);
    }
}

int main() {
    initializeAdjList();
    printf("Caminhos da busca em largura (BFS) do vértice 0 ao vértice 5:\n");
    bfs(Adj);
    return 0;
}
