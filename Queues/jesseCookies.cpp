#include <bits/stdc++.h>
using namespace std;


template<typename T> void print_queue(T& orig) {
    T q = orig;
    while(!q.empty()) {
        std::cout << q.top() << " ";
        q.pop();
    }
    std::cout << '\n';
}


int main(){
    ios :: sync_with_stdio(false);
    int N, K, temp, maxMoves = 0, first, second, combined;
    cin >> N >> K;

    priority_queue<int, vector<int>, greater<int> > pq;

    for (int i = 0; i < N; i++){
        cin >> temp;
        pq.push(temp);
    }

    while(!pq.empty()){
        if (pq.top() >= K){
            cout << maxMoves<<endl;
            break;
        }

        first = pq.top();
        pq.pop();
        if (pq.empty()){
            cout << -1 << endl;
            break;
        }
        else{
            second = pq.top();
            pq.pop();
            combined = first + (2 * second);
            pq.push(combined);
            maxMoves += 1;
        }
    }

    return 0;
}
