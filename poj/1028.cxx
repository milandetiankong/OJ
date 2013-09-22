#include <cstdio>
#include <cstring>

char f[102][72];
char b[102][72];

char cur[102];
char cmd[20];

int main(void) {
	int pf=0;
	int pb=0;
	strcpy(cur, "http://www.acm.org/");	
	while (scanf("%s", cmd), cmd[0]!='Q') {
		if (cmd[0] == 'V') {
			strcpy(b[pb++], cur);
			pf = 0;
			scanf("%s", cur);
		}else if (cmd[0] == 'B') {
			if (pb==0) {
				printf("Ignored\n");
				continue;
			}
			strcpy(f[pf++], cur);
			strcpy(cur, b[--pb]);
		}else if (cmd[0] == 'F') {
			if (pf==0) {
				printf("Ignored\n");
				continue;
			}
			strcpy(b[pb++], cur);
			strcpy(cur, f[--pf]);
		}
		printf("%s\n", cur);
	}
}