//its a grid problem
// learned how to move in every dierction shortly
//dfs
//how to give conditions on got depth

#include <bits/stdc++.h>
using namespace std;
#define  optimize() ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);

typedef long long ll;
typedef vector<ll> vl;
typedef pair<ll,ll> pl;
typedef vector<pl> vpl;

#define pb push_back
#define sz size()
#define F first
#define S second
#define y() cout << "YES" << endl;
#define n() cout << "NO" << endl;
#define all(x) (x).begin(),(x).end()
#define input(x) for(auto &u:(x)) cin >> u;
#define print(x) for(auto &u:(x)) cout << u;
#define endl '\n'
const  ll mod = 30;
ll tc_C =1;
ll x,y;
char arr[mod][mod];
bool vis[mod][mod];
vl vx ={1,-1,0,0};//upore,niche
vl vy ={0,0,1,-1};//dane,bame
ll cnt = 0;// main ans
void dfs(int xm,int ym){
    vis[xm][ym] = 1;
    cnt++;
    for(int i = 0; i<4;i++){
        //samne,piche ,dane,bame
        ll temx= xm+vx[i];
        ll temy= ym+vy[i];
        if(temx >= 1 && temx <= y && temy >= 1 && temy <= x && !vis[temx][temy] && arr[temx][temy]!='#'){
           dfs(temx,temy); 
        }// chking condition for going to the depth
        // ekahne temx <= x deowar karon\
        accordind to the input x dieh row bujaho hoiche
    }
}
//* main code
void test(){
    cin >> x >> y;
    for(int i = 1 ;i <= y;i++){
        for(int j= 1; j <= x;j++ ){
            cin >> arr[i][j];
        }
    }// input nilam

    for(int i = 1 ;i <= y;i++){
        for(int j= 1; j <= x;j++ ){
            if(arr[i][j]=='@'){
                dfs(i,j);//index of ith  row and jth column
                break;
            }
        }
    }

    cout << "Case " << tc_C << ": " << cnt << endl;
    tc_C++;
    memset(vis,0,sizeof(vis));// reinitilixe the vis vector to store the vistited for next test case
    cnt = 0;
    
    
   
}
  

int main(){
   optimize()
   ll testCase;
   cin >> testCase;
   while(testCase--)
   test();
   
   return 0;
}
