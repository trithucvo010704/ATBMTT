#include<bits/stdc++.h>
using namespace std ; 

using ll=  long long ; 
const int m  =26   ; // so luong chu cai 
ll powMod( int a, int b , int m ){
	ll res =  1 ; 
	while( b!= 0 ){
		if( b %2 == 1 ){
			res *=  a ; 
			res %= m ; 
		}
		a *= a ; 
		a %= m ; 
		b/= 2 ; 
	}
	return res ; 
}
int ocolit_morong ( int a , int m , int *x , int *y ){
	if( m == 0 ){
		*x = 1 ; 
		*y = 0 ; 
		return a ; 
	}
	int x1,y1 ; 
	int gcd = ocolit_morong( m , a%m , &x1, &y1); 
	*x = y1 ; 
	*y = x1 - (a/m ) *y1 ; 
	return gcd ; 
}
int nghich_modul (int a, int m){
	int x , y ; 
	int g = ocolit_morong(a , m ,&x, &y) ; 
	if( g == 1){
		int results = (x % m + m ) % m ; 
		return results; 
	}
	return -1 ; 
}
// ban chat cua ma hoa va giai ma caser giong nhau nen chi can xay dung mot ham cho ma hoa va giai ma  
string decrypt (string a , int k ){
	string results="" ; 
	char sl , newchar ; 
	int check ; 
	for( int i = 0 ; i< a.length() ; i++){
		if( (a[i] >= 'a' && a[i] <= 'z' ) || a[i] >= 'A' && a[i] <= 'Z' ){
			sl = ( a[i] >= 'a' && a[i] <= 'z') ? 'a' : 'A' ; 
			check = a[i] - sl + k ; 
			if( check < 0 ) {
				check = (check  % 26 + 26 ) % 26 ;
			} 
			newchar = check % 26  + sl ; 
			results += newchar ; 
		}
		else results += a[i] ; 
	}
	return results ; 
}

int generate_key( ){

	srand((int)time(0)); 
	int k = rand() %30  ;
	while( k< 0 || k > 25 ){
		int k = rand() %30  ;
	} 	
	return k ; 
}
int main(){
	string a ; 
	cout << "Nhap chuoi can ma hoa : " ; 
	getline(cin ,a ) ; 
	int k = 20;
	cout << "Khoa k : " <<k <<endl ;
	string banma = decrypt(a,k );  
	cout << "BAN MA : " <<banma <<endl ; 
	string banro = decrypt(banma , -k) ; 
	cout << "BAN RO : " << banro <<endl ; // dau vao la ban ma 
	 
	
}


