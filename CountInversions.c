/**********************************************************************
* PROGRAM TO COUNT THE NUMBER OF INVERSIONS IN AN ARRAY OF INTEGERS   *
*                                                                     *
*Authored by:   Sajeev R                                              *
*Created on:    14th Sep, 2016                                        *
*Completed on:                                                        *
**********************************************************************/

#include <stdio.h>
int count=0;


main(){
	int arr[]={2,4,1,3,5};
	int len=sizeof(arr)/sizeof(int);

	countInversions(arr,len);
	printf("\nThe number of inversions are: %d ",count);

	return;

}

countInversions(int *arr,int arrlen){

	int *temp=malloc(sizeof(int)*arrlen);
	mergeSortCountInv(arr,temp,0,arrlen-1);

	printf("\n Elements of arr: ");
	disp(arr,arrlen);
	printf("\n Elements of temp: ");
	disp(temp,arrlen);

	}

mergeSortCountInv(int *arr,int *temp, int p,int r){
	if(p<r){
		int q=(p+r)/2;
		mergeSortCountInv(arr,temp,p,q);
		mergeSortCountInv(arr,temp,q+1,r);
		mergeCount(arr,temp,p,q,r);
	}
	return;
}

mergeCount(int *arr,int *temp,int p,int q,int r){
	int i=p,j=q+1,k=0;

	while((i<=q)&&(j<=r)){
		if(arr[i]<arr[j]){
			temp[k++]=arr[i++];
		}
		else{
			count+=(q-i)+1;
			temp[k++]=arr[j++];
		}
	}

	while(i<=q)temp[k++]=arr[i++];
	while(j<=r)temp[k++]=arr[j++];
	return;

}


disp(int *arr,int len){
	for(int i=0;i<len;i++)
		printf(" %d",arr[i]);
}

