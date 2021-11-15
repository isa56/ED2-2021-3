#include <bits/stdc++.h>
#include <sstream>
#include <fstream>
#include "tiktok.h"

using namespace std;

// Construtor:
Tiktok::Tiktok(){}

Tiktok::Tiktok(string reviewId, string reviewText, int upvotes, string appVersion, string postedDate)
{
    this->reviewId = reviewId;
    this->reviewText = reviewText;
    this->upvotes = upvotes;
    this->appVersion = appVersion;
    this->postedDate = postedDate;
}

// Destrutor:
Tiktok::~Tiktok() {}

void Tiktok::setDados(string reviewId, string reviewText, int upvotes, string appVersion, string postedDate) { 
    this->reviewId = reviewId;
    this->reviewText = reviewText;
    this->upvotes = upvotes;
    this->appVersion = appVersion;
    this->postedDate = postedDate;
}

// Getters:
string Tiktok::getReviewId() { return this->reviewId; }

string Tiktok::getReviewText() { return this->reviewText; }

int Tiktok::getUpvotes() { return this->upvotes; }

string Tiktok::getAppVersion() { return this->appVersion; }

string Tiktok::getPostedDate() { return this->postedDate; }