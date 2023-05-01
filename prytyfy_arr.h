#ifndef PRYTYFY_ARR_H_INCLUDED
#define PRYTYFY_ARR_H_INCLUDED

#define print_arr(arr,arg...) prytyfy::_print_arr(#arr,#arg,arr,arg);

namespace prytyfy{
	template<typename T,typename... ST>
	void _print_arr(const char*s, const char*t, const T&a, ST... size){
		std::cerr<<s<<"{"<<t<<"} = ";
		int c=0;
		int dim = sizeof...(size);
		std::cerr<<"\n";
	}
}

#endif //PRYTYFY_ARR_H_INCLUDED
