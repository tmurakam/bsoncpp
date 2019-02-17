#include <iostream>

#include <Bson.hpp>

using bsoncpp::Document;
using bsoncpp::BsonArray;
using bsoncpp::ObjectId;
using std::cout;
using std::cerr;
using std::endl;
using std::shared_ptr;

int main() {
    Document bson1;
    bson1.put("a", 1);

    BsonArray ary;
    ary.push_back(123);
    ary.push_back("xxx");
    ary.push_back(bson1);

    ObjectId oid;

    Document bson;
    bson
            .put("key1", 12345)
            .put("key2", (int64_t)12345678901234567890UL)
            .put("key3", 123.45678)
            .put("key4", "String")
            .put("key5", true)
            .put("key6", bson1)
            .put("key7", ary)
            .put("key8", oid);

    cerr << bson.toJson() << endl;

    Document& b = bson.getDocument("key6");
    b.put("a", 2);

    cerr << bson.toJson() << endl;

    return 0;
}