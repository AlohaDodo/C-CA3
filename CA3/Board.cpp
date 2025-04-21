#include "Board.h"

#include <array>

#include "Crawler.h"
#include <vector>
#include <fstream>
#include <iostream>
#include <sstream>

using namespace std;

array<array<vector<Crawler*>, 10>, 10> board; //sets up the board cells

//function signings
void setUpCrawlers(ifstream &ifs, vector<Crawler*> &crawlers);
void displayCrawlers(vector<Crawler*> &crawlers);
void displayOneCrawler(vector<Crawler*> &crawlers);
Crawler* findBugById(vector<Crawler*> &crawlers, string bugId);
void tapBoard(vector<Crawler*> &crawlers);
void displayCells(array<array<vector<Crawler*>, 10>, 10> &board);
void clearBoard(array<array<vector<Crawler*>, 10>, 10>& board);
void fight (Crawler* c1,Crawler* c2);

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
        created_crawler->setDirection(static_cast<Direction>(stoi(temp)));// convert string to int

        getline(ss, temp, ','); // size
        created_crawler->setSize(stoi(temp)); // convert string to int

        board[created_crawler->pos.x][created_crawler->pos.y].push_back(created_crawler); //adds crawler positions to the board cells

        crawlers.push_back(created_crawler); // Add to vector
    }
}

//Q2 - Making a method to display all bugs
void displayCrawlers(vector<Crawler*> &crawlers)
{
    for (auto iter = begin(crawlers); iter != end(crawlers); iter++)
    {
        Crawler* crawler = *iter;

        cout << "crawler ID: " << crawler->getId();
        cout <<", position: (" << crawler->pos.x <<"," <<crawler->pos.y << ")";
        cout <<", size: " << crawler->getSize();
        cout <<", facing: " << crawler->directionToString();
        cout <<", alive: " << crawler->aliveToString();
        cout<<endl;

        board[crawler->pos.x][crawler->pos.y].push_back(crawler); //adds crawler positions to the board cells
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
    //clears the board before moving the crawlers, otherwise it also shows the crawler in their last positions

    for (auto iter = begin(crawlers); iter != end(crawlers); ++iter)
    {
        Crawler* crawler = *iter;

        if (crawler->getAlive() == true)
        {
            board[crawler->pos.x][crawler->pos.y].clear(); //removes only the 1 crawler from its position before it moves, dk why i was clearing the whole board before
            crawler->move();
            cout << "crawler ID: " << crawler->getId();
            cout <<", position: (" << crawler->pos.x <<"," <<crawler->pos.y << ")";
            cout <<", size: " << crawler->getSize();
            cout <<", facing: " << crawler->directionToString();
            cout <<", alive: " << crawler->aliveToString();
            cout<<endl;

            board[crawler->pos.x][crawler->pos.y].push_back(crawler);
            displayCells(board);


            //if theres 2 crawlers in the same place they fight
            if (board[crawler->pos.x][crawler->pos.y].size()>=2)
            {
                Crawler* crawler1 = board[crawler->pos.x][crawler->pos.y][0];
                Crawler* crawler2 = board[crawler->pos.x][crawler->pos.y][1];

                if (crawler1->getAlive()==true && crawler2->getAlive()==true)
                {
                    cout<<"Fighting crawlers..."<<endl;
                    fight(crawler1,crawler2);
                }
            }
        }

        else
            cout<<"Crawler "<<crawler->getId()<<" is dead"<<endl;

        cout<<endl;
    }
}

//Q2 - Making a method to display the board
void displayCells(array<array<vector<Crawler*>, 10>, 10>& board)
{
    for ( auto row = 0; row < 10; row++)
    {
        for ( auto col = 0; col < 10; col++)
        {
            cout<<"[";
            cout<<board[row][col].size();
            cout<<"]";
        }
        cout<<endl;
    }
}

//removes everything from the board
void clearBoard(array<array<vector<Crawler*>, 10>, 10>& board)
{
    for (int row = 0; row < 10; row++)
    {
        for (int col = 0; col < 10; col++)
        {
            board[row][col].clear();
        }
    }
}

void fight(Crawler* crawler1, Crawler* crawler2)
{
    cout<<crawler1->getId()<<" and "<<crawler2->getId()<<" fighting..."<<endl;

    if (crawler1->getSize() > crawler2->getSize()) //if crawler1 bigger than crawler2
        {
            crawler2->setAlive(false); //kills crawler 2

            //eats the other crawler and gets bigger
            crawler1->setSize(crawler1->getSize()+crawler2->getSize());
            cout<<"Crawler "<<crawler1->getId()<<" wins"<<endl;
        }

    else if (crawler2->getSize() > crawler1->getSize()) //if crawler 2 bigger than crawler 2
        {
            crawler1->setAlive(false); //kills crawler 1

            //eats the other crawler and gets bigger
            crawler2->setSize(crawler2->getSize()+crawler1->getSize());
            cout<<"Crawler "<<crawler2->getId()<<" wins"<<endl;
        }

    else if (crawler1->getSize() == crawler2->getSize()) //if crawler 1 and crawler 2 are the same size
    {
        int n = rand()%2;

        if (n==0)
        {
            crawler1->setAlive(false); //kills crawler 1

            crawler2->setSize(crawler2->getSize()+crawler1->getSize());
            cout<<"Crawler "<<crawler2->getId()<<" wins"<<endl;
        }

        else if (n==1)
        {
            crawler2->setAlive(false); //kills crawler 2

            crawler1->setSize(crawler1->getSize()+crawler2->getSize());
            cout<<"Crawler "<<crawler1->getId()<<" wins"<<endl;
        }
    }
}