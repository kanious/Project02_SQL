// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: RequestAuthenticateAccount.proto

#include "RequestAuthenticateAccount.pb.h"

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
constexpr RequestAuthenticateAccount::RequestAuthenticateAccount(
  ::PROTOBUF_NAMESPACE_ID::internal::ConstantInitialized)
  : email_(&::PROTOBUF_NAMESPACE_ID::internal::fixed_address_empty_string)
  , plaintextpassword_(&::PROTOBUF_NAMESPACE_ID::internal::fixed_address_empty_string)
  , requestid_(0)
  , clientid_(0)
  , serverid_(0){}
struct RequestAuthenticateAccountDefaultTypeInternal {
  constexpr RequestAuthenticateAccountDefaultTypeInternal()
    : _instance(::PROTOBUF_NAMESPACE_ID::internal::ConstantInitialized{}) {}
  ~RequestAuthenticateAccountDefaultTypeInternal() {}
  union {
    RequestAuthenticateAccount _instance;
  };
};
PROTOBUF_ATTRIBUTE_NO_DESTROY PROTOBUF_CONSTINIT RequestAuthenticateAccountDefaultTypeInternal _RequestAuthenticateAccount_default_instance_;
static ::PROTOBUF_NAMESPACE_ID::Metadata file_level_metadata_RequestAuthenticateAccount_2eproto[1];
static constexpr ::PROTOBUF_NAMESPACE_ID::EnumDescriptor const** file_level_enum_descriptors_RequestAuthenticateAccount_2eproto = nullptr;
static constexpr ::PROTOBUF_NAMESPACE_ID::ServiceDescriptor const** file_level_service_descriptors_RequestAuthenticateAccount_2eproto = nullptr;

const ::PROTOBUF_NAMESPACE_ID::uint32 TableStruct_RequestAuthenticateAccount_2eproto::offsets[] PROTOBUF_SECTION_VARIABLE(protodesc_cold) = {
  PROTOBUF_FIELD_OFFSET(::RequestAuthenticateAccount, _has_bits_),
  PROTOBUF_FIELD_OFFSET(::RequestAuthenticateAccount, _internal_metadata_),
  ~0u,  // no _extensions_
  ~0u,  // no _oneof_case_
  ~0u,  // no _weak_field_map_
  ~0u,  // no _inlined_string_donated_
  PROTOBUF_FIELD_OFFSET(::RequestAuthenticateAccount, requestid_),
  PROTOBUF_FIELD_OFFSET(::RequestAuthenticateAccount, clientid_),
  PROTOBUF_FIELD_OFFSET(::RequestAuthenticateAccount, serverid_),
  PROTOBUF_FIELD_OFFSET(::RequestAuthenticateAccount, email_),
  PROTOBUF_FIELD_OFFSET(::RequestAuthenticateAccount, plaintextpassword_),
  2,
  3,
  4,
  0,
  1,
};
static const ::PROTOBUF_NAMESPACE_ID::internal::MigrationSchema schemas[] PROTOBUF_SECTION_VARIABLE(protodesc_cold) = {
  { 0, 11, -1, sizeof(::RequestAuthenticateAccount)},
};

static ::PROTOBUF_NAMESPACE_ID::Message const * const file_default_instances[] = {
  reinterpret_cast<const ::PROTOBUF_NAMESPACE_ID::Message*>(&::_RequestAuthenticateAccount_default_instance_),
};

const char descriptor_table_protodef_RequestAuthenticateAccount_2eproto[] PROTOBUF_SECTION_VARIABLE(protodesc_cold) =
  "\n RequestAuthenticateAccount.proto\"}\n\032Re"
  "questAuthenticateAccount\022\021\n\trequestId\030\001 "
  "\002(\005\022\020\n\010clientId\030\002 \002(\005\022\020\n\010serverId\030\003 \002(\005\022"
  "\r\n\005email\030\004 \002(\t\022\031\n\021plaintextPassword\030\005 \002("
  "\t"
  ;
