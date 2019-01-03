#include<bits/stdc++.h>

using namespace std;
#define ok1 printf("ok1\n");
#define ok2 printf("ok2\n");
#define M 1000000000000000000LL
#define rep(i,n) for(int i=0;i<n;i++)
#define REP(i,s,n) for(int i=(s);i<(n);i++)
#define repr(i,n) for(int i=n-1;i>=0;i--)
#define REPR(i,s,n) for(int i=(s);i>=(n);(i)--)
#define all(a) (a).begin(),(a).end()
#define reall(a) (a).rbegin(),(a).rend()
#define pb push_back
#define pf push_front

typedef vector<int> vi;
typedef long long ll;
typedef vector<ll> vll;
typedef vector<vll> vvll;
#define WHITE 1
#define BLACK -1
#define Bordx 8
#define Bordy 8
vvll ban,BeforeBan;
ll turn = 1,color;

void print(vvll ban){
	//cout << "　";
	rep(i,8) cout << "　" << i + 1;
	cout << endl;
	rep(i,Bordx) {
		rep(j,Bordy){
			if(j == 0) cout << (char)('a' + i) << "|";
			if(ban[i][j] == WHITE) cout << "●|";
			else if(ban[i][j] ==BLACK) cout << "〇|";
			else cout << "＿|";
		}
		cout << endl;
	}
}
void setBan(){
	ban = vvll(Bordx, vll(Bordy,0));
	ban[3][3] = WHITE;
	ban[4][4] = WHITE;
	ban[3][4] = BLACK;
	ban[4][3] = BLACK;
	print(ban);
}

bool putRight(ll x, ll y, ll color){ //置いたマスより右側に裏返せる駒があるか判定
	bool flag = false;
	ll notColor;
	//相手の色を確認
	if(color == WHITE) notColor = BLACK;
	else notColor = WHITE;

	//裏返せるか確認
	while(y < Bordx - 1) {
		y++;
		if(ban[x][y] == 0) return false;
		else if(ban[x][y] == notColor){
			if(y == (Bordx - 1)) return false;
			flag = true;
			continue;
		}
		else if(flag) return true;
		else return false;
	}
	return false;
}

bool putLeft(ll x, ll y, ll color){ //置いたマスより左側に裏返せる駒があるか判定
	bool flag = false;
	ll notColor;
	//相手の色を確認
	if(color == WHITE) notColor = BLACK;
	else notColor = WHITE;

	//裏返せるか確認
	while(y > 0) {
		y--;
		if(ban[x][y] == 0) return false;
		else if(ban[x][y] == notColor){
			if(y == 0) return false;
			flag = true;
			continue;
		}
		else if(flag) return true;
		else return false;
	}
	return false;
}

bool putUp(ll x, ll y, ll color){ //置いたマスより上側に裏返せる駒があるか判定
	bool flag = false;
	ll notColor;
	//相手の色を確認
	if(color == WHITE) notColor = BLACK;
	else notColor = WHITE;
	//cout << "notColor is:" << notColor << endl;
	//裏返せるか確認
	while(x > 0) {
		x--;
		//cout << "flag is:" << flag << endl;
		if(ban[x][y] == 0) return false;
		else if(ban[x][y] == notColor){
			if(x == 0) return false;
			flag = true;
			continue;
		}
		else if(flag) return true;
		else return false;
	}
	return false;
}

bool putDown(ll x, ll y, ll color){ //置いたマスより下側に裏返せる駒があるか判定
	bool flag = false;
	ll notColor;
	//相手の色を確認
	if(color == WHITE) notColor = BLACK;
	else notColor = WHITE;

	//裏返せるか確認
	while(x < Bordy - 1) {
		x++;
		if(ban[x][y] == 0) return false;
		else if(ban[x][y] == notColor){
			if(x == (Bordy - 1)) return false;
			flag = true;
			continue;
		}
		else if(flag) return true;
		else return false;
	}
	return false;
}

bool putRU(ll x, ll y, ll color){ //置いたマスより右上側に裏返せる駒があるか判定
	bool flag = false;
	ll notColor;
	//相手の色を確認
	if(color == WHITE) notColor = BLACK;
	else notColor = WHITE;

	//裏返せるか確認
	while(x > 0 && y < Bordx - 1) {
		y++;
		x--;
		if(ban[x][y] == 0) return false;
		else if(ban[x][y] == notColor){
			if(y == (Bordx - 1) || x == 0) return false;
			flag = true;
			continue;
		}
		else if(flag) return true;
		else return false;
	}
	return false;
}

