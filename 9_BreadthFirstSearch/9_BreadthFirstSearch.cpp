/******************************************************************************
                    PCC104 - PROJETO E ANÁLISE DE ALGORITMOS
                  LISTA 2 - ATIVIDADES PRÁTICAS - EXERCÍCIO 09

                              Breadth-First Search

    Aluno: MARCO AURÉLIO MOURA SURIANI - 2021.10177
*******************************************************************************/

#include <iostream>
#include <vector>
#include <queue>  

using namespace std;

class Grafo {
    // Classe para armazenar grafos marcados (vértices, arestas e marcações)
private:
    // Inteiro com a quantidade de vértices. Os vértices são [0, ..., nodes-1]
    // Não é possível rotular os vértices!!
    int n_nodes = 0;
    // Vetor de arestas com pares de inteiros
    vector<pair<int, int>> edges;
    // Vetor com marcações dos nós
    vector<int> vertex_marks;
public:
    // Entrada da quantidade de vértices
    // Possível melhoria: só realiza se n_nodes = 0 (proibido alterar)
    void set_nodes(int n) { n_nodes = n; }

    // Devolve a quantidade de vértices
    int get_nodes() { return n_nodes;  }

    // Entrada de arestas: recebe coordenadas inteiras (x, y) 
    // e armazena como um par em vertex
    // O primeiro vértice é sempre menor que o segundo para facilitar a análise
    void set_edge(int x, int y) { 
        if (x <= y)
            edges.push_back(pair<int, int>(x, y));
        else
            edges.push_back(pair<int, int>(y, x));
        }

    // Saída de arestas: devolve a (n+1)-esima aresta (origem e destino)
    int get_o(int n) { return edges[n].first; }
    int get_d(int n) { return edges[n].second; }

    // Retorna a quantidade arestas armazenadas
    int num_edges() { return edges.size(); }

    // Entrada das marcações
    void set_marks(vector<int> vm) {
        vertex_marks.clear();
        vertex_marks = vm;
    }

    // Retorna as marcações
    vector<int> get_marks() { return vertex_marks; }

    // Retorna a marcação do vértice n
    int get_mark(int n) { return vertex_marks[n]; }
};

void bfs(Grafo& G, int& v, vector<int>& visited_vertex, int& count) {

    count++;
    visited_vertex[v] = count;

    queue<int> bfs_queue;
    bfs_queue.push(v);

    int w;

    while (!bfs_queue.empty())
    {
        for (int j = 0; j < G.num_edges(); j++)
        {
            w = G.get_d(j);
            if (G.get_o(j) == bfs_queue.front() && visited_vertex[w] == 0)
            {
                count++;
                // mark w with count
                visited_vertex[w] = count;
                // add w to the queue
                bfs_queue.push(w);
            }
        }
        // remove the front vertex from the queue
        bfs_queue.pop();
    }
}

void BFS(Grafo& G) {

    vector<int> visited_vertex;
    for (int i = 0; i < G.get_nodes(); i++)
        visited_vertex.push_back(0);

    int count = 0;

    for (int v = 0; v < G.get_nodes(); v++)
    {
        if (visited_vertex[v] == 0)
            bfs(G, v, visited_vertex, count);
    }
    G.set_marks(visited_vertex);
}

int main() {
    // Cria um objeto da Classe Grafo
    Grafo G;

    // Acrescenta 11 vértices ao grafo G
    int num_nodes = 11;
    G.set_nodes(num_nodes);

    // Acrescenta arestas ao grafo G
    G.set_edge(0, 1);
    G.set_edge(0, 3);
    G.set_edge(1, 2);
    G.set_edge(2, 3);
    G.set_edge(2, 10);
    G.set_edge(3, 4);
    G.set_edge(3, 6);
    G.set_edge(4, 8);
    G.set_edge(6, 7);
    G.set_edge(5, 9);

    // Imprime o Grafo G
    cout << "Grafo:" << endl;
    cout << "01 --- 00     05 --- 09" << endl;
    cout << "|      |" << endl;
    cout << "02 --- 03 --- 04 --- 08" << endl;
    cout << "|      |" << endl;
    cout << "10     06 --- 07" << endl << endl;

    // Imprime uma lista com os nós
    cout << "NDS: ";
    for (int i = 0; i < num_nodes; i++)
        cout << i << " , ";
    cout << endl;

    // Executa o algoritmo BFS, que marca automaticamente os vértices de G
    BFS(G);

    // Imprime a marcação de cada nó
    cout << "BFS: ";
    for (int i = 0; i < num_nodes; i++)
        cout << G.get_mark(i) << " , ";
    cout << endl;

    return 0;

}