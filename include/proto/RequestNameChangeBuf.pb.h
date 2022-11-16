// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: RequestNameChangeBuf.proto

#ifndef GOOGLE_PROTOBUF_INCLUDED_RequestNameChangeBuf_2eproto
#define GOOGLE_PROTOBUF_INCLUDED_RequestNameChangeBuf_2eproto

#include <limits>
#include <string>

#include <google/protobuf/port_def.inc>
#if PROTOBUF_VERSION < 3018000
#error This file was generated by a newer version of protoc which is
#error incompatible with your Protocol Buffer headers. Please update
#error your headers.
#endif
#if 3018001 < PROTOBUF_MIN_PROTOC_VERSION
#error This file was generated by an older version of protoc which is
#error incompatible with your Protocol Buffer headers. Please
#error regenerate this file with a newer version of protoc.
#endif

#include <google/protobuf/port_undef.inc>
#include <google/protobuf/io/coded_stream.h>
#include <google/protobuf/arena.h>
#include <google/protobuf/arenastring.h>
#include <google/protobuf/generated_message_table_driven.h>
#include <google/protobuf/generated_message_util.h>
#include <google/protobuf/metadata_lite.h>
#include <google/protobuf/generated_message_reflection.h>
#include <google/protobuf/message.h>
#include <google/protobuf/repeated_field.h>  // IWYU pragma: export
#include <google/protobuf/extension_set.h>  // IWYU pragma: export
#include <google/protobuf/unknown_field_set.h>
// @@protoc_insertion_point(includes)
#include <google/protobuf/port_def.inc>
#define PROTOBUF_INTERNAL_EXPORT_RequestNameChangeBuf_2eproto
PROTOBUF_NAMESPACE_OPEN
namespace internal {
class AnyMetadata;
}  // namespace internal
PROTOBUF_NAMESPACE_CLOSE

// Internal implementation detail -- do not use these members.
struct TableStruct_RequestNameChangeBuf_2eproto {
  static const ::PROTOBUF_NAMESPACE_ID::internal::ParseTableField entries[]
    PROTOBUF_SECTION_VARIABLE(protodesc_cold);
  static const ::PROTOBUF_NAMESPACE_ID::internal::AuxiliaryParseTableField aux[]
    PROTOBUF_SECTION_VARIABLE(protodesc_cold);
  static const ::PROTOBUF_NAMESPACE_ID::internal::ParseTable schema[1]
    PROTOBUF_SECTION_VARIABLE(protodesc_cold);
  static const ::PROTOBUF_NAMESPACE_ID::internal::FieldMetadata field_metadata[];
  static const ::PROTOBUF_NAMESPACE_ID::internal::SerializationTable serialization_table[];
  static const ::PROTOBUF_NAMESPACE_ID::uint32 offsets[];
};
extern const ::PROTOBUF_NAMESPACE_ID::internal::DescriptorTable descriptor_table_RequestNameChangeBuf_2eproto;
class RequestNameChangeBuf;
struct RequestNameChangeBufDefaultTypeInternal;
extern RequestNameChangeBufDefaultTypeInternal _RequestNameChangeBuf_default_instance_;
PROTOBUF_NAMESPACE_OPEN
template<> ::RequestNameChangeBuf* Arena::CreateMaybeMessage<::RequestNameChangeBuf>(Arena*);
PROTOBUF_NAMESPACE_CLOSE

// ===================================================================

