#include <iostream>
#include <iomanip>
using namespace std;

const int PREC = 2;

struct Review    // Review structure definition
{
    double rating;
    string comment;
    Review *next;
};

void makes_linked_list(Review*&, Review*&, int);    //Function prototypes to make the list and output the list
void output_list(Review*&, Review*&, char);

int main()
{
    Review *head =  nullptr;    // head and tail pointers initialized
    Review *tail = nullptr;
    int choice;    // choice variable to track user input
    
    // User is promtped to choose adding to the start or end of the list
    cout << "Do you want to create a list that adds to the start or the end of the liked list\n";
    cout << "Enter 1 or 2\n";
    cout << "1) Start of the list\n";
    cout << "2) End of the list\n";
    cout << "Entry: ";
    cin >> choice;
    
    while (choice != 1 && choice != 2) {    // Input validation loop
        cout << "Enter 1 or 2\n";
        cout << "1) Start of the list\n";
        cout << "2) End of the list\n";
        cout << "Entry: ";
        cin >> choice;
    }
    
    makes_linked_list(head, tail, choice);    // Build list function call
    
    return 0;
}

void makes_linked_list(Review *&ptrHD, Review *&ptrTL, int input)
{
    Review *newReview = nullptr;   // strcut pointer to be used to build the list
    char answ;
    
        newReview = new Review;    // head and tail pointers start by pointing at new Review
        ptrHD = newReview;
        ptrTL = newReview;
        newReview->next = nullptr;
        
        cout << "What was the reviewer's rating? Rating: ";   // User enters the rating and comment for the new Review
        cin >> ptrHD->rating;
        cin.ignore();
        cout << "What was the reviewer's comment? Comment: ";
        getline(cin, ptrHD->comment);
        
        cout << "Add another? Enter Y or N: ";    // User prompted to add another review or not
        cin >> answ;
        
        while (answ != 'Y' && answ != 'N') {    // Input validation loop
            cin.clear();
            cin.ignore(100, '\n');
            cout << "Enter Y or N: ";
            cin >> answ;
        }
        
        if (answ == 'Y' && input == 1) {   // Condition to add a new element depending on if they chose to add to the start or end of the list
            newReview = new Review;
            ptrHD = newReview;
            newReview->next = ptrTL->next;
            newReview = nullptr;
            
            cout << "What was the reviewer's rating? Rating: ";
            cin >> ptrHD->rating;
            cin.ignore();
            cout << "What was the reviewer's comment? Comment: ";
            getline(cin, ptrHD->comment);
            
            output_list(ptrHD, ptrTL, answ);    // Function call to output the list
        }

        if (answ == 'Y' && input == 2) {    // Condition to add a new element depending on if they chose to add to the start or end of the list
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
            
            output_list(ptrHD, ptrTL, answ);    // Function call to output the list
        }
        
        if (answ == 'N') {    // Function call to output single node in list if the user did not want to add a new Review
            output_list(ptrHD, ptrTL, answ);
        }
    
    delete newReview;    //newReview pointer freed
    newReview = nullptr;
}

void output_list(Review *&ptrHD, Review *&ptrTL, char input)
{
    double rate1;    // double varaibles to store the two ratings and the average
    double rate2;
    double avg;
    
    if (input == 'Y') {
        rate1 = ptrHD->rating;    // rate1 and rate2 store their respective data
        rate2 = ptrTL->rating;
        
        avg = ((rate1 + rate2) / 2);    // average calculated
        
        cout << "Here's the list\n";    // nodes in each list outputted
        cout << "-------\n";
        cout << "Review 1\n";
        cout << "Rating: " << setprecision(PREC) << ptrHD->rating << " Comment: " << ptrHD->comment << endl;
        cout << "-------\n";
        cout << "Review 2\n";
        cout << "Rating: " << setprecision(PREC) << ptrTL->rating << " Comment: " << ptrTL->comment << endl;
        cout << "-------\n";
        cout << "Average rating: " << setprecision(PREC) << avg << endl;    //average outputted
        cout << "-------\n";
        
        delete ptrHD;    // head and tail pointers freed
        ptrHD = nullptr;
        delete ptrTL;
        ptrHD = nullptr;
    }
    
    else {
        cout << "Here's the list\n";    // single node printed if user did not enter another
        cout << "-------\n";
        cout << "Review 1\n";
        cout << "Rating: " << setprecision(PREC) << ptrHD->rating << " Comment: " << ptrHD->comment << endl;
        cout << "-------\n";
        cout << "Average rating: " << setprecision(PREC) << ptrHD->rating << endl;
        cout << "-------\n";
    }
}
