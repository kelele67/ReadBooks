// 1、入队的时候更新最大值，
// 不对，出队的时候还需要比较，万一出队，则没法找到最大值了

// 2、维护一个最大堆
// O(1), O(log2N)

// 3、先来看栈的最大值
class stack {
public:
	stack() {
		stackTop = -1;
		maxStackItemIndex = -1;
	}
	void push(type x) {
		stackTop++;
		if (stackTop >= MAXN)
			;
		else {
			stackItem[stackTop] = x;
			if (x > Max()) {
				link2NextMaxItem[stackTop] = maxStackItemIndex;
				maxStackItemIndex = stackTop;
			}
			else {
				link2NextMaxItem[stackTop] = -1;
			}
		}
	}
	Type pop() {
		Type ret;
		if (stackTop < 0)
			;
		else {
			ret = stackItem[stackTop];
			if (stackTop == maxStackItemIndex) {
				maxStackItemIndex = link2NextMaxItem[stackTop];
			}
			stackTop--;
		}
		return ret;
	}

	Type max() {
		if (maxStackItemIndex >= 0) {
			return stackItem[maxStackItemIndex];
		}
		else {
			return -INF;
		}
	}

private:
	Type stackItem[MAXN];
	int stackTop;
	int link2NextMaxItem[MAXN];
	int maxStackItemIndex;
}

// 所以我们考虑用两个栈来实现一个队列
class Queue {
public:
	Type maxvalue(Type x, Type y) {
		return x > y ? x : y;
	}

	Type Queue::Max() {
		return maxvalue(stackA.Max(), stackB.Max());
	}

	Type DeQueue() {
		if (stackA.empty()) {
			while (!stackB.empty())
				stackA.push(stackB.pop());
		}
		return stackA.pop();
	}
private:
	stack stackA;
	stack stackB;
}