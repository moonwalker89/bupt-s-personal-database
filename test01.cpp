//2025.7.6
// template<typename T>//声明一个模板T,告诉编译器T是一个通用的未固定的数据类型,不用报错
// void  mySwap(T&a,T&b)//对于函数模板,需要警惕函数关于模板的操作对于转入参数的具体类型是否合法
// {
//     T temp=a;
//     a=b;
//     b=temp;
// }
// void swapInt(int &a,int &b)
// {
//     int temp=a;
//     a=b;
//     b=temp;
// }
// void swapDouble(double &a,double &b)
// {
//     double temp=a;
//     a=b;
//     b=temp;
// }
// void test01()
// {
//     int a=10,b=20;
//     // swapInt(a,b);
//     // cout<<"a="<<a<<endl;
//     // cout<<"b="<<b<<endl;
//     double c=1.1,d=2.2;
//     // swapDouble(c,d);
//     // cout<<"c="<<c<<endl;
//     // cout<<"d="<<d<<endl;
//     // mySwap(a,b);//自动识别类型
//     // mySwap(c,d);
//     mySwap<int>(a,b);//显式指定参数类型
//     mySwap<double>(c,d);
//     cout<<"a="<<a<<endl;
//     cout<<"b="<<b<<endl;
//     cout<<"c="<<c<<endl;
//     cout<<"d="<<d<<endl;
// }


//2025.7.11
//函数模板注意事项,1\自动类型推导出的T类型不能有矛盾,要一致的,2\模板必须确定出T的数据类型，才可以使用
// template<typename T>
// void  mySwap(T&a,T&b)
// {
//     T temp=a;
//     a=b;
//     b=temp;
// }
// void test01()
// {
//     int a=10,b=20;
//     mySwap(a,b);//正确的
//     char c='hhha';
//     //mySwap(a,c);//错误的，T不能即是char，又是int
//     cout<<"a="<<a<<endl;
//     cout<<"b="<<b<<endl;
// }
// template<class T>
// void func()
// {
//     cout<<"function is performing"<<endl;
// }
// void test02()
// {
//     //func();error
//     func<int>();//如果函数模板中未使用模板T，必须显式指定模板T的数据类型，告诉编译器，int，char，double其实都可以，
// }
//下面是用选择算法对数组进行从大到小的排序
// template<class T>
// void mySwap(T&a,T&b)
// {
//     T temp=a;
//     a=b;
//     b=temp;
// }
// template<class T>
// void mySelectionSort(T array[],int len)
// {
//     for(int i=0;i<len;i++)
//     {
//         int max=i;//假设当前元素是最大元素
//         for(int j=i+1;j<len;j++)//检验后面每一个元素都比当前元素小,反之则交换元素
//         {
//             if(array[max]<array[j])
//             max=j;//这个操作是找到在当前i元素后面最大的元素,不是找到一个比当前元素大的就马上修改max值
//         }
//         if(max!=i)
//         {
//             mySwap(array[max],array[i]);
//         }
//     }
// }
// template<class T>
// void myPrint(T array[],int len)
// {
//     for(int i=0;i<len;i++)
//     {
//         cout<<array[i];
//     }
//     cout<<endl;
// }
// void test01()
// {
//     char charArray[]="idajwfaja";
//     int len=sizeof(charArray)/sizeof(char);
//     mySelectionSort(charArray,len);
//     myPrint(charArray,len);
//     int intArray[]={5,5,9,5,8,4,4,7,6};
//     int num=sizeof(intArray)/sizeof(int);
//     mySelectionSort(intArray,num);
//     myPrint(intArray,num);
// }
//普通函数与函数模板区别：
// 普通函数调用时可以发生自动类型转换（隐式类型转换）
// 函数模板调用时，如果利用自动类型推导，不会发生隐式类型转换
// 如果利用显示指定类型的方式，可以发生隐式类型转换
//在这里的例子中,类型转化无论是显式,还是隐式,都要求函数是值传递,不能是引用传递
// void swapInt(int a,int b)
// {
//     int temp=a;
//     a=b;
//     b=temp;
//     cout<<"a="<<a<<endl;
//     cout<<"b="<<b<<endl;
// }
// template<class T>
// void mySwap(T a,T b)
// {
//     T temp=a;
//     a=b;
//     b=temp;
//     cout<<"a="<<a<<endl;
//     cout<<"b="<<b<<endl;
// }
// void test01()
// {
//     double a=2.1,b=39.90;
//     swapInt(a,b);
//     cout<<endl;
//     mySwap(a,b);
//     cout<<endl;
//     mySwap<int>(a,b);
// }
// int addTest(int a,int b)
// {
//     return a+b;
// }
// template<class T>
// T addTest2(T a, T b)
// {
//     return a+b;
// }
// void test02()
// {
//     int a=10,b=20;
//     char c='c';
//     cout<<addTest(a,b)<<endl;
//     cout<<"c的ASCII码是"<<(int)c<<endl;
//     cout<<addTest(a,c)<<endl;
//     cout<<endl<<endl;
//     double d=1.2,e=32.23;
//     cout<<addTest2(d,e)<<endl;
//     cout<<addTest2<double>(d,e)<<endl;
//     cout<<addTest2<int>(d,e)<<endl;
//     //cout<<addTest2(c,d);//参数类型为: (char, double),error
//     cout<<addTest2<double>(c,d)<<endl;
//     cout<<addTest2<int>(c,d)<<endl;
// }

//2025.7.12
// 1.2.5普通函数与函数模板的调用规则
// 调用规则如下：
// 1.如果函数模板和普通函数都可以实现，优先调用普通函数
// 2.可以通过空模板参数列表来强制调用函数模板
// 3.函数模板也可以发生重载
// 4.如果函数模板可以产生更好的匹配，优先调用函数模板
#include<iostream>
using namespace std;
template<class T>
void detectingDataTypes(T a);
void simplePrint(int a,int b )
{
    cout<<"普通函数在被调用中   "<<a<<endl;
}//若把普通函数的函数体或是实现给去掉,下面的simplePrint(a,b)无法正常运行
template<class T>
void simplePrint(T a,T b)
{
    cout<<"模板函数在被调用中   "<<a<<endl;
    detectingDataTypes(a);
}
template<class T>
void detectingDataTypes(T a)
{
    int size=sizeof(a);
    if(size==sizeof(int))
    {
        cout<<"此时,函数接收的参数是int类型"<<endl;
    }
    else if (size==sizeof(double))
    {
        cout<<"此时,函数接收的参数是double类型"<<endl;
    }
    else
    {
        cout<<"此时,函数接收的参数是其他类型"<<endl;
    }
}
template<class T>
void simplePrint(T a,T b,T c)
{
    cout<<"重载的模板函数在被调用中    "<<a<<endl;
    detectingDataTypes(a);
}
void test01()
{
    int a=0,b=0;
    double c=1.11,d=0;
    simplePrint(a,b);
    //通过空模板参数列表来强制调用函数模板
    simplePrint<>(a,b);
    simplePrint(a,b,100);
    
    simplePrint(c,d);//当传入的函数参数不符合普通函数的参数要求时,就会调用模板函数
    simplePrint<int>(c,d);//这个操作可以将模板函数接收到的函数参数先进行类型转化后在进行函数体代码
}

int main(){
    test01();
    return 0;
}