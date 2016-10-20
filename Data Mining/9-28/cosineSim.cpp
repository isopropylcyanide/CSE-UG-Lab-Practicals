#include <bits/stdc++.h>
using namespace std;

// A program to determine the cosine Similarity of two documents read from a file

#define _DOC_A "text1"
#define _DOC_B "text2"

class Document{
    // A document is a map of words with their frequency
    map<string, int> docMap;
public:
    Document(){}
    void fillDocumentFromFile(ifstream &);
    friend double cosineSimilarity(Document &, Document &);
    ~Document(){
        docMap.clear();
    }
};

double cosineSimilarity(Document &d1, Document &d2){
    // Finds cosine sim between two documents
    double _denoA = 0.0, _denoB = 0.0, _num = 0.0;
    double second;

    for (auto key : d1.docMap){
        second = 0.0;
        if (d2.docMap.find(key.first) != d2.docMap.end())
            second = d2.docMap[key.first];
        _num += key.second * second;
        _denoA += key.second * key.second;
        _denoB += second * second;
    }

    return _num / sqrt(_denoA * _denoB);
}


void Document::fillDocumentFromFile(ifstream &inf){
    // Reads from a file and fills the map
    string str;
    getline(inf, str);
    stringstream ss(str);

    while (ss){
        ss >> str;
        docMap[str] += 1;
    }
    docMap[str] -= 1;
    cout << "\n DOCUMENT MAP: \n";
    for (auto k : docMap)
        cout << "\t" << k.first << " -> " << k.second << endl;
    cout << endl;
}

int main(){
    Document d1, d2;
    ifstream f1(_DOC_A);
    ifstream f2(_DOC_B);

    d1.fillDocumentFromFile(f1);
    d2.fillDocumentFromFile(f2);
    double _cosSim = cosineSimilarity(d1, d2);
    cout << "\n Cosine Similarity : " << fixed << setprecision(4) << _cosSim << "\n\n";
}
