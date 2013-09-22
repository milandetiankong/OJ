#include <cstdio>

int main()
{
	//freopen("in.txt", "r", stdin);
	int n, m;
	while (scanf("%d %d", &n, &m) != EOF) {
		int sum = 0;
		int r = 1;
		if (m>=9) {
			r = 6;
		}
		m = n-m;
		for (int tmp=n; tmp/=5; sum +=tmp) ;
		for (int tmp=m; tmp/=5; sum -=tmp) ;

		for (; n!=m; n/=5, m/=5) {
			for (int i=m+(n-m)%10; i>m; i--) {
				if (i%5) {
					r = (r*i)%10;
				}
			}
		}

		for (int i=sum%4; i; i--) {
			r /= 2;
			if (r%2) {
				r += 5;
			}
		}
		printf("%d\n", r%10);
	}	
}