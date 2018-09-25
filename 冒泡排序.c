#冒泡排序

void bubble(int[] arr, int length){
	for(int i =0; i<length-1; i++)
	{
		for(int j = 0; j<len-i-1; j++)
		{
			if(arr[j]>arr[j+1])
			{
				int temp = arr[j]; 
				arr[j] = arr[j+1];
				arr[j+1] = temp;
				
				/*
				a[j]=a[j]+a[j+1];
				a[j+1]=a[j]-a[j+1];
				a[j]=a[j]-a[j+1]				
				*/
			}
		}
	}
}
