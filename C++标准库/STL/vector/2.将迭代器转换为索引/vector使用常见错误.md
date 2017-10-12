## 1

```c++
vector< int > ivec; 
ivec[ 0 ] = 1024; //错误
```
---

因为 ivec 还没有第一个元素 ，我们只能索引 vector 中已经存在的元素 size()操作返回 vector 包含的元素的个数。 

## 2

```c++
const int size = 7; 
int ia[ size ] = { 0, 1, 1, 2, 3, 5, 8 }; 
vector< int > ivec( size ); 

for ( int ix = 0; ix < size; ++ix ) 
      ivec.push_back( ia[ ix ]); 
```
---

程序结束时ivec 包含 14 个元素, ia 的元素从第八个元素开始插入。