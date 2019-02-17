#ifndef BSONCPP_BSONARRAY_H
#define BSONCPP_BSONARRAY_H

#include "BsonValues.hpp"

#include <vector>

namespace bsoncpp {

    class BsonArray : public BsonElement {
    public:
        BsonType type() override {
            return BsonType::ARRAY;
        }

        BsonArray() {}

        BsonArray(const BsonArray &array) {
            m_array = array.m_array;
        }

        BsonArray(BsonArray &&array) {
            m_array = std::move(array.m_array);
        }

        BsonArray &operator=(const BsonArray &array) {
            m_array = array.m_array;
            return *this;
        }

        BsonArray &operator=(BsonArray &&array) {
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
        BsonArray &push_back(const T &value) {
            m_array.push_back(BsonElement::create(value));
            return *this;
        }

        BsonArray &asArray() override {
            return *this;
        }

        std::string toJson() override;

    protected:
        std::vector<std::shared_ptr<BsonElement>> m_array;
    };

}


#endif
