#ifndef BSON_BSONUTILS_H
#define BSON_BSONUTILS_H

namespace bsoncpp {
    class BsonUtils {
    public:
        static std::string escapeJson(const std::string& str);
    };
}

#endif
