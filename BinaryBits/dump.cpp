#include <iostream>
#include <sstream>
#include <vector>
using namespace std;
bool validIp(const string &ipStr)
{
    int num, dots = 0;
    stringstream ss(ipStr);
    string part;
    vector<string> parts;
    while (getline(ss, part, '.'))
    {
        parts.push_back(part);
    }
    if (parts.size() != 4)
    {
        return false;
    }
    for (const auto &part : parts)
    {
        try
        {
            num = stoi(part);
        }
        catch (const exception &)
        {
            return false;
        }
        if (num < 0 || num > 255)
        {
            return false;
        }
        dots++;
    }
    return dots == 4;
}
bool isFirstAddress(const string &ipStr, int subnetMask)
{
    stringstream ss(ipStr);
    string part;
    vector<int> octet;
    while (getline(ss, part, '.'))
    {
        octet.push_back(stoi(part));
    }
    return subnetMask == 24 && octet.size() == 4 && octet[3] == 0;
}
void displayUsableAddresses(const string &ipStr, int subnetMask)
{
    stringstream ss(ipStr);
    string part;
    vector<int> octet;
    while (getline(ss, part, '.'))
    {
        octet.push_back(stoi(part));
    }
    if (subnetMask == 24 && octet.size() == 4)
    {
        cout << "Displaying usable IP addresses in the subnet range:\n";
        for (int i = 1; i < 255; i++)
        {
            cout << octet[0] << "." << octet[1] << "." << octet[2] << "." << i << "\n";
        }
    }
}
int main()
{
    string ip;
    int subnetMask = 24;
    cout << "Please enter a valid IP address: ";
    getline(cin, ip);
    if (validIp(ip))
    {
        cout << "Valid IP address entered.\n";
        if (isFirstAddress(ip, subnetMask))
        {
            cout << "This IP address is the first address (Network address).\n";
        }
        else
        {
            cout << "This IP address is not the first address.\n";
        }
        displayUsableAddresses(ip, subnetMask);
    }
    else
    {
        cout << "The IP address you entered is not valid.\n";
    }
    return 0;
}