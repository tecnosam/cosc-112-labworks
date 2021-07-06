#include <iostream>
#include <vector>
#include <string>
using namespace std;

/* the project is intended to store the scores of student in a sorted manner
 * a linked list would be used in implementation
 * but imma do something different
 * I'll sort as the data is inserted, increasing the time complexity of insertion to O(n)
 * But then, sorting time complexity would be O(n)
 * let's see how this goes
 */

typedef struct Subject {
	int score;
	string subject_name;
	Subject *next;
} Subject;

class Student {
	private:
		// students name and level
		string name;
		int level;

		// linked list of subjects
		Subject *subjects = NULL;
		int len_subjects = 0;

		// this function searches the list to find the correct spot to place a new subject
		// such that subjects[i-1] < subjects[i] < subjects[i+1]
		// returns subjects[i-1]
		Subject * _find_spot( int score );

		Subject * _search( int id );
	public:
		Student( string n, int lvl ) {
			name = n;
			level = lvl;
		}

		string getName(  ) {
			return name;
		}

		void add_subject( string subject_name, int score );
		void print_subjects( );

};

Subject * Student::_find_spot( int score ) {

	if ( subjects == NULL ) {
		return subjects;
	}
       	
	Subject* spot = subjects;

	while ( spot != NULL ) {
		if ( score < spot->score ) {
			if ( spot->next == NULL ) {
				

				return spot;

			} else if ( score > spot->next->score ) {
				
				return spot;
			
			}
		}
		spot = spot->next;
	}

	return NULL;
}

void Student::add_subject( string subject_name, int score ) {
	Subject *sub = new Subject;

	if (sub != NULL) {

		sub->subject_name = subject_name;
		sub->score = score;

		Subject *spot = _find_spot( score );


		if ( spot == NULL ) {

			sub->next = subjects;
			subjects = sub;

		} else {

			sub->next = spot->next;
			spot->next = sub;
	
		}

		cout<<"Initiated new Subject Object"<<endl;

		//subjects = sub;
		len_subjects++;


	} else {
		// user is out of memory
		cerr<<"You've run out of memory!!!"<<endl;
	}
}

void Student::print_subjects(  ) {
	Subject *temp = subjects;
	while ( temp != NULL ) {
		cout<<"subject: "<<temp->subject_name<<" \nScore: "<<temp->score<<endl;
		temp = temp->next;
	}
	delete temp;
}

void print_students( vector<Student> studs ) {
	for ( int i = 0; i < studs.size(); i++ ) {
		cout<<i+1<<" "<<studs[i].getName()<<endl;
	}
}

void displayMenu();
int resolve( int id );

int main() {
	static vector<Student> students;
	char option;
	string subject_name, name;
	int score, lvl, id;
	do {
		cout<<endl;
		displayMenu();
		cout<<endl<<"Select an option: ";
		cin>>option;
		cout<<endl;
		
		switch (option) {
			case 'A':
				// add student
				cout<<"What is the students name: ";
			
				cin.ignore();
				getline(cin, name);

				cout<<"What level is the student in: ";
				cin>>lvl;

				students.push_back( Student( name, lvl ) );

				cout<<"Successfully added 1 student!"<<endl;
				break;
			case 'B':
				// print all students
				print_students( students );
				break;
			case 'C':
				// add subject score to student
				cout<<"ID of the student: ";
				cin>>id;

				cout<<"What subject: ";
				cin.ignore();
				getline( cin, subject_name );

				cout<<"What was the score in "<<subject_name<<": ";
				cin>>score;
				
				students[ resolve(id) ].add_subject( subject_name, score );

				break;
			case 'D':
				// print scores of a student

				cout<<"ID of the student: ";
				cin>>id;

				cout<<endl<<"Student: "<<students[ resolve(id) ].getName()<<endl<<endl;

				students[ resolve(id) ].print_subjects();

				break;
			case 'Q':
				// quit the program
				cout<<"Bye bye"<<endl;
				break;
			default:
				cout<<"Command not found. Please try again"<<endl;
		}

	} while (option != 'Q');

	/*Student stud( "Samuel Abolo", 100 );

	students.push_back( stud );

	print_students( students );

	students[0].add_subject( "Mathematics", 96 );
	students[0].add_subject( "Physics", 95 );
	students[0].add_subject( "Introduction to programming with C", 100 );

	students[0].print_subjects();*/

	return 0;
}

int resolve( int id ) {
	return id-1;
}

void displayMenu() {
	cout<<"STUDENTS MENU"<<endl;
	cout<<"A) Add Student\n"<<"B) Display Students\n"<<"C) Add subject score\n"<<"D) Print Students Scores\n";
	cout<<"Q) Exit the program"<<endl;
}
