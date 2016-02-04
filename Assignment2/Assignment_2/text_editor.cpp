#include <iostream>
#include <string>
#include <stack>
using namespace std;

class info{
public:
	char op;			// Specifies Which operation
	string param;		// specifies the string appended or erased
};

class bin{
public:
	string all;
	int num_undo;
	int num_redo;
	stack<info> pushed;
	stack<info> removed;
	bin();

	string get_all();
	void append(string to_be_appended);
	void erase(int k);
	void get(int k);
	void undo();
	void redo();
};

bin::bin(){
	num_redo = 0;
	num_undo = 0;
}

string bin::get_all(){
	return this->all;
}

void bin::append(string to_be_appended){
	this->all.append(to_be_appended);		// Added to the displaying string
	info dummy;
	dummy.op = 'a';							// made a parameter dummy to add data to the stack
	dummy.param = to_be_appended;
	this->pushed.push(dummy);						// added data to the stack
	num_undo = 0;
	while(!this->removed.empty()){
		this->removed.pop();
	}
	// make zero since undos of no use to redo if append/erase in between
}

void bin::erase(int k){
	int s = all.length();
	info dummy;
	dummy.op = 'e';							// made a parameter dummy to add data to the stack
	dummy.param = all.substr(s-k,k);		// store the substring going to be deleted
	this->all.erase(s-k,k);						// erase from main string
	//cout<< "line 50" << endl;
	this->pushed.push(dummy);
	num_undo = 0;
	while(!this->removed.empty()){
		this->removed.pop();
	}
}

void bin::get(int k){
	cout<< this->all[k] <<endl;
}

void bin::undo(){
	//cout<<"undo"<<endl;
	if(!pushed.empty()){
		// check last operation
		if(this->pushed.top().op == 'a'){
			// pass the length to be erased to erase.
			// we didnt directl use the erase function we defined because it would then push this erase
			// also in the pushed stack.
			int s = all.length();
			this->all.erase(s-this->pushed.top().param.length(), this->pushed.top().param.length());
			//cout<< "line 68" << endl;
			this->removed.push(this->pushed.top());
			this->pushed.pop();
			// whats stored in removed is what was the original operation on which undo was done.
		}
		else if(this->pushed.top().op == 'e'){
			// pass the string to be appended to append.
			// we have stored the deleted string in param while erasing in the erase itself
			// now we append the erased part but do not add it in the pushed stack
			this->all.append(this->pushed.top().param);
			this->removed.push(this->pushed.top());
			this->pushed.pop();
		}

		num_undo ++;
	}
}

void bin::redo(){
	//cout<<"redo_start"<<endl;
	if(num_undo > 0){
		//cout<< "num_undo" <<num_undo << endl;
		// perform redo only if undo num undos greater than redos.
		if(this->removed.top().op == 'e'){
			//if before undo op performed was erase, perform erase on redo.
			// copied whole function except num_undo = 0 so that num_undo = 0 doesnt happen
			// store the same operation we are doing in pushed because on redo
			//its like the operation again happened
			//cout<<"redo:error"<<endl;
			int s = all.length();
			int k = this->removed.top().param.length();
			//cout << s <<" "<< k << endl;
			info dummy;
			dummy.op = 'e';							// made a parameter dummy to add data to the stack
			dummy.param = this->removed.top().param;		// store the substring going to be deleted
			//cout<< "line 108" << endl;
			this->all.erase(s-k,k);					// erase from main string
			//cout << "line 100" << endl;
			this->pushed.push(dummy);
			this->removed.pop();
		}
		else if(this->removed.top().op == 'a'){
			//if before undo op performed was append, perform append on redo.
			// copied whole function except num_undo = 0 so that num_undo = 0 doesnt happen
			// store the same operation we are doing in pushed because on redo
			// its like the operation again happened
			//cout<<"redo:append"<<endl;
			this->all.append(this->removed.top().param);		// Added to the displaying string
			info dummy;
			dummy.op = 'a';							// made a parameter dummy to add data to the stack
			dummy.param = this->removed.top().param;
			this->pushed.push(dummy);
			this->removed.pop();
		}
		num_undo--;						// decrement number of undos
	}
	//cout<<"redo_end"<<endl;

}


int main(){

	bin obj;
	int Q;
	cin >> Q;
	while(Q){
	char op;
	int k;
	string W;
	cin >> op;
	if(op == 'a'){
		cin >> W;
		obj.append(W);
	}
	else if(op == 'e'){
		cin >> k;
		obj.erase(k);
	}
	else if(op == 'g'){
		cin >> k;
		obj.get(k);
	}
	else if(op == 'u'){
		obj.undo();
	}
	else if(op == 'r'){
		obj.redo();
	}
	//cout << obj.get_all()<< endl;
	if(!obj.removed.empty()){
	//cout << obj.removed.top().op <<endl;
	}
	Q--;
	}

}