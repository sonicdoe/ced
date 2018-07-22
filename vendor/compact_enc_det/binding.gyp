{
  "targets": [{
    "target_name": "compact_enc_det",
    "type": "static_library",
    "include_dirs": [
      "."
    ],
    "sources": [
      "compact_enc_det/compact_enc_det.cc",
      "compact_enc_det/compact_enc_det_hint_code.cc",
      "util/encodings/encodings.cc",
      "util/languages/languages.cc"
    ],
    "cflags_cc": [
      "-std=c++11",
      "-Wno-narrowing"
    ],
    "xcode_settings": {
      "CLANG_CXX_LANGUAGE_STANDARD": "c++11",
      "OTHER_CFLAGS": [
        "-Wno-c++11-narrowing"
      ]
    },
    "direct_dependent_settings": {
      "include_dirs": [
        "."
      ]
    }
  }]
}
