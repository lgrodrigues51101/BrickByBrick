#include <iostream>
#include <ostream>
#include <read_config.hpp>
#include <vector>

int main(int argc, char const *argv[]) {
    std::vector<ServerInfo> config = read_server_config();

    for (size_t i = 0; i < config.size(); i++) {
        std::cout << "Server ID: " << config[i].id << ", Address: " << config[i].address << ", Port: " << config[i].port << std::endl;
    }

    return 0;
}
