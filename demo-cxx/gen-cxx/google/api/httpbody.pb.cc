// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: google/api/httpbody.proto

#include "google/api/httpbody.pb.h"

#include <algorithm>
#include "google/protobuf/io/coded_stream.h"
#include "google/protobuf/extension_set.h"
#include "google/protobuf/wire_format_lite.h"
#include "google/protobuf/descriptor.h"
#include "google/protobuf/generated_message_reflection.h"
#include "google/protobuf/reflection_ops.h"
#include "google/protobuf/wire_format.h"
// @@protoc_insertion_point(includes)

// Must be included last.
#include "google/protobuf/port_def.inc"
PROTOBUF_PRAGMA_INIT_SEG
namespace _pb = ::PROTOBUF_NAMESPACE_ID;
namespace _pbi = ::PROTOBUF_NAMESPACE_ID::internal;
namespace google {
namespace api {
template <typename>
PROTOBUF_CONSTEXPR HttpBody::HttpBody(
    ::_pbi::ConstantInitialized): _impl_{
    /*decltype(_impl_.extensions_)*/{}
  , /*decltype(_impl_.content_type_)*/ {
    &::_pbi::fixed_address_empty_string, ::_pbi::ConstantInitialized {}
  }

  , /*decltype(_impl_.data_)*/ {
    &::_pbi::fixed_address_empty_string, ::_pbi::ConstantInitialized {}
  }

  , /*decltype(_impl_._cached_size_)*/{}} {}
struct HttpBodyDefaultTypeInternal {
  PROTOBUF_CONSTEXPR HttpBodyDefaultTypeInternal() : _instance(::_pbi::ConstantInitialized{}) {}
  ~HttpBodyDefaultTypeInternal() {}
  union {
    HttpBody _instance;
  };
};

PROTOBUF_ATTRIBUTE_NO_DESTROY PROTOBUF_CONSTINIT
    PROTOBUF_ATTRIBUTE_INIT_PRIORITY1 HttpBodyDefaultTypeInternal _HttpBody_default_instance_;
}  // namespace api
}  // namespace google
static ::_pb::Metadata file_level_metadata_google_2fapi_2fhttpbody_2eproto[1];
static constexpr const ::_pb::EnumDescriptor**
    file_level_enum_descriptors_google_2fapi_2fhttpbody_2eproto = nullptr;
static constexpr const ::_pb::ServiceDescriptor**
    file_level_service_descriptors_google_2fapi_2fhttpbody_2eproto = nullptr;
const ::uint32_t TableStruct_google_2fapi_2fhttpbody_2eproto::offsets[] PROTOBUF_SECTION_VARIABLE(
    protodesc_cold) = {
    ~0u,  // no _has_bits_
    PROTOBUF_FIELD_OFFSET(::google::api::HttpBody, _internal_metadata_),
    ~0u,  // no _extensions_
    ~0u,  // no _oneof_case_
    ~0u,  // no _weak_field_map_
    ~0u,  // no _inlined_string_donated_
    ~0u,  // no _split_
    ~0u,  // no sizeof(Split)
    PROTOBUF_FIELD_OFFSET(::google::api::HttpBody, _impl_.content_type_),
    PROTOBUF_FIELD_OFFSET(::google::api::HttpBody, _impl_.data_),
    PROTOBUF_FIELD_OFFSET(::google::api::HttpBody, _impl_.extensions_),
};

static const ::_pbi::MigrationSchema
    schemas[] PROTOBUF_SECTION_VARIABLE(protodesc_cold) = {
        { 0, -1, -1, sizeof(::google::api::HttpBody)},
};

static const ::_pb::Message* const file_default_instances[] = {
    &::google::api::_HttpBody_default_instance_._instance,
};
const char descriptor_table_protodef_google_2fapi_2fhttpbody_2eproto[] PROTOBUF_SECTION_VARIABLE(protodesc_cold) = {
    "\n\031google/api/httpbody.proto\022\ngoogle.api\032"
    "\031google/protobuf/any.proto\"X\n\010HttpBody\022\024"
    "\n\014content_type\030\001 \001(\t\022\014\n\004data\030\002 \001(\014\022(\n\nex"
    "tensions\030\003 \003(\0132\024.google.protobuf.AnyBh\n\016"
    "com.google.apiB\rHttpBodyProtoP\001Z;google."
    "golang.org/genproto/googleapis/api/httpb"
    "ody;httpbody\370\001\001\242\002\004GAPIb\006proto3"
};
static const ::_pbi::DescriptorTable* const descriptor_table_google_2fapi_2fhttpbody_2eproto_deps[1] =
    {
        &::descriptor_table_google_2fprotobuf_2fany_2eproto,
};
static ::absl::once_flag descriptor_table_google_2fapi_2fhttpbody_2eproto_once;
const ::_pbi::DescriptorTable descriptor_table_google_2fapi_2fhttpbody_2eproto = {
    false,
    false,
    270,
    descriptor_table_protodef_google_2fapi_2fhttpbody_2eproto,
    "google/api/httpbody.proto",
    &descriptor_table_google_2fapi_2fhttpbody_2eproto_once,
    descriptor_table_google_2fapi_2fhttpbody_2eproto_deps,
    1,
    1,
    schemas,
    file_default_instances,
    TableStruct_google_2fapi_2fhttpbody_2eproto::offsets,
    file_level_metadata_google_2fapi_2fhttpbody_2eproto,
    file_level_enum_descriptors_google_2fapi_2fhttpbody_2eproto,
    file_level_service_descriptors_google_2fapi_2fhttpbody_2eproto,
};

