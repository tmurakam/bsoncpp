#include <sstream>
#include <random>

#include "ObjectId.hpp"

namespace bsoncpp {
    static std::random_device rd;
    static std::mt19937 mt(rd());

    ObjectId::ObjectId() {
        for (uint8_t &i : m_id) {
            i = (uint8_t) (mt() % 0xff);
        }
    }

    ObjectId::ObjectId(const std::string &value) {
        if (value.length() == SIZE * 2) {
            // maybe hex
            for (size_t i = 0; i < SIZE; i++) {
                auto s = value.substr(i * 2, 2);
                auto b = std::stoi(s, nullptr, 16);
                m_id[i] = (uint8_t)(b & 0xff);
            }
        }
        else if (value.length() == SIZE) {
            // raw ASCII
            memcpy(m_id, value.c_str(), ObjectId::SIZE);
        }
        else {
            throw "Illegal ObjectId: " + value;
        }
    }

    ObjectId::ObjectId(const uint8_t *value) {
        memcpy(m_id, value, ObjectId::SIZE);
    }

    std::string ObjectId::hex() {
        std::stringstream ss;
        char buf[3];

        for (uint8_t b : m_id) {
            sprintf(buf, "%02x", b);
            ss << buf;
        }
        return ss.str();
    }

    std::string ObjectId::toJson() {
        return R"({"$oid": ")" + hex() + R"("})";
    }
}
