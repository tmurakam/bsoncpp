#include <iostream>

#include <Bson.hpp>
#include <BsonValue.hpp>

using bsoncpp::Bson;
using bsoncpp::BsonValue;
using std::cout;
using std::cerr;
using std::endl;
using std::unique_ptr;

int main() {
    unique_ptr<BsonValue> v = BsonValue::create<int32_t>(1);

    cerr << v->getInt32() << endl;

    return 0;
}