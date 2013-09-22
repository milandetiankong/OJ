#include <cstdio>

#include <algorithm>

int buf[65];
bool flag[65];

bool cmp(int i, int j) {
	return i>j;
}


int k;
int len;
int n, sum;

bool dfs(int cur, int ii, int kk) {
	//printf("%d %d %d\n", cur, ii, kk);
	if (kk == k) {
		return true;
	}
	if (cur == len) {
		return dfs(0, 0, kk+1);
	}

	int pre, i;
	for (pre = 0, i=ii; i<n; ++i) {
		if (!flag[i] && buf[i]!=pre && cur+buf[i] <= len) {
			//try
			pre = buf[i];
			flag[i] = true;
			if (dfs(cur+buf[i], ii+1, kk)) {
				//success
				return true;
			}
			//failed
			flag[i] = false;
			if (ii == 0) {
				return false;
			}
		}
	}
	return false;
}


int main()
{
	//freopen("in.txt", "r", stdin);
	while (scanf("%d", &n), n) {
		sum = 0;
		for (int ni=0; ni<n; ni++) {
			scanf("%d", buf+ni);
			sum += buf[ni];
			flag[ni] = false;
		}
		std::sort(buf, buf+n, cmp);
		for (len=buf[0]; len < sum; ++len) {
			if (sum%len) {
				continue;
			}
			//printf("Try:%d %d\n", sum, k);
			k = sum/len;
			if (dfs(0, 0, 0)) {
				break;	
			}
		}
		printf("%d\n", len);
	}
}
