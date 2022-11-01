#include <iostream>
#include <string>
#include "User.h"
using namespace std;

int main()                                                                  // The entirity of the main function currently is testing. Class implimentation seems to work. 
{
    cout << "Testing GIT" << endl;
    cout << "Testing to see if merge likes me this time" << endl;
    cout << "Testing 123" << endl;
    cout << "This is a branch" << endl;
    cout << "It's still not updating" << endl;
    cout << "Testing2" << endl;

    User Bob(22, "Bob Smith", "Address", "test@gmail.com", "901-111-1121", "1234-5678-9012", "11/ 12", "123", "Username123", "Password123");
    User Jack;
    cout << Bob.getName() << endl;     // testing to ensure the class works and will upload to Github. User class works as intended. However, it's destructor is still not done.
    cout << Bob.getAddress() << endl;
    cout << Bob.getEmail() << endl;
    cout << Bob.getPhone() << endl;
    cout << Bob.getCreditCardNum() << endl;
    cout << Bob.getExpirationDate() << endl;
    cout << Bob.getCVV() << endl;
    cout << Bob.getUsername() << endl;
    cout << Bob.getPassword() << endl;
    Jack.setAddress("test address");
    cout << "Jack's Address: " << Jack.getAddress() << endl;
}