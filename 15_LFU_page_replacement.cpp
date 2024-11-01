#include <bits/stdc++.h>
#define MAX 100000;

using namespace std;

int main(){

    int n = 9;
    int pages[n] = { 5, 0, 1, 3, 2, 4, 1, 0, 5 };
    vector<int> page_vec;
    map<int,int> page_map;
    int capacity = 4;
    int page_faults = 0;

    for(int i=0;i<n;i++) page_map.insert({pages[i],0});

    for(int i=0;i<n;i++){

        int find = 0;
        for(auto val: page_vec){
            if(val == pages[i]) find = 1;
        }  
        if(page_vec.size() < capacity){
            if(!find){
                page_vec.push_back(pages[i]);
                page_faults++;
            }
        }
        else{
            if(!find){
                int min = MAX;
                int m_key;
                auto d_it = page_vec.begin();      //delete this iterator in line 41
                for(auto it=page_vec.begin(); it<page_vec.end(); it++){
                    if(page_map[*it]<min){
                        min = page_map[*it];
                        m_key = *it;
                        d_it = it;
                    }
                }
                page_vec.erase(d_it);
                page_vec.push_back(pages[i]);
                page_faults++;
            }
            page_map[pages[i]]++;
        }
    }
    cout<<"Page Faults: "<<page_faults<<endl;
}