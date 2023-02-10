#include<bits/stdc++.h>
using namespace std;
#define print(arg...) _print_all(#arg,arg);

// dimension setting
#define DIM(S) template<typename T> struct Dim<S<T>>{ enum {val = 1 + Dim<T>::val}; };
template<typename T>
struct Dim{
	enum {val = 0}; 
};
DIM(vector); DIM(deque); DIM(set); DIM(multiset); DIM(unordered_set);
template<typename S,typename T>
struct Dim<map<S,T>>{ enum {val = 1 + max((int)Dim<S>::val,(int)Dim<T>::val)}; };
template<typename S,typename T> 
struct Dim<unordered_map<S,T>>{ enum {val = 1 + max((int)Dim<S>::val,(int)Dim<T>::val)}; };
template<typename S,typename T>
struct Dim<pair<S,T>>{ enum{val = max((int)Dim<S>::val,(int)Dim<T>::val)}; };

template<typename T>
void _print(T a,int idt = 0,typename enable_if< (Dim<T>::val<=1) >::type* = 0){
	cerr<<a;
}

template<typename T,typename TT>ostream& operator<<(ostream&O,pair<T,TT> a);
template<typename T>ostream& operator<<(ostream&O,vector<T> a);
template<typename K,typename V>ostream& operator<<(ostream&O,map<K,V> a);
template<typename T,typename TT> void _print(pair<T,TT> a,int idt = 0,typename enable_if< (Dim<pair<T,TT>>::val>1) >::type* = 0);
template<typename T> void _print(vector<T> a,int idt = 0,typename enable_if< (Dim<vector<T>>::val>1) >::type* = 0);
template<typename K,typename V> void _print(map<K,V> a,int idt = 0,typename enable_if< (Dim<map<K,V>>::val>1) >::type* = 0);


template<typename T>
ostream& operator<<(ostream&O,vector<T> a){
	string B = "[",S = ",",E = "]";
	O<<B;
	int c=0;
	for(auto i:a)
		O<<(c++?S:"")<<i;
	return O<<E;
}
template<typename T>
void _print(vector<T> a,int idt,typename enable_if< (Dim<vector<T>>::val>1) >::type*){
	string B = "[",S = ",",E = "]";
	cerr<<B;
	int c=0;
	int dim = Dim<vector<T>>::val;
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

template<typename T,typename TT>
ostream& operator<<(ostream&O,pair<T,TT> a){
	string B = "(",S = ",",E = ")";
	return O<<B<<a.first<<S<<a.second<<E;
}
template<typename T,typename TT>
void _print(pair<T,TT> a,int idt,typename enable_if< (Dim<pair<T,TT>>::val>1) >::type*){
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

template<typename K,typename V>
ostream& operator<<(ostream&O,map<K,V> a){
	string B = "{",S = ",",E = "}";
	O<<B;
	int c=0;
	for(auto i:a)
		O<<(c++?S:"")<<i;
	return O<<E;
}
template<typename K,typename V>
void _print(map<K,V> a,int idt,typename enable_if< (Dim<map<K,V>>::val>1) >::type*){
	string B = "{",S = ",",E = "}";
	cerr<<B;
	int c=0;
	int dim = Dim<map<K,V>>::val;
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
template<typename ...T> 
void _print_all(const char*s,T... a){
	cerr<<s<<" = "; 
	int c=0; 
	((cerr<<(c++?", ":"")<<(Dim<T>::val>1?"\n":""),_print(a,0)),...); 
	cerr<<"\n";
}

void pair_vector_test(){
	vector<int> vi(3,3);
	vector<vector<int>> vvi(3,vi);
	vector<vector<vector<int>>> vvvi(3,vvi);
	print(vi,2);
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

signed main(){
	pair_vector_map_test();
}
