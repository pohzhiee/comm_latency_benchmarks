// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: bench1.proto

#include "bench1.pb.h"

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
namespace pb {
namespace Bench1 {
class Bench1DefaultTypeInternal {
 public:
  ::PROTOBUF_NAMESPACE_ID::internal::ExplicitlyConstructed<Bench1> _instance;
} _Bench1_default_instance_;
}  // namespace Bench1
}  // namespace pb
static void InitDefaultsscc_info_Bench1_bench1_2eproto() {
  GOOGLE_PROTOBUF_VERIFY_VERSION;

  {
    void* ptr = &::pb::Bench1::_Bench1_default_instance_;
    new (ptr) ::pb::Bench1::Bench1();
    ::PROTOBUF_NAMESPACE_ID::internal::OnShutdownDestroyMessage(ptr);
  }
  ::pb::Bench1::Bench1::InitAsDefaultInstance();
}

::PROTOBUF_NAMESPACE_ID::internal::SCCInfo<0> scc_info_Bench1_bench1_2eproto =
    {{ATOMIC_VAR_INIT(::PROTOBUF_NAMESPACE_ID::internal::SCCInfoBase::kUninitialized), 0, 0, InitDefaultsscc_info_Bench1_bench1_2eproto}, {}};

static ::PROTOBUF_NAMESPACE_ID::Metadata file_level_metadata_bench1_2eproto[1];
static constexpr ::PROTOBUF_NAMESPACE_ID::EnumDescriptor const** file_level_enum_descriptors_bench1_2eproto = nullptr;
static constexpr ::PROTOBUF_NAMESPACE_ID::ServiceDescriptor const** file_level_service_descriptors_bench1_2eproto = nullptr;

const ::PROTOBUF_NAMESPACE_ID::uint32 TableStruct_bench1_2eproto::offsets[] PROTOBUF_SECTION_VARIABLE(protodesc_cold) = {
  ~0u,  // no _has_bits_
  PROTOBUF_FIELD_OFFSET(::pb::Bench1::Bench1, _internal_metadata_),
  ~0u,  // no _extensions_
  ~0u,  // no _oneof_case_
  ~0u,  // no _weak_field_map_
  PROTOBUF_FIELD_OFFSET(::pb::Bench1::Bench1, time_),
  PROTOBUF_FIELD_OFFSET(::pb::Bench1::Bench1, nrows_),
  PROTOBUF_FIELD_OFFSET(::pb::Bench1::Bench1, ncols_),
  PROTOBUF_FIELD_OFFSET(::pb::Bench1::Bench1, data_),
};
static const ::PROTOBUF_NAMESPACE_ID::internal::MigrationSchema schemas[] PROTOBUF_SECTION_VARIABLE(protodesc_cold) = {
  { 0, -1, sizeof(::pb::Bench1::Bench1)},
};

static ::PROTOBUF_NAMESPACE_ID::Message const * const file_default_instances[] = {
  reinterpret_cast<const ::PROTOBUF_NAMESPACE_ID::Message*>(&::pb::Bench1::_Bench1_default_instance_),
};

const char descriptor_table_protodef_bench1_2eproto[] PROTOBUF_SECTION_VARIABLE(protodesc_cold) =
  "\n\014bench1.proto\022\tpb.Bench1\"B\n\006Bench1\022\014\n\004t"
  "ime\030\001 \001(\004\022\r\n\005nrows\030\002 \001(\004\022\r\n\005ncols\030\003 \001(\004\022"
  "\014\n\004data\030\004 \003(\001b\006proto3"
  ;
