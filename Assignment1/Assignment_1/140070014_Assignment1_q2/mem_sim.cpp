#include <iostream>
#include <list>

using namespace std;
	// need to store: frequency, age and Number in page:
class Frame {

private:

	int page;
	int frequency;
	int age;

public:
	int getpage();

	int getfrequency();

	int getage();

	void setpage(int number);

	void increase_frequency();

	void increase_age();
};

int Frame::getpage() {
	return page;
}

int Frame::getfrequency() {
	return frequency;
}

int Frame::getage() {
	return age;
}

void Frame::setpage(int number) {
	page = number;
	frequency = 1;
	age = 1;
}

void Frame::increase_frequency() {
	frequency++;
}

void Frame::increase_age() {
	age++;
}

/*void printlist(list<Frame*> &i1){
	list<Frame*>::iterator dummy4;

	dummy4 = i1.begin();

	while(dummy4 != i1.end()){
		cout << (*dummy4)->getpage() << " - " ;
		dummy4++;
	}
}*/

int main() {

	int N, P, M;
	int hits = 0;
	int miss = 1;

	cin >> N >> P >> M;
	Frame* first = NULL;
	first = new Frame;

	list<Frame*> memory;

	int min;

	int first_page;

	cin >> first_page;

	first->setpage(first_page);

	memory.push_back(first);

	list<Frame*>::iterator dummy1;

	list<Frame*>::iterator dummy2;

	list<Frame*>::iterator dummy3;

	list<Frame*>::iterator dummy4;

	int minage;

	int num = first_page; // for input

	//cout << num << " " << hits << " " << miss << endl ;

	// while taking the input store in the saved page frames.
	for (int i = 1; i < M; ++i) {

		cin >> num;

		int size = 1;

		dummy1 = memory.begin();

		min = (*dummy1)->getfrequency();

		bool HIT = false;

		while(dummy1 != memory.end()) {
			// if same page occurs again its a HIT
			//cout << num << " " << (*dummy1)->getpage() << " " <<endl;
			if((*dummy1)->getpage() == num) {

				//cout << "equal" <<endl;
				HIT = true;
				hits++;						// increase hits counter
				(*dummy1)->increase_frequency(); // increase frequency of recurring element
			}

			(*dummy1)->increase_age();			// increase age of all elements
			size++;								// increase size counter
			dummy1++;							// go to next element in list
		}
		//cout <<"size" << size << endl;

		// if the page referenced not in memory its a miss
		if(!HIT) {
			//cout << "in miss"<<endl;
			miss++;
			Frame* var = NULL;						// new variable to put into list
			var = new Frame;

			var->setpage(num);

			if(size < P+1) {
				memory.push_back(var);
			} else {
				dummy1 = memory.begin();
				// now checkwhich page has lowest frequency and replace
				dummy3 = dummy1;
				while(dummy1 != memory.end()) {
					if((*dummy1)->getfrequency() == min) {
						if((*dummy1)->getage() > (*dummy3)->getage()) {
							dummy3 = dummy1;
						}
					}

					if((*dummy1)->getfrequency() < min) {

						min = (*dummy1)->getfrequency();			// change min value
						dummy3 = dummy1;
					}

					dummy1++;
				}

				// if same frequency, delete the page which is older

				memory.erase(dummy3);
				memory.push_back(var);
			}
		}
		//cout << num << " " << hits << " " << miss <<endl;
		//cout << endl;
	}

	/*dummy4 = memory.begin();
	while(dummy4 != memory.end()){
		cout << (*dummy4)->getpage() << " - " ;
		dummy4++;
	}*/


	cout << hits << endl;
	cout << miss << endl;
	//cout << endl;
}
