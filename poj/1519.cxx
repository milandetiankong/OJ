#include <cstdio>


int main(int argc, char const *argv[])
{
	//freopen("in.txt", "r", stdin);
	char ch;
	int r = 0;
	bool start=true;
	while (ch = getchar()) {
		if (start && ch=='0'){
			break;
		}
		if ('\n' == ch) {
			printf("%d\n", r);
			r = 0;
			start = true;
			continue;
		}
		start = false;
		r +=  ch-'0';
		if (r >= 10) {
			r %= 10;
			++r;
		}
	}
	return 0;
}