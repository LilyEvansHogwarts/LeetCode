#include<vector>
#include<string>
#include<iostream>
using namespace std;

bool isValid(vector<vector<char> >& board, string word, int row, int col, vector<vector<int> > flag) {
    if(word == "")
	return true;
    if(row < 0 || row >= board.size()) return false;
    if(col < 0 || col >= board[0].size()) return false;
    if(board[row][col] != word[0] || flag[row][col] == 1) return false;
    flag[row][col] = 1;
    int N = word.size();
    string next = word.substr(1,N -1);
    if(isValid(board,next,row-1,col,flag)) return true;
    if(isValid(board,next,row+1,col,flag)) return true;
    if(isValid(board,next,row,col-1,flag)) return true;
    if(isValid(board,next,row,col+1,flag)) return true; 
    return false;
}

bool exist(vector<vector<char> >& board, string word) {
    if(word == "")
	return true;
    int row = board.size(), col = board[0].size();
    vector<vector<int> > flag(row, vector<int>(col,0));
    for(int i = 0;i < row;i++) {
	for(int j = 0;j < col;j++) {
	    if(board[i][j] == word[0]) {
		if(isValid(board,word,i,j,flag))
		    return true;
		flag[i][j] = 0;
	    }
	}
    }
    return false;
}

int main() {
    string s1 = "ABCCED";
    string s2 = "SEE";
    string s3 = "ABCB";
    vector<vector<char> > board = {{'A','B','C','E'},{'S','F','C','S'},{'A','D','E','E'}};
    cout << s1 << endl;
    cout << exist(board,s1) << endl;
    cout << s2 << endl;
    cout << exist(board,s2) << endl;
    cout << s3 << endl;
    cout << exist(board,s3) << endl;
    string s4 = "abcd";
    vector<vector<char> > board1 = {{'a','b'},{'c','d'}};
    cout << s4 << endl;
    cout << exist(board1,s4) << endl;
    return 0;
}

