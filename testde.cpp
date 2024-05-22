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

string mahoa( string banro , int a , int b){
	char sl ;
	char newchar ; 
	string results ; 
	for( char ch : banro){
		if(( ch >= 'a' && ch <= 'z' )|| (ch >= 'A' && ch<= 'Z') ){
			sl = (ch >= 'a' && ch <= 'z') ?'a' : 'A' ; 
			newchar = (a*(ch -sl) + b )%26 +sl;
			results+= newchar ;   
		}
		else results += ch ; 
	}
	return results ; 
}
string giaima( string banma , int a , int b){
	char sl ;
	char newchar ; 
	int a_1 = nghich_modul(a,26) ; 
	string results ; 
	for( char ch : banma){
		if(( ch >= 'a' && ch <= 'z' )|| (ch >= 'A' && ch<= 'Z') ){
			sl = (ch >= 'a' && ch <= 'z') ?'a' : 'A' ; 
			newchar  = (a_1 * (ch-sl-b+26)) % 26  +sl ; 
			results += newchar ;   
		}
		else results += ch ; 
	}
	return results; 
}

int main(){
	string dauvao = "TRUONG DAI HOC CONG NGHIEP HA NOI " ; 
	int a = 5 , b = 6 ;
	string banma = mahoa(dauvao ,a ,b) ; 
	string banro = giaima(banma, a, b) ;  
	cout << "Ban ma :" <<banma<<endl ;
	cout << "ban ro :" << banro << endl ; 
}