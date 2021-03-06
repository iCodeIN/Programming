#include <bits/stdc++.h>
#define MAX 1000100
#define F first
#define S second
#define ll long long int

using namespace std;
 
int n, m, x;
int a[MAX];
bool primo[MAX];
 
void sieve() {
 
    memset(primo, true, sizeof primo);
    primo[0] = primo[1] = false;
 
    for(int i = 2; i < MAX; i++){
        if(primo[i]){
            for(int j = i+i; j < MAX; j+= i)
                primo[j] = false;
        }
    }
}

bool isPrime(ll num) {
   if(num == 1) return true;
   if(num < MAX) return primo[num];
   if( num & 1 ) {
	if (num % 2 == 0 || num % 3 == 0) return false;
        int maxP = sqrt(num) + 2;
        for (int p = 5; p < maxP; p += 6)
            if (num % p == 0 || num % (p+2) == 0) return false;
        return true;

   }
   return false;
}
 
int main() {
 
    sieve();
    scanf("%d", &n);
    for(int i = 0; i < n; i++){
        scanf("%d", &m);
	for(int j = 0; j < m; j++) scanf("%d", &a[j]);
        sort(a, a+m);
        int j = 1;
        ll ans = -1;
        for(int i = 0; i < m; ++i) {
            for(; j < a[i]; ++j) {
                if(isPrime(j)) {
                    ans = j-1;
                    break;
                }
            }
            j = a[i] + 1;
            if(ans != -1) break;
        }

        if(ans == -1) {
            while(true) {
                if(isPrime(j)) {
                    ans = j-1;
                    break;
                }
                ++j;
            }
        }
        printf("%lld\n", ans);
    }
    return 0;
}
