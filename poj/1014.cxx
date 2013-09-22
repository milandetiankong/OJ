#include <cstdio>
#include <cstring>


bool f[20001*3];
int used[20001*3];

int w[7];

int main(void) {
	int li=1;
	int m;
	f[0] = true;
	while (true) {
		w[0] = 0;
		for (int i=1; i<7; ++i) {
			scanf("%d", w+i);
			w[0] += i*w[i];
		}
		if (!w[0]) {
			break;
		}
		if (w[0]%2) {
			goto err;
		}


		m = w[0] / 2;
		memset(f+1, 0, sizeof(bool)*m);

		for (int i=1; i<7; ++i) {
			if (!w[i]) {
				continue;
			}
			memset(used+1, 0, sizeof(int)*m);
			for (int j=i; j<=m; ++j) {
				if (!f[j] && f[j-i] && used[j-i]<w[i]) {
					f[j] = true;
					used[j] = 1 + used[j-i];
				}
			}
		}

err:	printf("Collection #%d:\n", li++);
		if (w[0]%2 || !f[m]) {
			printf("Can't be divided.\n");
		} else {
			printf("Can be divided.\n");
		}
		printf("\n");
	}


}