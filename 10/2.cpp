#include <iostream>
#include <string>

using namespace std;

////////////////////////////////////////////////////////////////

class publication
{
private:
    string title;
    float price;

public:

    virtual void GetData()
    {
        cout << "\nEnter title: ";
        cin >> title;
        cout << "Enter price: ";
        cin >> price;
    }

    virtual void PutData()
    {
        cout << "\n\nTitle: " << title;
        cout << "\nPrice: " << price;
    }
};

////////////////////////////////////////////////////////////////

class book : public publication
{
private:
    int pages;

public:
    void GetData()
    {
        publication::GetData();
        cout << "Enter number of pages: "; 
        cin >> pages;
    }

    void PutData()
    {
        publication::PutData();
        cout << "\nPages: " << pages;
    }
};

////////////////////////////////////////////////////////////////

class tape : public publication
{
private:
    float time;

public:

    void GetData()
    {
        publication::GetData();
        cout << "Enter playing time: "; 
        cin >> time;
    }

    void PutData()
    {
        publication::PutData();
        cout << "\nPlaying time: " << time;
    }
};

int main()
{
    publication* pubarr[100];          //array of ptrs to pubs
    int n = 0;                         //number of pubs in array
    char choice;                       //user's choice

    do {
        cout << "\nEnter data for book or tape (b/t)? ";
        cin >> choice;

        if (choice == 'b')               //make book object
        {
            pubarr[n] = new book;        //   put in array
        }
        else                            //make tape object
        {
            pubarr[n] = new tape;        //   put in array
        }

        pubarr[n++]->GetData();         //get data for object
        cout << "   Enter another (y/n)? ";  //another pub?
        cin >> choice;

    } while (choice == 'y');              //cycle until not 'y'
    for (int j = 0; j < n; j++)             //cycle thru all pubs
    {
        pubarr[j]->PutData();           //print data for pub
    }

    cout << endl;
    return 0;
}
