#include "validation.hpp"
#include <algorithm>
#include <random>
#include <ctype.h>

const size_t MINIMUM_PASSWORD_LENGTH = 9;

std::string getErrorMessage(const ErrorCode& error){
    std::string message;

    switch(error){
        case ErrorCode::Ok:
            message = "OK";
            break;
        case ErrorCode::PasswordNeedsAtLeastNineCharacters:
            message = "Password needs at least nine characters";
            break;
        case ErrorCode::PasswordNeedsAtLeastOneNumber:
            message = "Password needs at least one number";
            break;
        case ErrorCode::PasswordNeedsAtLeastOneSpecialCharacter:
            message = "Password needs at least one special character";
            break;
        case ErrorCode::PasswordNeedsAtLeastOneUppercaseLetter:
            message = "Password needs at least one uppercase letter";
            break;
        case ErrorCode::PasswordsDoesNotMatch:
            message = "Passwords does not match";
            break;
    }
    return message;
}
bool doesPasswordsMatch(const std::string& password, const std::string& repeatedPassword){
    return password == repeatedPassword;
}

ErrorCode checkPasswordRules(const std::string& password){
    if(password.length() < MINIMUM_PASSWORD_LENGTH){
        return ErrorCode::PasswordNeedsAtLeastNineCharacters;
    }

    if(std::none_of(password.begin(), password.end(), ::isdigit)){
        return ErrorCode::PasswordNeedsAtLeastOneNumber;
    }

    if(std::all_of(password.begin(), password.end(), ::isalnum)){
        return ErrorCode::PasswordNeedsAtLeastOneSpecialCharacter;
    }

    if(std::none_of(password.begin(), password.end(), ::isupper)){
        return ErrorCode::PasswordNeedsAtLeastOneUppercaseLetter;
    }

    return ErrorCode::Ok;
}

ErrorCode checkPassword(const std::string& password, const std::string& repeatedPassword){
    if(!doesPasswordsMatch(password, repeatedPassword)){
        return ErrorCode::PasswordsDoesNotMatch;
    }

    return checkPasswordRules(password);
}