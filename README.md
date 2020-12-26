# ced

> Detect the character encoding using Google’s [compact_enc_det](https://github.com/google/compact_enc_det) library

[![npm](https://img.shields.io/npm/v/ced.svg?logo=npm)](https://www.npmjs.com/package/ced)
[![CI](https://github.com/sonicdoe/ced/workflows/CI/badge.svg)](https://github.com/sonicdoe/ced/actions?query=workflow%3ACI)

## Installation

```console
$ npm install ced
```

In order to build ced, you may need to install some build tools first. Check [node-gyp’s readme](https://github.com/nodejs/node-gyp#installation) for more information.

## Usage

```js
const fs = require('fs')
const ced = require('ced')

const fileBuffer = fs.readFileSync('foo.txt')
const encoding = ced(fileBuffer)

console.log(encoding)
// 'UTF8'
```

## License

ced is licensed under the ISC License, compact_enc_det is licensed under the Apache License 2.0. See [`LICENSE`](./LICENSE) for the full license text.
