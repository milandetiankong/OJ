#include <cstdio>

int main(int argc, char const *argv[])
{
	//freopen("input.txt", "r", stdin);
	int a, b;
	while (scanf("%d %d", &a, &b)!=EOF) {
		printf("%d\n", a+b);
	}
	return 0;
}