#ifndef BSONCPP_BSONEXCEPTION_H
#define BSONCPP_BSONEXCEPTION_H

#include <stdexcept>

namespace bsoncpp {
    /**
     * BSON Exception
     */
    class BsonException : public std::runtime_error {
    public:
        explicit BsonException(const char *message) : runtime_error(message) {}
        explicit BsonException(const std::string& message) : runtime_error(message) {}
    };
}

#endif

