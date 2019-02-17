#include "BsonElement.hpp"
#include "BsonValues.hpp"
#include "Document.hpp"
#include "ObjectId.hpp"

namespace bsoncpp {

    std::shared_ptr<BsonElement> BsonElement::create(int32_t value) {
        return std::make_shared<BsonInt32>(value);
    }

    std::shared_ptr<BsonElement> BsonElement::create(int64_t value) {
        return std::make_shared<BsonInt64>(value);
    }

    std::shared_ptr<BsonElement> BsonElement::create(double value) {
        return std::make_shared<BsonDouble>(value);
    }

    std::shared_ptr<BsonElement> BsonElement::create(bool value) {
        return std::make_shared<BsonBool>(value);
    }

    std::shared_ptr<BsonElement> BsonElement::create(const std::string &value) {
        return std::make_shared<BsonString>(value);
    }

    std::shared_ptr<BsonElement> BsonElement::create(std::string &&value) {
        return std::make_shared<BsonString>(std::move(value));
    }

    std::shared_ptr<BsonElement> BsonElement::create(const char *value) {
        return std::make_shared<BsonString>(value);
    }

    std::shared_ptr<BsonElement> BsonElement::create(const Document &value) {
        return std::make_shared<Document>(value);
    }

    std::shared_ptr<BsonElement> BsonElement::create(Document &&value) {
        return std::make_shared<Document>(std::move(value));
    }

    std::shared_ptr<BsonElement> BsonElement::create(const BsonArray &value) {
        return std::make_shared<BsonArray>(value);
    }

    std::shared_ptr<BsonElement> BsonElement::create(BsonArray &&value) {
        return std::make_shared<BsonArray>(std::move(value));
    }

    std::shared_ptr<BsonElement> BsonElement::create(const std::vector<uint8_t>& value) {
        return std::make_shared<BsonBinary>(value);
    }

    std::shared_ptr<BsonElement> BsonElement::create(std::vector<uint8_t>&& value) {
        return std::make_shared<BsonBinary>(std::move(value));
    }

    std::shared_ptr<BsonElement> BsonElement::create(const uint8_t *ptr, size_t len) {
        return std::make_shared<BsonBinary>(std::vector<uint8_t>(ptr, ptr + len));
    }

    std::shared_ptr<BsonElement> BsonElement::create(const ObjectId &value) {
        return std::make_shared<ObjectId>(value);
    }
}