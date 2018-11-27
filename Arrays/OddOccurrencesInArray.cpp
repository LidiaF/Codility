#include <iostream>
#include <vector>
#include <algorithm>

/*
A non-empty array A consisting of N integers is given. The array contains an odd number of elements, and each element of the array can be paired with another element that has the same value, except for one element that is left unpaired.

For example, in array A such that:
  A[0] = 9  A[1] = 3  A[2] = 9
  A[3] = 3  A[4] = 9  A[5] = 7
  A[6] = 9

      * the elements at indexes 0 and 2 have value 9,
      * the elements at indexes 1 and 3 have value 3,
      * the elements at indexes 4 and 6 have value 9,
      * the element at index 5 has value 7 and is unpaired.

Write a function:

    int solution(vector<int> &A);

that, given an array A consisting of N integers fulfilling the above conditions, returns the value of the unpaired element.

For example, given array A such that:
  A[0] = 9  A[1] = 3  A[2] = 9
  A[3] = 3  A[4] = 9  A[5] = 7
  A[6] = 9

the function should return 7, as explained in the example above.

Write an efficient algorithm for the following assumptions:

        N is an odd integer within the range [1..1,000,000];
        each element of array A is an integer within the range [1..1,000,000,000];
        all but one of the values in A occur an even number of times.

Copyright 2009–2018 by Codility Limited. All Rights Reserved. Unauthorized copying, publication or disclosure prohibited. 
*/

int solution(std::vector<int> &A) {
	//Sort vector
    std::sort(A.begin(), A.end());

    int value = 0;

    int i = 0;
    int N = A.size();
    bool found = false;

    while((!found) && (i < (N - 1))) {
    	if(A[i] != A[i+1]) {
    		value = A[i];
    		found = true;
    	}
    	else 
    		i += 2;
	}

	if(value == 0)
		value = A[N-1];

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

	std::cout << "The odd value is: " << value << "\n";
	
	return 0;
}