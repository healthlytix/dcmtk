/*
 *
 *  Copyright (C) 2015, OFFIS e.V.
 *  All rights reserved.  See COPYRIGHT file for details.
 *
 *  This software and supporting documentation were developed by
 *
 *    OFFIS e.V.
 *    R&D Division Health
 *    Escherweg 2
 *    D-26121 Oldenburg, Germany
 *
 *
 *  Module: dcmsr
 *
 *  Author: Joerg Riesmeier
 *
 *  Purpose:
 *    classes: TID1001_ObservationContext
 *
 */


#ifndef CMR_TID1001_H
#define CMR_TID1001_H

#include "dcmtk/config/osconfig.h"   /* make sure OS specific configuration is included first */

#include "dcmtk/dcmsr/dsrstpl.h"

#include "dcmtk/dcmsr/cmr/define.h"
#include "dcmtk/dcmsr/cmr/cid7445.h"
#include "dcmtk/dcmsr/cmr/cid7452.h"
#include "dcmtk/dcmsr/cmr/cid7453.h"


/*---------------------*
 *  class declaration  *
 *---------------------*/

/** Implementation of DCMR Template:
 *  TID 1001 - Observation Context (and included templates 1002-1004).
 ** @note Please note that the included templates 1005-1010 are not yet supported.
 */
class DCMTK_CMR_EXPORT TID1001_ObservationContext
  : public DSRSubTemplate
{

  public:

    /** default constructor
     */
    TID1001_ObservationContext();

    /** add content items for TID 1002 (Observer Context) with Observer Type being "Person".
     *  This also includes the content items from TID 1003 (Person Observer Identifying
     *  Attributes).
     ** @param  personName        name of human observer that created the observations
     *                            (mandatory)
     *  @param  organizationName  organization or institution with which the human observer
     *                            is affiliated for the context of the current observation
     *                            (optional)
     *  @param  organizationRole  organizational role of human observer for the context of
     *                            the current observation (optional)
     *  @param  procedureRole     procedural role of human observer for the context of the
     *                            current observation (optional)
     *  @param  check             if enabled, check values for validity before setting them
     ** @return status, EC_Normal if successful, an error code otherwise
     */
    OFCondition addPersonObserver(const OFString &personName,
                                  const OFString &organizationName = "",
                                  const CID7452_OrganizationalRoles &organizationRole = CID7452_OrganizationalRoles(),
                                  const CID7453_PerformingRoles &procedureRole = CID7453_PerformingRoles(),
                                  const OFBool check = OFTrue);

    /** add content items for TID 1002 (Observer Context) with Observer Type being "Device".
     *  This also includes the content items from TID 1004 (Device Observer Identifying
     *  Attributes).
     ** @param  deviceUID         unique identifier of automated device that created the
     *                            observations (mandatory)
     *  @param  deviceName        institution-provided identifier of automated device that
     *                            created the observations (optional)
     *  @param  manufacturer      manufacturer of automated device that created the
     *                            observations (optional)
     *  @param  modelName         manufacturer-provided model name of automated device that
     *                            created the observations (optional)
     *  @param  serialNumber      manufacturer-provided serial number of automated device
     *                            that created the observations (optional)
     *  @param  physicalLocation  location of automated device that created the observations
     *                            whilst the observations were being made (optional)
     *  @param  procedureRoles    the roles played by a device in a procedure (optional,
     *                            multiple values allowed)
     *  @param  check             if enabled, check values for validity before setting them
     ** @return status, EC_Normal if successful, an error code otherwise
     */
    OFCondition addDeviceObserver(const OFString &deviceUID,
                                  const OFString &deviceName = "",
                                  const OFString &manufacturer = "",
                                  const OFString &modelName = "",
                                  const OFString &serialNumber = "",
                                  const OFString &physicalLocation = "",
                                  const OFList<CID7445_DeviceParticipatingRoles> &procedureRoles = OFList<CID7445_DeviceParticipatingRoles>(),
                                  const OFBool check = OFTrue);

    /** add content items for TID 1005 (Procedure Context)
     ** @return always returns EC_IllegalCall since this methods has not been implemented yet
     */
    OFCondition addProcedureContext();

    /** add content items for TID 1006 (Subject Context), and included TID 1007-1010
     ** @return always returns EC_IllegalCall since this methods has not been implemented yet
     */
    OFCondition addSubjectContext();
};


#endif