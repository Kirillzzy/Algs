#include <bits/stdc++.h>	


using namespace std;

typedef long long ll;


template <class T>
class SmartPointer{
private:
	T *pointer;
public:
	SmartPointer(T *p): pointer(p){}
	operator T*(){
		return pointer;
	}
	T *operator->(){
		if(!pointer){
			pointer = new T();
			cerr << "Bad Pointer!" << endl;
		}
		return pointer;
	}

	ptrdiff_t operator-(SmartPointer<T> p){
		return pointer - p;
	}

	ptrdiff_t operator-(void *p){
		return pointer - p;
	}
};

class Foo{
private:
	int a, b;
public:
	Foo(): a(0), b(0){}
	Foo(int a, int b): a(a), b(b){}
	int Sum(){
		return a + b;
	}
};

int main() {
	return 0;
}
