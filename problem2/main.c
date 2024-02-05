#include <stdio.h>
#include <string.h>
#include <assert.h>
#include "bitmap.h"
#include "bitmap.c"

int main() {
    int M;
    int N;
    scanf("%d %d", &M, &N);
    char *bitmap = bitmap_new(M);

    for (int i = 0; i < N; i++) {
        int number;
        scanf("%d", &number);
        if (number>= N || number < 0) {
            printf("Integer not found: %d\n",  number);
        } else {
            bitmap_toggle(bitmap, number);
        }
    }

    printf("Odd:");
    for (int i = 0; i < N; i++) {
        if (bitmap_test(bitmap, i)) {
            printf(" %d", i);
        }
    }
    printf("\n");
    return 0;
}
