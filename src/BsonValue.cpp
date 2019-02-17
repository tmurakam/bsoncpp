#include "BsonValue.hpp"
#include "Bson.hpp"
#include "BsonArray.hpp"

using std::unique_ptr;

namespace bsoncpp {
    template<>
    std::shared_ptr<BsonValue> BsonValue::create(int32_t value) {
        return std::make_shared<BsonValueInt32>(value);
    }
    template<>
    std::shared_ptr<BsonValue> BsonValue::create(int64_t value) {
        return std::make_shared<BsonValueInt64>(value);
    }
    template<>
    std::shared_ptr<BsonValue> BsonValue::create(double value) {
        return std::make_shared<BsonValueDouble>(value);
    }
    template<>
    std::shared_ptr<BsonValue> BsonValue::create(bool value) {
        return std::make_shared<BsonValueBool>(value);
    }
    template<>
    std::shared_ptr<BsonValue> BsonValue::create(std::string value) {
        return std::make_shared<BsonValueString>(value);
    }
    template<>
    std::shared_ptr<BsonValue> BsonValue::create(const char * value) {
        return std::make_shared<BsonValueString>(value);
    }

    template<>
    std::shared_ptr<BsonValue> BsonValue::create(std::shared_ptr<Bson> value) {
        return std::make_shared<BsonValueObject>(value);
    }
    template<>
    std::shared_ptr<BsonValue> BsonValue::create(Bson value) {
        return std::make_shared<BsonValueObject>(std::make_shared<Bson>(value)); // copy Bson
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
    BsonType BsonValue::typeOf(const bool &value) {
        return BsonType::BOOL;
    }
    template<>
    BsonType BsonValue::typeOf(const std::string &value) {
        return BsonType::STRING;
    }
    template<>
    BsonType BsonValue::typeOf(const std::shared_ptr<Bson>& value) {
        return BsonType::OBJECT;
    }
    template<>
    BsonType BsonValue::typeOf(const std::shared_ptr<BsonArray>& value) {
        return BsonType::ARRAY;
    }

    // TODO:


    /**
     * BsonObject
     */
    BsonValueObject::BsonValueObject(const Bson& value) : BsonValueBase() {
        m_value = std::make_shared<Bson>(value); // copy
    }

    std::string BsonValueObject::toJson() {
        return m_value->toJson();
    }

    /**
     * Bson array
     */
    BsonValueArray::BsonValueArray(const BsonArray& value) : BsonValueBase() {
        m_value = std::make_shared<BsonArray>(value); // copy
    }

    std::string BsonValueArray::toJson() {
        return m_value->toJson();
    }
}