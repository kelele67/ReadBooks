// 1、暴力直接循环
char c[10][10] = {
	"",
	"",
	"ABC",
	"DEF",
	"GHI",
	"JKL",
	"MNO",
	"PQRS",
	"TUV",
	"WXYZ",
};

int total[10] = {0, 0, 3, 3, 3, 3, 3, 4, 3, 4};

int number[TelLength];
int answer[TelLength];
// n位号码n个循环
// 。。。没人会这么写吧。。。

while (true) {
	for (i = 0; i < n; i++)
		printf("%c", c[number[i]][answer[i]]);
	printf("\n");
	int k = n - 1;
	while (k >= 0) {
		if (answer[k] < total[number[k]] - 1) {
			answer[k]++;
			break;
		}
		else {
			answer[k] = 0;
			k--;
		}
	}
	if (k < 0)
		break;
}

// 递归
void RecursiveSearch(int *number, int *answer, int idnex, int n) {
	if (idnex == n) {
		for (int i = 0; i < n; i++) {
			printf("%c", c[number[i]][answer[i]]);
		}
		printf("\n");
		return;
	}
	for (answer[index] =0; answer[index] < total[number[index]]; answer[index]++) {
		RecursiveSearch(number, answer, index+1, n);
	}
}

// 利用1中的算法，把该电话号码所对应的字符全部计算出来，然后去匹配字典，判断是否有答案
// 可以直接把字典里面的所有单词按照这种转换规则转换为数字->成为另一本数字字典