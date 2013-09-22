#include <cstdio>
long long abs(long a) {
	return a>=0?a:-a;
}
int main(void) {
	int a, b, d, swap;
	while (scanf("%d %d %d", &a, &b, &d), a+b+d) {
		swap = 0;
		if (a<b) {
			a +=b;
			b = a-b;
			a -= b;
			swap = 1;
		}	
		//ax+by=d
		long long s1=0, s2=1, d1=a, d2=b, tmp;	
		while (d2) {
			tmp = s1-d1/d2*s2;
			s1 = s2;
			s2 = tmp;

			tmp = d1%d2;
			d1 = d2;
			d2 = tmp;
		}
		//printf("%lld %lld %lld\n", s1, d1, s2	);
		s1 *= d/d1;
		long long len = a/d1;
		s1 %= len;
		if (s1<0) {
			s1 += len;
		}
		//ax+by=d a>b
		long long y0 = s1;
		long long x0;

		long long t = s1/len;

		long long y1 = y0 - t*len; 
		long long x1 = (d-b*y1)/a;
		t += 1;
		long long y2 = y0 - t*len;
		long long x2 = (d-b*y2)/a;

		x1 = abs(x1);
		y1 = abs(y1);

		x2 = abs(x2);
		y2 = abs(y2);

		if (x1+y1<x2+y2) {
			x0 = x1;
			y0 = y1;
		} else if (x2+y2<x1+y1) {
			x0 = x2;
			y0 = y2;
		} else if (x1*a + y1*b <= x2*a+y2*b){
			x0 = x1;
			y0 = y1;
		} else {
			x0 = x2;
			y0 = y2;
		}
		if (swap) {
			tmp = x0;
			x0 = y0;	
			y0 = tmp;
		}
		printf("%lld %lld\n", x0, y0);
	}
}