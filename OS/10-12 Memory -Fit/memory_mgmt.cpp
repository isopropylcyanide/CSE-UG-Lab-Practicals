#include <bits/stdc++.h>
using namespace std;

static int curr_match;

//compile with the flag -std = c++0x

void display_block(vector<int> & blocks){
	vector<int>:: iterator it = blocks.begin();
	for(;it != blocks.end();it++)
		cout<<" "<<*it;
}

bool predicate_first_fit(int i){
	/*A filter function that returns true if the block is able to store the required memory
	denoted by i and curr_match respectively*/
	return i>=curr_match;
}

void first_fit(vector<int>& blocks,vector<int> & procs){

	cout<<" FIRST FIT MEMORY ALLOCATION: ";
	cout<<"\t Free Blocks: "; display_block(blocks);
	cout<<endl;

	vector<int>:: iterator it = procs.begin();
	for(;it != procs.end();it++){

		curr_match=*it;

		vector<int>:: iterator si = find_if(blocks.begin(),blocks.end(),predicate_first_fit);

		if (si == blocks.end())
			cout<<"\n"<<*it<<"K must wait for memory.";

		else{
			cout<<"\n"<<*it<<"K is put in "<<*si<<"K partition";
			int index_of_block = si-blocks.begin();
			blocks[index_of_block]-=*it;
		}
		cout<<"\t Free Blocks: "; display_block(blocks);
	}
	cout<<endl<<endl;
}

void best_fit(vector<int>& blocks,vector<int> & procs){

	cout<<" BEST FIT MEMORY ALLOCATION: ";
	cout<<"\t Free Blocks: "; display_block(blocks);
	cout<<endl;

	vector<int>:: iterator it = procs.begin();
	for(;it != procs.end();it++){

		sort(blocks.begin(),blocks.end());
		vector<int>:: iterator si = upper_bound(blocks.begin(),blocks.end(),*it);

		if (si == blocks.end())
			cout<<"\n"<<*it<<"K must wait for memory.";

		else{
			cout<<"\n"<<*it<<"K is put in "<<*si<<"K partition";
			int index_of_block = si-blocks.begin();
			blocks[index_of_block]-=*it;
		}
		cout<<"\t Free Blocks: "; display_block(blocks);
	}
	cout<<endl<<endl;
}

void worst_fit(vector<int>& blocks,vector<int> & procs){

	cout<<" WORST FIT MEMORY ALLOCATION: ";
	cout<<"\t Free Blocks: "; display_block(blocks);
	cout<<endl;

	vector<int>:: iterator it = procs.begin();
	for(;it != procs.end();it++){

		curr_match=*it;
		auto largest_block_index = 0;
		auto largest_block_size = 0;

		vector<int>:: iterator si = find_if(blocks.begin(),blocks.end(),predicate_first_fit);

		if (si == blocks.end())
			cout<<"\n"<<*it<<"K must wait for memory.";

		else{
			while (si != blocks.end()){
				if (*si>largest_block_size){
					largest_block_size = *si;
					largest_block_index = si - blocks.begin();
				}
				si = find_if(next(si),blocks.end(),predicate_first_fit);
			}

			cout<<"\n"<<*it<<"K is put in "<<largest_block_size<<"K partition";
			blocks[largest_block_index]-=*it;
		}
			cout<<"\t Free Blocks: "; display_block(blocks);
	}
	cout<<endl<<endl;
}

void next_fit(vector<int>& blocks,vector<int> & procs){

	cout<<" NEXT FIT MEMORY ALLOCATION: ";
	cout<<"\t Free Blocks: "; display_block(blocks);
	cout<<endl;
	int offset = 0;

	vector<int>:: iterator it = procs.begin();
	for(;it != procs.end();it++){

		curr_match=*it;
		vector<int>:: iterator si = find_if(blocks.begin()+offset,blocks.end(),predicate_first_fit);

		if (si == blocks.end())
			cout<<"\n"<<*it<<"K must wait for memory.";

		else{
			cout<<"\n"<<*it<<"K is put in "<<*si<<"K partition";
			int index_of_block = si-blocks.begin();
			offset = index_of_block+1;
			if (offset == (int) blocks.size())
				offset = 0;

			blocks[index_of_block] -= *it;
		}
		cout<<"\t Free Blocks: "; display_block(blocks);
	}
	cout<<endl<<endl;
}
int main(){

	vector<int> blocks,procs;
	string size,buf;
	cout<<"Enter the partition details: ";

	getline(cin,size);
	stringstream ss(size);
	while(ss>>buf)
		blocks.push_back(stoi(buf));

	cout<<"Enter the memory required by processes: ";

	getline(cin,size);
	stringstream ss1(size);
	while(ss1>>buf)
		procs.push_back(stoi(buf));

	vector<int> saved_block(blocks);
	first_fit(blocks,procs);	blocks = saved_block;
	best_fit(blocks,procs);		blocks = saved_block;
	worst_fit(blocks,procs);	blocks = saved_block;
	next_fit(blocks,procs);

	return 0;
}
