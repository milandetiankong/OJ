#include <cstdio>
#include <cmath>
#include <cfloat>

#include <algorithm>


struct Node {
	double x, y;
	bool operator<(const Node &b) const {
		return x<b.x;
	}
};

Node buf[1005];

int main(void) {
	int n, d;	
	int t = 1;
	int x, y;
	int flag;
	while (scanf("%d %d", &n, &d), !(n==0&&d==0)) {
		flag = 0;
		for (int i=0; i<n; ++i) {
			scanf("%d %d", &x, &y);
			if (y>d) {
				flag = 1;
			} else {
				buf[i].x = x- sqrt(d*d - y*y);
				buf[i].y = 2*x-buf[i].x;	
			}
		}

		int sum = 1;
		if (flag) {
			sum = -1;
		} else {
			std::sort(buf, buf+n);
			double left=buf[0].x;
			double right=buf[0].y;
	
			for (int j=1; j<n; ++j) {	
				left = buf[j].x;
				if (left>right) {
					++sum;
					right = buf[j].y;
				} else if (buf[j].y<right){
					right = buf[j].y;
				}
			}
		}
		printf("Case %d: %d\n", t++, sum);
	}
}