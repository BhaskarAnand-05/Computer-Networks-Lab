#include <iostream>
#include <string>

using namespace std;

int main()
{
    string ip_address;
    cout << "Enter an IPv4 address: ";
    cin >> ip_address;

    // Split the IP address into its octets
    int octet1, octet2, octet3, octet4;
    sscanf(ip_address.c_str(), "%d.%d.%d.%d", &octet1, &octet2, &octet3, &octet4);

    // Determine the network class based on the first octet
    char network_class;
    if (octet1 >= 1 && octet1 <= 126)
    {
        network_class = 'A';
    }
    else if (octet1 >= 128 && octet1 <= 191)
    {
        network_class = 'B';
    }
    else if (octet1 >= 192 && octet1 <= 223)
    {
        network_class = 'C';
    }
    else if (octet1 >= 224 && octet1 <= 239)
    {
        network_class = 'D';
    }
    else
    {
        network_class = 'E';
    }

    // Determine the network ID and host ID based on the network class
    unsigned int network_id, host_id;
    if (network_class == 'A')
    {
        network_id = octet1 << 24;
        host_id = (octet2 << 16) | (octet3 << 8) | octet4;
    }
    else if (network_class == 'B')
    {
        network_id = (octet1 << 24) | (octet2 << 16);
        host_id = (octet3 << 8) | octet4;
    }
    else if (network_class == 'C')
    {
        network_id = (octet1 << 24) | (octet2 << 16) | (octet3 << 8);
        host_id = octet4;
    }
    else
    {
        network_id = 0;
        host_id = 0;
    }

    // Print the results
    cout << "Network ID: " << network_id << endl;
    cout << "Host ID: " << host_id << endl;
    cout << "Network class: " << network_class << endl;

    return 0;
}
