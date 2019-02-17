#ifndef BSON_BSONARRAY_H
#define BSON_BSONARRAY_H

#include "BsonValue.hpp"

#include <vector>

namespace bsoncpp {
    class BsonArray {
    public:
        BsonArray() {}

        BsonArray(const BsonArray& array) {
            m_array = array.m_array;
        }

        BsonArray(BsonArray&& array) {
            m_array = std::move(array.m_array);
        }

        BsonArray& operator=(const BsonArray& array) {
            m_array = array.m_array;
            return *this;
        }

        BsonArray& operator=(BsonArray&& array) {
            m_array = std::move(array.m_array);
            return *this;
        }

        bool empty() {
            return m_array.empty();
        }

        int size() {
            return m_array.size();
        }

        template<typename T>
        BsonArray& push_back(const T& value) {
            m_array.push_back(BsonValue::create(value));
            return *this;
        }

        // special case
        BsonArray& put(std::string key, const Bson& bson) {
            m_array.push_back(std::make_shared<BsonValueObject>(bson));
            return *this;
        }

        std::string toJson();

    protected:
        std::vector<std::shared_ptr<BsonValue>> m_array;
    };
}


#endif //BSON_BSONARRAY_H
