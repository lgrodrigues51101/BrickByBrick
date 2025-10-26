#ifndef READ_CONFIG
#define READ_CONFIG

#include <string>
#include <vector>

class ServerInfo {
   public:
    int id;
    std::string address;
    int port;
    ServerInfo(const int server_id, const std::string &server_address, const int server_port) : id(server_id), address(server_address), port(server_port) {}
};

std::vector<ServerInfo> read_server_config();
std::vector<ServerInfo> read_server_config(const std::string &filename);

#endif  // READ_CONFIG