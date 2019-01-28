#define NAPI_VERSION 2
#include <node/node_api.h>

#include <compact_enc_det/compact_enc_det.h>

namespace ced {
  napi_value Method(napi_env env, napi_callback_info info) {
    napi_status status;

    size_t argc = 1;
    napi_value args[1];
    status = napi_get_cb_info(env, info, &argc, args, nullptr, nullptr);
    if (status != napi_ok) return nullptr;

    void* buf;
    size_t buf_length;
    status = napi_get_buffer_info(env, args[0], &buf, &buf_length);
    if (status != napi_ok) return nullptr;

    const char* text = static_cast<const char*>(buf);
    size_t text_length = buf_length;

    bool is_reliable;
    int bytes_consumed;
    Encoding encoding = CompactEncDet::DetectEncoding(
      text,
      text_length,
      nullptr,
      nullptr,
      nullptr,
      UNKNOWN_ENCODING,
      UNKNOWN_LANGUAGE,
      CompactEncDet::QUERY_CORPUS,
      true,
      &bytes_consumed,
      &is_reliable
    );

    const char *encoding_name = EncodingName(encoding);

    napi_value encodingName;
    status = napi_create_string_utf8(env, encoding_name, NAPI_AUTO_LENGTH, &encodingName);
    if (status != napi_ok) return nullptr;

    return encodingName;
  }

  napi_value init(napi_env env, napi_value exports) {
    napi_status status;
    napi_value fn;

    status = napi_create_function(env, nullptr, 0, Method, nullptr, &fn);
    if (status != napi_ok) return nullptr;

    status = napi_set_named_property(env, exports, "detectEncoding", fn);
    if (status != napi_ok) return nullptr;

    return exports;
  }

  NAPI_MODULE(NODE_GYP_MODULE_NAME, init)
}
