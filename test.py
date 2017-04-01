import xevan_hash
from binascii import unhexlify, hexlify

import unittest


# {
#     "hash" : "0000000011ef47bda57dd19a0e71095180dff37b7724822448eb8cd46367576c",
#     "confirmations" : 4,
#     "size" : 239,
#     "height" : 290119,
#     "version" : 3,
#     "merkleroot" : "8dbadda0221ced1790e3ed0cc5568552938cf173c720d2a3fb1deca11bf2e481",
#     "tx" : [
#         "8dbadda0221ced1790e3ed0cc5568552938cf173c720d2a3fb1deca11bf2e481"
#     ],
#     "time" : 1491025717,
#     "nonce" : 52385877, hex = 031f5855
#     "bits" : "1c5b0f5a",
#     "difficulty" : 0.00024414,
#     "previousblockhash" : "00000000a0cbaccc11e43d5db4d8865efcb7907972d8ff7a6fa1db480608307f",
#     "nextblockhash" : "00000bafcc571ece7c5c436f887547ef41b574e10ef7cc6937873a74ef1efeae"
# }

header_hex = ("03000000" +
    "7f30080648dba16f7affd8727990b7fc5e86d8b45d3de411ccaccba000000000" +
    "81e4f21ba1ec1dfba3d220c773f18c93528556c50cede39017ed1c22a0ddba8d"
    "353fdf58" +
    "5a0f5b1c" +
    "55581f03")

best_hash = b'6c576763d48ceb48248224777bf3df805109710e9ad17da5bd47ef1100000000'

class TestSequenceFunctions(unittest.TestCase):

    def setUp(self):
        self.block_header = unhexlify(header_hex)
        self.best_hash = best_hash

    def test_xevan_hash(self):
        self.pow_hash = hexlify(xevan_hash.getPoWHash(self.block_header))
        self.assertEqual(self.pow_hash, self.best_hash)


if __name__ == '__main__':
    unittest.main()

