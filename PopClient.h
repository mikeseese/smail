#ifdef SMAIL_POPCLIENT_H
#define SMAIL_POPCLIENT_H

#include <string>

#include <boost/asio.hpp>

using namespace std;
using boost::asio::ip::tcp;

namespace smail {

    class PopClient {

    public:
        PopClient();

        void Init();

        void Connect(string host);
        void Connect(string host, bool is_name);
        void Connect(string host, bool is_name, bool ssl);
        void Connect(string host, bool is_name, bool ssl, int port);

        void Login(string user, string pass);

        unsigned int NumUnread();

        void Retrieve();
        void Retrieve(int num);

        string GetMessageText();

        string GetMessage();

        string GetFrom();

        bool Delete();
        bool Delete(int num);

        bool Status();
        
        void Close();

    private:
        tcp::socket socket;
        string current_message;
        bool debug;

    };

}

#endif