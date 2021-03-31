/******************************************************************************
                    PCC104 - PROJETO E ANÁLISE DE ALGORITMOS
                  LISTA 02 - ATIVIDADES PRÁTICAS - EXERCÍCIO 03

                               SEQUENTIAL SEARCH 2

    Aluno: MARCO AURÉLIO MOURA SURIANI - 2021.10177
*******************************************************************************/

#include <iostream>
#include <vector>

using namespace std;

template <class T>
void printVector(std::vector<T>& v)
/*  Função para Imprimir vetores
    ENTRADA:
    Vetor v com elementos de qualquer datatype
*/
{
    for (T n : v)           // Itera todos os elementos do vetor v
        cout << n << " ";   // Imprime cada elemento
    cout << endl;           // Encerra a linha
}


template <class T>
int sequentialSearch2Vector(std::vector<T>& v, int n, T K)
/*  Função para Trocar os valores de duas variáveis
    ENTRADAS:
    Vetor v com elementos de qualquer datatype
    Inteiro n com o número de elementos do vetor v
    Valor K a ser buscado
*/
{
    v.push_back(K);

    int i = 0;

    while (v[i] != K)
        i++;

    v.pop_back();

    if (i < n)
        return i;
    else
        return -1;
}

// Driver program to test above functions  
int main()
{
    // Create a vector containing integers
    std::vector<int> v = { 30, 64, 25, 12, 22, 35, 22, 11, 10 };
    int nv = v.size();
    cout << "Full vector:" << endl;
    printVector(v);

    int K = 64;
    int pos = sequentialSearch2Vector(v, nv, K);
    cout << endl << "Value: " << K << "\tPosition: " << pos + 1;

    K = 100;
    pos = sequentialSearch2Vector(v, nv, K);
    cout << endl << "Value: " << K << "\tPosition: " << pos + 1;

    return 0;
}