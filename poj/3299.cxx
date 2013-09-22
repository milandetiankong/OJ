#include <cstdio>
#include <cmath>



double t, d, h;
char buf[5];
double tmp;




double td(double t, double d) {
	return 0.5555*(6.11*pow(2.718281828, 5417.7530*(1/273.16-1/(273.16+d)))-10.0)+t;

}

double th(double t, double h) {
	double e = (h-t)/0.5555+10.0;
	e /= 6.11;
	e = log10(e)/log10(2.718281828)/5417.7530;
	e = 1/273.16 - e;
	e = 1/e;
	return e - 273.16;	
}

double dh(double d, double h) {
 return h - 0.5555*(6.11*pow(2.718281828, 5417.7530*(1/273.16-1/(273.16+d)))-10.0);
}

int main(void) {
	while (scanf("%s", buf), buf[0] != 'E') {
		t = d = h = -1.0;
		scanf("%lf", &tmp);
		if (buf[0]=='T') {
			t = tmp;
		} else if (buf[0]=='D') {
			d = tmp;
		} else {
			h = tmp;
		}

		scanf("%s %lf", buf, &tmp);
		if (buf[0]=='T') {
			t = tmp;
		} else if (buf[0]=='D') {
			d = tmp;
		} else {
			h = tmp;
		}

		if (-1.0 == t) {
			t = dh(d, h);	
		} else if (-1.0 == d) {
			d = th(t, h);
		} else {
			h = td(t, d);
		}

		printf("T %.1f D %.1f H %.1f\n", t, d, h);
	}


	return 0;
}