static ::PROTOBUF_NAMESPACE_ID::internal::once_flag descriptor_table_RequestAuthenticateAccount_2eproto_once;
const ::PROTOBUF_NAMESPACE_ID::internal::DescriptorTable descriptor_table_RequestAuthenticateAccount_2eproto = {
  false, false, 161, descriptor_table_protodef_RequestAuthenticateAccount_2eproto, "RequestAuthenticateAccount.proto", 
  &descriptor_table_RequestAuthenticateAccount_2eproto_once, nullptr, 0, 1,
  schemas, file_default_instances, TableStruct_RequestAuthenticateAccount_2eproto::offsets,
  file_level_metadata_RequestAuthenticateAccount_2eproto, file_level_enum_descriptors_RequestAuthenticateAccount_2eproto, file_level_service_descriptors_RequestAuthenticateAccount_2eproto,
};
PROTOBUF_ATTRIBUTE_WEAK const ::PROTOBUF_NAMESPACE_ID::internal::DescriptorTable* descriptor_table_RequestAuthenticateAccount_2eproto_getter() {
  return &descriptor_table_RequestAuthenticateAccount_2eproto;
}

// Force running AddDescriptors() at dynamic initialization time.
PROTOBUF_ATTRIBUTE_INIT_PRIORITY static ::PROTOBUF_NAMESPACE_ID::internal::AddDescriptorsRunner dynamic_init_dummy_RequestAuthenticateAccount_2eproto(&descriptor_table_RequestAuthenticateAccount_2eproto);

// ===================================================================

class RequestAuthenticateAccount::_Internal {
 public:
  using HasBits = decltype(std::declval<RequestAuthenticateAccount>()._has_bits_);
  static void set_has_requestid(HasBits* has_bits) {
    (*has_bits)[0] |= 4u;
  }
  static void set_has_clientid(HasBits* has_bits) {
    (*has_bits)[0] |= 8u;
  }
  static void set_has_serverid(HasBits* has_bits) {
    (*has_bits)[0] |= 16u;
  }
  static void set_has_email(HasBits* has_bits) {
    (*has_bits)[0] |= 1u;
  }
  static void set_has_plaintextpassword(HasBits* has_bits) {
    (*has_bits)[0] |= 2u;
  }
  static bool MissingRequiredFields(const HasBits& has_bits) {
    return ((has_bits[0] & 0x0000001f) ^ 0x0000001f) != 0;
  }
};

