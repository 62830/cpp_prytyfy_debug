#ifndef PRYTYFY_H_INCLUDED
#define PRYTYFY_H_INCLUDED
#include<iostream>
#include<vector>
#include<queue>
#include<deque>
#include<set>
#include<unordered_set>
#include<map>
#include<unordered_map>
#include<string>
#include<array>
//#include "prytyfy_arr.h"


#define PRYTYFY_H_ENABLE_COLOR
//#define PRYTYFY_H_RAINBOW_MODE
#ifdef PRYTYFY_H_RAINBOW_MODE
#define PRYTYFY_H_ENABLE_COLOR
#endif
#define print(arg...); prytyfy::_print_all(#arg,arg);

namespace prytyfy{

#define DIM(U) template<typename T> struct Dim<U<T>>{ enum {val = 1 + Dim<T>::val}; };
	template<typename T> struct Dim{ enum {val = 0}; };
	DIM(std::vector);
	DIM(std::deque);
	DIM(std::set);
	DIM(std::multiset);
	DIM(std::unordered_set);
	DIM(std::unordered_multiset);
	DIM(std::priority_queue);

	template<typename S,typename T> struct Dim<std::map<S,T>>{ enum {val = 1 + std::max((int)Dim<S>::val,(int)Dim<T>::val)}; };
	template<typename S,typename T> struct Dim<std::unordered_map<S,T>>{ enum {val = 1 + std::max((int)Dim<S>::val,(int)Dim<T>::val)}; };
	template<typename S,typename T> struct Dim<std::unordered_multimap<S,T>>{enum{val = 1 + std::max((int)Dim<S>::val,(int)Dim<T>::val) }; }; 

	template<typename S,typename T> struct Dim<std::pair<S,T>>{ enum{val = std::max((int)Dim<S>::val,(int)Dim<T>::val)}; }; 
	template<typename S>
	struct Dim<std::tuple<S>>{
		enum{val = Dim<S>::val};
	};
   	template<typename S,typename ...T>
	struct Dim<std::tuple<S,T...>>{
		enum{val = std::max((int)Dim<S>::val,(int)Dim<std::tuple<T...>>::val)};
	}; 
	template<typename S,size_t T> struct Dim<std::array<S,T>>{ enum {val = 1 + Dim<S>::val}; };
#undef DIM

#define PRYTYFY_DECLARE(U)template<typename ...T> void _print(const U<T...> &a,const int idt);
	template<typename T> void _print(const T &a,const int idt);
	PRYTYFY_DECLARE(std::vector);
	PRYTYFY_DECLARE(std::deque);
	PRYTYFY_DECLARE(std::set);
	PRYTYFY_DECLARE(std::multiset);
	PRYTYFY_DECLARE(std::unordered_set);
	PRYTYFY_DECLARE(std::unordered_multiset);
	PRYTYFY_DECLARE(std::priority_queue);

	PRYTYFY_DECLARE(std::map);
	PRYTYFY_DECLARE(std::unordered_map);
	PRYTYFY_DECLARE(std::unordered_multimap);

	template<typename ...T> void _print(const std::pair<T...> &a,const int idt,const bool from_map = false);
	PRYTYFY_DECLARE(std::array);
#undef PRYTYFY_DECLARE

#ifdef PRYTYFY_H_RAINBOW_MODE
	int rainbow = -1;
	std::string next_color(){
		rainbow = (++rainbow) % 6;
		return "\033["+std::to_string(91+rainbow)+"m";
	}
#endif

#define PRYTYFY(U,B,S,E,PRINT) template<typename... T> \
	void _print(const U<T...> &a,const int idt){ \
		std::cerr<<B; \
	   	int c=0; \
	   	const int dim = Dim<U<T...>>::val; \
	   	std::string sep = S; \
	   	if(dim > 1){ \
			for(int i=0;i<dim-1;++i) \
				sep += "\n"; \
		   	for(int i=0;i<idt+1;++i) \
		   	sep += " "; \
	   	} \
	   	for(auto i:a){ \
			std::cerr<<(c++?sep:""); \
		   	PRINT; \
	   	} \
		std::cerr<<E; \
	}
	template<typename T> void _print(const T &a,const int idt){std::cerr<<a; }
	PRYTYFY(std::vector,"[",", ","]",_print(i,idt+1))
	PRYTYFY(std::deque,"[",", ","]",_print(i,idt+1))
	PRYTYFY(std::set,"{",", ","}",_print(i,idt+1))
	PRYTYFY(std::multiset,"{",", ","}",_print(i,idt+1))
	PRYTYFY(std::unordered_set,"{",", ","}",_print(i,idt+1))
	PRYTYFY(std::unordered_multiset,"{",", ","}",_print(i,idt+1))
	template<typename... T>
	void _print(const std::priority_queue<T...> &a,const int idt){
		const std::string B = "<",S = ", ",E = ">";
		std::cerr<<B;
	   	int c=0;
	   	const int dim = Dim<std::priority_queue<T...>>::val;
		std::string sep = S;
	   	if(dim > 1){
			for(int i=0;i<dim-1;++i)
			   	sep += "\n";
		   	for(int i=0;i<idt+1;++i)
			   	sep += " ";
	   	}
	   	auto b = a;
	   	while(b.size()){
			std::cerr<<(c++?sep:"");
		   	_print(b.top(),idt+1);
		   	b.pop();
	   	}
		std::cerr<<E;
   	}

