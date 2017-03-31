#include <iostream>
#include <vector>

using namespace std;
//排序类
class CSort
{
public:
	static void print(const vector<int> &a);
	//冒泡排序法
	static void BubbleSort(vector<int> &a);
	//插入排序法
	static void InsertSort(vector<int> &a);


};

//打印
void CSort::print(const vector<int> &a)
{
	for (int i = 0;i < a.size();i++)
	{
		cout<<a[i]<<"    ";
	}
}

//冒泡法 比较相邻两个调换位置，每一趟可以固定一个值的位置
//优化思路 设立标志 记录上一次调换的最后位置作为下一次循环的结束位置
void CSort::BubbleSort(vector<int> &a)
{
	int end,flag;

	flag = a.size();
	while (flag > 0)
	{
		end = flag;
		flag = 0;//每次把flag记为0，表没有交换了
		for (int i = 1;i < end;i++)
		{
			if (a[i-1] > a[i])
			{
				swap(a[i-1],a[i]);
				flag = i;
			}
		}
	}
}

//插入排序 每次将一个值a[i]插入前面已经排好的序列中a[0]-a[i-1],形成排好序的序列a[0]-a[i]
//在排好序的序列中从后向前插入并移动
void CSort::InsertSort(vector<int> &a)
{
	for (int i = 1;i < a.size();i++)
	{
		for (int j = i-1;j >= 0 && a[j] > a[j+1];j--)
		{
			swap(a[j],a[j+1]);
		}
	}
}

int main()
{
	cout<<"Sort test.........."<<endl;
	cout<<"array: ";
	int a[] ={3,3,4,5,81,33,97,10,0};
	vector<int> _array(a,a+9);
	CSort::print(_array);
	CSort::InsertSort(_array);
	cout<<endl;
	cout<<"result: ";
	CSort::print(_array);
	cout<<endl;
}