class RequestNameChangeBuf final :
    public ::PROTOBUF_NAMESPACE_ID::Message /* @@protoc_insertion_point(class_definition:RequestNameChangeBuf) */ {
 public:
  inline RequestNameChangeBuf() : RequestNameChangeBuf(nullptr) {}
  ~RequestNameChangeBuf() override;
  explicit constexpr RequestNameChangeBuf(::PROTOBUF_NAMESPACE_ID::internal::ConstantInitialized);

  RequestNameChangeBuf(const RequestNameChangeBuf& from);
  RequestNameChangeBuf(RequestNameChangeBuf&& from) noexcept
    : RequestNameChangeBuf() {
    *this = ::std::move(from);
  }

  inline RequestNameChangeBuf& operator=(const RequestNameChangeBuf& from) {
    CopyFrom(from);
    return *this;
  }
  inline RequestNameChangeBuf& operator=(RequestNameChangeBuf&& from) noexcept {
    if (this == &from) return *this;
    if (GetOwningArena() == from.GetOwningArena()
  #ifdef PROTOBUF_FORCE_COPY_IN_MOVE
        && GetOwningArena() != nullptr
  #endif  // !PROTOBUF_FORCE_COPY_IN_MOVE
    ) {
      InternalSwap(&from);
    } else {
      CopyFrom(from);
    }
    return *this;
  }

  inline const ::PROTOBUF_NAMESPACE_ID::UnknownFieldSet& unknown_fields() const {
    return _internal_metadata_.unknown_fields<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(::PROTOBUF_NAMESPACE_ID::UnknownFieldSet::default_instance);
  }
  inline ::PROTOBUF_NAMESPACE_ID::UnknownFieldSet* mutable_unknown_fields() {
    return _internal_metadata_.mutable_unknown_fields<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>();
  }

  static const ::PROTOBUF_NAMESPACE_ID::Descriptor* descriptor() {
    return GetDescriptor();
  }
  static const ::PROTOBUF_NAMESPACE_ID::Descriptor* GetDescriptor() {
    return default_instance().GetMetadata().descriptor;
  }
  static const ::PROTOBUF_NAMESPACE_ID::Reflection* GetReflection() {
    return default_instance().GetMetadata().reflection;
  }
  static const RequestNameChangeBuf& default_instance() {
    return *internal_default_instance();
  }
  static inline const RequestNameChangeBuf* internal_default_instance() {
    return reinterpret_cast<const RequestNameChangeBuf*>(
               &_RequestNameChangeBuf_default_instance_);
  }
  static constexpr int kIndexInFileMessages =
    0;

  friend void swap(RequestNameChangeBuf& a, RequestNameChangeBuf& b) {
    a.Swap(&b);
  }
  inline void Swap(RequestNameChangeBuf* other) {
    if (other == this) return;
    if (GetOwningArena() == other->GetOwningArena()) {
      InternalSwap(other);
    } else {
      ::PROTOBUF_NAMESPACE_ID::internal::GenericSwap(this, other);
    }
  }
  void UnsafeArenaSwap(RequestNameChangeBuf* other) {
    if (other == this) return;
    GOOGLE_DCHECK(GetOwningArena() == other->GetOwningArena());
    InternalSwap(other);
  }

  // implements Message ----------------------------------------------

  inline RequestNameChangeBuf* New() const final {
    return new RequestNameChangeBuf();
  }

  RequestNameChangeBuf* New(::PROTOBUF_NAMESPACE_ID::Arena* arena) const final {
    return CreateMaybeMessage<RequestNameChangeBuf>(arena);
  }
  using ::PROTOBUF_NAMESPACE_ID::Message::CopyFrom;
  void CopyFrom(const RequestNameChangeBuf& from);
  using ::PROTOBUF_NAMESPACE_ID::Message::MergeFrom;
  void MergeFrom(const RequestNameChangeBuf& from);
  private:
  static void MergeImpl(::PROTOBUF_NAMESPACE_ID::Message* to, const ::PROTOBUF_NAMESPACE_ID::Message& from);
  public:
  PROTOBUF_ATTRIBUTE_REINITIALIZES void Clear() final;
  bool IsInitialized() const final;

  size_t ByteSizeLong() const final;
  const char* _InternalParse(const char* ptr, ::PROTOBUF_NAMESPACE_ID::internal::ParseContext* ctx) final;
  ::PROTOBUF_NAMESPACE_ID::uint8* _InternalSerialize(
      ::PROTOBUF_NAMESPACE_ID::uint8* target, ::PROTOBUF_NAMESPACE_ID::io::EpsCopyOutputStream* stream) const final;
  int GetCachedSize() const final { return _cached_size_.Get(); }

  private:
  void SharedCtor();
  void SharedDtor();
  void SetCachedSize(int size) const final;
  void InternalSwap(RequestNameChangeBuf* other);
  friend class ::PROTOBUF_NAMESPACE_ID::internal::AnyMetadata;
  static ::PROTOBUF_NAMESPACE_ID::StringPiece FullMessageName() {
    return "RequestNameChangeBuf";
  }
  protected:
  explicit RequestNameChangeBuf(::PROTOBUF_NAMESPACE_ID::Arena* arena,
                       bool is_message_owned = false);
  private:
  static void ArenaDtor(void* object);
  inline void RegisterArenaDtor(::PROTOBUF_NAMESPACE_ID::Arena* arena);
  public:

  static const ClassData _class_data_;
  const ::PROTOBUF_NAMESPACE_ID::Message::ClassData*GetClassData() const final;

  ::PROTOBUF_NAMESPACE_ID::Metadata GetMetadata() const final;

  // nested types ----------------------------------------------------

  // accessors -------------------------------------------------------

  enum : int {
    kEmailFieldNumber = 4,
    kNewnameFieldNumber = 5,
    kRequestIdFieldNumber = 1,
    kClientIdFieldNumber = 2,
    kServerIdFieldNumber = 3,
  };
  // required string email = 4;
  bool has_email() const;
  private:
  bool _internal_has_email() const;
  public:
  void clear_email();
  const std::string& email() const;
  template <typename ArgT0 = const std::string&, typename... ArgT>
  void set_email(ArgT0&& arg0, ArgT... args);
  std::string* mutable_email();
  PROTOBUF_MUST_USE_RESULT std::string* release_email();
  void set_allocated_email(std::string* email);
  private:
  const std::string& _internal_email() const;
  inline PROTOBUF_ALWAYS_INLINE void _internal_set_email(const std::string& value);
  std::string* _internal_mutable_email();
  public:

  // required string newname = 5;
  bool has_newname() const;
  private:
  bool _internal_has_newname() const;
  public:
  void clear_newname();
  const std::string& newname() const;
  template <typename ArgT0 = const std::string&, typename... ArgT>
  void set_newname(ArgT0&& arg0, ArgT... args);
  std::string* mutable_newname();
  PROTOBUF_MUST_USE_RESULT std::string* release_newname();
  void set_allocated_newname(std::string* newname);
  private:
  const std::string& _internal_newname() const;
  inline PROTOBUF_ALWAYS_INLINE void _internal_set_newname(const std::string& value);
  std::string* _internal_mutable_newname();
  public:

  // required int32 requestId = 1;
  bool has_requestid() const;
  private:
  bool _internal_has_requestid() const;
  public:
  void clear_requestid();
  ::PROTOBUF_NAMESPACE_ID::int32 requestid() const;
  void set_requestid(::PROTOBUF_NAMESPACE_ID::int32 value);
  private:
  ::PROTOBUF_NAMESPACE_ID::int32 _internal_requestid() const;
  void _internal_set_requestid(::PROTOBUF_NAMESPACE_ID::int32 value);
  public:

  // required int32 clientId = 2;
  bool has_clientid() const;
  private:
  bool _internal_has_clientid() const;
  public:
  void clear_clientid();
  ::PROTOBUF_NAMESPACE_ID::int32 clientid() const;
  void set_clientid(::PROTOBUF_NAMESPACE_ID::int32 value);
  private:
  ::PROTOBUF_NAMESPACE_ID::int32 _internal_clientid() const;
  void _internal_set_clientid(::PROTOBUF_NAMESPACE_ID::int32 value);
  public:

  // required int32 serverId = 3;
  bool has_serverid() const;
  private:
  bool _internal_has_serverid() const;
  public:
  void clear_serverid();
  ::PROTOBUF_NAMESPACE_ID::int32 serverid() const;
  void set_serverid(::PROTOBUF_NAMESPACE_ID::int32 value);
  private:
  ::PROTOBUF_NAMESPACE_ID::int32 _internal_serverid() const;
  void _internal_set_serverid(::PROTOBUF_NAMESPACE_ID::int32 value);
  public:

  // @@protoc_insertion_point(class_scope:RequestNameChangeBuf)
 private:
  class _Internal;

  // helper for ByteSizeLong()
  size_t RequiredFieldsByteSizeFallback() const;

  template <typename T> friend class ::PROTOBUF_NAMESPACE_ID::Arena::InternalHelper;
  typedef void InternalArenaConstructable_;
  typedef void DestructorSkippable_;
  ::PROTOBUF_NAMESPACE_ID::internal::HasBits<1> _has_bits_;
  mutable ::PROTOBUF_NAMESPACE_ID::internal::CachedSize _cached_size_;
  ::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr email_;
  ::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr newname_;
  ::PROTOBUF_NAMESPACE_ID::int32 requestid_;
  ::PROTOBUF_NAMESPACE_ID::int32 clientid_;
  ::PROTOBUF_NAMESPACE_ID::int32 serverid_;
  friend struct ::TableStruct_RequestNameChangeBuf_2eproto;
};
// ===================================================================


