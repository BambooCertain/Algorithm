#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
#include<algorithm>
#include<time.h>

const int maxn = 1e5 + 100;    //

int arr[maxn] ,tmp[maxn];  // arr数组用于存储排序前和排序后的序列，tmp数组用于在二分归并排序的过程中使用
int n; // n 代表序列的长度
void Mergesort(int l,int r)
{
    int mid = (l + r) >> 1;
    if(r - l + 1 <= 1)  // 如果序列长度<=1的话那么这个序列必然是有序的
    {
        return;
    }
    else if(r - l + 1 == 2) // 如果这个序列的长度 == 2 那么我们可以手动对这个序列进行排序
    {
        if(arr[r] < arr[l])
        {
        	int t;
        	t = arr[r];
        	arr[r] = arr[l];
        	arr[l] = t;
		}
    }
    else
    {
    	Mergesort(l , mid);     
    	Mergesort(mid + 1,  r); 
        // 当序列长度 > 2时，我们把序列分成两块，分别对序列的左子序列，和右子序列进行排序
        // 左右子序列排好序之后，我们需要把左右两个子序列归并成为一个有序序列
        int s1 = l , s2 = mid + 1;
        int s = l;
        while(s1 <= mid && s2 <= r) // 每次只取两个子序列中最小，这样来将两个子序列归并到一起
        {
            if(arr[s1] < arr[s2]) tmp[s++] = arr[s1++];
            else tmp[s++] = arr[s2++];
        }
        while(s1 <= mid) tmp[s++] = arr[s1++];
        while(s2 <= r) tmp[s++] = arr[s2++];
        for(int i = l ; i <= r; ++ i) arr[i] = tmp[i]; // 把排序好的tmp数组赋值给arr
    }
}


int main()
{
	srand(time(NULL));
    scanf("%d",&n);
    for(int i = 1 ; i <= n ; ++ i)
    {
        arr[i] = rand()%100 + 1; // 通过随机数生成数组元素
    }
    Mergesort(1 , n);
    for(int i = 1 ; i <= n ; ++ i)
    {
        printf("%d ",arr[i]);
    }
    printf("\n");
    return 0;
}
