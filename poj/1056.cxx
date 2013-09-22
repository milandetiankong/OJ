#include <cstdio>
#include <cstring>

#define BRANCH 2

#define MAX_BUF 10000

struct TrieNoder
{
	bool is_end;
	TrieNoder *next[BRANCH];
};

TrieNoder buf[MAX_BUF];
int bufi = 0;

TrieNoder * newTrie() {
	bufi = 0;
	memset(buf, 0, MAX_BUF * sizeof(TrieNoder));	
	return &buf[bufi++];
}

bool insertTrie(TrieNoder *r, char *x) {
	TrieNoder * tmp;
	for (int i=0; x[i]; i++) {
		tmp = r->next[x[i]-'0'];
		if (tmp == 0) {
			tmp = &buf[bufi++];
			r->next[x[i]-'0'] = tmp;
		} else if (x[i+1]==0) {
			return false;
		}
		if (tmp->is_end) {
			return false;
		}	
		r = tmp;
	}
	r->is_end = true;
	return true;
}

char s[100];

int main(int argc, char const *argv[])
{
	//freopen("in.txt", "r", stdin);
	bool nstop = true;
	TrieNoder * r = newTrie();
	int i = 0;
	while (scanf("%s", s) != EOF) {
		if (s[0]=='9') {
			printf("Set %d ", ++i);
			if (nstop) {
				printf("is immediately decodable\n");
			} else {
				printf("is not immediately decodable\n");
			}
			r = newTrie();
			nstop = true;
		} else if (nstop) {
			nstop = insertTrie(r, s);
		}
	}
	return 0;
}