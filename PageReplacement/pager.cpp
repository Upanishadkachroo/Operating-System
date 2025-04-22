#include<bits/stdc++.h>
#include<vector>
#include<unordered_map>
#include<fstream>
using namespace std;

struct Stats{
    int faults=0;
    int hits=0;
};

void printframes(const vector<int> &frames){
    for(size_t i=0; i<frames.size(); i++){
        cout<<frames[i];
        if(i<frames.size()-1) cout<<",";
    }
}

Stats simulatelru(int framecnt, const vector<int> &ip_string){
    vector<int> frames;
    unordered_map<int, int> used;
    Stats stats;

    cout<<"LRU: PAGE REPLACEMENT"<<endl;

    for(int i=0; i<ip_string.size(); i++){
        int pg=ip_string[i];
        cout<<"Step"<<i+1 <<pg<<"-";

        auto it=find(frames.begin(), frames.end(), pg);
        if(it!=frames.end()){
            stats.hits++;
            used[pg]=i;
            printframes(frames);
            cout<<"HIT"<<endl;
        }
        else{
            stats.faults++;
            if(frames.size()<framecnt){
                frames.push_back(pg);
            }
            else{
                int lruindex=i;
                int victim=-i;
                for(int f: frames){
                    if(used[f]<lruindex){
                        lruindex=used[f];
                        victim=f;
                    }
                }
                auto itvictim=find(frames.begin(), frames.end(), victim);
                *itvictim=pg;
            }
            used[pg]=i;
            printframes(frames);
            cout<<"PAGE FAULT"<<endl;
        }
    }
    return stats;
}

int main(){
    string choice;
    cout<<"LRU OR MRU ?"<<endl;
    cin>>choice;

    if(choice != "LRU" && choice != "MRU"){
        cout<<"Invalid choice"<<endl;
        return 1;
    }

    int framecnt, n;
    cout<<"Enter no. of frames";
    cin>>framecnt;

    cout<<"Enter the length of ip_string";
    cin>>n;

    vector<int> ip_string(n);
    cout<<"ENter the input string";
    for(int i=0; i<n; i++){
        cin>>ip_string[i];
    }

    Stats stats;

    if(choice=="LRU"){
        stats=simulatelru(framecnt, ip_string);
    }
    else{
        // stats=simulatemru(framecnt, ip_string);
    }

    //make csv of the output
    bool filehai=filesystem::exists("output.csv");

    ofstream fout("output.csv", ios::app);
    if(!filehai){
        fout<<"lru and mru data";
    }

    fout<<(choice == "lru" ? "LRU":"MRU")<<","<<stats.faults<<","<<stats.hits<<endl;
    fout.close();

    cout<<"SImulation completed"<<endl;
    cout<<"page faults: "<<stats.faults<<endl;
    cout<<"page hits: "<<stats.hits<<endl;
    cout<<"resilt is in output.csv file"<<endl;
}