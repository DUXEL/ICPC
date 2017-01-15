#include <bits/stdc++.h>
#include <functional>
using namespace std;

typedef function<char(int)> f_getter;
typedef function<void(int)> f_matcher;
typedef function<char(int,int)> f_multi_getter;
typedef function<void(int,int)> f_multi_matcher;

typedef long long ll;

#define MAX_LENGTH 1005

struct KMPMatchSetting{
	int t_length;
	int p_length;
	f_getter t_getter;
	f_getter p_getter;
	f_matcher matcher;
};

int kmp_b[MAX_LENGTH];

void kmpPreprocess(KMPMatchSetting& ms) {
  int i = 0, j = -1; kmp_b[0] = -1;
  while (i < ms.p_length) {
    while (j >= 0 && ms.p_getter(i) != ms.p_getter(j)) j = kmp_b[j];
    i++; j++;
    kmp_b[i] = j;
} }

void kmpSearch(KMPMatchSetting& ms) {
  int i = 0, j = 0;
  while (i < ms.t_length) {
    while (j >= 0 && ms.t_getter(i) != ms.p_getter(j)) j = kmp_b[j];
    i++; j++;
    if (j == ms.p_length) {
      ms.matcher(i-j);
      j = kmp_b[j];
} } }

struct RobinKarpMatchSetting {
	int p_length;
	int p_amount;
	map<ll, int> p_id;
	int t_length;
	f_getter t_getter;
	f_multi_getter p_getter;
	f_multi_matcher matcher;
};

ll rk_pot[MAX_LENGTH];
ll rk_p = 257, rk_M = 1000000007, rk_p_inv = 70038911; //pow(257,10**9+7-2,10**9+7)
void initRK(){
	ll p = 1;
	for (int i = 0; i < MAX_LENGTH; i++, p=(p*rk_p)%rk_M){
		rk_pot[i]=p;
	}
}

ll calcHashRK(int start, int offset, f_getter getter){
	ll r = 0;
	for (int i = start; i < start+offset; i++) r=(r+rk_pot[i]*getter(i))%rk_M;
	return r;
}

//Pair: map hash->id , vector patterns->ids
pair<map<ll,int>,vector<int>> RKPreprocess(int length, int amount, f_multi_getter& getter){
	map<ll, int> patId;
	vector<int> ids;
	int id = 1;
	for (int i = 0; i < amount; i++){
		ll h = calcHashRK(0,length,[i,getter](int j)->char{return getter(i,j);});
		if(! patId.count(h)){
			patId[h]=id;
		}
		id++;
		ids.push_back(patId[h]);
	}
	return {patId,ids};
}

void RKSearch(RobinKarpMatchSetting &ms){
	ll h = calcHashRK(0,ms.p_length,ms.t_getter);
	if (ms.p_id.count(h)){
		ms.matcher(0, ms.p_id[h]);
	}
	for (int i = ms.p_length; i < ms.t_length; i++){
		h = ((h-ms.t_getter(i-ms.p_length))%rk_M+rk_M)%rk_M;
		h = ( h * rk_p_inv ) % rk_M;
		h = (h + ms.t_getter(i)*rk_pot[ms.p_length-1]) % rk_M;
		if (ms.p_id.count(h)){
			ms.matcher(i+1-ms.p_length,ms.p_id[h]);
		}
	}
}

char patterns [105][105];
char text[MAX_LENGTH][MAX_LENGTH];
char found_ids[MAX_LENGTH][MAX_LENGTH];

int main() {
	initRK();
	int TC;
	scanf("%d",&TC);
	int R, C;
	while (TC--){
		scanf("%d %d", &R, &C);
		for (int i = 0; i < R; i++) scanf("%s",text[i]);
		int n_patterns, patterns_length;
		scanf("%d %d", &n_patterns, &patterns_length);
		for (int i = 0; i < n_patterns; i++) scanf("%s",patterns[i]);
		f_multi_getter read_patterns = [](int i, int j)->char{return patterns[i][j];};
		pair<map<ll,int>,vector<int>> rkPair = RKPreprocess(patterns_length, n_patterns, read_patterns);
		RobinKarpMatchSetting rk_ms;
		rk_ms.p_length = patterns_length;
		rk_ms.p_amount = rkPair.first.size();
		rk_ms.p_getter = [](int id, int j)->char{return patterns[id-1][j];};
		rk_ms.p_id = rkPair.first;
		rk_ms.t_length = C;
		for (int i = 0; i < R; i++)	{
			rk_ms.t_getter = [i](int j)->char{return text[i][j];};
			rk_ms.matcher = [i](int j, int id){found_ids[i][j]=id;};
			RKSearch(rk_ms);
		}
		KMPMatchSetting kmp_ms;
		kmp_ms.p_length = n_patterns;
		kmp_ms.p_getter = [rkPair](int i)->char{return rkPair.second[i];};
		kmp_ms.t_length = R;
		int count = 0;
		kmp_ms.matcher = [&count](int i){count++;};
		kmpPreprocess(kmp_ms);
		for (int i = 0; i < C; i++){
			kmp_ms.t_getter = [i](int j)->char{return found_ids[j][i];};
			kmpSearch(kmp_ms);
		}
		printf("%d\n",count);
		if(TC) memset(found_ids,0,sizeof(found_ids[0][0]) * MAX_LENGTH * MAX_LENGTH);
	}
}