bool putRD(ll x, ll y, ll color){ //置いたマスより上側に裏返せる駒があるか判定
	bool flag = false;
	ll notColor;
	//相手の色を確認
	if(color == WHITE) notColor = BLACK;
	else notColor = WHITE;

	//裏返せるか確認
	while(x < Bordy - 1 && y < Bordx - 1) {
		y++;
		x++;
		if(ban[x][y] == 0) return false;
		else if(ban[x][y] == notColor){
			if(y == (Bordx - 1) || x == (Bordy - 1)) return false;
			flag = true;
			continue;
		}
		else if(flag) return true;
		else return false;
	}
	return false;
}

bool putLU(ll x, ll y, ll color){ //置いたマスより上側に裏返せる駒があるか判定
	bool flag = false;
	ll notColor;
	//相手の色を確認
	if(color == WHITE) notColor = BLACK;
	else notColor = WHITE;

	//裏返せるか確認
	while(x > 0 && y > 0) {
		y--;
		x--;
		if(ban[x][y] == 0) return false;
		else if(ban[x][y] == notColor){
			if(y == 0 || x == 0) return false;
			flag = true;
			continue;
		}
		else if(flag) return true;
		else return false;
	}
	return false;
}

bool putLD(ll x, ll y, ll color){ //置いたマスより上側に裏返せる駒があるか判定
	bool flag = false;
	ll notColor;
	//相手の色を確認
	if(color == WHITE) notColor = BLACK;
	else notColor = WHITE;

	//裏返せるか確認
	while(x < Bordy - 1 && y > 0) {
		y--;
		x++;
		//cout << x << " " << y << endl;
		if(ban[x][y] == 0) return false;
		else if(ban[x][y] == notColor){
			if(y == 0 || x == (Bordy - 1)) return false;
			flag = true;
			continue;
		}
		else if(flag) return true;
		else return false;
	}
	return false;
}

bool canPut(ll x, ll y, ll color){
	bool flag = false;
	if(x < 0 || x > Bordx - 1 || y < 0 || y > Bordy - 1) return false; 
	if(ban[x][y] != 0) return false;
	//cout << flag << endl;
	if(putRight(x,y,color)) flag = true;
	//cout << 1 << endl;
	//cout << flag << endl;
	if(putLeft(x,y,color))  flag = true;
	//cout << 2 << endl;
	//cout << flag << endl;
	if(putUp(x,y,color))    flag = true;
	//cout << 3 << endl;
	//cout << flag << endl;
	if(putDown(x,y,color))  flag = true;
	//cout << 4 << endl;
	//cout << flag << endl;
	if(putRU(x,y,color))    flag = true;
	//cout << 5 << endl;
	//cout << flag << endl;
	if(putRD(x,y,color))    flag = true;
	//cout << 6 << endl;
	//cout << flag << endl;
	if(putLU(x,y,color))    flag = true;
	//cout << 7 << endl;
	//cout << flag << endl;
	if(putLD(x,y,color))    flag = true;
	//cout << 8 << endl;
	//cout << flag << endl;
	if(flag) return true;
	else return false;
}

void flipRight(ll x, ll y, ll color){  //右側を裏返す
	ll notColor;
	//相手の色を確認
	if(color == WHITE) notColor = BLACK;
	else notColor = WHITE;

	//裏返せるか確認
	while(y < Bordx - 1) {
		y++;
		if(ban[x][y] == notColor){
			ban[x][y] = color;
		}
		else break;
	}
}

void flipLeft(ll x, ll y, ll color){ //左側を裏返す
	ll notColor;
	//相手の色を確認
	if(color == WHITE) notColor = BLACK;
	else notColor = WHITE;

	while(y > 0) {
		y--;
		if(ban[x][y] == notColor){
			ban[x][y] = color;
		}
		else break;
	}
}

void flipUp(ll x, ll y, ll color){ //上側を裏返す
	ll notColor;
	//相手の色を確認
	if(color == WHITE) notColor = BLACK;
	else notColor = WHITE;

	//裏返せるか確認
	while(x > 0) {
		x--;
		if(ban[x][y] == notColor){
			ban[x][y] = color;
			continue;
		}
		else break;
	}
}

