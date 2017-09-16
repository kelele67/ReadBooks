/* 组合模式允许你将对象组合成树形结构来表现“整体/部分”层次结构。
 * 组合能让客户以一致的方式处理个别对象以及对象组合。
 */
        
/* 这个模式能够创建一个树形结构，
 * 在同一个结构中处理嵌套菜单和菜单项组。
 * 通过菜单和项放在相同结构中，我们创建了一个“整体/部分”层次结构，
 * 即由菜单和菜单项组成的对象树。
 * 使用组合结构，我们能把相同的操作应用在组合和个别对象上。
 * 换句话说，在大多数情况下，我们可以忽略对象组合和个别对象之间的差别
 */


/* 我们希望在午餐餐单中增加一份甜点餐单，
 * 也就是说希望能让甜点餐单变成午餐餐单的一个元素
 * 
 * 我们可以用组合模式解决这个问题：
 * 一开始我们创建一个组件接口作为餐单和菜单项的共同接口，
 * 让我们能够用统一的做法来处理菜单和菜单项。
 * 换句话说，我们可以针对菜单或菜单项调用相同的方法。
 * 然后实现菜单项和组合菜单组件，以及他们各自的方法。
 */


#include <iostream>
#include <vector>
#include <list>
#include <string>

using namespace std;

//菜单和菜单项共同的组件
class MenuComponent {
public:
	virtual void add(MenuComponent* menuComponent) {
		// 但gcc(4.8.1)中, 需要使用标准异常进行处理
		logic_error ex("add error!");
		throw exception(ex);
	}

	virtual void remove(MenuComponent* menuComponent) {
		logic_error ex("remove error!");
		throw exception(ex);
	}

	virtual MenuComponent* getChild(int i) {
		logic_error ex("getChild error!");
		throw exception(ex);
	}

	virtual string getName() {
		logic_error ex("getName error!");
		throw exception(ex);
	}

	virtual string getDescription() {
		logic_error ex("getDescription error!");
		throw exception(ex);
	}

	virtual double getPrice() {
		logic_error ex("getPrice error!");
		throw exception(ex);
	}

	virtual void print() {
		logic_error ex("getPrice error!");
		throw exception(ex);
	}
};

//菜单项类
class MenuItem : public MenuComponent {
public:
	MenuItem() {}
	MenuItem(string na, string descri, double pric) {
		name = na;
		description = descri;
		price = pric;
	}

	string getName() {
		return name;
	}

	string getDescription() {
		return description;
	}

	double getPrice() {
		return price;
	}

	void print() {
		cout << " " << getName() << ",    " << getPrice() << "    ---" << getDescription() << endl;
	}
private:
	string name;
	string description;
	double price;
};

// 组合菜单类
class Menu : public MenuComponent {
public:
	Menu(string nam, string descri) {
		name = nam;
		description = descri;
	}

	void add(MenuComponent* pMenuComponent) {
		pMenuComponents.push_back(pMenuComponent);
	}

	void remove(MenuComponent* pMenuComponent) {
		vector<MenuComponent*>::iterator iter = pMenuComponents.begin();
		for (; iter != pMenuComponents.end(); ++iter) {
			if (*iter == pMenuComponent) {
				pMenuComponents.erase(iter);
			}
		}
	}

	MenuComponent* getChild(int i) {
		return pMenuComponents[i];
	}

	string getName() {
		return name;
	}

	string getDescription() {
		return description;
	}

	void print() {
		cout << endl << getName() << ",     " << getDescription() << endl << "------------------" << endl;
		vector<MenuComponent*>::iterator iter = pMenuComponents.begin();
		while (iter != pMenuComponents.end()) {
			MenuComponent* pMenuComponent = *iter;
			pMenuComponent->print();
			++iter;
		}
	}
private:
	vector<MenuComponent*> pMenuComponents;
	string name;
	string description;
};

// 服务生类
class Waitress {
public:
	Waitress(MenuComponent* all_Menus) {
		allMenus = all_Menus;
	}

	void printMenu() {
		allMenus->print();
	}
private:
	MenuComponent* allMenus;
};

int main() {
	MenuComponent* pancakeHouseMenu = new Menu("PANCAKE HOUSE MENU", "Breakfast");
	MenuComponent* dinerMenu = new Menu("Diner MENU", "Lunch");  
    MenuComponent* dessertMenu = new Menu("DESSERT MENU","Dessert of coure!");  
  
    MenuComponent* allMenus = new Menu("ALL Menus", "All menus combined");

	allMenus->add(pancakeHouseMenu);
	allMenus->add(dinerMenu);
	dinerMenu->add(new MenuItem("Pasta", "Spaheti with Sauce", 3.89));

	dinerMenu->add(dessertMenu);
	dessertMenu->add(new MenuItem("Apple Pie", "Apple pie with a cruse", 1.59));

	Waitress* waitress = new Waitress(allMenus);
	waitress->printMenu();
	return 0;
}