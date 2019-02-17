#include "Bson.hpp"

namespace bsoncpp {
    std::string Bson::toJson() {
        std::string s = "{";

        bool isFirst = true;
        for (auto it = m_map.begin(); it != m_map.end(); it++) {
            if (isFirst) {
                isFirst = false;
            } else {
                s += ", ";
            }

            auto key = it->first;
            auto value = it->second;

            s += "\"";
            s += key; // TODO: no json escape!
            s += "\": ";
            s += value->toJson();
        }

        s += "}";
        return s;
    }
}