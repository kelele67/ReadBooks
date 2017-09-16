/**
 * 通过银行家算法预防死锁
 * 防止进入不安全状态
 */
#include <stdio.h>
#define RESOURCE_NUM 3
#define PROCESS_NUM 5

/* 对三种可分配资源定义结构体 */
typedef struct {
	int a;
	int b;
	int c;
} Resource;

/* 对各进程的资源进行初始化 */
Resource available = {3, 3, 2};
Resource x_max[PROCESS_NUM] = {{7 , 5 , 3} , {3 , 2 , 2} , {9 , 0 , 2} , {2 , 2 , 2} , {4 , 3 , 3}}; // 最大需要的资源
Resource allocation[PROCESS_NUM] = {{0 , 1 , 0} , {2 , 0 , 0} , {3 , 0 , 2} , {2 , 1 , 1} , {0 , 0 , 2}}; // 已经占有的资源
Resource need[PROCESS_NUM] = {{7 , 4 , 3} , {1 , 2 , 2} , {6 , 0 , 0} , {0 , 1 , 1} , {4 , 3 , 1}}; // 还需要的资源

/* 进行资源的尝试性分配 */
bool tryToDistribution(int process_id, Resource *r);

/* 分配资源不安全时进行回滚 */
void callBack(int process_id, Resource *r);

bool checkSecurity();

void outputResource();

/* 进行资源的尝试性分配 */
bool tryToDistribution(int process_id, Resource *r) {
	if (r->a > need[process_id].a || r->b > need[process_id].b ||r->c > need[process_id].c) {
		printf("The dilever is more than need !\n");
		return false;
	}
	if (r->a > available.a || r->b > available.b || r->c > available.c) {
		printf("The resource is not enough !\n");
		return false;
	}
	// 可利用资源向量
	available.a -= r->a;
	available.b -= r->b;
	available.c -= r->c;

	// 分配矩阵
	allocation[process_id].a += r->a;
	allocation[process_id].b += r->b;
	allocation[process_id].c += r->c;

	// 需求矩阵
	need[process_id].a -= r->a;
	need[process_id].b -= r->b;
	need[process_id].c -= r->c;
	return true;
}

/* 进行资源的安全性检查 */
bool checkSecurity() {
	bool finish[5] = {false};
	Resource work = available;
	while (true) {
		int pro_id, i; // 记录满足条件的进程
		// 寻找满足分配条件的进程
		for (i = 0; i < PROCESS_NUM; i++) {
			if (!finish[i]) {
				// 减产满足条件的进程
				if (need[i].a <= work.a && need[i].b <= work.b && need[i].c <= work.c) {
					pro_id = i;
					break;
				}
			}
		}
		if (i == PROCESS_NUM) {
			for (int j = 0; j < i; j++) {
				if (!finish[j]) {
					return false;
				}
			}
			return true;
		}

		work.a += allocation[i].a;
		work.b += allocation[i].b;
		work.c += allocation[i].c;

		finish[pro_id] = true;
	}
	return false;
}

/* 资源分配不安全时进行回滚 */
void callBack(int process_id, Resource *r) {
	available.a += r->a;
	available.b += r->b;
	available.c += r->c;

	allocation[process_id].a -= r->a;
	allocation[process_id].b -= r->b;
	allocation[process_id].c -= r->c;

	need[process_id].a += r->a;
	need[process_id].b += r->b;
	need[process_id].c += r->c;
}

/* 进行当前资源状态的输出操作 */
void outputResource() {
	printf("   ----MAX----    Allocation  -----Need-----\n");
	printf("   a    b    c  |  a   b   c |   a   b   c  \n");
	for(int i = 0; i < PROCESS_NUM; i++) {
		printf("P%d:", i);
		printf("%3d %3d %3d |", x_max[i].a, x_max[i].b, x_max[i].c);
		printf("%3d %3d %3d |", allocation[i].a, allocation[i].b, allocation[i].c);
		printf("%3d %3d %3d ", need[i].a, need[i].b, need[i].c);
		printf("\n");
	}
	printf("The available resourece now : a : %d b : %d c : %d\n", available.a, available.b, available.c);
}

int main() {
	outputResource();

	int process_id, choice;
	Resource r;
	while (true) {
		printf("Wheather go on deliever : (0 or 1) ");
		scanf("%d", &choice);
		if (choice) {
			printf("Please input request : (x and request) ");
			scanf("%d %d %d %d", &process_id, &r.a, &r.b, &r.c);
			if (tryToDistribution(process_id, &r)) {
				if (checkSecurity()) {
					printf("Resource deliever success !\n");
					if (!need[process_id].a) {
						available.a += allocation[process_id].a;
					}
					if (!need[process_id].b) {
						available.b += allocation[process_id].b;
					}
					if (!need[process_id].c) {
						available.c += allocation[process_id].c;
					}
					outputResource();
				}
				else {
					printf("The resource deliever is not safe !\n");
					callBack(process_id, &r);
				}
			}
			else {
				continue;
			}
		}
		else {
			break;
		}
	}
	printf("Handle over !\n");
	return 0;
}