RequestAuthenticateAccount::RequestAuthenticateAccount(::PROTOBUF_NAMESPACE_ID::Arena* arena,
                         bool is_message_owned)
  : ::PROTOBUF_NAMESPACE_ID::Message(arena, is_message_owned) {
  SharedCtor();
  if (!is_message_owned) {
    RegisterArenaDtor(arena);
  }
  // @@protoc_insertion_point(arena_constructor:RequestAuthenticateAccount)
}
RequestAuthenticateAccount::RequestAuthenticateAccount(const RequestAuthenticateAccount& from)
  : ::PROTOBUF_NAMESPACE_ID::Message(),
      _has_bits_(from._has_bits_) {
  _internal_metadata_.MergeFrom<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(from._internal_metadata_);
  email_.UnsafeSetDefault(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
  if (from._internal_has_email()) {
    email_.Set(::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr::EmptyDefault{}, from._internal_email(), 
      GetArenaForAllocation());
  }
  plaintextpassword_.UnsafeSetDefault(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
  if (from._internal_has_plaintextpassword()) {
    plaintextpassword_.Set(::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr::EmptyDefault{}, from._internal_plaintextpassword(), 
      GetArenaForAllocation());
  }
  ::memcpy(&requestid_, &from.requestid_,
    static_cast<size_t>(reinterpret_cast<char*>(&serverid_) -
    reinterpret_cast<char*>(&requestid_)) + sizeof(serverid_));
  // @@protoc_insertion_point(copy_constructor:RequestAuthenticateAccount)
}

void RequestAuthenticateAccount::SharedCtor() {
email_.UnsafeSetDefault(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
plaintextpassword_.UnsafeSetDefault(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
::memset(reinterpret_cast<char*>(this) + static_cast<size_t>(
    reinterpret_cast<char*>(&requestid_) - reinterpret_cast<char*>(this)),
    0, static_cast<size_t>(reinterpret_cast<char*>(&serverid_) -
    reinterpret_cast<char*>(&requestid_)) + sizeof(serverid_));
}

RequestAuthenticateAccount::~RequestAuthenticateAccount() {
  // @@protoc_insertion_point(destructor:RequestAuthenticateAccount)
  if (GetArenaForAllocation() != nullptr) return;
  SharedDtor();
  _internal_metadata_.Delete<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>();
}

inline void RequestAuthenticateAccount::SharedDtor() {
  GOOGLE_DCHECK(GetArenaForAllocation() == nullptr);
  email_.DestroyNoArena(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
  plaintextpassword_.DestroyNoArena(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
}

void RequestAuthenticateAccount::ArenaDtor(void* object) {
  RequestAuthenticateAccount* _this = reinterpret_cast< RequestAuthenticateAccount* >(object);
  (void)_this;
}
void RequestAuthenticateAccount::RegisterArenaDtor(::PROTOBUF_NAMESPACE_ID::Arena*) {
}
void RequestAuthenticateAccount::SetCachedSize(int size) const {
  _cached_size_.Set(size);
}

void RequestAuthenticateAccount::Clear() {
// @@protoc_insertion_point(message_clear_start:RequestAuthenticateAccount)
  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  cached_has_bits = _has_bits_[0];
  if (cached_has_bits & 0x00000003u) {
    if (cached_has_bits & 0x00000001u) {
      email_.ClearNonDefaultToEmpty();
    }
    if (cached_has_bits & 0x00000002u) {
      plaintextpassword_.ClearNonDefaultToEmpty();
    }
  }
  if (cached_has_bits & 0x0000001cu) {
    ::memset(&requestid_, 0, static_cast<size_t>(
        reinterpret_cast<char*>(&serverid_) -
        reinterpret_cast<char*>(&requestid_)) + sizeof(serverid_));
  }
  _has_bits_.Clear();
  _internal_metadata_.Clear<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>();
}

const char* RequestAuthenticateAccount::_InternalParse(const char* ptr, ::PROTOBUF_NAMESPACE_ID::internal::ParseContext* ctx) {
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
      // required string email = 4;
      case 4:
        if (PROTOBUF_PREDICT_TRUE(static_cast<::PROTOBUF_NAMESPACE_ID::uint8>(tag) == 34)) {
          auto str = _internal_mutable_email();
          ptr = ::PROTOBUF_NAMESPACE_ID::internal::InlineGreedyStringParser(str, ptr, ctx);
          #ifndef NDEBUG
          ::PROTOBUF_NAMESPACE_ID::internal::VerifyUTF8(str, "RequestAuthenticateAccount.email");
          #endif  // !NDEBUG
          CHK_(ptr);
        } else
          goto handle_unusual;
        continue;
      // required string plaintextPassword = 5;
      case 5:
        if (PROTOBUF_PREDICT_TRUE(static_cast<::PROTOBUF_NAMESPACE_ID::uint8>(tag) == 42)) {
          auto str = _internal_mutable_plaintextpassword();
          ptr = ::PROTOBUF_NAMESPACE_ID::internal::InlineGreedyStringParser(str, ptr, ctx);
          #ifndef NDEBUG
          ::PROTOBUF_NAMESPACE_ID::internal::VerifyUTF8(str, "RequestAuthenticateAccount.plaintextPassword");
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

::PROTOBUF_NAMESPACE_ID::uint8* RequestAuthenticateAccount::_InternalSerialize(
    ::PROTOBUF_NAMESPACE_ID::uint8* target, ::PROTOBUF_NAMESPACE_ID::io::EpsCopyOutputStream* stream) const {
  // @@protoc_insertion_point(serialize_to_array_start:RequestAuthenticateAccount)
  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  (void) cached_has_bits;

  cached_has_bits = _has_bits_[0];
  // required int32 requestId = 1;
  if (cached_has_bits & 0x00000004u) {
    target = stream->EnsureSpace(target);
    target = ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::WriteInt32ToArray(1, this->_internal_requestid(), target);
  }

  // required int32 clientId = 2;
  if (cached_has_bits & 0x00000008u) {
    target = stream->EnsureSpace(target);
    target = ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::WriteInt32ToArray(2, this->_internal_clientid(), target);
  }

  // required int32 serverId = 3;
  if (cached_has_bits & 0x00000010u) {
    target = stream->EnsureSpace(target);
    target = ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::WriteInt32ToArray(3, this->_internal_serverid(), target);
  }

  // required string email = 4;
  if (cached_has_bits & 0x00000001u) {
    ::PROTOBUF_NAMESPACE_ID::internal::WireFormat::VerifyUTF8StringNamedField(
      this->_internal_email().data(), static_cast<int>(this->_internal_email().length()),
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormat::SERIALIZE,
      "RequestAuthenticateAccount.email");
    target = stream->WriteStringMaybeAliased(
        4, this->_internal_email(), target);
  }

  // required string plaintextPassword = 5;
  if (cached_has_bits & 0x00000002u) {
    ::PROTOBUF_NAMESPACE_ID::internal::WireFormat::VerifyUTF8StringNamedField(
      this->_internal_plaintextpassword().data(), static_cast<int>(this->_internal_plaintextpassword().length()),
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormat::SERIALIZE,
      "RequestAuthenticateAccount.plaintextPassword");
    target = stream->WriteStringMaybeAliased(
        5, this->_internal_plaintextpassword(), target);
  }

  if (PROTOBUF_PREDICT_FALSE(_internal_metadata_.have_unknown_fields())) {
    target = ::PROTOBUF_NAMESPACE_ID::internal::WireFormat::InternalSerializeUnknownFieldsToArray(
        _internal_metadata_.unknown_fields<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(::PROTOBUF_NAMESPACE_ID::UnknownFieldSet::default_instance), target, stream);
  }
  // @@protoc_insertion_point(serialize_to_array_end:RequestAuthenticateAccount)
  return target;
}

size_t RequestAuthenticateAccount::RequiredFieldsByteSizeFallback() const {
// @@protoc_insertion_point(required_fields_byte_size_fallback_start:RequestAuthenticateAccount)
  size_t total_size = 0;

  if (_internal_has_email()) {
    // required string email = 4;
    total_size += 1 +
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::StringSize(
        this->_internal_email());
  }

  if (_internal_has_plaintextpassword()) {
    // required string plaintextPassword = 5;
    total_size += 1 +
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::StringSize(
        this->_internal_plaintextpassword());
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
size_t RequestAuthenticateAccount::ByteSizeLong() const {
// @@protoc_insertion_point(message_byte_size_start:RequestAuthenticateAccount)
  size_t total_size = 0;

  if (((_has_bits_[0] & 0x0000001f) ^ 0x0000001f) == 0) {  // All required fields are present.
    // required string email = 4;
    total_size += 1 +
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::StringSize(
        this->_internal_email());

    // required string plaintextPassword = 5;
    total_size += 1 +
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::StringSize(
        this->_internal_plaintextpassword());

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

const ::PROTOBUF_NAMESPACE_ID::Message::ClassData RequestAuthenticateAccount::_class_data_ = {
    ::PROTOBUF_NAMESPACE_ID::Message::CopyWithSizeCheck,
    RequestAuthenticateAccount::MergeImpl
};
const ::PROTOBUF_NAMESPACE_ID::Message::ClassData*RequestAuthenticateAccount::GetClassData() const { return &_class_data_; }

void RequestAuthenticateAccount::MergeImpl(::PROTOBUF_NAMESPACE_ID::Message* to,
                      const ::PROTOBUF_NAMESPACE_ID::Message& from) {
  static_cast<RequestAuthenticateAccount *>(to)->MergeFrom(
      static_cast<const RequestAuthenticateAccount &>(from));
}


void RequestAuthenticateAccount::MergeFrom(const RequestAuthenticateAccount& from) {
// @@protoc_insertion_point(class_specific_merge_from_start:RequestAuthenticateAccount)
  GOOGLE_DCHECK_NE(&from, this);
  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  (void) cached_has_bits;

  cached_has_bits = from._has_bits_[0];
  if (cached_has_bits & 0x0000001fu) {
    if (cached_has_bits & 0x00000001u) {
      _internal_set_email(from._internal_email());
    }
    if (cached_has_bits & 0x00000002u) {
      _internal_set_plaintextpassword(from._internal_plaintextpassword());
    }
    if (cached_has_bits & 0x00000004u) {
      requestid_ = from.requestid_;
    }
    if (cached_has_bits & 0x00000008u) {
      clientid_ = from.clientid_;
    }
    if (cached_has_bits & 0x00000010u) {
      serverid_ = from.serverid_;
    }
    _has_bits_[0] |= cached_has_bits;
  }
  _internal_metadata_.MergeFrom<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(from._internal_metadata_);
}

void RequestAuthenticateAccount::CopyFrom(const RequestAuthenticateAccount& from) {
// @@protoc_insertion_point(class_specific_copy_from_start:RequestAuthenticateAccount)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool RequestAuthenticateAccount::IsInitialized() const {
  if (_Internal::MissingRequiredFields(_has_bits_)) return false;
  return true;
}

void RequestAuthenticateAccount::InternalSwap(RequestAuthenticateAccount* other) {
  using std::swap;
  auto* lhs_arena = GetArenaForAllocation();
  auto* rhs_arena = other->GetArenaForAllocation();
  _internal_metadata_.InternalSwap(&other->_internal_metadata_);
  swap(_has_bits_[0], other->_has_bits_[0]);
  ::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr::InternalSwap(
      &::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(),
      &email_, lhs_arena,
      &other->email_, rhs_arena
  );
  ::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr::InternalSwap(
      &::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(),
      &plaintextpassword_, lhs_arena,
      &other->plaintextpassword_, rhs_arena
  );
  ::PROTOBUF_NAMESPACE_ID::internal::memswap<
      PROTOBUF_FIELD_OFFSET(RequestAuthenticateAccount, serverid_)
      + sizeof(RequestAuthenticateAccount::serverid_)
      - PROTOBUF_FIELD_OFFSET(RequestAuthenticateAccount, requestid_)>(
          reinterpret_cast<char*>(&requestid_),
          reinterpret_cast<char*>(&other->requestid_));
}

::PROTOBUF_NAMESPACE_ID::Metadata RequestAuthenticateAccount::GetMetadata() const {
  return ::PROTOBUF_NAMESPACE_ID::internal::AssignDescriptors(
      &descriptor_table_RequestAuthenticateAccount_2eproto_getter, &descriptor_table_RequestAuthenticateAccount_2eproto_once,
      file_level_metadata_RequestAuthenticateAccount_2eproto[0]);
}

// @@protoc_insertion_point(namespace_scope)
PROTOBUF_NAMESPACE_OPEN
template<> PROTOBUF_NOINLINE ::RequestAuthenticateAccount* Arena::CreateMaybeMessage< ::RequestAuthenticateAccount >(Arena* arena) {
  return Arena::CreateMessageInternal< ::RequestAuthenticateAccount >(arena);
}
PROTOBUF_NAMESPACE_CLOSE

// @@protoc_insertion_point(global_scope)
#include <google/protobuf/port_undef.inc>