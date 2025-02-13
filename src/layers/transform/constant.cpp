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

#define LBANN_CONSTANT_LAYER_INSTANTIATE
#include "lbann/layers/transform/constant.hpp"

// LBANN_ASSERT_MSG_HAS_FIELD
#include "lbann/proto/proto_common.hpp"
#include "lbann/utils/protobuf.hpp"
#include <lbann.pb.h>

namespace lbann {

template <typename TensorDataType, data_layout Layout, El::Device Device>
std::unique_ptr<Layer>
build_constant_layer_from_pbuf(lbann_comm* comm,
                               lbann_data::Layer const& proto_layer)
{
  LBANN_ASSERT_MSG_HAS_FIELD(proto_layer, constant);
  using LayerType = constant_layer<TensorDataType, Layout, Device>;

  const auto& params = proto_layer.constant();
  return std::make_unique<LayerType>(
    comm,
    El::To<TensorDataType>(params.value()),
    protobuf::to_vector<int>(params.num_neurons()));
}

#define PROTO_DEVICE(T, Device) \
  template class constant_layer<T, data_layout::DATA_PARALLEL, Device>; \
  template class constant_layer<T, data_layout::MODEL_PARALLEL, Device>; \
  LBANN_LAYER_BUILDER_ETI(constant, T, Device)

#include "lbann/macros/instantiate_device.hpp"

}// namespace lbann
