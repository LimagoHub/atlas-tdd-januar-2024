//
// Created by JoachimWagner on 31.01.2024.
//

#pragma once
#include "../Mockeuro_to_dollar_view.h"
#include "../Mockeuro_to_dollar_calculator.h"
#include "../../source/presenter/euro_to_dollar_presenter_impl.h"

using namespace testing;

class euro_to_dollar_presenter_impl_test: public Test{
protected:
    Mockeuro_to_dollar_view viewMock;
    Mockeuro_to_dollar_calculator modelMock;

    euro_to_dollar_presenter_impl objectUnderTest;

    void SetUp() override;

};
