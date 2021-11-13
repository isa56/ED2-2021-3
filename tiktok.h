#ifndef TIKTOK_H_INCLUDED
#define TIKTOK_H_INCLUDED

#include <bits/stdc++.h>
#include <sstream>
#include <fstream>
#include <string>


using namespace std;

class Tiktok
{
    // Atributos:
    private:
        string reviewId;
        string reviewText;
        int upvotes;
        string appVersion;
        string postedDate;

    // Métodos:
    public:
        //construtor e destrutor
        Tiktok(string reviewId, string reviewText, int upvotes, string appVersion, string postedDate);
        ~Tiktok();

        //funcao que seta todos os dados
        void setDados();    // Vamos usar? Sugestão: Criar Tiktok auxiliar antes e chamar essa função no loop

        // Getters:
        string getReviewId();
        string getReviewText();
        int getUpvotes();
        string getAppVersion();
        string getPostedDate();
};

#endif // TIKTOK_H_INCLUDED