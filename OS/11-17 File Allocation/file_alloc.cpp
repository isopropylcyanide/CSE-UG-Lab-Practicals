#include <iostream>
#include <map>
#include <set>
#include <list>
#include <vector>
#include <cstdlib>
using namespace std;

#define clear system("clear")

typedef map<int, pair< pair<int,int>,bool > > map_cont;
typedef map<int,list<int> >                   map_link;
typedef map<int,pair<int,vector<int> > >       map_index;

map_cont cont_create(int file_no,map_cont &directory,int size,int &free_space){

    // Employ first fit if possible
    map_cont:: iterator mit = directory.begin();
    bool file_created = false;

    if (mit == directory.end() && size<free_space){
        directory.insert(make_pair(file_no, make_pair(make_pair(0,size) ,true) ) );
        file_created = true;
        free_space -= size;
        return directory;
    }

    for(mit = directory.begin(); mit != directory.end(); mit++){
        //Look for the first hole possible to accomodate

        if (mit->second.second == true) continue;
        else if (mit->second.second== false ){
            if (mit->second.first.second - mit->second.first.first >= size){
                mit->second.first.second = mit->second.first.first+ size;
                mit->second.second = true;
                // mit->first = file_no;
                file_created = true;
                free_space -= size;
                break;
            }
        }
    }

    if (!file_created && size<free_space){
        mit = --directory.end();
        int last_limit = mit->second.first.second;
        free_space -= size;
        directory.insert(make_pair(file_no, make_pair(make_pair(last_limit,last_limit+size) ,true) ) );
    }

    else if(!file_created)
        cout << "\n File cannot be created now. Try defragmentation";

    return directory;
}


map_cont cont_delete(int file_no,map_cont& directory,int &free_space){

    map_cont:: iterator mit = directory.find(file_no);

    if(mit == directory.end()){
        cout << "\n No such file exists. ";
        return directory;
    }

    if(mit->second.second == false){
        cout << "\n File is already deleted";
        return directory;
    }

    else{
        mit->second.second = false;
        free_space += mit->second.first.second - mit->second.first.first;
    }

    return directory;
}


int cont_defragment(map_cont& directory,int & size_hole){

    cout << "\n\n Current hole size: "<< size_hole;
    cout << "\n Trying defragmentation: \n";

    map_cont:: iterator mit = directory.begin();
    if(mit == directory.end())
        return size_hole;

    int last_upper_bound = directory.begin()->second.first.second;
    //Stores the last bound of first file
    mit++;

    for(mit = directory.begin(); mit != directory.end(); mit++){
        if (mit->second.first.first != last_upper_bound ) {
            size_hole -= mit->second.first.first - last_upper_bound;
            int actual_size = mit->second.first.second - mit->second.first.first;
            mit->second.first.first = last_upper_bound;
            mit->second.first.second = mit->second.first.first + actual_size;
        }
        last_upper_bound = mit->second.first.second;
    }

    cout << "\n The new hole size: " << size_hole;
    return size_hole;
}


int cont_directory(map_cont& directory){
    //Display directory structure to the user
    map_cont:: iterator mit = directory.begin();
    int size_hole = 0;

    int last_upper_bound = 0;

    for(mit = directory.begin(); mit != directory.end(); mit++){
        if(mit == directory.begin())
            last_upper_bound = mit->second.first.second;

        if (mit->second.second == false){
            size_hole += mit->second.first.second - mit->second.first.first;
        }

        if(mit != directory.begin())
            size_hole += mit->second.first.first - last_upper_bound;

        cout << "\n Name : " << mit->first << "\t Location: (" << mit->second.first.first << "," << mit->second.first.second << ")" << "\t Valid: " << mit->second.second;
        last_upper_bound = mit->second.first.second;
    }

    cout << "\n\n Hole Size: " << size_hole;
    return size_hole;
}


void contiguous_mode(){

    clear;
    int max_size,choice = 1;
    cout << "\n Enter maximum size of allocation "; cin >> max_size;
    int free_space = max_size;
    int file_count = 0;
    int size_hole = 0;

    map_cont directory;

    while(choice) {
        clear;
        cout << "\n\n FREE(Actual): " << free_space << "\t\t TOTAL: " << max_size;
        cout << "\n\n Directory Structure : \n";

        size_hole = cont_directory(directory);

        cout << "\n\n 1. Create a file ";
        cout << "\n 2: Delete a file ";
        cout << "\n 3: Defragment ";
        cout << "\n 0: Return \t\t";
        cin >> choice;

        switch(choice){
            case 1:
                    int size;
                    cout << "\n Enter the size of the file:  "; cin >> size;
                    cont_create(++file_count,directory,size,free_space);
                    break;

            case 2:
                    int number;
                    cout << "\n Enter the file number to delete: "; cin >> number;
                    cont_delete(number,directory,free_space);
                    break;

            case 3: size_hole = cont_defragment(directory, size_hole);
        }
    }
}

map_link linked_create(int file_no, map_link &directory, int size,int &free_space,set<int>&pointers,const int & max_size){

    if(size>=free_space){
        cout << "\n File too large.";
        return directory;
    }

    list<int> file_pointers;
    while((int)file_pointers.size() != size){
        int temp_index = rand()%max_size;
        if (pointers.find(temp_index) == pointers.end()){
            pointers.insert(temp_index);
            file_pointers.push_back(temp_index);
        }
    }

    directory.insert(make_pair(file_no,file_pointers));
    free_space -= size;
    return directory;
}