// ===================================================================

#ifdef __GNUC__
  #pragma GCC diagnostic push
  #pragma GCC diagnostic ignored "-Wstrict-aliasing"
#endif  // __GNUC__
// RequestNameChangeBuf

// required int32 requestId = 1;
inline bool RequestNameChangeBuf::_internal_has_requestid() const {
  bool value = (_has_bits_[0] & 0x00000004u) != 0;
  return value;
}
inline bool RequestNameChangeBuf::has_requestid() const {
  return _internal_has_requestid();
}
inline void RequestNameChangeBuf::clear_requestid() {
  requestid_ = 0;
  _has_bits_[0] &= ~0x00000004u;
}
inline ::PROTOBUF_NAMESPACE_ID::int32 RequestNameChangeBuf::_internal_requestid() const {
  return requestid_;
}
inline ::PROTOBUF_NAMESPACE_ID::int32 RequestNameChangeBuf::requestid() const {
  // @@protoc_insertion_point(field_get:RequestNameChangeBuf.requestId)
  return _internal_requestid();
}
inline void RequestNameChangeBuf::_internal_set_requestid(::PROTOBUF_NAMESPACE_ID::int32 value) {
  _has_bits_[0] |= 0x00000004u;
  requestid_ = value;
}
inline void RequestNameChangeBuf::set_requestid(::PROTOBUF_NAMESPACE_ID::int32 value) {
  _internal_set_requestid(value);
  // @@protoc_insertion_point(field_set:RequestNameChangeBuf.requestId)
}

