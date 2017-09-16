/*  抽象工厂模式提供一个接口，
 *  用于创建相关或依赖对象的家族，
 *  而不需要明确指定具体类。
 */

/*  数据库访问程序设计，
 *  不同的数据库访问方式可能不一样，
 *  为了抽象对对不同数据库的访问，
 *  可以将数据库隐藏起来，提供统一的访问方式，
 *  用多态进行实现
 */

#include <iostream>
using namespace std;

// user表接口
class IUser
{
public:
	virtual void Insert() = 0;
	virtual void GetUser() = 0;
};

// SqlServer
class SqlServerUser : public IUser
{
public:
	void Insert()
	{
		cout << "在SqlServer中给user表增加一条记录" << endl;
	}
	void GetUser()
	{
		cout << "在SqlServer中给user表获取一条记录" << endl;
	}
};

// Access
class AccessUser : public IUser
{
public:
	void Insert()
	{
		cout << "在Access中给user表增加一条记录" << endl;
	}
	void GetUser()
	{
		cout << "在Access中给user表获取一条记录" << endl;
	}
};

// Department表 接口
class IDepartment
{
public:
	virtual void Insert() = 0;
	virtual void GetDepartment() = 0;
};

// SqlServer
class SqlServerDepartment : public IDepartment  
{  
public:  
    void Insert()  
    {  
        cout<<"在SQL Server中给Department表增加一条记录"<<endl;  
    }  
    void GetDepartment()  
    {  
        cout<<"在SQL Server中Department获取一条记录"<<endl;  
    }  
}; 

// Access
class AccessDepartment : public IDepartment  
{  
public:  
    void Insert()  
    {  
        cout<<"在Access中给Department表增加一条记录"<<endl;  
    }  
    void GetDepartment()  
    {  
        cout<<"在Access中Department获取一条记录"<<endl;  
    } 
};

// 抽象工厂接口
class IFactory  
{  
public:  
    virtual IUser* CreateUser() = 0;  
    virtual IDepartment* CreateDepartment() = 0;  
};  

// SqlServer工厂实现
class SqlServerFactory : public IFactory
{
	IUser* CreateUser()
	{ 
		return new SqlServerUser();
	}
	IDepartment* CreateDepartment()
	{
		return new SqlServerDepartment();
	}
};

// Access工厂实现
class AccessFactory : public IFactory  
{  
    IUser* CreateUser()  
    {  
        return new AccessUser();  
    }  
    IDepartment* CreateDepartment()  
    {  
        return new AccessDepartment();  
    }  
};  

// 客户代码
int main()
{
	//创建工厂
	IFactory *pFactory = NULL;
	IUser *pUser = NULL;
	IDepartment *pDepartment = NULL;
	int choice;
	cout << "选择数据库：";
	cin >> choice;
	switch(choice)
	{
		case 1:
			pFactory = new SqlServerFactory(); // 创建 SqlServer 访问的工厂
			break;
		case 2:
			pFactory = new AccessFactory(); // 创建Access访问的工厂
			break;
	}
	// 一致的操作
	pUser = pFactory->CreateUser();
	pDepartment = pFactory->CreateDepartment();
	pUser->Insert();
	pUser->GetUser();
	pDepartment->Insert();
	pDepartment->GetDepartment();

	return 0;
}