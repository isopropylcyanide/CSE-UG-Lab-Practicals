#include <algorithm>
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
 
#define MAXN 1024
 
 
int l[MAXN + 1], r[MAXN + 1], d[MAXN + 1], n, t, k;
 
// calculates the depth of the current node and every child beneath it.
void calc_depth(int cur, int depth)
{
    d[cur] = depth;
    if (l[cur] > 0) calc_depth(l[cur], depth + 1);
    if (r[cur] > 0) calc_depth(r[cur], depth + 1);
}
 
// prints the tree
void in_order(int cur)
{
    if (l[cur] > 0) in_order(l[cur]);
    cout << cur << " ";
    if (r[cur] > 0) in_order(r[cur]);
}
 
// Input is sample #02
int main()
{
	// read input
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> l[i] >> r[i];
    }
 
    // precalculation
    calc_depth(1, 1);
 
    cin >> t;
    while (t--) {
        cin >> k;
 
        for (int i = 1; i <= n; i++) {
            if (d[i] % k == 0) {
            	// d[i] is a multiple of k
            	// left child of i becomes right, and vice versa
                swap(l[i], r[i]);
            }
        }
 
        // print the answer
        in_order(1);
        cout << endl;
    }
    return 0;
}