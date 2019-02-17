#ifndef BSONCPP_OBJECTID_H
#define BSONCPP_OBJECTID_H

#include "BsonElement.hpp"

namespace bsoncpp {
    class ObjectId : public BsonElement {
    public:
        /**
         * Generate random ObjectId.
         */
        ObjectId();

        /**
         * Create ObjectId from string.
         * If string length == 24, it is treated as hex string.
         * If string length == 12, it is treated as raw ascii binary.
         * Otherwise, throws BsonException.
         * @param value
         */
        explicit ObjectId(const std::string& value);

        /**
         * Create ObjectId from binary.
         * It length must be 12.
         * @param value
         */
        explicit ObjectId(const uint8_t* value);

        BsonType type() override {
            return BsonType::OID;
        }

        ObjectId& asObjectId() override {
            return *this;
        }

        /**
         * Return hex string representation.
         * @return
         */
        std::string hex();

        std::string toJson() override;

        constexpr static int SIZE = 12;

    private:
        uint8_t m_id[SIZE];
    };
}

#endif
