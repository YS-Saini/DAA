#include<iostream>
#include<vector>
using namespace std;

bool is_Safe(vector<vector<bool>>& graph,vector<int>& path,int pos,int curr_ver){
    if (!graph[path[pos-1]][curr_ver])
        return false;
    for (int i=0;i<pos;i++){
        if (path[i]==curr_ver)
            return false;
    }
    return true;
}

bool hami_recur(vector<vector<bool>>& graph,vector<int>& path,int pos){
    if (pos==graph.size())
        return true;
    for (int i=1;i<graph.size();i++){
        if (is_Safe(graph,path,pos,i)){
            path[pos]=i;
            if (hami_recur(graph,path,pos+1))
                return true;
            path[pos]=-1;
        }
    }
}

void make_path(vector<vector<bool>> my_graph){
    vector<int> path(my_graph.size(),-1);
    path[0]=0;
    if (hami_recur(my_graph,path,1)){
        for (int i=0;i<path.size();i++){
            cout<<path[i]<<" ";
        }
    }
    else{
        cout<<"No path exists....";
    }
}

main(){
    vector<vector<bool>> my_graph={
        {0, 1, 0, 1, 0},
        {1, 0, 1, 1, 1},
        {0, 1, 0, 0, 1},
        {1, 1, 0, 0, 1},
        {0, 1, 1, 1, 0}
    };
    make_path(my_graph);
}