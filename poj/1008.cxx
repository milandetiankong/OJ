#include <cstdio>
#include <cstring>

const char* haab[] = {"pop", "no", "zip", "zotz", "tzec",\
 				"xul", "yoxkin", "mol", "chen", "yax",\
 				"zac", "ceh", "mac", "kankin", "muan",\
 				"pax", "koyab", "cumhu", "uayet"};

const char* tzo[] = {"imix", "ik", "akbal", "kan", "chicchan",\
 				"cimi", "manik", "lamat", "muluk", "ok",\
  				"chuen", "eb", "ben", "ix", "mem",\
   				"cib", "caban", "eznab", "canac", "ahau"};


char buf[20];

int find() {
	for (int i=0; i<sizeof(haab)/sizeof(char *); ++i) {
		if (strcmp(buf, haab[i]) == 0) {
			return i;
		}
	}
	return -1;
}
int main(void) {
	int t;
	int d, m, y;
	long long days;

	int years;
	scanf("%d", &t);
	printf("%d\n", t);
	while (t--) {
		scanf("%d. %s %d", &d, buf, &y);
		m = find();
		days = y*365;
		days += m*20;
		days += d+1; 		
		years = (days-1)/260;
		days = (days-1)%260+1;
		printf("%lld %s %d\n", (days-1)%13+1, tzo[(days-1)%20], years);
	}
}