#include <stdio.h>
#include <string.h>
#include <assert.h>
#include "bitmap.h"
#include "bitmap.c"

int main() {
    int max;
    int num;
    scanf("%d %d", &max, &num);
    char *bitmap = bitmap_new(max);

    for (int i = 0; i < num; i++) {
        int value;
        scanf("%d", &value);
        if (value < 0 || value >= max) {
            printf("Integer out of range: %d\n", value);
        } else {
            bitmap_set(bitmap, value);
        }
    }

    int max_len = 0;
    int cur_len = 0;
    int loc = -1;
    int cur_loc = 0;
    for (int i = 0; i < max; i++) {
        if (bitmap_test(bitmap, i)) {
            if (cur_len == 0) {
                cur_loc = i;
                cur_len = 1;
            } else {
                cur_len++;
            }
        } else if (cur_len > 0) {
            if (cur_len > max_len) {
                max_len = cur_len;
                loc = cur_loc;
            }
            cur_len = 0;
            cur_loc = -1;
        }
    }

    printf("Max sequence:" );
    for (int i = 0; i < max_len; i++) {
        printf(" %d", i + loc);
    }
    printf("\n");
    return 0;
}
