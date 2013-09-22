#include <cstdio>
#include <cstdlib>

int l, c;
char map[1001][1001];

char buf[2024];
int ans[1001][3];

struct TrieNoder
{
	int id;
	TrieNoder *next[26];
	TrieNoder() {
		id = 0;
		for (int i=0; i<26; i++) {
			next[i] = 0;
		}
	}
};

void insertTrie(TrieNoder *r, char *x, int id) {
	for (int i=0; x[i]; i++) {
		if (r->next[x[i]-'A'] == 0) {
			r->next[x[i]-'A'] = new TrieNoder();
		}
		r = r->next[x[i]-'A'];
	}
	r->id = id;
}

int f[8][2] ={	{-1, 0},
				{-1, 1},
				{0, 1},
				{1, 1},
				{1, 0},
				{1, -1},
				{0, -1},
				{-1, -1}};

void search(TrieNoder *r, int x, int y, int k) {
	int xx = x;
	int yy = y;
	while (x>=1 && x<=l && y>=1 && y<=c) {
		char ch = map[x][y];	
		r = r->next[ch-'A'];
		if (r==0) {
			return ;	
		}else if(r->id) {
			if (ans[r->id][0]==0) {
				ans[r->id][0] = xx;	
				ans[r->id][1] = yy;
				ans[r->id][2] = k;
			}
		}
		x += f[k][0];
		y += f[k][1];
	}
}

int main(int argc, char const *argv[])
{
	//freopen("in.txt", "r", stdin);
	int w;
	scanf("%d %d %d", &l, &c, &w);
	for (int li=1; li<=l; li++) {
		scanf("%s", map[li]+1);
	}
	TrieNoder *r = new TrieNoder();
	for (int li=1; li<=w; li++) {
		scanf("%s", buf);
		insertTrie(r, buf, li);
	}

	for (int i=1; i<=l; i++) {
		for (int j=1; j<=c; j++) {
			for (int k=0; k<8; k++) {
				search(r, i, j, k);
			}
		}
	}

	for (int j=1; j<=w; j++) {
		printf("%d %d %c\n", ans[j][0]-1, ans[j][1]-1, ans[j][2]+'A');
	}

	return 0;
}
