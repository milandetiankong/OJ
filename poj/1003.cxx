#include <cstdio>

#define MAX_N 280
double buf[MAX_N];

int main(int argc, char const *argv[])
{
	//freopen("input.txt", "r", stdin);
	double t;
	int i=0;
	buf[0] = 1.0/2;
	while (buf[i++] < 5.2) {
		buf[i] = buf[i-1] + 1.0/(i+2);
	}
	scanf("%lf", &t);
	while (t > 0.0001) {
		i=0;
		while (buf[i] < t) {
			i++;
		}
		printf("%d card(s)\n", i+1);
		scanf("%lf", &t);
	}
	return 0;
}