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
template<typename S>
struct Dim<tuple<S>>{
	enum{val = Dim<S>::val};
};
template<typename S,typename ...T>
struct Dim<tuple<S,T...>>{
	enum{val = max((int)Dim<S>::val,(int)Dim<tuple<T...>>::val)};
};

#define O cout
template<typename T>
void _print(const T &a,const int idt){
	O<<a;
}
/*
#define PRYTYFY_DECLARE(U) template<typename ...T>ostream& operator<<(ostream&O,const U<T...> &a); template<typename ...T> void _print(const U<T...> &a,const int idt = 0,typename enable_if< (Dim<U<T...>>::val>1) >::type* = 0);

PRYTYFY_DECLARE(vector)
PRYTYFY_DECLARE(deque)
PRYTYFY_DECLARE(set)
PRYTYFY_DECLARE(multiset)
PRYTYFY_DECLARE(unordered_set)
PRYTYFY_DECLARE(map)
PRYTYFY_DECLARE(unordered_map)
//template<typename T,typename TT> ostream& operator<<(ostream&O,const pair<T,TT> &a);
//template<typename ...T>ostream& operator<<(ostream&O,vector<T...> &a);
//template<typename T,typename TT> void _print(const pair<T,TT> &a,const int idt = 0,typename enable_if< (Dim<pair<T,TT>>::val>1) >::type* = 0);
//template<typename ...T> void _print(vector<T...> &a,int idt = 0,typename enable_if< (Dim<vector<T...>>::val>1) >::type* = 0);
PRYTYFY_DECLARE(tuple)
PRYTYFY_DECLARE(pair)

// M for one-dimention, N for N-dimension
#define PRYTYFY(U,B,S,E,M,N) template<typename ...T> ostream& operator<<(ostream&O,const U<T...> &a){O<<B; int c=0; for(auto i:a) O<<(c++?S:"")<<M; return O<<E; } template<typename ...T> void _print(const U<T...> &a,const int idt,typename enable_if< (Dim<U<T...>>::val>1) >::type*){cerr<<B; int c=0; int dim = Dim<U<T...>>::val; string sep = S; for(int i=0;i<dim-1;++i) sep += "\n"; for(int i=0;i<idt+1;++i) sep += " "; for(auto i:a){cerr<<(c++?sep:"");N; } cerr<<E; }

PRYTYFY(vector,"[",", ","]",i,_print(i,idt+1););
PRYTYFY(deque,"[",", ","]",i,_print(i,idt+1););
PRYTYFY(set,"{",", ","}",i,_print(i,idt+1););
PRYTYFY(multiset,"{",", ","}",i,_print(i,idt+1););
PRYTYFY(unordered_set,"{",", ","}",i,_print(i,idt+1););
PRYTYFY(map,"{",", ","}",i.first<<":"<<i.second,_print(i.first,idt+1); cerr<<((Dim<map<T...>>::val) > 2?":\n":":"); _print(i.second,idt+1););
PRYTYFY(unordered_map,"{",", ","}",i.first<<":"<<i.second,_print(i.first,idt+1); cerr<<((Dim<unordered_map<T...>>::val) > 2?":\n":":"); _print(i.second,idt+1););
*/

#define PRYTYFY_DECLARE(U)template<typename ...T> void _print(const U<T...> &a,const int idt);
PRYTYFY_DECLARE(vector)
PRYTYFY_DECLARE(deque)
PRYTYFY_DECLARE(set)
PRYTYFY_DECLARE(multiset)
PRYTYFY_DECLARE(unordered_set)
PRYTYFY_DECLARE(map)
PRYTYFY_DECLARE(unordered_map)
PRYTYFY_DECLARE(tuple)
template<typename ...T>
void _print(const pair<T...> &a,const int idt,const bool from_map = false);


#define PRYTYFY(U,B,S,E,PRINT) template<typename... T> void _print(const U<T...> &a,const int idt){O<<B; int c=0; int dim = Dim<U<T...>>::val; string sep = S; if(dim > 1){for(int i=0;i<dim-1;++i) sep += "\n"; for(int i=0;i<idt+1;++i) sep += " "; } for(auto i:a){O<<(c++?sep:""); PRINT; } O<<E; }
PRYTYFY(vector,"[",", ","]",_print(i,idt+1))
PRYTYFY(deque,"[",", ","]",_print(i,idt+1))
PRYTYFY(set,"{",", ","}",_print(i,idt+1))
PRYTYFY(multiset,"{",", ","}",_print(i,idt+1))
PRYTYFY(unordered_set,"{",", ","}",_print(i,idt+1))
PRYTYFY(map,"{",", ","}",_print(i,idt,true))
PRYTYFY(unordered_map,"{",", ","}",_print(i,idt,true))

// template<typename ...T>
// void _print(const map<T...> &a,const int idt){
// 	string B = "{",S = ", ",E = "}";
// 	O<<B;
// 	int c=0;
// 	int dim = Dim<map<T...>>::val;
// 	if(dim > 1){
// 		for(int i=0;i<dim-1;++i)
// 			S += "\n";
// 		for(int i=0;i<idt+1;++i)
// 			S += " ";
// 	}
// 	for(auto i:a){
// 		O<<(c++?S:"");
// 		_print(i,idt,true);
// 	}
// 	O<<E;
// }


