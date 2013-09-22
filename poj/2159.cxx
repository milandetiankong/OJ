#include <cstdio>

int map[30];
char buf[200];
int x[200];

int main() {
	scanf("%s", buf);
	for (int i=0; buf[i]; ++i) {
		++map[buf[i]-'A'];
	}
	for (int i=0; i<30; ++i) {
		++x[map[i]];
		map[i] = 0;
	}

	scanf("%s", buf);
	for (int i=0; buf[i]; ++i) {
		++map[buf[i]-'A'];
	}
	for (int i=0; i<30; ++i) {
		--x[map[i]];
		if (x[map[i]]<0) {
			printf("NO\n");
			return 0;
		}
	}
	printf("YES\n");
	return 0;
}