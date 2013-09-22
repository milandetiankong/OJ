#include <cstdio>


int main(void) {
	int xa, xb, xc, xk;
	while (scanf("%d %d %d %d", &xa, &xb, &xc, &xk), xa+xb+xc+xk) {
		long long n, b, a;
		//a*x + n*y = b 
		n = 1;
		n <<= xk;
		b = xb - xa;
		if (b<0) {
			b += n;
		}
		a = xc;
		long long s1=0, s2=1, d1=n, d2=a, tmp;
		while (d2) {
			tmp = s1 - (d1/d2)*s2;
			s1 = s2;
			s2 = tmp;

			tmp = d1%d2;
			d1 = d2;
			d2 = tmp;
		}
		//gcd = d1; x= s1
		if (b%d1) {
			printf("FOREVER\n");
		} else {	
			s1 *= b/d1;
			s1 %= (n/d1);
			if (s1<0) {
				s1 += n/d1;
			}
			printf("%lld\n", s1);
		}
	}

}