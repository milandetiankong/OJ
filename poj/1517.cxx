#include <cstdio>

int main(int argc, char const *argv[])
{
	int n=3, ii=2;
	double e=2.5;
	printf("n e\n");
	printf("- -----------\n");
	printf("0 1\n");
	printf("1 2\n");
	printf("2 2.5\n");
	while (n<10) {
		ii *= n;
		e += 1.0/ii;
		printf("%d %.9f\n", n, e);
		++n;
	}	
	return 0;
}