// required int32 clientId = 2;
inline bool RequestNameChangeBuf::_internal_has_clientid() const {
  bool value = (_has_bits_[0] & 0x00000008u) != 0;
  return value;
}
inline bool RequestNameChangeBuf::has_clientid() const {
  return _internal_has_clientid();
}
inline void RequestNameChangeBuf::clear_clientid() {
  clientid_ = 0;
  _has_bits_[0] &= ~0x00000008u;
}
inline ::PROTOBUF_NAMESPACE_ID::int32 RequestNameChangeBuf::_internal_clientid() const {
  return clientid_;
}
inline ::PROTOBUF_NAMESPACE_ID::int32 RequestNameChangeBuf::clientid() const {
  // @@protoc_insertion_point(field_get:RequestNameChangeBuf.clientId)
  return _internal_clientid();
}
inline void RequestNameChangeBuf::_internal_set_clientid(::PROTOBUF_NAMESPACE_ID::int32 value) {
  _has_bits_[0] |= 0x00000008u;
  clientid_ = value;
}
inline void RequestNameChangeBuf::set_clientid(::PROTOBUF_NAMESPACE_ID::int32 value) {
  _internal_set_clientid(value);
  // @@protoc_insertion_point(field_set:RequestNameChangeBuf.clientId)
}

// required int32 serverId = 3;
inline bool RequestNameChangeBuf::_internal_has_serverid() const {
  bool value = (_has_bits_[0] & 0x00000010u) != 0;
  return value;
}
inline bool RequestNameChangeBuf::has_serverid() const {
  return _internal_has_serverid();
}
inline void RequestNameChangeBuf::clear_serverid() {
  serverid_ = 0;
  _has_bits_[0] &= ~0x00000010u;
}
inline ::PROTOBUF_NAMESPACE_ID::int32 RequestNameChangeBuf::_internal_serverid() const {
  return serverid_;
}
inline ::PROTOBUF_NAMESPACE_ID::int32 RequestNameChangeBuf::serverid() const {
  // @@protoc_insertion_point(field_get:RequestNameChangeBuf.serverId)
  return _internal_serverid();
}
inline void RequestNameChangeBuf::_internal_set_serverid(::PROTOBUF_NAMESPACE_ID::int32 value) {
  _has_bits_[0] |= 0x00000010u;
  serverid_ = value;
}
inline void RequestNameChangeBuf::set_serverid(::PROTOBUF_NAMESPACE_ID::int32 value) {
  _internal_set_serverid(value);
  // @@protoc_insertion_point(field_set:RequestNameChangeBuf.serverId)
}

