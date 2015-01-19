#ifndef ERREUR_H_INCLUDED
#define ERREUR_H_INCLUDED

#include <exception>
#include <string>

#include "Log.h"

enum NIVEAU_ERREUR {LOW, MEDIUM, HIGH};
enum TYPE_ERREUR {UNKNOWN, FILE_NOT_FOUND, FILE_ERROR, ENTRY_FORMAT_ERROR};

class Erreur : public std::exception
{
public:
    Erreur(const std::string& str, NIVEAU_ERREUR n = LOW, TYPE_ERREUR = UNKNOWN) throw() :
        description("ERROR : " + str), niveau_ERREUR(n) {Log("EXCEPTION ERROR :" + str);}
    virtual ~Erreur() throw() {}

    virtual const char* what() const throw() {return description.c_str();}

private:
    std::string description;
    NIVEAU_ERREUR niveau_ERREUR;
    TYPE_ERREUR type_ERREUR;
};

#endif // ERREUR_H_INCLUDED
