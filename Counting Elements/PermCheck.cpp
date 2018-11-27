// you can use includes, for example:
#include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

int solution(vector<int> &A) {
    int perm = 0;
    
    int N = A.size();
    
    sort(A.begin(),A.end());
    
    int max_el = *(A.end()-1);
    
    if(max_el==N) {
        
        int i = 0;
        bool found = false;
        
        while(!found && i<N) {
            if(A[i]!=i+1)
                found = true;
            else
               ++i;
        }
        
        if (found == false)
            perm = 1;
    }
   
    return perm;
}

