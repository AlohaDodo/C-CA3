#include "Board.h"
#include "Crawler.h"
#include <vector>
#include <fstream>
#include <iostream>
#include <sstream>

using namespace std;

//function signings
void setUpCrawlers(ifstream &ifs, vector<Crawler*> &crawlers);
void displayCrawlers(vector<Crawler*> &crawlers);
void displayOneCrawler(vector<Crawler*> &crawlers);
Crawler* findBugById(vector<Crawler*> &crawlers, string bugId);
void tapBoard(vector<Crawler*> &crawlers);

//Set up crawlers - assign values from the file to variables
void setUpCrawlers(ifstream &ifs, vector<Crawler*> &crawlers) {
    string line;
    while (getline(ifs, line)) {  // Read each line from the file
        stringstream ss(line);
        Crawler* created_crawler = new Crawler();
        string temp;

        getline(ss, temp, ','); // c - type (not used)
        getline(ss, temp, ','); // id
        created_crawler->setId(stoi(temp)); // convert string to int id
        getline(ss, temp, ','); // position x coordinate
        created_crawler->pos.x = stoi(temp); // convert string to int x
        getline(ss, temp, ','); // position y coordinate
        created_crawler->pos.y = stoi(temp); // convert string to int y
        getline(ss, temp, ','); // direction
        created_crawler->setDirection(stoi(temp)); // convert string to int
        getline(ss, temp, ','); // size
        created_crawler->setSize(stoi(temp)); // convert string to int

        crawlers.push_back(created_crawler); // Add to vector
    }
}

ostream operator<<(const ostream & lhs, int(* rhs)());

//Q2 - Making a method to display all bugs
void displayCrawlers(vector<Crawler*> &crawlers)
{
    for (auto iter = begin(crawlers); iter != end(crawlers); iter++)
    {
        Crawler* crawler = *iter;

        cout << "crawler ID: " << crawler->getId() << endl;
        cout <<"crawler position x: " << crawler->pos.x << endl;
        cout <<"crawler position y: " << crawler->pos.y << endl;
        cout <<"crawler size: " << crawler->getSize() << endl;
        cout<<endl;

    }
}

//Q3 - Method find bug by ID
Crawler *findBugById(vector<Crawler *> &crawlers, int bugId) {
    for (int i = 0; i<crawlers.size(); i++) {
        if (crawlers[i]->getId() == bugId) {
            return crawlers[i];
        }
    }
    return nullptr;
}

//Making a method to display one bug
void displayOneCrawler(Crawler* &crawler) {
    cout << "crawler ID: " << crawler->getId() << endl;
}

//Q4 - Tap the board method
void tapBoard(vector<Crawler*> &crawlers)
{
    for (auto iter = begin(crawlers); iter != end(crawlers); iter++)
    {
        Crawler* crawler = *iter;
        crawler->move();

        cout <<"crawler ID: " << crawler->getId() << endl;
        cout <<"new crawler position x: " << crawler->pos.x << endl;
        cout <<"new crawler position y: " << crawler->pos.y << endl;
        cout <<"crawler size: " << crawler->getSize() << endl;
        cout<<endl;
    }
}
