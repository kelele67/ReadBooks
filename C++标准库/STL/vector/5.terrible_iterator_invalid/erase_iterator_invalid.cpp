#include <iostream>
#include <vector>

using namespace std;
int main()
{
    vector<int> v;
    v.push_back(1);
    v.push_back(2);
    v.push_back(3);

    std::vector<int>::iterator iter1 = v.begin() + 2;
    v.erase(v.begin() + 1);
    int n = *iter1;

    return 0;
}

// erase后，迭代器失效了。

// vector迭代器的几种失效的情况：
// 1.当插入（push_back）一个元素后，end操作返回的迭代器肯定失效。
// 2.当插入(push_back)一个元素后，capacity返回值与没有插入元素之前相比有改变，则需要重新加载整个容器，此时first和end操作返回的迭代器都会失效。
3.当进行删除操作（erase，pop_back）后，指向删除点的迭代器全部失效；指向删除点后面的元素的迭代器也将全部失效。