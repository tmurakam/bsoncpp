#ifndef BSON_BSONVALUE_H
#define BSON_BSONVALUE_H

#include <iostream>
#include <vector>

namespace bsoncpp {
    class Bson;
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
        static std::shared_ptr<BsonValue> create(T value);

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

        virtual bool getBool() {
            throw "Not BOOL";
        }

        virtual std::string& getString() {
            throw "Not String";
        }

        virtual std::vector<uint8_t>& getBinary() {
            throw "Not BINARY";
        }

        virtual std::shared_ptr<Bson> getObject() {
            throw "Not BSON Object";
        }

        virtual std::shared_ptr<BsonArray> getArray() {
            throw "Not ARRAY of BSON Object";
        }

        virtual std::string toJson() = 0;

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
        BsonValueBase(const BsonValueBase& other) {
            m_value = other.m_value;
            m_type = other.m_type;
        }

        // move ctor
        BsonValueBase(BsonValueBase &&other) {
            m_value = std::move(other.m_type);
            m_type = other.m_type;
        }

        // copy operator
        BsonValueBase& operator=(const BsonValueBase& value) {
            m_value = value.get();
            m_type = value.type();
        }

        // move operator
        BsonValueBase& operator=(BsonValueBase&& value) noexcept {
            m_value = std::move(value.get());
            m_type = value.type();
        }

        // ctor with init value
        BsonValueBase(const T &value) {
            m_value = value;
            m_type = typeOf(value);
        }

        // move value ctor
        BsonValueBase(T &&value) {
            m_value = std::move(value);
            m_type = value.m_type;
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

        std::string toJson() override {
            return std::to_string(m_value);
        }
    };

    class BsonValueInt64 : public BsonValueBase<int64_t> {
    public:
        BsonValueInt64() {}
        BsonValueInt64(int64_t value) : BsonValueBase(value) {}

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

        virtual std::shared_ptr<BsonArray> getArray() override {
            return m_value;
        }

        std::string toJson() override;
    };
}

#endif //BSON_BSONVALUE_H
