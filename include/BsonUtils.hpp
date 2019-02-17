#ifndef BSON_BSONUTILS_H
#define BSON_BSONUTILS_H

namespace bsoncpp {
    class BsonUtils {
    public:
        /**
         * Escape json string
         * @param str
         * @return escaped string
         */
        static std::string escapeJson(const std::string& str);
    };
}

#endif
