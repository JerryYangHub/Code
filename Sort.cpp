#include <iostream>
#include <vector>

using namespace std;
//������
class CSort
{
public:
	static void print(const vector<int> &a);
	//ð������
	static void BubbleSort(vector<int> &a);
	//��������
	static void InsertSort(vector<int> &a);


};

//��ӡ
void CSort::print(const vector<int> &a)
{
	for (int i = 0;i < a.size();i++)
	{
		cout<<a[i]<<"    ";
	}
}

//ð�ݷ� �Ƚ�������������λ�ã�ÿһ�˿��Թ̶�һ��ֵ��λ��
//�Ż�˼· ������־ ��¼��һ�ε��������λ����Ϊ��һ��ѭ���Ľ���λ��
void CSort::BubbleSort(vector<int> &a)
{
	int end,flag;

	flag = a.size();
	while (flag > 0)
	{
		end = flag;
		flag = 0;//ÿ�ΰ�flag��Ϊ0����û�н�����
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

//�������� ÿ�ν�һ��ֵa[i]����ǰ���Ѿ��źõ�������a[0]-a[i-1],�γ��ź��������a[0]-a[i]
//���ź���������дӺ���ǰ���벢�ƶ�
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