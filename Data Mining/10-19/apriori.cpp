#include <bits/stdc++.h>
using namespace std;

#define inputFile "apriorinput"
#define _MIN_SUPPORT 2

vector<set<int> > inputVec;
set<int> allItems;

class ItemSet{
    // An itemset is a collection of items with a given frequency
public:
    set<int> val;
    int freq; //denotes frequency of the above bitset
    ItemSet(){}
    //allow a natural ordering over the itemSet
    bool operator<(const ItemSet &t) const{
        return val < t.val;
    }
};

ostream &operator <<(ostream &c, ItemSet &x){
    for (auto s : x.val)
        c << s << " ";
    c << " Support -> " << x.freq;
    return c;
}

ostream &operator <<(ostream &c, set<int> &x){
    for (auto s : x)
        c << s << " ";
    return c;
}

int countFrequency(set<int> &x){
    // count frequency of set x in inputVec;
    int count = 0;
    for (auto ip : inputVec){
        if (includes(ip.begin(), ip.end(), x.begin(), x.end()))
            count += 1;
    }
    return count;
}

bool allSubsetsinSelected(set<int> &x, vector<ItemSet> &selected){
    // Check if all subsets of x are present in selected;
    int n = x.size();
    vector<int> v;
    for (auto a : x)
        v.push_back(a);

    for (int i = 0; i < pow(2, n); i++){
        vector<int> vv;
        for (int j = 0; j < n; j++){
            if (i & (1 << j))
                vv.push_back(v[j]);
        }
        set<int> ss(vv.begin(), vv.end());
        //check if this set is present in any
        bool flag = 0;
        for (auto item : selected){
            set<int> ip = item.val;
            if (ss.size() == 0 || ss.size() != n -1){
                flag = 1;
                break;
            }
            if (ss == ip){
                flag = 1;
                break;
            }
        }
        if (!flag)
            return false;
    }
    return true;
}


void generateItemSets(set <ItemSet> &candidates, int level){
    // Given a candidate set, generate L set and candidate set of next Level;
    cout << "\n\n\t" << "\e[1;4m" <<"For ITEMSET LEVEL: " << level -1 << "\e[0m\n";

    vector<ItemSet> selected;
    for (auto item : candidates){
        cout << " Candidate: " <<  item;
        if (item.freq >= _MIN_SUPPORT){
            selected.push_back(item);
            cout << "\t\e[3m" << " Selected \e[0m";
        }
        cout << endl;
    }

    // Now compute join of all
    candidates.clear();


    for (int i = 0; i < selected.size(); i++){
        for (int j = i + 1; j < selected.size(); j++){
            set<int> a = selected[i].val;
            set<int> b = selected[j].val;
            set <int> un;
            set_union(a.begin(), a.end(), b.begin(), b.end(), inserter(un, un.end()));
            // cout << "\n union of " << a << " and " << b << " -> " << un;
            if (un.size() == level){
                // we found a good set only if its subsets are in selected
                if (!allSubsetsinSelected(un, selected))
                    break;
                ItemSet ss;
                ss.val = un;
                ss.freq = countFrequency(ss.val);
                candidates.insert(ss);
            }
        }
    }
    if (candidates.size() == 0){
        // We couldn't find anything else;
        cout << "\n\n\t MINING COMPLETED At LEVEL:  " << level;
        cout << "\n\t Final ItemSet: \n\n";
        for (auto ss : selected)
            cout << "\t\e[4;1m" << ss << "\e[0m\n";
        cout << endl;
    }
    else
        generateItemSets(candidates, level + 1);

}

void readFile(ifstream &inf){
    // Read given file and prepare input vec
    int temp;
    string str;

    while (inf){
        set<int> b;
        getline(inf, str);
        stringstream ss(str);
        while (ss){
            ss >> temp;
            b.insert(temp);
            allItems.insert(temp);
        }
        inputVec.push_back(b);
    }
    inputVec.pop_back();

    cout << "\n\t" << "\e[1;4m" <<"Given Transactions\n\e[0m";
    for (int i = 0; i < inputVec.size(); i++)
        cout << "\t" << i + 1 << " : " << "\t" << inputVec[i] << endl;

    cout << "\e[1;3m" << "\n MINIMUM SUPPORT LEVEL: " << _MIN_SUPPORT <<"\e[0m";
    cout << endl;
}

int main(){
    // Read input from file and prepare inputVec
    ifstream inf(inputFile);
    assert(inf);
    readFile(inf);

    set<ItemSet> candidates;
    for (auto x : allItems){
        ItemSet ss;
        ss.val.insert(x);
        ss.freq = countFrequency(ss.val);
        candidates.insert(ss);
    }

    generateItemSets(candidates, 2);

    return 0;
}
