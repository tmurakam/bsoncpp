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
        Document() {}

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
        Document &put(std::string key, const T &value) {
            m_map[key] = BsonElement::create(value);
            return *this;
        }

        Document &put(std::string key, const std::shared_ptr<BsonElement> &value) {
            m_map[key] = value;
            return *this;
        }

        bool contains(const std::string &key) {
            return m_map.find(key) != m_map.end();
        }

        std::shared_ptr<BsonElement> get(std::string key) {
            return m_map[key];
        }

        int32_t getInt32(const std::string &key) {
            return m_map[key]->asInt32();
        }

        int64_t getInt64(const std::string &key) {
            return m_map[key]->asInt64();
        }

        double getDouble(const std::string &key) {
            return m_map[key]->asDouble();
        }

        bool getBool(const std::string &key) {
            return m_map[key]->asBool();
        }

        std::string &getString(const std::string &key) {
            return m_map[key]->asString();
        }

        Document& getDocument(const std::string &key) {
            return m_map[key]->asDocument();
        }

        BsonArray& getArray(const std::string &key) {
            return m_map[key]->asArray();
        }

        std::vector<uint8_t> getBinary(const std::string &key) {
            return m_map[key]->asBinary();
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
