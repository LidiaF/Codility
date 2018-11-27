#include <iostream>
#include <vector>
#include <algorithm>

/*
Write a function

    int solution(vector<int> &A);

that, given an array A consisting of N integers, returns the number of distinct values in array A.

For example, given array A consisting of six elements such that:
 A[0] = 2    A[1] = 1    A[2] = 1
 A[3] = 2    A[4] = 3    A[5] = 1

the function should return 3, because there are 3 distinct values appearing in array A, namely 1, 2 and 3.

Write an efficient algorithm for the following assumptions:

        N is an integer within the range [0..100,000];
        each element of array A is an integer within the range [−1,000,000..1,000,000].

Copyright 2009–2018 by Codility Limited. All Rights Reserved. Unauthorized copying, publication or disclosure prohibited. 
*/

int solution(std::vector<int> &A) {
  
  std::sort(A.begin(), A.end());

  int num = 0;
  int val = -1;

  for (unsigned int i = 0; i < A.size(); ++i) {
  	if ( val != A[i] ) {
  		++num;
  		val = A[i];
  	}
  }
  
  return num;
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

  int val = solution(A);

  std::cout << "The number of distinct elements is: " << val << "\n";
  
  return 0;
}