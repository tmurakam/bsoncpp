#include "Document.hpp"
#include "BsonUtils.hpp"

namespace bsoncpp {
    std::string Document::toJson() {
        std::string s = "{";

        bool isFirst = true;
        for (auto &e : m_map) {
            if (isFirst) {
                isFirst = false;
            } else {
                s += ", ";
            }

            auto key = e.first;
            auto value = e.second;

            s += "\"";
            s += BsonUtils::escapeJson(key);
            s += "\": ";
            s += value->toJson();
        }

        s += "}";
        return s;
    }

}