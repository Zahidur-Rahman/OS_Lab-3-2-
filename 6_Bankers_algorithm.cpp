#include <bits/stdc++.h>

using namespace std;

int main(){

    int prc, res;
    prc = 5;    //Num of Process
    res = 3;    //Num of Resources

    int alloc[prc][res] = { { 0, 1, 0 }, //Allocation Matrix 
                        { 2, 0, 0 },
                        { 3, 0, 2 }, 
                        { 2, 1, 1 }, 
                        { 0, 0, 2 } };
    
    int max[prc][res] = { { 7, 5, 3 }, //Max Need Matrix 
                      { 3, 2, 2 }, 
                      { 9, 0, 2 },
                      { 2, 2, 2 }, 
                      { 4, 3, 3 } };

    int avail[res] = {3,3,2}; //Available Resources

    int finish[prc] = {0}; 
    int ans[prc], indx=0;
    int need[prc][res];

    for(int i=0;i<prc;i++){
        for(int j=0;j<res;j++) need[i][j] = max[i][j] - alloc[i][j];
    }

    int w = 10;
    while(w){
        for(int i=0;i<prc;i++){
            if(finish[i]==0){
                int flag = 0;
                for(int j=0;j<res;j++){
                    if(need[i][j] > avail[j]){
                        flag = 1;
                        break;
                    }
                }
                if(flag==0){
                    ans[indx++] = i;
                    for(int j=0;j<res;j++) avail[j] += alloc[i][j];
                    finish[i] = 1;
                }
            }
        }
        w--;
    }

    int flag = 1;

    for(int i=0;i<prc;i++){
        if(finish[i]==0){
            flag = 0;
            cout<<"The System is not Safe"<<endl;
            break;
        }
    }

    if(flag==1){
        cout<<"The System is Safe"<<endl;
        for(int i=0;i<prc-1;i++) cout<<"P"<<ans[i]<<"->";
        cout<<"P"<<ans[prc-1]<<endl;
    }
}