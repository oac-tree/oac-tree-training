/******************************************************************************
 * $HeadURL: $
 * $Id: $
 *
 * Project       : Sequencer training
 *
 * Description   : Training materials for the Sequencer.
 *
 * Author        : Walter Van Herck (IO)
 *
 * Copyright (c) : 2010-2024 ITER Organization,
 *                 CS 90 046
 *                 13067 St. Paul-lez-Durance Cedex
 *                 France
 *
 * This file is part of ITER CODAC software.
 * For the terms and conditions of redistribution or use of this software
 * refer to the file ITER-LICENSE.TXT located in the top level directory
 * of the distribution package.
 ******************************************************************************/

#ifndef SEQUENCER_TRAINING_SIGNAL_GENERATOR_CVVF_FUNCTIONS_H_
#define SEQUENCER_TRAINING_SIGNAL_GENERATOR_CVVF_FUNCTIONS_H_

#include <sup/cvvf/user_function.h>

namespace sequencer
{
namespace training
{

/**
 * @brief CVVF function for validating the shape field in the configuration of the signal generator.
 */
class SignalGeneratorShapeValidator : public sup::cvvf::UserFunction
{
public:
  SignalGeneratorShapeValidator();

  virtual ~SignalGeneratorShapeValidator();

  bool GetInputType(sup::dto::AnyType& input_type) const override;

  bool GetOutputType(sup::dto::AnyType& output_type) const override;

  bool Process(const sup::dto::AnyValue& input, sup::dto::AnyValue& output) override;
private:
};

/**
 * @brief CVVF function for validating a reference signal descriptor.
 */
class SignalGeneratorReferenceSignalValidator : public sup::cvvf::UserFunction
{
public:
  SignalGeneratorReferenceSignalValidator();

  virtual ~SignalGeneratorReferenceSignalValidator();

  bool GetInputType(sup::dto::AnyType& input_type) const override;

  bool GetOutputType(sup::dto::AnyType& output_type) const override;

  bool Process(const sup::dto::AnyValue& input, sup::dto::AnyValue& output) override;
private:
};

/**
 * @brief CVVF function for transforming a reference signal descriptor in a signal configuration.
 */
class SignalGeneratorReferenceSignalTransformer : public sup::cvvf::UserFunction
{
public:
  SignalGeneratorReferenceSignalTransformer();

  virtual ~SignalGeneratorReferenceSignalTransformer();

  bool GetInputType(sup::dto::AnyType& input_type) const override;

  bool GetOutputType(sup::dto::AnyType& output_type) const override;

  bool Process(const sup::dto::AnyValue& input, sup::dto::AnyValue& output) override;
private:
};

}  // namespace training

}  // namespace sequencer

#endif  // SEQUENCER_TRAINING_SIGNAL_GENERATOR_CVVF_FUNCTIONS_H_
