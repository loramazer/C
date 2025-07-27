#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <time.h>

#define VECTOR_SIZE 100000000  // Tamanho do vetor
#define MAX_THREADS 12      // Número de threads

int NUM_THREADS;
int vetor[VECTOR_SIZE];      // Vetor global
long long resultados[MAX_THREADS];  // Soma parcial por thread

// Função que cada thread irá executar
unsigned long long fibonacci(int n) {
if (n <= 1) return n;
printf("Calculando fibonacci(%d) = fibonacci(%d) + fibonacci(%d)\n", n, n-1, n-2);
return fibonacci(n - 1) + fibonacci(n - 2);
}

int main(int argc, char *argv[]) {
    struct timespec tempo1, tempo2;
    double tempo;

    if ((argc < 2) || (argc>MAX_THREADS)) {printf ("Informe o número de threads.\n");exit(0);} else NUM_THREADS=atoi(argv[1]);

    pthread_t threads[NUM_THREADS];
    int ids[NUM_THREADS];

    // Inicializa o vetor com valores de 1 a VECTOR_SIZE
    for (int i = 0; i < VECTOR_SIZE; i++) {
        vetor[i] = 1; // Para facilitar o teste, todos os valores são 1
    }

 clock_gettime(CLOCK_REALTIME, &tempo1);
    // Cria as threads
    for (int i = 0; i < NUM_THREADS; i++) {
        ids[i] = i;
        pthread_create(&threads[i], NULL, fibonacci, (void*)&ids[i]);
    }

    // Aguarda todas as threads terminarem
    for (int i = 0; i < NUM_THREADS; i++) {
        pthread_join(threads[i], NULL);
        soma_total += resultados[i];
    }
clock_gettime(CLOCK_REALTIME, &tempo2);
        tempo = (double)(tempo2.tv_sec - tempo1.tv_sec) + (((double)(tempo2.tv_nsec - tempo1.tv_nsec))/1000000000);
printf("\nTempo decorrido: %f\n",tempo);

    printf("Soma total = %lld\n", soma_total);
    return 0;
}