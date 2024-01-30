//
// Created by JoachimWagner on 30.01.2024.
//

#pragma once
#include "personen_service.h"
#include "blacklist_service.h"
#include "../persistence/personen_repository.h"

class personen_service_impl: public personen_service{

    personen_repository &repo;
    blacklist_service &blacklistService;
public:
    personen_service_impl(personen_repository &repo, blacklist_service &blacklistService)
        : repo(repo),
        blacklistService(blacklistService) {}

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
        try {
            speichern_impl(person_);

        } catch (const personen_service_exception & ex) {
            throw ex;
        }
        catch (...) {
            throw personen_service_exception("Ein Fehler ist aufgetreten");
        }

    }

    void speichern(std::string vorname, std::string nachname) {
        person p{vorname, nachname};
        p.setId("1db25762-2642-4559-8149-927ed4f6f947");
        speichern(p);
    }

private:
    void speichern_impl(const person &person_) const {
        check_person(person_);
        repo.save_or_update(person_);
    }

    void check_person(const person &person_) const {
        validate(person_);
        business_check(person_);
    }

    void business_check(const person &person_) const {
        if (blacklistService.is_blacklisted(person_))
            throw personen_service_exception{"Person steht auf der Sperrliste"};
    }

    void validate(const person &person_) const {
        if (person_.getVorname().length() < 2)
            throw personen_service_exception{"Vorname zu kurz"};
        if (person_.getNachname().length() < 2)
            throw personen_service_exception{"Nachname zu kurz"};
    }
};
