#ifndef BSONCPP_BSONVALUE_H
#define BSONCPP_BSONVALUE_H

#include <iostream>
#include <vector>

#include "BsonElement.hpp"
#include "BsonUtils.hpp"

namespace bsoncpp {
    class BsonInt32 : public BsonElement {
    public:
        BsonInt32() : m_value(0) {}

        explicit BsonInt32(int32_t value) : m_value(value) {}

        BsonType type() override {
            return BsonType::INT32;
        }

        int32_t asInt32() override {
            return m_value;
        }

        int64_t asInt64() override {
            return m_value;
        }

        double asDouble() override {
            return m_value;
        }

        std::string toJson() override {
            return std::to_string(m_value);
        }

    private:
        const int32_t m_value;
    };

    class BsonInt64 : public BsonElement {
    public:
        BsonInt64() : m_value(0) {}

        explicit BsonInt64(int64_t value) : m_value(value) {}

        BsonType type() override {
            return BsonType::INT64;
        }

        int32_t asInt32() override {
            return m_value;
        }

        int64_t asInt64() override {
            return m_value;
        }

        double asDouble() override {
            return m_value;
        }

        std::string toJson() override {
            return std::to_string(m_value);
        }

    private:
        const int64_t m_value;
    };

    class BsonDouble : public BsonElement {
    public:
        BsonDouble() : m_value() {}

        explicit BsonDouble(double value) : m_value(value) {}

        BsonType type() override {
            return BsonType::DOUBLE;
        }

        int32_t asInt32() override {
            return m_value;
        }

        int64_t asInt64() override {
            return m_value;
        }

        double asDouble() override {
            return m_value;
        }

        std::string toJson() override {
            return std::to_string(m_value);
        }

    private:
        const double m_value;
    };

    class BsonBool : public BsonElement {
    public:
        BsonBool() : m_value(false) {}

        explicit BsonBool(bool value) : m_value(value) {}

        BsonType type() override {
            return BsonType::BOOL;
        }

        bool asBool() override {
            return m_value;
        }

        std::string toJson() override {
            return m_value ? "true" : "false";
        }

    private:
        const bool m_value;
    };

    class BsonString : public BsonElement {
    public:
        BsonString() = default;

        explicit BsonString(std::string value) : m_value(std::move(value)) {}

        BsonType type() override {
            return BsonType::STRING;
        }

        std::string& asString() override {
            return m_value;
        }

        std::string toJson() override {
            return "\"" + BsonUtils::escapeJson(m_value) + "\"";
        }

    private:
        std::string m_value; // not immutable...
    };

    class BsonBinary : public BsonElement {
    public:
        BsonBinary() = default;
        explicit BsonBinary(std::vector<uint8_t> value) : m_value(std::move(value)) {}

        BsonType type() override {
            return BsonType::BINARY;
        }

        std::vector<uint8_t>& asBinary() override {
            return m_value;
        }

        std::string toJson() override {
            throw "Binary toJson not supported!";
        }

    private:
        std::vector<uint8_t> m_value; // not immutable...
    };
}

#endif
