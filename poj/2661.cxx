#include <cstdio>
#include <cmath>

#define MAX_N 254018

int buf[MAX_N];

int Bfind(int find) {
	int s = 4;
	int t = MAX_N-1;
	int mid = (s + t)/2;
	while (s < mid) {
		if (buf[mid] == find) {
			break;
		} else if(buf[mid] > find) {
			t = mid;
		} else {
			s = mid;
		}
		mid = (s+t)/2;
	}

	if (buf[mid] == find) {
		return mid;
	} else if (buf[mid] > find) {
		return mid-1;
	} else {
		return mid;
	}
	return 0;
}

int main(int argc, char const *argv[])
{
	//freopen("in.txt", "r", stdin);
	int n, y;
	double tmp;
	n = 0;
	tmp = 0.0;
	while (++n<MAX_N) {
		tmp += log(n)/log(2);
		buf[n] = (int)tmp;
	}
	while (scanf("%d\n", &y), y) {
		printf("%d\n", Bfind(pow(2, (y - 1960)/10 + 2)-1));
	}


	return 0;
}