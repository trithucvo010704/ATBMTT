#include<bits/stdc++.h>
using namespace std  ; 
using ll = long long ; 
int gcd( int a, int b ){
	if( a< b ) return gcd(b,a) ; 
	else if ( b == 0 ) return a ; 
	else return gcd( b ,a % b ) ; 
}
int gcd2(int a, int b){
	while( a* b != 0){
		if( a > b ) a%= b ; 
		else b %= a ; 
	}
	return a+b ; 
}
int ocolit( int a, int m , int *x , int *y ){
	if( m == 0 ){
		*x = 1 ; 
		*y = 0 ; 
		return a  ; 
	}
	int x1 ,y1  ; 
	int gcd = ocolit(m,a%m,&x1,&y1) ; 
	*x = y1 ; 
	*y = x1 - (a/m) * y1 ; 
	return gcd ; 
}
int nghich_modul ( int a, int m ){
	int x ,y ; 
	int g =  ocolit(a,m,&x,&y) ; 
	if(g == 1){
		x = (x % m + m  ) % m ; 
		return x ; 
	}
	return -1 ; 
}
ll powMod( int a, int b, int m ){
	ll res  = 1  ; 
	while( b!= 0 ){
		if( b%2 == 1){
			res *= a ; 
			res %= m ; 
		}
		a*=a ; 
		a%= m ; 
		b/= 2 ; 
	}
	return res ; 
}

vector<ll> mahoa ( string a , ll n ,ll e ){
	vector<ll> ban_ma ; 
	for( char ch : a){
		ll m = (ll)ch ; 
		ll result = powMod(m,e,n) ; 
		ban_ma.push_back(result); 
	}
	
	return ban_ma ; 
}
string giaima ( vector<ll> mahoa , ll n , ll d) {
	string kq="" ; 
	for( ll a : mahoa){
		ll c  = powMod(a,d,n); 
		kq += (char) c ; 
	}
	return kq ; 
}
main(){
	int p = 17 , q =19 ; 
	cout << "P = " <<p <<" Q= " <<q <<endl ;
	ll n = p*q ; 
	ll phi = (p-1) *(q-1) ; 
	ll e = 2 ; 
	while(e <phi){
		if( gcd2(e,phi) == 1){
			break ; 
		}
		else {
			++e; 
		}
	}
	int d = nghich_modul(e,phi) ; 
	cout <<"Khoa cong khai e = " <<e <<" n = " <<n <<endl ; 
	cout <<"Khoa bi mat d = " <<d <<" n = " <<n <<endl ;
	
	string dauvao = "THUC"; 
	vector<ll> ban_ma = mahoa(dauvao,n,e) ; 
	cout << "Ban ma :" ; 
	for( ll a : ban_ma ) cout << a <<" " ; 
	cout << endl ; 
	string ban_ro = giaima(ban_ma ,n,d) ; 
	cout << "Ban ro "<< ban_ro <<endl ;
}