map_link linked_delete(int file,map_link &directory,int & free_space,set<int>&pointers){

    if(directory.find(file) == directory.end()){
        cout << "\n No such file exists";
        return directory;
    }

    list<int> file_pointers = directory.find(file)->second;
    list<int>:: iterator it;
    free_space += file_pointers.size();

    for(it = file_pointers.begin(); it != file_pointers.end(); it++)
        pointers.erase(*it);

    directory.erase(directory.find(file));
    return directory;
}

void link_directory(map_link &directory){

    map_link :: iterator mit = directory.begin();

    for(mit = directory.begin(); mit != directory.end(); mit++){

        cout << "\n Name : " << mit->first << "\t Location: ";
        list<int>:: iterator li = mit->second.begin();
        for(; li != mit->second.end(); li++)
            cout << *li << "->";
    }
}

void linked_mode(){

    clear;
    int max_size,choice = 1;
    cout << "\n Enter maximum size of allocation "; cin >> max_size;
    set <int> pointers;

    int file_count = 0;
    int free_space = max_size;
    map_link directory;

    while(choice){
        clear;
        cout << "\n\n FREE(Actual): " << free_space << "\t\t TOTAL: " << max_size;
        cout << "\n\n Directory Structure : \n";
        link_directory(directory);

        cout << "\n\n 1. Create a file ";
        cout << "\n 2: Delete a file ";
        cout << "\n 0: Return \t\t";
        cin >> choice;


        switch(choice){
            case 1:
                int size;
                cout << "\n Enter the size of the file:  "; cin >> size;
                linked_create(++file_count,directory,size,free_space,pointers,max_size);
                break;

            case 2:
                int number;
                cout << "\n Enter the file number to delete: "; cin >> number;
                linked_delete(number,directory,free_space,pointers);
                break;
            }
     }
}

map_index index_create(int file_no, map_index &directory, int size,int &free_space, set<int>&pointers,const int & max_size){

    //Accomodate size of the index block pointer
    if(size+1 >=free_space){
        cout << "\n File too large.";
        return directory;
    }

    //Set a previously unused index block address
    int index = rand()%max_size;
    while (pointers.find(index) != pointers.end())
        index = rand()%max_size;

    pointers.insert(index);

    //Now set the actual file blocks
    vector<int> file_pointers;

    while((int)file_pointers.size() != size){
        int temp_index = rand()%max_size;
        if (pointers.find(temp_index) == pointers.end()){
            pointers.insert(temp_index);
            file_pointers.push_back(temp_index);
        }
    }

    directory.insert(make_pair(file_no,make_pair(index,file_pointers) ) );
    free_space -= size + 1;
    return directory;
}

map_index index_delete(int file,map_index &directory,int & free_space,set<int>&pointers){

    if(directory.find(file) == directory.end()){
        cout << "\n No such file exists";
        return directory;
    }

    pair<int, vector<int> > index_block = directory.find(file)->second;
    vector<int>:: iterator it = index_block.second.begin();

    free_space += index_block.second.size() +1 ;

    // Delete all the blocks in the index block referred by the index block
    for(it = index_block.second.begin(); it != index_block.second.end(); it++)
        pointers.erase(*it);

    //Delete the address of the index block itself as well as the map entry
    pointers.erase(index_block.first);
    directory.erase(directory.find(file));

    return directory;
}

void index_directory(map_index &directory){

    map_index :: iterator mit = directory.begin();
    if (mit == directory.end())
        return;

    for(mit = directory.begin(); mit != directory.end(); mit++){

        cout << "\n Name : " << mit->first << "\t Block Address: " << mit->second.first << "\tBlocks ";
        vector<int>:: iterator li = mit->second.second.begin();
        for(; li != mit->second.second.end(); li++)
            cout << *li << "->";
    }
}

void indexed_mode(){
    clear;
    int max_size,choice = 1;
    cout << "\n Enter maximum size of allocation "; cin >> max_size;
    set <int> pointers;

    int file_count = 0;
    int free_space = max_size;
    map_index directory;

    while(choice){
        clear;
        cout << "\n\n FREE(Actual): " << free_space << "\t\t TOTAL: " << max_size;
        cout << "\n\n Directory Structure : \n";
        index_directory(directory);

        cout << "\n\n 1. Create a file ";
        cout << "\n 2: Delete a file ";
        cout << "\n 0: Return \t\t";
        cin >> choice;


        switch(choice){
            case 1:
                int size;
                cout << "\n Enter the size of the file:  "; cin >> size;
                index_create(++file_count,directory,size,free_space,pointers,max_size);
                break;

            case 2:
                int number;
                cout << "\n Enter the file number to delete: "; cin >> number;
                index_delete(number,directory,free_space,pointers);
                break;
            }
     }
}


int main(){

    int mode;

    while(1) {

        clear;
        cout << "\n Specify file allocation mode: \n";
        cout << "\n 1: Contiguous ";
        cout << "\n 2: Linked ";
        cout << "\n 3: Indexed ";
        cout << "\n 0: Exit \t";
        cin >> mode;

        switch (mode){

            case 1: contiguous_mode(); break;
            case 2: linked_mode();     break;
            case 3: indexed_mode();    break;
            case 0: exit(0);           break;
            default: main();
        }
    }
}
