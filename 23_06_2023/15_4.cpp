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

// Função auxiliar recursiva para realizar a busca em profundidade (DFS)
void dfsRecursive(int vertex, int visited[], int parent[]) {
    visited[vertex] = 1; // Marca o vértice como visitado
    printf("%d ", vertex); // Imprime o vértice atual

    // Itera pela lista de adjacência do vértice atual
    for (Node* neighbor = Adj[vertex]; neighbor != NULL; neighbor = neighbor->next) {
        if (!visited[neighbor->item]) {
            parent[neighbor->item] = vertex; // Define o vértice atual como pai do vizinho
            dfsRecursive(neighbor->item, visited, parent); // Chama a função recursivamente para o vizinho não visitado
        }
    }
}

// Função para realizar a busca em profundidade (DFS) e imprimir todos os caminhos
void dfs(int startVertex) {
    int visited[6] = {0}; // Array para manter o controle dos vértices visitados
    int parent[6] = {-1}; // Array para manter o controle dos vértices pais

    printf("Caminhos da busca em profundidade (DFS) a partir do vértice %d:\n", startVertex);

    dfsRecursive(startVertex, visited, parent); // Chama a função recursiva para realizar a DFS
}

int main() {
    initializeAdjList();
    dfs(0); // Executa a busca em profundidade (DFS) a partir do vértice 0
    return 0;
}


// 15.4b

/*
Não existe garantia que o primeiro caminho encontrado pois o DFS explora o caminhos de forma recursiva indo o mais fundo possivel em cada ramo antes de fazer o retrocesso.
*/