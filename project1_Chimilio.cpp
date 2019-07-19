//test program for stack
#include <iostream>
#include <string>
#include "stack_p1.h"
#include "stacks_for_regular_languages.h"
using namespace std;

//Code written by TA Amanpreet Kapoor
int main() {

 /*-------- Testing stack_p1 ------- */
   //stack for integers
   stack_p1<int> s;
   
	s.push(10);
	s.push(20);

	cout<< s.peek() << " ";
	while(!s.isEmpty())
	{
	cout<< s.pop() << " ";
	}
	cout<< s.isEmpty()<<" ";
	//Output - 20 20 10 1
/*-------- End of Testing stack_p1 ------- */

/*-------- Testing L1, L2, L3, L4 ------- */

char arr1[10]="ABABBA";
char arr2[10]="AAABBB";
char arr3[10]="ABAB";
char arr4[10]="ABBABB";

stacks_for_regular_languages obj;

cout<< obj.L1(arr1) <<" ";
cout<< obj.L2(arr2) <<" ";
cout<< obj.L3(arr3) <<" ";
cout<< obj.L4(arr4) <<" ";

//Output - 1 1 1 1

cout<< obj.L1(arr3) <<" ";
cout<< obj.L1(arr4) <<" ";

//Output - 0 0

/*-------- End of Testing L1, L2, L3, L4 ------- */

   return 0;
}
