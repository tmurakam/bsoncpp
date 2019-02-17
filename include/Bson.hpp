#ifndef BSON_BSON_H
#define BSON_BSON_H

#include <unordered_map>

#include "BsonElement.hpp"
#include "BsonValue.hpp"
#include "BsonArray.hpp"

namespace bsoncpp {

/**
 * BSON Object
 */
class Bson : public BsonElement {
public:
    BsonType type() override {
        return BsonType::OBJECT;
    }

    /**
     * Default constructor.
     */
    Bson() {}

    /**
     * Copy constructor.
     * Shallow copy unordered map.
     * @param bson
     */
    Bson(const Bson& bson) {
        m_map = bson.m_map;
    }

    /**
     * Move constructor.
     * @param bson
     */
    Bson(Bson&& bson) noexcept {
        m_map = std::move(bson.m_map);
    }

    /**
     * Assign operator.
     * Do shallow copy of internal unordered map.
     * @param bson
     * @return this
     */
    Bson& operator=(const Bson& bson) = default;

    /**
     * Move assign operator
     * @param bson
     * @return this
     */
    Bson& operator=(Bson&& bson) noexcept {
        m_map = std::move(bson.m_map);
        return *this;
    }

    /**
     * Put value to Bson object
     *
     * @tparam T type parameter
     * @param key Key
     * @param value Value
     * @return this
     */
    template<typename T>
    Bson& put(std::string key, const T& value) {
        m_map[key] = BsonValue::create(value);
        return *this;
    }

    Bson& put(std::string key, const std::shared_ptr<BsonValue>& value) {
        m_map[key] = value;
        return *this;
    }

    // special case
    Bson& put(std::string key, const Bson& bson) {
        m_map[key] = std::make_shared<BsonValueObject>(bson);
        return *this;
    }

    Bson& put(std::string key, const BsonArray& ary) {
        m_map[key] = std::make_shared<BsonValueArray>(ary);
        return *this;
    }

    bool contains(const std::string& key) {
        return m_map.find(key) != m_map.end();
    }

    std::shared_ptr<BsonValue> get(std::string key) {
        return m_map[key];
    }

    int32_t getInt32(const std::string& key) {
        return m_map[key]->getInt32();
    }

    int64_t getInt64(const std::string& key) {
        return m_map[key]->getInt64();
    }

    double getDouble(const std::string& key) {
        return m_map[key]->getDouble();
    }

    bool getBool(const std::string& key) {
        return m_map[key]->getBool();
    }

    std::string& getString(const std::string& key) {
        return m_map[key]->getString();
    }

    std::shared_ptr<Bson> getObject(const std::string& key) {
        return m_map[key]->getObject();
    }

    std::vector<uint8_t> getBinary(const std::string& key) {
        return m_map[key]->getBinary();
    }

    std::string toJson() override;

protected:
    std::unordered_map<std::string, std::shared_ptr<BsonValue>> m_map;
};

}

#endif //BSON_BSON_H
