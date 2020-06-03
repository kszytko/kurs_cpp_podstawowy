class ErrorCode{
    Ok,
    PasswordNeedsAtLeastNineCharacters,
    PasswordNeedsAtLeastOneNumber,
    PasswordNeedsAtLeastOneSpecialCharacter,
    PasswordNeedsAtLeastOneUppercaseLetter,
    PasswordDoesNotMatch
}

void getErrorMessage(const ErrorCode& error){
    std::string message;

    switch(error){
        case ErrorCode::Ok:
            message = "Ok";
            break;
        case ErrorCode::PasswordNeedsAtLeastNineCharacters:
            message = "PasswordNeedsAtLeastNineCharacters";
            break;
        case ErrorCode::PasswordNeedsAtLeastOneNumber:
            message = "PasswordNeedsAtLeastOneNumber";
            break;
        case ErrorCode::PasswordNeedsAtLeastOneSpecialCharacter:
            message = "PasswordNeedsAtLeastOneSpecialCharacter";
            break;
        case ErrorCode::PasswordNeedsAtLeastOneUppercaseLetter:
            message = "PasswordNeedsAtLeastOneUppercaseLetter";
            break;
        case ErrorCode::PasswordDoesNotMatch:
            message = "PasswordDoesNotMatch";
            break;
    }

    std::cout << message;
}
