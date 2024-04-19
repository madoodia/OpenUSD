//
// Copyright 2023 Pixar
//
// Licensed under the Apache License, Version 2.0 (the "Apache License")
// with the following modification; you may not use this file except in
// compliance with the Apache License and the following modification to it:
// Section 6. Trademarks. is deleted and replaced with:
//
// 6. Trademarks. This License does not grant permission to use the trade
//    names, trademarks, service marks, or product names of the Licensor
//    and its affiliates, except as required to comply with Section 4(c) of
//    the License and to reproduce the content of the NOTICE file.
//
// You may obtain a copy of the Apache License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the Apache License with the above modification is
// distributed on an "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY
// KIND, either express or implied. See the Apache License for the specific
// language governing permissions and limitations under the Apache License.
//
////////////////////////////////////////////////////////////////////////

/* ************************************************************************** */
/* **                                                                      ** */
/* ** This file is generated by a script.                                  ** */
/* **                                                                      ** */
/* ** Do not edit it directly (unless it is within a CUSTOM CODE section)! ** */
/* ** Edit hdSchemaDefs.py instead to make changes.                        ** */
/* **                                                                      ** */
/* ************************************************************************** */

#include "hdPrman/rileyCameraPrim.h"

#ifdef HDPRMAN_USE_SCENE_INDEX_OBSERVER

#include "hdPrman/rileyIds.h"
#include "hdPrman/rileyTypes.h"

#include "hdPrman/rileyCameraSchema.h"
#include "hdPrman/utils.h"

#include "pxr/imaging/hd/sceneIndex.h"

PXR_NAMESPACE_OPEN_SCOPE

HdPrman_RileyCameraPrim::HdPrman_RileyCameraPrim(
    HdContainerDataSourceHandle const &primSource,
    const HdsiPrimManagingSceneIndexObserver * const observer,
    HdPrman_RenderParam * const renderParam)
  : HdPrman_RileyPrimBase(renderParam)
{
    HdPrmanRileyCameraSchema schema =
        HdPrmanRileyCameraSchema::GetFromParent(primSource);


    HdPrman_RileyUniqueString name =
        HdPrman_RileyUniqueString(
            schema.GetName());

    HdPrman_RileyShadingNode projection =
        HdPrman_RileyShadingNode(
            schema.GetProjection());

    HdPrman_RileyTransform xform =
        HdPrman_RileyTransform(
            schema.GetXform(),
            _GetShutterInterval());

    HdPrman_RileyParamList properties =
        HdPrman_RileyParamList(
            schema.GetProperties());


    _rileyId = _AcquireRiley()->CreateCamera(
        riley::UserId(),

        name.rileyObject,
        projection.rileyObject,
        xform.rileyObject,
        properties.rileyObject);

// --(BEGIN CUSTOM CODE: Constructor)--
// --(END CUSTOM CODE: Constructor)--
}

void
HdPrman_RileyCameraPrim::_Dirty(
    const HdSceneIndexObserver::DirtiedPrimEntry &entry,
    const HdsiPrimManagingSceneIndexObserver * const observer)
{
    HdPrmanRileyCameraSchema schema =
        HdPrmanRileyCameraSchema::GetFromParent(
            observer->GetSceneIndex()->GetPrim(entry.primPath).dataSource);


    std::optional<HdPrman_RileyShadingNode> projection;
    if (entry.dirtyLocators.Intersects(
            HdPrmanRileyCameraSchema::GetProjectionLocator())) {
        projection =
            HdPrman_RileyShadingNode(
                schema.GetProjection());
    };

    std::optional<HdPrman_RileyTransform> xform;
    if (entry.dirtyLocators.Intersects(
            HdPrmanRileyCameraSchema::GetXformLocator())) {
        xform =
            HdPrman_RileyTransform(
                schema.GetXform(),
                _GetShutterInterval());
    };

    std::optional<HdPrman_RileyParamList> properties;
    if (entry.dirtyLocators.Intersects(
            HdPrmanRileyCameraSchema::GetPropertiesLocator())) {
        properties =
            HdPrman_RileyParamList(
                schema.GetProperties());
    };


    _AcquireRiley()->ModifyCamera(_rileyId,
        HdPrman_GetRileyObjectPtr(projection),
        HdPrman_GetRileyObjectPtr(xform),
        HdPrman_GetRileyObjectPtr(properties)
// --(BEGIN CUSTOM CODE: Modify)--
// --(END CUSTOM CODE: Modify)--
        );


}

HdPrman_RileyCameraPrim::~HdPrman_RileyCameraPrim()
{
    _AcquireRiley()->DeleteCamera(_rileyId
// --(BEGIN CUSTOM CODE: Delete)--
// --(END CUSTOM CODE: Delete)--
        );

}

PXR_NAMESPACE_CLOSE_SCOPE

#endif // #ifdef HDPRMAN_USE_SCENE_INDEX_OBSERVER