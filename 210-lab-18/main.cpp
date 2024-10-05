#include <iostream>
#include <iomanip>
using namespace std;

const int PREC = 2;

struct Review
{
    double rating;
    string comment;

    Review *next;
};

void makes_linked_list(Review*, Review*, int);

int main()
{
    Review *head = nullptr;
    Review *tail =  nullptr;
    int choice;
    
    cout << "Do you want to create a list that adds to the start or the end of the liked list\n";
    cout << "Enter 1 or 2\n";
    cout << "[1] Start of the list\n";
    cout << "[2] End of the list\n";
    cout << "Entry: ";
    cin >> choice;
    
    while (choice != 1 && choice != 2) {
        cout << "Enter 1 or 2\n";
        cout << "1) Start of the list\n";
        cout << "2) End of the list\n";
        cout << "Entry: ";
        cin >> choice;
    }
    
    makes_linked_list(head, tail, choice);
    
    delete head;
    delete tail;
    head = nullptr;
    tail = nullptr;
 
    return 0;
}


void makes_linked_list(Review *ptrHD, Review* ptrTL, int input)
{
    Review *newReview = nullptr;
    char y_or_n;
    
        newReview = new Review;
        ptrHD = newReview;
        ptrTL = newReview;
        newReview->next = nullptr;
        
        cout << "What was the reviewer's rating? Rating: ";
        cin >> ptrHD->rating;
        cin.ignore();
        cout << "What was the reviewer's comment? Comment: ";
        getline(cin, ptrHD->comment);
        
        cout << "Add another? Enter Y or N: ";
        cin >> y_or_n;
        
        while (y_or_n != 'Y' && y_or_n != 'N') {
            cout << "Enter Y or N: ";
            cin >> y_or_n;
        }
        
        if (y_or_n == 'Y' && input == 1) {
            newReview = new Review;
            ptrHD = newReview;
            newReview->next = ptrTL->next;
            newReview = nullptr;
            
            cout << "What was the reviewer's rating? Rating: ";
            cin >> ptrHD->rating;
            cin.ignore();
            cout << "What was the reviewer's comment? Comment: ";
            getline(cin, ptrHD->comment);
            
            cout << "Here's the list\n";
            cout << "Review 1\n";
            cout << "Rating: " << setprecision(PREC) << ptrHD->rating << " Comment: " << ptrHD->comment << endl;
            cout << "Review 2\n";
            cout << "Rating: " << setprecision(PREC) << ptrTL->rating << " Comment: " << ptrTL->comment << endl;
        }

        if (y_or_n == 'Y' && input == 2) {
            newReview = new Review;
            ptrHD->next = newReview;
            ptrTL = newReview;
            newReview->next = nullptr;
            newReview = nullptr;
            
            cout << "What was the reviewer's rating? Rating: ";
            cin >> ptrTL->rating;
            cin.ignore();
            cout << "What was the reviewer's comment? Comment: ";
            getline(cin, ptrTL->comment);
            
            cout << "Here's the list\n";
            cout << "Review 1\n";
            cout << "Rating: " << setprecision(PREC) << ptrHD->rating << " Comment: " << ptrHD->comment << endl;
            cout << "Review 2\n";
            cout << "Rating: " << setprecision(PREC) << ptrTL->rating << " Comment: " << ptrTL->comment << endl;
        }
        
        if (y_or_n == 'N') {
            cout << "Here's the list\n";
            cout << "Review 1\n";
            cout << "Rating: " << setprecision(PREC) << ptrHD->rating << " Comment: " << ptrHD->comment << endl;
        }
    
    delete newReview;
    newReview = nullptr;
}
