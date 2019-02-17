#include <string>
#include <sstream>

#include "BsonUtils.hpp"

namespace bsoncpp {
    std::string BsonUtils::escapeJson(const std::string &str) {
        std::ostringstream ss;
        for (char it : str) {
            switch (it) {
                case '\\':
                    ss << "\\\\";
                    break;
                case '"':
                    ss << "\\\"";
                    break;
                case '/':
                    ss << "\\/";
                    break;
                case '\b':
                    ss << "\\b";
                    break;
                case '\f':
                    ss << "\\f";
                    break;
                case '\n':
                    ss << "\\n";
                    break;
                case '\r':
                    ss << "\\r";
                    break;
                case '\t':
                    ss << "\\t";
                    break;
                default:
                    ss << it;
                    break;
            }
        }
        return ss.str();
    }
}
