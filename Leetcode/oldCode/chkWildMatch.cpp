//检查正则表达式的匹配
//递归
class WildMatch {
public:
    bool chkWildMatch(string A, int lena, string B, int lenb) {
        // write code here
        return isMatch(A.c_str(), B.c_str());
    }

private:
	bool isMatch(const char *a, const char *b) {
		if (*b == '\0') return *a == '\0';
		//如果字母b后面不是'*'，那么b必须匹配一个，否则FALSE
		if (*(b + 1) != '*') {
			// 注意：虽然b为'.'时代表任意一个字符，但是不能匹配 '\0'
			if (*a == *b || (*b == '.' && *a != '\0')) {
				return isMatch(a + 1, b + 1);
			} else {
				return false;
			}
		} else {
			//字母b后面是'*''
			//当字母b匹配或者b为'.'时，跳过b和'*'再进行匹配
			while (*a == *b || (*b == '.' && *a != '\0')) {
				if (isMatch(a, b + 2)) {
					return true;
				}
				a++;
			}
			return isMatch(a, b + 2);
		}
	}
};