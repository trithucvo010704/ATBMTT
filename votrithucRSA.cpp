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
int gcd( int a , int b){
	while( a* b !=0 ){
		if( a > b ){
			a %= b ; 
		}	
		else b %= a ;
				
	}
	return a+b ; 
}
ll powMod( ll a , ll b  , ll m){
	ll res = 1 ; 
	while( b!= 0 ){
		if(b %2 == 0){
			res *=a ; 
			res %= m ; 
		}
		a*= a ; 
		a%= m ; 
		b/= 2 ; 
	}
	return res ; 
}

vector<ll> mahoa( string banro , int n  , int e){
	vector<ll> banma ; 
	for( char ch : banro){
		if((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z')){
			ll m = (ll)ch ; 
			ll c = powMod(m,e,n) ; 
			banma.push_back(c) ;
		}
		else {
			ll m = 1 ;
			banma.push_back(m) ;
		}
	}
	return banma ; 
}

string giaima( vector<ll> banma , int n , int d){
	string kq="" ; 
	for( ll ch : banma ){
		if( ch != 1){
			ll m = powMod(ch,d,n) ; 
			kq += (char)m ;
		}
		else kq +=" "; 
		 
	}
	return kq ; 
}

vector<int> sang ( int gioihan){
	vector<bool> check ( gioihan+1 , true ) ; 
	vector<int> primes ; 
	for( int i = 2;  i<= sqrt(gioihan) ; i++){
		if(check[i]){
			for( int j = i*i; j<= gioihan ; j+= i ){
				check[j] = false ; 
			}
		}
		
	}
	for( int i = 2 ;  i<= gioihan ; i++){
		if(check[i]){
			primes.push_back(i) ; 
		}
	}
	return primes ; 
}
int main(){
	vector<int> ngto = sang(1000) ;
	int c = rand() % ngto.size() ; 

	int p = ngto[c] ; 
	c = rand() % ngto.size() ; 
	int q = ngto[c] ;
//	int p = 17 , q = 19 ; 
	int n = (p*q) ; 
	int phi = (p-1) * (q-1) ; 
	int e = 2 ; 
	while( e <phi ){
		if( gcd(e,phi) ==1){
			break ; 
		}
		++e; 
	} 
	int d = nghich_dao(e,phi) ; 
	cout <<"Khoa cong khai: " <<n <<" "<< e <<endl ;  
	cout <<"Khoa bi mat : " <<n <<" "<< d <<endl ;  
	string dauvao ; 
	cout <<"Nhap ban ro : " ; 
	getline(cin ,dauvao) ; 
	cout <<"Ban dau vao : " << dauvao <<endl ;
	
	vector<ll> banma= mahoa(dauvao,n,e) ; 
	cout <<"BAN MA: " ; 
	for( ll ch : banma){
		cout << ch <<" "; 
	}
	cout <<endl ; 
	string banro = giaima(banma , n,d) ; 
	cout <<"BAN RO : " <<banro <<endl ;

}