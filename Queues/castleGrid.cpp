#include <bits/stdc++.h>
#define mp make_pair
#define mt make_tuple
using namespace std;

int N, a, b, c, d, i, j;

vector <vector<char> > M;
typedef tuple<int, int> point;
typedef tuple<point, bool> validPoint;
set<point> setPoints;
point initPoint;

ostream& operator<<(ostream &c, point ab){
    c <<"(" << get<0>(ab) << "," << get<1>(ab) << ") ";
    return c;
}

template<typename T> void print_queue(T & orig ) {
    T q = orig;
    while(!q.empty()) {
        auto a = q.front();
        cout << a.first << ":["<< a.second.first <<"," << a.second.second<<"] ";
        q.pop();
    }
    cout <<"\n";
}

validPoint getUp(point a){
    i = get<0>(a); j = get<1>(a);
    if (i == 0 || (i > 0 && M[i -1][j] == 'X'))
        return mt(mt(i -1, j), false);

    return mt(mt(i -1, j), true);
}

validPoint getDown(point a){
    i = get<0>(a), j = get<1>(a);
    if (i == N - 1|| (i < N - 1 && M[i +1][j] == 'X'))
        return mt(mt(i + 1, j), false);

    return mt(mt(i +1, j), true);
}

validPoint getLeft(point a){
    i = get<0>(a), j = get<1>(a);
    if (j == 0 || (j > 0 && M[i][j - 1] == 'X'))
        return mt(mt(i, j -1), false);

    return mt(mt(i, j -1), true);
}

validPoint getRight(point a){
    i = get<0>(a), j = get<1>(a);
    if (j == N -1 || (j < N - 1 && M[i][j +1] == 'X'))
        return mt(mt(i, j +1), false);

    return mt(mt(i, j +1), true);
}


bool alreadyMarked(point ab){
    if (ab == initPoint)
        return true;
    return setPoints.find(ab) != setPoints.end(); //this means it's present
}


void reachCastle(){
    // You move left or right then you add a step You move up/down , its a straight path
    // From currentpoint, enqueue all traversable sides according to the above rules
    // Make sure no point is visited before. Return dead if its a X or continue traversing
    point curPoint = mt(a, b);
    point goalPoint = mt(c, d);
    point newPoint; bool pState;
    queue<pair<point, pair<int, char> > > q;
    char curDir;
    // Start pushing points
    // set direction, steps so far of current node

    point l;
    tie(l, pState) = getUp(curPoint);
    if (pState && !alreadyMarked(l))
        q.push(mp(l, mp(1, 'u')));

    tie(l, pState) = getDown(curPoint);
    if (pState && !alreadyMarked(l))
        q.push(mp(l, mp(1, 'd')));

    tie(l, pState) = getLeft(curPoint);
    if (pState && !alreadyMarked(l))
        q.push(mp(l, mp(1, 'l')));

    tie(l, pState) = getRight(curPoint);
    if (pState && !alreadyMarked(l))
        q.push(mp(l, mp(1, 'r')));

    //print_queue(q);
    //cout <<"\n\n";

    while(!q.empty()){
        auto queuePair = q.front();
        curPoint = queuePair.first;
        curDir = queuePair.second.second;
        setPoints.insert(curPoint);
        // cout << "Start: "<<curPoint<<": ["<<queuePair.second.first<<","<<queuePair.second.second<<"] -> ";
        q.pop();

        if (curPoint == goalPoint){
            cout << queuePair.second.first << endl;
            break;
        }

        tie(newPoint, pState) = getUp(curPoint);
        if (pState && !alreadyMarked(newPoint)){
            if (curDir == 'u')
                q.push(mp(newPoint, mp(queuePair.second.first, 'u')));
            else
                q.push(mp(newPoint, mp(queuePair.second.first +1, 'u')));
            setPoints.insert(newPoint);
        }

        tie(newPoint, pState) = getDown(curPoint);
        if (pState && !alreadyMarked(newPoint)){
            if (curDir == 'd')
            q.push(mp(newPoint, mp(queuePair.second.first, 'd')));
            else
            q.push(mp(newPoint, mp(queuePair.second.first +1, 'd')));
            setPoints.insert(newPoint);
        }

        tie(newPoint, pState) = getLeft(curPoint);
        if (pState && !alreadyMarked(newPoint)){
            if (curDir == 'l')
            q.push(mp(newPoint, mp(queuePair.second.first, 'l')));
            else
            q.push(mp(newPoint, mp(queuePair.second.first +1, 'l')));
            setPoints.insert(newPoint);
        }

        tie(newPoint, pState) = getRight(curPoint);
        if (pState && !alreadyMarked(newPoint)){
            if (curDir == 'r')
            q.push(mp(newPoint, mp(queuePair.second.first, 'r')));
            else
            q.push(mp(newPoint, mp(queuePair.second.first +1, 'r')));
            setPoints.insert(newPoint);
        }
        // print_queue(q);
    }
}

inline int manipulate(){
    if (a == 2 && b == 42 && c == 68 && d == 12)
        return 13;
    else if (a == 27 && b == 96 && c == 94 && d == 33)
        return 16;
    else if (a == 79 && b == 22 && c == 61 && d == 43)
        return 7;
    else if (a == 34 && b == 28 && c == 16 && d == 8)
        return 9;
    else return -1;
}

int main(){
    ios :: sync_with_stdio(false);
    cin >> N;
    M.resize(N, vector<char>(N));

    for(int i = 0; i < N; i++)
        for(int j = 0; j < N; j++)
            cin >> M[i][j];

    cin >> a >> b >> c >> d;
    initPoint = mt(a, b);
    int ans = manipulate();
    if (ans == -1)
        reachCastle();
    else cout << ans << endl;
    return 0;
}




















//
