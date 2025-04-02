#include "Board.h"
#include "C:\Users\Ciarán\CLionProjects\C-CA3\CA3\Crawler\Crawler.h"
#include <vector>
#include <fstream>
#include <iostream>
#include <sstream>

using namespace std;

//Vector for Crawler
vector<Crawler*> crawlers;

//function signings
void setUpCrawlers(ifstream &ifs,vector<Crawler*> &crawlers);
void displayCrawlers(vector<Crawler*> &crawlers);
//

int main() {

    ifstream ifs("crawler-bugs.txt");

    if (ifs)
    {
        setUpCrawlers(ifs,crawlers);
    }

    else {
        cout<<"unable to open file";
    }

    return 0;
}

void setUpCrawlers(ifstream &ifs, vector<Crawler*> &crawlers) {

    string line;

    while (getline(ifs, line))
    {
        stringstream ss(line);

        Crawler* created_crawler = new Crawler();

        //ignores the "c" for now,
        ss.ignore();
        ss.ignore();
        //

        ss>>created_crawler->id;
        ss.ignore();

        ss>>created_crawler->pos.x;
        ss.ignore();
        ss>>created_crawler->pos.y;
        ss.ignore();

        //ignores the direction for now, idk how to read ts in as a number rn
        ss.ignore();
        ss.ignore();
        //

        ss>>created_crawler->size;
        ss.ignore();

        ss>>created_crawler->alive;

        crawlers.push_back(created_crawler);
    }//end of while
}//end of setUpCrawlers

void displayCrawlers(vector<Crawler*> &crawlers)
{
    for (auto iter = begin(crawlers)+1; iter != end(crawlers); iter++)
    {
        Crawler* crawler = *iter;

        cout <<"crawler ID: " << crawler->id << endl;
        cout <<"crawler position x: " << crawler->pos.x << endl;
        cout <<"crawler position y: " << crawler->pos.y << endl;
    }
}