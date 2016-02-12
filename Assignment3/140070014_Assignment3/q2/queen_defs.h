#include <iostream>

using namespace std;

struct Vars {
	int count;
	/** DO NOT CHANGE ANYTHING ABOVE THIS LINE **/

	/** Add any global variables you may want below this line **/
	int placed;
	int n;
	int power;
	bool first_iteration;
	/** Define this function which takes in the N to solve for. This is called
	 * before calling countQueens from main **/
	void setup(int N) {
		count = 0;
		n = N;
		power = 1;
		for (int i = 0; i < n; ++i)
		{
			power = power * 2;
		}
	}

};

extern Vars glob_vars;

inline bool solved(int col, int ld, int rd) {
	// Must return true iff queens have been placed on each row.
	if(col == glob_vars.power - 1 ) {
		////cout << "count ++ \n";
		return true;
	}
	return false;
}

inline int getValidPositions(int col, int ld, int rd) {
	// Must return a bit vector with 1s in positions where it is
	// safe to place a queen
	int notsafe;
	notsafe = col | ld | rd;
	//cout << "col danger" << col << endl;
	//cout << "getValidPositions: " << (notsafe ^ (glob_vars.power-1)) << endl;
	//glob_vars.placed--;
	return notsafe ^ (glob_vars.power - 1);
}

inline bool positionsAvailable(int valid_positions) {
	// Must return true iff there are safe positions to place
	// queens
	////cout << "positions Available1 : " << valid_positions << endl;
	if(valid_positions != 0) {
		//cout << "positions Available2 : " << valid_positions << endl;
		return true;
	}
	return false;
}

inline int chooseOnePosition(int valid_positions) {
	// Must return an int with exactly one bit set as 1.
	// This bit must be chosen from the positions where
	// validPositions is also 1.
	int j = 1;
	while(!(valid_positions % 2)) {
		valid_positions = valid_positions/2;
		j*= 2;
	}
	//cout << "ChooseOnePosition: " << j << endl;
	return j;
}

inline int removeChosenPosition(int valid_positions, int cur_posn) {
	// Must return a bit pattern with one less 1, and this one is
	// removed from the position where cur_posn is 1.
	//cout << "removeChosenPosition: " << valid_positions - cur_posn << endl;
	return valid_positions - cur_posn;
}

inline int calcNewColDanger(int col, int cur_posn) {
	// Must return a bit pattern with the updated
	// column dangers due to placing a queen on cur_posn
	//cout << "calcNewColDanger : " << (col | cur_posn) << endl;
	return col | cur_posn;
}

inline int calcNewLdDanger(int ld, int cur_posn) {
	// Must return a bit pattern with the updated
	// bottom left diagonal dangers due to placing a queen
	// on cur_posn
	//cout << "calcNewLdDanger: " << ((ld | cur_posn)>>1) << endl;
	return (ld | cur_posn)>>1;
}

inline int calcNewRdDanger(int rd, int cur_posn) {
	// Must return a bit pattern with the updated
	// bottom right diagonal dangers due to placing a queen
	// on cur_posn
	//cout << "calcNewRdDanger: " << (((rd | cur_posn)<<1) & (glob_vars.power - 1)) << endl;
	return ((rd | cur_posn)<<1) & (glob_vars.power - 1) ;
}
