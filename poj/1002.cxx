#include <cstdio>

int buf[10000000];
char s[32];
char map[100];

int main(int argc, char const *argv[])
{
	//freopen("input.txt", "r", stdin);
	int n, tmp, i, x, y;	
	bool flag;
	map['0'] = 0;
	map['1'] = 1;
	map['2'] = 2;
	map['3'] = 3;
	map['4'] = 4;
	map['5'] = 5;
	map['6'] = 6;
	map['7'] = 7;
	map['8'] = 8;
	map['9'] = 9;

	map['A'] = map['B'] = map['C'] = 2;
	map['D'] = map['E'] = map['F'] = 3;
	map['G'] = map['H'] = map['I'] = 4;
	map['J'] = map['K'] = map['L'] = 5;
	map['M'] = map['N'] = map['O'] = 6;
	map['P'] = map['R'] = map['S'] = 7;
	map['T'] = map['U'] = map['V'] = 8;
	map['W'] = map['X'] = map['Y'] = 9;

	scanf("%d\n", &n);
	while (n--) {
		gets(s);
		for (tmp=0,i=0; s[i]; i++) {
			if (s[i] == '-') {
				continue;
			} else {
				tmp *= 10;
				tmp += map[s[i]];
			}
		}	
		buf[tmp]++ ;
	}
	flag = true;
	for (i=0; i<10000000; i++) {
		if (buf[i] > 1) {
			flag = false;
			y = i % 10000;
			x = i / 10000;
			printf("%03d-%04d %d\n", x, y, buf[i]);
		}
	}
	if (flag) {
		printf("No duplicates.\n");
	}
	return 0;
}