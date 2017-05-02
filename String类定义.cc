class String
{
public:
　　String(const char *str = NULL); // 通用构造函数
　　String(const String &another); // 拷贝构造函数
　　~String(); // 析构函数
　　String& operater =(const String &rhs); // 赋值函数
private:
　　char* m_data; // 用于保存字符串
};

//通用构造函数、拷贝构造函数有两种方式：
//一种是浅拷贝，一种是深拷贝，浅拷贝就是指向已经存在的内存地址，深拷贝就是分配新空间，将数据复制过来。
/*
// shallow copy
String::String(const char*str)
{
    m_data=str;
}
 
String::String(const String &another)
{
    *this=another;
}
*/

String::String(const char*str)
{
	if ( str == NULL ) // strlen在参数为NULL时会抛异常才会有这步判断
	{
		m_data =newchar[1] ;
		m_data[0] ='\0' ;
	}
	else
	{
		m_data =newchar[strlen(str) +1];
		strcpy(m_data,str);
	}
}

String::String(const String &another)
{
	m_data =newchar[strlen(another.m_data) +1];
	strcpy(m_data,other.m_data);
}

String & String::operator=(const String &rhs)
{
	if ( this==&rhs)
		return*this ;
	delete []m_data; //删除原来的数据，新开一块内存
	m_data =newchar[strlen(rhs.m_data) +1];
	strcpy(m_data,rhs.m_data);
	return*this ;
}

String::~String()
{
	delete []m_data ;
}
