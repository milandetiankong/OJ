#include <cstdio>
#include <cstring>

#define MAX_NUM  10001

char buf[MAX_NUM][17];

char ck[16];

void change (char x[]) {
	int cnt = 0;
	for (int j=0; ck[j]; j++) {
		if (ck[j] != x[j]) {
			if (cnt++>0) {
				return;
			}
		}
	}
	printf(" %s", x);
}

void add(char x[]) {
	int cnt = 0;
	for (int j=0, k=0; ck[j]; j++, k++) {
		if (ck[j] != x[k]) {
			j--;	
			if (cnt++>0) {
				return;
			}
		}
	}
	printf(" %s", x);
}

void del(char x[]) {
	int cnt = 0;
	for (int j=0, k=0; ck[j]; j++, k++) {
		if (ck[j] != x[k]) {
			k--;
			if (cnt++>0) {
				return;
			}
		}
	}
	printf(" %s", x);
}

int main(int argc, char const *argv[])
{
	int i;
	for (i=1; buf[i-1][1]!='#'; i++) {
		scanf("%s", buf[i]+1);
		buf[i][0] = strlen(buf[i]+1);
	}
	i--;	
	int is_find = 0;
	while (1) {
		is_find = 0;
		scanf("%s", ck);
		if (ck[0]=='#') {
			break;
		}
		int len = strlen(ck);
		for (int j=1; j<i; j++) {
			if (strcmp(ck,buf[j]+1)==0) {
				is_find = 1;
				printf("%s is correct\n", ck);
				break;
			}
		}
		if (is_find) {
			continue;
		}
		printf("%s:", ck);
		for (int j=1; j<i; j++) {
			if (len == buf[j][0]) {
				change(buf[j]+1);
			} else if (len+1 == buf[j][0]) {
				add(buf[j]+1);
			} else if (len-1 == buf[j][0]) {
				del(buf[j]+1);
			}
		}	
		printf("\n");
	}
	return 0;	
}