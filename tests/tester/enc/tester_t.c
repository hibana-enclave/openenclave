#include <openenclave/enclave.h>
#include <stdlib.h>
#include "tester_t.h"
OE_INLINE void* _ConstMemcpy(
    const void* dest, 
    const void* src,
    size_t n)
{
    return OE_Memcpy((void*)dest, src, n);
}


/*
********************************************************************************
**
** Type Information
**
********************************************************************************
*/

extern const OE_StructTI Date_ti;

static const OE_FieldTI _Date_fields_ti[] =
{
    {
        0, /* flags */
        "mm", /* name */
        OE_UINT32_T, /* type */
        NULL, /* structTI */
        NULL, /* countField */
        OE_OFFSETOF(struct Date, mm),
        sizeof(uint32_t), /* size */
        0, /* subscript */
    },
    {
        0, /* flags */
        "dd", /* name */
        OE_UINT32_T, /* type */
        NULL, /* structTI */
        NULL, /* countField */
        OE_OFFSETOF(struct Date, dd),
        sizeof(uint32_t), /* size */
        0, /* subscript */
    },
    {
        0, /* flags */
        "yyyy", /* name */
        OE_UINT32_T, /* type */
        NULL, /* structTI */
        NULL, /* countField */
        OE_OFFSETOF(struct Date, yyyy),
        sizeof(uint32_t), /* size */
        0, /* subscript */
    },
};

const OE_StructTI Date_ti =
{
    0, /* flags */
    "Date", /* name */
    sizeof(struct Date), /* size */
    _Date_fields_ti, /* fields */
    OE_COUNTOF(_Date_fields_ti) /* nfields */
};

extern const OE_StructTI Object_ti;

static const OE_FieldTI _Object_fields_ti[] =
{
    {
        0, /* flags */
        "id", /* name */
        OE_SIZE_T, /* type */
        NULL, /* structTI */
        NULL, /* countField */
        OE_OFFSETOF(struct Object, id),
        sizeof(size_t), /* size */
        0, /* subscript */
    },
    {
        OE_FLAG_PTR|OE_FLAG_STRING, /* flags */
        "name", /* name */
        OE_CHAR_T, /* type */
        NULL, /* structTI */
        NULL, /* countField */
        OE_OFFSETOF(struct Object, name),
        sizeof(void*), /* size */
        0, /* subscript */
    },
};

const OE_StructTI Object_ti =
{
    0, /* flags */
    "Object", /* name */
    sizeof(struct Object), /* size */
    _Object_fields_ti, /* fields */
    OE_COUNTOF(_Object_fields_ti) /* nfields */
};

extern const OE_StructTI Node_ti;

static const OE_FieldTI _Node_fields_ti[] =
{
    {
        0, /* flags */
        "value", /* name */
        OE_UINT32_T, /* type */
        NULL, /* structTI */
        NULL, /* countField */
        OE_OFFSETOF(struct Node, value),
        sizeof(uint32_t), /* size */
        0, /* subscript */
    },
    {
        OE_FLAG_PTR|OE_FLAG_COUNT, /* flags */
        "next", /* name */
        OE_STRUCT_T, /* type */
        &Node_ti, /* structTI */
        "1", /* countField */
        OE_OFFSETOF(struct Node, next),
        sizeof(void*), /* size */
        0, /* subscript */
    },
};

const OE_StructTI Node_ti =
{
    0, /* flags */
    "Node", /* name */
    sizeof(struct Node), /* size */
    _Node_fields_ti, /* fields */
    OE_COUNTOF(_Node_fields_ti) /* nfields */
};

struct ReturnVoidArgs
{
    unsigned char __pad0[4];
    int __dummy;
};

extern const OE_StructTI ReturnVoidArgs_ti;

static const OE_FieldTI _ReturnVoidArgs_fields_ti[] =
{
};

const OE_StructTI ReturnVoidArgs_ti =
{
    0, /* flags */
    "ReturnVoid", /* name */
    sizeof(struct ReturnVoidArgs), /* size */
    _ReturnVoidArgs_fields_ti, /* params */
    OE_COUNTOF(_ReturnVoidArgs_fields_ti) /* nparams */
};

struct ReturnUint32Args
{
    uint32_t ret;
    unsigned char __pad1[4];
};

extern const OE_StructTI ReturnUint32Args_ti;

static const OE_FieldTI _ReturnUint32Args_fields_ti[] =
{
    {
        OE_FLAG_ECALL, /* flags */
        "ret", /* name */
        OE_UINT32_T, /* type */
        NULL, /* structTI */
        NULL, /* countParam */
        OE_OFFSETOF(struct ReturnUint32Args, ret),
        sizeof(uint32_t), /* size */
        0, /* subscript */
    },
};

const OE_StructTI ReturnUint32Args_ti =
{
    0, /* flags */
    "ReturnUint32", /* name */
    sizeof(struct ReturnUint32Args), /* size */
    _ReturnUint32Args_fields_ti, /* params */
    OE_COUNTOF(_ReturnUint32Args_fields_ti) /* nparams */
};

struct ReturnStrArgs
{
    char *ret;
    unsigned char __pad1[4];
};

extern const OE_StructTI ReturnStrArgs_ti;

static const OE_FieldTI _ReturnStrArgs_fields_ti[] =
{
    {
        OE_FLAG_ECALL|OE_FLAG_PTR|OE_FLAG_STRING, /* flags */
        "ret", /* name */
        OE_CHAR_T, /* type */
        NULL, /* structTI */
        NULL, /* countParam */
        OE_OFFSETOF(struct ReturnStrArgs, ret),
        sizeof(void*), /* size */
        0, /* subscript */
    },
};

const OE_StructTI ReturnStrArgs_ti =
{
    0, /* flags */
    "ReturnStr", /* name */
    sizeof(struct ReturnStrArgs), /* size */
    _ReturnStrArgs_fields_ti, /* params */
    OE_COUNTOF(_ReturnStrArgs_fields_ti) /* nparams */
};

struct ReturnDateArgs
{
    struct Date ret;
    unsigned char __pad1[4];
};

extern const OE_StructTI ReturnDateArgs_ti;

static const OE_FieldTI _ReturnDateArgs_fields_ti[] =
{
    {
        OE_FLAG_ECALL, /* flags */
        "ret", /* name */
        OE_STRUCT_T, /* type */
        &Date_ti, /* structTI */
        NULL, /* countParam */
        OE_OFFSETOF(struct ReturnDateArgs, ret),
        sizeof(struct Date), /* size */
        0, /* subscript */
    },
};

const OE_StructTI ReturnDateArgs_ti =
{
    0, /* flags */
    "ReturnDate", /* name */
    sizeof(struct ReturnDateArgs), /* size */
    _ReturnDateArgs_fields_ti, /* params */
    OE_COUNTOF(_ReturnDateArgs_fields_ti) /* nparams */
};

struct ReturnObjectArgs
{
    struct Object ret;
    unsigned char __pad1[4];
};

extern const OE_StructTI ReturnObjectArgs_ti;

static const OE_FieldTI _ReturnObjectArgs_fields_ti[] =
{
    {
        OE_FLAG_ECALL, /* flags */
        "ret", /* name */
        OE_STRUCT_T, /* type */
        &Object_ti, /* structTI */
        NULL, /* countParam */
        OE_OFFSETOF(struct ReturnObjectArgs, ret),
        sizeof(struct Object), /* size */
        0, /* subscript */
    },
};

const OE_StructTI ReturnObjectArgs_ti =
{
    0, /* flags */
    "ReturnObject", /* name */
    sizeof(struct ReturnObjectArgs), /* size */
    _ReturnObjectArgs_fields_ti, /* params */
    OE_COUNTOF(_ReturnObjectArgs_fields_ti) /* nparams */
};

struct ReturnObjectsArgs
{
    struct Object *ret;
    unsigned char __pad1[4];
    size_t count;
    unsigned char __pad2[4];
};

extern const OE_StructTI ReturnObjectsArgs_ti;

static const OE_FieldTI _ReturnObjectsArgs_fields_ti[] =
{
    {
        OE_FLAG_ECALL|OE_FLAG_PTR|OE_FLAG_COUNT, /* flags */
        "ret", /* name */
        OE_STRUCT_T, /* type */
        &Object_ti, /* structTI */
        "count", /* countParam */
        OE_OFFSETOF(struct ReturnObjectsArgs, ret),
        sizeof(void*), /* size */
        0, /* subscript */
    },
    {
        OE_FLAG_IN, /* flags */
        "count", /* name */
        OE_SIZE_T, /* type */
        NULL, /* structName */
        NULL, /* countParam */
        OE_OFFSETOF(struct ReturnObjectsArgs, count),
        sizeof(size_t), /* size */
        0, /* subscript */
    },
};

const OE_StructTI ReturnObjectsArgs_ti =
{
    0, /* flags */
    "ReturnObjects", /* name */
    sizeof(struct ReturnObjectsArgs), /* size */
    _ReturnObjectsArgs_fields_ti, /* params */
    OE_COUNTOF(_ReturnObjectsArgs_fields_ti) /* nparams */
};

struct ReturnLinkedListArgs
{
    struct Node *ret;
    unsigned char __pad1[4];
};

extern const OE_StructTI ReturnLinkedListArgs_ti;

