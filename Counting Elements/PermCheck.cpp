#include <iostream>
#include <vector>
#include <algorithm>

/*
A non-empty array A consisting of N integers is given.

A permutation is a sequence containing each element from 1 to N once, and only once.

For example, array A such that:
    A[0] = 4
    A[1] = 1
    A[2] = 3
    A[3] = 2

is a permutation, but array A such that:
    A[0] = 4
    A[1] = 1
    A[2] = 3

is not a permutation, because value 2 is missing.

The goal is to check whether array A is a permutation.

Write a function:

    int solution(vector<int> &A);

that, given an array A, returns 1 if array A is a permutation and 0 if it is not.

For example, given array A such that:
    A[0] = 4
    A[1] = 1
    A[2] = 3
    A[3] = 2

the function should return 1.

Given array A such that:
    A[0] = 4
    A[1] = 1
    A[2] = 3

the function should return 0.

Write an efficient algorithm for the following assumptions:

        N is an integer within the range [1..100,000];
        each element of array A is an integer within the range [1..1,000,000,000].

Copyright 2009–2018 by Codility Limited. All Rights Reserved. Unauthorized copying, publication or disclosure prohibited. 
*/

int solution(std::vector<int> &A) {
    int perm = 0;
    
    int N = A.size();
    
    sort(A.begin(),A.end());
    
    int max_el = *(A.end()-1);
    
    if(max_el == N) {
        
        int i = 0;
        bool found = false;
        
        while((!found) && (i < N)) {
            if(A[i] != i+1)
                found = true;
            else
               ++i;
        }
        
        if (found == false)
            perm = 1;
    }
   
    return perm;
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

  if (value == 1)
    std::cout << "The vector is a permutation\n";
  else
    std::cout << "The vector is not a permutation\n";

  return 0;
}