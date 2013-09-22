#include <cstdio>

int main(void) {
	int n;
	scanf("%d", &n);
	printf("INTERSECTING LINES OUTPUT\n");
	for (int i=0; i<n; ++i) {
		int x1, y1;
		int x2, y2;
		int x3, y3;
		int x4, y4;
		
		scanf("%d %d %d %d %d %d %d %d", &x1, &y1, &x2, &y2, &x3, &y3, &x4, &y4);
		
		int x12 = x2 - x1;
		int x34 = x4 - x3;
		
		if (x12 && x34) {
			double k1 =(y2-y1)/(double)x12; 
			double k2 =(y4-y3)/(double)x34;
			
			double b1 = (y1-k1*x1);
			double b2 = (y4-k2*x4);
			
			if (k1 == k2) {
				if ( b1==b2 ) {
					printf("LINE\n");
				} else {
					printf("NONE\n");
				}
				continue;
			}
			double x = (b2-b1)/(k1-k2);
			double y = x*k2+b2;
			printf("POINT %.2f %.2f\n", x, y);
		}else if (x12) {
			double k1 = (y2-y1)/(double)x12;
			double b1 = y2 - k1*x2;
			double x = x3;
			double y = k1*x3 + b1;
			printf("POINT %.2f %.2f\n", x, y);
			
		}else if (x34){

			double k2 = (y4-y3)/(double)x34;
			double b2 = y4 - k2*x4;
			double x = x1;
			double y = k2*x1 + b2;
			printf("POINT %.2f %.2f\n", x, y);
			
		}else {
			if (x1 == x3) {
				printf("LINE\n");
			}else {
				printf("NONE\n");
			}
		}
		
	}
	printf("END OF OUTPUT\n");
}