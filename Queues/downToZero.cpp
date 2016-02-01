#include <bits/stdc++.h>
using namespace std;
typedef long long int llu;

#define MAX (1e6 + 5)
vector<int> prime;
vector<int> dist;
llu N, Q, num;

void sieve(){
    prime[1] = prime[0] = 0;
	llu i = 2;

    while (i*i < MAX){
        if(prime[i] == 1)
          for(llu j= i*i; j < MAX; j += i)
              prime[j] = 0;
        i +=1;
    }
}

int main(){
    ios :: sync_with_stdio(false);
    prime.resize(MAX, true);
    dist.resize(MAX, 0);
    sieve();
    cin >> Q;


    for (int i = 0; i < Q; i++){
        cin >> num;

        if (num == 0){
            cout << 0 << endl;
            continue;
        }
        queue<llu> q;
        q.push(num);
        dist[num] = 1;

        while(!q.empty()){
            N = q.front();
            q.pop();

            if(dist[N -1] == 0){
                dist[N -1] = dist[N] + 1;
                if (N -1 == 0)
                    break;
                q.push(N -1);
            }

            for(llu i = 2; i*i <= N; i++)
                if (N % i == 0){
                    llu a = max(i, N/i);
                    if (dist[a] == 0){
                        dist[a] = dist[N] +1;
                        q.push(a);
                    }
                }
        }

        cout << dist[0] -1 << endl;
        for(int i = 0; i < MAX; i++)
            dist[i] = 0;
    }
    return 0;
}























//
