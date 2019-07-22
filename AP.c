#include <stdio.h>
 
unsigned int v[100000], FL[30001], FR[30001];
 
#define min(a, b) ((a) < (b) ? (a) : (b))
#define max(a, b) ((a) > (b) ? (a) : (b))
 
int main()
{
	int i, n, tmp;
  	scanf("%d", &n);
  	
  	for(i=0; i<n; i++)
	{
		scanf("%d", &tmp);
		FR[30000 - (v[i] = tmp)]++;
	}
	
	FR[30000-v[0]]--;
	int minL=v[0], maxL = v[0];
	
	long long ans = 0;
	
	n--;
	for(i=1; i<n; i++)
	{
		int last = v[i-1], cur = v[i];
		if(last < minL) minL = last;
		else if(last > maxL) maxL = last;
		
		FL[last]++;
		FR[30000 - cur]--;
		
		int xx = cur<<1, lo = max(minL, xx - 30000), hi = min(maxL, xx - 1);
		
		unsigned int tmp = 0, *p1 = FL + lo, *lp1 = FL + hi - 14, *p2 = FR + 30000 - xx + lo;
		while(p1 <= lp1)
		{
			tmp += (*p1) * (*p2) + (*(p1+1)) * (*(p2+1)) + (*(p1+2)) * (*(p2+2)) + (*(p1+3)) * (*(p2+3)) + (*(p1+4)) * (*(p2+4))
		 + (*(p1+5)) * (*(p2+5)) + (*(p1+6)) * (*(p2+6)) + (*(p1+7)) * (*(p2+7)) + (*(p1+8)) * (*(p2+8)) + (*(p1+9)) * (*(p2+9))
		 + (*(p1+10)) * (*(p2+10)) + (*(p1+11)) * (*(p2+11)) + (*(p1+12)) * (*(p2+12)) + (*(p1+13)) * (*(p2+13)) + (*(p1+14)) * (*(p2+14));
			
			p1 += 15; p2 += 15;
		}
		while(p1 <= FL+hi) tmp += (*(p1++)) * (*(p2++));
		ans += tmp;
	}
	
	printf("%lld\n", ans);
	return 0;
}   