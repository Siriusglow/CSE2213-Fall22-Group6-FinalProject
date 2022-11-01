#include <iostream>
#include "User.h"
using namespace std;

int main()
{
    cout << "Testing GIT" << endl;
    cout << "Testing to see if merge likes me this time" << endl;
    cout << "Testing 123" << endl;
    cout << "This is a branch" << endl;
    cout << "It's still not updating" << endl;
    cout << "Testing2" << endl;

    User Username;
    Username.setName("bob");
    cout << Username.getName() << endl;     // testing to ensure the class works and will upload to Github

}