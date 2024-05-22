#include<bits/stdc++.h>
using namespace std ; 
using ll  = long long ; 
const int m =26  ; // so chu cai 
int generate_key(){
	srand((int)time(0)) ; 
	int k  =rand() % 25 ;
	return k ;  
}
ll powMod( int a, int b , int m){
	ll res  = 1  ; 
	while( b != 0 ){
		if( b%2 == 1 ){
			res *= a ; 
			res %= m ; 
		}
		a*= a; 
		a%= m ; 
		b/= 2 ; 
	}
	return res ; 
}

int ocolit( int a , int m , int *x, int *y){
	if( m ==  0  ){
		*x = 0 ; 
		*y = 1 ; 
		return a ; 
	}
	int x1, y1 ; 
	int gcd  = ocolit(m, a%m , &x1, &y1); 
	*x = y1 ; 
	*y = x1 - (a/m) *y1 ; 
	return gcd ; 
}
int nghich_modul( int a, int m ){
	int x , y ; 
	int g  =  ocolit(a,m, &x, &y) ; 
	if( g== 1 ){
		if( x <0 ) 
			x = (x % m + m ) % m ; 
		return x ; 
	}
	else return -1 ; 
}
string decrypt ( string a , int k ){
	string results = ""; 
	char newchar  ; 
	int sl , check ; 
	for( int i = 0 ;  i< a.length(); i++){
		if( (a[i] >= 'a' && a[i]<='z') || (a[i] >= 'A' && a[i] <= 'Z') ){
			sl =  (a[i] >= 'a' && a[i]<='z') ? 'a' : 'A' ; 
			check = a[i] - sl + k ; 
			if( check < 0 ) check = (check % m + m) % 26 ;  
			newchar = check % 26 + sl ; 
			results += newchar ; 
		}
		else {
			results += a[i] ; 
		}
	}
	return results ; 
}

main(){
	string a ;  cout << "Nhap ban can ma hoa : "; 
	getline(cin ,a ) ;
	int k =generate_key() ; cout <<"Khoa k " << k <<endl ;
	string ban_ma  =decrypt(a,k) ; 
	string ban_ro = decrypt(ban_ma , -k) ; 
	cout << "Ban ma :" << ban_ma <<endl ; 
	cout << "Ban ro:" << ban_ro <<endl ;  
}
