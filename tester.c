#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

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


float getRandomFloat() ;

int main(int argsc, char *argv[]) {
    char operation;
    FloatPoint result, fp1, fp2;
	struct timespec ts;

    clock_gettime(CLOCK_MONOTONIC, &ts);
    srandom(ts.tv_nsec);
    srand48(ts.tv_nsec);
    fp1.f = getRandomFloat();
    fp2.f = getRandomFloat();
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
    printf("(%f) %c (%f) = (%f)\n", fp1.f, operation, fp2.f, result.f);
}

float getRandomFloat()
{
	if (random() % 30 == 0) {
		switch (random() % 5)
		{
		case 0:
			return (float)0;
		case 1:
			return NAN;
		case 2:
			return -NAN;
		case 3:
			return INFINITY;
		case 4:
			return -INFINITY;
		}
	}
	float out = (double)random() / (double)random() * rand();
	return (random() % 2) ? out : -out;
}