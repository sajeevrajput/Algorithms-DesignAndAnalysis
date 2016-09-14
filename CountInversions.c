/**********************************************************************
* PROGRAM TO COUNT THE NUMBER OF INVERSIONS IN AN ARRAY OF INTEGERS   *
*                                                                     *
*Authored by:   Sajeev R                                              *
*Created on:    14th Sep, 2016                                        *
*Completed on:                                                        *
**********************************************************************/

#include <stdio.h>

main(){

	int arr[]={16,15,14,13,20,19,18,17};
	int len=sizeof(arr)/sizeof(int);
	//disp(arr,len);
	countInversions(arr,len);


}

void countInversions(int *arr,int arrlen){
		int mid=arrlen/2;
		int *left = malloc(mid*sizeof(int)), *right=malloc((arrlen-mid)*sizeof(int));

		countInversions(arr[mid],arrlen-mid);

	}
/*
void disp(int arr[],int len){
	int i;
	for(i=0; i<len;i++){
		printf("\nElement at %d is :%d",i,arr[i]);
	}
}
*/
