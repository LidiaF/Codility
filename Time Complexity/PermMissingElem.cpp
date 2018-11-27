#include <iostream>
#include <vector>
#include <algorithm>

/*An array A consisting of N different integers is given. The array contains integers in the range [1..(N + 1)], which means that exactly one element is missing.

Your goal is to find that missing element.

Write a function:

    int solution(vector<int> &A);

that, given an array A, returns the value of the missing element.

For example, given array A such that:
  A[0] = 2
  A[1] = 3
  A[2] = 1
  A[3] = 5

the function should return 4, as it is the missing element.

Write an efficient algorithm for the following assumptions:

        N is an integer within the range [0..100,000];
        the elements of A are all distinct;
        each element of array A is an integer within the range [1..(N + 1)].

Copyright 2009–2018 by Codility Limited. All Rights Reserved. Unauthorized copying, publication or disclosure prohibited. 
*/


int solution(std::vector<int> &A) {
	std::sort(A.begin(), A.end());

	int value = 1;

	int i = 0;
	int N = A.size();
    bool found = false;

    while (!found && i < N) {
    	if(i + 1 != A[i]){
    		value = i + 1;
    		found = true;
    	}
    	else 
    		++i;
    }
    
    if(found == false)
        value = N + 1;
    
    return value;
}



int main() {

	//Get vector size
	std::cout << "Please, digit vector size:\n";
	int N = 0;
	std::cin >> N;

	//Populate vector
	std::vector<int> A;
	std::cout << "Please, digit vector elements:\n";
	for (int i = 0; i < N; ++i) {
		int value = 0;
		std::cin >> value;
		A.push_back(value);
	}

	int value = solution(A);

	std::cout << "The missing element is: " << value << "\n";

	return 0;
}