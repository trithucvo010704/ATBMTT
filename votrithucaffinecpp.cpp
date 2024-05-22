#include<bits/stdc++.h>
using namespace std ; 

using ll =  long long ; 


int ocolit( int a , int b , int *x , int *y ){
	if( b == 0 ){
		*x  = 1 ; 
		*y = 0 ; 
		return a ; 
	}
	int x1, y1 ; 
	int gcd = ocolit( b , a%b ,&x1 , &y1) ; 
	*x = y1; 
	*y = x1 -(a/b)*y1; 
	return gcd ; 
}
int nghich_dao ( int a, int b ){
	int x , y ; 
	int g  =  ocolit(a,b,&x,&y) ; 
	if( g == 1){
		x = (x% b +b) % b ; 
		return x ; 
	}
	return -1; 
}

string mahoa( string banro , int a , int b ){
	int sl ; 
	char newchar ; 
	string kq ; 
	
	for( char ch : banro){
		if((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z')){
			sl = (ch >= 'a' && ch <= 'z') ? 'a' :'A' ; 
			newchar = (a*(ch-sl) +b ) %26 +sl ;
			kq += newchar ;  
		}
		else {
			kq += ch ; 
		}
	}
	return kq ; 
}
string giaima( string banma , int a, int b ){
	int sl ; 
	char newchar ; 
	string kq ; 
	int a_1  = nghich_dao(a,26) ; 
	for( char ch : banma){
		if((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z')){
			sl = (ch >= 'a' && ch <= 'z') ? 'a' :'A' ;
			newchar = (a_1 * ( ch-sl-b +26)) %26 +sl ;  
			kq += newchar ;  
		}
		else {
			kq += ch ; 
		}
	}
	return kq ; 
}

int generate(){
	int n = rand() %26 ; 
	return n ; 
}
int main(){
	int a  =generate() ; 
	int b = generate() ; 
	cout << "Khoa a " <<a <<" b " <<b <<endl  ;
	string dauvao ; 
	cout <<"Nhap ban ro : " ; 
	getline(cin ,dauvao) ; 
	cout <<"Ban dau vao : " << dauvao <<endl ;
	string banma = mahoa(dauvao,a,b) ; 
	string banro  = giaima(banma, a,b) ; 
	cout << "BAN MA : " << banma <<endl ; 
	cout << "BAN RO : " <<banro <<endl ; 
	
}