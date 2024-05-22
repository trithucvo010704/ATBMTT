#include<bits/stdc++.h>
using namespace std  ; 
using ll = long long ; 

ll powMod(int a, int b , int m ){
	ll res= 1 ; 
	while(b!= 0 ){
		if( b%2 == 1 ){
			res*= a  ;
			res%= m ; 
		}
		a*= a ; 
		a%= m ; 
		b/= 2 ; 
	}
	return res ; 
}

int ocolit_morong ( int a , int b , int *x , int * y ){
	if( b == 0 ){
		*x = 1 ; 
		*y = 0; 
		return a ;
	}
	int x1, y1 ; 
	int gcd  = ocolit_morong( b , a%b , &x1 , &y1) ; 
	*x =  y1  ; 
	*y = x1 - (a/b) * y1 ; 
	return gcd ; 
	
}
int nghich_modul ( int a , int m ){
	int x ,y  ; 
	int g  = ocolit_morong(a,m,&x,&y) ; 
	if( g == 1 ){
		x  =  (x%m + m ) % m ; 
		return x  ; 
	}
	return -1 ;
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
string giaima ( vector<ll> ban_ma , ll n, ll d){
	string ban_ro="" ; 
	for( ll ch : ban_ma) {
		ll c =  powMod(ch,d,n); 
		ban_ro += (char)c ; 
		
	}
	return ban_ro ; 
}

int gcd(int a, int b){
	if( a< b) return gcd( b,a ) ;
	else if (b == 0){
		return a ; 
	}
	else return ( b, a%b) ; 
} 
int gcd2(int a, int b){
    while (a*b != 0){ 
        if (a > b){
            a %= b; 
        }else{
            b %= a;
        }
    }
    return a + b;
}
vector<int> sang( int limit){
	vector<bool> check(limit+1 , true ) ; 
	vector<int> primes ; 
	for( int i = 2 ; i<= sqrt(limit) ; i++){
		if( check[i]){
			for( int j = i*i ; j< limit ; j+= i){
				check[j] = false ; 
			}
		}
	}
	for( int i = 2 ; i<=limit ; i++){
		if(check[i]){
			primes.push_back(i) ; 
		}
	}
	return primes; 
}
int sinhngto ( vector<int> sang){
	int nto = rand() % sang.size();
	return sang[nto]; 
}
int main(){

//	vector<int > s = sang(100) ; 
//	int p = sinhngto(s) , q = sinhngto(s) ; 
	int p = 17 , q = 19 ; 
	cout << "P " << p <<" Q " <<q <<endl ; 
	ll n = p*q ; 
	ll phi = (p-1) * (q-1) ; 
	ll e  = 2  ; 
	while (e < phi) {
        if (gcd2(e, phi) == 1)
            break;
        else
            e++;
	}; 
	
	int d = nghich_modul(e,phi) ; 
	cout << "Khoa cong khai : " << n <<" "<<e <<endl; 
	cout << "Khoa bi mat :" << n <<" "<<d <<endl ; 
	string dauvao = "THUC"; 
	vector<ll> ban_ma  = mahoa(dauvao , n,e) ; 
	cout << "Ban ma :" ; 
	for( ll a : ban_ma ) cout << a <<" " ; 
	cout << endl ; 
	string ban_ro = giaima(ban_ma ,n,d) ; 
	cout << "Ban ro "<< ban_ro <<endl ;

}
