//
// Created by JoachimWagner on 30.01.2024.
//

#pragma once
#include "../persistence/person.h"

class personen_service {

public:
    virtual void speichern(person &person_) = 0;

};
