////////////////////////////////////////////////////////////////////////////////
// Copyright (c) 2014-2016, Lawrence Livermore National Security, LLC. 
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
//
// lbann_optimizer_hypergradient_adam .hpp .cpp - Hypergradient SGD with Adam
// Reference:
// Baydin et al. "Online Learning Rate Adaptation with Hypergradient Descent", 2017.
////////////////////////////////////////////////////////////////////////////////

#ifndef LBANN_OPTIMIZER_HYPERGRADIENT_ADAM_HPP
#define LBANN_OPTIMIZER_HYPERGRADIENT_ADAM_HPP

#include "lbann/optimizers/lbann_optimizer.hpp"

namespace lbann
{

  /// Hypergradient Adam optimizer
  class hypergradient_adam : public optimizer
  {
  public:
    /**
     * @param init_learning_rate Initial Adam learning rate (0.001 reasonable).
     * @param hyper_learning_rate Hypergradient learning rate.
     * @param beta1 Decay rate for the first moment moving average.
     * @param beta2 Decay rate for the second moment moving average.
     * @param eps A small value.
     */
    hypergradient_adam
    (lbann_comm* comm,
     DataType init_learning_rate,
     DataType hyper_learning_rate = DataType(1e-7),
     DataType beta1 = DataType(0.9),
     DataType beta2 = DataType(0.99),
     DataType eps = DataType(1e-8));
    /// Destructor
    ~hypergradient_adam();
    /// Set parameters to optimize and initialize optimizer
    void setup(AbsDistMat* parameters);
    /// Update parameters using objective function gradient
    void update(const AbsDistMat* gradient);
    //private:
    /// Hypergradient learning rate.
    DataType m_hyper_learning_rate;
    /// Update factor for first moment estimate
    DataType m_beta1;
    /// Update factor for second moment estimate
    DataType m_beta2;
    /// Small factor to avoid division by zero
    DataType m_eps;
    /// beta1 ^ iteration
    DataType m_current_beta1;
    /// beta2 ^ iteration
    DataType m_current_beta2;
    /// First moment estimates
    AbsDistMat* m_moment1;
    /// Second moment estimates
    AbsDistMat* m_moment2;
    /// Gradient estimate from the prior step (for hypergradient).
    AbsDistMat* m_old_gradient;
  };

  /// Factory for Adam optimizer
  class hypergradient_adam_factory : public optimizer_factory
  {
  public:
    /// Constructor
    hypergradient_adam_factory
    (lbann_comm* comm,
     DataType init_learning_rate,
     DataType hyper_learning_rate = DataType(1e-7),
     DataType beta1 = DataType(0.9),
     DataType beta2 = DataType(0.99),
     DataType eps = DataType(1e-8));
    /// Destructor
    virtual ~hypergradient_adam_factory();
    /// Create hypergradient Adam optimizer
    optimizer* create_optimizer();
  private:
    /// Initial learning rate.
    DataType m_learning_rate;
    /// Hypergradient learning rate.
    DataType m_hyper_learning_rate;
    /// Update factor for first moment estimate
    DataType m_beta1;
    /// Update factor for second moment estimate
    DataType m_beta2;
    /// Small factor to avoid division by zero
    DataType m_eps;
  };

} // namespace lbann

#endif  // LBANN_OPTIMIZER_HYPERGRADIENT_ADAM_HPP
