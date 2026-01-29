/******************************************************************************
 * $HeadURL: $
 * $Id: $
 *
 * Project       : oac-tree training
 *
 * Description   : Training materials for the oac-tree.
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

#include <oac-tree/training/utils.h>

#include <sup/epics/epics_protocol_factory.h>
#include <sup/interfaces/config/configuration_protocol_server.h>
#include <sup/interfaces/cvvf/cvvf_protocol_server.h>
#include <sup/templates/inject_as_unique_ptr.h>

namespace oac_tree
{
namespace training
{

EPICSConfigServerStack::EPICSConfigServerStack(
  const std::string& service_name,
  std::unique_ptr<sup::config::ConfigurationInterface> config_handler)
  : m_config_handler{std::move(config_handler)}
  , m_server{sup::epics::CreateEPICSRPCServerStack(
                sup::epics::GetDefaultRPCServerConfig(service_name),
                sup::protocol::ProtocolRPCServerConfig{},
                std::make_unique<sup::config::ConfigurationProtocolServer>(*m_config_handler))}
{}

EPICSConfigServerStack::~EPICSConfigServerStack() = default;

EPICSCVVFServerStack::EPICSCVVFServerStack(
  const std::string& service_name,
  std::unique_ptr<sup::cvvf::CVVFInterface> cvvf_handler)
  : m_cvvf_handler{std::move(cvvf_handler)}
  , m_server{sup::epics::CreateEPICSRPCServerStack(
                sup::epics::GetDefaultRPCServerConfig(service_name),
                sup::protocol::ProtocolRPCServerConfig{},
                std::make_unique<sup::cvvf::CVVFProtocolServer>(*m_cvvf_handler))}
{}

EPICSCVVFServerStack::~EPICSCVVFServerStack() = default;

}  // namespace training

}  // namespace oac_tree
