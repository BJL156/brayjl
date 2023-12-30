#include "utils.hpp"

std::string brayjl::utils::readFile(std::string filepath) {
    std::ifstream file(filepath);
    if (!file.is_open()) {
        BRAYJL_CORE_ERROR("failed to read file: {}", filepath);
        return std::string();
    }

    std::string contents(
        (std::istreambuf_iterator<char>(file)),
        std::istreambuf_iterator<char>()
    );

    file.close();

    return contents;
}