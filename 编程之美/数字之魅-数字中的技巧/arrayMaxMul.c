// 1、从头和尾，把要除去的元素剔除后求乘积
// O(N)

// 2、分类讨论
// ①P为0
// 去掉一个0
// -> 乘积还是为0 -> 0
// -> 乘积 > 0   -> 返回
// -> 乘积 < 0   -> 0
// ②P为负数
// 把绝对值最小负数去掉
// ③P为正数
// 去掉一个绝对值最小的正数
// 
// 避免溢出->可以统计数组中正数，负数，和0的个数，从而判断P的正负性
// O(N)
