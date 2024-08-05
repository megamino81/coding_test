// 함께하는 효도
// https://softeer.ai/practice/7727

#include<iostream>
#include<vector>
using namespace std;
int n,m;
int ans;
int dy[4]={1,-1,0,0};
int dx[4]={0,0,1,-1};
int arr[21][21];
int temp_arr[21][21];
int temp_sum;
bool isSelected[3];
int nums[3];
vector<pair<int,int>>save_paths;
vector<pair<int,int>>start_pos;
struct info{
    int y,x,cnt;
};

void init(){
    temp_sum=0;
    save_paths.clear();
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            temp_arr[i][j]=arr[i][j];
        }
    }
}

void input(){
    cin>>n>>m;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>arr[i][j];
        }
    }
    for(int i=0;i<m;i++){
        int y,x;
        cin>>y>>x;
        start_pos.push_back({y-1,x-1});
    }
}
bool isValid(int y,int x){
    return y>=0 && x>=0 && y<n && x<n;
}
void dfs(int y,int x,int depth,vector<pair<int,int>>&paths){
    if(depth==3){
        int sum=0;
        bool visited[21][21]={false,};
        for(auto p:paths){
            int cy=p.first;
            int cx=p.second;
            if(!visited[cy][cx]){
                sum+=temp_arr[cy][cx];
                visited[cy][cx]=true;
            }
        }
        if(temp_sum<sum){
            temp_sum=sum;
            save_paths=paths;
        }
        return;
    }
    for(int i=0;i<4;i++){
        int ny=y+dy[i];
        int nx=x+dx[i];
        if(!isValid(ny,nx))continue;
        paths.push_back({ny,nx});
        dfs(ny,nx,depth+1,paths);
        paths.pop_back();
    }
}

void permutation(int depth){
    if(depth==m){
        int temp_ans=0;
        init();
        for(int i=0;i<m;i++){
            temp_sum=0;
            
            int y=start_pos[nums[i]].first;
            int x=start_pos[nums[i]].second;
            
            vector<pair<int,int>>temp_paths;
            
            temp_paths.push_back({y,x});
            dfs(y,x,0,temp_paths);
            
            temp_ans+=temp_sum;
            for(auto p:save_paths){
                temp_arr[p.first][p.second]=0;
            }
        }
        ans=max(ans,temp_ans);
    }
    for(int i=0;i<m;i++){
        if(!isSelected[i]){
            isSelected[i]=true;
            nums[depth]=i;
            permutation(depth+1);
            isSelected[i]=false;
        }
    }
}

int main(int argc, char** argv)
{
    input();
    permutation(0);
    cout<<ans;
    return 0;
}