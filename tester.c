#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef unsigned int uint;
typedef union Float {
    float f;
    uint i;
    struct {
        uint mant : 23;
        uint exp : 8;
        uint sign : 1;
    } body;
} FloatPoint;

int main(int argsc, char *argv[]) {
    srand(time(0));
    float f1 = (float)rand() / (float)RAND_MAX;
    float f2 = (float)rand() / (float)RAND_MAX;
    char operation;

    FloatPoint result, fp1, fp2;
    fp1.f = f1;
    fp2.f = f2;

    sscanf(argv[1], "%c", &operation);
    switch (operation) {
        case '+':
            result.f = fp1.f + fp2.f;
            break;
        case '-':
            result.f = fp1.f - fp2.f;
            break;
        case '*':
            result.f = fp1.f * fp2.f;
            break;
        case '/':
            result.f = fp1.f / fp2.f;
            break;
    }
    printf("f 1 0x%x '%c' 0x%x\n", fp1.i, operation, fp2.i);
    printf("%a\n", result.f);
}