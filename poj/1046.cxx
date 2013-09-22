#include <cstdio>

int r, g ,b;

int buf[16][3];


int main(void) {
	for (int i=0; i<16; ++i) {
		scanf("%d %d %d", buf[i], buf[i]+1, buf[i]+2);
	}
	int D, d;
	r = g = b = 0;
	while (true) {
		scanf("%d %d %d", &r, &g,&b);
		if (r+g+b == -3) {
			break;
		}
		D = 255*255*4;
		d = -1;
		for (int i=0; i<16; ++i) {
			int tmp = (r-buf[i][0])*(r-buf[i][0]) +\
				(g-buf[i][1])*(g-buf[i][1]) +\
				(b-buf[i][2])*(b-buf[i][2]);
			if (tmp < D) {
				d = i;
				D = tmp;
			}
		}
		printf("(%d,%d,%d) maps to (%d,%d,%d)\n",\
			r, g, b, buf[d][0], buf[d][1], buf[d][2]);
	}
}