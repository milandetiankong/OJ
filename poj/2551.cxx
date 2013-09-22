#include <cstdio>

int main()
{
	int n;
	while (scanf("%d", &n) != EOF) {
		int cnt = 1;
		for (int tmp=1; tmp; tmp = tmp*10 +1) {
			tmp = tmp%n;
			if (tmp==0) {
				break;
			}
			cnt ++;
		}
		printf("%d\n", cnt);
	}
	return 0;
}