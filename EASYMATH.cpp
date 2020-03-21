#include<bits/stdc++.h>

#define lli long long int

using namespace std;

lli include_exclude(lli n, lli a[5]) {
  lli ret = n, lcm[1 << 5] = {1}, sign[1 << 5] = {1};
 
  for (int i = 0; i < 5; ++i) {
    // Process the ith element: Add a[i] to every set processed till now
    for (int j = 0, k = 1 << i; j < (1 << i); ++j, ++k) {
      sign[k] = -sign[j];
      lli g = __gcd(lcm[j], a[i]);
      if (n / lcm[j] < a[i] / g) {
        lcm[k] = n + 1;
      } else {
        lcm[k] = lcm[j] * (a[i] / g);
      }
      ret += sign[k] * (n / lcm[k]);
    }
  }
 
  return ret;
}

int main() {
	ios_base::sync_with_stdio(false);
	lli t, n, m, a, d;
    lli arr[5];
    cin >> t;
    for (; t > 0; t--) {
        cin >> n >> m >> a >> d;
        for (int i = 0; i < 5; i++) {
            arr[i] = a + i*d;
        }
        cout << include_exclude(m, arr) - include_exclude(n-1, arr) << endl;
    }

	return 0;
}
