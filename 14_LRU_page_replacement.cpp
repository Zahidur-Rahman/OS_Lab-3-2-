#include <bits/stdc++.h>
#define MAX 1000

using namespace std;

//For checking if the page is already present
bool page_search(set<pair<int,int>> st, int n){
    for(auto val: st) if(val.second == n) return true;
    return false;
}
//For replacing pages 
void page_replace(set<pair<int,int>>& frame_set, int n){
    frame_set.erase(frame_set.begin());
    frame_set.insert({MAX,n});
}

//This function is for updating the pages score of recency 
//(Because set of pairs(element) decrement is not straight forward)
void frame_update(set<pair<int,int>>& frame_set, int n){
    //Had to do this two for loop separately due to a bug

    //This is for if the current page(n) is not present
    for(auto it=frame_set.begin(); it!=frame_set.end(); it++){
        pair<int,int> tmp_pair = make_pair((*it).first-1, (*it).second);
        frame_set.erase(it);
        frame_set.insert(tmp_pair);
    }
    //This is for if the current page(n) is present 
    for(auto it=frame_set.begin(); it!=frame_set.end(); it++){
        if((*it).second == n){
            pair<int,int> tmp_pair = make_pair(MAX, (*it).second);
            frame_set.erase(it);
            frame_set.insert(tmp_pair);
        }
    } 
}

int main(){

    int prc_no = 12;
    int pages[prc_no] = {0, 1, 2, 3, 0, 1, 4, 0, 1, 2, 3, 4};
    int capacity = 3;
    int page_fault = 0;

    set<pair<int, int>> frame_set; //page recency score, page no.

    for(int i=0; i<prc_no; i++){

        frame_update(frame_set, pages[i]); //update recency score

        //Actions to take if the page is absent
        if(!page_search(frame_set, pages[i])){
            page_fault++;
            if(frame_set.size()<capacity) frame_set.insert({MAX,pages[i]});
            else page_replace(frame_set, pages[i]);
        }
    }
    //result   
    cout<<page_fault<<endl;
}