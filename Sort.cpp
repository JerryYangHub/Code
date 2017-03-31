//������
class CSort
{
public:
	static void print(const vector<int> &a);
	//ð������
	static void BubbleSort(vector<int> &a);
	//��������
	static void InsertSort(vector<int> &a);
	//ϣ������
	static void ShellSort(vector<int> &a);
	//ѡ������
	static void SelectSort(vector<int> &a);
	//�鲢����
	static void MergeSort(vector<int> &a);
	//��������
	static void QuickSort(vector<int> &a);
private:
	//�ϲ���������
	static void MergeArray(vector<int> &a,int left,int middle,int right);
	static void mergesort(vector<int> &a,int left,int right);
	static void qiucksort(vector<int> &a,int left,int right);



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

//ϣ������ �ȼ������ �����̼��
void CSort::ShellSort(vector<int> &a)
{
	for (int gap = a.size()/2;gap > 0;gap /= 2)//��С���
	{
		for (int i = gap;i < a.size();i++)
		{
			for (int j = i - gap;j >= 0 && a[j] > a[j+gap];j -= gap)//�ȼ���Ƚ� ����
			{
				swap(a[j],a[j+gap]);
			}
		}
	}
}
//ѡ������ ÿһ��ѭ��ѡ����С�ķŵ�û�й̶�λ�õ������
void CSort::SelectSort(vector<int> &a)
{
	for (int i = 0;i < a.size();i++)
	{
		int k = i;
		for (int j = i+1;j < a.size();j++)
		{
			if (a[j] < a[k]) k = j;
		}
		swap(a[k],a[i]);
	}
}

//�鲢���� һ������ֳ��������� ����������ֱ����� �ٺϲ� 
//�ֳɵ����������ֿ����ٷ֣��ݹ飩

void CSort::MergeSort(vector<int> &a)
{
	mergesort(a,0,a.size()-1);
}
//һ�����������[left,middle]���Ұ��[middle+1,right]�ֱ�������ģ��ϲ��õ�һ�����������
void CSort::MergeArray(vector<int> &a,int left,int middle,int right)
{
	if(right == 2)
	{

	}
	vector<int> t(right-left+1);
	int i = left,j = middle+1,k = 0;
	while(i <= middle && j <= right)//����Ҫ����ʱ
	{
		if (a[i] < a[j]) t[k++] = a[i++];
		else t[k++] = a[j++];
	}
	//ֻʣһ��������
	while(i <= middle) t[k++] = a[i++];
	while(j <= right) t[k++] = a[j++];

	for (i = left;i <= right;i++) a[i] = t[i-left];
}
//�鲢�ĵݹ麯��
void CSort::mergesort(vector<int> &a,int left,int right)
{

	if (left < right)
	{
		
		int middle = (left + right) / 2;
		mergesort(a,left,middle);
		mergesort(a,middle + 1,right);
		MergeArray(a,left,middle,right);
	}

}
//�������� ����һ���� ��λ �ڷֱ��������� �� �Ҳ��
void CSort::QuickSort(vector<int> &a)
{
	qiucksort(a,0,a.size()-1);
}

//���ŵĵݹ�
void CSort::qiucksort(vector<int> &a,int left,int right)
{
	if (left < right)  
	{  
	
		int i = left, j = right, x = a[left];  
		while (i < j)  
		{  
			// ���������ҵ�һ��С��x���� 
			while(i < j && a[j] >= x)  j--;	  
			if(i < j) a[i++] = a[j];
			// ���������ҵ�һ�����ڵ���x���� 
			while(i < j && a[i] < x) i++;    
			if(i < j) a[j--] = a[i];  
		}  
		a[i] = x;  
		qiucksort(a, left, i - 1); // �ݹ����   
		qiucksort(a, i + 1, right);  
	}  

}