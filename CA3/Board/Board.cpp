#include "Board.h"
#include "Crawler.cpp" //help. i think i messed up and this is supposed to call .h but everythings in cpp idkk.
#include <vector>
#include <fstream>
#include <sstream>

using namespace std;

//Vector for Crawler
vector<Crawler*> crawlers;

//function signings
void setUpCrawlers(vector<Crawler*>crawlers);
//

int main() {

  setUpCrawlers(crawlers);

    return 0;
}

void setUpCrawlers(vector<Crawler*> crawlers) {

    ifstream ifs("crawler-bugs.txt");
    string line;

    while (getline(ifs, line))
    {
        stringstream ss(line);

        Crawler* crawlers = new Crawler();

        //ignores the "c" for now,
        ss.ignore();
        ss.ignore();
        //

        ss>>crawlers->id;
        ss.ignore();

        ss>>crawlers->pos.x;
        ss.ignore();
        ss>>crawlers->pos.y;
        ss.ignore();

        //ignores the direction for now, idk how to read ts in as a number rn
        ss.ignore();
        ss.ignore();
        //

        ss>>crawlers->size;
        ss.ignore();

        ss>>crawlers->alive;

    }
}