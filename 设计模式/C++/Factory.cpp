/*工厂方法模式定义了一个创建对象的接口，
 *但由子类决定要实例化的类是哪一个。
 *工厂方法让类把实例化推迟到子类。
 */

/* 让每个区域风味的披萨工厂继承基类披萨工厂
 * 使每个工厂的订单系统不变
 * 然后创建自己风味的披萨
 * 这样真正选购披萨类型，使用具体的披萨工厂决定
 */

#include <iostream>
#include <string>
#include <list>
using namespace std;

// 首先创建披萨类
class Pizza
{
public:
	Pizza(string nam, string doug, string sauc)
	{
		name = nam;
		dough = doug; // 生面团，钱
		sauce = sauc; // 酱料
	}
	void addTops(string tops)
	{
		toppings.push_back(tops);
	}

	void prepare()
	{
		cout << "Preparing" << name << endl;
		cout << "Tossing dough" << endl;
		cout << "Adding sauce" << endl;
		cout << "Adding toppings" << endl;
		list<string>::iterator iter = toppings.begin();
		for (; iter != toppings.end(); ++iter) {
			cout << "    " << *iter;
		}
		cout << endl;
	}

	void bake()
	{
		cout << "Bake for 25 minutes at 350" << endl;
	}

	void cut()
	{
		cout << "Cutting the pizza into diagonal slices" << endl;
	}

	void box()
	{
		cout << "Place pizza in offical PizzaStore box" << endl;
	}

	string getName()
	{
		return name;
	}

private:
	string name;
	string dough;
	string sauce;
	list<string> toppings;
};

// 创建纽约cheese风格的pizza类 和 纽约clam风格的pizza类
class NYStyleCheesePizza : public Pizza
{
public:
	NYStyleCheesePizza(): Pizza("NY Style Sauce and Cheese Pizza", "Thin Crust Dough", "Marinara Sauce")
	{
		addTops("Grated Reggiano Chesse");
	}
};

class NYStyleClamPizza : public Pizza
{
public:
	NYStyleClamPizza(): Pizza("NY Style Sauce and Clam Pizza", "Thin Crust Dough", "Marinara Sauce")
	{
		addTops("Grated Clam");
	}
};

// 创建基类工厂
class PizzaStore
{
public:
	virtual ~PizzaStore() {}

	Pizza* oderPizza(string type)
	{
		Pizza* pizza = createPizza(type);
		pizza->prepare();
		pizza->bake();
		pizza->cut();
		pizza->box();

		return pizza;
	}

	virtual Pizza* createPizza(string type) {
		return NULL;
	}
};

//创建具体类工厂（纽约pizza工厂）
class NYPizzaStore : public PizzaStore
{
public:
	Pizza* createPizza(string item)
	{
		if (item == "cheese")
		{
			return new NYStyleCheesePizza();
		}
		else if (item == "clam")
		{
			return new NYStyleClamPizza();
		}
		else 
		{
			return NULL;
		}
	}
};

// ... 创建其他地区工厂

int main()
{
	PizzaStore* nyStore = new NYPizzaStore();
	Pizza* pizza = nyStore->oderPizza("cheese");
	cout << "Ethan prdered a" << pizza->getName() << endl;

	return 0;
}
