#ifndef BSONCPP_DOCUMENT_H
#define BSONCPP_DOCUMENT_H

#include <map>

#include "BsonElement.hpp"
#include "BsonValues.hpp"
#include "BsonArray.hpp"

namespace bsoncpp {

    /**
     * BSON Document
     */
    class Document : public BsonElement {
    public:
        /**
         * Get element type
         * @return type
         */
        BsonType type() override {
            return BsonType::DOCUMENT;
        }

        /**
         * Default constructor.
         */
        Document() = default;

        /**
         * Copy constructor.
         * Shallow copy unordered map.
         * @param bson
         */
        Document(const Document& doc) {
            m_map = doc.m_map;
        }

        /**
         * Move constructor.
         * @param bson
         */
        Document(Document&& doc) noexcept {
            m_map = std::move(doc.m_map);
        }

        /**
         * Assign operator.
         * Do shallow copy of internal unordered map.
         * @param bson
         * @return this
         */
        Document &operator=(const Document& doc) = default;

        /**
         * Move assign operator
         * @param bson
         * @return this
         */
        Document &operator=(Document&& doc) noexcept {
            m_map = std::move(doc.m_map);
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
        Document &put(const std::string &key, const T &value) {
            m_map[key] = BsonElement::create(value);
            return *this;
        }

        /**
         * Check if has key?
         * @param key
         * @return
         */
        bool contains(const std::string &key) {
            return m_map.find(key) != m_map.end();
        }

        /**
         * Get element.
         * If no element, return null.
         * @param key
         * @return element ptr
         */
        std::shared_ptr<BsonElement> operator[](const std::string &key) {
            return m_map[key];
        }

        /**
         * Get element.
         * If no element, throw exception.
         * @param key
         * @return element ptr
         * @throws out_of_range No such key
         */
        std::shared_ptr<BsonElement> at(const std::string &key) {
            return m_map.at(key);
        }

        /**
         * Get type of element
         * @param key
         * @return BsonType
         */
        BsonType type(std::string &key) {
            return at(key)->type();
        }

        /**
         * Get int32 value.
         * @param key
         * @return
         * @throws No key or invalid type.
         */
        int32_t getInt32(const std::string &key) {
            return at(key)->asInt32();
        }

        /**
         * Get int64 value.
         * @param key
         * @return
         * @throws No key or invalid type.
         */
        int64_t getInt64(const std::string &key) {
            return at(key)->asInt64();
        }

        /**
         * Get double value.
         * @param key
         * @return
         * @throws No key or invalid type.
         */
        double getDouble(const std::string &key) {
            return at(key)->asDouble();
        }

        /**
         * Get bool value.
         * @param key
         * @return
         * @throws No key or invalid type.
         */
        bool getBool(const std::string &key) {
            return at(key)->asBool();
        }

        /**
         * Get string value.
         * @param key
         * @return
         * @throws No key or invalid type.
        */
        std::string &getString(const std::string &key) {
            return at(key)->asString();
        }

        /**
         * Get document.
         * @param key
         * @return
         * @throws No key or invalid type.
         */
        Document& getDocument(const std::string &key) {
            return at(key)->asDocument();
        }

        /**
         * Get array.
         * @param key
         * @return
         * @throws No key or invalid type.
         */
        BsonArray& getArray(const std::string &key) {
            return at(key)->asArray();
        }

        /**
         * Get binary.
         * @param key
         * @return
         * @throws No key or invalid type.
         */
        std::vector<uint8_t> getBinary(const std::string &key) {
            return at(key)->asBinary();
        }

        /**
         * Get ObjectId.
         * @param key
         * @return
         * @throws No key or invalid type.
         */
        ObjectId& getObjectId(const std::string &key) {
            return at(key)->asObjectId();
        }

        Document& asDocument() override {
            return *this;
        }

        std::string toJson() override;

    protected:
        std::map<std::string, std::shared_ptr<BsonElement>> m_map;
    };

}

#endif //BSON_BSON_H
