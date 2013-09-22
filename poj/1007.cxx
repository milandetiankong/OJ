#include <cstdio>
#include <algorithm>
using namespace std;

typedef struct
{
	char buf[51];
	int order;	
}Item;

Item s[100];

void getOrder(Item * s, int len){
	char *tmp = s->buf;
	s->order = 0;
	for (int i=0; i < len-1; i++) {
		for (int j=i+1; j < len; j++) {
			if (tmp[i] > tmp[j]) {
				++(s->order);
			}
		}
	}
}
bool compare(const Item &a, const Item &b){
	return a.order < b.order;
}
int main(int argc, char const *argv[])
{
	//freopen("in.txt", "r", stdin);
	int n, m, i;
	scanf("%d %d\n", &n, &m);
	i = 0;
	while ( i < m) {
		scanf("%s\n", s+i);
		getOrder(s+i, n);
		++i;
	}
	stable_sort(s, s+m, compare);
	for (i=0; i<m; i++) {
		printf("%s\n", s[i].buf);
	}
	return 0;
}