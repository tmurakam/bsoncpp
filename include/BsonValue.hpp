#ifndef BSON_BSONVALUE_H
#define BSON_BSONVALUE_H

#include <iostream>
#include <vector>

#include "BsonElement.hpp"

namespace bsoncpp {
    class Bson;
    class BsonArray;


    /**
     * BSON value
     */
    class BsonValue : public BsonElement {
    public:
        /**
         * Create BsonValue
         * @tparam T type
         * @param value value
         * @return BsonValue
         */
        template<typename T>
        static std::shared_ptr<BsonValue> create(T value);

        /**
         * Get type of value
         * @tparam T type parameter
         * @param x value
         * @return BsonType
         */
        template<typename T>
        BsonType typeOf(const T& value);
    };

    template<typename T>
    class BsonValueBase : public BsonValue {
    public:
        // default ctor
        BsonValueBase() {
        }

        // copy ctor
        BsonValueBase(const BsonValueBase& other) {
            m_value = other.m_value;
        }

        // move ctor
        BsonValueBase(BsonValueBase &&other) {
            m_value = std::move(other.m_type);
        }

        // copy operator
        BsonValueBase& operator=(const BsonValueBase& value) {
            m_value = value.get();
        }

        // move operator
        BsonValueBase& operator=(BsonValueBase&& value) noexcept {
            m_value = std::move(value.get());
        }

        // ctor with init value
        BsonValueBase(const T &value) {
            m_value = value;
        }

        // move value ctor
        BsonValueBase(T &&value) {
            m_value = std::move(value);
        }

        /**
         * Get value
         * @return value
         */
        T& get() const noexcept {
            return m_value;
        }

    protected:
        /** value */
        T m_value;
    };

    class BsonValueInt32 : public BsonValueBase<int32_t> {
    public:
        BsonValueInt32() {}
        BsonValueInt32(int32_t value) : BsonValueBase(value) {}

        BsonType type() override {
            return BsonType::INT32;
        }

        int32_t getInt32() override {
            return m_value;
        }

        int64_t getInt64() override {
            return m_value;
        }

        double getDouble() override {
            return m_value;
        }

        std::string toJson() override {
            return std::to_string(m_value);
        }
    };

    class BsonValueInt64 : public BsonValueBase<int64_t> {
    public:
        BsonValueInt64() {}
        BsonValueInt64(int64_t value) : BsonValueBase(value) {}

        BsonType type() override {
            return BsonType::INT64;
        }

        int32_t getInt32() override {
            return m_value;
        }

        int64_t getInt64() override {
            return m_value;
        }

        double getDouble() override {
            return m_value;
        }

        std::string toJson() override {
            return std::to_string(m_value);
        }
    };

    class BsonValueDouble : public BsonValueBase<double> {
    public:
        BsonValueDouble() {}
        BsonValueDouble(double value) : BsonValueBase(value) {}

        BsonType type() override {
            return BsonType::DOUBLE;
        }

        int32_t getInt32() override {
            return m_value;
        }

        int64_t getInt64() override {
            return m_value;
        }

        double getDouble() override {
            return m_value;
        }

        std::string toJson() override {
            return std::to_string(m_value);
        }
    };

    class BsonValueBool : public BsonValueBase<bool> {
    public:
        BsonValueBool() {}
        BsonValueBool(bool value) : BsonValueBase(value) {}

        BsonType type() override {
            return BsonType::BOOL;
        }

        bool getBool() override {
            return m_value;
        }

        std::string toJson() override {
            return m_value ? "true" : "false";
        }
    };

    class BsonValueString : public BsonValueBase<std::string> {
    public:
        BsonValueString() {}
        BsonValueString(std::string value) : BsonValueBase(value) {}

        BsonType type() override {
            return BsonType::STRING;
        }

        std::string& getString() override {
            return m_value;
        }

        std::string toJson() override {
            return "\"" + m_value + "\""; // TODO: no json escape
        }
    };

    class BsonValueObject : public BsonValueBase<std::shared_ptr<Bson>> {
    public:
        BsonValueObject() {}
        BsonValueObject(std::shared_ptr<Bson> value) : BsonValueBase(value) {}
        BsonValueObject(const Bson& value); // copy!

        BsonType type() override {
            return BsonType::OBJECT;
        }

        virtual std::shared_ptr<Bson> getObject() override {
            return m_value;
        }

        std::string toJson() override;
    };

    class BsonValueArray : public BsonValueBase<std::shared_ptr<BsonArray>> {
    public:
        BsonValueArray() {}
        BsonValueArray(std::shared_ptr<BsonArray> value) : BsonValueBase(value) {}
        BsonValueArray(const BsonArray& value); // copy!

        BsonType type() override {
            return BsonType::ARRAY;
        }

        virtual std::shared_ptr<BsonArray> getArray() override {
            return m_value;
        }

        std::string toJson() override;
    };
}

#endif //BSON_BSONVALUE_H
