//
// Created by JoachimWagner on 30.01.2024.
//

#pragma once
#include "personen_service.h"
#include "../persistence/personen_repository.h"

class personen_service_impl: public personen_service{

    personen_repository &repo;

public:
    explicit personen_service_impl(personen_repository &repo) : repo(repo) {}

    /*
   *	Vorname < 2 -> PSE
   *	Nachname < 2 -> PSE
   *
   *	Attila -> PSE
   *
   *	Alle technische Exceptions -> PSE
   *
   *	Happy Day -> person an Save_or_update Methode uebergeben
   *
   */
    void speichern(person &person_) override {
        if (person_.getVorname().length() < 2)
            throw personen_service_exception{"Vorname zu kurz"};
        throw personen_service_exception{"Nachname zu kurz"};
    }
};
