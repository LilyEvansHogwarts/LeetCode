#include<iostream>
#include<vector>
using namespace std;

bool isValid(vector<vector<char> >& board, int row, int col) {
    int r = 0,c = 0,box = 0;
    int bit;
    for(int i = 0;i < 9;i++) {
	if(i != col && board[row][i] != '.') {
	    bit = 1 << (board[row][i] - '1');
	    r |= bit;
	}
	if(i != row && board[i][col] != '.') {
	    bit = 1 << (board[i][col] - '1');
	    c |= bit;
	}
	int a = row/3*3 + i/3;
	int b = col/3*3 + i%3;
	if(!(a == row && b == col) && board[a][b] != '.') {
	    bit = 1 << (board[a][b] - '1');
	    box |= bit;
	}
    }
    int key = 1 << (board[row][col] - '1');
    if(r & key || c & key || box & key)
	return false;
    else
	return true;
}

bool fill(vector<vector<char> >& board, int row, int col) {
    if(col == 9)
	return fill(board,row + 1,0);
    if(row == 9)
	return true;
    if(board[row][col] == '.') {
	for(int i = 0;i < 9;i++) {
	    board[row][col] = i + '1';
	    if(isValid(board,row,col) && fill(board,row,col+1))
		return true;
	    else 
		board[row][col] = '.';
	}
    } else {
	return fill(board,row,col+1);
    }
    return false;
}

void solveSudoku(vector<vector<char> >& board) {
    fill(board,0,0);
}


void showSudoku(vector<vector<char> >& board) {
    for(int i = 0;i < 9;i++) {
	for(int j = 0;j < 9;j++) {
	    cout << board[i][j] << "\t";
	}
	cout << endl;
    }
}

int main() {
    vector<vector<char> > board1 = {{'5','3','.','.','7','.','.','.','.'},{'6','.','.','1','9','5','.','.','.'},{'.','9','8','.','.','.','.','6','.'},{'8','.','.','.','6','.','.','.','3'},{'4','.','.','8','.','3','.','.','1'},{'7','.','.','.','2','.','.','.','6'},{'.','6','.','.','.','.','2','8','.'},{'.','.','.','4','1','9','.','.','5'},{'.','.','.','.','8','.','.','7','9'}};
    solveSudoku(board1);
    showSudoku(board1);


    cout << endl;
    vector<vector<char> > board2 = {{'.','.','9','7','4','8','.','.','.'},{'7','.','.','.','.','.','.','.','.'},{'.','2','.','1','.','9','.','.','.'},{'.','.','7','.','.','.','2','4','.'},{'.','6','4','.','1','.','5','9','.'},{'.','9','8','.','.','.','3','.','.'},{'.','.','.','8','.','3','.','2','.'},{'.','.','.','.','.','.','.','.','6'},{'.','.','.','2','7','5','9','.','.'}};
    solveSudoku(board2);
    showSudoku(board2);
    return 0;
}


