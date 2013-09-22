#include <cstdio>
#include <cmath>

int buf[10000001];
double  tmp;

int main(int argc, char const *argv[])
{
	//freopen("in.txt", "r", stdin);
	int i=1, j;
	tmp = 0;
	while (i<10000001) {
		tmp += log10(i);
		buf[i] = (int)tmp;
		i++;
	}
	scanf("%d\n", &i);
	while (i--) {
		scanf("%d\n", &j);
		printf("%d\n", buf[j]+1);
	}
	return 0;
}