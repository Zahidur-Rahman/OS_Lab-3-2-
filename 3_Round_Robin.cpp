#include <bits/stdc++.h>
#define MAX 1000

using namespace std;

//To check if the element is already in the queue
bool queue_search(queue<int> q, int n){
    while(!q.empty()){
        if(q.front() == n) return true;
        q.pop();
    }
    return false;
}

void print_space(int n){
    while(n){
        cout<<" ";
        n--;
    }
}

int main(){

    int prc_no = 5; //no. of processes
    int ar_time[prc_no] = {0,1,2,3,4}; //arrival time
    int br_time[prc_no] = {6,3,5,1,4}; //burst time
    int time_quant = 2; //Time Quantum
    int time = 0;
    queue<int> ready_queue; //ready queue for processes
    vector<int> ans_vec; //final vector for output

    //first time pushing in the queue;
    for(int i=0; i<prc_no; i++) if(ar_time[i]<=time) ready_queue.push(i);

    while(!ready_queue.empty()){
        br_time[ready_queue.front()] = br_time[ready_queue.front()] - time_quant;
        time = time + time_quant;

        for(int i=0; i<prc_no; i++) if(ar_time[i]<=time && i!=ready_queue.front() && br_time[i]>0 
        && !queue_search(ready_queue,i)) ready_queue.push(i);

        if(br_time[ready_queue.front()] > 0) ready_queue.push(ready_queue.front());
        ans_vec.push_back(ready_queue.front()+1);
        ready_queue.pop();
    }

    //Showing gant chart
    cout<<"Gant chart: "<<endl;
    char sp = '|';
    for(auto val: ans_vec){
        cout<<sp;
        print_space(time_quant);
        cout<<'P'<<val;
        print_space(time_quant);
    }
    cout<<sp<<endl;
}