#include "validator.h"

void run() {
	int n = Int(1, 100);
	Space();
	Int(1, 100);
	Endl();
	int a = Int(1, n);
	Space();
	int b = Int(1, n);
	Space();
	int c = Int(1, n);
	Endl();

	assert(a != b);
	assert(a != c);
	assert(b != c);
}
