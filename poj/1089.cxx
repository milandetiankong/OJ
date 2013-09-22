#include <cstdio>

#include <algorithm>

struct Interval
{
	int start;
	int end;
};

Interval buf[50001];

bool compare(const Interval &a, const Interval &b) {
	return a.start < b.start;
}
int main(int argc, char const *argv[])
{
	int n;
	scanf("%d", &n);
	for (int i=0; i<n; i++) {
		scanf("%d %d", &buf[i].start, &buf[i].end);
	}
	std::sort(buf, buf+n, compare);

	int s = buf[0].start;
	int e = buf[0].end;

	for ( int i=1; i<n; i++) {	
		if (buf[i].start <= e) {
			e = e < buf[i].end ? buf[i].end:e;
		} else {
			printf("%d %d\n", s, e);
			s = buf[i].start;
			e = buf[i].end;
		}
	}
	printf("%d %d\n", s, e);
	return 0;
}