#define PRYTYFY_PAIR(U,B,S,E,FMB,FMS,FME) template<typename ...T> void _print(const pair<T...> &a,const int idt,const bool from_map){string sep; if(from_map){O<<FMB; string sep = FMS; } else{O<<B; string sep = S; } int dim = Dim<pair<T...>>::val; if(dim > 1) sep += "\n"; for(int i=0;i<idt+1;++i) sep += " "; apply([&](T... a){int c=0; ((O<<(c++?(Dim<T>::val>1?sep:S):""),_print(a,idt+1) ),... ); } ,a); if(from_map) O<<FME; else O<<E; }

PRYTYFY_PAIR(pair,"(",", ",")","",":","")
// template<typename ...T>
// void _print(const pair<T...> &a,const int idt,const bool from_map){
// 	string sep;
// 	if(from_map){
// 		O<<FMB;
// 		string sep = FMS;
// 	}
// 	else{
// 		O<<B;
// 		string sep = S;
// 	}
// 	int dim = Dim<pair<T...>>::val;
// 	if(dim > 1)
// 		sep += "\n";
// 	for(int i=0;i<idt+1;++i)
// 		sep += " ";
// 	apply(
// 		[&](T... a){
// 			int c=0;
// 			(
// 				(
// 					O<<(c++?(Dim<T>::val>1?sep:S):""),_print(a,idt+1)
// 				),...
// 			);
// 		}
// 	,a);
// 	if(from_map)
// 		O<<FME;
// 	else 
// 		O<<E;
// }

#define PRYTYFY_TUPLE(U,B,S,E) template<typename ...T> void _print(const U<T...> &a,const int idt){O<<B; string sep = S; int dim = Dim<U<T...>>::val; if(dim > 1) sep += "\n"; for(int i=0;i<idt+1;++i) sep += " "; apply([&](T... a){int c=0; ((O<<(c++?(Dim<T>::val>1?sep:S):""),_print(a,idt+1) ),... ); } ,a); O<<E; }

PRYTYFY_TUPLE(tuple,"(",", ",")")
// template<typename ...T>
// void _print(const tuple<T...> &a,const int idt){
// 	string B = "(",S = ", ",E = ")";
// 	O<<B;
// 	string sep = S;
// 	int dim = Dim<tuple<T...>>::val;
// 	if(dim > 1)
// 		sep += "\n";
// 	for(int i=0;i<idt+1;++i)
// 		sep += " ";
// 	apply(
// 		[&](T... a){
// 			int c=0;
// 			(
// 				(
// 					O<<(c++?(Dim<T>::val>1?sep:S):""),_print(a,idt+1)
// 				),...
// 			);
// 		}
// 	,a);
// 	O<<E;
// }

// template<typename ...T>
// void _print(const pair<T...> &a,const int idt){
// 	string B = "(",S = ", ",E = ")";
// 	O<<B;
// 	string sep = S;
// 	int dim = Dim<tuple<T...>>::val;
// 	if(dim > 1)
// 		sep += "\n";
// 	for(int i=0;i<idt+1;++i)
// 		sep += " ";
// 	apply(
// 		[&](T... a){
// 			int c=0;
// 			(
// 				(
// 					O<<(c++?(Dim<T>::val>1?sep:S):""),_print(a,idt+1)
// 				),...
// 			);
// 		}
// 	,a);
// 	O<<E;
// }

template<typename ...T> 
void _print_all(const char*s,const T&... a){
#ifdef ENABLE_COLOR
	O<<"\033[92m"<<s<<"\033[m"<<" = ";
#else
	O<<s<<" = ";
#endif
	int c=0; 
	((O<<(c++?", ":"")<<(Dim<T>::val>1?"\n":""),_print(a,0)),...); 
	O<<"\n";
}

void vector_demo(){
	vector<int> one_dim(16,42);
	vector<vector<int>> two_dim(4,vector<int>(4,42));
	vector<vector<vector<int>>> three_dim(2,vector<vector<int>>(2,vector<int>(4,42)));
	vector<vector<vector<vector<int>>>> four_dim(2,vector<vector<vector<int>>>(2,vector<vector<int>>(2,vector<int>(2,42))));
	print(one_dim,two_dim,three_dim,four_dim);
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
	map<int,vector<vector<vector<int>>>> mp;
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
	mp[12] = pyramid;
	mp[3] = pyramid;
	print(mp);
	print(um);
}

void test_tuple(){
	pair<int,int>pii;
	pii = {0,1};
	pair<vector<int>,int>pvii;
	pvii = {vector(3,0),1};
	pair<int,vector<int>>pivi;
	pivi = {1,vector<int>(3,0)};
	auto u = make_pair(vector<vector<int>>(3,vector<int>(3,0)),3);
	auto v = make_pair(3,vector<vector<int>>(3,vector<int>(3,0)));
	vector<pair<vector<vector<int>>,int>> vu(3,u);
	print(pii);
	print(pvii);
	print(pivi);
	print(u);
	print(v);
	print(vu);
	print(Dim<tuple<int,int>>::val);
	tuple<vector<vector<int>>,int,char> a = make_tuple(vector<vector<int>>(3,vector<int>(3,0)),4,'a');
	print(a);
	auto mix = make_tuple(a,pii,pvii,pivi,u,vu);
	print(mix);
}

signed main(){
	vector_demo();
	test_tuple();
	maps_demo();
	sets_demo();
}
