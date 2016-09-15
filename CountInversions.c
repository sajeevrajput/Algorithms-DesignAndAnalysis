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

	int arr[]={16,15,14,13,20,19,18,17};
	int len=sizeof(arr)/sizeof(int);

	countInversions(arr,len);
	printf("The number of inversions are %d: ",count);

	return;

}

void countInversions(int *arr,int arrlen){

	int *temp=malloc(sizeof(int)*arrlen);
	count=mergeSortCountInv(arr,temp,0,arrlen-1);

	}

int mergeSortCountInv(int *arr,int *temp, int p,int r){
	if(p<r){
		int q=(p+r)/2;
		count+=mergeSortCountInv(arr,temp,p,q);
		count+=mergeSortCountInv(arr,temp,q+1,r);
		count+=mergeCount(arr,temp,p,q,r);
	}
	return count;
}

int mergeCount(int *arr,int *temp,int p,int q,int r){
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
	return count;

}






