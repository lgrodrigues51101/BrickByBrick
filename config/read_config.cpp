#include <fstream>
#include <iostream>
#include <read_config.hpp>
#include <sstream>

std::vector<ServerInfo> read_server_config(const std::string &filename) {
    std::vector<ServerInfo> servers;
    std::ifstream file(filename);
    if (!file.is_open()) {
        std::cerr << "Error: Could not open file " << filename << std::endl;
        return servers;
    }

    std::string line;
    while (std::getline(file, line)) {
        if (line.empty() || line[0] == '#') continue;  // Skip empty lines and comments

        std::stringstream ss(line);
        std::string segment;

        std::string id_str, address, port_str;

        if (std::getline(ss, segment, ':')) {
            id_str = segment;
        } else {
            std::cerr << "Warning: Invalid server id: " << line << std::endl;
            continue;
        }

        if (std::getline(ss, segment, ':')) {
            address = segment;
        } else {
            std::cerr << "Warning: Invalid server address: " << line << std::endl;
            continue;
        }

        if (std::getline(ss, segment, ':')) {
            port_str = segment;
        } else {
            std::cerr << "Warning: Invalid server port: " << line << std::endl;
            continue;
        }

        try {
            servers.emplace_back(stoi(id_str), address, stoi(port_str));
        } catch (const std::invalid_argument &e) {
            std::cerr << "Error: Invalid number format (ID or Port) on line: " << line << std::endl;
        } catch (const std::out_of_range &e) {
            std::cerr << "Error: Number out of range on line: " << line << std::endl;
        }
    }

    file.close();
    return servers;
}

std::vector<ServerInfo> read_server_config() { return read_server_config("config/host.config"); }