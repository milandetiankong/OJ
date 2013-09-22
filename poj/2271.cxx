#include <cstdio>
#include <cstring>

int len;
char buf[100];

void print(char *x, int l) {
	if (l==0) {
		return;
	}
	char tmp = x[l];
	x[l] = 0;
	if (len==0) {
		printf("%s", x);	
		len = l;
	}else {
		if (len+l+1>80) {
			printf("\n%s", x);
			len = l;
		}else {
			printf(" %s", x);
			len += (l+1);
		}
	}
	x[l] =  tmp;
}
void printhr() {
	if (len !=0) {
		printf("\n");
	}
	printf("--------------------------------------------------------------------------------\n");
	len = 0;
}

void printbr() {
	printf("\n");
	len = 0;
}

void split() {
	int s=0;
	int i=0;
	while (buf[i]) {
		if (buf[i] == '<') {	
			print(&buf[s], i-s);
			if (buf[i+1] == 'h') {
				printhr();	
			}else {
				printbr();
			}
			i += 4;	
			s = i;
			continue;
		}
		++i;	
	}
	print(&buf[s], i-s);
}

int main(void) {
	while (scanf("%s", buf) != EOF) {
		split();
	}
	printf("\n");
}