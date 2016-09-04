/* XCFrameworkEngine
 * Copyright (C) Abhishek Porwal, 2016
 * Any queries? Contact author <https://github.com/abhishekp314>
 * This program is complaint with GNU General Public License, version 3.
 * For complete license, read License.txt in source root directory. */

#pragma once

#include "Engine/Utils/EngineUtils.h"
#include "Gameplay/GameActors/SimpleMeshActor.h"
#include "Gameplay/GameActors/SubActor.h"

#include "Graphics/XC_Shaders/XC_VertexFormat.h"
#include "Graphics/XC_Materials/MaterialTypes.h"
#include "Graphics/XC_Mesh/XCMesh.h"

class PistolBullet : public SimpleMeshActor, public SubActor
{
public:
    DECLARE_OBJECT_CREATION(PistolBullet)

    PistolBullet(void);
    PistolBullet(IActor* parentActor, XCVec3& initialPosition, std::string pMesh);
    
    virtual ~PistolBullet(void);
    
    virtual void               Init(i32 actorId);
    virtual void               Update(f32 dt);
    virtual void               UpdateOffsets(f32 dt);
    virtual void               Draw(RenderContext& renderContext);
    virtual void               Destroy();
    virtual void               ApplyOffsetRotation();

    SubActor*                  GetSubActor() { return (SubActor*)this; }

protected:

    ShaderType                 m_useShaderType;
    Material              m_material;
    XCVec4                     m_secondaryLookAxis;
    XCVec4                     m_secondaryUpAxis;
    XCVec4                     m_secondaryRightAxis;
};