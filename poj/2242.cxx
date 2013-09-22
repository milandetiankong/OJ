#include <cstdio>
#include <cmath>

double x1, yy1;
double x2, y2;
double x3, y3;

double x, y;

double a, b, c;
double e, f, g;

int main(void) {
	while (scanf("%lf %lf %lf %lf %lf %lf", &x1, &yy1, &x2, &y2, &x3, &y3) != EOF) {
		a = x1 - x2;
		b = yy1 - y2;
		c = a*(x1+x2) + b*(yy1+y2);
		c /= 2.0;

		e = x3-x2;
		f = y3-y2;
		g = e*(x3+x2) + f*(y3+y2);
		g /= 2.0;	

		if (a==0) {
			y = c/b;
			x = (g-f*y)/e;
		} else {
			y = (a*g-e*c)/(a*f - e*b);
			x = (c-b*y)/a;
		}
		printf("%.2f\n", sqrt(pow(x-x1,2)+pow(y-yy1,2))*2*3.141592653589793);
	}
	return 0;
}