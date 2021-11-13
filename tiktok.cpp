#include "tiktok.h"
#include <iostream>
#include <sstream>
#include <fstream>

using namespace std;

Tiktok::Tiktok(string reviewId, string reviewText, int upvotes, string appVersion, string postedDate)
{
    this->reviewId = reviewId;
    this->reviewText = reviewText;
    this->upvotes = upvotes;
    this->appVersion = appVersion;
    this->postedDate = postedDate;
}

Tiktok::~Tiktok() {}

string Tiktok::getReviewId() { return this->reviewId; }

string Tiktok::getReviewText() { return this->reviewText; }

int Tiktok::getUpvotes() { return this->upvotes; }

string Tiktok::getAppVersion() { return this->appVersion; }

string Tiktok::getPostedDate() { return this->postedDate; }