// required string email = 4;
inline bool RequestNameChangeBuf::_internal_has_email() const {
  bool value = (_has_bits_[0] & 0x00000001u) != 0;
  return value;
}
inline bool RequestNameChangeBuf::has_email() const {
  return _internal_has_email();
}
inline void RequestNameChangeBuf::clear_email() {
  email_.ClearToEmpty();
  _has_bits_[0] &= ~0x00000001u;
}
inline const std::string& RequestNameChangeBuf::email() const {
  // @@protoc_insertion_point(field_get:RequestNameChangeBuf.email)
  return _internal_email();
}
template <typename ArgT0, typename... ArgT>
inline PROTOBUF_ALWAYS_INLINE
void RequestNameChangeBuf::set_email(ArgT0&& arg0, ArgT... args) {
 _has_bits_[0] |= 0x00000001u;
 email_.Set(::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr::EmptyDefault{}, static_cast<ArgT0 &&>(arg0), args..., GetArenaForAllocation());
  // @@protoc_insertion_point(field_set:RequestNameChangeBuf.email)
}
inline std::string* RequestNameChangeBuf::mutable_email() {
  std::string* _s = _internal_mutable_email();
  // @@protoc_insertion_point(field_mutable:RequestNameChangeBuf.email)
  return _s;
}
inline const std::string& RequestNameChangeBuf::_internal_email() const {
  return email_.Get();
}
inline void RequestNameChangeBuf::_internal_set_email(const std::string& value) {
  _has_bits_[0] |= 0x00000001u;
  email_.Set(::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr::EmptyDefault{}, value, GetArenaForAllocation());
}
inline std::string* RequestNameChangeBuf::_internal_mutable_email() {
  _has_bits_[0] |= 0x00000001u;
  return email_.Mutable(::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr::EmptyDefault{}, GetArenaForAllocation());
}
inline std::string* RequestNameChangeBuf::release_email() {
  // @@protoc_insertion_point(field_release:RequestNameChangeBuf.email)
  if (!_internal_has_email()) {
    return nullptr;
  }
  _has_bits_[0] &= ~0x00000001u;
  return email_.ReleaseNonDefault(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), GetArenaForAllocation());
}
inline void RequestNameChangeBuf::set_allocated_email(std::string* email) {
  if (email != nullptr) {
    _has_bits_[0] |= 0x00000001u;
  } else {
    _has_bits_[0] &= ~0x00000001u;
  }
  email_.SetAllocated(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), email,
      GetArenaForAllocation());
  // @@protoc_insertion_point(field_set_allocated:RequestNameChangeBuf.email)
}

// required string newname = 5;
inline bool RequestNameChangeBuf::_internal_has_newname() const {
  bool value = (_has_bits_[0] & 0x00000002u) != 0;
  return value;
}
inline bool RequestNameChangeBuf::has_newname() const {
  return _internal_has_newname();
}
inline void RequestNameChangeBuf::clear_newname() {
  newname_.ClearToEmpty();
  _has_bits_[0] &= ~0x00000002u;
}
inline const std::string& RequestNameChangeBuf::newname() const {
  // @@protoc_insertion_point(field_get:RequestNameChangeBuf.newname)
  return _internal_newname();
}
template <typename ArgT0, typename... ArgT>
inline PROTOBUF_ALWAYS_INLINE
void RequestNameChangeBuf::set_newname(ArgT0&& arg0, ArgT... args) {
 _has_bits_[0] |= 0x00000002u;
 newname_.Set(::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr::EmptyDefault{}, static_cast<ArgT0 &&>(arg0), args..., GetArenaForAllocation());
  // @@protoc_insertion_point(field_set:RequestNameChangeBuf.newname)
}
inline std::string* RequestNameChangeBuf::mutable_newname() {
  std::string* _s = _internal_mutable_newname();
  // @@protoc_insertion_point(field_mutable:RequestNameChangeBuf.newname)
  return _s;
}
inline const std::string& RequestNameChangeBuf::_internal_newname() const {
  return newname_.Get();
}
inline void RequestNameChangeBuf::_internal_set_newname(const std::string& value) {
  _has_bits_[0] |= 0x00000002u;
  newname_.Set(::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr::EmptyDefault{}, value, GetArenaForAllocation());
}
inline std::string* RequestNameChangeBuf::_internal_mutable_newname() {
  _has_bits_[0] |= 0x00000002u;
  return newname_.Mutable(::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr::EmptyDefault{}, GetArenaForAllocation());
}
inline std::string* RequestNameChangeBuf::release_newname() {
  // @@protoc_insertion_point(field_release:RequestNameChangeBuf.newname)
  if (!_internal_has_newname()) {
    return nullptr;
  }
  _has_bits_[0] &= ~0x00000002u;
  return newname_.ReleaseNonDefault(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), GetArenaForAllocation());
}
inline void RequestNameChangeBuf::set_allocated_newname(std::string* newname) {
  if (newname != nullptr) {
    _has_bits_[0] |= 0x00000002u;
  } else {
    _has_bits_[0] &= ~0x00000002u;
  }
  newname_.SetAllocated(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), newname,
      GetArenaForAllocation());
  // @@protoc_insertion_point(field_set_allocated:RequestNameChangeBuf.newname)
}

#ifdef __GNUC__
  #pragma GCC diagnostic pop
#endif  // __GNUC__

// @@protoc_insertion_point(namespace_scope)


// @@protoc_insertion_point(global_scope)

#include <google/protobuf/port_undef.inc>
#endif  // GOOGLE_PROTOBUF_INCLUDED_GOOGLE_PROTOBUF_INCLUDED_RequestNameChangeBuf_2eproto
