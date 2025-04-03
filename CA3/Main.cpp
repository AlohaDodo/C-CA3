#include "Main.h"
#include "Crawler.h"
#include "Board.h"
#include "Crawler.cpp"
#include "Board.cpp"

int main() {

    ifstream ifs("crawler-bugs.txt");

    //Setting up the menu
    cout << "Select option:" << endl;
    cout << "1. Bug board" << endl;
    cout << "2. Display all bugs" << endl;
    cout << "3. Find a bug using ID" << endl;
    cout << "4. Tap the bug board" <<endl;
    cout << "5. Display life history of all bugs" << endl;
    cout << "6. Display all cells listing their bugs" << endl;
    cout << "7. Run simulation" << endl;
    cout << "8. Exit" << endl;
    cout << "Option: ";

    int option;
    cin >> option;
    switch (option) {
        //Loading up bug board
        case 2: displayCrawlers(crawlers);
        //Find bug by id
        //Tap the bug board
        //Display life history
        //Display all cells
        //Run simulation
        case 8 : exit(0);
    }

    if (ifs)
    {
        setUpCrawlers(ifs,crawlers);
        displayCrawlers(crawlers);
    }

    else {
        cout<<"unable to open file";
    }

    return 0;
}