void flipDown(ll x, ll y, ll color){ //下側を裏返す
	ll notColor;
	//相手の色を確認
	if(color == WHITE) notColor = BLACK;
	else notColor = WHITE;

	//裏返せるか確認
	while(x < Bordy - 1) {
		x++;
		if(ban[x][y] == notColor){
			ban[x][y] = color;
		}
		else break;
	}
}

void flipRU(ll x, ll y, ll color){ //右上側を裏返す
	ll notColor;
	//相手の色を確認
	if(color == WHITE) notColor = BLACK;
	else notColor = WHITE;

	//裏返せるか確認
	while(x > 0 && y < Bordx - 1) {
		y++;
		x--;
		if(ban[x][y] == notColor){
			ban[x][y] = color;
		}
		else break;
	}
}

void flipRD(ll x, ll y, ll color){ //右下側を裏返す
	ll notColor;
	//相手の色を確認
	if(color == WHITE) notColor = BLACK;
	else notColor = WHITE;

	//裏返せるか確認
	while(x < Bordy - 1 && y < Bordx - 1) {
		y++;
		x++;
		 if(ban[x][y] == notColor){
			ban[x][y] = color;
		}
		else break;
	}
}

void flipLU(ll x, ll y, ll color){ //左上側を裏返す
	ll notColor;
	//相手の色を確認
	if(color == WHITE) notColor = BLACK;
	else notColor = WHITE;

	//裏返せるか確認
	while(x > 0 && y > 0) {
		x--;
		y--;
		if(ban[x][y] == notColor){
			ban[x][y] = color;
		}
		else break;
	}
}

void flipLD(ll x, ll y, ll color){ //左下側を裏返す
	ll notColor;
	//相手の色を確認
	if(color == WHITE) notColor = BLACK;
	else notColor = WHITE;

	//裏返せるか確認
	while(x < Bordy - 1 && y > 0) {
		y--;
		x++;
		if(ban[x][y] == notColor){
			ban[x][y] = color;
			continue;
		}
		else break;
	}
}

void calc(ll x, ll y, ll color){
	ban[x][y] = color;
	if(putRight(x,y,color)) {
		flipRight(x,y,color);
	}
	if(putLeft(x,y,color))  {
		flipLeft(x,y,color);
	}
	if(putUp(x,y,color))    {
		flipUp(x,y,color);
	}
	if(putDown(x,y,color))  {
		flipDown(x,y,color);
	}
	if(putRU(x,y,color))    {
		flipRU(x,y,color);
	}
	if(putRD(x,y,color))    {
		flipRD(x,y,color);
	}
	if(putLU(x,y,color))    {
		flipLU(x,y,color);
	}
	if(putLD(x,y,color))    {
		flipLD(x,y,color);
	}
}

bool gameFinish(){
	bool flag = false;
	rep(i,Bordx){
		rep(j,Bordy){
			//cout << "moving! " << i << " " << j << endl;
			if(canPut(i,j,color)) {
				break;
				flag = true;
			}
		}
	}
	return flag;
}

void game(){
	ll x=0,y=0;
	string cx="";
	cout << "turn "<< turn;
	if(turn % 2) cout << " BLACK(〇)'s turn\n\n", color = BLACK;
	else cout << " WHITE(●)'s turn\n\n", color = WHITE;
	cout << "imput x(a～h) y(0～8))\n";
	cout << "if you want to undo, type 'undo'\n";
	cin >> cx;
	if(cx == "undo"){
		if(turn > 1) turn--;
		ban = BeforeBan;
		print(ban);
	}
	else{
		cin >> y;
		x = cx[0] - 'a';
		y--;
		//abs(x),abs(y);
		//cout << x << " " << y << endl;
		//cout << "moving 0 \n";
		if(!canPut(x,y,color)) {
			cout << "\n!!!!!!!  ERROR! Can't put it right here  !!!!!!!!\n";
		}
		else {
			//cout << "moving 1 \n";
			calc(x,y,color);
			//cout << "moving 2 \n";
			turn++;
		}
		
		print(ban);
	}
}

int main(){
	//ゲーム初期化
    setBan();
	BeforeBan = ban;
	while(true){
		game();
		BeforeBan = ban;
		if(gameFinish()) break;
	}
	return 0;
}  