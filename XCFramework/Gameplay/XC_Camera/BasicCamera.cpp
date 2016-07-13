/* XCFrameworkEngine
 * Copyright (C) Abhishek Porwal, 2016
 * Any queries? Contact author <https://github.com/abhishekp314>
 * This program is complaint with GNU General Public License, version 3.
 * For complete license, read License.txt in source root directory. */

#include "GameplayPrecompiledHeader.h"

#include "Gameplay/XC_Camera/BasicCamera.h"
#include "Engine/Input/Directinput.h"

BasicCamera::BasicCamera(XCVec4& pos, XCVec4& target, XCVec4& up, float aspectRatio, float fov, float nearPlane, float farPlane)
    :ICamera(pos, target, up, aspectRatio, fov, nearPlane, farPlane)
{
    m_CameraHeight = pos.Get<Y>();
    m_CameraRotationY = 0.0f;
    m_CameraRadius = 0.0f;

    m_directInput = &SystemLocator::GetInstance()->RequestSystem<DirectInput>("InputSystem");
}

BasicCamera::~BasicCamera(void)
{
}

void BasicCamera::Init()
{
    ICamera::Init();
}

void BasicCamera::Update(float dt)
{
    SetHeight(dt);
    SetRotation();

    ICamera::Update(dt);
}

void BasicCamera::SetHeight(float dt)
{
    if (m_directInput->KeyDown(INPUT_UP))
    {
        m_CameraHeight += 2.0f;
    }

    if (m_directInput->KeyDown(INPUT_DOWN))
    {
        m_CameraHeight -= 2.0f;
    }

    m_position.Set<Y>(m_CameraHeight);
}

void BasicCamera::SetRotation()
{
    float x = 0.0f;
    float y = 0.0f;

#if defined(WIN_32) || defined(XC_ORBIS)
    x = m_directInput->MouseDX();
    y = m_directInput->MouseDY();
#elif defined(DURANGO)
    x = DIRECTINPUT_DURANGO->getStickValue(0, GAMEPAD_LEFTTHUMBSTICK).x;
    y = DIRECTINPUT_DURANGO->getStickValue(0, GAMEPAD_LEFTTHUMBSTICK).y; 
#endif

    m_CameraRotationY += (float)(x / 25.0f);
    m_CameraRadius += (float)(y / 25.0f);

    if (fabs(m_CameraRotationY) >= 2 * XC_PI)
    {
        m_CameraRotationY = 0.0f;
    }

    if (m_CameraRadius >= 5.0f)
    {
        m_CameraRadius = 5.0f;
    }
 
    m_position.Set<X>(m_CameraRadius * cosf(m_CameraRotationY));
    m_position.Set<Z>(m_CameraRadius * sinf(m_CameraRotationY));
}

void BasicCamera::BuildProjectionMatrix()
{
    ICamera::BuildProjectionMatrix();
}

void BasicCamera::BuildViewMatrix()
{
    ICamera::BuildViewMatrix();
}

void BasicCamera::Destroy()
{
    ICamera::Destroy();
}

