#include "smtpclient.h"
#include <iostream>

using namespace jed_utils;
using namespace std;

int main()
{
	std::string smtp_server_address( "smtp.ravenspoint.com");
	SmtpClient client(smtp_server_address.c_str(), 587);
	try
	{
		PlaintextMessage msg(MessageAddress("myfromaddress@test.com", "Test Address Display"),
			MessageAddress("james@ravenspoint.com"),
			"This is a test (Subject)",
			"Hello\nHow are you?");

		int err_no = client.sendMail(msg);
		if (err_no != 0) {
			cout << client.getCommunicationLog() << '\n';
			cerr << "An error occurred. Return code : " << err_no << '\n';
			return 1;
		}
		cout << client.getCommunicationLog() << endl;
		cout << "Operation completed!" << endl;
	}
	catch (invalid_argument &err)
	{
		cerr << err.what() << endl;
	}
    return 0;
}