#include <iostream>
using namespace std;
int main(){
	char board[8][8];
	for(int i=0; i<8; i++)
		for(int j=0; j<8; j++)
			cin>>board[i][j];

	bool rows[8], cols[8];
	for(int i=0; i<8; i++){
		rows[i] = false; cols[i] = false;
	}

	for(int i=0; i<8; i++){
		for(int j=0; j<8; j++){
			if(board[i][j] == 'B'){
				// check row
					bool rowIsBlack = false, colIsBlack = false;
					for(int c = 0; c<8; c++){
						if(board[i][c]=='W'){
							break;
						}else if(c == 7){
							rowIsBlack = true;
						}
					}
				// check col
					for(int r = 0; r<8; r++){
						if(board[r][j]=='W'){
							break;
						}else if(r == 7){
							colIsBlack = true;
						}
					}

				if (rowIsBlack){
					rows[i] = true; // ++i;
				}
				if(colIsBlack){
					cols[j] = true; // ++j;
				}
			}
		}
	}
	int sum = 0;
	bool allColsBlack = false, allRowsBlack = true;
	for(int i=0; i<8; i++){
		if(rows[i])
			sum++;
		if(cols[i])
				sum++;
	}

	for(int i=0; i<8; i++){
		if(!cols[i])
			break;
		else if( i == 7)
			allColsBlack = true;
	}

	for(int i=0; i<8; i++){
		if(!rows[i])
			break;
		else if( i == 7)
			allRowsBlack = true;
	}

	if(allRowsBlack && allColsBlack){
		sum -= 8;
	}

	cout<<sum;
	return 0;
}
