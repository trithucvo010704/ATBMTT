#include<bits/stdc++.h>
using namespace std  ; 
using ll  = long long ; 
const int M = 26  ; 

int ocolit( int a , int m , int *x , int *y){
	if( m == 0 ){
		*x = 1 ; 
		*y = 0 ; 
		return a ; 
	}
	int x1, y1 ; 
	int gcd = ocolit(m ,a%m , &x1, &y1) ; 
	*x = y1 ; 
	*y = x1 - (a/m) * y1 ; 
	return gcd ; 
}
int nghich_modul ( int a, int m ){
	int x,y ; 
	int g  =  ocolit( a, m ,&x, &y) ;
	if( g== 1){
		x = (x% m +m ) % m ; // de x luon duong 
		return  x ; 
	}
	return -1 ; 
}

string decrypt( string input , int a, int b){
	string results ; 
	int sl ; 
	char newchar ; 
	for( char ch : input){
		if( (ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z')){
			sl = (ch >= 'a' && ch <= 'z') ?'a' :'A'; 
			newchar = (((ch -sl ) * a + b ) % M ) +sl ;
			results += newchar ;   
		}
		else results += ch ; 
	}
	return results ; 
}

string encrypt( string input , int a , int b ){
	string results ; 
	int sl ;  
	char newchar ; 
	int a_1 = nghich_modul(a,M) ; 
	for( char ch : input){
		if( (ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z')){
			sl = (ch >= 'a' && ch <= 'z') ?'a' :'A'; 
			newchar = (a_1 * (ch-sl-b +M )) % M + sl  ;  // dam bao khong am 
			results += newchar ;   
		}
		else results += ch ; 
	}
	return results ; 
}

int main(){
	string input = "THUC VO TRI" ; 
	int a = 17 , b  = 20 ; 
	string ban_ma  = decrypt(input,a,b) ; 
	string ban_ro = encrypt(ban_ma, a,b); 
	cout << "KHOA  a= "<<a <<"b = " <<b << endl ; 
	cout << "Ban ma : " << ban_ma <<endl ;
	cout << "Ban ro :" << ban_ro <<endl ; 
}