static const OE_FieldTI _ReturnLinkedListArgs_fields_ti[] =
{
    {
        OE_FLAG_ECALL|OE_FLAG_PTR|OE_FLAG_COUNT, /* flags */
        "ret", /* name */
        OE_STRUCT_T, /* type */
        &Node_ti, /* structTI */
        "1", /* countParam */
        OE_OFFSETOF(struct ReturnLinkedListArgs, ret),
        sizeof(void*), /* size */
        0, /* subscript */
    },
};

const OE_StructTI ReturnLinkedListArgs_ti =
{
    0, /* flags */
    "ReturnLinkedList", /* name */
    sizeof(struct ReturnLinkedListArgs), /* size */
    _ReturnLinkedListArgs_fields_ti, /* params */
    OE_COUNTOF(_ReturnLinkedListArgs_fields_ti) /* nparams */
};

struct TestStrdupArgs
{
    char *ret;
    unsigned char __pad1[4];
    const char *s;
    unsigned char __pad2[4];
};

extern const OE_StructTI TestStrdupArgs_ti;

static const OE_FieldTI _TestStrdupArgs_fields_ti[] =
{
    {
        OE_FLAG_ECALL|OE_FLAG_PTR|OE_FLAG_STRING, /* flags */
        "ret", /* name */
        OE_CHAR_T, /* type */
        NULL, /* structTI */
        NULL, /* countParam */
        OE_OFFSETOF(struct TestStrdupArgs, ret),
        sizeof(void*), /* size */
        0, /* subscript */
    },
    {
        OE_FLAG_IN|OE_FLAG_CONST|OE_FLAG_PTR|OE_FLAG_STRING, /* flags */
        "s", /* name */
        OE_CHAR_T, /* type */
        NULL, /* structName */
        NULL, /* countParam */
        OE_OFFSETOF(struct TestStrdupArgs, s),
        sizeof(void*), /* size */
        0, /* subscript */
    },
};

const OE_StructTI TestStrdupArgs_ti =
{
    0, /* flags */
    "TestStrdup", /* name */
    sizeof(struct TestStrdupArgs), /* size */
    _TestStrdupArgs_fields_ti, /* params */
    OE_COUNTOF(_TestStrdupArgs_fields_ti) /* nparams */
};

struct CopyObjectArgs
{
    int32_t ret;
    unsigned char __pad1[4];
    struct Object *dest;
    unsigned char __pad2[4];
    const struct Object *src;
    unsigned char __pad3[4];
};

extern const OE_StructTI CopyObjectArgs_ti;

static const OE_FieldTI _CopyObjectArgs_fields_ti[] =
{
    {
        OE_FLAG_ECALL, /* flags */
        "ret", /* name */
        OE_INT32_T, /* type */
        NULL, /* structTI */
        NULL, /* countParam */
        OE_OFFSETOF(struct CopyObjectArgs, ret),
        sizeof(int32_t), /* size */
        0, /* subscript */
    },
    {
        OE_FLAG_IN|OE_FLAG_OUT|OE_FLAG_PTR|OE_FLAG_COUNT, /* flags */
        "dest", /* name */
        OE_STRUCT_T, /* type */
        &Object_ti, /* structTI */
        "1", /* countParam */
        OE_OFFSETOF(struct CopyObjectArgs, dest),
        sizeof(void*), /* size */
        0, /* subscript */
    },
    {
        OE_FLAG_IN|OE_FLAG_CONST|OE_FLAG_PTR|OE_FLAG_COUNT, /* flags */
        "src", /* name */
        OE_STRUCT_T, /* type */
        &Object_ti, /* structTI */
        "1", /* countParam */
        OE_OFFSETOF(struct CopyObjectArgs, src),
        sizeof(void*), /* size */
        0, /* subscript */
    },
};

const OE_StructTI CopyObjectArgs_ti =
{
    0, /* flags */
    "CopyObject", /* name */
    sizeof(struct CopyObjectArgs), /* size */
    _CopyObjectArgs_fields_ti, /* params */
    OE_COUNTOF(_CopyObjectArgs_fields_ti) /* nparams */
};

struct CopyObjectsArgs
{
    int32_t ret;
    unsigned char __pad1[4];
    struct Object dest[2];
    unsigned char __pad2[4];
    const struct Object src[2];
    unsigned char __pad3[4];
};

extern const OE_StructTI CopyObjectsArgs_ti;

static const OE_FieldTI _CopyObjectsArgs_fields_ti[] =
{
    {
        OE_FLAG_ECALL, /* flags */
        "ret", /* name */
        OE_INT32_T, /* type */
        NULL, /* structTI */
        NULL, /* countParam */
        OE_OFFSETOF(struct CopyObjectsArgs, ret),
        sizeof(int32_t), /* size */
        0, /* subscript */
    },
    {
        OE_FLAG_OUT|OE_FLAG_ARRAY, /* flags */
        "dest", /* name */
        OE_STRUCT_T, /* type */
        &Object_ti, /* structTI */
        NULL, /* countParam */
        OE_OFFSETOF(struct CopyObjectsArgs, dest),
        sizeof(struct Object) * 2, /* size */
        2, /* subscript */
    },
    {
        OE_FLAG_IN|OE_FLAG_CONST|OE_FLAG_ARRAY, /* flags */
        "src", /* name */
        OE_STRUCT_T, /* type */
        &Object_ti, /* structTI */
        NULL, /* countParam */
        OE_OFFSETOF(struct CopyObjectsArgs, src),
        sizeof(struct Object) * 2, /* size */
        2, /* subscript */
    },
};

const OE_StructTI CopyObjectsArgs_ti =
{
    0, /* flags */
    "CopyObjects", /* name */
    sizeof(struct CopyObjectsArgs), /* size */
    _CopyObjectsArgs_fields_ti, /* params */
    OE_COUNTOF(_CopyObjectsArgs_fields_ti) /* nparams */
};

struct ECALL_MultipleParamsArgs
{
    int32_t ret;
    unsigned char __pad1[4];
    const char *strIn;
    unsigned char __pad2[4];
    uint32_t numIn;
    unsigned char __pad3[4];
    const struct Object *objectIn;
    unsigned char __pad4[4];
    char *strOut;
    unsigned char __pad5[4];
    uint32_t *numOut;
    unsigned char __pad6[4];
    struct Object *objectOut;
    unsigned char __pad7[4];
    struct Object *objectRefOut;
    unsigned char __pad8[4];
};

extern const OE_StructTI ECALL_MultipleParamsArgs_ti;

static const OE_FieldTI _ECALL_MultipleParamsArgs_fields_ti[] =
{
    {
        OE_FLAG_ECALL, /* flags */
        "ret", /* name */
        OE_INT32_T, /* type */
        NULL, /* structTI */
        NULL, /* countParam */
        OE_OFFSETOF(struct ECALL_MultipleParamsArgs, ret),
        sizeof(int32_t), /* size */
        0, /* subscript */
    },
    {
        OE_FLAG_IN|OE_FLAG_CONST|OE_FLAG_PTR|OE_FLAG_STRING, /* flags */
        "strIn", /* name */
        OE_CHAR_T, /* type */
        NULL, /* structName */
        NULL, /* countParam */
        OE_OFFSETOF(struct ECALL_MultipleParamsArgs, strIn),
        sizeof(void*), /* size */
        0, /* subscript */
    },
    {
        OE_FLAG_IN, /* flags */
        "numIn", /* name */
        OE_UINT32_T, /* type */
        NULL, /* structName */
        NULL, /* countParam */
        OE_OFFSETOF(struct ECALL_MultipleParamsArgs, numIn),
        sizeof(uint32_t), /* size */
        0, /* subscript */
    },
    {
        OE_FLAG_IN|OE_FLAG_CONST|OE_FLAG_PTR|OE_FLAG_COUNT, /* flags */
        "objectIn", /* name */
        OE_STRUCT_T, /* type */
        &Object_ti, /* structTI */
        "1", /* countParam */
        OE_OFFSETOF(struct ECALL_MultipleParamsArgs, objectIn),
        sizeof(void*), /* size */
        0, /* subscript */
    },
    {
        OE_FLAG_OUT|OE_FLAG_PTR|OE_FLAG_COUNT|OE_FLAG_STRING, /* flags */
        "strOut", /* name */
        OE_CHAR_T, /* type */
        NULL, /* structName */
        "128", /* countParam */
        OE_OFFSETOF(struct ECALL_MultipleParamsArgs, strOut),
        sizeof(void*), /* size */
        0, /* subscript */
    },
    {
        OE_FLAG_OUT|OE_FLAG_PTR|OE_FLAG_COUNT, /* flags */
        "numOut", /* name */
        OE_UINT32_T, /* type */
        NULL, /* structName */
        "1", /* countParam */
        OE_OFFSETOF(struct ECALL_MultipleParamsArgs, numOut),
        sizeof(void*), /* size */
        0, /* subscript */
    },
    {
        OE_FLAG_OUT|OE_FLAG_PTR|OE_FLAG_COUNT, /* flags */
        "objectOut", /* name */
        OE_STRUCT_T, /* type */
        &Object_ti, /* structTI */
        "1", /* countParam */
        OE_OFFSETOF(struct ECALL_MultipleParamsArgs, objectOut),
        sizeof(void*), /* size */
        0, /* subscript */
    },
    {
        OE_FLAG_OUT|OE_FLAG_REF|OE_FLAG_PTR|OE_FLAG_COUNT, /* flags */
        "objectRefOut", /* name */
        OE_STRUCT_T, /* type */
        &Object_ti, /* structTI */
        "1", /* countParam */
        OE_OFFSETOF(struct ECALL_MultipleParamsArgs, objectRefOut),
        sizeof(void*), /* size */
        0, /* subscript */
    },
};

