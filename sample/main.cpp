#include <iostream>

#include <Bson.hpp>

using bsoncpp::Bson;
using bsoncpp::BsonArray;
using bsoncpp::BsonValue;
using std::cout;
using std::cerr;
using std::endl;
using std::shared_ptr;

int main() {
    Bson bson1;
    bson1.put("a", 1);

    BsonArray ary;
    ary.push_back(123);
    ary.push_back("xxx");

    Bson bson;
    bson
            .put("key1", 12345)
            .put("key2", (int64_t)12345678901234567890UL)
            .put("key3", 123.45678)
            .put("key4", "String")
            .put("key5", true)
            .put("key6", bson1)
            .put("key7", ary);

    cerr << bson.toJson() << endl;

    auto b = bson.getObject("key6");
    b->put("a", 2);

    cerr << bson.toJson() << endl;

    return 0;
}