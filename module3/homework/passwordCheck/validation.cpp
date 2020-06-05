#include "validation.hpp"

std::string getErrorMessage(const ErrorCode& error){
    switch(error){
        std::string message;
        case ErrorCode::Ok:
            message = "Ok";
            break;
        case ErrorCode::PasswordNeedsAtLeastNineCharacters:
            message = "Password needs at least nine characters"
            break;
        case ErrorCode::PasswordNeedsAtLeastOneNumber:
            message = "Password needs at least one number"
            break;
        case ErrorCode::PasswordNeedsAtLeastOneSpecialCharacter:
            message = "Password needs at least one special character"
            break;
        case ErrorCode::PasswordNeedsAtLeastOneUppercaseLetter:
            message = "Password needs at least one uppercase letter"
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

ErrorCode checkPasswordRules(const std::string&);

ErrorCode checkPassword(const std::string&, const std::string&);