static const ::PROTOBUF_NAMESPACE_ID::internal::DescriptorTable*const descriptor_table_bench1_2eproto_deps[1] = {
};
static ::PROTOBUF_NAMESPACE_ID::internal::SCCInfoBase*const descriptor_table_bench1_2eproto_sccs[1] = {
  &scc_info_Bench1_bench1_2eproto.base,
};
static ::PROTOBUF_NAMESPACE_ID::internal::once_flag descriptor_table_bench1_2eproto_once;
static bool descriptor_table_bench1_2eproto_initialized = false;
const ::PROTOBUF_NAMESPACE_ID::internal::DescriptorTable descriptor_table_bench1_2eproto = {
  &descriptor_table_bench1_2eproto_initialized, descriptor_table_protodef_bench1_2eproto, "bench1.proto", 101,
  &descriptor_table_bench1_2eproto_once, descriptor_table_bench1_2eproto_sccs, descriptor_table_bench1_2eproto_deps, 1, 0,
  schemas, file_default_instances, TableStruct_bench1_2eproto::offsets,
  file_level_metadata_bench1_2eproto, 1, file_level_enum_descriptors_bench1_2eproto, file_level_service_descriptors_bench1_2eproto,
};

// Force running AddDescriptors() at dynamic initialization time.
static bool dynamic_init_dummy_bench1_2eproto = (  ::PROTOBUF_NAMESPACE_ID::internal::AddDescriptors(&descriptor_table_bench1_2eproto), true);
namespace pb {
namespace Bench1 {

// ===================================================================

void Bench1::InitAsDefaultInstance() {
}
class Bench1::_Internal {
 public:
};

Bench1::Bench1()
  : ::PROTOBUF_NAMESPACE_ID::Message(), _internal_metadata_(nullptr) {
  SharedCtor();
  // @@protoc_insertion_point(constructor:pb.Bench1.Bench1)
}
Bench1::Bench1(const Bench1& from)
  : ::PROTOBUF_NAMESPACE_ID::Message(),
      _internal_metadata_(nullptr),
      data_(from.data_) {
  _internal_metadata_.MergeFrom(from._internal_metadata_);
  ::memcpy(&time_, &from.time_,
    static_cast<size_t>(reinterpret_cast<char*>(&ncols_) -
    reinterpret_cast<char*>(&time_)) + sizeof(ncols_));
  // @@protoc_insertion_point(copy_constructor:pb.Bench1.Bench1)
}

void Bench1::SharedCtor() {
  ::memset(&time_, 0, static_cast<size_t>(
      reinterpret_cast<char*>(&ncols_) -
      reinterpret_cast<char*>(&time_)) + sizeof(ncols_));
}

Bench1::~Bench1() {
  // @@protoc_insertion_point(destructor:pb.Bench1.Bench1)
  SharedDtor();
}

void Bench1::SharedDtor() {
}

void Bench1::SetCachedSize(int size) const {
  _cached_size_.Set(size);
}
const Bench1& Bench1::default_instance() {
  ::PROTOBUF_NAMESPACE_ID::internal::InitSCC(&::scc_info_Bench1_bench1_2eproto.base);
  return *internal_default_instance();
}


void Bench1::Clear() {
// @@protoc_insertion_point(message_clear_start:pb.Bench1.Bench1)
  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  data_.Clear();
  ::memset(&time_, 0, static_cast<size_t>(
      reinterpret_cast<char*>(&ncols_) -
      reinterpret_cast<char*>(&time_)) + sizeof(ncols_));
  _internal_metadata_.Clear();
}

const char* Bench1::_InternalParse(const char* ptr, ::PROTOBUF_NAMESPACE_ID::internal::ParseContext* ctx) {
#define CHK_(x) if (PROTOBUF_PREDICT_FALSE(!(x))) goto failure
  while (!ctx->Done(&ptr)) {
    ::PROTOBUF_NAMESPACE_ID::uint32 tag;
    ptr = ::PROTOBUF_NAMESPACE_ID::internal::ReadTag(ptr, &tag);
    CHK_(ptr);
    switch (tag >> 3) {
      // uint64 time = 1;
      case 1:
        if (PROTOBUF_PREDICT_TRUE(static_cast<::PROTOBUF_NAMESPACE_ID::uint8>(tag) == 8)) {
          time_ = ::PROTOBUF_NAMESPACE_ID::internal::ReadVarint(&ptr);
          CHK_(ptr);
        } else goto handle_unusual;
        continue;
      // uint64 nrows = 2;
      case 2:
        if (PROTOBUF_PREDICT_TRUE(static_cast<::PROTOBUF_NAMESPACE_ID::uint8>(tag) == 16)) {
          nrows_ = ::PROTOBUF_NAMESPACE_ID::internal::ReadVarint(&ptr);
          CHK_(ptr);
        } else goto handle_unusual;
        continue;
      // uint64 ncols = 3;
      case 3:
        if (PROTOBUF_PREDICT_TRUE(static_cast<::PROTOBUF_NAMESPACE_ID::uint8>(tag) == 24)) {
          ncols_ = ::PROTOBUF_NAMESPACE_ID::internal::ReadVarint(&ptr);
          CHK_(ptr);
        } else goto handle_unusual;
        continue;
      // repeated double data = 4;
      case 4:
        if (PROTOBUF_PREDICT_TRUE(static_cast<::PROTOBUF_NAMESPACE_ID::uint8>(tag) == 34)) {
          ptr = ::PROTOBUF_NAMESPACE_ID::internal::PackedDoubleParser(_internal_mutable_data(), ptr, ctx);
          CHK_(ptr);
        } else if (static_cast<::PROTOBUF_NAMESPACE_ID::uint8>(tag) == 33) {
          _internal_add_data(::PROTOBUF_NAMESPACE_ID::internal::UnalignedLoad<double>(ptr));
          ptr += sizeof(double);
        } else goto handle_unusual;
        continue;
      default: {
      handle_unusual:
        if ((tag & 7) == 4 || tag == 0) {
          ctx->SetLastTag(tag);
          goto success;
        }
        ptr = UnknownFieldParse(tag, &_internal_metadata_, ptr, ctx);
        CHK_(ptr != nullptr);
        continue;
      }
    }  // switch
  }  // while
success:
  return ptr;
failure:
  ptr = nullptr;
  goto success;
#undef CHK_
}

::PROTOBUF_NAMESPACE_ID::uint8* Bench1::_InternalSerialize(
    ::PROTOBUF_NAMESPACE_ID::uint8* target, ::PROTOBUF_NAMESPACE_ID::io::EpsCopyOutputStream* stream) const {
  // @@protoc_insertion_point(serialize_to_array_start:pb.Bench1.Bench1)
  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  (void) cached_has_bits;

  // uint64 time = 1;
  if (this->time() != 0) {
    target = stream->EnsureSpace(target);
    target = ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::WriteUInt64ToArray(1, this->_internal_time(), target);
  }

  // uint64 nrows = 2;
  if (this->nrows() != 0) {
    target = stream->EnsureSpace(target);
    target = ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::WriteUInt64ToArray(2, this->_internal_nrows(), target);
  }

  // uint64 ncols = 3;
  if (this->ncols() != 0) {
    target = stream->EnsureSpace(target);
    target = ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::WriteUInt64ToArray(3, this->_internal_ncols(), target);
  }

  // repeated double data = 4;
  if (this->_internal_data_size() > 0) {
    target = stream->WriteFixedPacked(4, _internal_data(), target);
  }

  if (PROTOBUF_PREDICT_FALSE(_internal_metadata_.have_unknown_fields())) {
    target = ::PROTOBUF_NAMESPACE_ID::internal::WireFormat::InternalSerializeUnknownFieldsToArray(
        _internal_metadata_.unknown_fields(), target, stream);
  }
  // @@protoc_insertion_point(serialize_to_array_end:pb.Bench1.Bench1)
  return target;
}

size_t Bench1::ByteSizeLong() const {
// @@protoc_insertion_point(message_byte_size_start:pb.Bench1.Bench1)
  size_t total_size = 0;

  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  // repeated double data = 4;
  {
    unsigned int count = static_cast<unsigned int>(this->_internal_data_size());
    size_t data_size = 8UL * count;
    if (data_size > 0) {
      total_size += 1 +
        ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::Int32Size(
            static_cast<::PROTOBUF_NAMESPACE_ID::int32>(data_size));
    }
    int cached_size = ::PROTOBUF_NAMESPACE_ID::internal::ToCachedSize(data_size);
    _data_cached_byte_size_.store(cached_size,
                                    std::memory_order_relaxed);
    total_size += data_size;
  }

  // uint64 time = 1;
  if (this->time() != 0) {
    total_size += 1 +
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::UInt64Size(
        this->_internal_time());
  }

  // uint64 nrows = 2;
  if (this->nrows() != 0) {
    total_size += 1 +
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::UInt64Size(
        this->_internal_nrows());
  }

  // uint64 ncols = 3;
  if (this->ncols() != 0) {
    total_size += 1 +
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::UInt64Size(
        this->_internal_ncols());
  }

  if (PROTOBUF_PREDICT_FALSE(_internal_metadata_.have_unknown_fields())) {
    return ::PROTOBUF_NAMESPACE_ID::internal::ComputeUnknownFieldsSize(
        _internal_metadata_, total_size, &_cached_size_);
  }
  int cached_size = ::PROTOBUF_NAMESPACE_ID::internal::ToCachedSize(total_size);
  SetCachedSize(cached_size);
  return total_size;
}

void Bench1::MergeFrom(const ::PROTOBUF_NAMESPACE_ID::Message& from) {
// @@protoc_insertion_point(generalized_merge_from_start:pb.Bench1.Bench1)
  GOOGLE_DCHECK_NE(&from, this);
  const Bench1* source =
      ::PROTOBUF_NAMESPACE_ID::DynamicCastToGenerated<Bench1>(
          &from);
  if (source == nullptr) {
  // @@protoc_insertion_point(generalized_merge_from_cast_fail:pb.Bench1.Bench1)
    ::PROTOBUF_NAMESPACE_ID::internal::ReflectionOps::Merge(from, this);
  } else {
  // @@protoc_insertion_point(generalized_merge_from_cast_success:pb.Bench1.Bench1)
    MergeFrom(*source);
  }
}

void Bench1::MergeFrom(const Bench1& from) {
// @@protoc_insertion_point(class_specific_merge_from_start:pb.Bench1.Bench1)
  GOOGLE_DCHECK_NE(&from, this);
  _internal_metadata_.MergeFrom(from._internal_metadata_);
  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  (void) cached_has_bits;

  data_.MergeFrom(from.data_);
  if (from.time() != 0) {
    _internal_set_time(from._internal_time());
  }
  if (from.nrows() != 0) {
    _internal_set_nrows(from._internal_nrows());
  }
  if (from.ncols() != 0) {
    _internal_set_ncols(from._internal_ncols());
  }
}

void Bench1::CopyFrom(const ::PROTOBUF_NAMESPACE_ID::Message& from) {
// @@protoc_insertion_point(generalized_copy_from_start:pb.Bench1.Bench1)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

void Bench1::CopyFrom(const Bench1& from) {
// @@protoc_insertion_point(class_specific_copy_from_start:pb.Bench1.Bench1)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool Bench1::IsInitialized() const {
  return true;
}

void Bench1::InternalSwap(Bench1* other) {
  using std::swap;
  _internal_metadata_.Swap(&other->_internal_metadata_);
  data_.InternalSwap(&other->data_);
  swap(time_, other->time_);
  swap(nrows_, other->nrows_);
  swap(ncols_, other->ncols_);
}

::PROTOBUF_NAMESPACE_ID::Metadata Bench1::GetMetadata() const {
  return GetMetadataStatic();
}


// @@protoc_insertion_point(namespace_scope)
}  // namespace Bench1
}  // namespace pb
PROTOBUF_NAMESPACE_OPEN
template<> PROTOBUF_NOINLINE ::pb::Bench1::Bench1* Arena::CreateMaybeMessage< ::pb::Bench1::Bench1 >(Arena* arena) {
  return Arena::CreateInternal< ::pb::Bench1::Bench1 >(arena);
}
PROTOBUF_NAMESPACE_CLOSE

// @@protoc_insertion_point(global_scope)
#include <google/protobuf/port_undef.inc>