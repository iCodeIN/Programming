#include <stdio.h>

#define MAX 1000

using namespace std;

int n, l;

int merge(int a[], int tmp[],int b, int m, int e){
	int cont = 0;
	for(int i = b; i <= e; i++)
		tmp[i] = a[i];

	int i = b;
	int l = b;
	int r = m+1;
	while(l <= m && r <= e){

		if(tmp[l] <= tmp[r]) a[i] = tmp[l++];
		else { cont+= (m+1 - l); a[i] = tmp[r++];}
		i++;
	}

	while(l <= m) {a[i] = tmp[l++]; i++;}
	while(r <= e) {a[i] = tmp[r++]; i++;}

	return cont;
}

int merge_sort(int a[], int tmp[],int b, int e){
	int cont = 0;
	if(b < e){	
		int m = (b+e)/2;
		cont += merge_sort(a,tmp,b,m);
		cont += merge_sort(a,tmp,m+1,e);
		cont += merge(a,tmp,b,m,e);
	}

	return cont;
}

int a[MAX];
int tmp[MAX];
int main(){

	scanf("%d",&n);
	for(int i = 0 ; i <  n; i++)
	{
		scanf("%d",&l);
		for(int j = 0 ;  j < l ;  j++)
			scanf("%d",&a[j]);
		printf("Optimal train swapping takes %d swaps.\n",merge_sort(a,tmp,0,l-1));
	

	}

	return 0;
}
