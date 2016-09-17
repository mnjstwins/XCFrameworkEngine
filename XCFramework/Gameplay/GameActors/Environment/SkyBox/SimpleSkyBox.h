/* XCFrameworkEngine
 * Copyright (C) Abhishek Porwal, 2016
 * Any queries? Contact author <https://github.com/abhishekp314>
 * This program is complaint with GNU General Public License, version 3.
 * For complete license, read License.txt in source root directory. */

#pragma once

#include "Gameplay/GameActors/SimpleActor.h"

#include "Engine/Resource/ResourceHandle.h"

#include "Graphics/XC_Shaders/XC_ShaderTypes.h"
#include "Graphics/XC_Shaders/XC_VertexFormat.h"
#include "Graphics/XC_Materials/MaterialTypes.h"
#include "Graphics/XC_Shaders/XC_RasterizerTypes.h"
#include "Graphics/VertexBuffer.h"
#include "Graphics/IndexBuffer.h"

class SimpleSkyBox : public SimpleActor
{
public:
    DECLARE_OBJECT_CREATION(SimpleSkyBox)

    SimpleSkyBox(void);
    virtual ~SimpleSkyBox(void);

    void                            Init(i32 actorId) override;
    void                            PreLoad(const void* fbBuffer) override;
    void                            Load() override;
    void                            UpdateState() override;
    void                            Update(f32 dt) override;
    void                            Draw(RenderContext& renderContext) override;
    void                            Destroy() override;

    void                            BuildBuffers();

protected:
    u32                             m_Stride;
    u32                             m_Offset;

    ResourceHandle*                 m_cubeMapTexture;

    ShaderType                      m_useShaderType;
    Material                        m_material;
    
    VertexBuffer<VertexPos>         m_vertexBuffer;
    IndexBuffer<u32>                m_indexBuffer;

    RasterType                      m_rasterType;

    GPUResource*                    m_CBwvp;
};