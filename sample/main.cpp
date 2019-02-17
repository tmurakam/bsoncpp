#include <iostream>

#include <Bson.hpp>
#include <BsonValue.hpp>

using bsoncpp::Bson;
using bsoncpp::BsonValue;
using std::cout;
using std::cerr;
using std::endl;
using std::shared_ptr;

int main() {
    Bson bson1;
    bson1.put("a", 1);

    Bson bson;
    bson
            .put("key1", 12345)
            .put("key2", (int64_t)12345678901234567890UL)
            .put("key3", 123.45678)
            .put("key4", "String")
            .put("key5", true)
            .put("key6", bson1); //std::make_shared<Bson>(bson1));

    cerr << bson.toJson() << endl;

    return 0;
}