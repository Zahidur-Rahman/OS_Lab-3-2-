//Non-Preemtive

#include <bits/stdc++.h>
#define Max 100000

using namespace std;

int main(){

    int prc_no = 6; //no. of processes

    int pr[prc_no] = {2,1,3,4,3,5}; //Priority --> the lower the higher
    int ar[prc_no] = {3,2,5,4,1,0}; //Arrival time
    int br[prc_no] = {5,4,1,7,6,2}; //Burst time

    set<pair<pair<int,int>, int>> prc_set; //{{priority, arrival time}, prc no.}
    vector<int> ans_vec; //Final answer vector

    int time = 0;
    
    //first time initializing the process set
    for(int i=0;i<prc_no;i++) if(ar[i]<=time) prc_set.insert({{pr[i],ar[i]}, i}); 

    while(!prc_set.empty()){
        auto it = prc_set.begin(); //storing the first process to work with
        ans_vec.push_back((*it).second); //pushing process no. to answer vector
        time = time + br[(*it).second]; //increasing time according to process burst time
        pr[(*it).second] = 0; //marking the complete process by setting it's priority to zero
        prc_set.erase(it); //removing the complete process

        //inserting processes within the time range
        for(int i=0;i<prc_no;i++) if(ar[i]<=time && pr[i]!=0) prc_set.insert({{pr[i],ar[i]}, i}); 

        //for higher priority higher just reverse the set by rbegin, rend
    }

    for(auto val: ans_vec) cout<<val+1<<" ";
    cout<<endl;
}