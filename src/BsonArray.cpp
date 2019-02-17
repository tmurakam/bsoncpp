#include "BsonArray.hpp"
#include "Document.hpp"

namespace bsoncpp {

    std::string BsonArray::toJson() {
        std::string s = "[";

        bool isFirst = true;
        for (auto it = m_array.begin(); it != m_array.end(); it++) {
            if (isFirst) {
                isFirst = false;
            } else {
                s += ", ";
            }

            auto val = *it;
            s += val->toJson();
        }

        s += "]";
        return s;
    }

}