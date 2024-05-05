int sumv(vector<int> vec){
    return accumulate(vec.begin(),vec.end(),0);
}

void generatesol(int i, int n, vector<int> vec,vector<int> subset, int sum, vector<vector<int>>& ans){
    if (i >= n && sumv(vec) == sum){
        ans.push_back(vec);
        return;
    }
    else if (i >= n) return;
    vec.push_back(subset[i]);
    generatesol(i+1,n,vec,subset,sum,ans);
    vec.pop_back();
    generatesol(i+1,n,vec,subset,sum,ans);
}

vector<vector<int>> solve(vector<int> subset, int sum){
    vector<vector<int>> ans;
    vector<int> vec;
    int n = subset.size();
    generatesol(0,n,vec,subset,sum,ans);
    return ans;
}


int main() {
    vector<int> vec = {1,2,3,4,5};
    vector<vector<int>> ans = solve(vec,3);
    for (auto i : ans){
        for (auto j : i){
            cout << j << " ";
        }
        cout << endl;
    }
    return 0;
}
