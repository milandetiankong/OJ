#include <cstdio>
#include <cstdlib>


#define MAX_NUM 10
#define MAX_ST 100000

struct TrieNoder
{
	int is_word;
	TrieNoder *next[MAX_NUM];
};


char buf[11];
TrieNoder st[MAX_ST];

int sti = 0;

TrieNoder * newTrie() {
	TrieNoder * r = &st[sti++];
	r->is_word = 0;
	for (int i=0; i<MAX_NUM; i++) {
		r->next[i] = 0;
	}	
	return r;
}

int insertTrie(TrieNoder *r, char x[]) {
	TrieNoder * tmp;
	for (int i=0; x[i]; i++) {
		if (r->next[x[i]-'0']==0) {
			tmp = &st[sti++];
			tmp->is_word = 0;
			for (int j=0; j<MAX_NUM; j++) {
				tmp->next[j] = 0;
			}	
			r->next[x[i]-'0'] = tmp;
		}
		r = r->next[x[i]-'0'];
		if (r->is_word==-1) {
			return 1;
		}
		r->is_word++;
	}
	if (r->is_word>1) {
		return 1;
	} else {
		r->is_word = -1;
	}

	return 0;
}

int main(int argc, char const *argv[])
{	
	//freopen("in.txt", "r", stdin);
	int t, n;
	scanf("%d", &t);
	while (t--) {
		sti = 0;
		TrieNoder *r = newTrie();
		int stop = 0;
		scanf("%d", &n);
		while (n--) {
			scanf("%s", buf);
			if (!stop) {
				stop = insertTrie(r, buf);
			}
		}
		if (stop) {
			printf("NO\n");
		}else {
			printf("YES\n");
		}
	}
	return 0;
}