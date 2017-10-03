#include <stdio.h>

int collatz(int);

int main() {
const int number = 1000000;
 
int sequenceLength = 0;
int startingNumber = 0;
long sequence;
 
int cache[number + 1];
//Initialise cache
for (int i = 0; i < number + 1; i++) {
    cache[i] = -1;
}
cache[1] = 1;
 
for (int i = 2; i <= number; i++) {
    sequence = i;
    int k = 0;
    while (sequence != 1 && sequence >= i) {
        k++;
        if ((sequence % 2) == 0) {
            sequence = sequence / 2;
        } else {
            sequence = sequence * 3 + 1;
        }
    }
    //Store result in cache
    cache[i] = k + cache[sequence];
 
    //Check if sequence is the best solution
    if (cache[i] > sequenceLength) {
        sequenceLength = cache[i];
        startingNumber = i;
    }
}
	printf("%d, %d\n", startingNumber, sequenceLength);
}

int collatz(int start) {
	int chain = 0;
	int i = start;

	while (i != 1) {
		if (i % 2 == 0) i /= 2;
		else i = 3 * i + 1;
		chain++;
	}

	return chain;
}
