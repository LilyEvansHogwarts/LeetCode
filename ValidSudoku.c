#include<iostream>
#include<vector>
using namespace std;

bool isValidSudoku(vector<vector<char> >& board) {
    const int N = 9;
    if(board.size() != N || board[0].size() != N)
	return false;
    int row, col[N] = {0}, box[N] = {0};
    for(int i = 0;i < N;i++) {
	row = 0;
	for(int j = 0;j < N;j++) {
	    if(board[i][j] == '.')
		continue;
	    int bit = 1 << (board[i][j] - '1');
	    int num = i / 3 * 3 + j / 3;
	    if(row & bit || col[j] & bit || box[num] & bit)
		return false;
	    row |= bit;
	    col[j] |= bit;
	    box[num] |= bit;
	}
    }
    return true;
}

int main() {
    vector<vector<char> > board = {{'5','3','.','.','7','.','.','.','.'},{'6','.','.','1','9','5','.','.','.'},{'.','9','8','.','.','.','.','6','.'},{'8','.','.','.','6','.','.','.','3'},{'4','.','.','8','.','3','.','.','1'},{'7','.','.','.','2','.','.','.','6'},{'.','6','.','.','.','.','2','8','.'},{'.','.','.','4','1','9','.','.','5'},{'.','.','.','.','8','.','.','7','9'}};
    cout << isValidSudoku(board) << endl;
    return 0;
}
