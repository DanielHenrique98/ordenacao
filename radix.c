//radix
#include <stdio.h>
#include <stdlib.h>

// Função para encontrar o maior elemento em um array
int getMax(int arr[], int n) {
    int max = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }
    return max;
}

// Função de ordenação por contagem para um dígito específico
void countingSort(int arr[], int n, int exp) {
    int output[n];
    int count[10] = {0};

    // Conta a ocorrência de cada dígito
    for (int i = 0; i < n; i++) {
        count[(arr[i] / exp) % 10]++;
    }

    // Atualiza a contagem para refletir as posições reais dos dígitos
    for (int i = 1; i < 10; i++) {
        count[i] += count[i - 1];
    }

    // Constrói o array de saída ordenado
    for (int i = n - 1; i >= 0; i--) {
        output[count[(arr[i] / exp) % 10] - 1] = arr[i];
        count[(arr[i] / exp) % 10]--;
    }

    // Copia o array de saída ordenado de volta para o array original
    for (int i = 0; i < n; i++) {
        arr[i] = output[i];
    }
}

// Função Radix Sort
void radixSort(int arr[], int n) {
    // Encontra o maior elemento para determinar o número de dígitos
    int max = getMax(arr, n);

    // Ordena por cada dígito, do menos significativo ao mais significativo
    for (int exp = 1; max / exp > 0; exp *= 10) {
        countingSort(arr, n, exp);
    }
}

// Função para imprimir um array
void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int arr[] = {170, 45, 75, 90, 2, 24, 802, 66};
    int n = sizeof(arr) / sizeof(arr[0]);

    radixSort(arr, n);

    printf("Array ordenado: \n");
    printArray(arr, n);

    return 0;
}
//teste 
