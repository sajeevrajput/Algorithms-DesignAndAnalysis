/************************************************************************
* PROGRAM TO COUNT THE NUMBER OF INVERSIONS IN AN ARRAY OF INTEGERS   	*
*                                                                     	*
*	Inversions are counted by piggybacking the count variable in 	*
*	MergeSort(O(nlogn)) rather than using a layman's O(n^2)timed	*
*	algorithm							* 
*	IMPORTANT:							*
* 		The variable size here is INT which can take only 16-bit*
* 		size. Use big data type like unsigned long int (and 	*
* 		format specifier %ul) to get the desired result.	*
*									*									*
*Authored by:   Sajeev R                                              	*
*Created on:    14th Sep, 2016                                        	*
*Completed on:  18th Sep, 2016                                        	*
************************************************************************/

#include <stdio.h>
int count=0;
int len=0;


main(){
	int arr[]={1, 20, 6, 4, 5};
	//int arr[]={};
	len=sizeof(arr)/sizeof(int);
	countInversions(arr,len);
	printf("\nThe number of inversions are: %d ",count);
	return;
}

countInversions(int arr[],int arrlen){	//CALLER FUNCTION to MERGE SORT

	printf("\n Before Sorted: ");
	disp(arr,arrlen);
	
	int *temp=malloc(sizeof(int)*arrlen);
	mergeSortCountInv(arr,temp,0,arrlen-1);

	printf("\n After Sorted: ");
	disp(temp,arrlen);
	}

mergeSortCountInv(int arr[],int temp[], int p,int r){	//RECURSIVELY CALL MERGESORT
							//AND MERGE THEM
	int q=0;
	if(p<r){
		q=(p+r)/2;
		mergeSortCountInv(arr,temp,p,q);
		mergeSortCountInv(arr,temp,q+1,r);
		mergeCount(arr,temp,p,q,r);
	}
	return;
}

mergeCount(int arr[],int temp[],int p,int q,int r){
	int i=p,j=q+1,k=0;

	while((i<=q)&&(j<=r)){
		if(arr[i]<=arr[j]){
			temp[k++]=arr[i++];
		}
		else{
			count+=(q-i)+1;			//calculate the number of inversions
			temp[k++]=arr[j++];
		}
	}

	while(i<=q)temp[k++]=arr[i++];	//Copy the remaining arr values if any
	while(j<=r)temp[k++]=arr[j++];

	for(i=p;i<=r;i++)	/*else while merging sub arrays in arr[] wont be sorted	*/
		arr[i]=temp[i-p];

	return;

}


disp(int a[],int len){				//DISPLAY FUNCTION TO PRINT ELEMENTS OF AN ARRAY
	printf("\n");
	for(int i=0;i<len;i++)
		printf(" %d",a[i]);
	printf("\n");
}

//2407905288


