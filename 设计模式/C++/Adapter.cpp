/*
 * 适配器模式将一个类的接口，转换成客户期望的另一个接口。
 * 适配器让原本接口不兼容的类可以合作无间
 */

/* 适配器可以分为类适配器和对象适配器。
 * 类适配器使用多重继承对一个接口与另一个接口进行匹配。
 * 对象适配器依赖于对象组合
 */

/* 现在假设你缺少鸭子对象（叫声为Quack,飞行输出”I’m flying !”），
 * 想用一些火鸡对象（叫声为”Gobble gobble” 飞行输出”I’m flying a short distance!”）来冒充。
 * 显而易见，因为火鸡的接口(行为)不同，所以我们不能公然拿来使用
 */

#include <iostream>
using namespace std;

// 定义鸭子类
class Duck {
public:
	virtual void quack() {}; //嘎嘎声
	virtual void fly() {};
};

// 定义绿头鸭
class MallardDuck : public Duck {
public:
	void quack() {
		cout << "Quack" << endl;
	}

	void fly() {
		cout << "I'm flying" << endl;
	}
};

// 定义火鸡
class Turkey {
public:
	virtual void gobble() {};
	virtual void fly() {};
};

// 定义野火鸡
class WildTurkey : public Turkey {
public:
	void gobble() {
		cout << "Gobble gobble" << endl;
	}
	void fly() {
		cout << "I'm flying a short distance" << endl;
	}
};

// 定义火鸡适配器
class TurkeyAdapter : public Duck {
public:
	TurkeyAdapter(Turkey* tur) : turkey(tur) {}

	void quack() {
		turkey->gobble();
	}
	void fly() {
		turkey->fly();
	}
private:
	Turkey* turkey;
};

int main() {
	Duck *duck = new MallardDuck();
	duck->quack();
	duck->fly();

	Duck *turkeyAdapter = new TurkeyAdapter(new WildTurkey());
	turkeyAdapter->quack();
	turkeyAdapter->fly();
	return 0;
}

// 适配器和装饰者模式比较：
// 适配器：将一个接口转成另一个接口。包装某些对象，让它们的接口看起来不像自己而像别的东西。

// 装饰者：不改变接口，但加入责任。将对象包装起来，让新行为加入类中