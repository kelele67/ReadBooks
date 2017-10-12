// bool stringA contain B
//hash
//use the int to replace hashtable
//O1, O n+m

bool stringContain(string &a, string &b) {
    int hash = 0;
    for (int i = 0; i < a.length(); ++i) {
        hash |= (1 << (a[i] - 'A'));
    }
    for (int i = 0; i < b.length(); ++i) {
        if ((hash & (1 << (b[i] - 'A'))) == 0) {
            return false;
        }
    }
    return true;
}

//this makes me remind of the strspn

size_t _strspn(const char * string,const char * control)  
{  
    const char * str = (const char *)string;  
    const char * ctrl = (const char *)control;  
    unsigned char map[32];  
    int count = 0;  
    /*clear the map*/  
    memset(map,0,32*sizeof(unsigned char));  
    //memset(map,0,32);  
    /*set bits in control map*/  
    while(*ctrl)  
    {  
        map[*ctrl >> 3] |= (0x01 << (*ctrl & 7));  
        ctrl++;  
    }  
    /*count the str's char num in control*/  
    if(*str)  
    {  
        count = 0;  
  
        while((map[*str >> 3] & (0x01 << (*str & 7))))  
        {  
            count++;  
            str++;  
        }  
        return count;  
    }  
    return 0;  
}

int main(int args,char ** argv)  
{  
    char str[] = "129th";  
    char keys[] = "1234567890";  
  
    int i = _strspn(str,keys);  
  
    printf("the initial string has %d numbers\n",i);  
  
    getchar();  
    return 0;  
} 