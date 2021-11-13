#ifndef TIKTOK_H_INCLUDED
#define TIKTOK_H_INCLUDED

#include <iostream>
#include <sstream>
#include <fstream>


using namespace std;

class Tiktok
{
private:
    string reviewId;
    string reviewText;
    int upvotes;
    string appVersion;
    string postedDate;

public:
    //construtor e destrutor
    Tiktok(string reviewId, string reviewText, int upvotes, string appVersion, string postedDate);
    ~Tiktok();

    //funcao que seta todos os dados
    void setDados();

    string getReviewId();
    string getReviewText();
    int getUpvotes();
    string getAppVersion();
    string getPostedDate();
};

#endif // TIKTOK_H_INCLUDED