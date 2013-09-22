#include <cstdio>

int main(void) {
	int a1, a2, a3, a4, a5, a6;
	while (scanf("%d %d %d %d %d %d", &a1, &a2, &a3\
		, &a4, &a5, &a6), a1+a2+a3+a4+a5+a6) {
		int sum = a6;
		while (a5>0) {
			++sum;
			a1 -= 11;
			--a5;
		}

		while (a4>0) {
			++sum;
			if (a2>=5) {
				a2 -= 5;
			} else if (a2>0) {
				a1 -= (5-a2)*4;
				a2 = 0;
			} else {
				a1 -= 20;
			}
			--a4;
		}

		if (a3>3) {
			sum += a3/4;
			a3 %= 4;
		}
		while (a3>0) {
			if(a3==3){
				a3 = 0;
				if (a2>0) {
					--a2;
					a1 -= 5;
				} else {
					a1 -= 9;
				}
				++sum;
			} else if(a3==2) {
				a3 = 0;
				if (a2>=3) {
					a2 -= 3;
					a1 -= 6;
				} else if(a2>0) {
					a1 -= (3-a2)*4;
					a2 = 0;
					a1 -= 6;
				} else {
					a2 = 0;
					a1 -= 18;
				}
				++sum;
			} else {//a3==1;
				a3 = 0;
				if (a2>=5) {
					a2 -= 5;
					a1 -= 7;
				} else if(a2>0) {
					a1 -= (5-a2)*4;
					a2 = 0;
					a1 -= 7;
				} else {
					a2 = 0;
					a1 -= 27;
				}
				++sum;
			}
		}

		if (a2>8) {
			sum += a2/9;
			a2 %= 9;
		}
		if (a2>0) {
			a1 -= (9-a2)*4;
			a2 = 0;	
			++sum;
		}



		if (a1>35) {
			sum += a1/36;
			a1 %= 36;

		}
		if (a1>0) {
			++sum;
		}	
		printf("%d\n", sum);
	}
}