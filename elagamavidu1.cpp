#include<bits/stdc++.h>
using namespace std  ; 
using ll  = long long ; 
ll powmod( ll a, ll b , ll m ){
	ll res = 1 ; 
	while( b!= 0 ){
		if( b%2 == 1){
			res *= a  ;
			res%= m ; 
			
		}
		a*= a ; 
		a%= m ; 
		b /= 2 ; 
		
	}
	return res ; 
}
int gcd( int a, int b ){
	while( a* b != 0 ){
		if( a> b) a %= b ; 
		else b%=  a ; 
	}
	return a+b ; 
}

int ocolit( int a, int b , int *x , int *y ){
	if( b == 0 ){
		*x = 1 ; 
		*y =0 ;
		return a ; 
	}
	int x1, y1 ; 
	int gcd =  ocolit(b , a%b ,  &x1, &y1) ; 
	*x = y1 ; 
	*y  =  x1-  (a/b) * y1 ; 
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

vector<pair<ll,ll>> mahoa( string dauvao, int p ,int a , int y ){
	vector<pair<ll,ll>> banma ; 
	for( char ch : dauvao){
		ll m  =  (ll) ch ; // ep kieu thanh so tu nhien 
		ll k  = rand() % (p-1) +1 ;// chon ngau nhien k ; 
		ll K = powmod(y,k,p) ; 
		ll c1 = powmod(a,k,p) ; 
		ll c2 = (K *m) % p ; 
//		banma.push_back(make_pair(c1,c2)) ; 
		banma.emplace_back(c1,c2) ; 
	}
	return banma ; 
}

string giaima (vector<pair<ll,ll>> banma , ll p ,ll a, ll x){
	string banro = "" ; 
	for( pair<ll,ll> pa : banma){
		ll c1 = pa.first ; 
		ll c2 = pa.second ;
		ll k = powmod(c1,x,p) ; 
		ll k_1 = nghich_modul(k,p) ; 
		ll m = (c2 *k_1) % p ;
		banro += (char)m ;
	}
	return banro ; 
}
int main(){
	int p = 97 ;
	int a= 5 ; 
	int x = 58 ; 
	int y = powmod(a,x,p) ; 
	cout << "Khoa cong khai : " << p << " " << a << " " << y << endl;
    cout << "Khoa Bi Mat  : " << p << " " << a << " " << x << endl;
    string dauvao = "THUC";
	cout << "Ban dau vao : " <<dauvao<<endl ;
	vector<pair<ll,ll>> banma = mahoa(dauvao , p,a,y); 
	cout <<"BAN MA : " ; 
	for ( pair<ll,ll> pa : banma) {
        cout << "(" << pa.first << ", " << pa.second << ") ";
    }
    cout << endl;
    string banro = giaima(banma,p,a,x);     
    cout << "BAN RO : " <<banro; 
}