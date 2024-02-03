#include <iostream>
using namespace std;

void wincheck(string board[], int &posmoves){
	//CROSS WIN SIDE
	if(board[0]=="X" & board[1]=="X" & board[2]=="X"){
		posmoves=0;
		cout << "Cross Wins!" << endl;
	}
	if(board[3]=="X" & board[4]=="X" & board[5]=="X"){
		posmoves=0;
		cout << "Cross Wins!" << endl;
	}
	if(board[6]=="X" & board[7]=="X" & board[8]=="X"){
		posmoves=0;
		cout << "Cross Wins!" << endl;
	}
	if(board[0]=="X" & board[3]=="X" & board[6]=="X"){
		posmoves=0;
		cout << "Cross Wins!" << endl;
	}
	if(board[1]=="X" & board[4]=="X" & board[7]=="X"){
		posmoves=0;
		cout << "Cross Wins!" << endl;
	}
	if(board[2]=="X" & board[5]=="X" & board[8]=="X"){
		posmoves=0;
		cout << "Cross Wins!" << endl;
	}
	if(board[0]=="X" & board[4]=="X" & board[8]=="X"){
		posmoves=0;
		cout << "Cross Wins!" << endl;
	}
	if(board[2]=="X" & board[4]=="X" & board[6]=="X"){
		posmoves=0;
		cout << "Cross Wins!" << endl;
	}
	//CIRCLE WIN SIDE
	if(board[0]=="O" & board[1]=="O" & board[2]=="O"){
		posmoves=0;
		cout << "Circle Wins!" << endl;
	}
	if(board[3]=="O" & board[4]=="O" & board[5]=="O"){
		posmoves=0;
		cout << "Circle Wins!" << endl;
	}
	if(board[6]=="O" & board[7]=="O" & board[8]=="O"){
		posmoves=0;
		cout << "Circle Wins!" << endl;
	}
	if(board[0]=="O" & board[3]=="O" & board[6]=="O"){
		posmoves=0;
		cout << "Circle Wins!" << endl;
	}
	if(board[1]=="O" & board[4]=="O" & board[7]=="O"){
		posmoves=0;
		cout << "Circle Wins!" << endl;
	}
	if(board[2]=="O" & board[5]=="O" & board[8]=="O"){
		posmoves=0;
		cout << "Circle Wins!" << endl;
	}
	if(board[0]=="O" & board[4]=="O" & board[8]=="O"){
		posmoves=0;
		cout << "Circle Wins!" << endl;
	}
	if(board[2]=="O" & board[4]=="O" & board[6]=="O"){
		posmoves=0;
		cout << "Circle Wins!" << endl;
	}
}

void clrscreen(){ //clear the screen oh function. halleluja
	cout << "\033[2J\033[1;1H";
}

void movedraw(string board[], string move, int usrc){
	if(usrc==0){
		//CROSS MOVE 
		if(move=="a1") board[0]="X";
			if(move=="a2") board[1]="X";
				if(move=="a3") board[2]="X";
		
		if(move=="b1") board[3]="X";
			if(move=="b2") board[4]="X";
				if(move=="b3") board[5]="X";

		if(move=="c1") board[6]="X";
			if(move=="c2") board[7]="X";
				if(move=="c3") board[8]="X";
			}
	else{
		//CIRCLE MOVE 
		if(move=="a1") board[0]="O";
			if(move=="a2") board[1]="O";
				if(move=="a3") board[2]="O";
		
		if(move=="b1") board[3]="O";
			if(move=="b2") board[4]="O";
				if(move=="b3") board[5]="O";

		if(move=="c1") board[6]="O";
			if(move=="c2") board[7]="O";
				if(move=="c3") board[8]="O";
			}
}

void tabledraw(int usrc, string board[], int posmoves){
	clrscreen();
	while(true){
		string move;
	  	cout << "a " << board[0] << "     " << board[1] << "     " << board[2] << endl << endl; //https://www.fileformat.info/info/unicode/category/So/list.htm
	  	cout << "b " << board[3] << "     " << board[4] << "     " << board[5] << endl << endl;
	  	cout << "c " << board[6] << "     " << board[7] << "     " << board[8] << endl << "  1     2     3" << endl;
	    if(posmoves==0) break;
	    cout << endl << "Do your move (ex. a1, b3)" << endl;
	    if(usrc==0){
	    	cout << "Cross's turn!" << endl;
	    	cin >> move;
	  		movedraw(board, move, usrc);
	  		clrscreen();
	  		usrc=1;
	  		posmoves--;
	  		wincheck(board, posmoves);
	    }
	    else{
	    	cout << "Circle's turn!" << endl;
	    	cin >> move;
	  		movedraw(board, move, usrc);
	  		clrscreen();
	  		usrc=0;
	  		posmoves--;
	  		wincheck(board, posmoves);
	    }
  }
}

int main(){
	string board[9] {"\u25A1","\u25A1","\u25A1","\u25A1","\u25A1","\u25A1","\u25A1","\u25A1","\u25A1"};
	cout << "Welcome to CrossCircle!" << endl << "Please, select a shape" << endl;
	int usrc=0, posmoves=9;
	clrscreen();
	tabledraw(usrc, board, posmoves);
	cout << "Game ended!" << endl;
}