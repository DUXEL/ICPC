//============================================================================
// Name        : duxel.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <bits/stdc++.h>

using namespace std;

int fenwick[100002];

struct data{
	int l,r,value,index;
	bool typ;
};

int myfunc(data a, data b){
	if (a.r == b.r) return a.typ<b.typ;
	return a.r < b.r;
}

int LSOne(int s){
	return s&(-s);
}

int get(int b){
	int res=0;
	for(;b;b-=LSOne(b)) res+= fenwick[b];
	return res;
}

void update(int k, int v){
	for(;k<100010; k+= LSOne(k) ) fenwick[k]+=v;
}


int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n, q, a, b;
	//freopen("input","r",stdin);
	while(cin>>n){
		fill(fenwick,fenwick+100002, 0);
		data arr[100000+10010];
		for(int i=1; i<=n; i++){
			update(i,1);
		}
		int i;
		for(i=0; i<n; i++){
			cin >> arr[i].value;
			arr[i].typ = false;
			arr[i].index = i+1;
			arr[i].r = i+1;
		}
		cin >> q;

		int cnt=0;
		for(int j=i; j<n+q; j++){
			cin >> a >> b;
			arr[j].l =a;
			arr[j].r = b;
			arr[j].index = cnt++;
			arr[j].typ = true;
		}

		sort(arr, arr+n+q, myfunc);


		bool visitado[12];
		fill(visitado, visitado+12, false);
		int ans[q];
		int prev[12];

		for(int i=0; i<n+q; i++){
			if (arr[i].typ){
				ans[arr[i].index] = get(arr[i].r) - get(arr[i].l-1);
			}else{
				if (visitado[arr[i].value]){
					update(prev[arr[i].value], -1);
				}
				prev[arr[i].value] = arr[i].index;
				visitado[arr[i].value] = 1;
			}
		}

		for(int i=0; i<q; i++) cout << ans[i] << "\n";

	}
	return 0;
}
