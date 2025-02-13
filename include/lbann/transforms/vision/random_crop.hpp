////////////////////////////////////////////////////////////////////////////////
// Copyright (c) 2014-2022, Lawrence Livermore National Security, LLC.
// Produced at the Lawrence Livermore National Laboratory.
// Written by the LBANN Research Team (B. Van Essen, et al.) listed in
// the CONTRIBUTORS file. <lbann-dev@llnl.gov>
//
// LLNL-CODE-697807.
// All rights reserved.
//
// This file is part of LBANN: Livermore Big Artificial Neural Network
// Toolkit. For details, see http://software.llnl.gov/LBANN or
// https://github.com/LLNL/LBANN.
//
// Licensed under the Apache License, Version 2.0 (the "Licensee"); you
// may not use this file except in compliance with the License.  You may
// obtain a copy of the License at:
//
// http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or
// implied. See the License for the specific language governing
// permissions and limitations under the license.
////////////////////////////////////////////////////////////////////////////////

#ifndef LBANN_TRANSFORMS_RANDOM_CROP_HPP_INCLUDED
#define LBANN_TRANSFORMS_RANDOM_CROP_HPP_INCLUDED

#include "lbann/transforms/transform.hpp"

#include <google/protobuf/message.h>

namespace lbann {
namespace transform {

/** Crop an image at a random location. */
class random_crop : public transform {
public:
  /** Crop to an h x w image. */
  random_crop(size_t h, size_t w) : transform(), m_h(h), m_w(w) {}

  transform* copy() const override { return new random_crop(*this); }

  std::string get_type() const override { return "random_crop"; }

  void apply(utils::type_erased_matrix& data, std::vector<size_t>& dims) override;
private:
  /** Height and width of the crop. */
  size_t m_h, m_w;
};

std::unique_ptr<transform>
build_random_crop_transform_from_pbuf(google::protobuf::Message const&);

}  // namespace transform
}  // namespace lbann

#endif  // LBANN_TRANSFORMS_RANDOM_CROP_HPP_INCLUDED
