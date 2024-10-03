#include <iostream>
#include <regex>
//#include <mpi.h>

using namespace std;

int num_procs = 1;
int proc_rank = 0;

/// @brief Checks if a password meets Chipotle's password requirements as described in the main program. Uses regular expressions to test for validity.
/// @param password string to be parsed and checked
/// @return boolean value that reflects the password's validity
bool check(string& password){
    regex capital("[A-Z]+");
    regex lowercase("[a-z]+");
    regex number("[0-9]+");
    regex symbol("[~!@#$%^&*=+|/.,<>\\_-`\?()]+");
    regex length("[^\n \t][^\n \t][^\n \t][^\n \t][^\n \t][^\n \t][^\n \t][^\n \t]+");

    if(!regex_search(password, capital)){
        return false;
    }
    if(!regex_search(password, lowercase)){
        return false;
    }
    if(!regex_search(password, number)){
        return false;
    }
    if(!regex_search(password, symbol)){
        return false;
    }
    if(!regex_search(password, length)){
        return false;
    }
    cout << password << endl;
    return true;
}

int main(){
    /* Chipotle password requirements: 
        1. Must be at least 8 characters
        2. At least one Uppercase
        3. At least one Lowercase
        4. At least one special character

        mpicxx -Wall -Werror -O3
    */

    // MPI_Init(NULL,NULL); //

    // MPI_Comm_size(MPI_COMM_WORLD,&num_procs); //
    // MPI_Comm_rank(MPI_COMM_WORLD,&proc_rank); //

    int count = 0;
    string password;
    while(cin >> password){
        if(check(password)){
            count++;
        }
    }
    //if (debug) cout << "I am process " << proc_rank << " of " << num_procs << endl;
    printf("Valid passwords: %i\n", count);


    // MPI_Finalize(); //
    exit(0);
}