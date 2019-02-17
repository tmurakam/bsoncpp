#ifndef BSONCPP_OBJECTID_H
#define BSONCPP_OBJECTID_H

#include "BsonElement.hpp"

namespace bsoncpp {
    class ObjectId : public BsonElement {
    public:
        ObjectId();
        explicit ObjectId(const std::string& value);
        explicit ObjectId(const uint8_t* value);

        BsonType type() override {
            return BsonType::OID;
        }

        ObjectId& asObjectId() override {
            return *this;
        }

        std::string hex();

        std::string toJson() override;

        constexpr static int SIZE = 12;

    private:
        uint8_t m_id[SIZE];
    };
}

#endif