const OE_StructTI ECALL_MultipleParamsArgs_ti =
{
    0, /* flags */
    "ECALL_MultipleParams", /* name */
    sizeof(struct ECALL_MultipleParamsArgs), /* size */
    _ECALL_MultipleParamsArgs_fields_ti, /* params */
    OE_COUNTOF(_ECALL_MultipleParamsArgs_fields_ti) /* nparams */
};

struct OCALL_MultipleParamsArgs
{
    int32_t ret;
    unsigned char __pad1[4];
    const char *strIn;
    unsigned char __pad2[4];
    uint32_t numIn;
    unsigned char __pad3[4];
    const struct Object *objectIn;
    unsigned char __pad4[4];
    char *strOut;
    unsigned char __pad5[4];
    uint32_t *numOut;
    unsigned char __pad6[4];
    struct Object *objectOut;
    unsigned char __pad7[4];
    struct Object *objectRefOut;
    unsigned char __pad8[4];
};

extern const OE_StructTI OCALL_MultipleParamsArgs_ti;

static const OE_FieldTI _OCALL_MultipleParamsArgs_fields_ti[] =
{
    {
        OE_FLAG_OCALL, /* flags */
        "ret", /* name */
        OE_INT32_T, /* type */
        NULL, /* structTI */
        NULL, /* countParam */
        OE_OFFSETOF(struct OCALL_MultipleParamsArgs, ret),
        sizeof(int32_t), /* size */
        0, /* subscript */
    },
    {
        OE_FLAG_IN|OE_FLAG_CONST|OE_FLAG_PTR|OE_FLAG_STRING, /* flags */
        "strIn", /* name */
        OE_CHAR_T, /* type */
        NULL, /* structName */
        NULL, /* countParam */
        OE_OFFSETOF(struct OCALL_MultipleParamsArgs, strIn),
        sizeof(void*), /* size */
        0, /* subscript */
    },
    {
        OE_FLAG_IN, /* flags */
        "numIn", /* name */
        OE_UINT32_T, /* type */
        NULL, /* structName */
        NULL, /* countParam */
        OE_OFFSETOF(struct OCALL_MultipleParamsArgs, numIn),
        sizeof(uint32_t), /* size */
        0, /* subscript */
    },
    {
        OE_FLAG_IN|OE_FLAG_CONST|OE_FLAG_PTR|OE_FLAG_COUNT, /* flags */
        "objectIn", /* name */
        OE_STRUCT_T, /* type */
        &Object_ti, /* structTI */
        "1", /* countParam */
        OE_OFFSETOF(struct OCALL_MultipleParamsArgs, objectIn),
        sizeof(void*), /* size */
        0, /* subscript */
    },
    {
        OE_FLAG_OUT|OE_FLAG_PTR|OE_FLAG_COUNT|OE_FLAG_STRING, /* flags */
        "strOut", /* name */
        OE_CHAR_T, /* type */
        NULL, /* structName */
        "128", /* countParam */
        OE_OFFSETOF(struct OCALL_MultipleParamsArgs, strOut),
        sizeof(void*), /* size */
        0, /* subscript */
    },
    {
        OE_FLAG_OUT|OE_FLAG_PTR|OE_FLAG_COUNT, /* flags */
        "numOut", /* name */
        OE_UINT32_T, /* type */
        NULL, /* structName */
        "1", /* countParam */
        OE_OFFSETOF(struct OCALL_MultipleParamsArgs, numOut),
        sizeof(void*), /* size */
        0, /* subscript */
    },
    {
        OE_FLAG_OUT|OE_FLAG_PTR|OE_FLAG_COUNT, /* flags */
        "objectOut", /* name */
        OE_STRUCT_T, /* type */
        &Object_ti, /* structTI */
        "1", /* countParam */
        OE_OFFSETOF(struct OCALL_MultipleParamsArgs, objectOut),
        sizeof(void*), /* size */
        0, /* subscript */
    },
    {
        OE_FLAG_OUT|OE_FLAG_REF|OE_FLAG_PTR|OE_FLAG_COUNT, /* flags */
        "objectRefOut", /* name */
        OE_STRUCT_T, /* type */
        &Object_ti, /* structTI */
        "1", /* countParam */
        OE_OFFSETOF(struct OCALL_MultipleParamsArgs, objectRefOut),
        sizeof(void*), /* size */
        0, /* subscript */
    },
};

const OE_StructTI OCALL_MultipleParamsArgs_ti =
{
    0, /* flags */
    "OCALL_MultipleParams", /* name */
    sizeof(struct OCALL_MultipleParamsArgs), /* size */
    _OCALL_MultipleParamsArgs_fields_ti, /* params */
    OE_COUNTOF(_OCALL_MultipleParamsArgs_fields_ti) /* nparams */
};

struct GetObjectRefArgs
{
    int32_t ret;
    unsigned char __pad1[4];
    struct Object *object;
    unsigned char __pad2[4];
};

extern const OE_StructTI GetObjectRefArgs_ti;

static const OE_FieldTI _GetObjectRefArgs_fields_ti[] =
{
    {
        OE_FLAG_ECALL, /* flags */
        "ret", /* name */
        OE_INT32_T, /* type */
        NULL, /* structTI */
        NULL, /* countParam */
        OE_OFFSETOF(struct GetObjectRefArgs, ret),
        sizeof(int32_t), /* size */
        0, /* subscript */
    },
    {
        OE_FLAG_OUT|OE_FLAG_REF|OE_FLAG_PTR|OE_FLAG_COUNT, /* flags */
        "object", /* name */
        OE_STRUCT_T, /* type */
        &Object_ti, /* structTI */
        "1", /* countParam */
        OE_OFFSETOF(struct GetObjectRefArgs, object),
        sizeof(void*), /* size */
        0, /* subscript */
    },
};

const OE_StructTI GetObjectRefArgs_ti =
{
    0, /* flags */
    "GetObjectRef", /* name */
    sizeof(struct GetObjectRefArgs), /* size */
    _GetObjectRefArgs_fields_ti, /* params */
    OE_COUNTOF(_GetObjectRefArgs_fields_ti) /* nparams */
};

struct ModifyObjectArgs
{
    int32_t ret;
    unsigned char __pad1[4];
    struct Object *object;
    unsigned char __pad2[4];
};

extern const OE_StructTI ModifyObjectArgs_ti;

static const OE_FieldTI _ModifyObjectArgs_fields_ti[] =
{
    {
        OE_FLAG_ECALL, /* flags */
        "ret", /* name */
        OE_INT32_T, /* type */
        NULL, /* structTI */
        NULL, /* countParam */
        OE_OFFSETOF(struct ModifyObjectArgs, ret),
        sizeof(int32_t), /* size */
        0, /* subscript */
    },
    {
        OE_FLAG_IN|OE_FLAG_OUT|OE_FLAG_PTR|OE_FLAG_COUNT, /* flags */
        "object", /* name */
        OE_STRUCT_T, /* type */
        &Object_ti, /* structTI */
        "1", /* countParam */
        OE_OFFSETOF(struct ModifyObjectArgs, object),
        sizeof(void*), /* size */
        0, /* subscript */
    },
};

const OE_StructTI ModifyObjectArgs_ti =
{
    0, /* flags */
    "ModifyObject", /* name */
    sizeof(struct ModifyObjectArgs), /* size */
    _ModifyObjectArgs_fields_ti, /* params */
    OE_COUNTOF(_ModifyObjectArgs_fields_ti) /* nparams */
};

struct TestStrlcpyArgs
{
    size_t ret;
    unsigned char __pad1[4];
    char *dest;
    unsigned char __pad2[4];
    const char *src;
    unsigned char __pad3[4];
    size_t dsize;
    unsigned char __pad4[4];
};

extern const OE_StructTI TestStrlcpyArgs_ti;

static const OE_FieldTI _TestStrlcpyArgs_fields_ti[] =
{
    {
        OE_FLAG_ECALL, /* flags */
        "ret", /* name */
        OE_SIZE_T, /* type */
        NULL, /* structTI */
        NULL, /* countParam */
        OE_OFFSETOF(struct TestStrlcpyArgs, ret),
        sizeof(size_t), /* size */
        0, /* subscript */
    },
    {
        OE_FLAG_OUT|OE_FLAG_PTR|OE_FLAG_COUNT|OE_FLAG_STRING, /* flags */
        "dest", /* name */
        OE_CHAR_T, /* type */
        NULL, /* structName */
        "dsize", /* countParam */
        OE_OFFSETOF(struct TestStrlcpyArgs, dest),
        sizeof(void*), /* size */
        0, /* subscript */
    },
    {
        OE_FLAG_IN|OE_FLAG_CONST|OE_FLAG_PTR|OE_FLAG_STRING, /* flags */
        "src", /* name */
        OE_CHAR_T, /* type */
        NULL, /* structName */
        NULL, /* countParam */
        OE_OFFSETOF(struct TestStrlcpyArgs, src),
        sizeof(void*), /* size */
        0, /* subscript */
    },
    {
        OE_FLAG_IN, /* flags */
        "dsize", /* name */
        OE_SIZE_T, /* type */
        NULL, /* structName */
        NULL, /* countParam */
        OE_OFFSETOF(struct TestStrlcpyArgs, dsize),
        sizeof(size_t), /* size */
        0, /* subscript */
    },
};

