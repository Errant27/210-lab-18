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

void head_linked_list(Review*);
void tail_linked_list();
//void output_list();


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
        cout << "[1] Start of the list\n";
        cout << "[2] End of the list\n";
        cout << "Entry: ";
        cin >> choice;
    }
    
    if (choice == 1)
        head_linked_list(head);
       
    
    if (choice == 2) {
        head_linked_list(tail);
    }
    
    delete head;
    delete tail;
    head = nullptr;
    tail = nullptr;
 
    return 0;
}


void head_linked_list(Review *ptrHD)
{
    Review *newReview = nullptr;
    char y_or_n;
    
        newReview = new Review;
        ptrHD = newReview;
        ptrHD->next = nullptr;
        newReview = nullptr;
        
        cout << "What was the reviewer's rating? Rating: ";
        cin >> ptrHD->rating;
        cin.ignore();
        cout << "What was the reviewer's comment? Comment: ";
        getline(cin, ptrHD->comment);
        
        ptrHD->next = nullptr;
        newReview = nullptr;
        
        cout << "Add another? Enter Y or N: ";
        cin >> y_or_n;
        
        while (y_or_n != 'Y' && y_or_n != 'N') {
            cout << "Enter Y or N: ";
            cin >> y_or_n;
        }
        
        if (y_or_n == 'Y') {
            newReview = new Review;
            ptrHD->next = newReview;
            ptrHD->next->next = nullptr;
            newReview = nullptr;
            cout << "What was the reviewer's rating? Rating: ";
            cin >> ptrHD->next->rating;
            cin.ignore();
            cout << "What was the reviewer's comment? Comment: ";
            getline(cin, ptrHD->next->comment);
            
            cout << "Here's the list\n";
            cout << "Review 1\n";
            cout << "Rating: " << setprecision(PREC) << ptrHD->rating << " Comment: " << ptrHD->comment << endl;
            cout << "Review 2\n";
            cout << "Rating: " << setprecision(PREC) << ptrHD->next->rating << " Comment: " << ptrHD->next->comment << endl;
        }
        
        if (y_or_n == 'N') {
            cout << "Here's the list\n";
            cout << "Review 1\n";
            cout << "Rating: " << setprecision(PREC) << ptrHD->rating << " Comment: " << ptrHD->comment << endl;
        }
    
    delete newReview;
    newReview = nullptr;
}

void tail_linked_list(Review *ptrTL)
{
    Review *newReview = nullptr;
    Review *nav = nullptr;
    char y_or_n;
    
        newReview = new Review;
        ptrTL = newReview;
        ptrTL->next = nullptr;
        newReview = nullptr;
        
        cout << "What was the reviewer's rating? Rating: ";
        cin >> ptrTL->rating;
        cin.ignore();
        cout << "What was the reviewer's comment? Comment: ";
        getline(cin, ptrTL->comment);
        
        ptrTL->next = nullptr;
        newReview = nullptr;
        
        cout << "Add another? Enter Y or N: ";
        cin >> y_or_n;
        
        while (y_or_n != 'Y' && y_or_n != 'N') {
            cout << "Enter Y or N: ";
            cin >> y_or_n;
        }
        
        if (y_or_n == 'Y') {
            newReview = new Review;
            nav = newReview;
            nav->next = ptrTL;
            newReview = nullptr;
            cout << "What was the reviewer's rating? Rating: ";
            cin >> nav->rating;
            cin.ignore();
            cout << "What was the reviewer's comment? Comment: ";
            getline(cin, nav->comment);
            
            cout << "Here's the list\n";
            cout << "Review 1\n";
            cout << "Rating: " << setprecision(PREC) << nav->rating << " Comment: " << nav->comment << endl;
            cout << "Review 2\n";
            cout << "Rating: " << setprecision(PREC) << nav->next->rating << " Comment: " << nav->next->comment << endl;
        }
        
        if (y_or_n == 'N') {
            cout << "Here's the list\n";
            cout << "Review 1\n";
            cout << "Rating: " << setprecision(PREC) << nav->rating << " Comment: " << nav->comment << endl;
        }
    
    delete newReview;
    newReview = nullptr;
}

//void output_list();

