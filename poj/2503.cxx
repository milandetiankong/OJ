#include <cstdio>
#include <cstdlib>

#define BRANCH 26

struct TrieNoder
{
	char * is_words;
	TrieNoder *next[BRANCH];
};

TrieNoder *newTrie() {
	TrieNoder * r = (TrieNoder *)malloc(sizeof(TrieNoder));
	r->is_words = 0;	
	for (int i=0; i<BRANCH; i++) {
		r->next[i] = 0;
	}
	return r;
}

void insertTrie(TrieNoder *r, char *x, char *y) {
	TrieNoder *tmp;	
	for (int i=0; x[i]; i++) {
		if (r->next[x[i]-'a']==0) {
			tmp =(TrieNoder *)malloc(sizeof(TrieNoder));
			tmp->is_words = 0;
			for (int j=0; j<BRANCH; j++) {
				tmp->next[j] = 0;
			}
			r->next[x[i]-'a'] = tmp;
		}
		r = r->next[x[i]-'a'];
	}
	r->is_words = y;
}
char * find(TrieNoder *r, char *x) {
	for (int i=0; x[i]; i++) {
		if (r->next[x[i]-'a']!=0) {
			r = r->next[x[i]-'a'];
		} else {
			return 0;
		}
	}	
	return r->is_words;
}

void delTrie(TrieNoder *r) {
	for (int i=0; i<BRANCH; i++) {
		if (r->next[i]) {
			delTrie(r->next[i]);
		}
	}	
	free(r);
}

char buf[50];
char en[100000][11];

int main(int argc, char const *argv[])
{
	//freopen("in.txt", "r", stdin);
	int eni = 0;
	TrieNoder * r = newTrie();
	int s;
	while (gets(buf)&&buf[0]) {
		for (s=0; buf[s]!=' '; s++) {
			en[eni][s] = buf[s];
		}
		en[eni][s++] = 0;	
		insertTrie(r, buf+s, en[eni]);
		eni++;
	}
	char *ans;
	while(scanf("%s", buf) != EOF) {
		ans = find(r, buf);
		if (ans) {
			printf("%s\n", ans);
		} else {
			printf("eh\n");
		}
	}
	delTrie(r);
	return 0;
}