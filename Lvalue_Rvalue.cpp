#include "pch.h"
#include <iostream>

//global variable
int a = 5;
int b = 78;
//foo() function returns a global variable by reference
int& foo()
{
	return a;
}
//returns maximum of i and j and returns by referance
int& max(int& i, int& j)
{
	if (i > j)
		return i;
	return j;
}
//returns the copy of b global variable,returns rvalue
int bar()
{
	return b;
}
int main()
{
	//////////////////
	/////LVALUES//////
	//////////////////

	{
		int& foo();
		//becouse foo() is a lvalue we can rewrite it 
		//this value will be written to the memory,which foo() function will return and
		//foo() returns a global variable
		foo() = 45;
		std::cout << "foo():" << foo() << "\n";  //prints 45
		std::cout << "a:" << a << "\n";   //prints 45
		int b{ 3 };
		int c{ 5 };
		max(a, b) = 11;
		max(a, b) = a; //max(a,b) have memory location(max(a,b) is lvalue),that's why we can rewrite it
		int* p = &foo(); //foo() is lvalue therefore it has memory location, 
		//and we can assign the address of this location to the p pointer
		std::cout << "*p:" << *p << "\n";  //now p points to the address that foo() function returns and prints 45
		std::cout << "max(a,b):" << max(a, b) << " " << "a:" << a << " " << "b: " << b; //prints 11 a:3 b:11
	}
	///////////////////
	//////RVALUES//////
	///////////////////
	{
		int bar();
		int j = 0;
		j = bar(); //OK bar() is an rvalue
		/*
		bar() = 5;////error bar() is rvalue,have not memory location and we can not assign a value to it
		int* p1=&bar() //error bar() have not the address, we cannot take the address of rvalue
		*/
		/////int& a0 = bar();//error int& a0 is a lvalue referance
		const int& a1 = bar();
		std::cout << "\nconst int& a1=" << a1 << "\n"; //const lvalue we can bind to rvalue
		int&& a = bar();  //rvalue referance
		std::cout << "\n" << "int&& a=" << a;
	}
}