// Copyright (c) 2009-2010 Satoshi Nakamoto
// Copyright (c) 2009-2015 The Bitcoin Core developers
// Distributed under the MIT software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#include "primitives/block.h"

#include "hash.h"
#include "util.h"
#include "tinyformat.h"
#include "utilstrencodings.h"
#include "crypto/common.h"
#include "crypto/xevan.h"
#include "consensus/consensus.h"

uint256 CBlockHeader::GetHash() const
{
    if(nTime <= PHI2_TIMESTAMP) {
      return XEVAN(BEGIN(nVersion), END(nNonce));
    } else {
      return phi2_hash(BEGIN(nVersion), END(nNonce));
    }
}

std::string CBlock::ToString() const
{
    std::stringstream s;
    if(nTime <= PHI2_TIMESTAMP) {
      s << strprintf("CBlock(hash=%s, ver=%d, hashPrevBlock=%s, hashMerkleRoot=%s, nTime=%u, nBits=%08x, nNonce=%u, vtx=%u XEVAN)\n",
          GetHash().ToString(),
          nVersion,
          hashPrevBlock.ToString(),
          hashMerkleRoot.ToString(),
          nTime, nBits, nNonce,
          vtx.size());
    } else {
      s << strprintf("CBlock(hash=%s, ver=%d, hashPrevBlock=%s, hashMerkleRoot=%s, nTime=%u, nBits=%08x, nNonce=%u, vtx=%u PHI2)\n",
          GetHash().ToString(),
          nVersion,
          hashPrevBlock.ToString(),
          hashMerkleRoot.ToString(),
          nTime, nBits, nNonce,
          vtx.size());
    }

    for (unsigned int i = 0; i < vtx.size(); i++)
    {
        s << "  " << vtx[i].ToString() << "\n";
    }
    return s.str();
}
