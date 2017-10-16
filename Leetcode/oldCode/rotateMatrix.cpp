//首先想到直接旋转，但是一层一层超级慢
//所以想到先沿对角线翻转，再沿水平中线翻转

class Solution {
public:
    vector<vector<int> > rotateMatrix(vector<vector<int> > mat, int n) {
        // write code here
        // 沿对角线翻转（左下角到右上角的对角线）
        for (int i = 0; i < n; ++i) {
        	for (int j = 0; j < n -i; ++j) {
        		swap(mat[i][j], mat[n - 1 - j][n - 1 - i]);
        	}
        }
        for (int i = 0; i < n / 2; ++i) {
        	for (int j = 0; j < n; ++j) {
        		swap(mat[i][j], mat[n - 1 - i][j]);
        	}
        }
        return mat;
    }
};