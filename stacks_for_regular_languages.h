//
//  stacks_for_regular_languages.h
//  
//
//  Created by Cheryl Resch on 5/29/18.
//

//Elba Chimilio
//Section: 7303
//#include <string>

#ifndef stacks_for_regular_languages_h
#define stacks_for_regular_languages_h
#include "stack_p1.h"
#include <string>
#include "string.h"
using namespace std;

class stacks_for_regular_languages {
public:

bool L1(char* inputString) {
	stack_p1<int> s;
	for (int i = 0; i < inputString[i]; i++) {
		s.push(inputString[i]);
	}
	//Checks that input is not empty
	if(s.isEmpty()){
	return false;
	}
	//Checks that input only contains A and B
	int count=0;
	int length = sizeof(inputString)/sizeof(char);
	for(int j =0; j<inputString[j]; j++){
	   if(inputString[j]=='A' || inputString[j]=='B'){
			count=count+1;
	   } else if (inputString[j] !='A' || inputString[j] !='B'){
		   return false;
	   }
	}

	//Checks for same number of A's and B's
	int i=0;
	while(i < length) {
	   char x = inputString[i];
	   if(s.isEmpty()) {
		   s.push(x);
	   } else if(s.peek()== x) {
		   s.push(x);
	   } else {
		   s.pop();
	   }
		i++;
	}
	if(s.isEmpty())
	   return false;
	else
	   return true;
}
   
bool L2(char* inputString){
	stack_p1<int> s;
	for (int i = 0; i < inputString[i]; i++) {
		s.push(inputString[i]);
	}
	//Checks that input is not empty
	if(s.isEmpty()){
	return false;
	}
	//Checks that input only contains A and B
	int count=0;
	int length = sizeof(inputString)/sizeof(char);
	for(int j =0; j<inputString[j]; j++){
	   if(inputString[j]=='A' || inputString[j]=='B'){
			count=count+1;
	   } else if (inputString[j] !='A' || inputString[j] !='B'){
		   return false;
	   }
	}

	//Checks for same number of A's and B's
	int i=0;
	while(i < length) {
	   char x = inputString[i];
	   if(s.isEmpty()) {
		   s.push(x);
	   } else if(s.peek()== x) {
		   s.push(x);
	   } else {
		   s.pop();
	   }
		i++;
	}
	if(s.isEmpty())
	   return false;
	else
	   return true;
}
   
bool L3(char* inputString){
	stack_p1<int> s;
	for (int i = 0; i < inputString[i]; i++) {
		s.push(inputString[i]);
	}
	//Checks that input is not empty
	if(s.isEmpty()){
	return false;
	}
	//Checks that input only contains A and B
	int count=0;
	int length = sizeof(inputString)/sizeof(char);
	for(int j =0; j<inputString[j]; j++){
	   if(inputString[j]=='A' || inputString[j]=='B'){
			count=count+1;
	   } else if (inputString[j] !='A' || inputString[j] !='B'){
		   return false;
	   }
	}

	//Checks for same number of A's and B's
	int i=0;
	while(i < length) {
	   char x = inputString[i];
	   if(s.isEmpty()) {
		   s.push(x);
	   } else if(s.peek()== x) {
		   s.push(x);
	   } else {
		   s.pop();
	   }
		i++;
	}
	if(s.isEmpty())
	   return false;
	else
	   return true;
}
   
bool L4(char* inputString){
	stack_p1<int> s;
	for (int i = 0; i < inputString[i]; i++) {
		s.push(inputString[i]);
	}
	//Checks that input is not empty
	if(s.isEmpty()){
	return false;
	}
	//Checks that input only contains A and B
	int count=0;
	int length = sizeof(inputString)/sizeof(char);
	for(int j =0; j<inputString[j]; j++){
	   if(inputString[j]=='A' || inputString[j]=='B'){
			count=count+1;
	   } else if (inputString[j] !='A' || inputString[j] !='B'){
		   return false;
	   }
	}

	//Checks for same number of A's and B's
	int i=0;
	while(i < length) {
	   char x = inputString[i];
	   if(s.isEmpty()) {
		   s.push(x);
	   } else if(s.peek()== x) {
		   s.push(x);
	   } else {
		   s.pop();
	   }
		i++;
	}
	if(s.isEmpty())
	   return false;
	else
	   return true;
}
};
#endif /* stacks_for_regular_languages_h */
