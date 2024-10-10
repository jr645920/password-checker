#include <iostream>
//#include <regex>

using namespace std;

/// @brief Checks if a password meets Chipotle's password requirements as described in the main program. Uses regular expressions to test for validity.
/// @param password string to be parsed and checked
/// @return boolean value that reflects the password's validity
bool check(string password){
    //regex capital("[A-Z]+");
    //regex lowercase("[a-z]+");
    //regex number("[0-9]+");
    //regex symbol("[~!@#$%^&*=+|/.,<>\\_-`\?()[]\";:]+");
    //regex length("[^\n \t][^\n \t][^\n \t][^\n \t][^\n \t][^\n \t][^\n \t][^\n \t]+");

    // if(!regex_search(password, capital)){
    //     return false;
    // }
    // if(!regex_search(password, lowercase)){
    //     return false;
    // }
    // if(!regex_search(password, number)){
    //     return false;
    // }
    // if(!regex_search(password, symbol)){
    //     return false;
    // }
    // if(!regex_search(password, length)){
    //     return false;
    // }

    bool upper = false;
    bool lower = false;
    bool number = false;
    bool special = false;

    if(password.length() < 8){
        return false;
    }
    for(long unsigned int i = 0; i < password.length(); i++){
        if(!upper && isupper(password[i])){
            upper = true;
        }
        else if(!lower && islower(password[i])){
            lower = true;
        }
        else if(!number && isdigit(password[i])){
            number = true;
        }
        // ~!@#$%^&*=+|/.,<>\\_-`\?()[]\";:
        else if(!special && (password[i]=='~'||password[i]=='!'||password[i]=='@'||password[i]=='#'||password[i]=='$'||password[i]=='%'||password[i]=='^'||
        password[i]=='&'||password[i]=='*'||password[i]=='='||password[i]=='+'||password[i]=='|'||password[i]=='/'||password[i]=='.'||password[i]==','||
        password[i]=='<'||password[i]=='>'||password[i]=='\\'||password[i]=='_'||password[i]=='-'||password[i]=='`'||password[i]=='?'||password[i]=='('||
        password[i]==')'||password[i]=='['||password[i]==']'||password[i]=='"'||password[i]==';'||password[i]==':'||password[i]=='!')){
            special = true;
        }
    }
    // if(!regex_search(password, symbol)){
    //     return false;
    // }
    if(!(upper && lower && number && special)){
        return false;
    }
    printf("%s\n", password.c_str());
    return true;
}

int main(){
    /* Chipotle password requirements: 
        1. Must be at least 8 characters
        2. At least one Uppercase
        3. At least one Lowercase
        4. At least one special character

        Chipotle also accepts non-ASCII characters, so long
        as the password still meets the requirements above.
        Moreover, non-ASCII characters are not counted in 
        the special character condition.

        ex: *7¡Vamos! is a valid password
            7Vamos is not a valid password

    */

    int count = 0;
    string password;
    while(cin >> password){
        if(check(password)){
            count++;
        }
    }
    printf("Valid passwords: %i\n", count);

    exit(0);
}