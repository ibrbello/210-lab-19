// COMSC-210 | Lab 19 | Ibrahim Bello
// This code stores movie reviews for multiple movies using a Movie class.
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
using namespace std;

// Additions:
// 1. Movie class
// 2. File input
// 3. Vector of Movie objects

// Movie class
class Movie {
    private:
        string title;
        Node review;
    public:
        string getTitle() const     {return title;}
        void setTitle(string s)     {title = s;}
};


//  Node struct
struct Node {
    // data
    double rating;
    string comments;
    // pointer
    Node *next;
};

int main() {
    vector<Movie> movies;
    

    Node *head = nullptr;
    Node *current = head;
    // Ask whether the user wants to add node to head or tail
    cout << "Which linked list method should we use?" << endl;
    cout << "   [1]: New nodes are added at the head of the linked list" << endl;
    cout << "   [2]: New nodes are added at the tail of the linked list" << endl;
    int methodChoice;
    cin >> methodChoice;
    cout << "The choice was " << methodChoice << endl;

    string anotherEntry;
    // enter do-while loop
    do {
        // get user input
        double tmpRating;
        do { // input validation
            cout << "Enter review rating 0-5: ";
            cin >> tmpRating;
        } while (tmpRating < 0 || tmpRating > 5);
        cin.ignore(); 

        cout << "Enter review comments: ";
        string tmpComments;
        getline(cin, tmpComments);

        Node *newNode = new Node; // create ptr that points to dynamically allocated space
        if (methodChoice == 1) { // adding to head
        
            // adds node at head
            if (!head) { // If list is empty
                head = newNode; 
                newNode->next = nullptr; 
                newNode->rating = tmpRating; 
                newNode->comments = tmpComments;
            }
            else { // If list is not empty
                newNode->next = head; 
                newNode->rating = tmpRating; 
                newNode->comments = tmpComments;
                head = newNode; 
            } 
        }

        else { // adding to tail
            // if list is empty, same as above
            if (!head) { // If list is empty
                head = newNode; 
                newNode->next = nullptr; 
                newNode->rating = tmpRating; 
                newNode->comments = tmpComments;
            }
            else {
                // if not: traverse list to the end, and make the pointer of the last node 
                // point to the new node
                current = head;
                while (current->next) { // Traverse list
                    current = current->next;
                }
                current->next = newNode;
                newNode->rating = tmpRating; 
                newNode->comments = tmpComments;
                newNode->next = nullptr;
            }
        }
        cout << "Do you want to enter another review? y/n: " << endl;
        cin >> anotherEntry;
        cin.ignore();
    } while (anotherEntry != "n");
   
    // Output
    double avgRating = 0;
    double total = 0;
    int count = 0;
    cout << endl;
    cout << "Outputting reviews..." << endl;
    // traverse list
    current = head;
    while (current) { 
        count++;
        cout << "Review #" << count << ": " << "Rating: " << current->rating << ": " 
            << current->comments << endl;
        total += current->rating;
        current = current->next;
    }
    // compute average
    avgRating = total / count;
    // print average
    cout << "Average rating: " << avgRating << endl;

     // Cleanup to prevent memory leak
     while (head) {
        Node* temp = head;
        head = head->next;
        delete temp;
    }
    return 0;
}