// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: ResponseNameChangeBuf.proto

#include "ResponseNameChangeBuf.pb.h"

#include <algorithm>

#include <google/protobuf/io/coded_stream.h>
#include <google/protobuf/extension_set.h>
#include <google/protobuf/wire_format_lite.h>
#include <google/protobuf/descriptor.h>
#include <google/protobuf/generated_message_reflection.h>
#include <google/protobuf/reflection_ops.h>
#include <google/protobuf/wire_format.h>
// @@protoc_insertion_point(includes)
#include <google/protobuf/port_def.inc>

PROTOBUF_PRAGMA_INIT_SEG
constexpr ResponseNameChangeBuf::ResponseNameChangeBuf(
  ::PROTOBUF_NAMESPACE_ID::internal::ConstantInitialized)
  : newname_(&::PROTOBUF_NAMESPACE_ID::internal::fixed_address_empty_string)
  , requestid_(0)
  , clientid_(0)
  , serverid_(0){}
struct ResponseNameChangeBufDefaultTypeInternal {
  constexpr ResponseNameChangeBufDefaultTypeInternal()
    : _instance(::PROTOBUF_NAMESPACE_ID::internal::ConstantInitialized{}) {}
  ~ResponseNameChangeBufDefaultTypeInternal() {}
  union {
    ResponseNameChangeBuf _instance;
  };
};
PROTOBUF_ATTRIBUTE_NO_DESTROY PROTOBUF_CONSTINIT ResponseNameChangeBufDefaultTypeInternal _ResponseNameChangeBuf_default_instance_;
static ::PROTOBUF_NAMESPACE_ID::Metadata file_level_metadata_ResponseNameChangeBuf_2eproto[1];
static constexpr ::PROTOBUF_NAMESPACE_ID::EnumDescriptor const** file_level_enum_descriptors_ResponseNameChangeBuf_2eproto = nullptr;
static constexpr ::PROTOBUF_NAMESPACE_ID::ServiceDescriptor const** file_level_service_descriptors_ResponseNameChangeBuf_2eproto = nullptr;

const ::PROTOBUF_NAMESPACE_ID::uint32 TableStruct_ResponseNameChangeBuf_2eproto::offsets[] PROTOBUF_SECTION_VARIABLE(protodesc_cold) = {
  PROTOBUF_FIELD_OFFSET(::ResponseNameChangeBuf, _has_bits_),
  PROTOBUF_FIELD_OFFSET(::ResponseNameChangeBuf, _internal_metadata_),
  ~0u,  // no _extensions_
  ~0u,  // no _oneof_case_
  ~0u,  // no _weak_field_map_
  ~0u,  // no _inlined_string_donated_
  PROTOBUF_FIELD_OFFSET(::ResponseNameChangeBuf, requestid_),
  PROTOBUF_FIELD_OFFSET(::ResponseNameChangeBuf, clientid_),
  PROTOBUF_FIELD_OFFSET(::ResponseNameChangeBuf, serverid_),
  PROTOBUF_FIELD_OFFSET(::ResponseNameChangeBuf, newname_),
  1,
  2,
  3,
  0,
};
static const ::PROTOBUF_NAMESPACE_ID::internal::MigrationSchema schemas[] PROTOBUF_SECTION_VARIABLE(protodesc_cold) = {
  { 0, 10, -1, sizeof(::ResponseNameChangeBuf)},
};

static ::PROTOBUF_NAMESPACE_ID::Message const * const file_default_instances[] = {
  reinterpret_cast<const ::PROTOBUF_NAMESPACE_ID::Message*>(&::_ResponseNameChangeBuf_default_instance_),
};

const char descriptor_table_protodef_ResponseNameChangeBuf_2eproto[] PROTOBUF_SECTION_VARIABLE(protodesc_cold) =
  "\n\033ResponseNameChangeBuf.proto\"_\n\025Respons"
  "eNameChangeBuf\022\021\n\trequestId\030\001 \002(\005\022\020\n\010cli"
  "entId\030\002 \002(\005\022\020\n\010serverId\030\003 \002(\005\022\017\n\007newname"
  "\030\004 \002(\t"
  ;
