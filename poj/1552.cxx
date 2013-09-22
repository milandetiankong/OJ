#include <cstdio>
#include <cstring>

#define MAX_N 100
bool buf[MAX_N];
int s[16];

int main(int argc, char const *argv[])
{
	//freopen("in.txt", "r", stdin);
	int i, tmp;
	while (scanf("%d", &tmp), tmp != -1) {
		memset(buf, 0, sizeof(buf));
		s[0] = tmp;
		buf[tmp] = true;
		i = 1;
		while(scanf("%d", s+i), s[i]) {
			buf[s[i]] = true;
			i++;
		}
		int sum = 0;
		for (--i; i>=0; --i) {
			if (!(s[i]%2) && buf[s[i]/2]) {
				++sum;
			}
		}
		printf("%d\n", sum);
	}
	return 0;
}