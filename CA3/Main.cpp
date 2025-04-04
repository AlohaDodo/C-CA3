#include "Crawler.h"
#include "Board.h"
#include "Crawler.cpp"
#include "Board.cpp"

int main() {
    vector<Crawler*> crawlers;

    //Feature 1 - Initialise bug board
    ifstream ifs("crawler-bugs.txt");

    //If file doesn't open or fails to find file (remember to fix your directory)
    if (!ifs) {
        cout << "Unable to open file." << endl;
        return 1;
    }

    //Getters setters etc
    setUpCrawlers(ifs, crawlers);

    //While loop so code doesn't break
    while (true) {
        //Printing out menu options
        cout << "\nSelect option:\n"
             << "1. Display all bugs\n"
             << "2. Find a bug using ID\n"
             << "3. Tap the bug board\n"
             << "4. Display life history of all bugs\n"
             << "5. Display all cells listing their bugs\n"
             << "6. Run simulation\n"
             << "7. Exit\n"
             << "Option: ";

        //Inputting which option the user would chose
        int option;
        cin >> option;

        switch (option) {
            //If user picks to display all Crawlers
            case 1:
                displayCrawlers(crawlers);
            break;

            //If user picks to find bug by ID - example 101
            case 2:
                //User entering in an id they want to filter out with
                cout << "Enter bug id: ";
                int bugId;
                cin >> bugId;
            {
                //declaring a variable and going to the method by bringing in the vector and id inputted by user
                Crawler* found = findBugById(crawlers, bugId);
                //if there was something returned in found
                if (found) {
                    displayOneCrawler(found);
                }
                //if there was nothing return in found, it gets a nullptr returned. then returns error
                else {
                    cout << "Bug not found!" << endl;
                }
            }
            break;

            //If user wants to tap the board.
            case 3:
                tapBoard(crawlers);
            break;

            //If user wants to look at the history of the bugs
            case 4:
            //getPathHistory(crawlers);
            break;

            //If user wants to exit or finish the game
            case 7:
                cout << "Bye bye" << endl;
            return 0;
            default:
                cout << "Invalid option. Try again.\n";
            break;
        }
    }
}

