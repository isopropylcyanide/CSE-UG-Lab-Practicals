#include <bits/stdc++.h>
using namespace std;

typedef long long int llu;
vector<pair<llu, llu> >pumps;
// Pair of petrol and next distance
llu N, t;

void findMinPoint(){
    llu start = 0, end = 1;
    llu currPet = pumps[start].first - pumps[start].second;

    while (end != start || currPet < 0){
        while (currPet < 0 && start != end){
            currPet -= pumps[start].first - pumps[start].second;
            start = (start +1)%N;

            if (start == 0)
                return;
        }
        currPet += pumps[end].first - pumps[end].second;
        end = (end +1)%N;
    }
    cout << start << endl;
}

int main(){
    ios :: sync_with_stdio(false);
    cin >> N;

    pumps.resize(N);
    for (int i = 0; i < N; i++)
        cin >> pumps[i].first >> pumps[i].second;

    findMinPoint();
    return 0;

}
