#ifndef BSONCPP_BSONELEMENT_H
#define BSONCPP_BSONELEMENT_H

#include <iostream>
#include <vector>

namespace bsoncpp {
    class Document;
    class BsonArray;

    /**
     * Bson Type
     */
    enum class BsonType : int {
        /** 32bit integer */
                INT32,
        /** 64bit integer */
                INT64,
        /** double */
                DOUBLE,
        /** String */
                STRING,
        /** Boolean */
                BOOL,
        /** BSON Document */
                DOCUMENT,
        /** Array */
                ARRAY,
        /** binary */
                BINARY
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


        virtual int32_t asInt32() {
            throw "Not INT32";
        }

        virtual int64_t asInt64() {
            throw "Not INT64";
        }

        virtual double asDouble() {
            throw "Not DOUBLE";
        }

        virtual bool asBool() {
            throw "Not BOOL";
        }

        virtual std::string& asString() {
            throw "Not String";
        }

        virtual std::vector<uint8_t>& asBinary() {
            throw "Not BINARY";
        }

        virtual Document& asDocument() {
            throw "Not BSON Object";
        }

        virtual BsonArray& asArray() {
            throw "Not ARRAY of BSON Object";
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

        virtual std::string toJson() = 0;
    };

}


#endif //BSON_BSONELEMENT_H
