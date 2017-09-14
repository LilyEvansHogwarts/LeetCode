#include<iostream>
#include<vector>
#include<string>
using namespace std;

int x, y;
int m, n;

void show_vector(vector<string>& l) {
    for(auto ll:l)
	cout << ll << endl;
    cout << endl;
}


void solve(vector<string>& board, int x, int y) {
    if(x < 0 || y < 0 || x >= m || y >= n) return;
    int l = 0;
    if(board[x][y] == 'M') 
	board[x][y] = 'X';
    else if(board[x][y] == 'E') {
	if(x > 0 && board[x-1][y] == 'M') l++;
	if(x < m - 1 && board[x+1][y] == 'M') l++;
	if(y > 0 && board[x][y-1] == 'M') l++;
	if(y < n - 1 && board[x][y+1] == 'M') l++;
	if(x > 0 && y > 0 && board[x-1][y-1] == 'M') l++;
	if(x > 0 && y < n - 1 && board[x-1][y+1] == 'M') l++;
	if(x < m - 1 && y > 0 && board[x+1][y-1] == 'M') l++;
	if(x < m - 1 && y < n - 1 && board[x+1][y+1] == 'M') l++;
	if(l == 0) {
	    board[x][y] = 'B';
	    cout << x << "\t" << y << "\t" << l << endl;
	    show_vector(board);
	    solve(board, x-1, y);
	    solve(board, x+1, y);
	    solve(board, x, y-1);
	    solve(board, x, y+1);
	    solve(board, x-1, y-1);
	    solve(board, x+1, y-1);
	    solve(board, x+1, y-1);
	    solve(board, x-1, y+1);
	} else {
	    board[x][y] = l + '0';
	    cout << x << "\t" << y << "\t" << l << endl;
	    show_vector(board);
	}
    }
}

vector<string> updateBoard(vector<string>& board, vector<int>& click) {
    if(board.size() == 0 || board[0].size() == 0) return board;
    m = board.size();
    n = board[0].size();
    solve(board, click[0], click[1]);
    return board;
}


int main() {
    vector<string> num = {"EMMEEEEE","EEMEEEEE","EEEEEEEE","EMEEEEEE","EEEEEEEE","EEMEEEEE","EEEEEEEE","EEEEEEEE"};
    vector<int> click = {5,5};
    vector<string> res = updateBoard(num, click);
    show_vector(res);
    return 0;
}
