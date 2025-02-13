################################################################################
## Copyright (c) 2014-2022, Lawrence Livermore National Security, LLC.
## Produced at the Lawrence Livermore National Laboratory.
## Written by the LBANN Research Team (B. Van Essen, et al.) listed in
## the CONTRIBUTORS file. <lbann-dev@llnl.gov>
##
## LLNL-CODE-697807.
## All rights reserved.
##
## This file is part of LBANN: Livermore Big Artificial Neural Network
## Toolkit. For details, see http://software.llnl.gov/LBANN or
## https://github.com/LLNL/LBANN.
##
## Licensed under the Apache License, Version 2.0 (the "Licensee"); you
## may not use this file except in compliance with the License.  You may
## obtain a copy of the License at:
##
## http://www.apache.org/licenses/LICENSE-2.0
##
## Unless required by applicable law or agreed to in writing, software
## distributed under the License is distributed on an "AS IS" BASIS,
## WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or
## implied. See the License for the specific language governing
## permissions and limitations under the license.
################################################################################
# Add the headers for this directory
set_full_path(THIS_DIR_HEADERS
  batchwise_reduce_sum.hpp
  concatenate.hpp
  cross_grid_sum_slice.hpp
  cross_grid_sum.hpp
  pooling.hpp
  reshape.hpp
  slice.hpp
  split.hpp
  sum.hpp
  weighted_sum.hpp
  unpooling.hpp
  constant.hpp
  dummy.hpp
  hadamard.hpp
  reduction.hpp
  evaluation.hpp
  gaussian.hpp
  bernoulli.hpp
  uniform.hpp
  crop.hpp
  categorical_random.hpp
  discrete_random.hpp
  stop_gradient.hpp
  in_top_k.hpp
  sort.hpp
  weights.hpp
  tessellate.hpp
  scatter.hpp
  gather.hpp
  )

# Propagate the files up the tree
set(HEADERS "${HEADERS}" "${THIS_DIR_HEADERS}" PARENT_SCOPE)
