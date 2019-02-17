#include "BsonArray.hpp"
#include "Document.hpp"

namespace bsoncpp {

    std::string BsonArray::toJson() {
        std::string s = "[";

        bool isFirst = true;
        for (auto& e : m_array) {
            if (isFirst) {
                isFirst = false;
            } else {
                s += ", ";
            }

            s += e->toJson();
        }

        s += "]";
        return s;
    }

}