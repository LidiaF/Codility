#include<iostream>
#include<vector>
#include<cmath>

/*A non-empty array A consisting of N integers is given. Array A represents numbers on a tape.

Any integer P, such that 0 < P < N, splits this tape into two non-empty parts: A[0], A[1], ..., A[P − 1] and A[P], A[P + 1], ..., A[N − 1].

The difference between the two parts is the value of: |(A[0] + A[1] + ... + A[P − 1]) − (A[P] + A[P + 1] + ... + A[N − 1])|

In other words, it is the absolute difference between the sum of the first part and the sum of the second part.

For example, consider array A such that:
  A[0] = 3
  A[1] = 1
  A[2] = 2
  A[3] = 4
  A[4] = 3

We can split this tape in four places:

        P = 1, difference = |3 − 10| = 7
        P = 2, difference = |4 − 9| = 5
        P = 3, difference = |6 − 7| = 1
        P = 4, difference = |10 − 3| = 7

Write a function:

    int solution(vector<int> &A);

that, given a non-empty array A of N integers, returns the minimal difference that can be achieved.

For example, given:
  A[0] = 3
  A[1] = 1
  A[2] = 2
  A[3] = 4
  A[4] = 3

the function should return 1, as explained above.

Write an efficient algorithm for the following assumptions:

        N is an integer within the range [2..100,000];
        each element of array A is an integer within the range [−1,000..1,000].

Copyright 2009–2018 by Codility Limited. All Rights Reserved. Unauthorized copying, publication or disclosure prohibited. */


int solution(std::vector<int> &A) {
  int sum = 0;
  for (unsigned int i = 0; i < A.size(); ++i)
    sum += A[i];

  int diff_l = A[0];
  int diff_r = sum - A[0];

  int m_sum = std::abs(diff_l - diff_r);

  std::cout << "diff_l: " << diff_l << " diff_r: " << diff_r << "\n";

  for (unsigned int i = 1; i < A.size() - 1; ++i) {
    diff_l += A[i];
    diff_r -= A[i];
    std::cout << "diff_l: " << diff_l << " diff_r: " << diff_r << "\n";
    int diff = std::abs(diff_l - diff_r);
    if(diff < m_sum)
      m_sum = diff;
  }

  return m_sum;
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

  int sum = solution(A);

  std::cout << "The minimal difference is: " << sum << "\n";

  return 0;
}