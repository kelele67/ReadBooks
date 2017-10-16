// //想到的方法是奇数行直接push_back进vector，偶数行的时候先入栈，再pop到
// class Printer {
// public:
//     vector<int> printMatrix(vector<vector<int> > mat, int n, int m) {
//         // write code here

//     	vector<int> result;
//     	stack<int> s;
//         for (int i = 0; i < n; i ++) {
//         	for (int j = 0; j < m; j++) {
//         		//
//         		if (i % 2 == 0 || i == 0) {
//         			result.push_back(mat[i][j]);
//         		} else {
//         			s.push(mat[i][j]);
//                     if (s.size() == m) {
//                         while (!s.empty()) {
//                             int p = s.top();
//                             result.push_back(p);
//                             s.pop();
//                         }
//                     }
//         		}
//         	}
//         }
//         return result;
//     }
// };

class Printer {
public:
    vector<int> printMatrix(vector<vector<int> > mat, int n, int m) {
        // write code here
        vector<int> result;
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            if (i % 2 == 0){
                result.push_back(mat[i][j]);
            }
            else{
                result.push_back(mat[i][m-j-1]);
            }
        }
    }
    return result;
    }
};