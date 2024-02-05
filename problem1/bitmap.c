//
// Created by Alex Brodsky on 2023-09-21.
//

#include <stdlib.h>
#include "bitmap.h"


extern char *bitmap_new(int size) {
    return calloc(1, (size + 7) >> 3);
}

extern int bitmap_test(char *bitmap, int i) {
    return (bitmap[i >> 3] >> (i & 7)) & 1;
}
extern void bitmap_set(char *bitmap, int i) {
    bitmap[i >> 3] |= 1 << (i & 7);
}

extern void bitmap_reset(char *bitmap, int i) {
    bitmap[i >> 3] &= ~(1 << (i & 7));
}

extern void bitmap_toggle(char *bitmap, int i) {
    bitmap[i >> 3] ^= 1 << (i & 7);
}

