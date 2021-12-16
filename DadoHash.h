#ifndef DADO_H_INCLUDED
#define DADO_H_INCLUDED

#include <bits/stdc++.h>

using namespace std;

class DadoHash
{

private:
    string appVersion;
    int nVezes;

public:
    DadoHash(){ nVezes = 0; }
    // ~DadoHash();

    // Getters e Setters:
    string getAppVersion() { return appVersion; }
    int getNVezes() { return nVezes; }
    void incrementNVezes() { nVezes++; }
    void setDados(string version)
    {
        appVersion = version;
        nVezes = 0;
    }
};

#endif