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



#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;

int grid[20][20] = {0,};
int tmp[20][20] = {0,};
bool visited[20][20] = {false,};
bool route[20][20] = {false,};
int n; int m;
int move_x[4] = {0,1,0,-1};
int move_y[4] = {1,0,-1,0};
vector<pair<int, int>> bestPath;
vector<pair<int, int>> currentPath;
vector<int> results;

bool canMove(int nx, int ny){
    if(nx<0 || nx>=n || ny<0 || ny>=n) return false;
    return true;
}

int dfs(int x, int y, int time, int current_fruit) {
    if (time >= 3) {
        return current_fruit;
    }
    int max_fruit = current_fruit;
    for (int i = 0; i < 4; ++i) {
        int mx = x + move_x[i];
        int my = y + move_y[i];
        if (canMove(mx, my) && !visited[mx][my]) {
            int fruit = grid[mx][my];
            visited[mx][my] = true;
            currentPath.push_back({mx, my});
            int total_fruit = dfs(mx, my, time + 1, current_fruit + fruit);
            if (results.back() < total_fruit) {
                results.push_back(total_fruit); // 이거였음!!!!!!!!!
                max_fruit = total_fruit;
                if (time == 2) {
                    bestPath = currentPath;
                    // cout << max_fruit<<"/";
                    // for(auto i:bestPath) cout << i.first<<","<<i.second<<"\n";
                }
            }
            currentPath.pop_back();
            visited[mx][my] = false;
        }
    }
    return results.back();
}

int findMax(int x, int y){
    // cout << x<<","<<y<<")\n";
    int start_fruit = grid[x][y];
    visited[x][y] = 1;
    grid[x][y] = 0;
    results.push_back(start_fruit);
    int max_fruit = dfs(x, y, 0, start_fruit);
    visited[x][y] = 0;
    
    for(auto i:bestPath){
        // cout <<"("<< i.first<<"," << i.second<<") ";
        grid[i.first][i.second] = 0;
    }
    currentPath.clear();
    return max_fruit;
}

int main(int argc, char** argv)
{
    int friends[3][3] = {0,};
    int answer = 0;
    cin >> n >> m;
    for(int i=0; i<n; ++i){
        for(int j=0; j<n; ++j) {
            cin >> grid[i][j];
        }
    }
    for(int i=0; i<m; ++i) cin >> friends[i][0] >> friends[i][1];
    memcpy(tmp, grid, sizeof(grid));
    vector<int> mlist;
    for(int i=0; i<m; ++i) mlist.push_back(i);
    do {
        int max = 0;
        memcpy(grid, tmp, sizeof(tmp));
        for (int j = 0; j < m; ++j) {
            int fr = mlist[j];
            max += findMax(friends[fr][0]-1, friends[fr][1]-1);
            // cout << max << "///----\n\n";
        }
        if (answer < max) answer = max;
    } while (next_permutation(mlist.begin(), mlist.end())); // 잘못된 공백 문자 수정
    cout << answer;
   return 0;
}