// This function exists to be marked as weak.
// It can significantly speed up compilation by breaking up LLVM's SCC
// in the .pb.cc translation units. Large translation units see a
// reduction of more than 35% of walltime for optimized builds. Without
// the weak attribute all the messages in the file, including all the
// vtables and everything they use become part of the same SCC through
// a cycle like:
// GetMetadata -> descriptor table -> default instances ->
//   vtables -> GetMetadata
// By adding a weak function here we break the connection from the
// individual vtables back into the descriptor table.
PROTOBUF_ATTRIBUTE_WEAK const ::_pbi::DescriptorTable* descriptor_table_google_2fapi_2fhttpbody_2eproto_getter() {
  return &descriptor_table_google_2fapi_2fhttpbody_2eproto;
}
// Force running AddDescriptors() at dynamic initialization time.
PROTOBUF_ATTRIBUTE_INIT_PRIORITY2
static ::_pbi::AddDescriptorsRunner dynamic_init_dummy_google_2fapi_2fhttpbody_2eproto(&descriptor_table_google_2fapi_2fhttpbody_2eproto);
namespace google {
namespace api {
// ===================================================================

class HttpBody::_Internal {
 public:
};

void HttpBody::clear_extensions() {
  _internal_mutable_extensions()->Clear();
}
HttpBody::HttpBody(::PROTOBUF_NAMESPACE_ID::Arena* arena)
  : ::PROTOBUF_NAMESPACE_ID::Message(arena) {
  SharedCtor(arena);
  // @@protoc_insertion_point(arena_constructor:google.api.HttpBody)
}
HttpBody::HttpBody(const HttpBody& from)
  : ::PROTOBUF_NAMESPACE_ID::Message() {
  HttpBody* const _this = this; (void)_this;
  new (&_impl_) Impl_{
      decltype(_impl_.extensions_){from._impl_.extensions_}
    , decltype(_impl_.content_type_) {}

    , decltype(_impl_.data_) {}

    , /*decltype(_impl_._cached_size_)*/{}};

  _internal_metadata_.MergeFrom<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(from._internal_metadata_);
  _impl_.content_type_.InitDefault();
  #ifdef PROTOBUF_FORCE_COPY_DEFAULT_STRING
        _impl_.content_type_.Set("", GetArenaForAllocation());
  #endif  // PROTOBUF_FORCE_COPY_DEFAULT_STRING
  if (!from._internal_content_type().empty()) {
    _this->_impl_.content_type_.Set(from._internal_content_type(), _this->GetArenaForAllocation());
  }
  _impl_.data_.InitDefault();
  #ifdef PROTOBUF_FORCE_COPY_DEFAULT_STRING
        _impl_.data_.Set("", GetArenaForAllocation());
  #endif  // PROTOBUF_FORCE_COPY_DEFAULT_STRING
  if (!from._internal_data().empty()) {
    _this->_impl_.data_.Set(from._internal_data(), _this->GetArenaForAllocation());
  }
  // @@protoc_insertion_point(copy_constructor:google.api.HttpBody)
}

inline void HttpBody::SharedCtor(::_pb::Arena* arena) {
  (void)arena;
  new (&_impl_) Impl_{
      decltype(_impl_.extensions_){arena}
    , decltype(_impl_.content_type_) {}

    , decltype(_impl_.data_) {}

    , /*decltype(_impl_._cached_size_)*/{}
  };
  _impl_.content_type_.InitDefault();
  #ifdef PROTOBUF_FORCE_COPY_DEFAULT_STRING
        _impl_.content_type_.Set("", GetArenaForAllocation());
  #endif  // PROTOBUF_FORCE_COPY_DEFAULT_STRING
  _impl_.data_.InitDefault();
  #ifdef PROTOBUF_FORCE_COPY_DEFAULT_STRING
        _impl_.data_.Set("", GetArenaForAllocation());
  #endif  // PROTOBUF_FORCE_COPY_DEFAULT_STRING
}

HttpBody::~HttpBody() {
  // @@protoc_insertion_point(destructor:google.api.HttpBody)
  if (auto *arena = _internal_metadata_.DeleteReturnArena<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>()) {
  (void)arena;
    return;
  }
  SharedDtor();
}

inline void HttpBody::SharedDtor() {
  ABSL_DCHECK(GetArenaForAllocation() == nullptr);
  _internal_mutable_extensions()->~RepeatedPtrField();
  _impl_.content_type_.Destroy();
  _impl_.data_.Destroy();
}

void HttpBody::SetCachedSize(int size) const {
  _impl_._cached_size_.Set(size);
}

void HttpBody::Clear() {
// @@protoc_insertion_point(message_clear_start:google.api.HttpBody)
  ::uint32_t cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  _internal_mutable_extensions()->Clear();
  _impl_.content_type_.ClearToEmpty();
  _impl_.data_.ClearToEmpty();
  _internal_metadata_.Clear<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>();
}

const char* HttpBody::_InternalParse(const char* ptr, ::_pbi::ParseContext* ctx) {
#define CHK_(x) if (PROTOBUF_PREDICT_FALSE(!(x))) goto failure
  while (!ctx->Done(&ptr)) {
    ::uint32_t tag;
    ptr = ::_pbi::ReadTag(ptr, &tag);
    switch (tag >> 3) {
      // string content_type = 1;
      case 1:
        if (PROTOBUF_PREDICT_TRUE(static_cast<::uint8_t>(tag) == 10)) {
          auto str = _internal_mutable_content_type();
          ptr = ::_pbi::InlineGreedyStringParser(str, ptr, ctx);
          CHK_(ptr);
          CHK_(::_pbi::VerifyUTF8(str, "google.api.HttpBody.content_type"));
        } else {
          goto handle_unusual;
        }
        continue;
      // bytes data = 2;
      case 2:
        if (PROTOBUF_PREDICT_TRUE(static_cast<::uint8_t>(tag) == 18)) {
          auto str = _internal_mutable_data();
          ptr = ::_pbi::InlineGreedyStringParser(str, ptr, ctx);
          CHK_(ptr);
        } else {
          goto handle_unusual;
        }
        continue;
      // repeated .google.protobuf.Any extensions = 3;
      case 3:
        if (PROTOBUF_PREDICT_TRUE(static_cast<::uint8_t>(tag) == 26)) {
          ptr -= 1;
          do {
            ptr += 1;
            ptr = ctx->ParseMessage(_internal_add_extensions(), ptr);
            CHK_(ptr);
            if (!ctx->DataAvailable(ptr)) break;
          } while (::PROTOBUF_NAMESPACE_ID::internal::ExpectTag<26>(ptr));
        } else {
          goto handle_unusual;
        }
        continue;
      default:
        goto handle_unusual;
    }  // switch
  handle_unusual:
    if ((tag == 0) || ((tag & 7) == 4)) {
      CHK_(ptr);
      ctx->SetLastTag(tag);
      goto message_done;
    }
    ptr = UnknownFieldParse(
        tag,
        _internal_metadata_.mutable_unknown_fields<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(),
        ptr, ctx);
    CHK_(ptr != nullptr);
  }  // while
message_done:
  return ptr;
failure:
  ptr = nullptr;
  goto message_done;
#undef CHK_
}

::uint8_t* HttpBody::_InternalSerialize(
    ::uint8_t* target, ::PROTOBUF_NAMESPACE_ID::io::EpsCopyOutputStream* stream) const {
  // @@protoc_insertion_point(serialize_to_array_start:google.api.HttpBody)
  ::uint32_t cached_has_bits = 0;
  (void) cached_has_bits;

  // string content_type = 1;
  if (!this->_internal_content_type().empty()) {
    const std::string& _s = this->_internal_content_type();
    ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::VerifyUtf8String(
        _s.data(), static_cast<int>(_s.length()), ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::SERIALIZE, "google.api.HttpBody.content_type");
    target = stream->WriteStringMaybeAliased(1, _s, target);
  }

  // bytes data = 2;
  if (!this->_internal_data().empty()) {
    const std::string& _s = this->_internal_data();
    target = stream->WriteBytesMaybeAliased(2, _s, target);
  }

  // repeated .google.protobuf.Any extensions = 3;
  for (unsigned i = 0,
      n = static_cast<unsigned>(this->_internal_extensions_size()); i < n; i++) {
    const auto& repfield = this->_internal_extensions(i);
    target = ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::
        InternalWriteMessage(3, repfield, repfield.GetCachedSize(), target, stream);
  }

  if (PROTOBUF_PREDICT_FALSE(_internal_metadata_.have_unknown_fields())) {
    target = ::_pbi::WireFormat::InternalSerializeUnknownFieldsToArray(
        _internal_metadata_.unknown_fields<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(::PROTOBUF_NAMESPACE_ID::UnknownFieldSet::default_instance), target, stream);
  }
  // @@protoc_insertion_point(serialize_to_array_end:google.api.HttpBody)
  return target;
}

::size_t HttpBody::ByteSizeLong() const {
// @@protoc_insertion_point(message_byte_size_start:google.api.HttpBody)
  ::size_t total_size = 0;

  ::uint32_t cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  // repeated .google.protobuf.Any extensions = 3;
  total_size += 1UL * this->_internal_extensions_size();
  for (const auto& msg : this->_internal_extensions()) {
    total_size +=
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::MessageSize(msg);
  }

  // string content_type = 1;
  if (!this->_internal_content_type().empty()) {
    total_size += 1 + ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::StringSize(
                                    this->_internal_content_type());
  }

  // bytes data = 2;
  if (!this->_internal_data().empty()) {
    total_size += 1 + ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::BytesSize(
                                    this->_internal_data());
  }

  return MaybeComputeUnknownFieldsSize(total_size, &_impl_._cached_size_);
}

const ::PROTOBUF_NAMESPACE_ID::Message::ClassData HttpBody::_class_data_ = {
    ::PROTOBUF_NAMESPACE_ID::Message::CopyWithSourceCheck,
    HttpBody::MergeImpl
};
const ::PROTOBUF_NAMESPACE_ID::Message::ClassData*HttpBody::GetClassData() const { return &_class_data_; }


void HttpBody::MergeImpl(::PROTOBUF_NAMESPACE_ID::Message& to_msg, const ::PROTOBUF_NAMESPACE_ID::Message& from_msg) {
  auto* const _this = static_cast<HttpBody*>(&to_msg);
  auto& from = static_cast<const HttpBody&>(from_msg);
  // @@protoc_insertion_point(class_specific_merge_from_start:google.api.HttpBody)
  ABSL_DCHECK_NE(&from, _this);
  ::uint32_t cached_has_bits = 0;
  (void) cached_has_bits;

  _this->_internal_mutable_extensions()->MergeFrom(from._internal_extensions());
  if (!from._internal_content_type().empty()) {
    _this->_internal_set_content_type(from._internal_content_type());
  }
  if (!from._internal_data().empty()) {
    _this->_internal_set_data(from._internal_data());
  }
  _this->_internal_metadata_.MergeFrom<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(from._internal_metadata_);
}

void HttpBody::CopyFrom(const HttpBody& from) {
// @@protoc_insertion_point(class_specific_copy_from_start:google.api.HttpBody)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool HttpBody::IsInitialized() const {
  return true;
}

void HttpBody::InternalSwap(HttpBody* other) {
  using std::swap;
  auto* lhs_arena = GetArenaForAllocation();
  auto* rhs_arena = other->GetArenaForAllocation();
  _internal_metadata_.InternalSwap(&other->_internal_metadata_);
  _internal_mutable_extensions()->InternalSwap(other->_internal_mutable_extensions());
  ::_pbi::ArenaStringPtr::InternalSwap(&_impl_.content_type_, lhs_arena,
                                       &other->_impl_.content_type_, rhs_arena);
  ::_pbi::ArenaStringPtr::InternalSwap(&_impl_.data_, lhs_arena,
                                       &other->_impl_.data_, rhs_arena);
}

::PROTOBUF_NAMESPACE_ID::Metadata HttpBody::GetMetadata() const {
  return ::_pbi::AssignDescriptors(
      &descriptor_table_google_2fapi_2fhttpbody_2eproto_getter, &descriptor_table_google_2fapi_2fhttpbody_2eproto_once,
      file_level_metadata_google_2fapi_2fhttpbody_2eproto[0]);
}
// @@protoc_insertion_point(namespace_scope)
}  // namespace api
}  // namespace google
PROTOBUF_NAMESPACE_OPEN
template<> PROTOBUF_NOINLINE ::google::api::HttpBody*
Arena::CreateMaybeMessage< ::google::api::HttpBody >(Arena* arena) {
  return Arena::CreateMessageInternal< ::google::api::HttpBody >(arena);
}
PROTOBUF_NAMESPACE_CLOSE
// @@protoc_insertion_point(global_scope)
#include "google/protobuf/port_undef.inc"
