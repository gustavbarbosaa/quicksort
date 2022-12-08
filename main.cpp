#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int particionarVetor(int vetor[], int inicio, int fim) {

    int esquerda, direita, pivo, auxiliar;

    esquerda = inicio;
    direita = fim;
    pivo = vetor[inicio];

    while (esquerda < direita) {

        while (esquerda <= fim && vetor[esquerda] <= pivo) {
            if (esquerda < direita) {
                esquerda++;
            } else {
                break;
            }
        }

        while (direita >= 0 && vetor[direita] > pivo) {
            if (direita >= esquerda) {
                direita--;
            } else {
                break;
            }
        }

        if (esquerda < direita) {
            auxiliar = vetor[esquerda];
            vetor[esquerda] = vetor[direita];
            vetor[direita] = auxiliar;
            esquerda++;
            direita--;
        }
    }

    vetor[inicio] = vetor[direita];
    vetor[direita] = pivo;

    return direita;
};

void quickSort(int vetor[], int inicio, int fim) {
    int pivo;

    if (fim > inicio) {
        pivo = particionarVetor(vetor, inicio, fim);
        quickSort(vetor, inicio, pivo - 1);
        quickSort(vetor, pivo + 1, fim);
    }
}

void imprimirVetor(int vetor[], int tam)
{
	int i;
	for (i = 0; i < tam; i++)
		cout << vetor[i] << " ";
	cout << endl;
}

int main()
{
    int arr[] = {5,4,3,2,1};
    int tam = sizeof(arr)/sizeof(arr[0]);

    quickSort(arr, 0, tam - 1);
    imprimirVetor(arr, tam);

    return 0;
}
