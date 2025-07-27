#include <stdio.h>
#include <stdlib.h>
#include <time.h>

unsigned long long fibonacci(int n) {
if (n <= 1) return n;
printf("Calculando fibonacci(%d) = fibonacci(%d) + fibonacci(%d)\n", n, n-1, n-2);
return fibonacci(n - 1) + fibonacci(n - 2);
}

int main() {
struct timespec start, end;
clock_gettime(CLOCK_MONOTONIC, &start);

unsigned long long result = fibonacci(26);

clock_gettime(CLOCK_MONOTONIC, &end);

double elapsed = (end.tv_sec - start.tv_sec) +
                 (end.tv_nsec - start.tv_nsec) / 1e9;

printf("Resultado: %llu\n", result);
printf("Tempo com clock_gettime: %.9f segundos\n", elapsed);
return 0;
}