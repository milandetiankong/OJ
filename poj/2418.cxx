#include <cstdio>
#include <cstdlib>

char s[100];

#define BRANCH 128

struct TrieNoder
{
	int num;
	TrieNoder *next[BRANCH];
	TrieNoder() {
		num = 0;
		for (int i=0; i<BRANCH; i++) {
			next[i] = 0;
		}
	}
};

int sum = 0;

void insertTrie(TrieNoder *r, char *x) {
	for (int i=0; x[i]; i++) {
		if (r->next[x[i]] == 0) {
			r->next[x[i]] = new TrieNoder();
		}
		r = r->next[x[i]];
	}
	r->num++;
	sum ++;
}

char ss[100];
int ssi=0;
void print(TrieNoder *r) {
	for (int i=0; i<BRANCH; i++) {
		if (r->next[i]) {
			ss[ssi++] = i;
			print(r->next[i]);
		}
	}	
	if (r->num) {
		ss[ssi] = 0;
		printf("%s %.4f\n", ss, r->num*100.0/sum);
	}
	ssi--;
}


int main(int argc, char const *argv[])
{
	//freopen("in.txt", "r", stdin);
	TrieNoder *r = new TrieNoder();
	while (gets(s)) {
		insertTrie(r, s);
	}	
	print(r);
	return 0;
}