static ::PROTOBUF_NAMESPACE_ID::internal::once_flag descriptor_table_ResponseNameChangeBuf_2eproto_once;
const ::PROTOBUF_NAMESPACE_ID::internal::DescriptorTable descriptor_table_ResponseNameChangeBuf_2eproto = {
  false, false, 126, descriptor_table_protodef_ResponseNameChangeBuf_2eproto, "ResponseNameChangeBuf.proto", 
  &descriptor_table_ResponseNameChangeBuf_2eproto_once, nullptr, 0, 1,
  schemas, file_default_instances, TableStruct_ResponseNameChangeBuf_2eproto::offsets,
  file_level_metadata_ResponseNameChangeBuf_2eproto, file_level_enum_descriptors_ResponseNameChangeBuf_2eproto, file_level_service_descriptors_ResponseNameChangeBuf_2eproto,
};
PROTOBUF_ATTRIBUTE_WEAK const ::PROTOBUF_NAMESPACE_ID::internal::DescriptorTable* descriptor_table_ResponseNameChangeBuf_2eproto_getter() {
  return &descriptor_table_ResponseNameChangeBuf_2eproto;
}

// Force running AddDescriptors() at dynamic initialization time.
PROTOBUF_ATTRIBUTE_INIT_PRIORITY static ::PROTOBUF_NAMESPACE_ID::internal::AddDescriptorsRunner dynamic_init_dummy_ResponseNameChangeBuf_2eproto(&descriptor_table_ResponseNameChangeBuf_2eproto);

// ===================================================================

class ResponseNameChangeBuf::_Internal {
 public:
  using HasBits = decltype(std::declval<ResponseNameChangeBuf>()._has_bits_);
  static void set_has_requestid(HasBits* has_bits) {
    (*has_bits)[0] |= 2u;
  }
  static void set_has_clientid(HasBits* has_bits) {
    (*has_bits)[0] |= 4u;
  }
  static void set_has_serverid(HasBits* has_bits) {
    (*has_bits)[0] |= 8u;
  }
  static void set_has_newname(HasBits* has_bits) {
    (*has_bits)[0] |= 1u;
  }
  static bool MissingRequiredFields(const HasBits& has_bits) {
    return ((has_bits[0] & 0x0000000f) ^ 0x0000000f) != 0;
  }
};

