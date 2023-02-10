#include<bits/stdc++.h>
using namespace std;
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
template<typename T,typename TT>ostream& operator<<(ostream&O,const pair<T,TT> &a);
//template<typename ...T>ostream& operator<<(ostream&O,vector<T...> &a);
template<typename T,typename TT> void _print(const pair<T,TT> &a,const int idt = 0,typename enable_if< (Dim<pair<T,TT>>::val>1) >::type* = 0);
//template<typename ...T> void _print(vector<T...> &a,int idt = 0,typename enable_if< (Dim<vector<T...>>::val>1) >::type* = 0);

#define PRYTYFY(U,B,S,E) template<typename ...T> ostream& operator<<(ostream&O,const U<T...> &a){O<<B; int c=0; for(auto i:a) O<<(c++?S:"")<<i; return O<<E; } template<typename ...T> void _print(const U<T...> &a,const int idt,typename enable_if< (Dim<U<T...>>::val>1) >::type*){cerr<<B; int c=0; int dim = Dim<U<T...>>::val; string sep = S; for(int i=0;i<dim-1;++i) sep += "\n"; for(int i=0;i<idt+1;++i) sep += " "; for(auto i:a){cerr<<(c++?sep:""); _print(i,idt+1); } cerr<<E; }

//tested
PRYTYFY(vector,"[",", ","]")
PRYTYFY(set,"{",", ","}")
PRYTYFY(map,"{",", ","}")
// untested 
PRYTYFY(deque,"[",", ","]")
PRYTYFY(multiset,"{",", ","}")
PRYTYFY(unordered_set,"{",", ","}")
PRYTYFY(unordered_map,"{",", ","}")

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
	cerr<<s<<" = "; 
	int c=0; 
	((cerr<<(c++?", ":"")<<(Dim<T>::val>1?"\n":""),_print(a,0)),...); 
	cerr<<"\n";
}

void pair_vector_test(){
	vector<int> vi(3,3);
	vector<vector<int>> vvi(3,vi);
	vector<vector<vector<int>>> vvvi(3,vvi);
	int a = 2;
	print(vi,2,a);
	print(vvi,2);
	print(vvvi);
	cout<<Dim<pair<int,vector<vector<int>>>>::val;
	print(pair<int,vector<vector<vector<int>>>>{2,vvvi});
	print(pair<vector<vector<vector<int>>>,int>{vvvi,2});
	vector<pair<int,vector<vector<vector<int>>>>> v;
	v.push_back({2,vvvi});
	v.push_back({2,vvvi});
	print(v);
}

void map_test(){
	map<int,int> mii;
	for(int i=0;i<4;++i)
		mii[i] = 7-i;
	print(mii);
	map<int,map<int,int>> mim;
	mim[3] = mii;
	mii[100] = 100;
	mim[20] = mii;
	print(mim);
}

void pair_vector_map_test(){
	vector<map<int,vector<int>>> vmv;
	map<int,vector<int>> mv;
	mv[42] = {69,70,71};
	vmv.push_back(mv);
	mv[69] = {};
	mv[16384] = {23,34,45};
	vmv.push_back(mv);
	print(mv);
	print(vmv);
}

void set_test(){
	set<int> a({12,69});
	print(a);
	a.insert(23);
	print(a);
	set<string> ss;
	print(ss);
	ss.insert("hell");
	ss.insert("hello");
	ss.insert("word");
	ss.insert("world");
	print(ss);
}

void set_mix_test(){
	set<map<int,int>> sm;
	map<int,int> m;
	sm.insert(m);
	m[7122] = 69;
	m[42] = 24;
	sm.insert(m);
	sm.insert(m);
	m[7122] = 0;
	sm.insert(m);
	print(sm);

	vector<set<vector<string>>> vsv;
	set<vector<string>> sv;
	sv.insert({"heeloo","wrold"});
	vsv.push_back(sv);
	sv.insert({"haaloo","wrold"});
	sv.insert({"haaloo","ni jiao","shen ma ming zi"});
	vsv.push_back(sv);
	vsv.push_back(sv);
	print(vsv);

	map<int,set<int>> ms;
	set<int> s;
	s.insert(12);
	ms[1] = s;
	s.insert(22);
	ms[2] = s;
	s.insert(32);
	ms[3] = s;
	print(ms);
}

signed main(){
}
