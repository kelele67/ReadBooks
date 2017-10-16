class Balls {
public:
    int calcDistance(int A, int B, int C, int D) {
        // write code here
        return (int)(distance(A) + distance(B) + distance(C) + distance(D));
    }
private:
    static int distance(int M) {
        float m = M;
        float sum = 0;
        while (m) {
            sum += m + m/2;
            m = m / 2;
        }
        return ceil(sum);
    }
     
};