const OE_StructTI TestStrlcpyArgs_ti =
{
    0, /* flags */
    "TestStrlcpy", /* name */
    sizeof(struct TestStrlcpyArgs), /* size */
    _TestStrlcpyArgs_fields_ti, /* params */
    OE_COUNTOF(_TestStrlcpyArgs_fields_ti) /* nparams */
};

struct TestOptQualifierArgs
{
    size_t ret;
    unsigned char __pad1[4];
    char *p1;
    unsigned char __pad2[4];
    const char *p2;
    unsigned char __pad3[4];
    size_t p1size;
    unsigned char __pad4[4];
};

extern const OE_StructTI TestOptQualifierArgs_ti;

static const OE_FieldTI _TestOptQualifierArgs_fields_ti[] =
{
    {
        OE_FLAG_ECALL, /* flags */
        "ret", /* name */
        OE_SIZE_T, /* type */
        NULL, /* structTI */
        NULL, /* countParam */
        OE_OFFSETOF(struct TestOptQualifierArgs, ret),
        sizeof(size_t), /* size */
        0, /* subscript */
    },
    {
        OE_FLAG_OUT|OE_FLAG_PTR|OE_FLAG_COUNT|OE_FLAG_STRING|OE_FLAG_OPT, /* flags */
        "p1", /* name */
        OE_CHAR_T, /* type */
        NULL, /* structName */
        "p1size", /* countParam */
        OE_OFFSETOF(struct TestOptQualifierArgs, p1),
        sizeof(void*), /* size */
        0, /* subscript */
    },
    {
        OE_FLAG_IN|OE_FLAG_CONST|OE_FLAG_PTR|OE_FLAG_STRING|OE_FLAG_OPT, /* flags */
        "p2", /* name */
        OE_CHAR_T, /* type */
        NULL, /* structName */
        NULL, /* countParam */
        OE_OFFSETOF(struct TestOptQualifierArgs, p2),
        sizeof(void*), /* size */
        0, /* subscript */
    },
    {
        OE_FLAG_IN, /* flags */
        "p1size", /* name */
        OE_SIZE_T, /* type */
        NULL, /* structName */
        NULL, /* countParam */
        OE_OFFSETOF(struct TestOptQualifierArgs, p1size),
        sizeof(size_t), /* size */
        0, /* subscript */
    },
};

const OE_StructTI TestOptQualifierArgs_ti =
{
    0, /* flags */
    "TestOptQualifier", /* name */
    sizeof(struct TestOptQualifierArgs), /* size */
    _TestOptQualifierArgs_fields_ti, /* params */
    OE_COUNTOF(_TestOptQualifierArgs_fields_ti) /* nparams */
};

struct ReturnIntPtrArgs
{
    int *ret;
    unsigned char __pad1[4];
    int *p;
    unsigned char __pad2[4];
    size_t n;
    unsigned char __pad3[4];
};

extern const OE_StructTI ReturnIntPtrArgs_ti;

static const OE_FieldTI _ReturnIntPtrArgs_fields_ti[] =
{
    {
        OE_FLAG_ECALL|OE_FLAG_PTR|OE_FLAG_COUNT|OE_FLAG_OPT, /* flags */
        "ret", /* name */
        OE_INT_T, /* type */
        NULL, /* structTI */
        "n", /* countParam */
        OE_OFFSETOF(struct ReturnIntPtrArgs, ret),
        sizeof(void*), /* size */
        0, /* subscript */
    },
    {
        OE_FLAG_IN|OE_FLAG_OUT|OE_FLAG_PTR|OE_FLAG_COUNT|OE_FLAG_OPT, /* flags */
        "p", /* name */
        OE_INT_T, /* type */
        NULL, /* structName */
        "n", /* countParam */
        OE_OFFSETOF(struct ReturnIntPtrArgs, p),
        sizeof(void*), /* size */
        0, /* subscript */
    },
    {
        OE_FLAG_IN, /* flags */
        "n", /* name */
        OE_SIZE_T, /* type */
        NULL, /* structName */
        NULL, /* countParam */
        OE_OFFSETOF(struct ReturnIntPtrArgs, n),
        sizeof(size_t), /* size */
        0, /* subscript */
    },
};

const OE_StructTI ReturnIntPtrArgs_ti =
{
    0, /* flags */
    "ReturnIntPtr", /* name */
    sizeof(struct ReturnIntPtrArgs), /* size */
    _ReturnIntPtrArgs_fields_ti, /* params */
    OE_COUNTOF(_ReturnIntPtrArgs_fields_ti) /* nparams */
};

struct TestCallbackArgs
{
    unsigned char __pad0[4];
    void *func;
    unsigned char __pad1[4];
};

extern const OE_StructTI TestCallbackArgs_ti;

static const OE_FieldTI _TestCallbackArgs_fields_ti[] =
{
    {
        OE_FLAG_IN|OE_FLAG_PTR|OE_FLAG_UNCHECKED, /* flags */
        "func", /* name */
        OE_VOID_T, /* type */
        NULL, /* structName */
        NULL, /* countParam */
        OE_OFFSETOF(struct TestCallbackArgs, func),
        sizeof(void*), /* size */
        0, /* subscript */
    },
};

const OE_StructTI TestCallbackArgs_ti =
{
    0, /* flags */
    "TestCallback", /* name */
    sizeof(struct TestCallbackArgs), /* size */
    _TestCallbackArgs_fields_ti, /* params */
    OE_COUNTOF(_TestCallbackArgs_fields_ti) /* nparams */
};

struct TestIntPtrRefArgs
{
    bool ret;
    unsigned char __pad1[4];
    int *intPtrOut;
    unsigned char __pad2[4];
    size_t n;
    unsigned char __pad3[4];
};

extern const OE_StructTI TestIntPtrRefArgs_ti;

static const OE_FieldTI _TestIntPtrRefArgs_fields_ti[] =
{
    {
        OE_FLAG_ECALL, /* flags */
        "ret", /* name */
        OE_BOOL_T, /* type */
        NULL, /* structTI */
        NULL, /* countParam */
        OE_OFFSETOF(struct TestIntPtrRefArgs, ret),
        sizeof(bool), /* size */
        0, /* subscript */
    },
    {
        OE_FLAG_OUT|OE_FLAG_REF|OE_FLAG_PTR|OE_FLAG_COUNT, /* flags */
        "intPtrOut", /* name */
        OE_INT_T, /* type */
        NULL, /* structName */
        "n", /* countParam */
        OE_OFFSETOF(struct TestIntPtrRefArgs, intPtrOut),
        sizeof(void*), /* size */
        0, /* subscript */
    },
    {
        OE_FLAG_IN, /* flags */
        "n", /* name */
        OE_SIZE_T, /* type */
        NULL, /* structName */
        NULL, /* countParam */
        OE_OFFSETOF(struct TestIntPtrRefArgs, n),
        sizeof(size_t), /* size */
        0, /* subscript */
    },
};

const OE_StructTI TestIntPtrRefArgs_ti =
{
    0, /* flags */
    "TestIntPtrRef", /* name */
    sizeof(struct TestIntPtrRefArgs), /* size */
    _TestIntPtrRefArgs_fields_ti, /* params */
    OE_COUNTOF(_TestIntPtrRefArgs_fields_ti) /* nparams */
};

struct TestBufferOverunArgs
{
    unsigned char __pad0[4];
    char src[8];
    unsigned char __pad1[4];
};

extern const OE_StructTI TestBufferOverunArgs_ti;

static const OE_FieldTI _TestBufferOverunArgs_fields_ti[] =
{
    {
        OE_FLAG_OUT|OE_FLAG_ARRAY, /* flags */
        "src", /* name */
        OE_CHAR_T, /* type */
        NULL, /* structName */
        NULL, /* countParam */
        OE_OFFSETOF(struct TestBufferOverunArgs, src),
        sizeof(char) * 8, /* size */
        8, /* subscript */
    },
};

const OE_StructTI TestBufferOverunArgs_ti =
{
    0, /* flags */
    "TestBufferOverun", /* name */
    sizeof(struct TestBufferOverunArgs), /* size */
    _TestBufferOverunArgs_fields_ti, /* params */
    OE_COUNTOF(_TestBufferOverunArgs_fields_ti) /* nparams */
};

struct ReturnEnclaveMemoryArgs
{
    void *ret;
    unsigned char __pad1[4];
};

extern const OE_StructTI ReturnEnclaveMemoryArgs_ti;

static const OE_FieldTI _ReturnEnclaveMemoryArgs_fields_ti[] =
{
    {
        OE_FLAG_ECALL|OE_FLAG_PTR|OE_FLAG_UNCHECKED, /* flags */
        "ret", /* name */
        OE_VOID_T, /* type */
        NULL, /* structTI */
        NULL, /* countParam */
        OE_OFFSETOF(struct ReturnEnclaveMemoryArgs, ret),
        sizeof(void*), /* size */
        0, /* subscript */
    },
};

