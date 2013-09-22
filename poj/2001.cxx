#include <cstdio>
#include <cstring>

using namespace std;

#define MAX_NUM 26

char buf[1000][21];

struct TrieNode
{
	int cnt;
	TrieNode * next[MAX_NUM];
};

TrieNode * newTrie() {
	TrieNode * root = new(TrieNode);
	for (int i=0; i<MAX_NUM; i++) {
		root->next[i] = 0;
	}
	root->cnt = 0;
	return root;
}


void insertTrie(TrieNode *root, char x[]) {
	int len = strlen(x);	
	TrieNode * pre;
	for (int i=0; i<len; i++) {
		pre = root->next[x[i]-'a'];
		if (!pre) {
			pre = new(TrieNode);
			for (int j=0; j<MAX_NUM; j++) {
				pre->next[j] = 0;
			}
			pre->cnt = 0;
			root->next[x[i]-'a'] = pre;
		}
		root = pre;
		root->cnt++;
	}
}

void find(TrieNode *root, char x[]) {
	int i=0;
	while(x[i]) {	
		putchar(x[i]);
		root = root->next[x[i]-'a'];
		if (root->cnt==1) {
			break;
		}
		i++;
	}	
	putchar('\n');
}

int main(int argc, const char *argv[])
{	
	int i = 0;
	TrieNode * root = newTrie();

	while (scanf("%s", buf[i]) != EOF) {
		insertTrie(root, buf[i]);
		i++;
	}
	for (int j=0; j<i; j++) {
		printf("%s ", buf[j]);
		find(root, buf[j]);
	}
	return 0;
}