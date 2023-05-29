// Copyright (c) 2021 The Dash Core developers
// Distributed under the MIT/X11 software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#ifndef SRC_THRESHOLD_HPP_
#define SRC_THRESHOLD_HPP_

#include "privatekey.hpp"
#include "elements.hpp"

#include <optional>

namespace bls {
    namespace Threshold {
        std::optional<PrivateKey> PrivateKeyShare(const std::vector<PrivateKey>& sks, const Bytes& id, strvec_t &errors);
        std::optional<PrivateKey> PrivateKeyRecover(const std::vector<PrivateKey>& sks, const std::vector<Bytes>& ids, strvec_t &errors);

        std::optional<G1Element> PublicKeyShare(const std::vector<G1Element>& pks, const Bytes& id, strvec_t &errors);
        std::optional<G1Element> PublicKeyRecover(const std::vector<G1Element>& sks, const std::vector<Bytes>& ids, strvec_t &errors);

        std::optional<G2Element> SignatureShare(const std::vector<G2Element>& sks, const Bytes& id, strvec_t &errors);
        std::optional<G2Element> SignatureRecover(const std::vector<G2Element>& sigs, const std::vector<Bytes>& ids, strvec_t &errors);

        G2Element Sign(const PrivateKey& privateKey, const Bytes& vecMessage);
        bool Verify(const G1Element& pubKey, const Bytes& vecMessage, const G2Element& signature);
    } // end namespace Threshold
} // end namespace bls

#endif  // SRC_THRESHOLD_HPP_
