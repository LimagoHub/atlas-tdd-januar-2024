//
// Created by JoachimWagner on 30.01.2024.
//

#pragma once
#include "../Mockpersonen_repository.h"
#include "../../source/services/personen_service_exception.h"
#include "../../source/services/personen_service_impl.h"

using namespace testing;

class personen_service_impl_test :public Test{

protected:
    Mockpersonen_repository repoMock;
    personen_service_impl object_under_test{repoMock};

};
