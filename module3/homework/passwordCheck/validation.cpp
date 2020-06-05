#include "validation.hpp"
#include <random>

std::string getErrorMessage(const ErrorCode& error){
    std::string message;

    switch(error){
        case ErrorCode::Ok:
            message = "Ok";
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
    std::random_device rd;
    std::uniform_int_distribution<> distrib(0, 5);
    return static_cast<ErrorCode>(distrib(rd));

}

ErrorCode checkPassword(const std::string&, const std::string&);