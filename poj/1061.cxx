#include <cstdio>

int main(void) {
	long long x, y, m, n, L;
	scanf("%lld %lld %lld %lld %lld", &x, &y, &m, &n, &L);
	long long  xy, mn;
	if (m>n) {
		mn = m - n;
		xy = x - y;
	} else {
		mn = n - m;
		xy = y - x;
	}
	xy = L - xy;
	//mn %= L;
	//xy %= L;
	// mn*k == xy (%L)
	long long s1=1, s2=0, d1, d2, tmp;
	d1 = mn;
	d2 = L;

	while (d2) {
		tmp = s1 - d1/d2*s2;
		s1 = s2;
		s2 = tmp;

		tmp = d1%d2;
		d1 = d2;
		d2 = tmp;
	}

	if (xy%d1 == 0) {
		long long ans = (s1*xy/d1) % (L/d1);
		printf("%lld\n", ans>=0?ans:ans+L/d1);
	} else {
		printf("Impossible\n");
	}
}