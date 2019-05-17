#include<vector>

using namespace std;


class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        int m = matrix.size();
        if(m == 0) return 0;
        int n = matrix[0].size();
        vector<int> h(n,0) ,left(n,0),right(n,n);
        int ret = 0;
        for(int i = 0;i < m;i++) {
            int l = 0;
            int r = n;
            for(int j = 0;j < n;j++) {
                h[j] = matrix[i][j] == '0' ? 0:h[j]+1;
                if(h[j] > 0) {
                    left[j] = left[j] > l ? left[j] : l;
                }
                else {
                    left[j] = 0;
                    l = j+1;
                }
            }
            for(int j = n-1;j >= 0;j--) {
                if(h[j] > 0) {
                    right[j] = right[j] < r ? right[j] : r;
                }
                else {
                    right[j] = n;
                    r = j;
                }
            }
            for(int j = 0;j < n;j++) {
                if(ret < (right[j] - left[j]) * h[j]) {
                    ret = (right[j] - left[j]) * h[j];
                }
            }
        }
        return ret;
    }
};
