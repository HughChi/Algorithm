#include <stdio.h>
int a[100],n;
void quickSort(int left,int right){
	int partition;
	int i=left;
	int j=right;
	if(left>right)
		return;
	partition=a[left];

	while(i!=j){
		while(a[j]>=partition && i<j)
			j--;
		while(a[i]<=partition && i<j)
			i++;
		if(i<j){
			int temp=a[i];
			a[i]=a[j];
			a[j]=temp;
		}
	}
	a[left]=a[i];
	a[i]=partition;
	quickSort(left,i-1);
	quickSort(i+1,right);

}
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	quickSort(1,n);
	for(int i=1;i<=n;i++){
		printf("%d",a[i]);
	}
	return 0;
}