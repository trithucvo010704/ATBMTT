#include<bits/stdc++.h>
using namespace std ; 
// sinh so nguyen to 
using ll = long long  ;
bool isPrime( int n){
	if(n<2) return false ; 
	else {
		for( int i = 2 ; i<= sqrt(n); i++){
			if( n%i ==0){
				return false ; 
			}
		}
		return true ; 
	}
}
int randomPrime (int &n){
	srand((int)time(0)); 
	n =  1 + rand() % 100   ; 
	while(!isPrime(n)){
		n =  1 + rand() % 100   ; 
	}
	return n ; 
	
}
ll powMod( int a, int b , int n ){
	ll res= 1 ; 
	while(b!= 0 ){
		if( b%2 == 1){
			res*= a ; 
			res%= n ; 
		}
		a *=a ; 
		a %= n ; 
		b/= 2 ; 
	}
	return res ; 
}
int gcd( int a , int b ){
	if( b == 0 ){
		return a ; 
	}
	else return gcd(b ,a%b); 
}
int EculidExtended( int a , int b , int *x , int *y){
	if( b == 0){
		*y= 0 ;
		*x =1 ; 
		return a ; 
	}
	int x1,y1 ; 
	int gcd = EculidExtended(b,a%b,&x1,&y1) ;
	
	*x = y1; 
	*y = x1 -(a/b) * y1 ; 
	return gcd ; 
}

int modInvers( int a, int m){
	int x , y ; 
	int g = EculidExtended(a,m,&x,&y); 	
	if( g== 1){
		int results =  ( x% m + m  ) % m ; 
		return results ; 
	}
	return -1; 
}
int encode( int m, int e , int n){
	int results = powMod(m,e,n) ;
	return results ; 
}
int decode( int c ,int d, int n){
	int results = powMod(c,d,n);
	return results ; 
}

int main(){
	int p1,q1; 
	int q = randomPrime(p1); 
	int p = randomPrime(q1);
	cout << "P= " <<p <<" Q = "<<q <<endl ;
	int n =  p*q ; 
	int phi = (p-1)  * (q-1) ; 
	cout << "N = "<<n <<" Phi = "<<phi <<endl ;
	
	int e = 1+ rand() % (phi -1);
	while( gcd(e,phi) != 1){
		e = 1+ rand() % (phi -1);
	}
	cout << "E = " <<e<<endl ;

	int d = modInvers(e,phi) ;
	cout << "D = "<<d<<endl; 
	
	int m = 1+ rand() % (n-10);
	cout << m<<endl ;
	
	int C = encode(m,e,n);
	cout << C<<endl ;
	
	int M = decode(C,d,n); 
	cout << M<<endl ;
	
	
}


//
//int main(){
//	cout <<randomPrime() <<endl ;
//	cout << powMod(2,3,9) <<endl ;
//	cout << gcd(18,9) <<endl ;
//	cout << modInvers(9,26)<<endl; 
//}