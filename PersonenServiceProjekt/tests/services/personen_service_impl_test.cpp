//
// Created by JoachimWagner on 30.01.2024.
//

#include "personen_service_impl_test.h"
#include <stdexcept>

TEST_P(personen_service_impl_parameter_test, speichern__throws_personen_service_exception) {
    try {

        object_under_test.speichern(invalidPerson);
        FAIL() << "Exception erwartet";
    } catch (personen_service_exception &ex) {
        EXPECT_STREQ(ex.what(), expectedErrorMessage.c_str());
    }
}

TEST_F(personen_service_impl_test, speichern__vorname_zu_kurz__throws_personen_service_exception) {
    // Arrange
    person invalid_person{"J", "Doe"};
    try {
        EXPECT_CALL(repoMock, save_or_update(_)).Times(0);
        object_under_test.speichern(invalid_person);
        FAIL() << "Exception expected";
    } catch(const personen_service_exception & ex) {
        EXPECT_THAT(ex.what(), StrEq("Vorname zu kurz") );
    }
}

TEST_F(personen_service_impl_test, speichern__nachname_zu_kurz__throws_personen_service_exception) {
    // Arrange
    person invalid_person{"John", "D"};
    try {
        object_under_test.speichern(invalid_person);
        FAIL() << "Exception expected";
    } catch(const personen_service_exception & ex) {
        EXPECT_THAT(ex.what(), StrEq("Nachname zu kurz") );
    }
}

TEST_F(personen_service_impl_test, speichern__blacklisted_person__throws_personen_service_exception) {
    // Arrange
    person invalid_person{"John", "Doe"};
    try {
        EXPECT_CALL(blacklistServiceMock, is_blacklisted(invalid_person)).WillOnce(Return(true));
        object_under_test.speichern(invalid_person);
        FAIL() << "Exception expected";
    } catch(const personen_service_exception & ex) {
        EXPECT_THAT(ex.what(), StrEq("Person steht auf der Sperrliste") );
    }
}


TEST_F(personen_service_impl_test, speichern__exception_in_underlying_service__throws_personen_service_exception) {
    // Arrange
    person valid_person{"John", "Doe"};
    try {

        EXPECT_CALL(repoMock, save_or_update(_)).WillOnce(Throw(std::logic_error{"Upps"}));
        object_under_test.speichern(valid_person);
        FAIL() << "Exception expected";
    } catch(const personen_service_exception & ex) {
        EXPECT_THAT(ex.what(), StrEq("Ein Fehler ist aufgetreten") );

    }
}

TEST_F(personen_service_impl_test, speichern__happy_day__person_passed_to_repo) {

    InSequence dummy;
    // Arrange
    person valid_person{"John", "Doe"};

    // Record Mode
    EXPECT_CALL(blacklistServiceMock, is_blacklisted(_)).WillOnce(Return(false));
    EXPECT_CALL(repoMock, save_or_update(valid_person));


    object_under_test.speichern(valid_person);

}

TEST_F(personen_service_impl_test, speichern_overloaded__happy_day__person_passed_to_repo) {


    // Arrange
    person captured_person{};

    // Record Mode

    EXPECT_CALL(repoMock, save_or_update(_)).WillOnce(DoAll(SaveArg<0>(&captured_person)));


    object_under_test.speichern("Jane","Doe");
    EXPECT_THAT( captured_person.getVorname(), AnyOf(StartsWith("J"), StartsWith("M")));
    EXPECT_THAT(captured_person.getNachname(), AnyOf(Eq("Doe"), Eq("Mustermann")));
    EXPECT_THAT(captured_person.getId(), Not(IsEmpty()));
}

void personen_service_impl_test::SetUp() {
    ON_CALL(blacklistServiceMock, is_blacklisted(_)).WillByDefault(Return(false));
}

INSTANTIATE_TEST_SUITE_P(
        speichern_invalid_names, // Name der Testa frei waehlbar
        personen_service_impl_parameter_test, // Verbindung zur Testklasse
        Values(
                std::make_pair(person{"","Doe"},"Vorname zu kurz" ),
                std::make_pair(person{"J","Doe"},"Vorname zu kurz" ),
                std::make_pair(person{"John",""},"Nachname zu kurz" ),
                std::make_pair(person{"John","D"},"Nachname zu kurz" )
        )
);

