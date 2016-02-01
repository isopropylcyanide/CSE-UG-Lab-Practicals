#include <bits/stdc++.h>
using namespace std;

// Demonstrate Deadlock avoidance in Operating Systems by using bankers's algorithm

int main(){

	int num_proc,resources;

	cout<<"\nNumber of processes "; cin>>num_proc;
    cout<<"\nNumber of resource types "; cin>>resources;

    int avail_res[resources];
    int max_needed[num_proc][resources];
    int allocated[num_proc][resources];

    cout<<"\nAvailable units of resources: ";
    for(int i = 0; i<resources; i++)cin>>avail_res[i];

    cout<<"\nMaximum resources the processes take: \n";
	for(int i = 0; i<num_proc; i++){
		for(int j = 0; j<resources; j++)
			cin >> max_needed[i][j];
	}

	cout<<"\nAllocated resources the processes have: \n";
	for(int i = 0; i<num_proc; i++){
		for(int j = 0; j<resources; j++)
			cin >> allocated[i][j];
	}



	//Check for enough resources
	//See if the processes release enough resources for a particular process's need
	//Compute a sum of all allocated resources
	vector<int>total_allocated(resources);

	for(int j = 0; j<resources; j++){
		total_allocated[j]= avail_res[j];
		for(int i= 0; i < num_proc; i++)
			total_allocated[j] += allocated[i][j];
	}

	//For each process, if need for each resource <= sum of all other processes's allocated resource
	bool insufficient_resources = false;
	vector <int> resource_heavy;

	for(int i= 0; i < num_proc; i++){
		bool enough_allocated = true;
		for(int j = 0; j<resources; j++){
			if (max_needed[i][j]-allocated[i][j] > total_allocated[j]-allocated[i][j])
				enough_allocated = false;

		}
		if(!enough_allocated){
			insufficient_resources = true;
			resource_heavy.push_back(i+1);
		}
	}

	if (insufficient_resources){
		cout<<"\n Requested greater resources than available: ";
		cout<<"\n Heavy processes is/are : ";
		vector<int>:: iterator si = resource_heavy.begin();
		for(; si != resource_heavy.end(); si++)
			cout<<"-->"<<*si;
		cout<<endl;
		return -1;
	}

	// Create a sequence to hold the no deadlock allocations
	vector<int>final_sequence;

	while(int(final_sequence.size()) != num_proc){
		// Possible bug: if the released resources till now do not suffice the minimum need of the
		// remaining processes

		for(int i= 0; i < num_proc; i++){

			if(find(final_sequence.begin(),final_sequence.end(),i+1) != final_sequence.end())
				continue;

			bool possible = true;

			for(int j = 0; j<resources; j++)
				if (avail_res[j] < (max_needed[i][j]-allocated[i][j]))
					possible = false;

			if (possible){
				// Greedily allocate resource to the process
				final_sequence.push_back(i+1);

				// Release the allocated resources
				for(int j = 0; j<resources; j++)
					avail_res[j] += allocated[i][j];
				}
		}
	}

	cout<<"\nThe sequence to avoid deadlock is : ";
	vector<int>:: iterator si = final_sequence.begin();
	for(; si != final_sequence.end(); si++)
		cout<<"-->"<<"P("<<*si-1<<")";

	cout<<endl;

	return 0;
}
