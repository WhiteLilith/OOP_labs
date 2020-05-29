#include <iostream>
#include <cstdlib>

using namespace std;

////////////////////////////////////////////////////////////////

struct link //one element of list

{

	int data; //data item

	link* next; //pointer to next link

};

////////////////////////////////////////////////////////////////

class linklist //a list of links
{
private:
	link* first; //pointer to first link

public:
	linklist() //no-argument constructor
	{
		first = NULL;
	} //no first link

	linklist(const linklist &ls)
	{
		if (ls.first == NULL)
		{
			return;
		}
		else
		{
			first = new link;
			first->data = ls.first->data;

			link *neww = first;
			link *old = ls.first;

			while (old->next != NULL)
			{
				old = old->next;
				neww->next = new link;
				neww = neww->next;
				neww->data = old->data;
			}
			neww->next = NULL;
		}
	}

	~linklist(); //destructor

	void additem(int d); //add data item (one link)

	void display(); //display all links

	linklist& operator =(const linklist ls)
	{
		*this = linklist(ls);
		return *this;
	}
};

//--------------------------------------------------------------

void linklist::additem(int d) //add data item

{

	link* newlink = new link; //make a new link

	newlink->data = d; //give it data

	newlink->next = first; //it points to next link

	first = newlink; //now first points to this

}

//--------------------------------------------------------------

void linklist::display() //display all links
{
	link* current = first; //set ptr to first link

	while (current != NULL) //quit on last link
	{
		cout << endl << current->data; //print data

		current = current->next; //move to next link
	}
}

//--------------------------------------------------------------

linklist::~linklist() //destructor

{

	link* current = first; //set ptr to first link

	while (current != NULL) //quit on last link
	{
		link* temp = current; //save ptr to this link
		cout << "Now deleting: " << current->data << endl;
		current = current->next; //get ptr to next link

		delete temp; //delete this link

	}

}

int main()
{
	linklist *deletingExperement = new linklist;

	deletingExperement->additem(3);
	deletingExperement->additem(0);
	deletingExperement->additem(-2);
	deletingExperement->additem(-909);

	deletingExperement->display();
	cout << endl;

	linklist showingExperiment = *deletingExperement;
	delete deletingExperement;

	cout << endl;
	showingExperiment.display();
	cout << endl;

	return 0;
}
