#include <bits/stdc++.h>
#define MAX 1000000
#define ll long long int

using namespace std;

struct data {
	int sum;
	bool left, right;
};

data t[4*MAX];
data make_data(int val){
	data result;
	result.sum = 0;
	result.left = (val == 1); 
	result.right = left;	
	return result;
};

data combine(data l, data r){
	data result;
	result.sum = l.sum + r.sum + ((l.right && r.left) ? 1 : 0);
	result.left = l.left;
	result.right = r.right;
	return result;
}

void build(int id, int a[], int b, int e){

	if(b == e) {t[id] = make_data(a[b]); return;}

	int m = (b+e)/2;

	build(2*id, a, b,m);
	build(2*id + 1, a, m + 1, e);

	t[id] = combine(t[2*id],t[2*id + 1]);
};

void update(int id, int b, int e, int pos, int val){

	if(b == e) {t[id] = make_data(val); return; }

	int m = (b+e)/2;

	if(pos <= m)
		update(2*id,b,m,pos,val);
	else
		update(2*id + 1, m+1, e, pos,val);
	
	t[id] = combine(t[2*id],t[2*id + 1]);

}

data query(int id, int b, int e, int i, int j) {

	if(i == b && j == e) return t[id];

	int m = (b+e)/2;

	if(j <= m) return query(2*id,b,m,i,j);
	if(i > m) return query(2*id+1,m+1,e,i,j);
	return combine(query(2*id,b,m,i,m),query(2*id+1,m+1,e,m+1,j));
};

int l,q;
int n,m,k;
int a[MAX];
char in[MAX];
char c;
int x,y;

int main(){
	scanf("%d %d",&l,&q);
	scanf("\n%s",in);
	for(int i = 1; i <= l; i++) {a[i] = (in[i-1] == '.'?1:0);}
	//printf("\n");
	build(1,a,1,l+1);
	for(int j = 1 ; j <= q ; j++){
		scanf("%d %c",&n,&c);
		//printf("%d %c\n",n,c);
		update(1,1,l+1,n+1,(c == '.' ? 1 : 0));
		data res = query(1,1,l+1,1,l+1);
		printf("%d\n",res.sum);
	}
	return 0;
}
