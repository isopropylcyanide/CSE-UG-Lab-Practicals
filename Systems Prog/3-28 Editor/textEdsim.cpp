#include <bits/stdc++.h>
#include <pthread.h>

using namespace std;

/* Implement a simple text editor
   Add, delete data at any point, modify any area of text.
*/
static bool loopRunning = true;
vector<string> lines;

void * readUserInput(void *arg){
    string line;
    while (loopRunning){
        getline(cin, line);
        lines.push_back(line);
    }

    cout << "\n\n ******** TEXT READ *********\n";

    for (auto a : lines)
        cout << a << endl;

    return NULL;
}

void signalSave(int sig){
    if (sig == SIGINT){
        if (loopRunning == false)
            SIG_DFL(SIGINT);
        else
            loopRunning = false;
    }
}



int main(){
    string line;
    signal(SIGINT, signalSave);

    pthread_t userInput;
    pthread_create(&userInput, NULL, readUserInput, NULL);

    pthread_join(userInput, NULL);
}
