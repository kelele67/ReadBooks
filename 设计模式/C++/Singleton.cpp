/*单例模式确保一个类只有一个实例，并提供一个全局访问点
 */


// 普通的教科书实现
class Singleton
{
protected:
	Singleton() {}
private:
	static Singleton* p;
public:
	static Singleton* instance();
};
Singleton* Singleton::p = NULL;
Singleton* Singleton::instance()
{
	if (p == NULL)
	{
		p = new Singleton();
	}
	return p;
}

// 懒汉式
/* 定义一个单例类，使用类的私有静态指针变量指向类的唯一实例，
 * 并用一个公有的静态方法获取该实例。
 * 单例模式通过类本身来管理其唯一实例，这种特性提供了解决问题的方法。唯一的实例是类的一个普通对象，
 * 但设计这个类时，让它只能创建一个实例并提供对此实例的全局访问。
 * 唯一实例类Singleton在静态成员函数中隐藏创建实例的操作。
 */

/* （1 具有一个指向唯一实例的私有静态指针m_pInstance； 
 * （2 有一个可以获取这个唯一实例的公有函数，并且在需要的时候创建该实例； 
 * （3 构造函数私有，外界不可创建该类实例
 */
class Singleton
{
private:
	Singleton() {} // 构造函数是私有的
	static Singleton *m_pInstance;
public:
	static Singleton *GetInstance()
	{
		if (m_pInstance == NULL) //判断是否第一次调用
			m_pInstance = new Singleton();
		return m_pInstance;
	}
};

// 解决上面 m_pInstance 变量释放的问题 
// 定义一个静态变量
// 程序在结束的时候，系统会自动析构所有的全局变量。
// 系统也会析构所有的类的静态成员变量
class Singleton 
{
private:
	Singleton() {}
	static Singleton *m_pInstance;
	class CGarbo //唯一的工作就是在析构函数中删除 Singleton实例
	{
	public:
		~CGarbo()
		{
			if (Singleton::m_pInstance)
				delete Singleton::m_pInstance;
		}
	};
	static CGarbo Garbo; // 定义一个静态成员变量，程序结束时，系统会自动调用他的析构函数
public:
	static Singleton *GetInstance()
	{
		if (m_pInstance == NULL)
			m_pInstance = new Singleton();
		return m_pInstance;
	}
};


// 饿汉模式
// 不像上面在单例类内部添加一个静态对象
// 而是用局部静态变量方法构造
class Singleton
{
private:
	Singleton() {}
public:
	static Singleton &GetInstance()
	{
		static Singleton instance;
		return instance;
	}
}

/* 用此种方法会出现类拷贝的问题，例如 Singleton singleton = Singleton :: GetInstance();
 * 这种调用方式编译器会为类生成一个默认的构造函数，来支持类的拷贝。这样的话就违背了单例的特性，
 * 所以我们可以稍微改一下，返回的是指针：
 */
class Singleton
{
private:
	Singleton() {}
public:
	static Singleton *GetInstance()
	{
		static Singleton instance;
		return &instance;
	}
}

/* 也可以不让编译器这么做，
 * 显式的声明类拷贝的构造函数，重载 = 操作符
 */
class Singleton
{
private:
	Singleton() {}
	Singleton(const Singleton &);
	Singleton & operator = (const Singleton &);
public:
	static Singleton &GetInstance()
	{
		static Singleton instance;
		return instance;
	}
}