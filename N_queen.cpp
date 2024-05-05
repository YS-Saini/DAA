#include<iostream>
#include<vector>
using namespace std;

vector<vector<int>> answer;

bool is_safe(int col,int qno,vector<int> my_arr){
    for (int i=0;i<qno;i++){
        if (my_arr[i]==col || abs(col-my_arr[i])==abs(qno-i)){
            return false;
        }
    }
    return true;

}

void get_sol(int n,vector<int> my_arr){
    if (n==my_arr.size()){
        answer.push_back(my_arr);
        return ;
    }
    for (int i=0;i<my_arr.size();i++){
        if (is_safe(i,n,my_arr)){
            my_arr[n]=i;
            get_sol(n+1,my_arr);
        }
    }
}

void display_ans(){
    int m=answer.size();
    int n=answer[0].size();
    for (int i=0;i<m;i++){
        cout<<"Solution "<<i+1<<':';
        for (int j=0;j<n;j++){
            cout<<answer[i][j]<<' ';
        }
        cout<<endl;
    }
}

main(){
    int n=4;
    vector<int> test(n,0);
    get_sol(0,test);
    display_ans();
    
}