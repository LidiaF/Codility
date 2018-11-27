#include <iostream>
#include <vector>

/*A non-empty array A consisting of N integers is given. The consecutive elements of array A represent consecutive cars on a road.

Array A contains only 0s and/or 1s:

        0 represents a car traveling east,
        1 represents a car traveling west.

The goal is to count passing cars. We say that a pair of cars (P, Q), where 0 ≤ P < Q < N, is passing when P is traveling to the east and Q is traveling to the west.

For example, consider array A such that:
  A[0] = 0
  A[1] = 1
  A[2] = 0
  A[3] = 1
  A[4] = 1

We have five pairs of passing cars: (0, 1), (0, 3), (0, 4), (2, 3), (2, 4).

Write a function:

    int solution(vector<int> &A);

that, given a non-empty array A of N integers, returns the number of pairs of passing cars.

The function should return −1 if the number of pairs of passing cars exceeds 1,000,000,000.

For example, given:
  A[0] = 0
  A[1] = 1
  A[2] = 0
  A[3] = 1
  A[4] = 1

the function should return 5, as explained above.

Write an efficient algorithm for the following assumptions:

      * N is an integer within the range [1..100,000];
      * each element of array A is an integer that can have one of the following values: 0, 1.

Copyright 2009–2018 by Codility Limited. All Rights Reserved. Unauthorized copying, publication or disclosure prohibited. */


int solution(std::vector<int> &A) {

  int num = 0;

  int u = 0;
  int z = 0;

  bool stop = 0;
  
  int i = A.size() - 1;
  while ((i >= 0) && (!stop)) {

    if (A[i]==1)
      ++u;
    else
      z = 1;

    num += u*z;

    z = 0;

    if (num > 1000000000) {
      num = -1;
      stop = true;
    }
    --i;
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

  int value = solution(A);

  std::cout << "The number of passing cars is: " << value << "\n";
  
  return 0;
}