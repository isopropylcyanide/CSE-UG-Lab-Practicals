#include <bits/stdc++.h>
#include <iostream>
using namespace std;


void lru_replacement(vector<int> & input_pages, const int & page_size){
	cout<<"\n LEAST RECENTLY USED \n";

	static int page_fault=0;
	static int page_hits=0;

	deque<int>window;
	vector<int>::iterator it=input_pages.begin();
	deque<int>::iterator qt=window.begin();


	for(;it!=input_pages.end(); it++){
		cout<<"\n For: "<<*it;
		if (find(window.begin(),window.end(),*it)!=window.end())
			page_hits+=1;
			
		else{
			page_fault+=1;
			if(int(window.size())==page_size) {
				//Replace the least recently used

				map<int,int> queue_used;
				for(qt=window.begin() ;qt!=window.end(); qt++)
					queue_used.insert(make_pair(*qt,0));

				//Find the current index of the loop => j
				//From j down to 0 check which first page_size -1 numbers have appeared

				int current_index=it-input_pages.begin();
				int priority=0;
				int element_to_be_replaced=0;

				vector<bool>already_marked(input_pages.size(),false);	
				for(int j=current_index-1; j>=0; j--){
					if (queue_used.find(input_pages[j])!=queue_used.end() && !already_marked[input_pages[j]]){
						queue_used[input_pages[j]]=priority++;
						already_marked[input_pages[j]]=true;
					}
				}

				int temp=INT_MIN;

				map<int,int>:: iterator mi=queue_used.begin();
				for(;mi!=queue_used.end();mi++){
					if (mi->second>temp){
						element_to_be_replaced=mi->first;
						temp=mi->second;
					}
				}

				cout<<"\t Replacing : "<<element_to_be_replaced<<" with: "<<*it;
				int replace_index = find(window.begin(),window.end(),element_to_be_replaced)-window.begin();
				window[replace_index]=*it;

			}
			else window.push_back(*it);
			cout<<"\t Queue: ";
			for(qt=window.begin() ;qt!=window.end(); qt++)
				cout<<" "<<*qt;
		}

	}	
		cout<<"\n\nTotal page faults: "<<page_fault;
		cout<<"\nTotal page hits: "<<page_hits<<endl;

 }

void optimal_replacement(vector<int> & input_pages,const int & page_size){
	cout<<"\n OPTIMAL REPLACEMENT \n";

	static int page_fault=0;
	static int page_hits=0;

	deque<int>window;
	vector<int>::iterator it=input_pages.begin();
	deque<int>::iterator qt=window.begin();


	for(;it!=input_pages.end(); it++){
		cout<<"\n For: "<<*it;
		if (find(window.begin(),window.end(),*it)!=window.end())
			page_hits+=1;
			
		else{
			page_fault+=1;
			if(int(window.size())==page_size) {
				//Replace the to-be least recently used

				map<int,int> queue_used;
				for(qt=window.begin() ;qt!=window.end(); qt++)
					queue_used.insert(make_pair(*qt,int(input_pages.size())));

				//Find the current index of the loop => j
				//From j upto n check which first page_size -1 numbers have appeared

				int current_index=it-input_pages.begin();
				int priority=0;
				int element_to_be_replaced=0;

				vector<bool>already_marked(input_pages.size(),false);

				for(int j=current_index; j<int(input_pages.size()); j++){
					if (queue_used.find(input_pages[j])!=queue_used.end() && !already_marked[input_pages[j]]){
						queue_used[input_pages[j]]=priority++;
						already_marked[input_pages[j]]=true;
					}
				}

				int temp=INT_MIN;

				map<int,int>:: iterator mi=queue_used.begin();
				for(;mi!=queue_used.end();mi++){
					if (mi->second>temp){
						element_to_be_replaced=mi->first;
						temp=mi->second;
					}
				}

				cout<<"\t Replacing : "<<element_to_be_replaced<<" with: "<<*it;
				int replace_index = find(window.begin(),window.end(),element_to_be_replaced)-window.begin();
				window[replace_index]=*it;

			}
			else window.push_back(*it);
			cout<<"\t Queue: ";
			for(qt=window.begin() ;qt!=window.end(); qt++)
				cout<<" "<<*qt;
		}

	}	
		cout<<"\n\nTotal page faults: "<<page_fault;
		cout<<"\nTotal page hits: "<<page_hits<<endl;

 }

void fifo_replacement(vector<int> & input_pages,const int & page_size){
	cout<<"\n FIRST IN FIRST OUT \n";

	static int page_fault=0;
	static int page_hits=0;

	deque<int>window;
	vector<int>::iterator it=input_pages.begin();
	deque<int>::iterator qt=window.begin();


	for(;it!=input_pages.end(); it++){
		cout<<"\n For: "<<*it;
		if (find(window.begin(),window.end(),*it)!=window.end())
			page_hits+=1;
			
		else{
			page_fault+=1;
			if(int(window.size())==page_size) window.pop_front();
			window.push_back(*it);
			cout<<"\t Queue: ";
			for(qt=window.begin() ;qt!=window.end(); qt++)
				cout<<" "<<*qt;
		}

	}	
		cout<<"\n\nTotal page faults: "<<page_fault;
		cout<<"\nTotal page hits: "<<page_hits<<endl;

 }


int main(){
	char input;
	vector<int>input_pages;

	ifstream infile("input.txt");

	while((input=infile.get())!=EOF){
		if (int(input)==32)continue;
		input_pages.push_back(input-'0');
	}

	infile.close();

	//Enter the variable page_size here
	const int page_size=4;

	fifo_replacement(input_pages,page_size);
	lru_replacement(input_pages,page_size);
	optimal_replacement(input_pages,page_size);

	return 0;
}

