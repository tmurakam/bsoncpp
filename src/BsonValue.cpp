#include "BsonValue.hpp"

using std::unique_ptr;

namespace bsoncpp {
    template<>
    std::unique_ptr<BsonValue> BsonValue::create(int32_t value) {
        return std::unique_ptr<BsonValue>{new BsonValueInt32(value)};
    }

    // TODO:

    template<>
    BsonType BsonValue::typeOf(const int32_t &value) {
        return BsonType::INT32;
    }
    template<>
    BsonType BsonValue::typeOf(const int64_t &value) {
        return BsonType::INT64;
    }
    template<>
    BsonType BsonValue::typeOf(const double &value) {
        return BsonType::DOUBLE;
    }
    template<>
    BsonType BsonValue::typeOf(const std::string &value) {
        return BsonType::STRING;
    }
    // TODO:
}