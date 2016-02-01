#include <bits/stdc++.h>
using namespace std;
typedef long long int llu;

#define MAX (1e6 + 5)
llu N, Q, k;
vector<llu> A;


int main(){
        ios :: sync_with_stdio(false);
        cin >> N >> Q;
        A.resize(N);

        for(int i = 0; i < N; i++)
            cin >> A[i];

        llu globalMin, localMax;
        // For each d, make pairs of A with d items each, find the min(max(p1),max(p2)..)
        // where p1, p2 are the pairs
        while (Q--){
            cin >> k;
            globalMin = LONG_LONG_MAX;
            deque<int> q(k);
            int i;

            for ( i = 0; i < k; i++){
                while(!q.empty() && A[i] >= A[q.back()])
                    q.pop_back();
                q.push_back(i);
            }

            for(; i < N; i++){
                localMax = A[q.front()];
                while (!q.empty() && q.front() <= i - k)
                    q.pop_front();

                while(!q.empty() && A[i] >= A[q.back()])
                    q.pop_back();

                q.push_back(i);
                globalMin = min(globalMin, localMax);
            }
            localMax = A[q.front()];
            globalMin = min(globalMin, localMax);
            cout << globalMin << endl;

        }

        return 0;
}
