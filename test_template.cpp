#include<bits/stdc++.h>
using namespace std;
//#define ENABLE_COLOR
#define print(arg...) _print_all(#arg,arg);

// dimension setting
#define DIM(S) template<typename T> struct Dim<S<T>>{ enum {val = 1 + Dim<T>::val}; };
template<typename T>
struct Dim{
	enum {val = 0}; 
};
DIM(vector) DIM(deque) DIM(set) DIM(multiset) DIM(unordered_set)
template<typename S,typename T>
struct Dim<map<S,T>>{ enum {val = 1 + max((int)Dim<S>::val,(int)Dim<T>::val)}; };
template<typename S,typename T> 
struct Dim<unordered_map<S,T>>{ enum {val = 1 + max((int)Dim<S>::val,(int)Dim<T>::val)}; };
template<typename S,typename T>
struct Dim<pair<S,T>>{ enum{val = max((int)Dim<S>::val,(int)Dim<T>::val)}; };

template<typename T>
void _print(const T &a,const int idt = 0,typename enable_if< (Dim<T>::val<=1) >::type* = 0){
	cerr<<a;
}

#define PRYTYFY_DECLARE(U) template<typename ...T>ostream& operator<<(ostream&O,const U<T...> &a); template<typename ...T> void _print(const U<T...> &a,const int idt = 0,typename enable_if< (Dim<U<T...>>::val>1) >::type* = 0);
PRYTYFY_DECLARE(vector)
PRYTYFY_DECLARE(deque)
PRYTYFY_DECLARE(set)
PRYTYFY_DECLARE(multiset)
PRYTYFY_DECLARE(unordered_set)
PRYTYFY_DECLARE(map)
PRYTYFY_DECLARE(unordered_map)
template<typename T,typename TT> ostream& operator<<(ostream&O,const pair<T,TT> &a);
//template<typename ...T>ostream& operator<<(ostream&O,vector<T...> &a);
template<typename T,typename TT> void _print(const pair<T,TT> &a,const int idt = 0,typename enable_if< (Dim<pair<T,TT>>::val>1) >::type* = 0);
//template<typename ...T> void _print(vector<T...> &a,int idt = 0,typename enable_if< (Dim<vector<T...>>::val>1) >::type* = 0);

// M for one-dimention, N for N-dimension
#define PRYTYFY(U,B,S,E,M,N) template<typename ...T> ostream& operator<<(ostream&O,const U<T...> &a){O<<B; int c=0; for(auto i:a) O<<(c++?S:"")<<M; return O<<E; } template<typename ...T> void _print(const U<T...> &a,const int idt,typename enable_if< (Dim<U<T...>>::val>1) >::type*){cerr<<B; int c=0; int dim = Dim<U<T...>>::val; string sep = S; for(int i=0;i<dim-1;++i) sep += "\n"; for(int i=0;i<idt+1;++i) sep += " "; for(auto i:a){cerr<<(c++?sep:"");N; } cerr<<E; }

PRYTYFY(vector,"[",", ","]",i,_print(i,idt+1););
PRYTYFY(deque,"[",", ","]",i,_print(i,idt+1););
PRYTYFY(set,"{",", ","}",i,_print(i,idt+1););
PRYTYFY(multiset,"{",", ","}",i,_print(i,idt+1););
PRYTYFY(unordered_set,"{",", ","}",i,_print(i,idt+1););
PRYTYFY(map,"{",", ","}",i.first<<":"<<i.second,_print(i.first,idt+1); cerr<<((Dim<map<T...>>::val) > 2?":\n":":"); _print(i.second,idt+1););
PRYTYFY(unordered_map,"{",", ","}",i.first<<":"<<i.second,_print(i.first,idt+1); cerr<<((Dim<unordered_map<T...>>::val) > 2?":\n":":"); _print(i.second,idt+1););
/*
PRYTYFY vector
template<typename ...T> ostream& operator<<(ostream&O,vector<T...> &a){
	string B = "[",S = ",",E = "]";
	O<<B;
	int c=0;
	for(auto i:a)
		O<<(c++?S:"")<<i;
	return O<<E;
}
template<typename ...T>
void _print(vector<T...> &a,int idt,typename enable_if< (Dim<vector<T...>>::val>1) >::type*){
	string B = "[",S = ",",E = "]";
	cerr<<B;
	int c=0;
	int dim = Dim<vector<T...>>::val;
	string sep = S;
	for(int i=0;i<dim-1;++i)
		sep += "\n";
	for(int i=0;i<idt+1;++i)
		sep += " ";
	for(auto i:a){
		cerr<<(c++?sep:"");
		_print(i,idt+1);
	}
	cerr<<E;
}
*/

template<typename T,typename TT>
ostream& operator<<(ostream&O,const pair<T,TT> &a){
	string B = "(",S = ",",E = ")";
	return O<<B<<a.first<<S<<a.second<<E;
}
template<typename T,typename TT>
void _print(const pair<T,TT> &a,const int idt,typename enable_if< (Dim<pair<T,TT>>::val>1) >::type*){
	string B = "(",S = ",",E = ")";
	cerr<<B; 
	string sep = S; 
	if(Dim<TT>::val > 1)
		sep += "\n"; 
	for(int i=0;i<idt+1;++i) 
		sep += " "; 
	_print(a.first,idt+1); 
	cerr<<sep; 
	_print(a.second,idt+1); 
	cerr<<E; 
}

template<typename ...T> 
void _print_all(const char*s,const T&... a){
#ifdef ENABLE_COLOR
	cerr<<"\033[92m"<<s<<"\033[m"<<" = ";
#else
	cerr<<s<<" = ";
#endif
	int c=0; 
	((cerr<<(c++?", ":"")<<(Dim<T>::val>1?"\n":""),_print(a,0)),...); 
	cerr<<"\n";
}

void vector_demo(){
	vector<int> one_dim(16,42);
	vector<vector<int>> two_dim(4,vector<int>(4,42));
	vector<vector<vector<int>>> three_dim(2,vector<vector<int>>(2,vector<int>(4,42)));
	vector<vector<vector<vector<int>>>> four_dim(2,vector<vector<vector<int>>>(2,vector<vector<int>>(2,vector<int>(2,42))));
	print(one_dim);
	print(two_dim);
	print(three_dim);
	print(four_dim);
	int cnt = 1;
	vector<vector<vector<int>>>pyramid;
	for(int i=0;i<4;++i){
		vector<vector<int>>tmp;
		for(int j=0;j<i+1;++j){
			vector<int> t;
			for(int k=0;k<i+1;++k){
				t.push_back(cnt++);
			}
			tmp.push_back(t);
		}
		pyramid.push_back(tmp);
	}
	print(pyramid);
}

void sets_demo(){
	vector<int>a({1,2,2,3,3,4});
	set<int>s(a.begin(),a.end());
	multiset<int>ms(a.begin(),a.end());
	unordered_set<int>us(a.begin(),a.end());
	print(s,ms,us);
	multiset<set<int>>mss;
	mss.insert(s);
	mss.insert(s);
	print(mss);
}

void maps_demo(){
	map<int,string>m;
	unordered_map<int,string>um;
	for(int i=0;i<5;++i){
		m[i] = "aa"+to_string(i);
		um[i] = "bb"+to_string(i);
	}
	print(m);
	print(um);
}

signed main(){
	print("------------------------");
	vector_demo();
	print("------------------------");
	sets_demo();
	print("------------------------");
	maps_demo();
	print("------------------------");
}
