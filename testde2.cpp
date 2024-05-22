#include<bits/stdc++.h>
using namespace std  ; 
using ll = long long  ; 

int ocolit( int a, int b ,int *x , int *y ){
	if( b == 0 ){
		*x  = 1 ;
		*y  = 0; 
		return a ; 
	}
	int x1,y1 ; 
	int gcd= ocolit(b , a%b ,  &x1,  &y1) ; 
	*x =  y1 ; 
	*y =  x1 -  (a/b) * y1 ;
	return gcd ; 
}
int nghich_modul ( int a, int m){
	int x, y ; 
	int g = ocolit(a,m,&x, &y) ; 
	if( g== 1){
		x = ( x%m +m) % m ; 
		return x ; 
	}
	return -1 ; 
}
ll powmod( ll a,ll b ,ll m){
	ll res =1 ; 
	while( b!= 0 ){
		if( b% 2== 1){
			res *= a; 
			res%= m ; 
		}
		a*= a  ; 
		a%= m ; 
		b/=2 ; 
	}
	return res ; 
}

vector<pair<ll,ll>> mahoa(string banro , int p, int a , int y){
	vector<pair<ll,ll>> banma ; 
	for( char ch : banro){
		ll m = (ll)ch; 
		int k =  rand() %  (p-1) +1 ; 
		int K = powmod(y,k,p) ; 
		ll c1 = powmod(a,k,p) ; 
		ll c2 = (K *m) %p ; 
		banma.push_back(make_pair(c1,c2));
	}
	return banma ; 
}
string giaima(vector<pair<ll,ll>> banma , int p ,int a , int x ){
	string banro  ; 
	for( pair<ll,ll> pa : banma){
		ll c1  = pa.first ; 
		ll c2 = pa.second ; 
		ll k = powmod(c1,x,p) ; 
		ll k_1 = nghich_modul(k,p) ; 
		ll m = (c2 *k_1) % p ;
		banro += (char)m ; 
	}
	return banro ; 
}

vector<int> sang ( int limit){
	vector<bool> check( limit+1 , true ) ; 
	vector<int> primes ; 
	for( int i = 2 ;  i<= sqrt(limit) ; i++){
		if(check[i]){
			for( int j = i*i ; j<= limit  ; j+= i){
				check[j] = false ; 
			}
		}
	}
	for( int i = 2  ; i<= limit ; i++){
		if( check[i]){
			primes.push_back(i) ; 
		}
	}
	return primes; 
}
int generate (vector<int> prime){
	srand
	int n =  rand() % prime.size() ;
	return n ; 
}
main(){
	vector<int> primes = sang(1000) ;
	int p = 117;   
	int a = 5 ; 
	int x ;cout <<"Vui long nhap x  : " ; cin >> x ; 
	while( x > p-1 ) {
		cout << "Nhap lai x : " ;  cin >> x; 
	} 
	 
	int y = powmod(a,x,p) ; 
	cout <<"Khoa cong khai : " <<p <<" "<<a <<" "<< y <<endl ;
	cout <<"Khoa bi mat : " <<p <<" "<<a <<" "<< x <<endl ;
	
	string dauvao = "HAUI"; 
	vector<pair<ll,ll>> banma =  mahoa(dauvao , p,a,y) ; 
	cout << "BAN MA :" ; 
	for( pair<ll,ll> pa : banma){
		cout << "(" << pa.first <<" " <<pa.second <<" ) " ;  
	}
	cout << endl ;
	string banro = giaima(banma, p,a,x) ;
	cout << "BAN RO : " <<banro << endl ;  
}