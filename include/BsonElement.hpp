//
// Created by 村上 卓弥 on 2019-02-17.
//

#ifndef BSON_BSONELEMENT_H
#define BSON_BSONELEMENT_H

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

class BsonElement {
public:
    virtual BsonType type() = 0;

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
};

}


#endif //BSON_BSONELEMENT_H
