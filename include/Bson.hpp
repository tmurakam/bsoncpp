#ifndef BSON_BSON_H
#define BSON_BSON_H

#include <unordered_map>

#include "BsonValue.hpp"

namespace bsoncpp {
    /**
     * BSON Object
     */
    class Bson {
    public:
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
        Bson& operator=(const Bson& bson) noexcept {
            m_map = bson.m_map;
            return *this;
        }

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


        std::shared_ptr<BsonValue> get(std::string key) {
            return m_map[key];
        }

        bool hasKey(std::string key) {
            return m_map.find(key) != m_map.end();
        }

        std::string toJson();

    protected:
        std::unordered_map<std::string, std::shared_ptr<BsonValue>> m_map;
    };
}


#endif //BSON_BSON_H