const OE_StructTI ReturnEnclaveMemoryArgs_ti =
{
    0, /* flags */
    "ReturnEnclaveMemory", /* name */
    sizeof(struct ReturnEnclaveMemoryArgs), /* size */
    _ReturnEnclaveMemoryArgs_fields_ti, /* params */
    OE_COUNTOF(_ReturnEnclaveMemoryArgs_fields_ti) /* nparams */
};

struct TestBufferCopyArgs
{
    unsigned char __pad0[4];
    void *dest;
    unsigned char __pad1[4];
    const void *src;
    unsigned char __pad2[4];
    size_t n;
    unsigned char __pad3[4];
    bool forceOverwrite;
    unsigned char __pad4[4];
};

extern const OE_StructTI TestBufferCopyArgs_ti;

static const OE_FieldTI _TestBufferCopyArgs_fields_ti[] =
{
    {
        OE_FLAG_OUT|OE_FLAG_PTR|OE_FLAG_COUNT, /* flags */
        "dest", /* name */
        OE_VOID_T, /* type */
        NULL, /* structName */
        "n", /* countParam */
        OE_OFFSETOF(struct TestBufferCopyArgs, dest),
        sizeof(void*), /* size */
        0, /* subscript */
    },
    {
        OE_FLAG_IN|OE_FLAG_CONST|OE_FLAG_PTR|OE_FLAG_COUNT, /* flags */
        "src", /* name */
        OE_VOID_T, /* type */
        NULL, /* structName */
        "n", /* countParam */
        OE_OFFSETOF(struct TestBufferCopyArgs, src),
        sizeof(void*), /* size */
        0, /* subscript */
    },
    {
        OE_FLAG_IN, /* flags */
        "n", /* name */
        OE_SIZE_T, /* type */
        NULL, /* structName */
        NULL, /* countParam */
        OE_OFFSETOF(struct TestBufferCopyArgs, n),
        sizeof(size_t), /* size */
        0, /* subscript */
    },
    {
        OE_FLAG_IN, /* flags */
        "forceOverwrite", /* name */
        OE_BOOL_T, /* type */
        NULL, /* structName */
        NULL, /* countParam */
        OE_OFFSETOF(struct TestBufferCopyArgs, forceOverwrite),
        sizeof(bool), /* size */
        0, /* subscript */
    },
};

const OE_StructTI TestBufferCopyArgs_ti =
{
    0, /* flags */
    "TestBufferCopy", /* name */
    sizeof(struct TestBufferCopyArgs), /* size */
    _TestBufferCopyArgs_fields_ti, /* params */
    OE_COUNTOF(_TestBufferCopyArgs_fields_ti) /* nparams */
};

/*
********************************************************************************
**
** Inbound calls
**
********************************************************************************
*/

OE_EXTERNC void ReturnVoid();

/* ICALL: generator.cpp(431) */
OE_ECALL void __ReturnVoid(void* args)
{
    OE_Result __r = OE_OK;

    ReturnVoid();


    (void)__r;
}

OE_EXTERNC uint32_t ReturnUint32();

/* ICALL: generator.cpp(431) */
OE_ECALL void __ReturnUint32(void* args)
{
    OE_Result __r = OE_OK;

    const OE_StructTI* __ti = &ReturnUint32Args_ti;
    typedef struct ReturnUint32Args __Args;
    __Args* __args = (__Args*)args;
    __Args __buf;
    __Args* __a = &__buf;

    OE_Memset(__a, 0, sizeof(__Args));

    __r = OE_CheckPreConstraints(__ti, args);
    if (__r != OE_OK)
        goto done;

    __r = OE_PadStruct(__ti, __a);
    if (__r != OE_OK)
        goto done;

    __a->ret = ReturnUint32();

    __r = OE_CheckStruct(__ti, __a);
    if (__r != OE_OK)
        goto done;


    __r = OE_SetArg(__ti, __a, 0, 0, &__args->ret, OE_HostMalloc);
    if (__r != OE_OK)
        goto done;

    __r = OE_CheckPostConstraints(__ti, args);
    if (__r != OE_OK)
        goto done;

done:
    OE_DestroyStruct(__ti, __a, free);

    (void)__r;
}

OE_EXTERNC char *ReturnStr();

/* ICALL: generator.cpp(431) */
OE_ECALL void __ReturnStr(void* args)
{
    OE_Result __r = OE_OK;

    const OE_StructTI* __ti = &ReturnStrArgs_ti;
    typedef struct ReturnStrArgs __Args;
    __Args* __args = (__Args*)args;
    __Args __buf;
    __Args* __a = &__buf;

    OE_Memset(__a, 0, sizeof(__Args));

    __r = OE_CheckPreConstraints(__ti, args);
    if (__r != OE_OK)
        goto done;

    __r = OE_PadStruct(__ti, __a);
    if (__r != OE_OK)
        goto done;

    __a->ret = ReturnStr();

    __r = OE_CheckStruct(__ti, __a);
    if (__r != OE_OK)
        goto done;


    __r = OE_SetArg(__ti, __a, 0, true, &__args->ret, OE_HostMalloc);
    if (__r != OE_OK)
        goto done;

    __r = OE_CheckPostConstraints(__ti, args);
    if (__r != OE_OK)
        goto done;

done:
    OE_DestroyStruct(__ti, __a, free);

    (void)__r;
}

OE_EXTERNC struct Date ReturnDate();

/* ICALL: generator.cpp(431) */
OE_ECALL void __ReturnDate(void* args)
{
    OE_Result __r = OE_OK;

    const OE_StructTI* __ti = &ReturnDateArgs_ti;
    typedef struct ReturnDateArgs __Args;
    __Args* __args = (__Args*)args;
    __Args __buf;
    __Args* __a = &__buf;

    OE_Memset(__a, 0, sizeof(__Args));

    __r = OE_CheckPreConstraints(__ti, args);
    if (__r != OE_OK)
        goto done;

    __r = OE_PadStruct(__ti, __a);
    if (__r != OE_OK)
        goto done;

    __a->ret = ReturnDate();

    __r = OE_CheckStruct(__ti, __a);
    if (__r != OE_OK)
        goto done;


    __r = OE_SetArg(__ti, __a, 0, 0, &__args->ret, OE_HostMalloc);
    if (__r != OE_OK)
        goto done;

    __r = OE_CheckPostConstraints(__ti, args);
    if (__r != OE_OK)
        goto done;

done:
    OE_DestroyStruct(__ti, __a, free);

    (void)__r;
}

OE_EXTERNC struct Object ReturnObject();

/* ICALL: generator.cpp(431) */
OE_ECALL void __ReturnObject(void* args)
{
    OE_Result __r = OE_OK;

    const OE_StructTI* __ti = &ReturnObjectArgs_ti;
    typedef struct ReturnObjectArgs __Args;
    __Args* __args = (__Args*)args;
    __Args __buf;
    __Args* __a = &__buf;

    OE_Memset(__a, 0, sizeof(__Args));

    __r = OE_CheckPreConstraints(__ti, args);
    if (__r != OE_OK)
        goto done;

    __r = OE_PadStruct(__ti, __a);
    if (__r != OE_OK)
        goto done;

    __a->ret = ReturnObject();

    __r = OE_CheckStruct(__ti, __a);
    if (__r != OE_OK)
        goto done;


    __r = OE_SetArg(__ti, __a, 0, 0, &__args->ret, OE_HostMalloc);
    if (__r != OE_OK)
        goto done;

    __r = OE_CheckPostConstraints(__ti, args);
    if (__r != OE_OK)
        goto done;

done:
    OE_DestroyStruct(__ti, __a, free);

    (void)__r;
}

OE_EXTERNC struct Object *ReturnObjects(
    size_t count);

/* ICALL: generator.cpp(431) */
OE_ECALL void __ReturnObjects(void* args)
{
    OE_Result __r = OE_OK;

    const OE_StructTI* __ti = &ReturnObjectsArgs_ti;
    typedef struct ReturnObjectsArgs __Args;
    __Args* __args = (__Args*)args;
    __Args __buf;
    __Args* __a = &__buf;

    OE_Memset(__a, 0, sizeof(__Args));

    __r = OE_CheckPreConstraints(__ti, args);
    if (__r != OE_OK)
        goto done;

    __r = OE_SetArg(__ti, __args, 1, false, (void*)&__a->count, malloc);
    if (__r != OE_OK)
        goto done;

    __r = OE_PadStruct(__ti, __a);
    if (__r != OE_OK)
        goto done;

    __a->ret = ReturnObjects(
        __a->count);

    __r = OE_CheckStruct(__ti, __a);
    if (__r != OE_OK)
        goto done;


    __r = OE_SetArg(__ti, __a, 0, true, &__args->ret, OE_HostMalloc);
    if (__r != OE_OK)
        goto done;

    __r = OE_CheckPostConstraints(__ti, args);
    if (__r != OE_OK)
        goto done;

done:
    OE_DestroyStruct(__ti, __a, free);

    (void)__r;
}

OE_EXTERNC struct Node *ReturnLinkedList();

