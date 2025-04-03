#include "Main.h"
#include "Crawler.h"
#include "Board.h"
#include "Crawler.cpp"
#include "Board.cpp"

int main() {

    ifstream ifs("crawler-bugs.txt");

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