class ErrorCode{
    Ok,
    PasswordNeedsAtLeastNineCharacters,
    PasswordNeedsAtLeastOneNumber,
    PasswordNeedsAtLeastOneSpecialCharacter,
    PasswordNeedsAtLeastOneUppercaseLetter,
    PasswordDoesNotMatch
}

void getErrorMessage(const ErrorCode&);

bool doesPasswordMatch(std::string, std::string);
ErrorCode checkPasswordRules(std::string);
