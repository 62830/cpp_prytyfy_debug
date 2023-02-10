#include<bits/stdc++.h>
using namespace std;

template<typename T>
void f(T a){
	static int var = 0;
	cout<<var;
	++var;
}

template<>
void f(int a){
	static int var = 3;
	cout<<var;
	++var;
}

int main(){
	f(12);
	f(12);
	f('a');
	f('a');

}