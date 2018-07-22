# ced

> Detect the character encoding using Google’s [compact_enc_det](https://github.com/google/compact_enc_det) library

## Installation

```console
$ npm install ced
```

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
