//排序类
class CSort
{
public:
	static void print(const vector<int> &a);
	//冒泡排序法
	static void BubbleSort(vector<int> &a);
	//插入排序法
	static void InsertSort(vector<int> &a);
	//希尔排序法
	static void ShellSort(vector<int> &a);
	//选择排序法
	static void SelectSort(vector<int> &a);
	//归并排序
	static void MergeSort(vector<int> &a);
	//快速排序
	static void QuickSort(vector<int> &a);
private:
	//合并有序数组
	static void MergeArray(vector<int> &a,int left,int middle,int right);
	static void mergesort(vector<int> &a,int left,int right);
	static void qiucksort(vector<int> &a,int left,int right);



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

//希尔排序 等间隔排序 再缩短间隔
void CSort::ShellSort(vector<int> &a)
{
	for (int gap = a.size()/2;gap > 0;gap /= 2)//缩小间隔
	{
		for (int i = gap;i < a.size();i++)
		{
			for (int j = i - gap;j >= 0 && a[j] > a[j+gap];j -= gap)//等间隔比较 插入
			{
				swap(a[j],a[j+gap]);
			}
		}
	}
}
//选择排序 每一次循环选择最小的放到没有固定位置的最左侧
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

//归并排序 一个数组分成两个数组 对两个数组分别排序 再合并 
//分成的两个数组又可以再分（递归）

void CSort::MergeSort(vector<int> &a)
{
	mergesort(a,0,a.size()-1);
}
//一个数组的左半侧[left,middle]和右半侧[middle+1,right]分别是有序的，合并得到一个有序的数组
void CSort::MergeArray(vector<int> &a,int left,int middle,int right)
{
	if(right == 2)
	{

	}
	vector<int> t(right-left+1);
	int i = left,j = middle+1,k = 0;
	while(i <= middle && j <= right)//都还要数据时
	{
		if (a[i] < a[j]) t[k++] = a[i++];
		else t[k++] = a[j++];
	}
	//只剩一个有数据
	while(i <= middle) t[k++] = a[i++];
	while(j <= right) t[k++] = a[j++];

	for (i = left;i <= right;i++) a[i] = t[i-left];
}
//归并的递归函数
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
//快速排序 任意一个数 定位 在分别排它左侧的 和 右侧的
void CSort::QuickSort(vector<int> &a)
{
	qiucksort(a,0,a.size()-1);
}

//快排的递归
void CSort::qiucksort(vector<int> &a,int left,int right)
{
	if (left < right)  
	{  
	
		int i = left, j = right, x = a[left];  
		while (i < j)  
		{  
			// 从右向左找第一个小于x的数 
			while(i < j && a[j] >= x)  j--;	  
			if(i < j) a[i++] = a[j];
			// 从左向右找第一个大于等于x的数 
			while(i < j && a[i] < x) i++;    
			if(i < j) a[j--] = a[i];  
		}  
		a[i] = x;  
		qiucksort(a, left, i - 1); // 递归调用   
		qiucksort(a, i + 1, right);  
	}  

}