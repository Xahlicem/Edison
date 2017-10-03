#include <stdio.h>

int div(long);
int divisors(long);
long tri(int);

int main() {
	int i = 0;
	long t = 0;
	int max = 0;
	while (1) {
		i++;
		t = tri(i);
		//for (int x = 1; x <= i; x++) t += x;
		int d = divisors(t);
		if (d > max) printf("%d:%d %d\n", i, t, (max = d));
		if (max >= 500) break;
	}

	printf("%d:%d %d\n", i, t, max);
}

int div(long num) {
	int n = 1;
	for (long i = 1; i < num; i++) if (num % i == 0) n++;
	return n;
}

long tri(int num) {
	return num * (num + 1) / 2;
}

int divisors(long x) {
    long limit = x;
    int numberOfDivisors = 0;

    if (x == 1) return 1;

    for (long i = 1; i < limit; ++i) {
        if (x % i == 0) {
            limit = x / i;
            if (limit != i) {
                numberOfDivisors++;
            }
            numberOfDivisors++;
        }
    }

    return numberOfDivisors;
}