/* ICALL: generator.cpp(431) */
OE_ECALL void __ReturnLinkedList(void* args)
{
    OE_Result __r = OE_OK;

    const OE_StructTI* __ti = &ReturnLinkedListArgs_ti;
    typedef struct ReturnLinkedListArgs __Args;
    __Args* __args = (__Args*)args;
    __Args __buf;
    __Args* __a = &__buf;

    OE_Memset(__a, 0, sizeof(__Args));

    __r = OE_CheckPreConstraints(__ti, args);
    if (__r != OE_OK)
        goto done;

    __r = OE_PadStruct(__ti, __a);
    if (__r != OE_OK)
        goto done;

    __a->ret = ReturnLinkedList();

    __r = OE_CheckStruct(__ti, __a);
    if (__r != OE_OK)
        goto done;


    __r = OE_SetArg(__ti, __a, 0, true, &__args->ret, OE_HostMalloc);
    if (__r != OE_OK)
        goto done;

    __r = OE_CheckPostConstraints(__ti, args);
    if (__r != OE_OK)
        goto done;

done:
    OE_DestroyStruct(__ti, __a, free);

    (void)__r;
}

OE_EXTERNC char *TestStrdup(
    const char *s);

/* ICALL: generator.cpp(431) */
OE_ECALL void __TestStrdup(void* args)
{
    OE_Result __r = OE_OK;

    const OE_StructTI* __ti = &TestStrdupArgs_ti;
    typedef struct TestStrdupArgs __Args;
    __Args* __args = (__Args*)args;
    __Args __buf;
    __Args* __a = &__buf;

    OE_Memset(__a, 0, sizeof(__Args));

    __r = OE_CheckPreConstraints(__ti, args);
    if (__r != OE_OK)
        goto done;

    __r = OE_SetArg(__ti, __args, 1, true, (void*)&__a->s, malloc);
    if (__r != OE_OK)
        goto done;

    __r = OE_PadStruct(__ti, __a);
    if (__r != OE_OK)
        goto done;

    __a->ret = TestStrdup(
        __a->s);

    __r = OE_CheckStruct(__ti, __a);
    if (__r != OE_OK)
        goto done;


    __r = OE_SetArg(__ti, __a, 0, true, &__args->ret, OE_HostMalloc);
    if (__r != OE_OK)
        goto done;

    __r = OE_CheckPostConstraints(__ti, args);
    if (__r != OE_OK)
        goto done;

done:
    OE_DestroyStruct(__ti, __a, free);

    (void)__r;
}

OE_EXTERNC int32_t CopyObject(
    struct Object *dest,
    const struct Object *src);

/* ICALL: generator.cpp(431) */
OE_ECALL void __CopyObject(void* args)
{
    OE_Result __r = OE_OK;

    const OE_StructTI* __ti = &CopyObjectArgs_ti;
    typedef struct CopyObjectArgs __Args;
    __Args* __args = (__Args*)args;
    __Args __buf;
    __Args* __a = &__buf;

    OE_Memset(__a, 0, sizeof(__Args));

    __r = OE_CheckPreConstraints(__ti, args);
    if (__r != OE_OK)
        goto done;

    __r = OE_SetArg(__ti, __args, 1, true, (void*)&__a->dest, malloc);
    if (__r != OE_OK)
        goto done;

    __r = OE_SetArg(__ti, __args, 2, true, (void*)&__a->src, malloc);
    if (__r != OE_OK)
        goto done;

    __r = OE_PadStruct(__ti, __a);
    if (__r != OE_OK)
        goto done;

    __a->ret = CopyObject(
        __a->dest,
        __a->src);

    __r = OE_CheckStruct(__ti, __a);
    if (__r != OE_OK)
        goto done;


    __r = OE_SetArg(__ti, __a, 0, 0, &__args->ret, OE_HostMalloc);
    if (__r != OE_OK)
        goto done;

    __r = OE_ClearArg(__ti, __a, 1, 0, __args->dest, OE_HostFree);
    if (__r != OE_OK)
        goto done;

    __r = OE_SetArg(__ti, __a, 1, 0, __args->dest, OE_HostMalloc);
    if (__r != OE_OK)
        goto done;

    __r = OE_CheckPostConstraints(__ti, args);
    if (__r != OE_OK)
        goto done;

done:
    OE_DestroyStruct(__ti, __a, free);

    (void)__r;
}

OE_EXTERNC int32_t CopyObjects(
    struct Object dest[2],
    const struct Object src[2]);

/* ICALL: generator.cpp(431) */
OE_ECALL void __CopyObjects(void* args)
{
    OE_Result __r = OE_OK;

    const OE_StructTI* __ti = &CopyObjectsArgs_ti;
    typedef struct CopyObjectsArgs __Args;
    __Args* __args = (__Args*)args;
    __Args __buf;
    __Args* __a = &__buf;

    OE_Memset(__a, 0, sizeof(__Args));

    __r = OE_CheckPreConstraints(__ti, args);
    if (__r != OE_OK)
        goto done;

    __r = OE_SetArg(__ti, __args, 2, false, (void*)__a->src, malloc);
    if (__r != OE_OK)
        goto done;

    __r = OE_PadStruct(__ti, __a);
    if (__r != OE_OK)
        goto done;

    __a->ret = CopyObjects(
        __a->dest,
        __a->src);

    __r = OE_CheckStruct(__ti, __a);
    if (__r != OE_OK)
        goto done;


    __r = OE_SetArg(__ti, __a, 0, 0, &__args->ret, OE_HostMalloc);
    if (__r != OE_OK)
        goto done;

    __r = OE_SetArg(__ti, __a, 1, 0, __args->dest, OE_HostMalloc);
    if (__r != OE_OK)
        goto done;

    __r = OE_CheckPostConstraints(__ti, args);
    if (__r != OE_OK)
        goto done;

done:
    OE_DestroyStruct(__ti, __a, free);

    (void)__r;
}

OE_EXTERNC int32_t ECALL_MultipleParams(
    const char *strIn,
    uint32_t numIn,
    const struct Object *objectIn,
    char *strOut,
    uint32_t *numOut,
    struct Object *objectOut,
    struct Object **objectRefOut);

/* ICALL: generator.cpp(431) */
OE_ECALL void __ECALL_MultipleParams(void* args)
{
    OE_Result __r = OE_OK;

    const OE_StructTI* __ti = &ECALL_MultipleParamsArgs_ti;
    typedef struct ECALL_MultipleParamsArgs __Args;
    __Args* __args = (__Args*)args;
    __Args __buf;
    __Args* __a = &__buf;

    OE_Memset(__a, 0, sizeof(__Args));

    __r = OE_CheckPreConstraints(__ti, args);
    if (__r != OE_OK)
        goto done;

    __r = OE_SetArg(__ti, __args, 1, true, (void*)&__a->strIn, malloc);
    if (__r != OE_OK)
        goto done;

    __r = OE_SetArg(__ti, __args, 2, false, (void*)&__a->numIn, malloc);
    if (__r != OE_OK)
        goto done;

    __r = OE_SetArg(__ti, __args, 3, true, (void*)&__a->objectIn, malloc);
    if (__r != OE_OK)
        goto done;

    __r = OE_InitArg(__ti, __args, 4, true, (void*)&__a->strOut, malloc);
    if (__r != OE_OK)
        goto done;

    __r = OE_InitArg(__ti, __args, 5, true, (void*)&__a->numOut, malloc);
    if (__r != OE_OK)
        goto done;

    __r = OE_InitArg(__ti, __args, 6, true, (void*)&__a->objectOut, malloc);
    if (__r != OE_OK)
        goto done;

    __r = OE_PadStruct(__ti, __a);
    if (__r != OE_OK)
        goto done;

    __a->ret = ECALL_MultipleParams(
        __a->strIn,
        __a->numIn,
        __a->objectIn,
        __a->strOut,
        __a->numOut,
        __a->objectOut,
        __args->objectRefOut ? &__a->objectRefOut : NULL);

    __r = OE_CheckStruct(__ti, __a);
    if (__r != OE_OK)
        goto done;


    __r = OE_SetArg(__ti, __a, 0, 0, &__args->ret, OE_HostMalloc);
    if (__r != OE_OK)
        goto done;

    __r = OE_SetArg(__ti, __a, 4, 0, __args->strOut, OE_HostMalloc);
    if (__r != OE_OK)
        goto done;

    __r = OE_SetArg(__ti, __a, 5, 0, __args->numOut, OE_HostMalloc);
    if (__r != OE_OK)
        goto done;

    __r = OE_SetArg(__ti, __a, 6, 0, __args->objectOut, OE_HostMalloc);
    if (__r != OE_OK)
        goto done;

    __r = OE_SetArg(__ti, __a, 7, true, &__args->objectRefOut, OE_HostMalloc);
    if (__r != OE_OK)
        goto done;

    __r = OE_CheckPostConstraints(__ti, args);
    if (__r != OE_OK)
        goto done;

done:
    OE_DestroyStruct(__ti, __a, free);

    (void)__r;
}

OE_EXTERNC int32_t GetObjectRef(
    struct Object **object);

/* ICALL: generator.cpp(431) */
OE_ECALL void __GetObjectRef(void* args)
{
    OE_Result __r = OE_OK;

    const OE_StructTI* __ti = &GetObjectRefArgs_ti;
    typedef struct GetObjectRefArgs __Args;
    __Args* __args = (__Args*)args;
    __Args __buf;
    __Args* __a = &__buf;

    OE_Memset(__a, 0, sizeof(__Args));

    __r = OE_CheckPreConstraints(__ti, args);
    if (__r != OE_OK)
        goto done;

    __r = OE_PadStruct(__ti, __a);
    if (__r != OE_OK)
        goto done;

    __a->ret = GetObjectRef(
        __args->object ? &__a->object : NULL);

    __r = OE_CheckStruct(__ti, __a);
    if (__r != OE_OK)
        goto done;


    __r = OE_SetArg(__ti, __a, 0, 0, &__args->ret, OE_HostMalloc);
    if (__r != OE_OK)
        goto done;

    __r = OE_SetArg(__ti, __a, 1, true, &__args->object, OE_HostMalloc);
    if (__r != OE_OK)
        goto done;

    __r = OE_CheckPostConstraints(__ti, args);
    if (__r != OE_OK)
        goto done;

done:
    OE_DestroyStruct(__ti, __a, free);

    (void)__r;
}

