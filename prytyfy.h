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

#define PRYTYFY_H_ENABLE_COLOR
#define print(arg...) prytyfy::_print_all(#arg,arg)
#define print_arr(arr,arg...) prytyfy::_print_arr(#arr, #arg, arr, ##arg)
#define IDT() prytyfy::indenter __idt##__LINE__

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

	template<> struct Dim<std::string>{ enum{ val = 1 }; };

	template<typename S,int T> struct Dim<S[T]>{ enum{val = 1 + Dim<S>::val}; };
	DIM(std::valarray);
#undef DIM

	constexpr const char* dim2clr(int d){
#ifdef PRYTYFY_H_ENABLE_COLOR
		if(d <= 2)
			return "\033[37m";
		if(d%3 == 0)
			return "\033[1;32m";
		if(d%3 == 1)
			return "\033[1;33m";
		if(d%3 == 2)
			return "\033[1;35m";
#else
		return "";
#endif
	}

#ifdef PRYTYFY_H_ENABLE_COLOR
	const char* __rst_clr = "\033[m";
#else
	const char* __rst_clr = "";
#endif

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
	PRYTYFY_DECLARE(std::tuple);
	PRYTYFY_DECLARE(std::array);
	void _print(const std::string &a,const int idt);
	void _print(const char a[],const int idt);
	void _print(const char a,const int idt);

	template<typename T,int L>
	void _print(const T (&a)[L],const int idt);
	template<typename T,int L, typename S0>
	void _print(const T (&a)[L],const int idt,S0 sz);
	template<typename T,int L, typename S0, typename... ST>
	void _print(const T (&a)[L],const int idt,S0 sz, ST... size);

	PRYTYFY_DECLARE(std::valarray);
#undef PRYTYFY_DECLARE

#define PRYTYFY(U,B,S,E,PRINT) template<typename... T> \
	void _print(const U<T...> &a,const int idt){ \
	   	const int dim = Dim<U<T...>>::val; \
		const char* be_clr = dim2clr(dim); \
		std::cerr<<be_clr<<B<<__rst_clr; \
	   	int c=0; \
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
		std::cerr<<be_clr<<E<<__rst_clr; \
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
	   	const int dim = Dim<std::priority_queue<T...>>::val;
		const std::string B = "<",S = ", ",E = ">";
		const char* be_clr = dim2clr(dim);
		std::cerr<<be_clr<<B<<__rst_clr;
	   	int c=0;
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
		std::cerr<<be_clr<<E<<__rst_clr;
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
	   	const int dim = Dim<std::array<T,ST>>::val; 
		const char* be_clr = dim2clr(dim);
		std::cerr<<be_clr<<B<<__rst_clr;
	   	int c=0; 
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
		std::cerr<<be_clr<<E<<__rst_clr;
	}

	void _print(const std::string &a,const int idt){ 
		const std::string B = "\"",E = "\"";
		std::cerr<<B<<a<<E;
	}

	void _print(const char a[],const int idt){
		const std::string B = "\"",E = "\"";
		std::cerr<<B<<a<<E;
	}

	void _print(const char a,const int idt){
		const std::string B = "'",E = "'";
		std::cerr<<B<<a<<E;
	}

	template<typename T,int L>
	void _print(const T (&a)[L],const int idt){
		_print(a,idt,L);
	}

	template<typename T,int L, typename S0>
	void _print(const T (&a)[L],const int idt,S0 sz){
	   	const int dim = Dim<T[L]>::val; 
		const char* be_clr = dim2clr(dim); 
		const std::string B = "[", S = ", ", E = "]";
		std::cerr<<be_clr<<B<<__rst_clr; 
	   	int c=0; 
	   	std::string sep = S; 
	   	if(dim > 1){ 
			for(int i=0;i<dim-1;++i) 
				sep += "\n"; 
		   	for(int i=0;i<idt+1;++i) 
				sep += " "; 
	   	} 
		if(sz == -1)
			sz = L;
	   	for(int i=0;i<sz;++i){ 
			std::cerr<<(c++?sep:""); 
		   	_print(a[i],idt+1); 
	   	} 
		std::cerr<<be_clr<<E<<__rst_clr;
	}

	template<typename T,int L, typename S0, typename... ST>
	void _print(const T (&a)[L],const int idt,S0 sz, ST... size){
	   	const int dim = Dim<T[L]>::val; 
		const char* be_clr = dim2clr(dim); 
		const std::string B = "[", S = ", ", E = "]";
		std::cerr<<be_clr<<B<<__rst_clr; 
	   	int c=0; 
	   	std::string sep = S; 
	   	if(dim > 1){ 
			for(int i=0;i<dim-1;++i) 
				sep += "\n"; 
		   	for(int i=0;i<idt+1;++i) 
				sep += " "; 
	   	} 
		if(sz == -1)
			sz = L;
	   	for(int i=0;i<sz;++i){ 
			std::cerr<<(c++?sep:""); 
		   	_print(a[i],idt+1,size...); 
	   	} 
		std::cerr<<be_clr<<E<<__rst_clr;
	}

	PRYTYFY(std::valarray,"[",", ","]",_print(i,idt+1))

#undef PRYTYFY

	int __idt_level = 0;
	struct indenter{
		//indenter(){std::cerr<<"{\n";++__idt_level;}
		//~indenter(){std::cerr<<"}\n";--__idt_level;}
		indenter(){++__idt_level;}
		~indenter(){--__idt_level;}
	};

	template<typename ...T>
	void _print_all(const char*s,const T&... a){
		std::string idt = "";
		for(int i=0;i<__idt_level;++i)
			idt += "    ";
		std::cerr<<idt;
#ifdef PRYTYFY_H_ENABLE_COLOR
		std::cerr<<"\033[92m"<<s<<__rst_clr<<" = ";
#else
		std::cerr<<s<<" = ";
#endif
		int c=0;
		((std::cerr<<(c++?", ":"")<<(Dim<T>::val>1?"\n"+idt:""),_print(a,4*__idt_level)),...);
		std::cerr<<"\n";
	}


	template<typename T,typename... ST>
	void _print_arr(const char*s, const char*t, const T&a, ST... size){
		std::string idt = "";
		for(int i=0;i<__idt_level;++i)
			idt += "    ";
		std::cerr<<idt;
#ifdef PRYTYFY_H_ENABLE_COLOR
		std::cerr<<"\033[92m"<<s;
		if(t[0] != '\0')
			std::cerr<<"{"<<t<<"}";
		std::cerr<<__rst_clr<<" = ";
#else
		std::cerr<<s;
		if(t[0] != '\0')
			std::cerr<<"{"<<t<<"}";
		std::cerr<<" = ";
#endif
		std::cerr<<(Dim<T>::val>1?"\n"+idt:"");

		_print(a,4*__idt_level,size...);
		std::cerr<<"\n";
	}
}

#endif //PRYTYFY_H_INCLUDED