ResponseNameChangeBuf::ResponseNameChangeBuf(::PROTOBUF_NAMESPACE_ID::Arena* arena,
                         bool is_message_owned)
  : ::PROTOBUF_NAMESPACE_ID::Message(arena, is_message_owned) {
  SharedCtor();
  if (!is_message_owned) {
    RegisterArenaDtor(arena);
  }
  // @@protoc_insertion_point(arena_constructor:ResponseNameChangeBuf)
}
ResponseNameChangeBuf::ResponseNameChangeBuf(const ResponseNameChangeBuf& from)
  : ::PROTOBUF_NAMESPACE_ID::Message(),
      _has_bits_(from._has_bits_) {
  _internal_metadata_.MergeFrom<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(from._internal_metadata_);
  newname_.UnsafeSetDefault(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
  if (from._internal_has_newname()) {
    newname_.Set(::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr::EmptyDefault{}, from._internal_newname(), 
      GetArenaForAllocation());
  }
  ::memcpy(&requestid_, &from.requestid_,
    static_cast<size_t>(reinterpret_cast<char*>(&serverid_) -
    reinterpret_cast<char*>(&requestid_)) + sizeof(serverid_));
  // @@protoc_insertion_point(copy_constructor:ResponseNameChangeBuf)
}

void ResponseNameChangeBuf::SharedCtor() {
newname_.UnsafeSetDefault(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
::memset(reinterpret_cast<char*>(this) + static_cast<size_t>(
    reinterpret_cast<char*>(&requestid_) - reinterpret_cast<char*>(this)),
    0, static_cast<size_t>(reinterpret_cast<char*>(&serverid_) -
    reinterpret_cast<char*>(&requestid_)) + sizeof(serverid_));
}

ResponseNameChangeBuf::~ResponseNameChangeBuf() {
  // @@protoc_insertion_point(destructor:ResponseNameChangeBuf)
  if (GetArenaForAllocation() != nullptr) return;
  SharedDtor();
  _internal_metadata_.Delete<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>();
}

inline void ResponseNameChangeBuf::SharedDtor() {
  GOOGLE_DCHECK(GetArenaForAllocation() == nullptr);
  newname_.DestroyNoArena(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
}

void ResponseNameChangeBuf::ArenaDtor(void* object) {
  ResponseNameChangeBuf* _this = reinterpret_cast< ResponseNameChangeBuf* >(object);
  (void)_this;
}
void ResponseNameChangeBuf::RegisterArenaDtor(::PROTOBUF_NAMESPACE_ID::Arena*) {
}
void ResponseNameChangeBuf::SetCachedSize(int size) const {
  _cached_size_.Set(size);
}

void ResponseNameChangeBuf::Clear() {
// @@protoc_insertion_point(message_clear_start:ResponseNameChangeBuf)
  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  cached_has_bits = _has_bits_[0];
  if (cached_has_bits & 0x00000001u) {
    newname_.ClearNonDefaultToEmpty();
  }
  if (cached_has_bits & 0x0000000eu) {
    ::memset(&requestid_, 0, static_cast<size_t>(
        reinterpret_cast<char*>(&serverid_) -
        reinterpret_cast<char*>(&requestid_)) + sizeof(serverid_));
  }
  _has_bits_.Clear();
  _internal_metadata_.Clear<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>();
}

const char* ResponseNameChangeBuf::_InternalParse(const char* ptr, ::PROTOBUF_NAMESPACE_ID::internal::ParseContext* ctx) {
#define CHK_(x) if (PROTOBUF_PREDICT_FALSE(!(x))) goto failure
  _Internal::HasBits has_bits{};
  while (!ctx->Done(&ptr)) {
    ::PROTOBUF_NAMESPACE_ID::uint32 tag;
    ptr = ::PROTOBUF_NAMESPACE_ID::internal::ReadTag(ptr, &tag);
    switch (tag >> 3) {
      // required int32 requestId = 1;
      case 1:
        if (PROTOBUF_PREDICT_TRUE(static_cast<::PROTOBUF_NAMESPACE_ID::uint8>(tag) == 8)) {
          _Internal::set_has_requestid(&has_bits);
          requestid_ = ::PROTOBUF_NAMESPACE_ID::internal::ReadVarint64(&ptr);
          CHK_(ptr);
        } else
          goto handle_unusual;
        continue;
      // required int32 clientId = 2;
      case 2:
        if (PROTOBUF_PREDICT_TRUE(static_cast<::PROTOBUF_NAMESPACE_ID::uint8>(tag) == 16)) {
          _Internal::set_has_clientid(&has_bits);
          clientid_ = ::PROTOBUF_NAMESPACE_ID::internal::ReadVarint64(&ptr);
          CHK_(ptr);
        } else
          goto handle_unusual;
        continue;
      // required int32 serverId = 3;
      case 3:
        if (PROTOBUF_PREDICT_TRUE(static_cast<::PROTOBUF_NAMESPACE_ID::uint8>(tag) == 24)) {
          _Internal::set_has_serverid(&has_bits);
          serverid_ = ::PROTOBUF_NAMESPACE_ID::internal::ReadVarint64(&ptr);
          CHK_(ptr);
        } else
          goto handle_unusual;
        continue;
      // required string newname = 4;
      case 4:
        if (PROTOBUF_PREDICT_TRUE(static_cast<::PROTOBUF_NAMESPACE_ID::uint8>(tag) == 34)) {
          auto str = _internal_mutable_newname();
          ptr = ::PROTOBUF_NAMESPACE_ID::internal::InlineGreedyStringParser(str, ptr, ctx);
          #ifndef NDEBUG
          ::PROTOBUF_NAMESPACE_ID::internal::VerifyUTF8(str, "ResponseNameChangeBuf.newname");
          #endif  // !NDEBUG
          CHK_(ptr);
        } else
          goto handle_unusual;
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
  _has_bits_.Or(has_bits);
  return ptr;
failure:
  ptr = nullptr;
  goto message_done;
#undef CHK_
}

::PROTOBUF_NAMESPACE_ID::uint8* ResponseNameChangeBuf::_InternalSerialize(
    ::PROTOBUF_NAMESPACE_ID::uint8* target, ::PROTOBUF_NAMESPACE_ID::io::EpsCopyOutputStream* stream) const {
  // @@protoc_insertion_point(serialize_to_array_start:ResponseNameChangeBuf)
  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  (void) cached_has_bits;

  cached_has_bits = _has_bits_[0];
  // required int32 requestId = 1;
  if (cached_has_bits & 0x00000002u) {
    target = stream->EnsureSpace(target);
    target = ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::WriteInt32ToArray(1, this->_internal_requestid(), target);
  }

  // required int32 clientId = 2;
  if (cached_has_bits & 0x00000004u) {
    target = stream->EnsureSpace(target);
    target = ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::WriteInt32ToArray(2, this->_internal_clientid(), target);
  }

  // required int32 serverId = 3;
  if (cached_has_bits & 0x00000008u) {
    target = stream->EnsureSpace(target);
    target = ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::WriteInt32ToArray(3, this->_internal_serverid(), target);
  }

  // required string newname = 4;
  if (cached_has_bits & 0x00000001u) {
    ::PROTOBUF_NAMESPACE_ID::internal::WireFormat::VerifyUTF8StringNamedField(
      this->_internal_newname().data(), static_cast<int>(this->_internal_newname().length()),
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormat::SERIALIZE,
      "ResponseNameChangeBuf.newname");
    target = stream->WriteStringMaybeAliased(
        4, this->_internal_newname(), target);
  }

  if (PROTOBUF_PREDICT_FALSE(_internal_metadata_.have_unknown_fields())) {
    target = ::PROTOBUF_NAMESPACE_ID::internal::WireFormat::InternalSerializeUnknownFieldsToArray(
        _internal_metadata_.unknown_fields<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(::PROTOBUF_NAMESPACE_ID::UnknownFieldSet::default_instance), target, stream);
  }
  // @@protoc_insertion_point(serialize_to_array_end:ResponseNameChangeBuf)
  return target;
}

size_t ResponseNameChangeBuf::RequiredFieldsByteSizeFallback() const {
// @@protoc_insertion_point(required_fields_byte_size_fallback_start:ResponseNameChangeBuf)
  size_t total_size = 0;

  if (_internal_has_newname()) {
    // required string newname = 4;
    total_size += 1 +
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::StringSize(
        this->_internal_newname());
  }

  if (_internal_has_requestid()) {
    // required int32 requestId = 1;
    total_size += ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::Int32SizePlusOne(this->_internal_requestid());
  }

  if (_internal_has_clientid()) {
    // required int32 clientId = 2;
    total_size += ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::Int32SizePlusOne(this->_internal_clientid());
  }

  if (_internal_has_serverid()) {
    // required int32 serverId = 3;
    total_size += ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::Int32SizePlusOne(this->_internal_serverid());
  }

  return total_size;
}
size_t ResponseNameChangeBuf::ByteSizeLong() const {
// @@protoc_insertion_point(message_byte_size_start:ResponseNameChangeBuf)
  size_t total_size = 0;

  if (((_has_bits_[0] & 0x0000000f) ^ 0x0000000f) == 0) {  // All required fields are present.
    // required string newname = 4;
    total_size += 1 +
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::StringSize(
        this->_internal_newname());

    // required int32 requestId = 1;
    total_size += ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::Int32SizePlusOne(this->_internal_requestid());

    // required int32 clientId = 2;
    total_size += ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::Int32SizePlusOne(this->_internal_clientid());

    // required int32 serverId = 3;
    total_size += ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::Int32SizePlusOne(this->_internal_serverid());

  } else {
    total_size += RequiredFieldsByteSizeFallback();
  }
  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  return MaybeComputeUnknownFieldsSize(total_size, &_cached_size_);
}

const ::PROTOBUF_NAMESPACE_ID::Message::ClassData ResponseNameChangeBuf::_class_data_ = {
    ::PROTOBUF_NAMESPACE_ID::Message::CopyWithSizeCheck,
    ResponseNameChangeBuf::MergeImpl
};
const ::PROTOBUF_NAMESPACE_ID::Message::ClassData*ResponseNameChangeBuf::GetClassData() const { return &_class_data_; }

void ResponseNameChangeBuf::MergeImpl(::PROTOBUF_NAMESPACE_ID::Message* to,
                      const ::PROTOBUF_NAMESPACE_ID::Message& from) {
  static_cast<ResponseNameChangeBuf *>(to)->MergeFrom(
      static_cast<const ResponseNameChangeBuf &>(from));
}


void ResponseNameChangeBuf::MergeFrom(const ResponseNameChangeBuf& from) {
// @@protoc_insertion_point(class_specific_merge_from_start:ResponseNameChangeBuf)
  GOOGLE_DCHECK_NE(&from, this);
  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  (void) cached_has_bits;

  cached_has_bits = from._has_bits_[0];
  if (cached_has_bits & 0x0000000fu) {
    if (cached_has_bits & 0x00000001u) {
      _internal_set_newname(from._internal_newname());
    }
    if (cached_has_bits & 0x00000002u) {
      requestid_ = from.requestid_;
    }
    if (cached_has_bits & 0x00000004u) {
      clientid_ = from.clientid_;
    }
    if (cached_has_bits & 0x00000008u) {
      serverid_ = from.serverid_;
    }
    _has_bits_[0] |= cached_has_bits;
  }
  _internal_metadata_.MergeFrom<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(from._internal_metadata_);
}

void ResponseNameChangeBuf::CopyFrom(const ResponseNameChangeBuf& from) {
// @@protoc_insertion_point(class_specific_copy_from_start:ResponseNameChangeBuf)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool ResponseNameChangeBuf::IsInitialized() const {
  if (_Internal::MissingRequiredFields(_has_bits_)) return false;
  return true;
}

void ResponseNameChangeBuf::InternalSwap(ResponseNameChangeBuf* other) {
  using std::swap;
  auto* lhs_arena = GetArenaForAllocation();
  auto* rhs_arena = other->GetArenaForAllocation();
  _internal_metadata_.InternalSwap(&other->_internal_metadata_);
  swap(_has_bits_[0], other->_has_bits_[0]);
  ::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr::InternalSwap(
      &::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(),
      &newname_, lhs_arena,
      &other->newname_, rhs_arena
  );
  ::PROTOBUF_NAMESPACE_ID::internal::memswap<
      PROTOBUF_FIELD_OFFSET(ResponseNameChangeBuf, serverid_)
      + sizeof(ResponseNameChangeBuf::serverid_)
      - PROTOBUF_FIELD_OFFSET(ResponseNameChangeBuf, requestid_)>(
          reinterpret_cast<char*>(&requestid_),
          reinterpret_cast<char*>(&other->requestid_));
}

::PROTOBUF_NAMESPACE_ID::Metadata ResponseNameChangeBuf::GetMetadata() const {
  return ::PROTOBUF_NAMESPACE_ID::internal::AssignDescriptors(
      &descriptor_table_ResponseNameChangeBuf_2eproto_getter, &descriptor_table_ResponseNameChangeBuf_2eproto_once,
      file_level_metadata_ResponseNameChangeBuf_2eproto[0]);
}

// @@protoc_insertion_point(namespace_scope)
PROTOBUF_NAMESPACE_OPEN
template<> PROTOBUF_NOINLINE ::ResponseNameChangeBuf* Arena::CreateMaybeMessage< ::ResponseNameChangeBuf >(Arena* arena) {
  return Arena::CreateMessageInternal< ::ResponseNameChangeBuf >(arena);
}
PROTOBUF_NAMESPACE_CLOSE

// @@protoc_insertion_point(global_scope)
#include <google/protobuf/port_undef.inc>
