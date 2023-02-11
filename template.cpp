#include<bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) for(int i=a;i<b;++i)
#define IFOR(i,a,b) for(int i=a-1;i>=b;--i)
#define IO ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define ll long long
#define F first
#define S second
#define pb emplace_back 
#define vi vector<int>
#define vll vector<ll>
#define vvi vector<vi>
#define vvll vector<vll>
#define pii pair<int,int>
#define pll pair<ll,ll>
#define BE(a) a.begin(),a.end()
#define endl '\n'
#define print(arg...) _print_all(#arg,arg);
#define DIM(S) template<typename T> struct Dim<S<T>>{ enum {val = 1 + Dim<T>::val}; };
#define PRYTYFY_DECLARE(U) template<typename ...T>ostream& operator<<(ostream&O,const U<T...> &a); template<typename ...T> void _print(const U<T...> &a,const int idt = 0,typename enable_if< (Dim<U<T...>>::val>1) >::type* = 0);
#define PRYTYFY(U,B,S,E,M,N) template<typename ...T> ostream& operator<<(ostream&O,const U<T...> &a){O<<B; int c=0; for(auto i:a) O<<(c++?S:"")<<M; return O<<E; } template<typename ...T> void _print(const U<T...> &a,const int idt,typename enable_if< (Dim<U<T...>>::val>1) >::type*){cerr<<B; int c=0; int dim = Dim<U<T...>>::val; string sep = S; for(int i=0;i<dim-1;++i) sep += "\n"; for(int i=0;i<idt+1;++i) sep += " "; for(auto i:a){cerr<<(c++?sep:"");N; } cerr<<E; }
template<typename T> struct Dim{enum {val = 0}; }; DIM(vector) DIM(deque) DIM(set) DIM(multiset) DIM(unordered_set) template<typename S,typename T> struct Dim<map<S,T>>{ enum {val = 1 + max((int)Dim<S>::val,(int)Dim<T>::val)}; }; template<typename S,typename T> struct Dim<unordered_map<S,T>>{ enum {val = 1 + max((int)Dim<S>::val,(int)Dim<T>::val)}; }; template<typename S,typename T> struct Dim<pair<S,T>>{ enum{val = max((int)Dim<S>::val,(int)Dim<T>::val)}; }; template<typename T> void _print(const T &a,const int idt = 0,typename enable_if< (Dim<T>::val<=1) >::type* = 0){cerr<<a; } PRYTYFY_DECLARE(vector); PRYTYFY_DECLARE(deque); PRYTYFY_DECLARE(set); PRYTYFY_DECLARE(multiset); PRYTYFY_DECLARE(unordered_set); PRYTYFY_DECLARE(map); PRYTYFY_DECLARE(unordered_map); template<typename T,typename TT> ostream& operator<<(ostream&O,const pair<T,TT> &a); template<typename T,typename TT> void _print(const pair<T,TT> &a,const int idt = 0,typename enable_if< (Dim<pair<T,TT>>::val>1) >::type* = 0); PRYTYFY(vector,"[",", ","]",i,_print(i,idt+1);); PRYTYFY(deque,"[",", ","]",i,_print(i,idt+1);); PRYTYFY(set,"{",", ","}",i,_print(i,idt+1);); PRYTYFY(multiset,"{",", ","}",i,_print(i,idt+1);); PRYTYFY(unordered_set,"{",", ","}",i,_print(i,idt+1);); PRYTYFY(map,"{",", ","}",i.first<<":"<<i.second,_print(i.first,idt+1); cerr<<((Dim<map<T...>>::val) > 2?":\n":":"); _print(i.second,idt+1);); PRYTYFY(unordered_map,"{",", ","}",i.first<<":"<<i.second,_print(i.first,idt+1); cerr<<((Dim<unordered_map<T...>>::val) > 2?":\n":":"); _print(i.second,idt+1);); template<typename T,typename TT> ostream& operator<<(ostream&O,const pair<T,TT> &a){string B = "(",S = ",",E = ")"; return O<<B<<a.first<<S<<a.second<<E; } template<typename T,typename TT> void _print(const pair<T,TT> &a,const int idt,typename enable_if< (Dim<pair<T,TT>>::val>1) >::type*){string B = "(",S = ",",E = ")"; cerr<<B; string sep = S; if(Dim<TT>::val > 1) sep += "\n"; for(int i=0;i<idt+1;++i) sep += " "; _print(a.first,idt+1); cerr<<sep; _print(a.second,idt+1); cerr<<E; } template<typename ...T> void _print_all(const char*s,const T&... a){cerr<<"\033[92m"<<s<<"\033[m"<<" = "; int c=0; ((cerr<<(c++?", ":"")<<(Dim<T>::val>1?"\n":""),_print(a,0)),...); cerr<<"\n"; }

template<typename T> struct Dim{ enum {val = 0}; }; DIM(vector); DIM(deque); DIM(set); DIM(multiset); DIM(unordered_set); template<typename S,typename T> struct Dim<map<S,T>>{ enum {val = 1 + Dim<T>::val}; }; template<typename S,typename T> struct Dim<unordered_map<S,T>>{ enum {val = 1 + Dim<T>::val}; }; template<typename S,typename T> ostream& operator<<(ostream&O,pair<S,T> a){ return O<<"("<<a.first<<", "<<a.second<<")"; } template<typename T> void _print(const char *s,T a,bool nxt_line = false,int idt = 0,int dim = Dim<T>::val,typename enable_if< (Dim<T>::val<=1) >::type* = 0){ bool b = strlen(s); if(b) cerr<<s<<" = "; cerr<<a<<(b?"\n":""); return; }
UGLIFY(vector,"[",", ","]"); UGLIFY(deque,"[",", ","]"); UGLIFY(set,"{",", ","}"); UGLIFY(multiset,"{",", ","}"); UGLIFY(unordered_set,"{",", ","}"); UGLIFY(map,"{",", ","}"); UGLIFY(unordered_map,"{",", ","}"); 
template<typename ...T> void _print_all(const char*s,T... a){ cerr<<s<<" = "; int c=0; ((cerr<<(c++?", ":""),_print("",a,true)),...); cerr<<"\n"; }

signed main(){
	IO;
	return 0;
}