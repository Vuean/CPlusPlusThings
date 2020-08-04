#include<iostream> 
using namespace std; 

class Apple 
{ 
public: 
	static int i; 
	
	Apple() { }
}; 

int main() 
{ 
Apple obj1; 
Apple obj2; 
obj1.i =2020; 
obj2.i = 3030; 
	
// prints value of i 
cout << obj1.i<<" "<<obj2.i; 
} 