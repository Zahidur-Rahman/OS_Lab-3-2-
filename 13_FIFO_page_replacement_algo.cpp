#include <bits/stdc++.h>

using namespace std;

int main(){

    int n = 13;
    int pages[n] = {7, 0, 1, 2, 0, 3, 0, 4, 2, 3, 0, 3, 2};
    int capacity = 4;

    set<int> page_set;
    queue<int> page_queue;

    int page_faults = 0;

    for(int i=0;i<n;i++){
        if(page_set.size() < capacity){
            if(page_set.find(pages[i]) == page_set.end()){
                page_set.insert(pages[i]);
                page_queue.push(pages[i]);
                page_faults++;
            }
        }
        else{
            if(page_set.find(pages[i]) == page_set.end()){
                int tmp = page_queue.front();
                page_queue.pop();
                page_set.erase(tmp);
                page_set.insert(pages[i]);
                page_queue.push(pages[i]);
                page_faults++;
            }
        }
    }
    cout<<"Page Faults: "<<page_faults<<endl;
}