#include "gtest/gtest.h"
#include "validation.hpp"

std::string PROPER_1_PASSWORD = "aabcDEF!@#123";
std::string PROPER_2_PASSWORD = "ABC%$#123qwe";
std::string PROPER_3_PASSWORD = "+++ABC123~=!";

std::string EMPTY_PASSWORD = "";
std::string TOO_SHORT_PASSWORD = "abCD!@12";
std::string NO_NUMBER_PASSWORD = "abcDEF!@#$";
std::string NO_SPECIAL_PASSWORD = "abcDEF1234";
std::string NO_UPPERCASE_PASSWORD = "abcdef!@#34";

TEST(DoesPasswordsMatchTests, returnsTrueForIdenticalPasswords) {
    EXPECT_TRUE(doesPasswordsMatch(EMPTY_PASSWORD, EMPTY_PASSWORD));
    EXPECT_TRUE(doesPasswordsMatch(PROPER_1_PASSWORD, PROPER_1_PASSWORD));
    EXPECT_TRUE(doesPasswordsMatch(TOO_SHORT_PASSWORD, TOO_SHORT_PASSWORD));
}

TEST(DoesPasswordsMatchTests, returnsFalseForDifferentPasswords) {
    EXPECT_FALSE(doesPasswordsMatch(EMPTY_PASSWORD, PROPER_1_PASSWORD));
    EXPECT_FALSE(doesPasswordsMatch(PROPER_2_PASSWORD, EMPTY_PASSWORD));
    EXPECT_FALSE(doesPasswordsMatch(PROPER_3_PASSWORD, TOO_SHORT_PASSWORD));
}

TEST(checkPasswordRulesTests, returnsRightErrorForIncorectPasswords) {
    EXPECT_EQ(checkPasswordRules(EMPTY_PASSWORD), ErrorCode::PasswordNeedsAtLeastNineCharacters);
    EXPECT_EQ(checkPasswordRules(TOO_SHORT_PASSWORD), ErrorCode::PasswordNeedsAtLeastNineCharacters);
    EXPECT_EQ(checkPasswordRules(NO_NUMBER_PASSWORD), ErrorCode::PasswordNeedsAtLeastOneNumber);  
    EXPECT_EQ(checkPasswordRules(NO_SPECIAL_PASSWORD), ErrorCode::PasswordNeedsAtLeastOneSpecialCharacter); 
    EXPECT_EQ(checkPasswordRules(NO_UPPERCASE_PASSWORD), ErrorCode::PasswordNeedsAtLeastOneUppercaseLetter);  
}

TEST(checkPasswordRulesTests, returnsOkOnRightPasswords) {
    EXPECT_EQ(checkPasswordRules(PROPER_1_PASSWORD), ErrorCode::Ok); 
    EXPECT_EQ(checkPasswordRules(PROPER_2_PASSWORD), ErrorCode::Ok);
    EXPECT_EQ(checkPasswordRules(PROPER_3_PASSWORD), ErrorCode::Ok);
}

TEST(checkPasswordTests, returnsValuesBetweenOkAndPasswordNeedsAtLeastOneUppercaseLetter) {
    EXPECT_EQ(checkPassword(EMPTY_PASSWORD, EMPTY_PASSWORD), ErrorCode::PasswordNeedsAtLeastNineCharacters);
    EXPECT_EQ(checkPassword(TOO_SHORT_PASSWORD, TOO_SHORT_PASSWORD), ErrorCode::PasswordNeedsAtLeastNineCharacters);
    EXPECT_EQ(checkPassword(NO_NUMBER_PASSWORD, NO_NUMBER_PASSWORD), ErrorCode::PasswordNeedsAtLeastOneNumber);  
    EXPECT_EQ(checkPassword(NO_SPECIAL_PASSWORD, NO_SPECIAL_PASSWORD), ErrorCode::PasswordNeedsAtLeastOneSpecialCharacter); 
    EXPECT_EQ(checkPassword(NO_UPPERCASE_PASSWORD, NO_UPPERCASE_PASSWORD), ErrorCode::PasswordNeedsAtLeastOneUppercaseLetter);  
}

TEST(checkPasswordTests, returnsPasswordsDoesNotMatchForDifferentPasswords) {
    EXPECT_EQ(checkPassword(PROPER_1_PASSWORD, EMPTY_PASSWORD), ErrorCode::PasswordsDoesNotMatch); 
    EXPECT_EQ(checkPassword(PROPER_1_PASSWORD, PROPER_2_PASSWORD), ErrorCode::PasswordsDoesNotMatch);
    EXPECT_EQ(checkPassword(TOO_SHORT_PASSWORD, PROPER_3_PASSWORD), ErrorCode::PasswordsDoesNotMatch); 
}

TEST(getErrorMessageTests, returnsErrorCodeAsString) {
    EXPECT_EQ(getErrorMessage(ErrorCode::Ok), "OK");
    EXPECT_EQ(getErrorMessage(ErrorCode::PasswordNeedsAtLeastNineCharacters), "Password needs at least nine characters");
    EXPECT_EQ(getErrorMessage(ErrorCode::PasswordNeedsAtLeastOneNumber), "Password needs at least one number");
    EXPECT_EQ(getErrorMessage(ErrorCode::PasswordNeedsAtLeastOneSpecialCharacter), "Password needs at least one special character");
    EXPECT_EQ(getErrorMessage(ErrorCode::PasswordNeedsAtLeastOneUppercaseLetter), "Password needs at least one uppercase letter");
    EXPECT_EQ(getErrorMessage(ErrorCode::PasswordsDoesNotMatch), "Passwords does not match");
}