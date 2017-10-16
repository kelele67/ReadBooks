//如果有一个时间能使得B的空闲时间 = A的空闲时间
//那么就说明这个时间是合适的
//完全不懂这题，感觉他其实是让我们求是否交集

#include <iostream>
#include <unordered_map>
using namespace std;

using MyHash = unordered_map<int, bool>;

int main(void) {
	int p, q, l, r;
	while (cin >> p >> q >> l >> r) {
		int a[p], b[p];
		for (int i = 0; i < p; ++i) {
			cin >> a[i] >> b[i];
		}

		int c[q], d[q];
		for (int i = 0; i < q; ++i) {
			cin >> c[i] >> d[i];
		}

		MyHash hash_cnt;
		for (int i = 0; i < p; ++i) {
			for (int j = 0; j < q; ++j) {
				//用滚动数组
				int tp1 = a[i] - d[j];
				int tp2 = b[i] - c[j];

				//最小差值 超过区间
				if (tp2 > r) tp2 = r;
				
				//最大差值 小于区间
				if (tp1 < l) tp1 = l;

				for (int i = tp1; i <= tp2; ++i) {
					hash_cnt.insert(MyHash::value_type(i, true));
				}
			}
		}
		cout << hash_cnt.size() << endl;
	}
	return 0;
}