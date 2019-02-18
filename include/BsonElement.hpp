#ifndef BSONCPP_BSONELEMENT_H
#define BSONCPP_BSONELEMENT_H

#include <iostream>
#include <memory>
#include <vector>

#include "BsonException.hpp"

namespace bsoncpp {
    class Document;
    class BsonArray;
    class ObjectId;

    /**
     * Bson Type
     */
    enum class BsonType : int {
        INT32,    /**< 32bit integer */
        INT64,    /**< 64bit integer */
        DOUBLE,   /**< double */
        STRING,   /**< String */
        BOOL,     /**< Boolean */
        DOCUMENT, /**< BSON Document */
        ARRAY,    /**< Array */
        BINARY,   /**< binary */
        OID       /**< Object Id */
    };

    /**
     * Bson Element.
     */
    class BsonElement {
    public:
        virtual BsonType type() = 0;

        bool isInt32() {
            return type() == BsonType::INT32;
        }

        bool isInt64() {
            return type() == BsonType::INT64;
        }

        bool isDouble() {
            return type() == BsonType::DOUBLE;
        }

        bool isNumber() {
            return isInt32() || isInt64() || isDouble();
        }

        bool isBool() {
            return type() == BsonType::BOOL;
        }

        bool isString() {
            return type() == BsonType::STRING;
        }

        bool isDocument() {
            return type() == BsonType::DOCUMENT;
        }

        bool isArray() {
            return type() == BsonType::ARRAY;
        }

        bool isObjectId() {
            return type() == BsonType::OID;
        }


        virtual int32_t asInt32() {
            throw BsonException("Not INT32");
        }

        virtual int64_t asInt64() {
            throw BsonException("Not INT64");
        }

        virtual double asDouble() {
            throw BsonException("Not DOUBLE");
        }

        virtual bool asBool() {
            throw BsonException("Not BOOL");
        }

        virtual std::string& asString() {
            throw BsonException("Not String");
        }

        virtual Document& asDocument() {
            throw BsonException("Not Document");
        }

        virtual BsonArray& asArray() {
            throw BsonException("Not ARRAY");
        }

        virtual std::vector<uint8_t>& asBinary() {
            throw BsonException("Not BINARY");
        }

        virtual ObjectId& asObjectId() {
            throw BsonException("Not ObjectID");
        }

        static std::shared_ptr<BsonElement> create(int32_t value);
        static std::shared_ptr<BsonElement> create(int64_t value);
        static std::shared_ptr<BsonElement> create(double value);
        static std::shared_ptr<BsonElement> create(bool value);

        static std::shared_ptr<BsonElement> create(const std::string &value); // copy
        static std::shared_ptr<BsonElement> create(std::string &&value); // move
        static std::shared_ptr<BsonElement> create(const char *value); // copy

        static std::shared_ptr<BsonElement> create(const Document &value); // copy
        static std::shared_ptr<BsonElement> create(Document &&value); // move

        static std::shared_ptr<BsonElement> create(const BsonArray &value); // copy
        static std::shared_ptr<BsonElement> create(BsonArray &&value); // move

        static std::shared_ptr<BsonElement> create(const std::vector<uint8_t>& value); // copy
        static std::shared_ptr<BsonElement> create(std::vector<uint8_t>&& value); // move
        static std::shared_ptr<BsonElement> create(const uint8_t *ptr, size_t len); // copy

        static std::shared_ptr<BsonElement> create(const ObjectId& value);

        virtual std::string toJson() = 0;
    };

}


#endif //BSON_BSONELEMENT_H
