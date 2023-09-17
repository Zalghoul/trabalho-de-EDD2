#include <stdio.h>
#include <string.h>

void swap(char **a, char **b) {
    char *temp = *a;
    *a = *b;
    *b = temp;
}

int partition(char *arr[], int low, int high, int *comparisons, int *swaps) {
    char *pivot = arr[high];
    int i = low - 1;

    for (int j = low; j <= high - 1; j++) {
        (*comparisons)++;
        if (strcmp(arr[j], pivot) < 0) {
            i++;
            (*swaps)++;
            swap(&arr[i], &arr[j]);
        }
    }
    (*swaps)++;
    swap(&arr[i + 1], &arr[high]);
    return i + 1;
}

void quicksort(char *arr[], int low, int high, int *comparisons, int *swaps) {
    if (low < high) {
        int pi = partition(arr, low, high, comparisons, swaps);

        quicksort(arr, low, pi - 1, comparisons, swaps);
        quicksort(arr, pi + 1, high, comparisons, swaps);
    }
}

int main() {
    char *arr[20] = {
        "maca", "banana", "pera", "uva", "laranja", "abacaxi", "limao", "manga", "abacate", "kiwi",
        "cereja", "morango", "pessego", "goiaba", "melancia", "framboesa", "amora", "caqui", "figo", "papaya"
    };

    int comparisons = 0;
    int swaps = 0;
    int n = sizeof(arr) / sizeof(arr[0]);

    quicksort(arr, 0, n - 1, &comparisons, &swaps);

    printf("Número de trocas: %d\n", swaps);
    printf("Número de comparações: %d\n", comparisons);

    printf("Vetor ordenado:\n");
    for (int i = 0; i < n; i++) {
        printf("• %s\n", arr[i]);
    }

    
    char *median;
    if (n % 2 == 0) {
        char *middle1 = arr[(n / 2) - 1];
        char *middle2 = arr[n / 2];
        printf("Medianas: %s e %s\n", middle1, middle2);
        median = middle1;
    } else {
        median = arr[n / 2];
        printf("Mediana: %s\n", median);
    }

    
    FILE *outputFile = fopen("copiasaida.txt", "w");
    if (outputFile != NULL) {
        fprintf(outputFile, "Número de trocas: %d\n", swaps);
        fprintf(outputFile, "Número de comparações: %d\n", comparisons);
        fprintf(outputFile, "Vetor ordenado:\n");
        for (int i = 0; i < n; i++) {
            fprintf(outputFile, "• %s\n", arr[i]);
        }
        if (n % 2 == 0) {
            char *middle1 = arr[(n / 2) - 1];
            char *middle2 = arr[n / 2];
            fprintf(outputFile, "Medianas: %s e %s\n", middle1, middle2);
        } else {
            fprintf(outputFile, "Mediana: %s\n", median);
        }
        fclose(outputFile);
        printf("Resultados escritos em 'copiasaida.txt'\n");
    } else {
        printf("Erro ao criar o arquivo de saída.\n");
    }

    return 0;
}