OE_EXTERNC int32_t ModifyObject(
    struct Object *object);

/* ICALL: generator.cpp(431) */
OE_ECALL void __ModifyObject(void* args)
{
    OE_Result __r = OE_OK;

    const OE_StructTI* __ti = &ModifyObjectArgs_ti;
    typedef struct ModifyObjectArgs __Args;
    __Args* __args = (__Args*)args;
    __Args __buf;
    __Args* __a = &__buf;

    OE_Memset(__a, 0, sizeof(__Args));

    __r = OE_CheckPreConstraints(__ti, args);
    if (__r != OE_OK)
        goto done;

    __r = OE_SetArg(__ti, __args, 1, true, (void*)&__a->object, malloc);
    if (__r != OE_OK)
        goto done;

    __r = OE_PadStruct(__ti, __a);
    if (__r != OE_OK)
        goto done;

    __a->ret = ModifyObject(
        __a->object);

    __r = OE_CheckStruct(__ti, __a);
    if (__r != OE_OK)
        goto done;


    __r = OE_SetArg(__ti, __a, 0, 0, &__args->ret, OE_HostMalloc);
    if (__r != OE_OK)
        goto done;

    __r = OE_ClearArg(__ti, __a, 1, 0, __args->object, OE_HostFree);
    if (__r != OE_OK)
        goto done;

    __r = OE_SetArg(__ti, __a, 1, 0, __args->object, OE_HostMalloc);
    if (__r != OE_OK)
        goto done;

    __r = OE_CheckPostConstraints(__ti, args);
    if (__r != OE_OK)
        goto done;

done:
    OE_DestroyStruct(__ti, __a, free);

    (void)__r;
}

OE_EXTERNC size_t TestStrlcpy(
    char *dest,
    const char *src,
    size_t dsize);

/* ICALL: generator.cpp(431) */
OE_ECALL void __TestStrlcpy(void* args)
{
    OE_Result __r = OE_OK;

    const OE_StructTI* __ti = &TestStrlcpyArgs_ti;
    typedef struct TestStrlcpyArgs __Args;
    __Args* __args = (__Args*)args;
    __Args __buf;
    __Args* __a = &__buf;

    OE_Memset(__a, 0, sizeof(__Args));

    __r = OE_CheckPreConstraints(__ti, args);
    if (__r != OE_OK)
        goto done;

    __r = OE_InitArg(__ti, __args, 1, true, (void*)&__a->dest, malloc);
    if (__r != OE_OK)
        goto done;

    __r = OE_SetArg(__ti, __args, 2, true, (void*)&__a->src, malloc);
    if (__r != OE_OK)
        goto done;

    __r = OE_SetArg(__ti, __args, 3, false, (void*)&__a->dsize, malloc);
    if (__r != OE_OK)
        goto done;

    __r = OE_PadStruct(__ti, __a);
    if (__r != OE_OK)
        goto done;

    __a->ret = TestStrlcpy(
        __a->dest,
        __a->src,
        __a->dsize);

    __r = OE_CheckStruct(__ti, __a);
    if (__r != OE_OK)
        goto done;


    __r = OE_SetArg(__ti, __a, 0, 0, &__args->ret, OE_HostMalloc);
    if (__r != OE_OK)
        goto done;

    __r = OE_SetArg(__ti, __a, 1, 0, __args->dest, OE_HostMalloc);
    if (__r != OE_OK)
        goto done;

    __r = OE_CheckPostConstraints(__ti, args);
    if (__r != OE_OK)
        goto done;

done:
    OE_DestroyStruct(__ti, __a, free);

    (void)__r;
}

OE_EXTERNC size_t TestOptQualifier(
    char *p1,
    const char *p2,
    size_t p1size);

/* ICALL: generator.cpp(431) */
OE_ECALL void __TestOptQualifier(void* args)
{
    OE_Result __r = OE_OK;

    const OE_StructTI* __ti = &TestOptQualifierArgs_ti;
    typedef struct TestOptQualifierArgs __Args;
    __Args* __args = (__Args*)args;
    __Args __buf;
    __Args* __a = &__buf;

    OE_Memset(__a, 0, sizeof(__Args));

    __r = OE_CheckPreConstraints(__ti, args);
    if (__r != OE_OK)
        goto done;

    __r = OE_InitArg(__ti, __args, 1, true, (void*)&__a->p1, malloc);
    if (__r != OE_OK)
        goto done;

    __r = OE_SetArg(__ti, __args, 2, true, (void*)&__a->p2, malloc);
    if (__r != OE_OK)
        goto done;

    __r = OE_SetArg(__ti, __args, 3, false, (void*)&__a->p1size, malloc);
    if (__r != OE_OK)
        goto done;

    __r = OE_PadStruct(__ti, __a);
    if (__r != OE_OK)
        goto done;

    __a->ret = TestOptQualifier(
        __a->p1,
        __a->p2,
        __a->p1size);

    __r = OE_CheckStruct(__ti, __a);
    if (__r != OE_OK)
        goto done;


    __r = OE_SetArg(__ti, __a, 0, 0, &__args->ret, OE_HostMalloc);
    if (__r != OE_OK)
        goto done;

    __r = OE_SetArg(__ti, __a, 1, 0, __args->p1, OE_HostMalloc);
    if (__r != OE_OK)
        goto done;

    __r = OE_CheckPostConstraints(__ti, args);
    if (__r != OE_OK)
        goto done;

done:
    OE_DestroyStruct(__ti, __a, free);

    (void)__r;
}

OE_EXTERNC int *ReturnIntPtr(
    int *p,
    size_t n);

/* ICALL: generator.cpp(431) */
OE_ECALL void __ReturnIntPtr(void* args)
{
    OE_Result __r = OE_OK;

    const OE_StructTI* __ti = &ReturnIntPtrArgs_ti;
    typedef struct ReturnIntPtrArgs __Args;
    __Args* __args = (__Args*)args;
    __Args __buf;
    __Args* __a = &__buf;

    OE_Memset(__a, 0, sizeof(__Args));

    __r = OE_CheckPreConstraints(__ti, args);
    if (__r != OE_OK)
        goto done;

    __r = OE_SetArg(__ti, __args, 1, true, (void*)&__a->p, malloc);
    if (__r != OE_OK)
        goto done;

    __r = OE_SetArg(__ti, __args, 2, false, (void*)&__a->n, malloc);
    if (__r != OE_OK)
        goto done;

    __r = OE_PadStruct(__ti, __a);
    if (__r != OE_OK)
        goto done;

    __a->ret = ReturnIntPtr(
        __a->p,
        __a->n);

    __r = OE_CheckStruct(__ti, __a);
    if (__r != OE_OK)
        goto done;


    __r = OE_SetArg(__ti, __a, 0, true, &__args->ret, OE_HostMalloc);
    if (__r != OE_OK)
        goto done;

    __r = OE_ClearArg(__ti, __a, 1, 0, __args->p, OE_HostFree);
    if (__r != OE_OK)
        goto done;

    __r = OE_SetArg(__ti, __a, 1, 0, __args->p, OE_HostMalloc);
    if (__r != OE_OK)
        goto done;

    __r = OE_CheckPostConstraints(__ti, args);
    if (__r != OE_OK)
        goto done;

done:
    OE_DestroyStruct(__ti, __a, free);

    (void)__r;
}

OE_EXTERNC void TestCallback(
    void *func);

/* ICALL: generator.cpp(431) */
OE_ECALL void __TestCallback(void* args)
{
    OE_Result __r = OE_OK;

    const OE_StructTI* __ti = &TestCallbackArgs_ti;
    typedef struct TestCallbackArgs __Args;
    __Args* __args = (__Args*)args;
    __Args __buf;
    __Args* __a = &__buf;

    OE_Memset(__a, 0, sizeof(__Args));

    __r = OE_CheckPreConstraints(__ti, args);
    if (__r != OE_OK)
        goto done;

    __r = OE_SetArg(__ti, __args, 0, true, (void*)&__a->func, malloc);
    if (__r != OE_OK)
        goto done;

    __r = OE_PadStruct(__ti, __a);
    if (__r != OE_OK)
        goto done;

    TestCallback(
        __a->func);

    __r = OE_CheckStruct(__ti, __a);
    if (__r != OE_OK)
        goto done;


    __r = OE_CheckPostConstraints(__ti, args);
    if (__r != OE_OK)
        goto done;

done:
    OE_DestroyStruct(__ti, __a, free);

    (void)__r;
}

OE_EXTERNC bool TestIntPtrRef(
    int **intPtrOut,
    size_t n);

