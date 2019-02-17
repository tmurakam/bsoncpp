#ifndef BSON_BSONVALUE_H
#define BSON_BSONVALUE_H

#include <iostream>
#include <vector>

namespace bsoncpp {
    class Bson;

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
        /** binary */
        BINARY,
        /** BSON Object */
        OBJECT,
        /** Array of BSON object */
        ARRAY
    };

    /**
     * BSON value
     */
    class BsonValue {
    public:
        /**
         * Get value type
         * @return type
         */
        BsonType type() {
            return m_type;
        }

        /**
         * Create BsonValue
         * @tparam T type
         * @param value value
         * @return BsonValue
         */
        template<typename T>
        static std::unique_ptr<BsonValue> create(T value);

        /**
         * Get type of value
         * @tparam T type parameter
         * @param x value
         * @return BsonType
         */
        template<typename T>
        BsonType typeOf(const T& value);

        virtual int32_t getInt32() {
            throw "Not INT32";
        }

        virtual int64_t getInt64() {
            throw "Not INT64";
        }

        virtual double getDouble() {
            throw "Not DOUBLE";
        }

        virtual std::string& getString() {
            throw "Not String";
        }

        virtual std::vector<uint8_t>& getBinary() {
            throw "Not BINARY";
        }

        virtual Bson& getObject() {
            throw "Not BSON Object";
        }

        virtual std::vector<Bson>& getArray() {
            throw "Not ARRAY of BSON Object";
        }

    protected:
        /** Bson Type */
        BsonType m_type;
    };

    template<typename T>
    class BsonValueBase : public BsonValue {
    public:
        // default ctor
        BsonValueBase() {
            m_type = typeOf(m_value);
        }

        // copy ctor
        BsonValueBase(const T &value) {
            m_value = value;
            m_type = typeOf(value);
        }

        // move ctor
        BsonValueBase(T &&value) {
            m_value = std::move(value);
            m_type = value.m_type;
        }

        // copy operator
        BsonValueBase& operator=(const BsonValueBase& value) {
            m_value = value.get();
            m_type = value.type();
        }

        // move operator
        BsonValueBase& operator=(BsonValueBase&& value) {
            m_value = std::move(value.get());
            m_type = value.type();
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

        int32_t getInt32() override {
            return m_value;
        }

        int64_t getInt64() override {
            return m_value;
        }

        double getDouble() override {
            return m_value;
        }
    };

    /*
    class BsonValueString : public BsonValue<std::string> {
    public:
    };

    class BsonValueBinary : public BsonValue<std::vector<uint8_t>> {
    public:
    };
     */

}

#endif //BSON_BSONVALUE_H
