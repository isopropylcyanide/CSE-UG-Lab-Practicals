#include <bits/stdc++.h>
using namespace std;
#define mp make_pair

/*Given edge weights a, b, c, d, e, and f, find some minimum non-negative integer (pp) that, when added to one single edge weight in the graph, will get rid of any negative cycles*/

int a, b, c, d, e, f;

int fixNegativeCycles(){
    // Only negative cycles are
    // ABDA, ABCDA, ACDA
    printf("a: %d, b: %d, c: %d, d: %d, e: %d, f: %d,\n",a, b, c, d, e, f );
    int cycleA = a + b + f;
    int cycleB = a + d + e;
    int cycleC = a + b + c + d;

    cout <<"cycle A: "<<cycleA << endl;
    cout <<"cycle B: "<<cycleB << endl;
    cout <<"cycle C: "<<cycleC << endl;

    if (cycleA >=0  && cycleB >= 0 && cycleC >=0)
        return 0;

    if (cycleA < 0 && cycleB < 0 && cycleC < 0){
        vector<int> ans;
        ans.push_back(abs(cycleA));
        ans.push_back(abs(cycleB));
        ans.push_back(abs(cycleC));
        return *max_element(ans.begin(), ans.end());
    }
    vector<int> minE;
   if (cycleA < 0)
       minE.push_back(-cycleA);

   if (cycleB < 0)
       minE.push_back(-cycleB);

   if (cycleC < 0)
       minE.push_back(-cycleC);

   return *min_element(minE.begin(), minE.end());
}


int main(){
    ios :: sync_with_stdio(false);
    cin >> a >> b >> c >> d >> e >> f;

    cout << fixNegativeCycles() << endl;

    return 0;
}
