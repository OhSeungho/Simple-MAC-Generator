#include <iostream>
#include <cstring>
#include <time.h>
#include "sha256.h"
#include "sha256_a.h"

using namespace std;
using std::string;
using std::cout;
using std::endl;

// Nonce(ºñÇ¥)
unsigned int PRNG(static unsigned int key) {
    key = 8253729 * key;

    return key % 32768;
}

string server(string message, string mac_output, int key, int c_key) {
    string chk_message = "";
    int m_key = 0;
    m_key = PRNG(key);
    chk_message = sha256(message);
    if (chk_message == mac_output && m_key == c_key) {
        cout << "Server : " << chk_message << endl;
        cout << "Match" << endl;
    }
    else {
        cout << "Suspected Attack" << endl;

        return 0;
    }
}

int main(int argc, char* argv[])
{
    string message = "";
    string mac_output = "";

    int type = 0;
    int key = 0;
    int c_key = 0;
    
    cout << "Message Authentication Code(SHA-256)" << endl;
    cout << "1_Client, 2_Attaker" << endl;
    cin >> type;
    cout << "Input Key : ";
    cin >> key;
    c_key = PRNG(key);
    cout << "Input Message : ";
    cin >> message;
    if (type == 1) {
        mac_output = sha256(message);
        cout << "Client : " << mac_output << endl;
    }
    else {
        mac_output = sha256("attack");
        cout << mac_output << endl;
    }

    server(message, mac_output, key, c_key);

    return 0;
}

