#pragma once 

#include <string>

constexpr size_t MINIMUM_PASSWORD_LENGTH = 9;

enum class ErrorCode{
    Ok,
    PasswordNeedsAtLeastNineCharacters,
    PasswordNeedsAtLeastOneNumber,
    PasswordNeedsAtLeastOneSpecialCharacter,
    PasswordNeedsAtLeastOneUppercaseLetter,
    PasswordsDoesNotMatch
};

std::string getErrorMessage(const ErrorCode);
bool doesPasswordsMatch(const std::string&, const std::string&);
ErrorCode checkPasswordRules(const std::string&);
ErrorCode checkPassword(const std::string&, const std::string&);