	PRYTYFY(std::map,"{",", ","}",_print(i,idt,true))
	PRYTYFY(std::unordered_map,"{",", ","}",_print(i,idt,true))
	PRYTYFY(std::unordered_multimap,"{",", ","}",_print(i,idt,true))

	template<typename ...T>
	void _print(const std::pair<T...> &a,const int idt,const bool from_map){
		const std::string B = "(",S = ", ",E = ")";
		const std::string FMB = "", FMS = ":", FME = "";
		std::string sep;
	   	if(from_map){
			std::cerr<<FMB;
		   	sep = FMS;
		}
	   	else{
			std::cerr<<B;
		   	sep = S;
	   	}
	   	int dim = Dim<std::pair<T...>>::val;
	   	if(dim > 1)
		   	sep += "\n";
	   	for(int i=0;i<idt+1;++i)
		   	sep += " ";
	   	apply(
			[&](T... a){
				int c=0;
				((std::cerr<<(c++?(Dim<T>::val>1?sep:(from_map?FMS:S)):""),_print(a,idt+1) ),... );
			 },
			 a
		);
	   	if(from_map)
		   	std::cerr<<FME;
	   	else
		   	std::cerr<<E;
   	}

	template<typename ...T>
	void _print(const std::tuple<T...> &a,const int idt){
		const std::string B = "(",S = ", ",E = ")";
		std::cerr<<B;
		std::string sep = S;
	   	const int dim = Dim<std::tuple<T...>>::val;
	   	if(dim > 1)
		   	sep += "\n";
	   	for(int i=0;i<idt+1;++i)
		   	sep += " ";
	   	apply(
			[&](T... a){
				int c=0;
				((std::cerr<<(c++?(Dim<T>::val>1?sep:S):""),_print(a,idt+1) ),... );
			},
			a
		);
		std::cerr<<E;
	}


	template<typename T,size_t ST> 
	void _print(const std::array<T,ST> &a,const int idt){ 
		const std::string B = "[",S = ", ",E = "]";
		std::cerr<<B; 
	   	int c=0; 
	   	const int dim = Dim<std::array<T,ST>>::val; 
	   	std::string sep = S; 
	   	if(dim > 1){ 
			for(int i=0;i<dim-1;++i) 
				sep += "\n"; 
		   	for(int i=0;i<idt+1;++i) 
		   	sep += " "; 
	   	} 
	   	for(auto i:a){ 
			std::cerr<<(c++?sep:""); 
			_print(i,idt+1);
	   	} 
		std::cerr<<E; 
	}

#undef PRYTYFY

	template<typename ...T>
	void _print_all(const char*s,const T&... a){
#ifdef PRYTYFY_H_RAINBOW_MODE
		std::cerr<<next_color()
			<<s
			<<next_color()<<" = ";
#elif defined(PRYTYFY_H_ENABLE_COLOR)
		std::cerr<<"\033[92m"<<s<<"\033[m"<<" = ";
#else
		std::cerr<<s<<" = ";
#endif

#ifdef PRYTYFY_H_RAINBOW_MODE
		int c=0;
		((std::cerr<<"\033[m"
		  <<(c++?", ":"")
		  <<next_color()
		  <<(Dim<T>::val>1?"\n":""),
		  _print(a,0)),...);
		std::cerr<<"\n"<<"\033[m";
#else
		int c=0;
		((std::cerr<<(c++?", ":"")<<(Dim<T>::val>1?"\n":""),_print(a,0)),...);
		std::cerr<<"\n";
#endif
	}
}

#endif //PRYTYFY_H_INCLUDED
