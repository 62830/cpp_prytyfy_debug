#include<bits/stdc++.h>
using namespace std;
// color the variables in the output, delete it if not supported
#define ENABLE_COLOR
//	where to output (cout,cerr...)
#define OSTRM cout

#define print(arg...) _print_all(#arg,arg);
#define DIM(S) template<typename T> struct Dim<S<T>>{ enum {val = 1 + Dim<T>::val}; };
#define PRYTYFY_DECLARE(U)template<typename ...T> void _print(const U<T...> &a,const int idt);
#define PRYTYFY(U,B,S,E,PRINT) template<typename... T> void _print(const U<T...> &a,const int idt){OSTRM<<B; int c=0; int dim = Dim<U<T...>>::val; string sep = S; if(dim > 1){for(int i=0;i<dim-1;++i) sep += "\n"; for(int i=0;i<idt+1;++i) sep += " "; } for(auto i:a){OSTRM<<(c++?sep:""); PRINT; } OSTRM<<E; }
#define PRYTYFY_PAIR(U,B,S,E,FMB,FMS,FME) template<typename ...T> void _print(const U<T...> &a,const int idt,const bool from_map){string sep; if(from_map){OSTRM<<FMB; sep = FMS;} else{OSTRM<<B; sep = S; } int dim = Dim<U<T...>>::val; if(dim > 1) sep += "\n"; for(int i=0;i<idt+1;++i) sep += " "; apply([&](T... a){int c=0; ((OSTRM<<(c++?(Dim<T>::val>1?sep:(from_map?FMS:S)):""),_print(a,idt+1) ),... ); } ,a); if(from_map) OSTRM<<FME; else OSTRM<<E; }
#define PRYTYFY_TUPLE(U,B,S,E) template<typename ...T> void _print(const U<T...> &a,const int idt){OSTRM<<B; string sep = S; int dim = Dim<U<T...>>::val; if(dim > 1) sep += "\n"; for(int i=0;i<idt+1;++i) sep += " "; apply([&](T... a){int c=0; ((OSTRM<<(c++?(Dim<T>::val>1?sep:S):""),_print(a,idt+1) ),... ); } ,a); OSTRM<<E; }
//dimension setting
template<typename T> struct Dim{enum {val = 0}; }; DIM(vector) DIM(deque) DIM(set) DIM(multiset) DIM(unordered_set) template<typename S,typename T> struct Dim<map<S,T>>{ enum {val = 1 + max((int)Dim<S>::val,(int)Dim<T>::val)}; }; template<typename S,typename T> struct Dim<unordered_map<S,T>>{ enum {val = 1 + max((int)Dim<S>::val,(int)Dim<T>::val)}; }; template<typename S,typename T> struct Dim<pair<S,T>>{ enum{val = max((int)Dim<S>::val,(int)Dim<T>::val)}; }; template<typename S> struct Dim<tuple<S>>{enum{val = Dim<S>::val}; }; template<typename S,typename ...T> struct Dim<tuple<S,T...>>{enum{val = max((int)Dim<S>::val,(int)Dim<tuple<T...>>::val)}; };
//function declaration
template<typename T> void _print(const T &a,const int idt){OSTRM<<a; } PRYTYFY_DECLARE(vector) PRYTYFY_DECLARE(deque) PRYTYFY_DECLARE(set) PRYTYFY_DECLARE(multiset) PRYTYFY_DECLARE(unordered_set) PRYTYFY_DECLARE(map) PRYTYFY_DECLARE(unordered_map) PRYTYFY_DECLARE(tuple) template<typename ...T> void _print(const pair<T...> &a,const int idt,const bool from_map = false);
//customizable begin,seperate,end characters
PRYTYFY(vector,"[",", ","]",_print(i,idt+1))
PRYTYFY(deque,"[",", ","]",_print(i,idt+1))
PRYTYFY(set,"{",", ","}",_print(i,idt+1))
PRYTYFY(multiset,"{",", ","}",_print(i,idt+1))
PRYTYFY(unordered_set,"{",", ","}",_print(i,idt+1))
PRYTYFY(map,"{",", ","}",_print(i,idt,true))
PRYTYFY(unordered_map,"{",", ","}",_print(i,idt,true))
PRYTYFY_PAIR(pair,"(",", ",")","",":","")
PRYTYFY_TUPLE(tuple,"(",", ",")")

template<typename ...T> 
void _print_all(const char*s,const T&... a){
#ifdef ENABLE_COLOR
	OSTRM<<"\033[92m"<<s<<"\033[m"<<" = ";
#else
	OSTRM<<s<<" = ";
#endif
	int c=0; 
	((OSTRM<<(c++?", ":"")<<(Dim<T>::val>1?"\n":""),_print(a,0)),...); 
	OSTRM<<"\n";
}

void demo(){
	//yup no semicolon
	print(2,3.14,"hell world")

	vector<vector<vector<int>>> cubic_tower;
	int cnt = 0;
	for(int i=0;i<4;++i){
		vector<vector<int>>s;
		for(int j=0;j<i+1;++j){
			vector<int> t;
			for(int k=0;k<i+1;++k){
				t.push_back(++cnt);
			}
			s.push_back(t);
		}
		cubic_tower.push_back(s);
	}
	//if you really insist;
	print(cubic_tower);

	set<set<int>>independent_set;
	for(int i=1;i<6;++i)
		for(int j=i+1;j<6;++j)
			for(int k=j+1;k<6;++k)
				independent_set.insert({i,j,k});
	print(independent_set);
}

signed main(){
	demo();
}