/* ICALL: generator.cpp(431) */
OE_ECALL void __TestIntPtrRef(void* args)
{
    OE_Result __r = OE_OK;

    const OE_StructTI* __ti = &TestIntPtrRefArgs_ti;
    typedef struct TestIntPtrRefArgs __Args;
    __Args* __args = (__Args*)args;
    __Args __buf;
    __Args* __a = &__buf;

    OE_Memset(__a, 0, sizeof(__Args));

    __r = OE_CheckPreConstraints(__ti, args);
    if (__r != OE_OK)
        goto done;

    __r = OE_SetArg(__ti, __args, 2, false, (void*)&__a->n, malloc);
    if (__r != OE_OK)
        goto done;

    __r = OE_PadStruct(__ti, __a);
    if (__r != OE_OK)
        goto done;

    __a->ret = TestIntPtrRef(
        __args->intPtrOut ? &__a->intPtrOut : NULL,
        __a->n);

    __r = OE_CheckStruct(__ti, __a);
    if (__r != OE_OK)
        goto done;


    __r = OE_SetArg(__ti, __a, 0, 0, &__args->ret, OE_HostMalloc);
    if (__r != OE_OK)
        goto done;

    __r = OE_SetArg(__ti, __a, 1, true, &__args->intPtrOut, OE_HostMalloc);
    if (__r != OE_OK)
        goto done;

    __r = OE_CheckPostConstraints(__ti, args);
    if (__r != OE_OK)
        goto done;

done:
    OE_DestroyStruct(__ti, __a, free);

    (void)__r;
}

OE_EXTERNC void TestBufferOverun(
    char src[8]);

/* ICALL: generator.cpp(431) */
OE_ECALL void __TestBufferOverun(void* args)
{
    OE_Result __r = OE_OK;

    const OE_StructTI* __ti = &TestBufferOverunArgs_ti;
    typedef struct TestBufferOverunArgs __Args;
    __Args* __args = (__Args*)args;
    __Args __buf;
    __Args* __a = &__buf;

    OE_Memset(__a, 0, sizeof(__Args));

    __r = OE_CheckPreConstraints(__ti, args);
    if (__r != OE_OK)
        goto done;

    __r = OE_PadStruct(__ti, __a);
    if (__r != OE_OK)
        goto done;

    TestBufferOverun(
        __a->src);

    __r = OE_CheckStruct(__ti, __a);
    if (__r != OE_OK)
        goto done;


    __r = OE_SetArg(__ti, __a, 0, 0, __args->src, OE_HostMalloc);
    if (__r != OE_OK)
        goto done;

    __r = OE_CheckPostConstraints(__ti, args);
    if (__r != OE_OK)
        goto done;

done:
    OE_DestroyStruct(__ti, __a, free);

    (void)__r;
}

OE_EXTERNC void *ReturnEnclaveMemory();

/* ICALL: generator.cpp(431) */
OE_ECALL void __ReturnEnclaveMemory(void* args)
{
    OE_Result __r = OE_OK;

    const OE_StructTI* __ti = &ReturnEnclaveMemoryArgs_ti;
    typedef struct ReturnEnclaveMemoryArgs __Args;
    __Args* __args = (__Args*)args;
    __Args __buf;
    __Args* __a = &__buf;

    OE_Memset(__a, 0, sizeof(__Args));

    __r = OE_CheckPreConstraints(__ti, args);
    if (__r != OE_OK)
        goto done;

    __r = OE_PadStruct(__ti, __a);
    if (__r != OE_OK)
        goto done;

    __a->ret = ReturnEnclaveMemory();

    __r = OE_CheckStruct(__ti, __a);
    if (__r != OE_OK)
        goto done;


    __r = OE_SetArg(__ti, __a, 0, true, &__args->ret, OE_HostMalloc);
    if (__r != OE_OK)
        goto done;

    __r = OE_CheckPostConstraints(__ti, args);
    if (__r != OE_OK)
        goto done;

done:
    OE_DestroyStruct(__ti, __a, free);

    (void)__r;
}

OE_EXTERNC void TestBufferCopy(
    void *dest,
    const void *src,
    size_t n,
    bool forceOverwrite);

/* ICALL: generator.cpp(431) */
OE_ECALL void __TestBufferCopy(void* args)
{
    OE_Result __r = OE_OK;

    const OE_StructTI* __ti = &TestBufferCopyArgs_ti;
    typedef struct TestBufferCopyArgs __Args;
    __Args* __args = (__Args*)args;
    __Args __buf;
    __Args* __a = &__buf;

    OE_Memset(__a, 0, sizeof(__Args));

    __r = OE_CheckPreConstraints(__ti, args);
    if (__r != OE_OK)
        goto done;

    __r = OE_InitArg(__ti, __args, 0, true, (void*)&__a->dest, malloc);
    if (__r != OE_OK)
        goto done;

    __r = OE_SetArg(__ti, __args, 1, true, (void*)&__a->src, malloc);
    if (__r != OE_OK)
        goto done;

    __r = OE_SetArg(__ti, __args, 2, false, (void*)&__a->n, malloc);
    if (__r != OE_OK)
        goto done;

    __r = OE_SetArg(__ti, __args, 3, false, (void*)&__a->forceOverwrite, malloc);
    if (__r != OE_OK)
        goto done;

    __r = OE_PadStruct(__ti, __a);
    if (__r != OE_OK)
        goto done;

    TestBufferCopy(
        __a->dest,
        __a->src,
        __a->n,
        __a->forceOverwrite);

    __r = OE_CheckStruct(__ti, __a);
    if (__r != OE_OK)
        goto done;


    __r = OE_SetArg(__ti, __a, 0, 0, __args->dest, OE_HostMalloc);
    if (__r != OE_OK)
        goto done;

    __r = OE_CheckPostConstraints(__ti, args);
    if (__r != OE_OK)
        goto done;

done:
    OE_DestroyStruct(__ti, __a, free);

    (void)__r;
}

/*
********************************************************************************
**
** Outbound calls
**
********************************************************************************
*/

/* OCALL: generator.cpp(772) */
OE_EXTERNC OE_Result OCALL_MultipleParams(
    int32_t *ret,
    const char *strIn,
    uint32_t numIn,
    const struct Object *objectIn,
    char *strOut,
    uint32_t *numOut,
    struct Object *objectOut,
    struct Object **objectRefOut)
{
    OE_Result __r = OE_UNEXPECTED;
    const OE_StructTI* __ti = &OCALL_MultipleParamsArgs_ti;
    typedef struct OCALL_MultipleParamsArgs __Args;
    __Args __args;
    __Args* __a = NULL;

    /**************************/
    /*** create args struct ***/
    /**************************/

    OE_Memset(&__args, 0, sizeof(__Args));
    __args.strIn = strIn;
    __args.numIn = numIn;
    __args.objectIn = objectIn;
    __args.strOut = strOut;
    __args.numOut = numOut;
    __args.objectOut = objectOut;
    if (objectRefOut)
        __args.objectRefOut = *objectRefOut;

    if (!(__a = (__Args*)OE_HostStackCalloc(1, sizeof(__Args))))
    {
        __r = OE_OUT_OF_MEMORY;
        goto done;
    }

    __r = OE_SetArg(__ti, &__args, 1, true, (void*)&__a->strIn, OE_HostStackMalloc);
    if (__r != OE_OK)
        goto done;

    __r = OE_SetArg(__ti, &__args, 2, false, (void*)&__a->numIn, OE_HostStackMalloc);
    if (__r != OE_OK)
        goto done;

    __r = OE_SetArg(__ti, &__args, 3, true, (void*)&__a->objectIn, OE_HostStackMalloc);
    if (__r != OE_OK)
        goto done;

    __r = OE_InitArg(__ti, &__args, 4, true, (void*)&__a->strOut, OE_HostStackMalloc);
    if (__r != OE_OK)
        goto done;

    __r = OE_InitArg(__ti, &__args, 5, true, (void*)&__a->numOut, OE_HostStackMalloc);
    if (__r != OE_OK)
        goto done;

    __r = OE_InitArg(__ti, &__args, 6, true, (void*)&__a->objectOut, OE_HostStackMalloc);
    if (__r != OE_OK)
        goto done;

    __r = OE_InitArg(__ti, &__args, 7, true, (void*)&__a->objectRefOut, OE_HostStackMalloc);
    if (__r != OE_OK)
        goto done;

    /********************/
    /*** perform call ***/
    /********************/

    __r = OE_CallHost("__OCALL_MultipleParams", __a);
    if (__r != OE_OK)
        goto done;

    /********************/
    /*** return value ***/
    /********************/

    __r = OE_SetArg(__ti, __a, 0, 0, ret, malloc);
    if (__r != OE_OK)
        goto done;

    /*************************/
    /*** output parameters ***/
    /*************************/

    __r = OE_SetArg(__ti, __a, 4, 0, strOut, OE_HostStackMalloc);
    if (__r != OE_OK)
        goto done;

    __r = OE_SetArg(__ti, __a, 5, 0, numOut, OE_HostStackMalloc);
    if (__r != OE_OK)
        goto done;

    __r = OE_SetArg(__ti, __a, 6, 0, objectOut, OE_HostStackMalloc);
    if (__r != OE_OK)
        goto done;

    __r = OE_SetArg(__ti, __a, 7, true, &objectRefOut, OE_HostStackMalloc);
    if (__r != OE_OK)
        goto done;

done:

    if (__a)
        OE_FreeStruct(__ti, __a, OE_HostStackFree);

    return __r;
}

